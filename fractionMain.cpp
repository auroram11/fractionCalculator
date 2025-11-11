#include <iostream> 
#include <string>
#include "fraction.hpp"

int main(int argc, char ** argv){
    std::cout << "Enter a fraction in this form 'x / y' \n";
    int numA, denomA, numB, denomB;
    std::string slash; // not important, takes in the / so that the variable of denom. can be saved
    std::cin >>  numA >> slash >> denomA;
    Fraction f1 (numA, denomA);
    std::cout << "\n\nEnter another fraction of the same form:\n";
    std::cin >>  numB >> slash >> denomB;
    Fraction f2 (numB, denomB);
    int ans;

    while (ans != 5){
        std::cout<< "\n\nWhat do you want to do?\n1 - add\n2 - subtract\n3 - multiply\n4 - divide\n5 - exit\n------\n";
        std::cin>> ans;

        // operator signs can now be used between fractions 
        
        if (ans ==1){
            std::cout << "\n" << f1+f2;
        }

        else if (ans ==2){
            std::cout << "\n" << f1-f2;
        }

        else if (ans ==3){
            std::cout << "\n" << f1*f2;
        }

        else if (ans ==4){
            std::cout << "\n" << f1/f2;
        }
    }
}
