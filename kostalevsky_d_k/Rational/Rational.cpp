#include<iostream>

class Rational {
    public:
        //constructors and destructor
        Rational(int32_t num_, int32_t denum_) {
            if ((num_ < 0) && (denum_ < 0)) {
                num_ = abs(num_);
                denum_ = abs(denum_);
            }
            num = num_;
            denum = denum_;
            reduce();
        }

        Rational()
            : num(0), denum(1) {}

        ~Rational() = default;

        // get and set
        void setnum(int32_t num_) {
            num = num_;
        }
        int getnum() const {
            return num;
        }

        void setdenum(int32_t denum_) {
            denum = denum_;
        }
        int getdenum() const {
            return denum;
        } 

        //operators overload
        Rational operator+(const Rational& rhs) const {
            int n1 = num * rhs.denum;
            int n2 = rhs.num * denum;
            int prod = denum * rhs.denum;
            Rational sum(n1 + n2, prod);
            return sum;
        }

        Rational& operator+=(const Rational &rhs) {
            int n = num * rhs.denum;
            int n1 = rhs.num * denum;
            int prod = denum * rhs.denum;

            num = n + n1;
            denum = prod;
            reduce();
            return *this;
        }

        Rational operator-(const Rational& rhs) const {
            int n1 = num * rhs.denum;
            int n2 = rhs.num * denum;
            int prod = denum * rhs.denum;
            Rational sub(n1 - n2, prod);
            return sub;
        }

        Rational& operator-=(const Rational &rhs) {
            int n = num * rhs.denum;
            int n1 = rhs.num * denum;
            int prod = denum * rhs.denum;

            num = n - n1;
            denum = prod;
            reduce();
            return *this;
        }

        bool operator<(const Rational &rhs) const {
            return ((num * rhs.denum) < (rhs.num * denum));
        }

        bool operator>(const Rational &rhs) const {
            return ((num * rhs.denum) > (rhs.num * denum));
        }

        bool operator==(const Rational &rhs) const {
            return ((num * rhs.denum) == (rhs.num * denum));
        }

        bool operator!=(const Rational &rhs) const {
            return ((num * rhs.denum) != (rhs.num * denum));
        }

        Rational operator~() const {
            return Rational(-num, denum);
        }

        Rational operator*(const Rational& rhs) const {
            return Rational(num * rhs.num, denum * rhs.denum);
        }

         Rational operator/(const Rational& rhs) const {
            return Rational(num * rhs.denum, denum * rhs.num);
        }

    private:
        //variables
        int32_t num;
        int32_t denum;
        
        //methods
        void reduce() {
            int n = abs(num);
            int d = abs(denum);
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
            denum /= di;
        }
};

std::ostream& operator<<(std::ostream& ostrm, const Rational& r) {
    return ostrm << '(' << r.getnum() << '/' << r.getdenum() << ')';
}

int main() {
    Rational n(1, 2);
    Rational n1(2, 3);
    Rational n2(1, 2);
    Rational n3(2, 3);
    Rational res = n + n1;
    Rational res1 = n - n1;
    bool res2 = n < n1;
    bool res3 = n > n1;
    Rational res4 = n2 += n3;
    Rational res5 = n2 -= n3;
    std::cout << res << std::endl;
    std::cout << res1 << std::endl;
    std::cout << res2 << std::endl;
    std::cout << res3 << std::endl;
    std::cout << res4 << std::endl;
    std::cout << res5 << std::endl;
    std::cout << ~n << std::endl;
    std::cout << n * n1 << std::endl;
    std::cout << n / n1 << std::endl;
    return 0;
}


