#pragma once
#ifndef RATIONAL_HPP_
#define RATIONAL_HPP_
#include <iosfwd>

class Rational {
    public:
        Rational(int32_t num_, int32_t denum_);
        explicit Rational(const int32_t num) noexcept;
        Rational(const Rational&) = default;
        ~Rational() = default;
        void setnum(int32_t);
        void setdenom(int32_t);
        int32_t getnum() const;
        int32_t getdenom() const;
        Rational();

        Rational& operator=(const Rational& rhs);

        Rational& operator+=(const Rational& rhs);
        Rational& operator-=(const Rational& rhs);
        Rational& operator*=(const Rational& rhs);
        Rational& operator/=(const Rational& rhs);

        Rational operator~()const;

        bool operator<(const Rational &rhs) const;
        bool operator<=(const Rational& rhs) const;
        bool operator>(const Rational &rhs) const;
        bool operator>=(const Rational& rhs) const;
        bool operator==(const Rational &rhs) const;
        bool operator!=(const Rational &rhs) const;

        std::ostream& writeTo(std::ostream& ostrm);
        std::istream& readFrom(std::istream& istrm);

    private:
        int32_t num{0};
        int32_t denom{1};
        static const char sep{'/'};
    private:
        void reduce();
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& rhs);

Rational& operator+(const Rational& rhs, const Rational& lhs);
Rational& operator-(const Rational& rhs, const Rational& lhs);
Rational operator*(const Rational& rhs, const Rational& lhs);
Rational operator/(const Rational& rhs, const Rational& lhs);

#endif  // RATIONAL_HPP_
