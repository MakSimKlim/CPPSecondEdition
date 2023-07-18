#include "Date.h"

Date::Date(uint16_t dayP, uint16_t monthP, uint16_t yearP, int currYear) :
	day{ dayP },
	month{ monthP },
	year{ yearP },
	// инициализация константных полей
	currentYear {currYear},
	baseYear{1970}

{
	std::cout << "Date constructed for " << this << "\n";
};

Date::Date() : Date { 1, 1, 1970, 1970 }
{};

Date::~Date() {
	std::cout << "Date destroyed for " << this << "\n";
}