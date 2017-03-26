//
// Created by Dariusz Czajkowski on 25/03/2017.
//

#include "SimpleJson.h"

using nets::JsonValue;
using std::to_string;

JsonValue::JsonValue(map<string, JsonValue> _value) {
    m = _value;
}

JsonValue::JsonValue(double _value) {
    d = _value;
}

JsonValue::JsonValue(int _value) {
    i = _value;
}

JsonValue::JsonValue(bool _value) {
    b = _value;
}

JsonValue::JsonValue(string _value) {
    s = _value;
}

JsonValue::JsonValue(vector<JsonValue> _value) {
    v = _value;
}

optional<JsonValue> JsonValue::ValueByName(const string &name) const {

}

string JsonValue::ToString() const {
    if ((bool) s) {
        return "\"" + s + "\"";
    } else if ((bool) d) {
        return std::to_string(d);
    } else if ((bool) i) {
        return std::to_string(i);
    } else if ((bool) b) {
        if (b) {
            return "true";
        } else {
            return "false";
        }
    } else if ((bool) v) {
        return "I am a vector!";
    } else if ((bool) m) {
        return "I am a map!";
    }
}
