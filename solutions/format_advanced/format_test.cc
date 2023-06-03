#include "catch2/catch_test_macros.hpp"
#include "format.h"

#include <forward_list>
#include <list>
#include <sstream>
#include <vector>

TEST_CASE("Validate range formatting") {
  std::stringstream s;

  std::list<int> t1;
  format_range(s, t1);
  REQUIRE(s.str() == "{}");

  std::vector<int> t2;
  s.str("");
  format_range(s, t2);
  REQUIRE(s.str() == "{}");

  std::vector<int> t3{1};
  s.str("");
  format_range(s, t3);
  REQUIRE(s.str() == "{1}");

  std::vector<int> t4{1, 2, 3};
  s.str("");
  format_range(s, t4);
  REQUIRE(s.str() == "{1,2,3}");

  std::list<int> t5{1, 2, 3};
  s.str("");
  format_range(s, t5);
  REQUIRE(s.str() == "{1<=>2<=>3}");

  std::forward_list<int> t6{1, 2, 3};
  s.str("");
  format_range(s, t6);
  REQUIRE(s.str() == "{1->2->3}");
}