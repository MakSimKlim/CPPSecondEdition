#include "Date.h"

Date::Date(uint16_t dayP, uint16_t monthP, uint16_t yearP) :
	day{ dayP },
	month{ monthP },
	year{ yearP }
{
	std::cout << "Date constructed for " << this << "\n";
};

Date::Date() : Date{ 1, 1, 1970 }
{};

Date::~Date() {
	std::cout << "Date destroyed for " << this << "\n";
}