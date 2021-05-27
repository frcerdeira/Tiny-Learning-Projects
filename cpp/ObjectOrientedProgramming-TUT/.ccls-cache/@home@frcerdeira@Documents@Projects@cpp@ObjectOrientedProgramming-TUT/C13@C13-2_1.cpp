// Tutorial learncpp
// Lesson 13-2; Ex: a
//
// Write a class named Fraction that has a integer numerator and denominator member. Write a print() function that prints out the fraction.
// This should print:
//     1/4
//     1/2

#include <iostream>

using namespace std;

class Fraction {
    private:
        double m_numerator{ };
        double m_denominator{ };
    public:
        Fraction( double x = 0, double y = 1 )
            : m_numerator{ x }, m_denominator{ y } { }
        void print(){
            cout << m_numerator << "/" << m_denominator << endl;
        }
};

int main() {
    Fraction f1{ 1, 4 };
    f1.print();

    Fraction f2{ 1, 2 };
    f2.print();

    return 0;
}
