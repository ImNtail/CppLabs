#include "IFormattable.h"
#include "..//First/Deck.h"

#include <string>
#include <iostream>

class Adapter : public IFormattable
{
public:
	Adapter();
	std::string format() override;
	void prettyPrint(const Deck& formatDeck) override;
};