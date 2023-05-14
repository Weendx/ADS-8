// Copyright 2021 NNTU-CS
#include <iostream>
#include "train.h"


Train::Cage* Train::createCage(const bool& lampState) {
    Cage* cage = new Cage();
    cage->light = lampState;
    if (last == nullptr) {
        cage->prev = cage;
        cage->next = cage;
        return cage;
    }
    cage->prev = last;
    cage->next = first;
    last->next = cage;
    last = cage;
    return cage;
}

Train::Train() : first(nullptr), last(nullptr), countCages(0), countOp(0) {}
Train::~Train() {
    auto item = first;
    while (item != first) {
        std::cout << "destructor" << std::endl;
        item = item->next;
        delete item->prev;
    }
    delete first;
    first = nullptr;
    last = nullptr;
}

void Train::addCage(bool light) {
    auto cage = createCage(light);
    if (first == nullptr) {
        first = cage;
        last = cage;
    }
}

int Train::getOpCount() {
    return countOp;
}

int Train::getLength() {
    if (!first || countCages)
        return countCages;
    std::cout << "Train::getLength\n";
    auto item = first;

        item->light = true;
        countCages = 1;
    while (true) {
        item = item->next;
        ++countOp;

        if (item->light == false) {
            ++countCages;
        } else {
            item->light = false;
            for (int i = countCages; i > 0; --i) {
                item = item->prev;
                ++countOp;
            }
            if (item->light == false)
                return countCages;
            countCages = 1;
        }
    }
}
