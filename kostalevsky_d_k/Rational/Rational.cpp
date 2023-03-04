#include<iostream>
#include<sstream>
#include "Rational.h"

class Rational {
    public:
        //constructors and destructor
        Rational(int32_t num_, int32_t denom_) {
            if (denom_ != 0) {
                if ((num_ < 0) && (denom_ < 0)) {
                    num_ = abs(num_);
                    denom_ = abs(denom_);
                }
                num = num_;
                denom = denom_;
                reduce();
            }
            else {
                throw std::invalid_argument("Division by zero");
            }
        }

        Rational() {
            setnum(0);
            setdenom(1);
        }

        Rational(int32_t num) {
            setnum(num);
            setdenom(1);
        }


        ~Rational() = default;

        // get and set
        void setnum(int32_t num_) {
            num = num_;
        }
        int32_t getnum() const {
            return num;
        }

        void setdenom(int32_t denom_) {
            denom = denom_;
        }
        int32_t getdenom() const {
            return denom;
        } 

        //operators overload
        Rational operator+(const Rational& rhs) const {
            int n1 = num * rhs.denom;
            int n2 = rhs.num * denom;
            int prod = denom * rhs.denom;
            Rational sum(n1 + n2, prod);
            return sum;
        }

        Rational& operator+=(const Rational &rhs) {
            int n = num * rhs.denom;
            int n1 = rhs.num * denom;
            int prod = denom * rhs.denom;

            num = n + n1;
            denom = prod;
            reduce();
            return *this;
        }

        Rational operator-(const Rational& rhs) const {
            int n1 = num * rhs.denom;
            int n2 = rhs.num * denom;
            int prod = denom * rhs.denom;
            Rational sub(n1 - n2, prod);
            return sub;
        }

        Rational& operator-=(const Rational &rhs) {
            int n = num * rhs.denom;
            int n1 = rhs.num * denom;
            int prod = denom * rhs.denom;

            num = n - n1;
            denom = prod;
            reduce();
            return *this;
        }

        bool operator<(const Rational &rhs) const {
            return ((num * rhs.denom) < (rhs.num * denom));
        }

        bool operator>(const Rational &rhs) const {
            return ((num * rhs.denom) > (rhs.num * denom));
        }

        bool operator==(const Rational &rhs) const {
            return ((num * rhs.denom) == (rhs.num * denom));
        }

        bool operator!=(const Rational &rhs) const {
            return ((num * rhs.denom) != (rhs.num * denom));
        }

        Rational operator~() const {
            return Rational(-num, denom);
        }

        Rational operator*(const Rational& rhs) const {
            return Rational(num * rhs.num, denom * rhs.denom);
        }

        Rational& operator*=(const Rational& rhs) {
            *this = *this * rhs;
            return *this;
        }

        Rational operator/(const Rational& rhs) const {
            return Rational(num * rhs.denom, denom * rhs.num);
        }

        Rational& operator/=(const Rational& rhs) {
            *this = *this / rhs;
            return *this;
        }

        Rational& operator=(const Rational& rhs) {
            setnum(rhs.getnum());
            setdenom(rhs.getdenom());
            return *this;
        }

    private:
        //variables
        int32_t num;
        int32_t denom;
        
        //methods
        void reduce() {
            int n = abs(num);
            int d = abs(denom);
            int di = 1;
            if (n > d) {
                std::swap(n, d);
            }
            for (int f = 2; f <= n; f++) {
                if ((n % f == 0) && (d % f == 0)) {
                    di = f;
                }
            }
            num /= di;
            denom /= di;
        }
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& r) {
    return ostrm << '(' << r.getnum() << '/' << r.getdenom() << ')';
}

std::istream& operator>>(std::istream& is, Rational& rhs) {
    int numerator, denominator;
    char c;
    is >> numerator >> c >> denominator;
    rhs = Rational(numerator, denominator);
    return is;
}

