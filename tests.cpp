#define CATCH_CONFIG_MAIN
#include "/Users/martynasgiedraitis/Desktop/antra_oop/class/catch_amalgamated.hpp"
#include "studentas.h"

TEST_CASE("Testuojame Student klasės vidurkio funkciją"){
    Student stud("Vardas", "Pavarde", 5, {10, 8, 10, 4, 10});
    stud.skaiciuotiVidurki();
    REQUIRE(stud.getVid() == 6.4);

}

// TEST_CASE("Testuojame Student klasės egzamino nustatymą"){
//     Student stud;
//     stud.setEgz(10);
//     REQUIRE(stud.getEgz() == 10);
// }