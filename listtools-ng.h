#ifndef LISTTOOLS_NG_INCLUDE_ONCE
#define LISTTOOLS_NG_INCLUDE_ONCE

/*! \file listtools-ng.h
 *  \brief Implementasjon av en enkel lenket liste
 *
 *  Denne filen inneholder hele implementasjonen av listen for å gjøre det
 *  enkelt å inkludere biblioteket i andre prosjekter. Alt som trengs for å
 *  inkludere `listtools-ng` i et annet prosjekt er inkludere denne filen i
 *  kildekoden til prosjektet.
 */

#include <assert.h>

//! En abstrakt klasse som kan arves for å definere et element som kan høre til
//! i en liste.
class element {
  char m_type; //!< Bokstav som definerer typen til elementet.

public:
  //! Lage et element med den gitte typen.
  element(char type) : m_type(type) {}
  virtual ~element() {}

  //! Returnerer typen til elementet. Se `element_type` for mer info.
  /*!
   * \returns En bokstav som representerer typen til elementet.
   */
  char type() const { return m_type; }
};

//! En lenket liste
/*!
 * En liste av elementer der hvert element peker på det neste elementet i
 * listen. Listen egner seg best som en [FIFO-kø (First In First
 * Out)](https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)) eller
 * som en "vanlig" liste i situasjoner der man ofte trenger å sette inn verdier
 * midt i listen. Listen kan også brukes som en [stack/LIFO-kø (Last In First
 * Out)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)), men en
 * [`std::vector`](http://www.cplusplus.com/reference/vector/vector/) passer
 * bedre i det tilfellet.
 *
 * ## Eksempel
 *
 * ```cpp
 * #include "listtools-ng.h"
 * #include <iostream>
 *
 * struct el : public element {
 *   int m_val;
 *
 *   el(int val) : element('E'), m_val(val) {}
 * };
 *
 * int main() {
 *   list list;
 *
 *   list.push_front(new el(5));
 *   std::cout << ((el *)list.front())->m_val << std::endl; // Printer '5'
 *
 *   list.push_front(new el(10));
 *   std::cout << ((el *)list.front())->m_val << std::endl; // Printer '10'
 *
 *   // Fjern det første elementet i listen
 *   el *front = (el *)list.pop_front();
 *   std::cout << front->m_val << std::endl;                // Printer '10'
 *   std::cout << ((el *)list.front())->m_val << std::endl; // Printer '5'
 * }
 * ```
 */
class list {

  //! En node i listen som inneholder en verdi og en peker til den neste
  //! noden in listen
  struct Node {
    //! Verdien til denne noden
    element *value;
    //! En peker til neste node
    Node *next;
  };

private:
  //! Det første elementet i listen
  Node *m_head;
  //! Det siste elementet i listen
  Node *m_tail;

public:
  //! Lager en ny tom liste
  list() : m_head(nullptr), m_tail(nullptr) {}
  //! Sletter alle nodene i listen fra minne
  ~list() {
    Node *current = m_head;
    // Itererer over alle nodene i listen og fjern dem fra minne.
    while (current != nullptr) {
      Node *tmp = current->next;
      delete current->value;
      delete current;
      current = tmp;
    }
  }

  //! Legg til et nytt element foran i listen.
  //!
  //! **NB!** `new_value` må være allokert med `new`, og så lenge elementet er
  //! en del av listen så vil det bli deallokert når listen ødelegges.
  /*!
   * \param new_value En peker til verdien som skal legges foran i listen.
   */
  void push_front(element *new_value) {
    // Lag en ny node som peker på det nåværende hodet av listen.
    Node *new_head = new Node{
        new_value,
        m_head,
    };
    m_head = new_head;

    if (m_tail == nullptr) {
      // Listen er tom, så den nye noden er både hodet og halen.
      m_tail = m_head;
    }
  }

  //! Se på det første elementet i listen, hvis det eksisterer.
  /*!
   * \return En peker til det første elementet i listen, eller `nullptr` hvis
   * listen er tom.
   */
  element *front() { return m_head != nullptr ? m_head->value : nullptr; }

  //! Fjern og returner det første elementet i listen, hvis det eksisterer.
  //!
  //! **NB!** Det er opp til brukeren å deallokere elementet med `delete`.
  /*!
   * \return En peker til det første elementet i listen, ellers `nullptr` hvis
   * listen er tom.
   */
  element *pop_front() {
    if (m_head == nullptr)
      return nullptr;

    // Lagre verdiene fra den første noden før vi deallokerer den.
    element *val = m_head->value;
    Node *new_head = m_head->next;
    delete m_head;

    m_head = new_head;

    if (m_head == nullptr)
      // Listen er tom siden det nye hodet er tomt.
      m_tail = nullptr;

    return val;
  }
};

#endif /* LISTTOOLS_NG_INCLUDE_ONCE */
