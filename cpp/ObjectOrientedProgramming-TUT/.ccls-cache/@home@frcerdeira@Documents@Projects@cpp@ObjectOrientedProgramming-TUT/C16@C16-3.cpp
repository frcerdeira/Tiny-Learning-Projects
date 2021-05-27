// Tutorial learncpp
// Lesson 16-3;
//
// Update the Department/Teacher example so the Department can handle multiple Teachers. The following code should execute:
// This should print:
//      Department: Bob Frank Beth
//      Bob still exists!
//      Frank still exists!
//      Beth still exists!

#include <functional>
#include <iostream>
#include <vector>

class Teacher {
    private:
        std::string m_name{ };
    public:
        Teacher( const std::string name )
            :m_name{ name } { }

        const std::string getName() const { return m_name; } // const because we don't want to modify m_name, just give the value
};

class Department {
    private:
        std::vector< std::reference_wrapper< const Teacher > > m_teachers{ }; // Array of Teachers that will hold their names (from Class Teacher)
    public:
        void add( const Teacher& name ) {
            m_teachers.push_back( name ); // Add a name to the array
        }

        friend std::ostream& operator << ( std::ostream& out, const Department& d1 ); // Print the names of the members of the department
};


std::ostream& operator << ( std::ostream& out, const Department& d1 ) {
    out << "Department: ";
    for ( const auto& i : d1.m_teachers) {
        out << i.get().getName() << " ";
    }
    out << std::endl;

    return out;
}

int main() {

  // Create a teacher outside the scope of the Department
  Teacher t1{ "Bob" };
  Teacher t2{ "Frank" };
  Teacher t3{ "Beth" };

  {
    // Create a department and add some Teachers to it
    Department department{}; // create an empty Department

    department.add(t1);
    department.add(t2);
    department.add(t3);

    std::cout << department;

  } // department goes out of scope here and is destroyed

  std::cout << t1.getName() << " still exists!\n";
  std::cout << t2.getName() << " still exists!\n";
  std::cout << t3.getName() << " still exists!\n";

  return 0;
}
