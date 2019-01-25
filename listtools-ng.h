#ifndef LISTTOOLS_NG_INCLUDE_ONCE
#define LISTTOOLS_NG_INCLUDE_ONCE

/*! \file listtools-ng.h
 *  \brief Implementasjon av en enkel lenket liste
 *
 *  Denne filen inneholder hele implementasjonen av listen i for å gjøre det
 *  enkelt å inkludere biblioteket in andre prosjekter. Alt som trengs for å
 *  inkludere `listtools-ng` i et annet prosjekt er `#include "listtools-ng.h"`.
 *
 */

//! En lenket liste

//! Listen sørger for at alle elementene er linket sammen ved at hvert element
//! i listen inneholder en peker til det neste elementet. Listen kan brukes som
//! en [FIFO-kø (First In First Out)](https://en.wikipedia.org/wiki/FIFO_(computing_and_electronics)) og en
//! [stack/LIFO-kø (Last In First Out)](https://en.wikipedia.org/wiki/Stack_(abstract_data_type)).
//!
//! Listen er generisk over typen `T`, altså de ulike verdiene den kan holde.
//! Det vil si at hvis man vil definere en liste med heltall, så gjøres det med
//! `List<int>`. Videre kan man gjøre det samme for alle andre typer i C++.
//! Fordelen ved å bruke en generisk type, er at vi slipper å holde styr på
//! hvilken type en liste inneholder. Kompilatoren sørger for at hvis man
//! definerer en liste som inneholder heltall, så kan man kun legge til heltall
//! i listen. Dersom man prøver å legge til et flyttall i en liste med heltall
//! vil man få en kompilasjonsfeil. Resultatet av dette er at vi får et trygt
//! API som er vanskelig å misbruke.
//!
//! ## Eksempel
//!
//! ```cpp
//! int main(){
//!     List<float> list;
//!
//!     list.push_front(5);
//!     cout << *list.front() << endl;
//!
//!     list.push_front(10);
//!     cout << *list.front() << endl;
//! }
//! ```
//!
//! #### Utgangsverdier
//!
//! ```
//! 5
//! 10
//! ```
template <class T> class List {

  //! En node i listen som inneholder en verdi og en peker til den neste
  //! noden in listen
  struct Node {
    //! Verdien til denne noden
    T value;
    //! En peker til neste node
    Node *next;
  };

private:
  //! Det første elementet i listen
  Node *head;
  //! Det siste elementet i listen
  Node *tail;

public:
  //! Lager en ny tom liste
  List() : head(nullptr), tail(nullptr) {}
  //! Sletter alle nodene i listen fra minne
  ~List() {
    Node *current = this->head;
    // Itererer over alle nodene i listen og fjerner dem fra minne
    while (current != nullptr) {
      Node *tmp = current->next;
      delete current;
      current = tmp;
    }
  }

  //! Legg til et nytt element foran i listen

  //! \param new_value verdien som skal legges foran i listen
  void push_front(T new_value) {
    // Lag en ny node som peker på det nåværende hodet av listen
    Node *new_head = new Node{
        new_value,
        this->head,
    };
    this->head = new_head;

    // Hvis halen er null (listen er tom), så er den nye noden både hode og hale
    if (this->tail == nullptr) {
      this->tail = this->head;
    }
  }

  //! Se på det første elementet i listen, hvis det eksisterer

  //! \return enten en peker til den første verdien eller en `nullptr` hvis listen
  //! er tom
  T *front() {
    if (this->head == nullptr)
      return nullptr;
    return &this->head->value;
  }
};

#endif
