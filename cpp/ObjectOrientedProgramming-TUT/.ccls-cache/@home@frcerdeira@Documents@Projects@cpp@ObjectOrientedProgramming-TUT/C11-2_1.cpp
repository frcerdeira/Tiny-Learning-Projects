// Tutorial learncpp
// Lesson 11-2; Ex: 1

// Intended output:
// Pair(1, 1)
// Pair(2, 2)

#include <iostream>
#include <vector>

using namespace std;

class IntPair {
    public:
        int m_a{};
        int m_b{};

        auto set( int a, int b ){
            m_a = a;
            m_b = b;
        }

        void print(){
            cout << "Pair(" << m_a << ", " << m_b << ")" << endl;
        };

};

int main(int argc, char const *argv[]){
    IntPair p1;

    p1.set( 1, 1 ); // set p1 values to (1, 1)

    IntPair p2{ 2, 2 }; // initialize p2 values to (2, 2)

    p1.print();
    p2.print();

    return 0;
}
