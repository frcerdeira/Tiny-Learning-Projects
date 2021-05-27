// Tutorial learncpp
// Lesson 13-3; Ex: a
//
// Add an overloaded operator<< and operator< to the Car class at the top of the lesson
// This should print:
//     (Honda, Accord)
//     (Honda, Civic)
//     (Toyota, Camry)
//     (Toyota, Corolla)
//
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<Car> cars {
    { "Toyota", "Corolla" },
    { "Honda", "Accord" },
    { "Toyota", "Camry" },
    { "Honda", "Civic" }
};
    sort(cars.begin(), cars.end()); // requires an overloaded operator<
    for (const auto& car : cars)
        cout << car << '\n'; // requires an overloaded operator<<
    return 0;
}
