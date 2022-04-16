// Copyright 2022 NNTU-CS
#ifndef INCLUDE_TPQUEUE_H_
#define INCLUDE_TPQUEUE_H_
#include <string>

template<typename T, int size>
class TPQueue {
private:
    T arr[150];
    int start1, final1;

public:
    TPQueue() : start1(0), final1(0) {}
    int getSize() {
        return final1 - start1;
    }
    void push(T k) {
        if (getSize() >= size) {
            throw std::string("Full!"); 
        }
        else {
            int temp = final1++;
            while ((--temp >= start1) && (arr[temp % size].prior < k.prior)) {
                arr[(temp + 1) % size] = arr[temp % size];
            }
            arr[(temp + 1) % size] = k;
        }
    }
    T pop(){
        return arr[(start1++) % size];
    }
    T back(){
        return arr[(final1 - 1) % size];
    }
    T front(){
        return arr[(start1) % size];
    }
};

struct SYM {
  char ch;
  int prior;
};

#endif  // INCLUDE_TPQUEUE_H_
