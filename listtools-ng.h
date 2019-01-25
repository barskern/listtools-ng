#ifndef LISTTOOLS_NG_INCLUDE_ONCE
#define LISTTOOLS_NG_INCLUDE_ONCE

/*! \file listtools-ng.h
 *  \brief Implementasjon av ulike typer lister og køer
 *
 *  Denne filen inneholder alle implementasjonene i dette biblioteket for å
 *  gjøre det enkelt å inkludere i andre prosjekter. Se hver enkelt liste for
 *  eksempler på hvordan de skal brukes.
 */

//! En liste med elementer som ligger spredt i minne.

//! Listen sørger for at alle elementene er linket sammen ved at et element
//! inneholder en peker til det neste elementet.
//!
//! Listen er generisk over typen til verdiene den holder, det vil si at man
//! kan definere listen for mange ulike datatyper, uten at man trenger å
//! dynamisk holde styr på innholdet. Fordelen med dette er at vi får et
//! tryggere API som er vanskelig å misbruke. Se eksemplene for å se hvordan
//! listen kan brukes.
template <class T> class List {

  //! En node i listen som inneholder en verdi og en peker til den neste
  //! node in listen
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
  List() : head(nullptr), tail(nullptr) {}
  ~List() {
    Node *current = this->head;
    // Iterer over alle nodene i listen og fjern dem fra minne
    while (current != nullptr) {
      Node *tmp = current->next;
      delete current;
      current = tmp;
    }
  }
  //! Legg til et nytt element foran i listen
  void push_front(T new_value) {
    // Lag en ny node som peker på det nåværende hodet av listen, og sett den
    // nye noden som det nye hodet av listen vår
    this->head = new Node{
        new_value,
        this->head,
    };
    // Hvis vi ikke allerede har en hale (listen er tom), så er den nåværende
    // noden både hode og halen
    if (this->tail == nullptr) {
        this->tail = this->head;
    }
  }
  //! Se på det første elementet i listen, hvis det eksisterer
  T* front() {
      if (this->head == nullptr) return nullptr;
      return &this->head->value;
  }
};

#endif
