// Tutorial learncpp
// Lesson 11-5; Ex: 1
//
// Write a class named Ball. Ball should have two private member variables with default values: m_color (“black”) and m_radius (10.0).
// Ball should provide constructors to set only m_color, set only m_radius, set both, or set neither value.
// For this quiz question, do not use default parameters for your constructors.
// Also write a function to print out the color and radius of the ball.
//
// Output should be:
//     colour: black, radius: 10
//     colour: blue, radius: 10
//     colour: black, radius: 20
//     colour: blue, radius: 20

#include <iostream>

class Ball {
    private:
        std::string m_colour{ "black" };
        double m_radius{ 10.0 };
    public:
        Ball( std::string colour = "black", double radius = 10.0){
            m_colour = colour;
            m_radius = radius;
        }
        Ball( double radius ){
            m_radius = radius;
        }

        void print(){
            std::cout << "colour: " << m_colour << ", radius: " << m_radius << std::endl;
        };

};
int main(){
    Ball def{};
    def.print();

    Ball blue{ "blue" };
    blue.print();

    Ball twenty{ 20.0 };
    twenty.print();

    Ball blueTwenty{ "blue", 20.0 };
    blueTwenty.print();

    return 0;
}
