#include <iostream>
#include <sstream>
#include "include/rational/rational.hpp"

//constructors and destructor
Rational::Rational(int32_t num_, int32_t denom_) {
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

Rational::Rational() {
    setnum(0);
    setdenom(1);
}

explicit Rational::Rational(const int32_t num) noexcept{
    setnum(num);
    setdenom(1);
}

Rational::Rational(const Rational&) = default;

// get and set
void Rational::setnum(int32_t num_) {
    num = num_;
}
int32_t Rational::getnum() const {
    return num;
}

void Rational::setdenom(int32_t denom_) {
    denom = denom_;
}
int32_t Rational::getdenom() const {
    return denom;
} 

//operators overload
// Rational operator+(const Rational& rhs) const {
//     int n1 = num * rhs.denom;
//     int n2 = rhs.num * denom;
//     int prod = denom * rhs.denom;
//     Rational sum(n1 + n2, prod);
//     return sum;
// }

Rational& Rational::operator+=(const Rational &rhs) {
    int n = num * rhs.denom;
    int n1 = rhs.num * denom;
    int prod = denom * rhs.denom;
    num = n + n1;
    denom = prod;
    reduce();
    return *this;
}

// Rational operator-(const Rational& rhs) const {
//     int n1 = num * rhs.denom;
//     int n2 = rhs.num * denom;
//     int prod = denom * rhs.denom;
//     Rational sub(n1 - n2, prod);
//     return sub;
// }

Rational& Rational::operator-=(const Rational &rhs) {
    int n = num * rhs.denom;
    int n1 = rhs.num * denom;
    int prod = denom * rhs.denom;

    num = n - n1;
    denom = prod;
    reduce();
    return *this;
}

bool Rational::operator<(const Rational &rhs) const {
    return ((num * rhs.denom) < (rhs.num * denom));
}

bool Rational::operator<=(const Rational& rhs) const {
    return (operator==(rhs) || !operator>(rhs));
}

bool Rational::operator>(const Rational &rhs) const {
    return ((num * rhs.denom) > (rhs.num * denom));
}

bool Rational::operator>=(const Rational& rhs) const {
    return (operator==(rhs) || operator>(rhs));
}

bool Rational::operator==(const Rational &rhs) const {
    return ((num * rhs.denom) == (rhs.num * denom));
}

bool Rational::operator!=(const Rational &rhs) const {
    return ((num * rhs.denom) != (rhs.num * denom));
}

Rational Rational::operator~() const {
    return Rational(-num, denom);
}

// Rational operator*(const Rational& rhs) const {
//     return Rational(num * rhs.num, denom * rhs.denom);
// }

Rational& Rational::operator*=(const Rational& rhs) {
    *this = *this * rhs;
    return *this;
}

// Rational operator/(const Rational& rhs) const {
//     return Rational(num * rhs.denom, denom * rhs.num);
// }

Rational& Rational::operator/=(const Rational& rhs) {
    *this = *this / rhs;
    return *this;
}

Rational& Rational::operator=(const Rational& rhs) {
    setnum(rhs.getnum());
    setdenom(rhs.getdenom());
    return *this;
}

std::ostream& Rational::writeTo(std::ostream& ostrm) const {
    ostrm << num << sep << denom;
    return ostrm;
}

std::istream& Rational::readFrom(std::istream& istrm) {
    int32_t p(0);
    int32_t q(1);
    char divide(0);
    istrm >> p;
    istrm >> divide;
    istrm >> q;
    if (istrm.good() || !istrm.fail() && istrm.eof()) {
        if (Rational::sep == divide) {
            istrm.clear();
            *this = Rational(p, q);
        } else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}

//variables
int32_t num{0};
int32_t denom{1};
static const char sep{'/'};

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


// std::ostream& operator<<(std::ostream& ostrm, const Rational &r) {
//     return ostrm << '(' << r.getnum() << '/' << r.getdenom() << ')';
// }

// std::istream& operator>>(std::istream& is, Rational& rhs) {
//     int numerator, denominator;
//     char c;
//     is >> numerator >> c >> denominator;
//     rhs = Rational(numerator, denominator);
//     return is;
// }

Rational& operator+(const Rational &rhs, const Rational& lhs) {
int n1 = lhs.getnum() * rhs.getdenom();
int n2 = rhs.getnum() * lhs.getdenom();
int prod = lhs.getdenom() * rhs.getdenom();
Rational sum(n1 + n2, prod);
return sum;
}

Rational& operator-(const Rational& rhs, const Rational& lhs) {
int n1 = lhs.getnum() * rhs.getdenom();
int n2 = rhs.getnum() * lhs.getdenom();
int prod = lhs.getdenom() * rhs.getdenom();
Rational sub(n1 - n2, prod);
return sub;
}

Rational operator*(const Rational& rhs, const Rational& lhs) {
return Rational(lhs.getnum() * rhs.getnum(), lhs.getdenom() * rhs.getdenom());
}

Rational operator/(const Rational& rhs, const Rational& lhs) {
return Rational(lhs.getnum() * rhs.getdenom(), lhs.getdenom() * rhs.getnum());
}

std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs){
return rhs.writeTo(ostrm);
}

std::istream& operator>>(std::istream& istrm, Rational& rhs){
return rhs.readFrom(istrm);
}
