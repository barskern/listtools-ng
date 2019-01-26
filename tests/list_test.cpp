#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
#include "../listtools-ng.h"

SCENARIO( "elementer kan legges til foran i listen og man kan se på dem", "[List]" ) {

    GIVEN( "En tom liste" ) {
        List<int> list;

        REQUIRE( !list.front().has_value() );

        WHEN( "et element legges til foran i listen" ) {

            list.push_front(5);

            THEN( "kan man se på det første elementet" ) {
                REQUIRE( *list.front().value() == 5 );
            }
        }
        WHEN( "flere element legges foran i listen" ) {

            list.push_front(5);
            list.push_front(10);
            list.push_front(15);

            THEN( "er det siste elementet som ligger foran" ) {
                REQUIRE( *list.front().value() == 15 );
            }
        }
    }
}
