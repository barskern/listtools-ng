# listtools-ng

[![Build Status](https://travis-ci.com/barskern/listtools-ng.svg?token=S3nA1j4MQ8fzYt5KzyxX&branch=master)](https://travis-ci.com/barskern/listtools-ng)
![](https://img.shields.io/badge/status-under--utvikling-orange.svg)
[![](https://img.shields.io/badge/docs-online-green.svg)](http://barskern.no/listtools-ng)

**listtools-ng** er et bibliotek bestående av en headerfil som implementerer en enkel lenket liste. Hovedmålet med biblioteket er å gi en **enkel**, **minimal** og **elegant** abstraksjon over en lenket liste.

## Hvordan bruke prosjektet

Alt som trengs for å få tilgang til biblioteket er å skrive  `#include "listtools-ng.h"` i ditt prosjekt, etter at du har lastet ned headerfilen.

## Eksempel

```cpp
#include "listtools-ng.h"
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

```

Se i mappen `examples` for flere eksempler på bruk av biblioteket.

## Dokumentasjon

Dokumentasjonen ligger på [barskern.no/listtools-ng](http://barskern.no/listtools-ng).

Man kan også generere dokumentasjonen lokalt. For å kunne generere dokumentasjonen må man ha [`doxygen`](http://doxygen.nl/) installert. Man kan enten kjøre `make docs` eller følgende kommandoer for CMake:

```sh
cmake -Bbuild -H. -DBUILD_DOC=yes .
cmake --build build
```

Den genererte dokumentasjonen lages `docs`-mappen. Ved å åpne `docs/index.html` så finner man hovedsiden.

## Kjøre tester

For å kjøre testene kan man enten kjøre `make tests` eller følgende kommandoer for CMake:

```sh
cmake -Bbuild -H. .
cmake --build build
./build/tests/ListTests
```
