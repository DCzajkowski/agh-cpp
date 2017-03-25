//
// Created by Dariusz Czajkowski on 25/03/2017.
//

#include "SimpleJson.h"

using nets::JsonValue;

JsonValue::JsonValue(map<string, JsonValue> _object_map) {
    object_map = _object_map;
}

optional<JsonValue> JsonValue::ValueByName(const string &name) const {
    
}

string JsonValue::ToString() const {

}