#include <gtest/gtest.h>

#include <cstdint>
#include <vector>
#include <algorithm>

namespace sak
{
    namespace {
        /// Helper class that implements a simple buffer. Data can be written
        /// into the buffer which appends it to the existing data. Keeps
        /// track of the amount of data in the buffer.
        class buffer
        {
        public:

            /// Constructs a new zero sized buffer
            buffer()
                : m_size(0)
            { }

            /// Constructs a new buffer with an initial capacity
            buffer(uint32_t capacity)
                : m_size(0)
            {
                m_vector.resize(capacity);
            }

            /// @return the size in bytes of the data in the buffer
            uint32_t size() const
            {
                return m_size;
            }

        private:

            /// Internal storage
            std::vector<uint8_t> m_vector;

            /// The amount on internally stored data
            uint32_t m_size;
        };
    }
}

TEST(TestBuffer, append_to_initialized)
{
    {
        sak::buffer b(10);
        b.size();

        std::vector<uint8_t> data(32, 'x');
        data.size();
    }
}
