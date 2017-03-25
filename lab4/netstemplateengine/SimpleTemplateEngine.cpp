//
// Created by Dariusz Czajkowski on 25/03/2017.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
#include <boost/xpressive/xpressive.hpp>

using nets::View;

using namespace boost::xpressive;

View::View(string _view) {
    view = _view;
}

string View::Render(const unordered_map <string, string> &model) const {
    string _view = view;

    for (const auto & replacement : model) {
        sregex r = sregex::compile("\\{\\{" + replacement.first + "\\}\\}");
        _view = regex_replace(_view, r, replacement.second);
    }

    sregex r = sregex::compile("\\{\\{\\w+\\}\\}");
    _view = regex_replace(_view, r, "");

    return _view;
}
