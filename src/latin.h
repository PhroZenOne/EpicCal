#ifndef LATINDATE_H_
#define LATINDATE_H_

#include "date.h"
#include <ostream>
#include <stdexcept>

namespace lab2 {
class LatinDate: public Date {
public:

	virtual ~LatinDate();
	LatinDate();
	LatinDate(const Date &);
	LatinDate(int year, int month, int day);

	void set_calendar(int year, int month, int day);

	int days_per_week() const;
	int days_this_month() const;
	int months_per_year() const;
	std::string week_day_name() const;
	std::string month_name() const;

	int day() const;
	int year() const;
	int month() const;
	int week_day() const;

	void add_year(int n = 1);
	void add_month(int n = 1);

protected:

	virtual bool is_leap_year(int year) const = 0;

	static const int DAYS_PER_WEEK = 7;
	static const int MONTH_PER_YEAR = 12;
	static const int MOD_WEEK_DAY = 2; // 2 means wednesday..
	static const int MOD_YEAR = 1858;
	static const int MOD_MONTH = 10; // Can't declare day as it differers from julian and gregorian.

	static const std::string MONTH_NAME[];
	static const std::string WEEK_NAME[];
	static const short DAYS_IN_MONTH[];
	static const short SUMM_DAYS_IN_MONTH[];

	int mDay;
	int mYear;
	int mMonth;
	int mWeek_day;

	int get_days_in_month(int year, int month) const;
	void set_day_vars();
	void add_day(int n = 1);
	void remove_day(int n = 1);
	void remove_month(int n = 1);
	void remove_year(int n = 1);
	void check_if_valid(const int & year, const int & month,
			const int & day) const;

	virtual int get_mod_day() const = 0;
};

std::ostream & operator<<(std::ostream& stream, const LatinDate & cal);

}
#endif
