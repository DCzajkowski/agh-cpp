//
// Created by Dariusz Czajkowski on 07/03/17.
//

#include "SimpleForwardList.h"

struct ForwardList {
    int number;
    struct ForwardList * next;
} typedef ForwardList;

ForwardList * CreateNode(int value) {
    struct ForwardList * element = new ForwardList;

    element->number = value;
    element->next = nullptr;

    return element;
}