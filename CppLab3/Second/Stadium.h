#pragma once
#include <string>
#include <vector>
#include "SportsConstruction.h"
#include "ISeasonTicketProvider.h"

class Stadium : public SportsConstruction, public ISeasonTicketProvider
{
	std::string footballClub_;
	int sectors_;
public:
	Stadium();
	Stadium(std::string address, std::string footballClub, int sectors, int capacity, float attendance);

	void setFootballClub(std::string footballClub);
	void setSectors(int sectors);
	void setSeasonTickets(int season_tickets) override;

	void ticket()override;

	void serialize() const;
	void serialize(const std::string& filename) const;
	void deserialize();
	void deserialize(const std::string& filename);

	static void sort(Stadium* arr[], int n);
	friend std::ostream& operator<< (std::ostream& out, const Stadium& s);

	int getCapacity()const;
	float getAvgAttendance()const;
};