// Copyright (c) 2012-2013, Steinwurf ApS
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//     * Neither the name of Steinwurf ApS nor the
//       names of its contributors may be used to endorse or promote products
//       derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
// ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL Steinwurf ApS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
// (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
// ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
// (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
// SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include <cstdint>
#include <ctime>

#include <gtest/gtest.h>

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
        EXPECT_EQ(0U, b.size());

        std::vector<uint8_t> data(32, 'x');
        EXPECT_EQ(32U, data.size());
    }
}

GTEST_API_ int main(int argc, char** argv)
{
    srand(static_cast<uint32_t>(time(0)));

    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

