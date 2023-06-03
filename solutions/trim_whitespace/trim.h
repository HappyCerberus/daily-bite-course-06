#pragma once

#include <cctype>
#include <ranges>

// Trim leading whitespace
constexpr auto trim_leading_whitespace =
    std::views::drop_while([](char c) { return std::isspace(c); });

// Trim leading and trailing whitespace
constexpr auto trim_whitespace = std::views::reverse | trim_leading_whitespace |
                                 std::views::reverse | trim_leading_whitespace;