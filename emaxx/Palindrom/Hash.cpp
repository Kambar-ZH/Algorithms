#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    string s;
    cin >> s;
    const int p = 31;
    long long hash = 0, p_pow = 1;
    for (size_t i=0; i<s.length(); ++i)
    {
        // желательно отнимать 'a' от кода буквы
        // единицу прибавляем, чтобы у строки вида 'aaaaa' хэш был ненулевой
        hash += (s[i] - 'a' + 1) * p_pow;
        p_pow *= p;
    }
    cout << hash;
    return 0;
}