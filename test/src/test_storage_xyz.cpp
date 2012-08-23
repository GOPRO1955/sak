// Copyright (c) 2012, Steinwurf ApS
// All rights reserved.

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

#include <gtest/gtest.h>
#include <sak/storage.h>


template<class PodType>
void test_vector_helper(uint32_t vector_size)
{
    std::vector<PodType> v(vector_size);

    sak::const_storage cs = sak::storage(v);
    EXPECT_EQ(cs.m_size, vector_size * sizeof(PodType));
    EXPECT_EQ(sak::cast_storage<PodType>(cs), &v[0]);

    sak::mutable_storage ms = sak::storage(v);
    EXPECT_EQ(ms.m_size, vector_size * sizeof(PodType));
    EXPECT_EQ(sak::cast_storage<PodType>(ms), &v[0]);

    sak::const_storage_list csl = sak::storage_list(v);
    EXPECT_EQ(std::distance(csl.begin(), csl.end()), 1U);

    sak::mutable_storage_list msl = sak::storage_list(v);
    EXPECT_EQ(std::distance(msl.begin(), msl.end()), 1U);

    // Check const
    const std::vector<PodType> &v_ref = v;

    sak::const_storage const_cs = sak::storage(v_ref);
    EXPECT_EQ(const_cs.m_size, vector_size * sizeof(PodType));
    EXPECT_EQ(sak::cast_storage<PodType>(const_cs), &v_ref[0]);

    sak::const_storage_list const_csl = sak::storage_list(v_ref);
    EXPECT_EQ(std::distance(const_csl.begin(), const_csl.end()), 1U);
}

TEST(TestStorage, test_storage_function_vector)
{
    uint32_t size = rand() % 100000;
    test_vector_helper<char>(size);
    test_vector_helper<short>(size);
    test_vector_helper<int>(size);
    test_vector_helper<uint8_t>(size);
    test_vector_helper<uint16_t>(size);
    test_vector_helper<uint32_t>(size);
    test_vector_helper<uint64_t>(size);
}


template<class PodType>
void test_buffer_helper(uint32_t vector_size)
{
    std::vector<PodType> v(vector_size);

    PodType *v_data = &v[0];
    uint32_t v_size = vector_size * sizeof(PodType);

    sak::const_storage cs = sak::storage(v_data, v_size);
    EXPECT_EQ(cs.m_size, v_size);
    EXPECT_EQ(sak::cast_storage<PodType>(cs), &v_data[0]);

    sak::mutable_storage ms = sak::storage(v_data, v_size);
    EXPECT_EQ(ms.m_size, v_size);
    EXPECT_EQ(sak::cast_storage<PodType>(ms), &v_data[0]);

    sak::const_storage_list csl = sak::storage_list(v_data, v_size);
    EXPECT_EQ(std::distance(csl.begin(), csl.end()), 1U);

    sak::mutable_storage_list msl = sak::storage_list(v_data, v_size);
    EXPECT_EQ(std::distance(msl.begin(), msl.end()), 1U);

    // Check const
    const PodType *v_data_const = v_data;

    sak::const_storage const_cs = sak::storage(v_data_const, v_size);
    EXPECT_EQ(const_cs.m_size, v_size);
    EXPECT_EQ(sak::cast_storage<PodType>(const_cs), &v_data_const[0]);

    sak::const_storage_list const_csl = sak::storage_list(v_data_const, v_size);
    EXPECT_EQ(std::distance(const_csl.begin(), const_csl.end()), 1U);
}

TEST(TestStorage, test_storage_function_buffer)
{
    uint32_t size = rand() % 100000;
    test_buffer_helper<char>(size);
    test_buffer_helper<short>(size);
    test_buffer_helper<int>(size);
    test_buffer_helper<uint8_t>(size);
    test_buffer_helper<uint16_t>(size);
    test_buffer_helper<uint32_t>(size);
    test_buffer_helper<uint64_t>(size);
}


TEST(TestStorage, test_mutable_to_const_conversion)
{
    uint32_t size = 500;
    std::vector<uint8_t> v(size);

    sak::mutable_storage ms = sak::storage(v);
    sak::const_storage cs = ms;
    cs = ms;

    sak::mutable_storage_list msl = sak::storage_list(v);
    sak::const_storage_list csl = msl;
    csl = msl;

}


