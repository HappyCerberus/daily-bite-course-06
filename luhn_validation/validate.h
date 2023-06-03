#pragma once

#include <algorithm>
#include <ranges>

// \brief Implements Luhn validation
template <std::ranges::bidirectional_range Rng>
bool valid_card(const Rng &rng) {}