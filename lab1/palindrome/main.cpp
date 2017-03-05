#include <iostream>
#include "Palindrome.h"

int main() {
    if (is_palindrome("kajak")) {
        std::cout << "'Kajak' jest palindromem" << std::endl;
    } else {
        std::cout << "'Kajak' nie jest palindromem" << std::endl;
    }

    if (is_palindrome("Hejka")) {
        std::cout << "'Hejka' jest palindromem" << std::endl;
    } else {
        std::cout << "'Hejka' nie jest palindromem" << std::endl;
    }

    return 0;
}
