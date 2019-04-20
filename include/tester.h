#ifndef TESTER_H
#define TESTER_H

#include "mocker.h"
#include "list.h"

#define NUMBER_OF_TESTS 1000

template <typename T>
struct Greater {
  bool operator () (T a, T b) {
    return a >= b; // What would happend without the =?
    // Con esta implementación de list.h para insertar un elemento
    // se busca el primer nodo cuyo valor cumpla esta desigualdad con
    // el elemento a insertar (i.e elem >= node -> data)
    // Entonces si tuvieramos una lista
    // [T1] -> [T2] -> [T2] -> [T2] -> [T3] -> NULL
    // Y fueramos a insertar un nodo / T1 > elem = T2 > T3
    // Entonces ese nodo se insertaría entre [T1] y [T2]
    // Pero, si la relación fuera 'a > b'
    // Entonces ese nodo se insertaría entre [T2] y [T3] 
  }
};

template <typename T>
struct Less {
  bool operator () (T a, T b) {
    return a <= b; // What would happend without the =?
    // Explicación análoga a la dada para `Greater`
  }
};

struct Integer {
  typedef int T;
  typedef Less <T> Operation;
};

struct Float {
  typedef float T;
  typedef Greater <T> Operation;
};

class Tester {
private:
  template <typename T>
  static bool isSorted (List<T>& list);

public:
  static void execute();
};

#endif
