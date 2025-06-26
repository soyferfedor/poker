#include "card.hpp"

enum class combinations {
	HIGH_CARD,
	ONE_PAIR,
	TWO_PAIR,
	THREE_OF_A_KIND,
	STRAIGHT,
	FLUSH,
	FULL_HOUSE,
	FOUR_OF_A_KIND,
	STRAIGHT_FLUSH,
	ROYAL_FLUSH
};

Card maxRank (Card c1, Card c2) {
	return c1.getRank() > c2.getRank() ? c1 : c2;
}

bool isEqualRank (Card c1, Card c2) {
	return c1.getRank() == c2.getRank();
}

bool isEqualSuit (Card c1, Card c2) {
	return c1.getSuit() == c2.getSuit();
}

bool isROYAL_FLUSH(std::vector<Card> vec) {
	if (vec.size() < 5)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[4] = {0,0,0,0};
	suit s;
	Card comb[5];
	for (Card tmp : vec)
		switch (tmp.getSuit()) {
			case suit::SPADES		: su[0]++;
			case suit::HEARTS		: su[1]++;
			case suit::DIAMONDS		: su[2]++;
			case suit::CLUBS		: su[3]++;
		}
	if ((int)su[0] >= 4) {
		s = suit::SPADES;
		goto counting_ranks;
	}
	if ((int)su[1] >= 4) {
		s = suit::HEARTS;
		goto counting_ranks;
	}
	if ((int)su[2] >= 4) {
		s = suit::DIAMONDS;
		goto counting_ranks;
	}
	if ((int)su[3] >= 4) {
		s = suit::CLUBS;
		goto counting_ranks;
	}
	return 0;
counting_ranks:
	int r1 = 0, r2 = 0, r3 = 0, r4 = 0, r5 = 0;
	for (Card tmp : vec) {
		if (tmp.getVal() == std::make_pair(s, rank::A))
			r1 = 1;
		if (tmp.getVal() == std::make_pair(s, rank::K))
			r2 = 1;
		if (tmp.getVal() == std::make_pair(s, rank::Q))
			r3 = 1;
		if (tmp.getVal() == std::make_pair(s, rank::J))
			r4 = 1;
		if (tmp.getVal() == std::make_pair(s, rank::_10))
			r5 = 1;
	}
	return r1*r2*r3*r4*r5;
}
