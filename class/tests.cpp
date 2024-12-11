#include <gtest/gtest.h>
#include "studentas.h"
#include "mylib.h"

TEST(StudentTest, CalculateAverage){
    std::vector<int> pazymiai = {8,9,7};
    int egzas=6;
    Student stud("Vardas", "Pavarde", egzas, pazymiai);
    stud.skaiciuotiVidurki();

    double expected_vid=(8+9+7)/3.0*0.4+6*0.6;
    expected_vid=round(expected_vid*100)/100;
    EXPECT_DOUBLE_EQ(stud.getVid(), expected_vid);

}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);  // Inicijuoja Google Test
    return RUN_ALL_TESTS();  // Paleidžia visus testus
}
// TEST_CASE("Testuojame Student klasės egzamino nustatymą"){
//     Student stud;
//     stud.setEgz(10);
//     REQUIRE(stud.getEgz() == 10);
// }