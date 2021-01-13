#define _CRT_SECURE_NO_WARNINGS
#include "Court.h"
#include <iostream>
#include <ctime>

Court::Court()
{
	address_ = "unknown";
	capacity_ = 0;
	attendance_ = 0.0;
	avgAttendance_ = 0.0;
	historyOfAttendances_.reserve(4);
	seasonTickets_ = 15;
}
Court::Court(std::string address, int capacity, float attendance, std::string coverage)
{
	address_ = address;
	capacity_ = capacity;
	attendance_ = attendance;
	coverage_ = coverage;
	avgAttendance_ = 0.0;
	historyOfAttendances_.reserve(4);
	seasonTickets_ = 15;
}

void Court::setSeasonTickets(int seasonTickets)
{
	seasonTickets_ = seasonTickets > 15 ? 15 : seasonTickets;
}

void Court::ticket()
{
	time_t now = time(0);
	tm* ltm = localtime(&now);
	int currentMonth = 1 + ltm->tm_mon;
	if (currentMonth > 5 && currentMonth < 9) {
		if (seasonTickets_ > 0)
		{
			seasonTickets_--;
			std::cout << "Issued season ticket with number: " << 16 - seasonTickets_ << std::endl;
		}
		else
			std::cout << "No more season tickets" << std::endl;
	}
	else
		std::cout << "Now is not the time to buy season tickets" << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Court& s)
{
	out << "The stadium is in " << s.address_ << std::endl;
	out << "Capacity: " << s.capacity_ << std::endl;
	out << "Number of available season tickets: " << s.seasonTickets_ << std::endl;
	return out;
}