#include <bits/stdc++.h>
using namespace std;
 
struct longint
{
    vector<int> number;
    int sign;
    longint() : sign(1) { }
};

longint read (string & num)
{
    longint x;
    int n = num.length();
    for (int i = n - 1; i >= 0; --i)
    {
        if (num[i] == '-')
        {
            x.sign *= -1;
            continue;
        }
        x.number.push_back(num[i] - '0');
    }
    return x;
}

longint plusik(longint & a, longint & b)
{
    longint x;
    vector<int> num1, num2;
    if (a.number.size() > b.number.size())
    {
        num1 = a.number;
        num2 = b.number;
    }
    else
    {
        num1 = b.number;
        num2 = a.number;
    }
    int n1(num1.size()), n2(num2.size());
    int digit = 0;
    for (int i = 0; i < n2; ++i)
    {
        int sum = num1[i] + num2[i] + digit;
        x.number.push_back(sum % 10);
        digit = sum / 10;
    }
    for (int i = n2; i < n1; ++i)
    {
        int sum = num1[i] + digit;
        x.number.push_back(sum % 10);
        digit = sum / 10;
    }
    if (digit > 0)
        x.number.push_back(digit);
    return x;
}

bool abs_compare_number(longint & a, longint & b)
{
    if (a.number.size() > b.number.size())
        return 1;
    else if (a.number.size() < b.number.size())
        return 0;
    for (int i = a.number.size() - 1; i >= 0; --i)
    {
        if (a.number[i] == b.number[i]) continue;
        else if (a.number[i] > b.number[i]) return 1;
        else if (a.number[i] < b.number[i]) return 0;
    }
    return 0;
}

longint minusik(longint & a, longint & b)
{
    longint c;
    if (a.sign == 1 && b.sign == -1) 
    {    
        c = plusik(a, b);
        return c;
    }
    if (a.sign == -1 && b.sign == 1)
    {
        c = plusik(a, b);
        c.sign = -1;
        return c;
    }
    vector<int> num1, num2;
    if (abs_compare_number(a, b) == 1)
    {
        num1 = a.number;
        num2 = b.number;
    }
    else
    {
        num1 = b.number;
        num2 = a.number;
        c.sign = -1;
    }
    int n1(num1.size()), n2(num2.size());
    int remainder = 0;
    for (int i = 0; i < n2; ++i)
    {
        int sub = 10 + num1[i] - num2[i]- remainder;
        c.number.push_back(sub % 10);
        remainder = 1 - sub / 10;
    }
    for (int i = n2; i < n1; ++i)
    {
        int sub = 10 + num1[i] - remainder;
        c.number.push_back(sub % 10);
        remainder = 1 - sub / 10;
    }
    if (remainder > 0)
        c.number[c.number.size() - 1] -= 1;
    if (a.sign == 1 && b.sign == 1)
        return c;
    else
    {
        c.sign *= -1;
        return c;
    }
}

longint multik(longint a, longint b)
{
    longint c;
    if (a.sign != b.sign)
        c.sign *= -1;
    vector<int> num1, num2;
    num1 = a.number;
    num2 = b.number;
    int n1(num1.size()), n2(num2.size());
    for (int i = 0; i < n1 + n2; ++i)
        c.number.push_back(0);
    // cout << c.number.size();
    for (int i = 0; i < n1; ++i)
    {
        for (int j = 0; j < n2; ++j)
        {
            int multi = num1[i] * num2[j];
            // cout << multi;
            int cnt = 0;
            while(true)
            {
                int remainder = (c.number[i + j + cnt] + multi % 10) / 10;
                c.number[i + j + cnt] = (c.number[i + j + cnt] + multi % 10) % 10;
                if (remainder)
                    c.number[i + j + cnt + 1] += 1;
                // cout << remainder << endl;
                // cout << i + j + cnt << " " << c.number[i + j + cnt] + multi % 10 << " " << c.number[i + j + cnt] << " " << multi % 10 << endl;
                multi /= 10; cnt+=1;
                if (!multi)
                    break;
            }
        }
    }
    return c;
}

void write (longint & x)
{
    if (x.sign == -1)
        cout << '-';
    int flag = 0;
    int n = x.number.size() - 1;
    for (int i = n; i >= 0; --i)
    {
        if (x.number[i] != 0)
            flag = 1;
        if (flag)
            cout << x.number[i];
    }
    cout << endl;
}

int main()
{
    string num1, num2;
    cin >> num1 >> num2;
    longint a, b;
    a = read(num1);
    b = read(num2);
    // write(a);
    // write(b);
    longint c = multik(a, b);
    write(c);
    return 0;
}