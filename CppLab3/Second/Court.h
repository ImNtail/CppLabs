#pragma once
#include "SportsConstruction.h"
#include "ISeasonTicketProvider.h"

class Court : public SportsConstruction, public ISeasonTicketProvider
{
public:
	Court();
	Court(std::string address, int capacity, float attendance, std::string coverage);

	void setSeasonTickets(int seasonTickets) override;
	void ticket() override;

	friend std::ostream& operator<< (std::ostream& out, const Court& s);
};