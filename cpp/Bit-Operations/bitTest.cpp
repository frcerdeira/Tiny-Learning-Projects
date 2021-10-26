#include <bitset>
#include <iostream>
#include <limits>

void ignoreLine()
{
    std::cin.ignore( std::numeric_limits<std::streamsize>::max(), '\n' );
}

bool ask_user_input( short int& input_number )
{
    bool valid_input = false;

    std::cout << "Choose a number (in ["
              << std::numeric_limits<short>::min()
              << ", "
              << std::numeric_limits<short>::max()
              << "]): ";

    std::cin >> input_number;

    if (std::cin.fail())
    {
        std::cin.clear();
        ignoreLine();
        valid_input = false;

        std::cout << "Invalid input, please try again" << std::endl;
    }
    else
    {
        ignoreLine();
        valid_input = true;
    }

    return valid_input;
}

int main(int argc, char *argv[])
{

    short int number{};

    bool valid_num = false;

    do
        valid_num = ask_user_input( number );
    while (!valid_num);

    std::bitset<16> bit_rep( number );

    std::cout << "Your Number: " << number << "\n"
              << "16-Bit Representation of " << number << ": " << bit_rep << std::endl;

    for (size_t it = 0; it < bit_rep.size(); it++)
    {
        if ( bit_rep.test( it ) )
            std::cout << "Bit " << it << " is set!" << std::endl;
    }

    return 0;
}
