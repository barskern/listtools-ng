#include "../listtools-ng.h"
#include "catch.hpp"

SCENARIO("en `Option` kan representere en verdi som kanskje er tilstede",
         "[Option]") {

  GIVEN("en tom `Option`") {

    Option<int> empty;

    REQUIRE(!empty.has_value());

    WHEN("den brukes for å gi en reserve verdi") {

      THEN("returneres reserve verdien") { REQUIRE(empty.value_or(1) == 1); }
    }
  }

  GIVEN("en `Option` med en verdi") {

    Option<int> full(1);

    REQUIRE(full.has_value());

    WHEN("man ønsker å bruke verdien") {

      THEN("returnerer den den tidligere gitte verdien") {
        REQUIRE(full.value() == 1);
      }
    }

    WHEN("den brukes for å gi en reserve verdi") {

      THEN("returneres den orginale verdien") {
        REQUIRE(full.value_or(2) == 1);
      }
    }
  }
}

SCENARIO("en `Option` kan representere en referanse som kanskje er tilstede",
         "[Option]") {

  GIVEN("en `Option` med en referanse") {

    int a = 1;
    Option<int &> full(a);

    REQUIRE(full.has_value());

    WHEN("man ønsker å bruke verdien") {

      THEN("returnerer den den tidligere gitte verdien") {
        REQUIRE(full.value() == 1);
      }
    }

    WHEN("den brukes for å gi en reserve verdi (referanse)") {

      int b = 2;
      THEN("returneres den orginale verdien") {
        REQUIRE(full.value_or(b) == 1);
      }
    }

    WHEN("den brukes for å gi en reserve verdi (konstant)") {

      THEN("returneres den orginale verdien") {
        REQUIRE(full.value_or(2) == 1);
      }
    }
  }
  GIVEN("en tom `Option` med en referanse") {

    Option<int &> empty;

    REQUIRE(!empty.has_value());

    WHEN("den brukes for å gi en reserve verdi (referanse)") {

      int b = 1;
      THEN("returneres reserve verdien") { REQUIRE(empty.value_or(b) == 1); }
    }

    WHEN("den brukes for å gi en reserve verdi (konstant)") {

      THEN("returneres reserve verdien") { REQUIRE(empty.value_or(1) == 1); }
    }
  }
}
