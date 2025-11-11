#include <iostream>
#include <string>
#include "fraction.hpp"

void Fraction::reduce () {
    // reduces a fraction to lowest terms
    int R;
    int a = num, b = denom;
    std::cout << "REDUCE: " << num << "/" << denom << "\n";

    std::cout <<"\n";
    if (num == denom){
        // if numerator and denom are equal, fraction is equal to 1
        num = 1;
        denom = 1;
    }

    else {
        while ((a % b) != 0)  {
            R = a % b;
            a = b;
            b = R;
        }
        num = num / b;
        denom = denom /b;
        // divides both numerator and denominator by greatest common denominator
    }
}
Fraction::Fraction (int n, int d)
    : num(n), denom(d)
    {
        if (denom == 0) {
            denom = 1;
        }
    }

        // static Fraction add (Fraction a, Fraction b) {
        //     if (a.denom == b.denom) {
        //         int newN= a.num+b.num;
        //         Fraction c (newN, a.denom);
        //         c.reduce();
        //         return c;
        //     }
        //     else {
        //         int newN = (a.num * b.denom) + (b.num*a.denom);
        //         int newD = (a.denom*b.denom);
        //         Fraction c (newN, newD);
                
        //         c.reduce();
        //         return c;
        //     }
        // }
        
        // static Fraction subtract(Fraction a, Fraction b) {
        //     if (a.denom == b.denom) {
        //         int newN= a.num-b.num;
        //         Fraction d (newN, a.denom);
        //         d.reduce();
        //         return d;
        //     }
        //     else {
        //         int newN = (a.num * b.denom) - (b.num*a.denom);
        //         int newD = (a.denom*b.denom);
        //         Fraction d (newN, newD);
        //         d.reduce();
        //         return d;
        //     }
        // }

        // static Fraction mult (Fraction a, Fraction b){
        //     int newN = a.num *b.num;
        //     int newD = a.denom*b.denom;
        //     Fraction e (newN, newD);
        //     e.reduce();
        //     return e;
        // }

        // static Fraction div (Fraction a, Fraction b) {
        //     int newN = a.num*b.denom;
        //     int newD = a.denom*b.num;
        //     Fraction f (newN, newD);
        //     f.reduce();
        //     return f;
        // }

Fraction Fraction::operator+ (const Fraction& rhs) const {
    Fraction sum (num * rhs.denom + rhs.num*denom, denom*rhs.denom);
        sum.reduce(); // reduces sum
        return sum;
}

Fraction Fraction::operator- (const Fraction& rhs) const {
    Fraction difference (num * rhs.denom - rhs.num*denom, denom*rhs.denom);
    difference.reduce();
    return difference;
    }

Fraction Fraction::operator* (const Fraction& rhs) const {
    Fraction product (num * rhs.num, denom*rhs.denom);
    product.reduce();
    return product;
}

Fraction Fraction::operator/ (const Fraction& rhs) const {
    Fraction quotient (num * rhs.denom ,denom*rhs.num);
    // multiplies by reciprocal
    quotient.reduce();
    return quotient;
}

std::string Fraction::toString ()const{
    // will output << to print a fraction as 'x / y'
    std::string fraction = std::to_string(num) + " / " + std::to_string(denom);
    return fraction;
}


std::ostream& operator<< (std::ostream& stream, const Fraction& frac) {
    // overrides the operator to cout fractions using the toString function
    stream << frac.toString() ;
    return stream;
}

