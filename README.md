# listtools-ng

[![Build Status](https://travis-ci.com/barskern/listtools-ng.svg?token=S3nA1j4MQ8fzYt5KzyxX&branch=master)](https://travis-ci.com/barskern/listtools-ng)
![](https://img.shields.io/badge/status-under--utvikling-orange.svg)

**listtools-ng** er et bibliotek bestående av en headerfil som implementerer en enkel lenket liste. Hovedmålet med biblioteket er å gi en **enkel**, **minimal** og **elegant** abstraksjon over en lenket liste.

## Hvordan bruke prosjektet

Alt som trengs for å få tilgang til biblioteket er å skrive  `#include "listtools-ng.h"` i ditt prosjekt, etter at du har lastet ned headerfilen.

## Eksempel

```cpp
#include "listtools-ng.h"
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

```

Se i mappen `examples` for flere eksempler på bruk av biblioteket.

## Dokumentasjon

Dokumentasjonen ligger på [barskern.no/listtools-ng](http://barskern.no/listtools-ng).

Man kan også generere dokumentasjonen lokalt. For å kunne generere dokumentasjonen må man ha [`doxygen`](http://doxygen.nl/) installert. Man kan enten kjøre `make docs` eller følgende kommandoer for CMake:

```sh
cmake -H. -Bbuild
cmake --build build --target docs
```

Den genererte dokumentasjonen lages `build/html`-mappen. Ved å åpne `build/html/index.html` så finner man hovedsiden.

## Kjøre tester

For å kjøre testene kan man enten kjøre `make tests` eller følgende kommandoer for CMake:

```sh
cmake -H. -Bbuild
cmake --build build
./build/tests/ListTests
```
