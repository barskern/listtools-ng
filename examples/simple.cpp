#include "../listtools-ng.h"
#include <iostream>

int main() {
  list<int> list;

  list.push_front(5);
  std::cout << list.front().value() << std::endl; // Printer '5'

  list.push_front(10);
  std::cout << list.front().value() << std::endl; // Printer '10'

  // Fjern det første elementet i listen
  int front = list.pop_front().value();
  std::cout << front << std::endl;                // Printer '10'
  std::cout << list.front().value() << std::endl; // Printer '5'
}
