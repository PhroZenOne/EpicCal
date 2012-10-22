#ifndef GREGORIANDATE_H_
#define GREGORIANDATE_H_

#include "latin.h"
#include <stdexcept>

namespace lab2 {
class Gregorian: public LatinDate {
public:
	Gregorian();
	Gregorian(const Date &);
	Gregorian(int day, int month, int year);
	virtual ~Gregorian(void);

	static const int MOD_DAY = 16;

	bool is_leap_year(int year) const;

	int get_mod_day() const;
};
}
#endif
