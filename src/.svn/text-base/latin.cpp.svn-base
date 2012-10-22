#ifndef LatinDate_CPP_
#define LatinDate_CPP_

#include "latin.h"

using namespace lab2;

LatinDate::~LatinDate() {
}

LatinDate::LatinDate() :
		mDay(0), mYear(0), mMonth(0), mWeek_day(0) {
}

LatinDate::LatinDate(const Date & r) :
		Date(r), mDay(0), mYear(0), mMonth(0), mWeek_day(0) {
}

void LatinDate::set_calendar(int year, int month, int day) {
	daystamp = 0;

	--month; //0-index to be consistent.
	--day;
	check_if_valid(day, month, year);
	mDay = day;
	mMonth = month;
	mYear = year;

	// calculate the daystamp

	int current_year = year; // save the current year to do some calculations on it later
	--year; // start counting hole years (excluding current one).

	// add all years.
	while (year > MOD_YEAR) {
		if (is_leap_year(year)) {
			daystamp += 366;
		} else {
			daystamp += 365;
		}
		--year;
	}

	// add days in year
	if (current_year != MOD_YEAR) {
		// add all days and month;
		daystamp += day;
		daystamp += SUMM_DAYS_IN_MONTH[month];
		if (is_leap_year(current_year) && month > 1) {
			daystamp += 1;
		}
		daystamp += DAYS_IN_MONTH[11]; // add December for 1858
		daystamp += DAYS_IN_MONTH[10] - get_mod_day(); // add the rest of days in November to MOD day.
	} else { // if current_year is same as mod year lets see how many days into the year we are.
		int days_from_start_of_year = SUMM_DAYS_IN_MONTH[month] + day;
		int fix_days_from_start = SUMM_DAYS_IN_MONTH[10] + get_mod_day();
		daystamp += days_from_start_of_year - fix_days_from_start;
	}

	mWeek_day = MOD_WEEK_DAY; // mod julian day was a Wednesday!
	mWeek_day = (mWeek_day + daystamp) % 7;
	mWeek_day = mWeek_day < 0 ? mWeek_day + 7 : mWeek_day;
}

//
// Access
//

void LatinDate::add_year(int n) {
	if (n < 0) {
		remove_year(-n);
		return;
	}

	if (mMonth == 1 && mDay == 28 && n % 4 == 0 && is_leap_year(mYear + n)) {
		int days_to_add = (365 * n) + (n / 4);
		daystamp += days_to_add;
		mYear += n;
		mWeek_day = (mWeek_day + days_to_add) % 7;
	} else {
		if (mMonth == 1 && mDay == 28) {
			remove_day(); // if we are on leap day and add year not divisible by 4 lets take a step back.
		}
		while (n--) {
			if ((is_leap_year(mYear) && mMonth <= 1)
					|| (is_leap_year(mYear + 1) && mMonth > 1)) {
				daystamp += 366;
				++mYear;
				mWeek_day = (mWeek_day + 366) % 7;
			} else {
				daystamp += 365;
				++mYear;
				mWeek_day = (mWeek_day + 365) % 7;
			}
		}
	}
}

void LatinDate::remove_year(int n) {
	if (n < 0) {
		add_year(-n);
		return;
	}

	if (mMonth == 1 && mDay == 28 && n % 4 == 0 && is_leap_year(mYear - n)) {
		int days_to_remove = (365 * n) + (n / 4);
		daystamp -= days_to_remove;
		mYear -= n;
		mWeek_day = (((mWeek_day - days_to_remove) % 7) + 7) % 7; // % 7) + 7) % 7... c++ modulus is broken, I fixed it! :P
	} else {
		if (mMonth == 1 && mDay == 28) {
			remove_day(1); // if we are on leap day and add year not divisible by 4 lets take a step back.
		}
		while (n--) {
			if ((is_leap_year(mYear) && mMonth > 1)
					|| (is_leap_year(mYear - 1) && mMonth <= 1)) {
				daystamp -= 366;
				--mYear;
				mWeek_day = (((mWeek_day - 366) % 7) + 7) % 7;
			} else {
				daystamp -= 365;
				--mYear;
				mWeek_day = (((mWeek_day - 365) % 7) + 7) % 7;
			}
		}
	}
}

void LatinDate::add_month(int n) {
	if (n < 0) {
		remove_month(-n);
		return;
	}
	while (n--) {
		int day_before = mDay;
		int days_to_add = get_days_in_month(mYear, mMonth);
		add_day(days_to_add);
		if (day_before != mDay) {
			add_day(30 - days_to_add);
		}
	}
}

int LatinDate::days_per_week() const {
	return DAYS_PER_WEEK;
}

int LatinDate::days_this_month() const {
	return get_days_in_month(mYear, mMonth);
}

int LatinDate::months_per_year() const {
	return MONTH_PER_YEAR;
}

