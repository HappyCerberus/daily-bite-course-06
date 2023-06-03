#include "catch2/catch_test_macros.hpp"
#include "trim.h"

#include <string>

TEST_CASE("Validate trim") {
  using namespace std::literals;

  std::string t1 = "";
  REQUIRE(std::ranges::equal(t1, t1 | trim_whitespace));

  std::string t2 = "abc";
  REQUIRE(std::ranges::equal(t2, t2 | trim_whitespace));

  std::string t3 = "  abc  ";
  REQUIRE(std::ranges::equal("abc"s, t3 | trim_whitespace));

  std::string t4 = "\t\ta b c";
  REQUIRE(std::ranges::equal("a b c"s, t4 | trim_whitespace));

  std::string t5 = "a b c\t";
  REQUIRE(std::ranges::equal("a b c"s, t5 | trim_whitespace));
}