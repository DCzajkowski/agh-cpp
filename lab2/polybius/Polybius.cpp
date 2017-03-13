//
// Created by Dariusz Czajkowski on 12/03/17.
//

#include "Polybius.h"
#include <string>
#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const map<char, string> polybius_square = {
    {'A', "11"}, {'B', "12"}, {'C', "13"}, {'D', "14"}, {'E', "15"},
    {'F', "21"}, {'G', "22"}, {'H', "23"}, {'I', "24"}, {'J', "24"}, {'K', "25"},
    {'L', "31"}, {'M', "32"}, {'N', "33"}, {'O', "34"}, {'P', "35"},
    {'Q', "41"}, {'R', "42"}, {'S', "43"}, {'T', "44"}, {'U', "45"},
    {'V', "51"}, {'W', "52"}, {'X', "53"}, {'Y', "54"}, {'Z', "55"},
};

string PolybiusCrypt(string message) {
    string output = "";

    for (int i = 0; i < message.length(); i++) {
        for (const auto & letter : polybius_square) {
            if (toupper(message[i]) == letter.first) {
                output += letter.second;

                break;
            }
        }
    }

    return output;
}

string PolybiusDecrypt(string crypted) {
    string output = "";

    for (int i = 0; i < crypted.length(); i += 2) {
        for (const auto & letter : polybius_square) {
            if (crypted.substr(i, 2) == letter.second) {
                output += tolower(letter.first);

                break;
            }
        }
    }

    return output;
}
