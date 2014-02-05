#include <gtest/gtest.h>

#include <cstdint>
#include <vector>

GTEST_API_ int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);

    std::vector<uint8_t> m_vector;
    m_vector.resize(10);

    std::vector<uint8_t> data(32);
    EXPECT_EQ(32U, data.size());
    EXPECT_EQ(1,2);
    return RUN_ALL_TESTS();
}
