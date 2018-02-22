#include <gtest/gtest.h>
#include <util/VectorComparator.h>

TEST(VectorComparatorTests, EqualityTests) {

    std::vector<Position> v1;
    std::vector<Position> v2;
    ASSERT_TRUE(VectorComparator::comparePositions(v1, v2));

    v1.push_back({'E', 4});
    ASSERT_FALSE(VectorComparator::comparePositions(v1, v2));

    v2.push_back({'E', 4});
    ASSERT_TRUE(VectorComparator::comparePositions(v1, v2));

    v1.push_back({'D', 4});
    v2.push_back({'F', 4});
    ASSERT_FALSE(VectorComparator::comparePositions(v1, v2));

}
