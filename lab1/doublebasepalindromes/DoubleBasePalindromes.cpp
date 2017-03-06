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
    std::string binary;

    for (int i = 1; i <= max_value_exclusive; i++) {
        binary = std::bitset<64>(i).to_string();
        binary.erase(0, binary.find_first_not_of('0'));
        if (is_palindrome(std::to_string(i)) && is_palindrome(binary)) {
            result += i;
        }
    }

    return result;
}