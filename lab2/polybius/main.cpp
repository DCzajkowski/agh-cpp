//
// Created by Dariusz Czajkowski on 12/03/17.
//

#include <string>
#include <iostream>
#include <fstream>
#include "Polybius.h"

using namespace std;

int main(int argc, char const *argv[]) {
    string input = argv[1];
    string output = argv[2];
    int encrypt = atoi(argv[3]);

    string input_contents = "";

    ifstream input_file(input);
    if (input_file.is_open()) {
        string contents((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
        input_contents = contents.c_str();

        input_file.close();
    } else {
        cout << "We were unable to open the file provided.";
        exit(1);
    }


    string output_contents = "";

    if (encrypt) {
        output_contents = PolybiusCrypt(input_contents);
    } else {
        output_contents = PolybiusDecrypt(input_contents);
    }

    ofstream output_file;
    output_file.open(output);
    output_file << output_contents;
    output_file.close();

    return 0;
}
