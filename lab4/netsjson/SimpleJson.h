//
// Created by Dariusz Czajkowski on 25/03/2017.
//

#ifndef JIMP_EXERCISES_SIMPLEJSON_H
#define JIMP_EXERCISES_SIMPLEJSON_H

#include <experimental/optional>
#include <string>
#include <map>
#include <vector>

using std::string;
using std::map;
using std::vector;
using std::experimental::optional;

namespace nets {
    class JsonValue {
        protected:
            map<string, JsonValue> object_map;

        public:
            JsonValue(map<string, JsonValue> _object_map);
            JsonValue(double value);
            JsonValue(int value);
            JsonValue(string value);
            JsonValue(vector<JsonValue> value);
        
            optional<JsonValue> ValueByName(const string &name) const;
            string ToString() const;
    };
}

#endif //JIMP_EXERCISES_SIMPLEJSON_H
