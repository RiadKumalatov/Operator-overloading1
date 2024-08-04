#include <iostream>
#include <stdexcept> 

class Fraction
{
private:
    int numerator_;
    int denominator_;

    void reduce()
    {
        int gcd = compute_gcd(numerator_, denominator_);
        numerator_ /= gcd;
        denominator_ /= gcd;
    }

    int compute_gcd(int a, int b) const
    {
        while (b != 0)
        {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

public:
    Fraction(int numerator, int denominator)
    {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero");
        }
        numerator_ = numerator;
        denominator_ = denominator;
        reduce();
    }

    bool operator==(const Fraction& other) const
    {
        return numerator_ * other.denominator_ == other.numerator_ * denominator_;
    }

    bool operator!=(const Fraction& other) const
    {
        return !(*this == other);
    }

    bool operator<(const Fraction& other) const
    {
        return numerator_ * other.denominator_ < other.numerator_ * denominator_;
    }

    bool operator<=(const Fraction& other) const
    {
        return *this < other || *this == other;
    }

    bool operator>(const Fraction& other) const
    {
        return !(*this <= other);
    }

    bool operator>=(const Fraction& other) const
    {
        return !(*this < other);
    }

    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac)
    {
        os << frac.numerator_ << '/' << frac.denominator_;
        return os;
    }
};

int main()
{
    Fraction f1(4, 3);
    Fraction f2(6, 11);

    std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
    std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
    std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
    std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
    std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
    std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';

    return 0;
}
