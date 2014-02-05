#include <gtest/gtest.h>

#include <cstdint>
#include <vector>

int main()
{
    std::vector<uint8_t> m_vector;
    m_vector.resize(10);

    std::vector<uint8_t> data(32);
    EXPECT_EQ(32U, data.size());
}
