#pragma once

#include <iostream>
#include <utility>

/* \brief Formats the provided range into the provided output stream

The content of the range is surrounded by {}, each two elements are delimited by
','.
*/
template <std::ranges::range Rng>
std::ostream &format_range(std::ostream &s, const Rng &rng);