#include "card.hpp"
#include <vector>
#include <iterator>
#include <algorithm>

class availCards {
	std::vector<Card> cards;
public:
	availCards() {
		for (auto s=0; s < suitVar; s++)
			for (auto r=0; r < rankVar; r++)
				cards.push_back(Card(static_cast<suit>(s), static_cast<rank>(r)));
	}
	unsigned int numUnknCards() const {return cards.size();}
	void erase(Card crt) {
		auto it = std::remove(cards.begin(), cards.end(), crt);
		cards.erase(it, cards.end());
	} //write
	void erase(std::pair<suit, rank> crt) {} //write
	void erase(suit crtS, rank crtR) {} //write
	~availCards() {cards.clear();}
};
