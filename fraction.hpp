#include <iostream> 
#include <string>

// declaring class

class Fraction {
    int num, denom;
     void reduce ();

public:

    // declaring fraction
    Fraction (int n, int d);

    // declaring operators
    Fraction operator+ (const Fraction& rhs) const;
    Fraction operator- (const Fraction& rhs) const ;
    Fraction operator* (const Fraction& rhs) const ;
    Fraction operator/ (const Fraction& rhs) const ;
    std::string toString ()const;

};

std::ostream& operator<< (std::ostream& stream, const Fraction& frac) ;