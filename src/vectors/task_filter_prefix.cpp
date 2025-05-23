#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include <string>
#include <vector>

namespace inf2_basics {

/// Erwartet einen Vektor v und einen String s.
/// Liefert einen Vektor zurück, der nur die Strings aus v enthält, die mit s
/// beginnen.
std::vector<std::string> filter_prefix(std::vector<std::string> v,
                                       std::string s) {
  std::vector<std::string> result;
  // TODO
  return result;
}

TEST_CASE("[vectors] task_filter_prefix", "[vectors][tasks]") {
  {  // leerer vector
    std::vector<std::string> v;
    std::vector<std::string> expected;
    CHECK(filter_prefix(v, "a") == expected);
    CHECK(filter_prefix(v, "b") == expected);
    CHECK(filter_prefix(v, "c") == expected);
  }

  {  // kein Vorkommen
    std::vector<std::string> v{"abc", "ab", "acde", "e", "cdefg", "cdabc"};
    std::vector<std::string> expected;
    CHECK(filter_prefix(v, "x") == expected);
  }

  {  // allgemeiner Fall
    std::vector<std::string> v = {"abc", "ab", "acde", "e", "cdefg", "cdabc"};
    std::vector<std::string> expected_a = {"abc", "ab", "acde"};
    std::vector<std::string> expected_ab = {"abc", "ab"};
    std::vector<std::string> expected_c = {"cdefg", "cdabc"};
    std::vector<std::string> expected_cd = {"cdefg", "cdabc"};
    CHECK(filter_prefix(v, "a") == expected_a);
    CHECK(filter_prefix(v, "ab") == expected_ab);
    CHECK(filter_prefix(v, "c") == expected_c);
    CHECK(filter_prefix(v, "cd") == expected_cd);
  }
}

}  // namespace inf2_basics
