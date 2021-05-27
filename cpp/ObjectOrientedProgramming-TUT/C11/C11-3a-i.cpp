// Tutorial learncpp
// Lesson 11-3; Ex: 1

// Write a simple class named Point3d. The class should contain:
//      Three private member variables of type int named m_x, m_y, and m_z;
//      A public member function named setValues() that allows you to set values for m_x, m_y, and m_z.
//      A public member function named print() that prints the Point in the following format: <m_x, m_y, m_z>

#include <iostream>

class Point3d {
    int m_x, m_y, m_z;
    public:
        // Set Values to a, b, c
        void setValues( int a, int b, int c ){
            m_x = a;
            m_y = b;
            m_z = c;
        };

        // Intended format: <m_x, m_y, m_z>
        void print(){
            std::cout << "<" << m_x << "," << m_y << "," << m_z << ">" << std::endl;
        };
};

int main(){
    Point3d point;
    point.setValues( 1, 2, 3 );

    point.print();
    std::cout << '\n';

    return 0;
}
