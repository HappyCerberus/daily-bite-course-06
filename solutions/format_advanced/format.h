#pragma once

#include <iostream>
#include <utility>

/* \brief Formats the provided range into the provided output stream

The content of the range is surrounded by {},
each two elements are delimited by ',' for random access ranges,
'<=>' for bidirectional ranges or '->' for forward ranges.
*/
template <std::ranges::forward_range Rng>
std::ostream &format_range(std::ostream &s, const Rng &rng) {
  std::string delim = "";
  s << "{";
  for (auto &v : rng) {
    s << std::exchange(delim, "->") << v;
  }
  s << "}";
  return s;
}

template <std::ranges::bidirectional_range Rng>
std::ostream &format_range(std::ostream &s, const Rng &rng) {
  std::string delim = "";
  s << "{";
  for (auto &v : rng) {
    s << std::exchange(delim, "<=>") << v;
  }
  s << "}";
  return s;
}

template <std::ranges::random_access_range Rng>
std::ostream &format_range(std::ostream &s, const Rng &rng) {
  std::string delim = "";
  s << "{";
  for (auto &v : rng) {
    s << std::exchange(delim, ",") << v;
  }
  s << "}";
  return s;
}