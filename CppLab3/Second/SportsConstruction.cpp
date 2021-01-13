#include "SportsConstruction.h"
#include <iostream>

void SportsConstruction::setAddress(std::string address)
{
	address_ = address;
}

void SportsConstruction::setCoverage(std::string coverage)
{
	coverage_ = coverage;
}

void SportsConstruction::setCapacity(int capacity)
{
	capacity_ = capacity;
}

void SportsConstruction::setSeasonTickets(int seasonTickets)
{
	seasonTickets_ = seasonTickets;
}

void SportsConstruction::setSquare(float square)
{
	square_ = square;
}

void SportsConstruction::setAttendance(float attendance)
{
	attendance_ = attendance;
}

void SportsConstruction::playGame(int visitors)
{
	historyOfAttendances_.push_back(calculateAttendance(visitors));
	float sum = 0;
	for (size_t i = 0; i < historyOfAttendances_.size(); i++)
		sum += historyOfAttendances_[i];
	avgAttendance_ = sum / historyOfAttendances_.size();
}

float SportsConstruction::calculateAttendance(int visitors)const
{
	return (float)visitors / capacity_ * 100;
}

std::ostream& operator<<(std::ostream& out, const SportsConstruction& s)
{
	out << "The sport construction is in " << s.address_ << std::endl;
	out << "Capacity: " << s.capacity_ << std::endl;
	out << "Number of available season tickets: " << s.seasonTickets_ << std::endl;
	return out;
}