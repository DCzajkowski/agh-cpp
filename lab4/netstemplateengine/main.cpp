//
// Created by Dariusz Czajkowski on 25/03/2017.
//

#include <iostream>
#include <map>
#include "SimpleTemplateEngine.h"

using std::cout;
using std::map;

int main() {
    nets::View view{"Hello {{name}}!"};

    cout << view.Render({{"name", "Xavier"}});

    return 0;
}
