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

    cout << view.Render({{"name", "Xavier"}}) << std::endl;

    nets::View view2{"Hello {{name}}, {{name}}! How are you doing {{name2}}?"};

    cout << view2.Render({{"name", "Xavier"}, {"name2", "Roman"}});

    nets::View view3{"Hello {{test}}, {{test2}}!"};

    cout << view3.Render({{"test", "{{test2}}"}, {"test2", "{{test}}"}});

    nets::View view4{"Not found {{test2}} {{test}} {{test2}} {{test}}!"};

    cout << view4.Render({{"test2", " :O"}, {"test", " lol "}});

    nets::View view5{"{{template_with_underscore}}<=>{{template_with_underscore_missing}}"};

    cout << view5.Render({{"template_with_underscore", "replacement"}});

    return 0;
}
