#include <bits/stdc++.h>
using namespace std;
 
const int base = 1000000000;

struct lnum
{
    void read();
    void write();
    int sign = 1;
    vector<int> d;
};

void lnum::read()
{
    string number;
    cin >> number;
    for (int i = (int)number.length(); i > 0; i -= 9)
    {
        (i < 9) ? d.push_back(atoi (number.substr (0, i).c_str())) : d.push_back(atoi (number.substr (i - 9, 9).c_str()));   
    }
    while (d.size() > 1 && d.back() == 0)
        d.pop_back();
}

void lnum::write()
{
    if (d.size() == 1 && d[0] == 0) 
    {
        cout << 0;
        return;
    }
    if (sign != 1) cout << '-';
    for (int i = (int)d.size() - 1; i >= 0; --i) 
    {
        if (i != d.size() - 1)
        {
            if (d[i] == 0) cout << "000000000";
            else 
            {
                for (int j = 0; j < 9; j++)
                {
                    if (pow(10, j) > d[i]) cout << "0";
                }
            }
        }
        if (d[i] != 0) cout << d[i];
    }
}

bool cmp(lnum a, lnum b)
{
    if (a.d.size() < b.d.size()) return true;
    else if (a.d.size() > b.d.size()) return false;
    for (int i = a.d.size() - 1; i >= 0; --i)
    {
        if (a.d[i] < b.d[i]) return true;
        else if (a.d[i] > b.d[i]) return false;
    }
    return false;
}

lnum plus_(lnum a, lnum b)
{
    int carry = 0;
    for (int i = 0; i < max(a.d.size(), b.d.size()) || carry; ++i)
    {
        if (i == a.d.size())
            a.d.push_back(0);
        a.d[i] += carry + (i < b.d.size() ? b.d[i] : 0);
        carry = a.d[i] >= base;
        if (carry) a.d[i] -= base;
    }
    return a;
}

lnum minus_(lnum a, lnum b)
{
    if (cmp(a, b)) {
        swap(a, b);
        a.sign = -1;
    }
    int carry = 0;
    for (size_t i = 0; i < b.d.size() || carry; ++i)
    {
        a.d[i] -= carry + (i < b.d.size() ? b.d[i] : 0);
        carry = a.d[i] < 0;
        if (carry) a.d[i] += base;
    }
    while (a.d.size() > 1 && a.d.back() == 0)
	    a.d.pop_back();
    return a;
}

int main()
{
    ios_base::sync_with_stdio(0);
    lnum a, b;
    a.read();
    b.read();
    lnum res;
    res = minus_(a, b);
    res.write();
    return 0;
}