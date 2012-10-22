#ifndef DATE_CPP
#define DATE_CPP

#include "date.h"
#include "kattistime.h"
#include <time.h>

using namespace lab2;

//
// Constr
//

Date::Date(void)
{
	time_t time;
	k_time(&time);

	// unix time stamp goes from 1 Jan 1970 Gregorian time.
	// this calendars timestamp will be from mod julian day 17 jan 1858 Gregorian time.
	// the difference in seconds between the timestamps is 40587 days.

	daystamp = ((int) (time / (60 * 60 * 24)) + 40587); //divide by sec, min, hour to get days.
}

Date::~Date(void)
{}

//
// Operators
//

Date & Date::operator=(const Date & r)
{
	daystamp = r.daystamp;
	set_day_vars();
	return *this;
}

Date & Date::operator++()
{
	add_day();
	return *this;
}

Date & Date::operator--()
{
	remove_day();
	return *this;
}

Date & Date::operator+=(const int n)
{
	add_day(n);
	return *this;
}

Date & Date::operator-=(const int n)
{
	remove_day(n);
	return *this;
}

//
// comparison
//

bool Date::operator==(const Date & r) const
{
	return (daystamp == r.daystamp);
}

bool Date::operator!=(const Date & r) const
{
	return (daystamp != r.daystamp);
}

bool Date::operator>(const Date & r) const
{
	return (daystamp > r.daystamp);
}

bool Date::operator>=(const Date & r) const
{
	return (daystamp >= r.daystamp);
}

bool Date::operator<=(const Date & r) const
{
	return (daystamp <= r.daystamp);
}

bool Date::operator<(const Date & r) const
{
	return (daystamp < r.daystamp);
}

int Date::operator-(const Date & r) const
{
	return daystamp - r.daystamp;
}

//
// Access
//

int Date::mod_julian_day() const
{
	return daystamp;
}

namespace lab2
{
std::ostream & operator<<(std::ostream& stream, const lab2::Date & date)
{
	stream << date.year() << "-" << ((date.month() < 10) ? "0" : "")
			<< date.month() << "-" << ((date.day() < 10) ? "0" : "")
			<< date.day();
	return stream;
}
}

#endif
