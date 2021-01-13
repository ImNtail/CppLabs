#pragma once
#include <string>

class ISeasonTicketProvider
{
public:
	virtual void ticket() = 0;
	virtual ~ISeasonTicketProvider() {}
};