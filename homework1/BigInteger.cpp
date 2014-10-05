#include "BigInteger.h"

BigInteger::BigInteger(): sign(true){
    digits.push_back(0);
}

BigInteger::BigInteger(BigInteger const& other) : sign(other.sign), digits(other.digits){}

BigInteger::BigInteger(int a) {
    a >= 0 ? sign = true : sign = false;
    a = abs(a);
    digits.push_back(a % base);
    if (a >= base)
        digits.push_back(a / base);
}

BigInteger::BigInteger(BigInteger && a) {
    sign = move(a.sign);
    digits = move(a.digits);
}

BigInteger::BigInteger(string const& s) : sign(true){
    int k = 0;
    if (s[0] == '-') {
        sign = false;
        k++;
    }

    for (int i = s.length(); i > k; i -= length) {
        if (i - k < length) {
            int cur = atoi(s.substr(k, i - k).c_str());
            digits.push_back(cur);
        } else {
            int cur = atoi(s.substr(i - length, length).c_str());
            digits.push_back(cur);
        }
    }
    convert();
    zip(*this);
}

string convertInt(int a) {
    stringstream ss;
    ss << a;
    return ss.str();
}

BigInteger& BigInteger::operator=(BigInteger const& other) {
    sign = other.sign;
    digits = other.digits;
    return *this;
}

/* arithmetic operators*/

BigInteger& BigInteger::operator+=(BigInteger const& other) {
    if (sign != other.sign) {
        bool s = sign;
        sign = true;
        BigInteger b = other;
        b.sign = true;
        if (*this >= b)
        {
            sign = s;
            return minus(digits, other.digits, sign);
        }
        else
        {
            sign = s;
            return minus(other.digits, digits, other.sign);
        }
    }
    return plus(digits, other.digits, sign);
}

BigInteger& BigInteger::operator-=(BigInteger const& other) {
    if (sign != other.sign) return plus(digits, other.digits, sign);
    bool s = sign;
    sign = true;
    BigInteger b = other;
    b.sign = true;
    if (*this >= b)
    {
        sign = s;
        return minus(digits, other.digits, sign);
    }
    else
    {
        sign = s;
        return minus(other.digits, digits, !other.sign);
    }
}

BigInteger& BigInteger::operator*=(BigInteger const& other) {
    return mul(digits, other.digits, sign, other.sign);
}

BigInteger& BigInteger::operator/=(BigInteger const& other) {
    return div(*this, other, sign, other.sign);
}

BigInteger& BigInteger::operator%=(BigInteger const& other) {
    BigInteger cur = *this;
    BigInteger d = cur.div(cur, other, sign, other.sign);
    BigInteger m = d *= other;
    *this -= m;
    zip(*this);
    return *this;
}

/* equation operators */
bool BigInteger::operator>(BigInteger const& other) {
    return compare(other) == 1;
}

bool BigInteger::operator<(BigInteger const& other) {
    return compare(other) == -1;
}

bool BigInteger::operator==(BigInteger const& other) {
    return compare(other) == 0;
}

bool BigInteger::operator>=(BigInteger const& other) {
    return compare(other) >= 0;
}

bool BigInteger::operator<=(BigInteger const& other) {
    return compare(other) <= 0;
}

bool BigInteger::operator!=(BigInteger const& other) {
    return compare(other) != 0;
}

/* unary operators */

const BigInteger BigInteger::operator+() {
    BigInteger res = *this;
    return res;
}

const BigInteger BigInteger::operator-() {
    BigInteger res = *this;
    res.sign = !sign;
    zip(res);
    return res;
}

const BigInteger& BigInteger::operator++() {
    *this += 1;
    zip(*this);
    return *this;
}

const BigInteger& BigInteger::operator++(int a) {
    return ++ * this;
}

const BigInteger& BigInteger::operator--() {
    *this -= 1;
    zip(*this);
    return *this;
}

const BigInteger& BigInteger::operator--(int a) {
    return -- * this;
}

BigInteger::operator string() const {
    BigInteger tmp = *this;
    string result = "";
    int d = 10;
    tmp.sign = true;
    while (tmp >= 10) {
        int carry = 0;
        for (int i = tmp.digits.size() - 1; i >= 0; --i) {
            long long cur = tmp.digits[i] + carry * 1ll * base;
            carry = (cur % d);
            tmp.digits[i] = cur/d;

        }
        while(tmp.digits[tmp.digits.size() - 1] == 0 && tmp.digits.size() > 1)
            tmp.digits.pop_back();
        result = convertInt(carry).append(result);
    }
    result = convertInt(tmp.digits[0]).append(result);
    if(!sign)
    {
        string minus = "-";
        result = minus.append(result);
    }
    return result;
}

ostream& operator<<(ostream& s, BigInteger const& a) {
    s << (string)a;
    return s;
}

istream& operator>>(istream & s, BigInteger & a) {
    string str;
    s >> str;
    BigInteger b(str);
    a.digits = b.digits;
    a.sign = b.sign;
    return s;
}

void BigInteger::convert() {
    vector<unsigned int> res;
    while(!(digits.size() == 1 && digits[0] < base))
    {
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; --i) {
            long long cur = digits[i] + carry * 1ll * l;
            digits[i] = cur / base;
            carry = (cur % base);
        }
        while(digits[digits.size() - 1] == 0 && digits.size() > 1)
            digits.pop_back();
        res.push_back(carry);
    }
    res.push_back(digits[0]);
    digits = res;
}

