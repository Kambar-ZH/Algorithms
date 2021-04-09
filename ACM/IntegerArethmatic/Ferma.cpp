#include <bits/stdc++.h>
using namespace std;

template <class T, class T2>
T ferma (const T & n, T2 unused)
{
	T2
		x = sqrt(n),
		y = 0,
		r = x*x - y*y - n;
	for (;;)
		if (r == 0)
			return x!=y ? x-y : x+y;
		else
			if (r > 0)
			{
				r -= y+y+1;
				++y;
			}
			else
			{
				r += x+x+1;
				++x;
			}
};

int main()
{
    int n = ferma(127, 0);
    cout << n;
    return 0;
}