// Tutorial learncpp
// Lesson 13-2; Ex: c
//
// The fraction 2/4 is the same as 1/2, but 2/4 is not reduced to the lowest terms.
// We can reduce any given fraction to lowest terms by finding the greatest common divisor (GCD) between the numerator and denominator, and then dividing both the numerator and denominator by the GCD.
// This should print:
//      2/5
//      3/8
//      3/20
//      4/5
//      3/4
//      1/4
//      0/6 (? meh, whatevs)

#include <iostream>

using namespace std;

class Fraction {
    private:
        int m_numerator{ };
        int m_denominator{ };

        // Translation of Greatest Common Divisor function:
        // Is b=0 ?
        // Yes? Then we check if a>0
        // Yes? a    No? -a
        // Is b!=0 ?
        // We go again in the merry-go-round! But this time:
        //     a and b -> b and the remainder of a/b
        int gcd( int a, int b ) {
            return ( b == 0 ) ? ( a > 0 ? a : -a ) : gcd( b, a % b );
        }
    public:
        Fraction( int x = 0, int y = 1 )
            : m_numerator{ x }, m_denominator{ y } { }

        void print( ){
            reduce( ); // Make it pretty before printin'
            cout << m_numerator << "/" << m_denominator << endl;
        }
        void reduce( ) {
            int div { gcd( m_numerator, m_denominator ) };
            m_numerator /= div;
            m_denominator /= div;
        }

        friend Fraction operator * ( const Fraction &f1, int val );
        friend Fraction operator * ( int val, const Fraction &f1 );
        friend Fraction operator * ( const Fraction &f1, const Fraction &f2 );
        friend Fraction operator / ( int val, const Fraction &f1 );
};

Fraction operator * ( const Fraction &f1, int val ) {
    return{ f1.m_numerator * val, f1.m_denominator };
}
Fraction operator * ( int val, const Fraction &f1 ) {
    return{ val * f1.m_numerator, f1.m_denominator };
}
Fraction operator * ( const Fraction &f1, const Fraction &f2 ) {
    return{ f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator };
}

int main() {
    Fraction f1{ 2, 5 };
    f1.print();

    Fraction f2{ 3, 8 };
    f2.print();

    Fraction f3{ f1 * f2 };
    f3.print();

    Fraction f4{ f1 * 2 };
    f4.print();

    Fraction f5{ 2 * f2 };
    f5.print();

    Fraction f6{ Fraction{ 1, 2 } * Fraction{ 2, 3 } * Fraction{ 3, 4 } };
    f6.print();

    Fraction f7{0, 6};
    f7.print();

    return 0;
}
