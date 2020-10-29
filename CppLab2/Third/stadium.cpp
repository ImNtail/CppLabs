#include <iostream>
#include <string>
#include "Stadium.h"

//==================== constructors / destructor ====================

Stadium::Stadium()
{
	address_ = "";
	footballClub_ = "";
	sectorsNum_ = NULL;
	capacity_ = NULL;
	attendance_ = NULL;
}

Stadium::Stadium(std::string address, std::string footballClub, int sectorsNum, int capacity, int attendance)
{
	address_ = address;
	footballClub_ = footballClub;
	sectorsNum_ = sectorsNum;
	capacity_ = capacity;
	attendance_ = attendance;
}

Stadium::Stadium(const Stadium& s)
{
	address_ = s.address_;
	footballClub_ = s.footballClub_;
	sectorsNum_ = s.sectorsNum_;
	capacity_ = s.capacity_;
	attendance_ = s.attendance_;
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
}

Stadium::~Stadium()
{
	std::cout << "Stadium has deleted" << std::endl;
}

//==================== setters / getters ====================

void Stadium::set(std::string address, std::string footballClub, int sectorsNum, int capacity, int attendance)
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

void Stadium::setCapacity(int capacity)
{
	capacity_ = capacity;
}

void Stadium::setAttendance(int attendance)
{
	attendance_ = attendance;
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

int Stadium::getCapacity() const
{
	return capacity_;
}

int Stadium::getAttendance() const
{
	return attendance_;
}

//==================== other functions ====================

void Stadium::serialize()
{

}

void Stadium::serialize(const std::string& filename)
{

}

void Stadium::deserialize()
{

}

void Stadium::deserialize(const std::string& filename)
{

}