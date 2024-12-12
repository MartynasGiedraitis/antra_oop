#include <gtest/gtest.h>
#include "studentas.h"
#include "mylib.h"
#include <sstream>

TEST(StudentTest, CalculateAverage){
    std::vector<int> pazymiai = {8,9,7};
    int egzas=6;
    Student stud("Vardas", "Pavarde", egzas, pazymiai);
    stud.skaiciuotiVidurki();

    double expected_vid=(8+9+7)/3.0*0.4+6*0.6;
    expected_vid=round(expected_vid*100)/100;
    EXPECT_DOUBLE_EQ(stud.getVid(), expected_vid);

}
TEST(StudentTest, PrintInfo) {
    
    Student stud("Jonas", "Jonaitis", 8, {7, 9, 10});
    stud.skaiciuotiVidurki();
    std::ostringstream oss;
    
    stud.printInfo(oss);
 
    std::string expected_output = "Jonas           Jonaitis        8.27      ";  
    EXPECT_EQ(oss.str(), expected_output);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv); 
    return RUN_ALL_TESTS(); 
}
