#include <doctest/doctest.h> // for Approx, ResultBuilder, TestCase

#include <gsl/span>      // for span
#include <lds/lds_n.hpp> // for cylin_n, halton_n, sphere3, sphere_n

TEST_CASE("HaltonN") {
  const size_t base[] = {2, 3, 5, 7};
  auto hgen = lds2::HaltonN(base);
  const auto res = hgen.pop();
  CHECK_EQ(res[0], doctest::Approx(0.5));
}
