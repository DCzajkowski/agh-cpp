//
// Created by Dariusz Czajkowski on 14/03/17.
//

#include <CCounter.h>
#include <iostream>

using namespace ccounter;
using std::unique_ptr;
using std::cout;
using std::endl;

int main() {
    unique_ptr<Counter> counter = Init();

    Inc("a", &counter);
    Inc("b", &counter);
    Inc("a", &counter);

    for (const auto & count : counter->values) {
        cout << count.first << "|" << count.second << endl;
    }

    return 0;
}