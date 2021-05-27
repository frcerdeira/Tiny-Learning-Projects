// Tutorial learncpp
// Lesson 13-2; Ex: b
//
// Add overloaded multiplication operators to handle multiplication between a Fraction and integer, and between two Fractions.
// Use the friend function method.
// Hint:
// To multiply two fractions, first multiply the two numerators together, and then multiply the two denominators together.
// To multiply a fraction and an integer, multiply the numerator of the fraction by the integer and leave the denominator alone.
// This should print:
//      2/5
//      3/8
//      6/40
//      4/5
//      6/8
//      6/24

#include <iostream>

using namespace std;

class Fraction {
    private:
        int m_numerator{ };
        int m_denominator{ };
    public:
        Fraction( int x = 0, int y = 1 )
            : m_numerator{ x }, m_denominator{ y } { }

        void print(){
            cout << m_numerator << "/" << m_denominator << endl;
        }

        friend Fraction operator * ( const Fraction &f1, int val );
        friend Fraction operator * ( int val, const Fraction &f1 );
        friend Fraction operator * ( const Fraction &f1, const Fraction &f2 );
};

Fraction operator * ( const Fraction &f1, int val ) {
    return{ f1.m_numerator * val, f1.m_denominator }; // return with { } or it doesn't work :(
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

    return 0;
}
