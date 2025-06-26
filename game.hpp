#include "card.hpp"
#include <vector>

class availCards {
	std::vector<Card> cards;
public:
	availCards() {
		for (auto s=0; s < suitVar; s++)
			for (auto r=0; r < rankVar; r++)
				cards.push_back(Card(static_cast<suit>(s), static_cast<rank>(r)));
	}
	unsigned int numUnknCards() const {return cards.size();}
	~availCards() {cards.clear();}
};
