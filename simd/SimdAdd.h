#pragma once

#include <vector>
#include <iostream>
#include <immintrin.h>

unsigned int FLOAT_COUNT_FOR_AVX_REGISTER = 8u;

std::vector<float> simdAdd(const std::vector<float> &vec1, const std::vector<float> &vec2) {
    std::vector<float> result(vec1.size());

    const unsigned int VECTORIZABLE_CHUNK_COUNT = vec1.size() - (vec1.size() % FLOAT_COUNT_FOR_AVX_REGISTER);

    unsigned int i = 0u;

    // Sum operation with simd
    for (; i < VECTORIZABLE_CHUNK_COUNT; i += FLOAT_COUNT_FOR_AVX_REGISTER) {
        auto vec1Register = _mm256_loadu_ps(vec1.data() + i);
        auto vec2Register = _mm256_loadu_ps(vec2.data() + i);

        auto intermediateSum = _mm256_add_ps(vec1Register, vec2Register);

        _mm256_storeu_ps(result.data() + i, intermediateSum);
    }

    // Handle not vectorized section
    for (; i < result.size(); ++i) {
        result[i] = vec1[i] + vec2[i];
    }

    return result;
}
