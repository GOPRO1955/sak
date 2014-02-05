#include <gtest/gtest.h>

#include <cstdint>
#include <vector>

namespace sak
{

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
        /// Appends data to the end of the buffer
        /// @param data the bytes to append to the end of the buffer
        /// @param size the size of the data in bytes
        void append(const uint8_t* data, uint32_t size)
        {
            assert(data != 0);
            assert(size > 0);

            if (m_size + size > m_vector.size())
            {
                m_vector.resize(m_size + size);
            }

            std::copy_n(data, size, &m_vector[m_size]);
            m_size += size;
        }
        /// Appends data to the end of the buffer
        /// @param data_start the start address of the of the data
        /// @param data_end the end address of the data
        void append(const uint8_t* data_start, const uint8_t* data_end)
        {
            assert(data_start != 0);
            assert(data_end != 0);
            assert(data_start < data_end);

            uint32_t size = static_cast<uint32_t>(data_end - data_start);
            append(data_start, size);
        }
        /// Appends data to the end of the buffer
        /// @param storage the data to append
        template<class Storage>
        void append(const Storage& storage);

        /// @return a pointer to the start of the data in the buffer
        const uint8_t* data() const
        {
            return &m_vector[0];
        }

        /// @return a pointer to the start of the data in the buffer
        uint8_t* data()
        {
            return &m_vector[0];
        }

        /// @return the size in bytes of the data in the buffer
        uint32_t size() const
        {
            return m_size;
        }

        /// Re-sizes the buffer to a specific size
        /// If size is greater than the current size, the buffer is extended
        /// to make it size bytes with the extra bytes added to the end.
        /// The new bytes are uninitialized.
        /// If size is less than the current size, bytes are removed from
        /// the end.
        void resize(uint32_t size)
        {
            // Currently our re-allocation strategy is not
            // to "shrink" the buffer. If at some point this
            // should become important in an application
            // we could add that possibility as a reallocation-policy

            if (size <= m_vector.size())
            {
                m_size = size;
            }
            else
            {
                m_vector.resize(size);
                m_size = size;
            }
        }

        /// Sets the buffer to zero size
        void buffer::clear()
        {
            m_size = 0;
        }

    private:

        /// Internal storage
        std::vector<uint8_t> m_vector;

        /// The amount on internally stored data
        uint32_t m_size;
    };

    template<class Storage>
    inline void buffer::append(const Storage& storage)
    {
        for (auto it = storage.begin(); it != storage.end(); ++it)
        {
            append(it->m_data, it->m_size);
        }
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
