#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdlib.h>
#include <sstream>

using namespace std;

struct BigInteger {
private:
    void convert();
    void prepare(BigInteger& a);
    void move_right(int k);
    void move_left(int k);
    void insert_value(BigInteger& a, int value);
    BigInteger & div(BigInteger& aa, BigInteger const& bb, bool s1, bool s2);
    int compare(BigInteger const& b);
    BigInteger& minus(vector< uint> a, vector< uint> b, bool s);
    BigInteger& plus(vector< uint> a, vector< uint> b, bool s);
    BigInteger& mul(vector< uint> a, vector< uint> b, bool s1, bool s2);
    void mul_on_short(BigInteger& a, int value);
    void zip(BigInteger& a);
public:
    /* varialbes */
    static const int length = 6;
    static const int p = 31;
    static const int l = 1000000;
    static const uint base = 1 << 31;
    bool sign;
    vector< uint> digits;

    /* constructors */
    BigInteger();
    BigInteger(BigInteger const& other);
    BigInteger(int a);
    BigInteger(string const& s);
    BigInteger(BigInteger && otherv);
    BigInteger&  operator=(BigInteger const& other);

    /* arithmetic operators */
    BigInteger&  operator+=(BigInteger const& other);
    BigInteger&  operator-=(BigInteger const& other);
    BigInteger&  operator*=(BigInteger const& other);
    BigInteger&  operator/=(BigInteger const& other);
    BigInteger&  operator%=(BigInteger const& other);

    /* equation operators */
    bool operator>(BigInteger const& a);
    bool operator<(BigInteger const& a);
    bool operator==(BigInteger const& a);
    bool operator>=(BigInteger const& a);
    bool operator<=(BigInteger const& a);
    bool operator!=(BigInteger const& a);

    /* unary operators */
    const BigInteger  operator+();
    const BigInteger  operator-();
    const BigInteger& operator++();
    const BigInteger& operator++(int a);
    const BigInteger& operator--();
    const BigInteger& operator--(int a);

    operator std::string() const;
};

string convertInt(int a);
ostream& operator<<(ostream& os, BigInteger const&);
istream& operator>>(istream& is, BigInteger &);

BigInteger operator+(BigInteger a, BigInteger const& b);
BigInteger operator-(BigInteger a, BigInteger const& b);
BigInteger operator*(BigInteger a, BigInteger const& b);
BigInteger operator/(BigInteger a, BigInteger const& b);
BigInteger operator%(BigInteger a, BigInteger const& b);
