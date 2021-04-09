#include <bits/stdc++.h>
using namespace std;
 
int phi (int n) {
	int result = n; // n = 16
	for (int i=2; i*i<=n; ++i) // i = 2 until 4  
		if (n % i == 0) { // находим все делители числа 16
			while (n % i == 0) // пока это число делится на i факторизуем его
				n /= i; // цикл повторяется 4 раза
			result -= result / i; // результат равен 16 - 16 / 2 = 8
		}
    cout << endl;
	if (n > 1) // если остаток простой
		result -= result / n;
	return result;
}

int main()
{
    int n;
    scanf("%d", &n);
    int result = phi(n);
    printf("%d", result);
    return 0;
}
// Мы ищем все числа от 1 до n - 1 которые взаимно просты с n

// По свойству разложения
// phi(30) = phi(2) * phi(3) * phi(5) = (2 - 1) * (3 - 1) * (5 - 1) = 8
// так как по 2,3,5 простые числа пользуемся свойством phi(p) = p - 1