#include "../listtools-ng.h"
#include <iostream>

struct el : public element {
  int m_val;

  el(int val) : element('E'), m_val(val) {}
};

int main() {
  list list;

  list.push_front(new el(5));
  std::cout << ((el *)list.front())->m_val << std::endl; // Printer '5'

  list.push_front(new el(10));
  std::cout << ((el *)list.front())->m_val << std::endl; // Printer '10'

  // Fjern det første elementet i listen
  el *front = (el *)list.pop_front();
  std::cout << front->m_val << std::endl;                // Printer '10'
  std::cout << ((el *)list.front())->m_val << std::endl; // Printer '5'
}
