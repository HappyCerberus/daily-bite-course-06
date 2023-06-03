#include "catch2/catch_test_macros.hpp"
#include "validate.h"

#include <iostream>

std::vector<int> string_to_digits(const std::string &str) {
  std::vector<int> result;
  std::ranges::transform(str, std::back_inserter(result),
                         [](char c) { return c - '0'; });
  return result;
}

TEST_CASE("Luhn validation") {
  SECTION("Valid card numbers") {
    std::vector<std::string> valid_numbers{
        "4111111111111111", // Visa
        "6011514433546201", // Discover
        "6771549495586802", // Maestro
        "370267463651064",  // American Express
        "5425233430109903"  // Mastercard
    };
    for (const auto &number : valid_numbers) {
      auto digits = string_to_digits(number);
      if (!valid_card(digits)) {
        std::cerr << number << "\n";
      }
      REQUIRE(valid_card(digits));
    }
  }

  SECTION("Invalid card numbers") {
    std::vector<std::string> invalid_numbers{
        "1234567812345678", "0000000000000001", "1111111111111111",
        "9999999999999996"};
    for (const auto &number : invalid_numbers) {
      auto digits = string_to_digits(number);
      REQUIRE_FALSE(valid_card(digits));
    }
  }
}