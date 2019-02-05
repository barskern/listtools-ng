#include "../lib/catch.hpp"
#include "../listtools-ng.h"

SCENARIO("en `option` kan representere en verdi som kanskje er tilstede",
         "[option]") {

  GIVEN("en tom `option`") {

    option<int> empty;

    REQUIRE(!empty.has_value());

    WHEN("den brukes for å gi en reserve verdi") {

      THEN("returneres reserve verdien") { REQUIRE(empty.value_or(1) == 1); }
    }
  }

  GIVEN("en `option` med en verdi") {

    option<int> full(1);

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

SCENARIO("en `option` kan representere en referanse som kanskje er tilstede",
         "[option]") {

  GIVEN("en `option` med en referanse") {

    int a = 1;
    option<int &> full(a);

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
  GIVEN("en tom `option` med en referanse") {

    option<int &> empty;

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
