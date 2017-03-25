//
// Created by Dariusz Czajkowski on 25/03/2017.
//

#ifndef JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
#define JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H

#include <string>
#include <unordered_map>

using std::string;
using std::unordered_map;

namespace nets {
    class View {
        protected:
            string view;

        public:
            View(string _view);

            string Render(const unordered_map <string, string> &model) const;
    };
}

#endif //JIMP_EXERCISES_SIMPLETEMPLATEENGINE_H
