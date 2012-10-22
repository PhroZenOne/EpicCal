#ifndef JULIANDATE_H_
#define JULIANDATE_H_

#include "latin.h"

namespace lab2 {
class Julian: public LatinDate {
public:
	Julian();
	Julian(const Date &);
	Julian(int day, int month, int year);
	virtual ~Julian(void);

	static const int MOD_DAY = 4;

	bool is_leap_year(int year) const;

	int get_mod_day() const;
};
}
#endif
