// 230619_2(указатели на функции)
// 
//

#include <iostream>
using namespace std;

int add(int n, int m)
{
	return n + m;
}
int divd(int n, int m)
{
	return n / m;
}
int mult(int n, int m)
{
	return n * m;
}
int subt(int n, int m)
{
	return n - m;
}



int main()
{
	int (*ptr)(int, int);
	int a = 6, b = 2;
	char c = '+';
	ptr = add;
	while (c != ' ')
	{
		cout << a << " " << c << " " << b << " = ";
		switch (c)
		{
		case '+':
			ptr = add;
			c = '/';
			break;
		case '-':
			ptr = subt;
			c = ' ';
			break;
		case '*':
			ptr = mult;
			c = '-';
			break;
		case '/':
			ptr = divd;
			c = '*';
			break;
			}
		a = ptr(a, b);
		cout << ptr(a, b) << endl;
	}
	return 0;
   
}

