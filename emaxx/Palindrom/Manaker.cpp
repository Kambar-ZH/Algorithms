// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     string s;
//     cin >> s;
//     int n = s.length();
//     vector<int> d1(n);
//     int l = 0, r = -1; // левая и правая указатели строки
//     for (int i = 0; i < n; ++i)
//     {
//         int k = i > r ? 1 : min(d1[l + r - i], r - i + 1); // к равен единице если i вышел за указатель r
//         // иначе выбираем минимальное значение среди 
//         while (i + k < n && i - k >= 0 && s[i + k] == s[i - k])
//             ++k;
//         d1[i] = k;
//         if (i + k - 1 > r)
//             l = i - k + 1, r = i + k - 1;
//     }
//     vector<int> d2(n);
//     l = 0, r = -1;
//     for (int i = 0; i < n; ++i)
//     {
//         int k = i > r ? 0 : min(d2[l + r - i + 1], r - i + 1);
//         while (i + k < n && i - k - 1 >= 0 && s[i + k] == s[i - k - 1])
//             ++k;
//         d2[i] = k;
//         if (i + k - 1 > r)
//             l = i - k, r = i + k - 1;
//     }
//     for (int i = 0; i < d1.size(); ++i)
//     {
//         cout << d1[i] << "  " << d2[i] << endl; // выводим все подпалиндромы
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> d1(n), d2(n);
    int l(0), r(-1);
    for (int i(0); i < n; ++i)
    {
        int k = (i > r) ? 1 : min(d1[l + r - i], r - i + 1);
        while (i + k < n && i - k >= 0 && s[i + k] == s[i - k])
        {
            ++k;
        }
        d1[i] = k;
        if (i + k - 1 > r)
        {
            l = i - k + 1, r = i + k - 1;
        }
    }
    for (int i(0); i < n; ++i)
    {
        int k = (i > r) ? 1 : min(d2[l + r - i - 1], r - i + 1);
        while (i + k < n && i - k - 1>= 0 && s[i + k] == s[i - k - 1])
        {
            ++k;
        }
        d2[i] = k;
        if (i + k - 1 > r)
        {
            l = i - k, r = i + k - 1;
        }
    }
    for (int i = 0; i < d1.size(); ++i)
    {
        cout << i << " " << d1[i] << " " << d2[i] << endl;
    }
    return 0;
}