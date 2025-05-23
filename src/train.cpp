// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train():countOp(0), first(nullptr) {}

void Train::addCar(bool light_t) { Car* car = new Car;
  car->light = light_t;
  car->prev = nullptr;
  car->next = nullptr;
  if (first == nullptr) {
    first = car;
    first->prev = first;
    first->next = first;
  } else {
    Car* end = first->prev;
    car->next = first;
    car->prev = end;
    end->next = car;
    first->prev = car;
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
    while (back--) {
      cur = cur->prev;
      countOp++;
    }
    if (cur->light == false) return steps;
  }
}

int Train::getOpCount() { return countOp; }
