#define CATCH_CONFIG_MAIN

#include "../listtools-ng.h"
#include <catch2/catch.hpp>

struct el : public element {
  int m_val;

  el(int val) : element('E'), m_val(val) {}
};

SCENARIO("elementer kan legges til foran i listen og man kan se på dem",
         "[list]") {

  GIVEN("En tom liste") {
    list list;

    REQUIRE(!list.front());

    WHEN("et element legges til foran i listen") {

      list.push_front(new el(5));

      THEN("kan man se på det første elementet") {
        REQUIRE(((el *)list.front())->m_val == 5);
      }
    }
    WHEN("flere element legges foran i listen") {

      list.push_front(new el(5));
      list.push_front(new el(10));
      list.push_front(new el(15));

      THEN("er det siste elementet som ligger foran") {
        REQUIRE(((el *)list.front())->m_val == 15);
      }
    }
  }
}

SCENARIO("elementer kan fjernes fra starten av listen", "[list]") {

  GIVEN("En liste som ikke er tom") {
    list list;

    list.push_front(new el(5));
    list.push_front(new el(10));
    list.push_front(new el(15));

    REQUIRE(list.front());

    WHEN("et element fjernes fra starten av listen") {

      el *v = (el *)list.pop_front();

      THEN("får man tilbake det siste elementet som ble lagt til listen") {
        REQUIRE(v->m_val == 15);
      }

      THEN("er det neste elementet på listen foran på listen") {
        REQUIRE(((el *)list.front())->m_val == 10);
      }
    }
    WHEN("alle elementene fjernes fra listen") {

      REQUIRE(list.pop_front());
      REQUIRE(list.pop_front());
      REQUIRE(list.pop_front());

      THEN("er det første elementet tomt") { REQUIRE(!list.front()); }

      THEN("skjer det ingenting dersom man prøver å fjerne flere elementer") {
        REQUIRE(!list.pop_front());
        REQUIRE(!list.pop_front());
        REQUIRE(!list.pop_front());

        REQUIRE(!list.front());
      }
    }
  }
}
