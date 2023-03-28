#pragma once

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

        Rational operator+(const Rational& rhs) const;
        Rational operator-(const Rational& rhs) const;
        Rational operator*(const Rational& rhs) const;
        Rational operator/(const Rational& rhs) const;

        Rational& operator+=(const Rational& rhs);
        Rational& operator-=(const Rational& rhs);
        Rational& operator*=(const Rational& rhs);
        Rational& operator/=(const Rational& rhs);

        Rational operator~()const;

        bool operator<(const Rational &rhs) const;
        bool operator>(const Rational &rhs) const;
        bool operator==(const Rational &rhs) const;
        bool operator!=(const Rational &rhs) const;

    private:
        int32_t num;
        int32_t denom;
    private:
        void reduce();
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& r);
std::istream& operator>>(std::istream& is, Rational& rhs);
