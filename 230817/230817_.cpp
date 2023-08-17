// 230817_
//

#include <iostream>
#include <time.h>


using namespace std;

int max(int a, int b)
{
	return a > b ? a : b;
}
template <typename T1, typename T2> int max(T1 a, T2 b) = delete;
// ключевое слово delete выключает (запрещает) перегрузки




int main()
{
	srand(time(0));
	cout << max(20, 30) << endl;
	cout << max(20.5, 30) << endl;    //ошибка из-за delete
	cout << max('a', 30) << endl;     //ошибка из-за delete
	cout << max(20.5, false) << endl; //ошибка из-за delete

	return 0;

}

