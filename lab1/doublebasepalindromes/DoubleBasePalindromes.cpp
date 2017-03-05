//
// Created by mwypych on 02.02.17.
//
#include <cstdint>
#include <string>
#include <bitset>
#include "DoubleBasePalindromes.h"
#include "../palindrome/Palindrome.h"

uint64_t DoubleBasePalindromes(int max_value_exclusive) {
    uint64_t result = 0;

    for (int i = 1; i <= max_value_exclusive; i++) {
        if (is_palindrome(std::to_string(i)) && is_palindrome(std::bitset<64>(i).to_string())) {
            result += i;
        }
    }

    return result;
}
