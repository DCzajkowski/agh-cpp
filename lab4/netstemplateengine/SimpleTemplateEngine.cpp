//
// Created by Dariusz Czajkowski on 25/03/2017.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
#include <regex>

using nets::View;
using std::cout;
using std::endl;
using std::regex_replace;
using std::regex;

View::View(string _view) {
    view = _view;
}

string View::Render(const unordered_map <string, string> &model) const {
    string _view = view;

    for (const auto & replacement : model) {
        regex r ("/{{" + replacement.first + "}}/");
        _view = regex_replace(_view, r, replacement.second);
    }

    regex r ("/{{\\w+}}/");
    _view = regex_replace(_view, r, "");

    return _view;
}
