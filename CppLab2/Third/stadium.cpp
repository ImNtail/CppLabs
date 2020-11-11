#include <iostream>
#include <fstream>
#include <string>
#include "Stadium.h"

//==================== constructors / destructor ====================

int Stadium::cnt = 0;

Stadium::Stadium()
{
	address_ = "";
	footballClub_ = "";
	sectorsNum_ = NULL;
	capacity_ = NULL;
	attendance_ = NULL;
	avgPerc_ = NULL;
	cnt++;
}

Stadium::Stadium(std::string footballClub, std::string address, int sectorsNum, int capacity, int attendance)
{
	address_ = address;
	footballClub_ = footballClub;
	sectorsNum_ = sectorsNum;
	capacity_ = capacity;
	attendance_ = attendance;
	avgPerc_ = NULL;
	cnt++;
}

Stadium::Stadium(const Stadium& s)
{
	address_ = s.address_;
	footballClub_ = s.footballClub_;
	sectorsNum_ = s.sectorsNum_;
	capacity_ = s.capacity_;
	attendance_ = s.attendance_;
	avgPerc_ = s.avgPerc_;
	cnt++;
}

Stadium& Stadium::operator=(Stadium s)
{
	swap(s);
	return *this;
}

void Stadium::swap(Stadium s)
{
	std::swap(address_, s.address_);
	std::swap(footballClub_, s.footballClub_);
	std::swap(sectorsNum_, s.sectorsNum_);
	std::swap(capacity_, s.capacity_);
	std::swap(attendance_, s.attendance_);
	std::swap(avgPerc_, s.avgPerc_);
}

Stadium::~Stadium()
{
	std::cout << "Stadium has deleted" << std::endl;
	cnt--;
}

//==================== setters / getters ====================

void Stadium::set(std::string footballClub, std::string address, int sectorsNum, int capacity, int attendance)
{
	address_ = address;
	footballClub_ = footballClub;
	sectorsNum_ = sectorsNum;
	capacity_ = capacity;
	attendance_ = attendance;
}

void Stadium::setAddress(std::string address)
{
	address_ = address;
}

void Stadium::setClub(std::string footballClub)
{
	footballClub_ = footballClub;
}

void Stadium::setSectorsNum(int sectorsNum)
{
	sectorsNum_ = sectorsNum;
}

void Stadium::setCapacity(float capacity)
{
	capacity_ = capacity;
}

void Stadium::setAttendance(float attendance)
{
	attendance_ = attendance;
}

void Stadium::setAvgPerc(float avgPerc)
{
	avgPerc_ = avgPerc;
}

std::string Stadium::getAddress() const
{
	return address_;
}

std::string Stadium::getClub() const
{
	return footballClub_;
}

int Stadium::getSectorsNum() const
{
	return sectorsNum_;
}

float Stadium::getCapacity() const
{
	return capacity_;
}

float Stadium::getAttendance() const
{
	return attendance_;
}

float Stadium::getAvgPerc() const
{
	return avgPerc_;
}

//==================== other functions ====================

void Stadium::print()
{
	std::cout << "\nFootball club: " << footballClub_ << "\nAddress of the stadium: " << address_ << "\nSector nums: "
		<< sectorsNum_ << "\nCapacity: " << capacity_ << "\nAttendance: " << attendance_ << "\nAvg percentage: " << avgPerc_ << "\n" << std::endl;
}

std::string defaultPath(std::string name)
{
	std::string defaultLocation = __FILE__;
	int pos = defaultLocation.find_last_of('\\');
	if (pos != std::string::npos)
		defaultLocation.erase(pos, std::numeric_limits<std::string::size_type>::max());
	defaultLocation = defaultLocation + "\\" + name + ".txt";
	return defaultLocation;
}

void Stadium::serialize()
{
	std::ofstream out;
	out.open(defaultPath(footballClub_));
	if (out.is_open())
		out << "| " << footballClub_ << " | " << address_ << " | " << sectorsNum_ << " | " << capacity_ << " | " << attendance_ << " | " << avgPerc_ << " |\n";
	out.close();
	std::cout << "Stadium has written" << std::endl;
}

void Stadium::serialize(const std::string& filename)
{
	std::ofstream out;
	out.open(defaultPath(filename));
	if (out.is_open())
		out << "| " << footballClub_ << " | " << address_ << " | " << sectorsNum_ << " | " << capacity_ << " | " << attendance_ << " | " << avgPerc_ << " |\n";
	out.close();
	std::cout << "Stadium has written" << std::endl;
}

void Stadium::deserialize()
{
	std::string line;
	std::ifstream in(defaultPath(footballClub_));
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();
}

void Stadium::deserialize(const std::string& filename)
{
	std::string line;
	std::ifstream in(defaultPath(filename));
	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::cout << line << std::endl;
		}
	}
	in.close();
}

void Stadium::sort(Stadium** arr, int size)
{
	std::cout << "\nSortion:" << std::endl;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			std::cout << arr[j]->getAvgPerc() << " --- " << arr[j + 1]->getAvgPerc() << std::endl;
			if (arr[j]->getAvgPerc() < arr[j + 1]->getAvgPerc())
			{
				Stadium* temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	std::cout << "Sorted." << std::endl;
}