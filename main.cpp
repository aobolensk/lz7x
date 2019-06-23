#include <iostream>
#include <cassert>
#include "lz77.h"
#include "lz78.h"

void test() {
    #define ASSERT_EQ(expected, actual) \
        assert((expected) == (actual))

    // LZ77
    for (size_t buf_size = 1; buf_size < 20; ++buf_size) {
        ASSERT_EQ("abacabacabadaca",
                LZ77::decode(LZ77::encode("abacabacabadaca", buf_size)));
    }
    ASSERT_EQ("abcdefghijklmnopqrstuvwxyz",
            LZ77::decode(LZ77::encode("abcdefghijklmnopqrstuvwxyz", 4)));
    ASSERT_EQ("a",
            LZ77::decode(LZ77::encode("a", 2)));
    ASSERT_EQ("aba",
            LZ77::decode(LZ77::encode("aba", 2)));
    ASSERT_EQ("abaaba",
            LZ77::decode(LZ77::encode("abaaba", 2)));
    ASSERT_EQ("abc",
            LZ77::decode(LZ77::encode("abc", 2)));

    // LZ78
    std::cout << "abacabacabadaca" << std::endl;
    std::cout << LZ78::decode(LZ78::encode("abacabacabadaca")) << std::endl;
    ASSERT_EQ("abacabacabadaca",
            LZ78::decode(LZ78::encode("abacabacabadaca")));
    ASSERT_EQ("abcdefghijklmnopqrstuvwxyz",
            LZ78::decode(LZ78::encode("abcdefghijklmnopqrstuvwxyz")));
    ASSERT_EQ("a",
            LZ78::decode(LZ78::encode("a")));
    ASSERT_EQ("aba",
            LZ78::decode(LZ78::encode("aba")));
    ASSERT_EQ("abaaba",
            LZ78::decode(LZ78::encode("abaaba")));
    ASSERT_EQ("abc",
            LZ78::decode(LZ78::encode("abc")));

    #undef ASSERT_EQ
    std::cout << "Tests are successfully passed!" << std::endl;
}

int main() {
    test();
    return 0;
}
