#pragma once
#include <iosfwd>

class Rational {
    public:
        Rational::Rational(int32_t num_, int32_t denum_);
        explicit Rational::Rational(const int32_t num) noexcept;
        Rational::Rational(const Rational&) = default;
        ~Rational() = default;
        void setnum();
        void setdenom();
        int32_t getnum();
        int32_t getdenom();

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
        int32_t num;
        int32_t denom;
        static const char sep;
    private:
        void reduce();
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& rhs);

Rational& operator+(const Rational& rhs, const Rational& lhs);
Rational& operator-(const Rational& rhs, const Rational& lhs);
Rational operator*(const Rational& rhs, const Rational& lhs);
Rational operator/(const Rational& rhs, const Rational& lhs);
