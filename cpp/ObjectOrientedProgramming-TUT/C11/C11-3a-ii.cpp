// Tutorial learncpp
// Lesson 11-3; Ex: 2
//
// Cont. of the previous code
// Add a function named isEqual() to your Point3d class.

#include <iostream>

class Point3d {
    int m_x, m_y, m_z;
    public:
        // Set Values to a, b, c
        void setValues( int a, int b, int c ) {
            m_x = a;
            m_y = b;
            m_z = c;
        };

        // Reminds me of some of the stuff I was doing with pewel
        bool isEqual( const Point3d &d ) {
            return ( m_x == d.m_x && m_y == d.m_y && m_z == d.m_z );
        };

        // Intended format: <m_x, m_y, m_z>
        void print() {
            std::cout << "<" << m_x << "," << m_y << "," << m_z << ">" << std::endl;
        };
};

int main()
{
    Point3d point1;
    point1.setValues( 1, 2, 3 );

    Point3d point2;
    point2.setValues( 1, 2, 3 );

    if ( point1.isEqual( point2 ) ) {
        std::cout << "point1 and point2 are equal\n";
    }
    else {
        std::cout << "point1 and point2 are not equal\n";
    }

    Point3d point3;
    point3.setValues( 3, 4, 5 );

    if ( point1.isEqual( point3 ) ){
        std::cout << "point1 and point3 are equal\n";
    }
    else{
        std::cout << "point1 and point3 are not equal\n";
    }

    return 0;
}
