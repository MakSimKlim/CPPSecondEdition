#include <iostream>
#include "Date.h"
using namespace std;

class Account
{
	double sum;
	const double rate;
public:
	Account(double rateP, double sumP) : rate{ rateP }
	{
		sum = sumP;
	}

	double getRate() const { return rate; }
	double getIncome() { return sum * rate / 100; }
	double getIncome() const { return sum * rate / 100; }
	double getSum() const { return sum; }
	double setSum()
	{
		sum += getIncome();
		return sum;
	}
};

int main()
{
	Account acc1(5, 2000);
	const Account acc2{ 8, 5000 };
	acc1.getRate();
	acc2.getRate();

	acc1.getSum();
	acc2.getSum();

	acc1.getIncome();
	acc2.getIncome();

	acc1.getSum();
	acc2.getSum();
	return 0;
}