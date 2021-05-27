// Tutorial learncpp
// Lesson 13-3; Ex: a
//
// Take the Fraction class we wrote in the previous quiz (listed below) and add an overloaded operator<< and operator>> to it.
// This should produce the result:
//     Enter fraction 1: 2/3
//     Enter fraction 2: 3/8
//     2/3 * 3/8 is 1/4
//

#include <iostream>
#include<limits> //used to get numeric limits

using namespace std;

class Fraction {
    private:
        int m_numerator{ };
        int m_denominator{ };

        int gcd( int a, int b ) {
            return ( b == 0 ) ? ( a > 0 ? a : -a ) : gcd( b, a % b );
        }
    public:
        Fraction( int x = 0, int y = 1 )
            : m_numerator{ x }, m_denominator{ y } {
            reduce( ); // Make it pretty as soon as it's made
        }

        void print( ) {
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
        friend istream& operator >> ( istream &in, Fraction &f1 );
        friend ostream& operator << ( ostream &out, const Fraction &f1 );
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

istream& operator >> ( istream &in, Fraction &f1 ) {
    in >> f1.m_numerator;
    in.ignore( numeric_limits<streamsize> :: max(), '/' );
    in >> f1.m_denominator;

    f1.reduce(); // We make a new fraction so we should do this again
    return in;
}
ostream& operator << ( ostream &out, const Fraction &f1 ) {
    out << f1.m_numerator << "/" << f1.m_denominator;

    return out;
}

int main() {
    Fraction f1{};
    cout << "Enter fraction 1: ";
    cin >> f1;

    Fraction f2{};
    cout << "Enter fraction 2: ";
    cin >> f2;

    cout << f1 << " * " << f2 << " is " << f1 * f2 << '\n'; // note: The result of f1 * f2 is an r-value

    return 0;
}
