//
// Created by Dariusz Czajkowski on 12/03/17.
//

#include <string>
#include <iostream>
#include <fstream>
#include "Polybius.h"

using namespace std;

int main(int argc, char const *argv[]) {
    // Input file name
    string input = argv[1];
    // Output file name
    string output = argv[2];
    // Mode
    int encrypt = atoi(argv[3]);

    // Input file
    ifstream input_file(input);

    // If file cannot be open, flash an error
    if (!input_file.is_open()) {
        cout << "We were unable to open the file provided.";
        exit(1);
    }

    // Get input file contents
    string contents((istreambuf_iterator<char>(input_file)), istreambuf_iterator<char>());
    string input_contents = contents.c_str();

    input_file.close();

    // Open the output file and insert contents
    ofstream output_file;
    output_file.open(output);
    output_file << ((encrypt) ? PolybiusCrypt(input_contents) : PolybiusDecrypt(input_contents));
    output_file.close();

    return 0;
}