std::string LatinDate::week_day_name() const {
	return WEEK_NAME[mWeek_day];
}

std::string LatinDate::month_name() const {
	return MONTH_NAME[mMonth];
}

int LatinDate::year() const {
	return mYear;
}

int LatinDate::month() const {
	return mMonth + 1; // month() is not zero indexed, mMonth is.
}

int LatinDate::day() const {
	return mDay + 1; // day() is not zero indexed, mDay is.
}

int LatinDate::week_day() const {
	return mWeek_day + 1;
}

//
// Constants
//

const short LatinDate::DAYS_IN_MONTH[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30,
		31, 30, 31 };

const short LatinDate::SUMM_DAYS_IN_MONTH[12] = { 0, 31, 59, 90, 120, 151, 181,
		212, 243, 273, 304, 334 }; //prefab sum

const std::string LatinDate::MONTH_NAME[] = { "january", "february", "march",
		"april", "may", "june", "july", "august", "september", "october",
		"november", "december" };

const std::string LatinDate::WEEK_NAME[] = { "monday", "tuesday", "wednesday",
		"thursday", "friday", "saturday", "sunday" };

//
// Tools
//

int LatinDate::get_days_in_month(int year, int month) const {
	return DAYS_IN_MONTH[month] + ((month == 1 && is_leap_year(year)) ? 1 : 0);
}

void LatinDate::set_day_vars() {
	mDay = get_mod_day(); //reset all to mod julian day (0 indexed)
	mMonth = MOD_MONTH;
	mYear = MOD_YEAR; // now we have 17 Nov 1858 Greg or 5 Nov julian day.
	mWeek_day = MOD_WEEK_DAY; // mod julian day was a Wednesday!
	int tmp = daystamp;
	daystamp = 0; //reset daystamp
	// then add the calculated number of days.
	add_day(tmp);
}

void LatinDate::add_day(int n) {
	if (n < 0) {
		remove_day(-n);
		return;
	}
	mWeek_day = (mWeek_day + n) % 7;
	int days_this_month = get_days_in_month(mYear, mMonth) - 1; // -1 Because of 0-index mDay
	while (n--) {
		++daystamp;
		++mDay;
		if (mDay > days_this_month) {
			mDay = 0;
			if (mMonth != 11) {
				++mMonth;
			} else {
				mMonth = 0;
				++mYear;
			}
			days_this_month = get_days_in_month(mYear, mMonth) - 1; // -1 Because of 0-index mDay
		}
	}
}

void LatinDate::remove_day(int n) {
	if (n < 0) {
		add_day(-n);
		return;
	}

	mWeek_day = (mWeek_day - n) % 7;
	mWeek_day = mWeek_day < 0 ? mWeek_day + 7 : mWeek_day;

	while (n--) {
		--daystamp;
		--mDay;
		if (mDay < 0) {
			--mMonth;
			if (mMonth < 0) {
				mMonth = 11;
				--mYear;
			}
			mDay = get_days_in_month(mYear, mMonth) - 1;
		}
	}
}

void LatinDate::remove_month(int n) {
	if (n < 0) {
		add_month(-n);
		return;
	}

	while (n--) {
		int day_before = mDay;
		int month_before = mMonth - 1;
		int tmp_year = mYear;
		if (month_before < 0) {
			tmp_year--;
			month_before = 11;
		}

		int days_to_remove = get_days_in_month(tmp_year, month_before);
		add_day(-days_to_remove);
		if (day_before != mDay) {
			add_day(days_to_remove - 30);
		}
	}
}

void LatinDate::check_if_valid(const int & day, const int & month,
		const int & year) const {

	//This calendar is not allowing stuff before 1858
	if (year < MOD_YEAR) {
		throw std::out_of_range("date before 1858 not OK");
	} else if (month < 0 || month > 11) {
		throw std::out_of_range("date month is out of bounds");
	} else if (day < 0) {
		throw std::out_of_range("date day is negative");
	}

	if (month != 1) // month == 1 means November, special care needed for leap year.
			{
		if (day > DAYS_IN_MONTH[month] - 1) //-1 <= 0 index;
				{
			throw std::out_of_range("Day to large for month");
		}
	} else if (!is_leap_year(year)) {
		if (day > DAYS_IN_MONTH[month] - 1) {
			throw std::out_of_range("Day to large for month");
		}
	} else if (day > DAYS_IN_MONTH[month]) {
		// it is leap-year and month is november.
		throw std::out_of_range("Day to large for month");
	}
}

namespace lab2 {
std::ostream & operator<<(std::ostream& stream, const lab2::LatinDate & cal) {

	stream << cal.year() << "-" << ((cal.month() < 10) ? "0" : "")
			<< cal.month() << "-" << ((cal.day() < 10) ? "0" : "") << cal.day();
	return stream;
}
}

#endif
