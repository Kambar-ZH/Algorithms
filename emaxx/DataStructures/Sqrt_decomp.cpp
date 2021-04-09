// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     // входные данные
//     int n;
//     vector<int> a(n);
//     cin >> n;
//     for (int i = 0; i < n; ++i)
//     {
//         cin >> a[i];
//     }

//     // предпосчёт
//     int len = (int)sqrt(n + .0) + 1; // и размер блока, и количество блоков
//     vector<int> b(len);
//     for (int i = 0; i < n; ++i)
//         b[i / len] += a[i];

//     // ответ на запросы
//     for (;;)
//     {
//         int l, r; // считываем входные данные - очередной запрос
//         cin >> l >> r;
//         int sum = 0;
//         int c_l = l / len,   c_r = r / len;
//         if (c_l == c_r)
//             for (int i=l; i<=r; ++i)
//                 sum += a[i];
//         else {
//             for (int i=l, end=(c_l+1)*len-1; i<=end; ++i)
//                 sum += a[i];
//             for (int i=c_l+1; i<=c_r-1; ++i)
//                 sum += b[i];
//             for (int i=c_r*len; i<=r; ++i)
//                 sum += a[i];
//         }
//         cout << sum;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    int len = sqrt(n + .0) + 1;
    vector<int> b(len);
    for (int i = 0; i < len; ++i)
    {
        b[i / len] += a[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int l, r;
        cin >> l >> r;
        int c_l = (l - 1) / len, c_r = (r - 1) / len;
        int maxi = 0;
        if (c_l == c_r)
        {
            for (int i = l - 1; i < r - 1; ++i)
            {
                maxi = max(maxi, a[i]);
            }
        }
        else
        {
            for (int i = l - 1; i <= (c_l + 1) * len - 1; i++)
            {
                maxi = max(maxi, a[i]);
            }
            int maxi_b = 0;
            for (int i = (maxi_b) * len; i <= min((maxi_b + 1) * len, n); ++i)
            {
                maxi = max(maxi, a[i]);
            }
            cout <<(maxi_b + 1) * len << " " << (maxi_b + 2) * len << " " << r - 1 << " " << l - 1 << endl;
            for (int i = c_r * len; i <= r - 1; ++i)
            {
                maxi = max(maxi, a[i]);
            }
        }
        cout << maxi << " ";
    }
    return 0;
}