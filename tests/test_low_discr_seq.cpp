#include <doctest/doctest.h>  // for Approx, ResultBuilder, TestCase, CHECK

#include <gsl/gsl>               // for span
#include <lds/low_discr_seq.hpp>  // for circle, halton, sphere, sphere3_hopf

TEST_CASE("circle") {
    auto cgen = lds::circle(2);
    auto [x, y] = cgen();
    auto xx = x;  // make clang compiler happy
    CHECK_EQ(xx, doctest::Approx(0.0));
}

TEST_CASE("halton") {
    unsigned base[] = {2, 3};
    auto hgen = lds::halton(base);
    auto [x, y] = hgen();
    auto xx = x;  // make clang compiler happy
    CHECK_EQ(xx, doctest::Approx(0.5));
}

TEST_CASE("sphere") {
    unsigned base[] = {2, 3};
    auto sgen = lds::sphere(base);
    auto [s0, s1, s2] = sgen();
    auto ss0 = s0;  // make clang compiler happy
    CHECK_EQ(ss0, doctest::Approx(0.8660254038));
}

TEST_CASE("sphere3_hopf") {
    unsigned base[] = {2, 3, 5};
    auto shfgen = lds::sphere3_hopf(base);
    auto [s0, s1, s2, s3] = shfgen();
    auto ss0 = s0;  // make clang compiler happy
    CHECK_EQ(ss0, doctest::Approx(-0.2236067977));
}
