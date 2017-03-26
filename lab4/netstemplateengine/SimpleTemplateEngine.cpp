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

    std::regex pattern("\\{\\{\\w+\\}\\}");

    auto words_begin = std::sregex_iterator(_view.begin(), _view.end(), pattern);
    auto words_end = std::sregex_iterator();

    for (std::sregex_iterator i = words_begin; i != words_end; ++i) {
        bool replaced = false;
        std::cout << std::endl << std::endl << "|" << i->str() << "|" << std::endl;
        for (const auto & replacement : model) {
            if ("{{" + replacement.first + "}}" == i->str()) {
                std::cout << "1. " << _view << std::endl;
                _view.replace(i->position(), i->str().size(), replacement.second);
                std::cout << "2. " << _view << std::endl;

                replaced = true;
//                break;
            }
        }

        std::cout << "swapped?: " << replaced << std::endl;

        if (!replaced) {
            _view.replace(i->position(), i->str().size(), "");
        }
    }

//    _view = regex_replace(_view, pattern, "");

    return _view;
}
