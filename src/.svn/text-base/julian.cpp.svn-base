#include "julian.h"

using namespace lab2;

Julian::Julian() :
		LatinDate() {
	set_day_vars();
}

Julian::Julian(const Date & r) :
		LatinDate(r) {
	set_day_vars();
}

Julian::Julian(int year, int month, int day) {
	set_calendar(year, month, day);
}

Julian::~Julian(void) {
}

bool Julian::is_leap_year(int year) const {
	if (year % 4 != 0)
		return false; /* not a leap year */
	return true;
}

int Julian::get_mod_day() const {
	return MOD_DAY;
}
