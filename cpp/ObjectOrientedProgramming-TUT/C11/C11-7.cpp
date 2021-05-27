// Tutorial learncpp
// Lesson 11-6; Ex: 1
//
// Update the following program to use non-static member initialization and member initializer lists.
//
// Output should be:
//     color: black, radius: 10
//     color: blue, radius: 10
//     color: black, radius: 20
//     color: blue, radius: 20

#include <string>
#include <iostream>

class Ball{
    private:
        std::string m_colour{ "black" };
        double m_radius{ }; // The radius always gets initialized so it's no biggie if we don't say nothing here ;)

    public:
        // Constructor with only radius parameter (color will use default value)
        Ball( double radius )
            :m_radius{ radius }{}
        // Constructor with both color and radius parameters
        Ball( const std::string &colour = "black", double radius = 10.0)
            :m_colour{ colour },
             m_radius{ radius }{}
        void print(){
            std::cout << "colour: " << m_colour << ", radius: " << m_radius << '\n';
        }
};

int main(){
    Ball def;
    def.print();

    Ball blue{ "blue" };
    blue.print();

    Ball twenty{ 20.0 };
    twenty.print();

    Ball blueTwenty{ "blue", 20.0 };
    blueTwenty.print();

    return 0;
}
