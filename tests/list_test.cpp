#define CATCH_CONFIG_MAIN

#include "../listtools-ng.h"
#include <catch2/catch.hpp>

SCENARIO("elementer kan legges til foran i listen og man kan se på dem",
         "[list]") {

  GIVEN("En tom liste") {
    list<int> list;

    REQUIRE(!list.front().has_value());

    WHEN("et element legges til foran i listen") {

      list.push_front(5);

      THEN("kan man se på det første elementet") {
        REQUIRE(list.front().value() == 5);
      }
    }
    WHEN("flere element legges foran i listen") {

      list.push_front(5);
      list.push_front(10);
      list.push_front(15);

      THEN("er det siste elementet som ligger foran") {
        REQUIRE(list.front().value() == 15);
      }
    }
  }
}

SCENARIO("elementer kan fjernes fra starten av listen", "[list]") {

  GIVEN("En liste som ikke er tom") {
    list<int> list;

    list.push_front(5);
    list.push_front(10);
    list.push_front(15);

    REQUIRE(list.front().has_value());

    WHEN("et element fjernes fra starten av listen") {

      int v = list.pop_front().value();

      THEN("får man tilbake det siste elementet som ble lagt til listen") {
        REQUIRE(v == 15);
      }

      THEN("er det neste elementet på listen foran på listen") {
        REQUIRE(list.front().value() == 10);
      }
    }
    WHEN("alle elementene fjernes fra listen") {

      REQUIRE(list.pop_front().has_value());
      REQUIRE(list.pop_front().has_value());
      REQUIRE(list.pop_front().has_value());

      THEN("er det første elementet tomt") {
        REQUIRE(!list.front().has_value());
      }

      THEN("skjer det ingenting dersom man prøver å fjerne flere elementer") {
        REQUIRE(!list.pop_front().has_value());
        REQUIRE(!list.pop_front().has_value());
        REQUIRE(!list.pop_front().has_value());

        REQUIRE(!list.front().has_value());
      }
    }
  }
}
