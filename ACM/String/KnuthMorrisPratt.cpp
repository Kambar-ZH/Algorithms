// #include <bits/stdc++.h>

// using namespace std;

// vector<int> prefix_function(const string& s) {
//     vector<int> pi(s.length(), 0); // создаем вектор и заполняем его нулями по длине строки

//     for (int i = 1; i < s.length(); i++) { // начинаем итерацию с перового элемента так как нулевой подстроки не может быть
//         int j = pi[i - 1]; // j = pi[0, 1, 2, ... , s.length() - 2]

//         while (j > 0 && s[i] != s[j]) { // 
//             j = pi[j - 1];
//         }

//         if (s[i] == s[j]) { // если первый элемент равен нулевому тогда
//             pi[i] = j + 1; // прибавляем в префикс функцию значение j + 1
//         } else { // иначе
//             pi[i] = j; // префикс функция становится j
//         }
//     }

//     return pi;
// }

// int main() {
//     string s, t; // строка, подстрока
//     cin >> s >> t;

//     vector<int> pi = prefix_function(t + '#' + s); // префикс функция
//     for (int i = 0; i < pi.size(); ++i)
//     {
//         cout << pi[i] << " ";
//     }
//     cout << "\n";
//     int t_len = t.length();

//     for (int i = 0; i < s.length(); i++) {
//         if (pi[t_len + 1 + i] == t_len) {
//             cout << "s[" << i - t_len + 1 << ".." << i << "] = t" << endl;
//         }
//     }
// }


#include <bits/stdc++.h>
using namespace std;

vector<int> KMP_search(const string & str)
{
    int str_len = str.length();
    vector<int> pi(str_len, 0);
    int j = 0;  
    for (int i = 1; i < str_len; ++i)
    {
        j = pi[i - 1];
        while (j > 0 and str[i] != str[j])
        {
            j = pi[j - 1];
        }
        if (str[i] == str[j])
        {
            pi[i] = j + 1;
        }
        else
        {
            pi[i] = j;
        }
    }
    return pi;
}

int main()
{
    string str, substr;
    cin >> str >> substr;
    vector<int> result = KMP_search(substr + "#" + str);
    for (int prefix = 0; prefix < result.size(); ++ prefix)
    {
        cout << result[prefix] << " ";
    }
    cout << "\n";
    for (int prefix = 0; prefix < result.size(); ++ prefix)
    {
        if (result[prefix] == substr.length())
            cout << "string[" << prefix - 2 * substr.length() <<  "..." << prefix - substr.length() - 1 << "] = substring";
    }
    return 0;
}