void BigInteger::prepare(BigInteger& a)
{
    if(!a.sign) {
        for(int i = 0; i < a.digits.size(); i++) {
            a.digits[i] ^= base - 1;
        }
        a -= 1;
    }
}

void BigInteger::move_right(int k)
{
    for(int i = 0; i < digits.size() - k - 1; i++) {
        digits[i] = digits[i + k];
    }
    for(int i = 0; i < k; i++) {
        digits.pop_back();
    }
    zip(*this);
}

void BigInteger::move_left(int k)
{
    for(int i = 0; i < k; i++)
    {
        digits.push_back(0);
    }
}

void BigInteger::insert_value(BigInteger& a, int value)
{
    a.digits.push_back(0);
    for(int i = a.digits.size() - 1; i >= 0; i--)
    {
        a.digits[i] = a.digits[i - 1];
    }
    a.digits[0] = value;
    zip(a);
}

BigInteger & BigInteger::div(BigInteger& aa, BigInteger const& bb, bool s1, bool s2) {
    BigInteger b = bb;

    aa.sign = true;
    b.sign = true;
    int temp = base / (b.digits.back() + 1);
    mul_on_short(aa, temp);
    mul_on_short(b, temp);
    BigInteger ost;
    int blast = b.digits.back();
    BigInteger tmp;
    int ss = b.digits.size();
    for(int i = aa.digits.size() - 1; i >= 0; i--)
    {
        insert_value(ost, aa.digits[i]);
        int t = ss < ost.digits.size() ? ost.digits[ss] : 0;
        int k = ss - 1 < ost.digits.size() ? ost.digits[ss - 1] : 0;
        int curj = (1ll * t * base + k) / blast;
        tmp = b;
        mul_on_short(tmp, curj);
        ost -= tmp;

        while(ost < 0)
        {
            ost += b;
            curj--;
        }
        aa.digits[i] = curj;
    }
    aa.sign = s1 == s2;
    zip(aa);
    return aa;
}

int BigInteger::compare(BigInteger const& b) {
    if(sign != b.sign)
        return (sign) ? 1 : -1;

    if (digits.size() > b.digits.size())
        return (sign) ? 1 : -1;
    else if (digits.size() < b.digits.size())
        return (sign) ? -1 : 1;
    else {
        for (int i = digits.size() - 1; i >= 0; i--) {
            if (digits[i] > b.digits[i]) {
                return (sign ) ? 1 : -1;
            } else if (digits[i] < b.digits[i]) {
                return (sign) ? -1 : 1;
            }
        }
    }
    return 0;
}

BigInteger & BigInteger::minus(vector<unsigned int> a, vector<unsigned int> b, bool s) {
    bool perenos = 0;
    for(int i = b.size(); i < a.size(); i++)
        b.push_back(0);

    for (int i = 0; i < a.size(); i++) {
        int cur = a[i] - b[i] - perenos;
        perenos = 0;
        if (cur < 0) {
            perenos = 1;
            cur += base;
        }
        a[i] = cur;
    }
    digits = a;
    sign = s;
    zip(*this);
    return *this;
}

BigInteger & BigInteger::plus(vector<unsigned int> a, vector<unsigned int> b, bool s) {
    int perenos = 0;
    int maxt = max(a.size(), b.size());
    for(int i = a.size(); i < maxt; i++)
        a.push_back(0);
    for(int i = b.size(); i < maxt; i++)
        b.push_back(0);
    for (int i = 0; i < maxt; i++) {
        int cur = b[i] + a[i] + perenos;
        a[i] = cur % base;
        perenos = cur / base;
    }
    if (perenos) a.push_back(perenos);
    digits = a;
    sign = s;
    zip(*this);
    return *this;
}

BigInteger & BigInteger::mul(vector<unsigned int> a, vector<unsigned int> b, bool s1, bool s2) {
    vector<unsigned int> c(a.size() + b.size());
    for (int i = 0; i < a.size(); i++) {
        int perenos = 0;
        for (int j = 0; j < b.size() || perenos; j++) {
            long long cur = c[i + j] + 1ll * a[i] * (j < b.size() ? b[j] : 0) + perenos;
            c[i + j] = cur % base;
            perenos = cur / base;
        }
    }
    digits = c;
    sign = (s1 == s2);
    zip(*this);
    return *this;
}

void BigInteger::mul_on_short(BigInteger& a, int value) {
    int perenos = 0;
    for (int i = 0; i < a.digits.size(); i++) {
        long long cur = 1ll * a.digits[i] * value + perenos;
        a.digits[i] = cur % base;
        perenos = cur / base;
    }
    if(perenos) a.digits.push_back(perenos);
    zip(a);
}

void BigInteger::zip(BigInteger& a) {
    while (a.digits.size() > 1 && a.digits.back() == 0)
        a.digits.pop_back();
    if(a.digits.size() == 1 && a.digits[0] == 0)
        a.sign = true;
}


BigInteger operator+(BigInteger a, BigInteger const& b) {
    return a += b;
}

BigInteger operator-(BigInteger a, BigInteger const& b) {
    return a -= b;
}

BigInteger operator*(BigInteger a, BigInteger const& b) {
    return a *= b;
}

BigInteger operator/(BigInteger a, BigInteger const& b) {
    return a /= b;
}

BigInteger operator%(BigInteger a, BigInteger const& b) {
    return a %= b;
}
