#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main()
#include "catch.hpp"
#include "../listtools-ng.h"

SCENARIO( "lister kan legge til elementer foran i listen og se på dem", "[List]" ) {

    GIVEN( "En tom liste" ) {
        List<int> list;

        REQUIRE( list.front() == nullptr );

        WHEN( "et element legges til foran i listen" ) {

            list.push_front(5);

            THEN( "kan man se på det første elementet" ) {
                REQUIRE( *list.front() == 5 );
            }
        }
        WHEN( "flere element legges foran i listen" ) {

            list.push_front(5);
            list.push_front(10);
            list.push_front(15);

            THEN( "er det siste elementet som ligger foran" ) {
                REQUIRE( *list.front() == 15 );
            }
        }
    }
}
