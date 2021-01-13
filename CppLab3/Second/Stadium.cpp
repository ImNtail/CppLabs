#include "Stadium.h"
#include <iostream>
#include <fstream>
#include <vector>

Stadium::Stadium()
{
	address_ = "Unknown";
	footballClub_ = "Unknown";
	sectors_ = 0;
	capacity_ = 0;
	attendance_ = 0.0;
	avgAttendance_ = 0.0;
	historyOfAttendances_.reserve(4);
	seasonTickets_ = 100;
}
Stadium::Stadium(std::string address, std::string footballClub, int sectors, int capacity, float attendance)
{
	address_ = address;
	footballClub_ = footballClub;
	sectors_ = sectors;
	capacity_ = capacity;
	attendance_ = attendance;
	avgAttendance_ = 0.0;
	historyOfAttendances_.reserve(4);
	seasonTickets_ = 100;
}

void Stadium::setFootballClub(std::string footballClub)
{
	footballClub_ = footballClub;
}

void Stadium::setSectors(int sectors)
{
	sectors_ = sectors;
}

void Stadium::setSeasonTickets(int season_tickets)
{
	seasonTickets_ = season_tickets > 100 ? 100 : season_tickets;
}

void Stadium::ticket()
{
	if (seasonTickets_ > 0)
	{
		seasonTickets_--;
		serialize();
		std::cout << "Issued season ticket with number: " << 100 - seasonTickets_ << std::endl;
	}
	else
		std::cout << "No more season tickets" << std::endl;
}

void Stadium::serialize() const
{
	serialize(footballClub_);
}

void Stadium::serialize(const std::string& filename) const
{
	std::ofstream fout(filename + ".txt");
	if (fout.is_open())
	{
		fout << address_ << std::endl;
		fout << footballClub_ << std::endl;
		fout << sectors_ << std::endl;
		fout << capacity_ << std::endl;
		fout << attendance_ << std::endl;
		fout << avgAttendance_ << std::endl;
		fout << seasonTickets_ << std::endl;
		fout.close();
	}
}

void Stadium::deserialize()
{
	deserialize(footballClub_);
}

void Stadium::deserialize(const std::string& filename)
{
	std::ifstream file(filename + ".txt");
	std::string line;
	if (file.is_open())
	{
		std::getline(file, line);
		address_ = line;
		std::getline(file, line);
		footballClub_ = line;
		std::getline(file, line);
		sectors_ = std::stoi(line);
		std::getline(file, line);
		capacity_ = std::stoi(line);
		std::getline(file, line);
		attendance_ = atof(line.c_str());
		std::getline(file, line);
		avgAttendance_ = atof(line.c_str());
		std::getline(file, line);
		seasonTickets_ = std::stoi(line);
	}
}

void Stadium::sort(Stadium* arr[], int n)
{
	int i, j;
	Stadium* key;
	for (i = 1; i < n; ++i)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j]->getAvgAttendance() < key->getAvgAttendance())
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

int Stadium::getCapacity() const
{
	return capacity_;
}

float Stadium::getAvgAttendance() const
{
	return avgAttendance_;
}

std::ostream& operator<<(std::ostream& out, const Stadium& s)
{
	out << "The stadium is in " << s.address_ << std::endl;
	out << "Home club: " << s.footballClub_ << std::endl;
	out << "Capacity: " << s.capacity_ << std::endl;
	out << "Number of available season tickets: " << s.seasonTickets_ << std::endl;

	return out;
}