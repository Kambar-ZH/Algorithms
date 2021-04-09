#include <bits/stdc++.h>
using namespace std;
template<class T, class T2>
T binpow ( const T & a, const T2 & n) {
	if (n == 0)
		return 1;
	if (n % 2 == 1)
		return binpow (a, n-1) * a;
	else {
		T b = binpow (a, n/2);
		return b * b;
	}
}

template<class T, class T2>
T binpow2 ( T & a, T2 & n) {
	T res = 1;
	while (n)
		if (n & 1) {
			res *= a;
			--n;
		}
		else {
			a *= a;
			n >>= 1;
		}
	return res;
}

template<class T, class T2>
T binpow2_modify (T a, T2 n) {
	T res = 1;
	while (n) {
		if (n & 1)
			res *= a;
		a *= a;
		n >>= 1;
	}
	return res;
}

int main()
{
    long long a, n;
    scanf("%d %d", &a, &n);
    printf("%d", binpow2_modify(a, n));
    return 0;
}