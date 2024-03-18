#include <iostream>
#include <string>

class Calendar
{
public:
	Calendar();
	~Calendar();

	void get_date() {
		std::cout << date << "\n";
	}

	void set_date() {
		int year, month, day;

		std::cout << "enter a date (year, month, day) in numerical format and exactly in that order\n";

		std::cin >> year;
		std::cin >> month;
		std::cin >> day;

		if (date_condition(year, month, day)) {
			date = std::to_string(year) + ":" + std::to_string(month) + ":" + std::to_string(day);
			YEAR = year;
		}
		else {
			std::cerr << "Incorrect date\n";
			return;
		}
	}

	void year_is_leap() {
		if (YEAR != 0) {
			if (YEAR % 4 == 0 or (YEAR % 100 == 0 and YEAR % 400 == 0)) {
				std::cout << YEAR << " year is leap\n";
			}
			else {
				std::cout << YEAR << " year is not leap\n";
			}
		}
	}


private:
	std::string date = "0000-00-00";
	int YEAR = 0000;

	bool date_condition(int year, int month, int day) {

		bool yearIsCorrect = (year >= 1000 and year <= 9999 ? true : false);
		bool monthIsCorrect = (month >= 1 and month <= 12 ? true : false);
		bool dayIsCorrect = (day >= 0 and day <= 31 ? true : false);

		if (yearIsCorrect and monthIsCorrect and dayIsCorrect) {
			return true;
		}
		return false;
	}
};

Calendar::Calendar()
{
	std::cout << "object created\n";
}

Calendar::~Calendar()
{
	std::cout << "object destroyed\n";
}


int main() {
	Calendar MyDate;

	MyDate.set_date();
	MyDate.get_date();
	MyDate.year_is_leap();


	return 0;
}