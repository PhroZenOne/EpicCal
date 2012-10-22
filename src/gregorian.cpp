#ifndef GregorianDate_CPP
#define GregorianDate_CPP

#include "gregorian.h"

using namespace lab2;

Gregorian::Gregorian() :
		LatinDate() {
	set_day_vars();
}

Gregorian::Gregorian(const Date & r) :
		LatinDate(r) {
	set_day_vars();
}

Gregorian::Gregorian(int year, int month, int day) {
	set_calendar(year, month, day);
}

Gregorian::~Gregorian(void) {
}

bool Gregorian::is_leap_year(int year) const {
	return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int Gregorian::get_mod_day() const {
	return MOD_DAY;
}

#endif
