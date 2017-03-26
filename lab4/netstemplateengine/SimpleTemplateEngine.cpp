//
// Created by Dariusz Czajkowski on 25/03/2017.
//

#include "SimpleTemplateEngine.h"
#include <iostream>
#include <boost/xpressive/xpressive.hpp>
#include <regex>
#include <iterator>

using nets::View;

using namespace boost::xpressive;

View::View(string _view) {
    view = _view;
}

string View::Render(const unordered_map <string, string> &model) const {
    string _view = view;

    for (const auto & replacement : model) {
        std::regex pattern("\\{\\{" + replacement.first + "\\}\\}");

        auto words_begin = std::sregex_iterator(_view.begin(), _view.end(), pattern);
        auto words_end = std::sregex_iterator();


        for (std::sregex_iterator i = words_begin; i != words_end; i++) {
            _view.replace(i->position(), i->str().size(), replacement.second);
        }
    }

    // sregex r = sregex::compile("\\{\\{\\w+\\}\\}");
    // _view = regex_replace(_view, r, "");

    return _view;
}
