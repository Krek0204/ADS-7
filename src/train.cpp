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

int Train::getLength() { int length = 1;
  Car* cur = first;
  if (cur == nullptr) return 0;
  cur->light = true;
  while (true) {
    cur = cur->next;
    countOp++;
    if (cur->light == false) {
      cur->light = true;
      length++;
      continue;
    } else {
      cur->light = false;
      int steps = length - 1;
      while (steps) {
        cur = cur->prev;
        countOp++;
        steps--;
      }
      if (cur->light == false) return length;
      else {
        steps = length - 1;
        while (steps) {
          cur = cur->next;
          countOp++;
          steps--;
        }
        cur->light = true;
        length++;
        continue;
      }
    }
  }
}

int Train::getOpCount() { return countOp; }
