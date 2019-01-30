# listtools-ng

[![Build Status](https://travis-ci.com/barskern/listtools-ng.svg?token=S3nA1j4MQ8fzYt5KzyxX&branch=master)](https://travis-ci.com/barskern/listtools-ng)
![](https://img.shields.io/badge/status-under--utvikling-orange.svg)

**listtools-ng** er et bibliotek bestående av en headerfil som implementerer en enkel lenket liste. Hovedmålet med biblioteket er å gi en **enkel**, **minimal** og **elegant** abstraksjon over en lenket liste.

## Hvordan bruke prosjektet

Alt som trengs for å få tilgang til biblioteket er å skrive  `#include "listtools-ng.h"` i ditt prosjekt.

## Eksempel

```cpp
#include "listtools-ng.h"
#include <iostream>

int main() {
  List<int> list;

  list.push_front(5);
  std::cout << list.front().value() << std::endl; // Printer '5'

  list.push_front(10);
  std::cout << list.front().value() << std::endl; // Printer '10'

  // Fjern det første elementet i listen
  int front = list.pop_front().value();
  std::cout << front << std::endl;                // Printer '10'
  std::cout << list.front().value() << std::endl; // Printer '5'
}

```

Se i mappen `examples` for flere eksempler på bruk av biblioteket.

## Dokumentasjon

Planen at dokumentasjonen skal være tilgjengelig på gjennom nettside, men inntil videre må brukeren selv generere dokumentasjonen. Dokumentasjonen kan genereres ved hjelp av `make docs`. For å kunne generere dokumentasjonen må man ha [`make`](https://www.gnu.org/software/make/) og [`doxygen`](http://doxygen.nl/) installert. Når dokumentasjonen er generert finner du `index.html` filen, som er startpunktet for dokumentasjonen, i `docs` mappen.
