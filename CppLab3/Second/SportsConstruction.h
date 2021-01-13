#pragma once
#include <string>
#include <vector>

class SportsConstruction
{
protected:
	std::string address_;
	std::string coverage_;
	int capacity_;
	int seasonTickets_;
	float square_;
	float attendance_;
	float avgAttendance_;
	std::vector <float> historyOfAttendances_;

public:
	void setAddress(std::string address);
	void setCoverage(std::string coverage);
	void setCapacity(int capacity);
	virtual void setSeasonTickets(int seasonTickets);
	void setSquare(float square);
	void setAttendance(float Attendance);
	void playGame(int visitors);
	float calculateAttendance(int visitors) const;
	friend std::ostream& operator<<(std::ostream& out, const SportsConstruction& s);
	virtual ~SportsConstruction() {}
};