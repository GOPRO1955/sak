#include <cstdint>
#include <vector>
#include <iostream>

int main()
{
    std::vector<uint8_t> v1(10);
    std::cout << v1.size() << std::endl;
    std::vector<uint8_t> v2(32);
    std::cout << v2.size() << std::endl;
}
