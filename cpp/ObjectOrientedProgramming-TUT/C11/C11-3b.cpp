// Tutorial learncpp
// Lesson 11-3; Ex: 3
//
// The class should be named Stack, and should contain:
//     -> A private fixed array of integers of length 10.
//     -> A private integer to keep track of the size of the stack.
//     -> A public member function named reset() that sets the size to 0.
//     -> A public member function named push() that pushes a value on the stack. push() should return false if the array is already full, and true otherwise.
//     -> A public member function named pop() that pops a value off the stack and returns it. If there are no values on the stack, the code should exit via an assert.
//     -> A public member function named print() that prints all the values in the stack.
//
// This should print:
// ( )
// ( 5 3 8 )
// ( 5 3 )
// ( )

#include <iostream>
#include <cassert>
#include <array>

class Stack {
    private:
        std::array<int, 10> my_array;
        int stackPos = 0;
    public:
        // We just need to say, hey, the current position in the stack is 0
        void reset(){
            stackPos = 0;
        };
        // Push a value to the array
        bool push(int value){
            // Do we still have space to push?
            if( stackPos == my_array.size() ){
                return false;
            };
            // Yes? Ok, push it and advance one position in the stack
            my_array[ stackPos ] = value;
            stackPos++;

            return true;
        };
        // Remove the last value of the array
        int pop(){
            // Do we still have values to remove? :(
            if( stackPos == 0 ){
                return false;
            }
            // NOTE: !!I should have used this instead!!
            // assert(stackPos > 0 && "Can not pop empty stack");

            return my_array[ --stackPos ];
        };
        // Print what we got
        void print(){
            std::cout << "( ";
            for( int i = 0; i < stackPos; i++ ){
                std::cout << my_array[i] << " ";
            };
            std::cout << " )" << std::endl;
        };
};

int main() {
    Stack stack;

    stack.print();

    stack.push( 5 );
    stack.push( 3 );
    stack.push( 8 );
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();

    stack.reset();
    stack.print();

    return 0;
}
