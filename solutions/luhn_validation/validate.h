#pragma once

#include <algorithm>
#include <ranges>

template <std::ranges::bidirectional_range Rng>
bool valid_card(const Rng &rng) {
  // digits on odd indexes of the payload and the check digit
  constexpr auto odd = std::views::reverse | std::views::stride(2);
  // digits on the even indexes of the payload
  constexpr auto even =
      std::views::reverse | std::views::drop(1) | std::views::stride(2);

  // sum up the odd digits
  auto sum = std::ranges::fold_left(rng | odd, 0, std::plus<>{});

  // sum of doubled even digits
  auto transform = [](int v) {
    if (v > 4)
      return 2 * v - 9;
    else
      return 2 * v;
  };
  sum += std::ranges::fold_left(rng | even | std::views::transform(transform),
                                0, std::plus<>{});
  // check the result
  return sum % 10 == 0;
}