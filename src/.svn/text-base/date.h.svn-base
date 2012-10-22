#ifndef DATE_H_
#define DATE_H_

#include <string>
#include <iostream>

namespace lab2 {
class Date {
public:

	Date(void);

	virtual ~Date();

	Date & operator=(const Date &);

	Date & operator++(); //prefix
	Date & operator--(); //prefix

	Date & operator+=(int n);
	Date & operator-=(int n);

	bool operator==(const Date &) const;
	bool operator!=(const Date &) const;
	bool operator>(const Date &) const;
	bool operator>=(const Date &) const;
	bool operator<=(const Date &) const;
	bool operator<(const Date &) const;

	int operator-(const Date &) const;

	int mod_julian_day() const; // days from modified julian day (17 Nov 1858)

	virtual int year() const = 0;
	virtual int month() const = 0;
	virtual int day() const = 0;

	virtual int days_per_week() const = 0;
	virtual int days_this_month() const = 0;
	virtual int months_per_year() const = 0;
	virtual int week_day() const = 0;
	virtual std::string week_day_name() const = 0;
	virtual std::string month_name() const = 0;

	virtual void add_month(int n = 1) = 0;
	virtual void add_year(int n = 1) = 0;

protected:

	virtual void set_day_vars() = 0;
	virtual void add_day(int n = 1) = 0;
	virtual void remove_day(int n = 1) = 0;

	// daystamp counts days from from 17 nov 1858. The assignment says that the code should handle time from the year
	// 1858.
	int daystamp;
};

std::ostream & operator<<(std::ostream& stream, const Date & date);

}

#endif
