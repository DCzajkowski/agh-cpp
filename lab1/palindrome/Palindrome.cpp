//
// Created by mwypych on 02.02.17.
//
#include <string>
#include "Palindrome.h"

bool is_palindrome(std::string str) {
    int length = str.length();


    for (int i = 0; i < length - i - 1; i++) {
        if (str[i] != str[length - i - 1]) {
            return false;
        }
    }
    return true;
}