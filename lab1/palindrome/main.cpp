#include <iostream>
#include "Palindrome.h"

int main() {
    if (is_palindrome("LOL")) {
        std::cout << "'LOL' is a palindrome" << std::endl;
    } else {
        std::cout << "'LOL' is not a palindrome" << std::endl;
    }

    if (is_palindrome("Hello")) {
        std::cout << "'Hello' is a palindrome" << std::endl;
    } else {
        std::cout << "'Hello' is not a palindrome" << std::endl;
    }

    return 0;
}
