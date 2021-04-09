#include <bits/stdc++.h>
using namespace std;

void z_function_trivial(string word, vector<int> & z)
{
    for (int i = 0; i < word.length(); ++i)
    {
        while (i + z[i] < word.length() && word[z[i]] == word[i + z[i]])
        {
            z[i] += 1;
        }
    }
}



void z_function(string word, vector<int> & z)
{
    int n = word.size();
    for(int i = 1, l = 0, r = 0; i < n; ++i)
    {
        if (i <= r)
        {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < n && word[z[i]] == word[i + z[i]])
        {
            z[i] += 1;
        }
        if (i + z[i] - 1 > r)
        {
            l = i;
            r = i + z[i] - 1;
        }
    }
}











// void z_function(string word, vector<int> & z)
// {
//     int n = word.size();
//     for (int i=1, l=0, r=0; i<n; ++i) { // пробеамся от 1 до последнего символа
// 		if (i <= r) // пока i <= r примсваиваем значению z[i] минимальное
// 			z[i] = min (r-i+1, z[i-l]);
// 		while (i+z[i] < n && word[z[i]] == word[i+z[i]]) // пока находим совпадения
// 			++z[i]; // прибавляем значение z для этого индекса
// 		if (i+z[i]-1 > r) // если сумма больше чем правая граница
// 			l = i,  r = i+z[i]-1; // тогда l = индексу, а r = 
// 	}
// }

int main()
{
    string word;
    cin >> word;
    vector<int> z (word.length(), 0);
    z_function(word, z);
    for (int i = 0; i < z.size(); ++i)
    {
        cout << z[i] << " ";
    }
    return 0;
}