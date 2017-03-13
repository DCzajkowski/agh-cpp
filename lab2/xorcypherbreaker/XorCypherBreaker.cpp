//
// Created by Dariusz Czajkowski on 13/03/17.
//

#include "XorCypherBreaker.h"

#define ALPHABET_SIZE 26
#define FIRST_LOWERCASE_ASCII_LETTER 97

using namespace std;

string XorCypherBreaker(
    const vector<char> &cryptogram,
    int key_length,
    const vector<string> &dictionary
) {
    // I make a copy of the cryptogram so that I can easily manipulate it
    vector<char> cryptogram_copy = cryptogram;

    // We assume the password is three-letter
    string password = {'0', '0', '0'};

    // The password that is the correct one
    string output;

    // A global (in current scope) counter that holds a number of occurrences of currently most probable password
    int counter = 0;

    // Go through each lowercase letter in the alphabet for each letter in the being guessed password
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        for (int j = 0; j < ALPHABET_SIZE; j++) {
            for (int k = 0; k < ALPHABET_SIZE; k++) {
                // Get track of the number of occurrences of currently being guessed password
                int occurrences = 0;

                // Set each password's letter to the ASCII code of the loop
                password[0] = FIRST_LOWERCASE_ASCII_LETTER + i;
                password[1] = FIRST_LOWERCASE_ASCII_LETTER + j;
                password[2] = FIRST_LOWERCASE_ASCII_LETTER + k;

                // XOR each cryptogram three letter sequence by a generated password
                for (int l = 0; l + 2 < cryptogram_copy.size(); l += 3) {
                    cryptogram_copy[l] = cryptogram[l] ^ password[0];
                    cryptogram_copy[l + 1] = cryptogram[l + 1] ^ password[1];
                    cryptogram_copy[l + 2] = cryptogram[l + 2] ^ password[2];
                }

                // Go through each cryptogram letter
                for (int m = 0; m + 2 < cryptogram_copy.size(); m++) {
                    string guessed_password = "";
                    guessed_password += cryptogram_copy[m];
                    guessed_password += cryptogram_copy[m + 1];
                    guessed_password += cryptogram_copy[m + 2];

                    // If generated password is in the dictionary, +1 occurrences of current password
                    if (find(dictionary.begin(), dictionary.end(), guessed_password) != dictionary.end()) {
                        occurrences += 1;
                    }
                }

                // If occurrences of currently generated password is greater than the password
                // having currently biggest possibility, then put it in place as a more
                // probable to be the correct password and reset the counter to the
                // current password's occurrences number
                if (occurrences >= counter) {
                    counter = occurrences;

                    output = password;
                }
            }
        }
    }

    return output;
}
