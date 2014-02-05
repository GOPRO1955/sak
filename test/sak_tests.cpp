#include <cstdint>
#include <vector>

int main()
{
    std::vector<uint8_t> m_vector(10);

    std::vector<uint8_t> data(32);
    if (data.size() == 32)
        return 0;
    else
        return 1;
}
