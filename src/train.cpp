// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train():countOp(0), first(nullptr) {}

void Train::addCar(bool light_t) {
  if (first == nullptr) {
    first = new Car;
    first->light = light_t;
    first->next = nullptr;
    first->prev = nullptr;
  } else {
    Car* cur = first;
    while (cur->next != nullptr) {
      cur = cur->next;
    }
    cur->next = new Car;
    cur->next->light = light_t;
    cur->next->prev = cur;
    cur->next->next = first;
    first->prev = cur->next;
  }
}

int Train::getLength() {
  Car* cur = first;
  if (cur == nullptr) return 0;
  cur->light = true;
  while (true) {
    int steps = 0;
    do {
      cur = cur->next;
      countOp++;
      steps++;
    } while (cur->light == false);
    cur->light = false;
    int back = steps;
    while(back--) {
      cur = cur->prev;
      countOp++;
    }
    if (cur->light == false) return steps;
  }
}

int Train::getOpCount() { return countOp; }
