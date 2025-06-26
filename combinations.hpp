#ifndef COMBINATIONS_HPP_INCLUDED
#define COMBINATIONS_HPP_INCLUDED

#include "card.hpp"

enum class combination {
	HIGH_CARD,
	ONE_PAIR,																	// done
	TWO_PAIR,																	// done
	THREE_OF_A_KIND,															// done
	STRAIGHT,
	FLUSH,																		// done
	FULL_HOUSE,
	FOUR_OF_A_KIND,																// done
	STRAIGHT_FLUSH,
	ROYAL_FLUSH																	// done
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

bool isONE_PAIR(std::vector<Card> vec) {
	if (vec.size() < 2)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[13] = {0};
	for (Card tmp : vec)
		switch (tmp.getRank()) {
			case rank::A		: su[0]++;
			case rank::_2		: su[1]++;
			case rank::_3		: su[2]++;
			case rank::_4		: su[3]++;
			case rank::_5		: su[4]++;
			case rank::_6		: su[5]++;
			case rank::_7		: su[6]++;
			case rank::_8		: su[7]++;
			case rank::_9		: su[8]++;
			case rank::_10		: su[9]++;
			case rank::J		: su[10]++;
			case rank::Q		: su[11]++;
			case rank::K		: su[12]++;
		}
	int sum = 0;
	for (int t: su)
		sum += t/2;
	return sum;
}

bool isTWO_PAIR(std::vector<Card> vec) {
	if (vec.size() < 4)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[13] = {0};
	for (Card tmp : vec)
		switch (tmp.getRank()) {
			case rank::A		: su[0]++;
			case rank::_2		: su[1]++;
			case rank::_3		: su[2]++;
			case rank::_4		: su[3]++;
			case rank::_5		: su[4]++;
			case rank::_6		: su[5]++;
			case rank::_7		: su[6]++;
			case rank::_8		: su[7]++;
			case rank::_9		: su[8]++;
			case rank::_10		: su[9]++;
			case rank::J		: su[10]++;
			case rank::Q		: su[11]++;
			case rank::K		: su[12]++;
		}
	int sum = 0;
	for (int t: su)
		sum += t/2;
	return sum >= 2 ? true : false;
}

bool isTHREE_OF_A_KIND(std::vector<Card> vec) {
	if (vec.size() < 3)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[13] = {0};
	for (Card tmp : vec)
		switch (tmp.getRank()) {
			case rank::A		: su[0]++;
			case rank::_2		: su[1]++;
			case rank::_3		: su[2]++;
			case rank::_4		: su[3]++;
			case rank::_5		: su[4]++;
			case rank::_6		: su[5]++;
			case rank::_7		: su[6]++;
			case rank::_8		: su[7]++;
			case rank::_9		: su[8]++;
			case rank::_10		: su[9]++;
			case rank::J		: su[10]++;
			case rank::Q		: su[11]++;
			case rank::K		: su[12]++;
		}
	int sum = 0;
	for (int t: su)
		sum += t/3;
	return sum;
}

bool isFLUSH(std::vector<Card> vec) {
	if (vec.size() < 5)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[4] = {0,0,0,0};
	for (Card tmp : vec)
		switch (tmp.getSuit()) {
			case suit::SPADES		: su[0]++;
			case suit::HEARTS		: su[1]++;
			case suit::DIAMONDS		: su[2]++;
			case suit::CLUBS		: su[3]++;
		}
	return su[0]/5 + su[1]/5 + su[2]/5 + su[3]/5;
}

bool isFOUR_OF_A_KIND(std::vector<Card> vec) {
	if (vec.size() < 4)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[13] = {0};
	for (Card tmp : vec)
		switch (tmp.getRank()) {
			case rank::A		: su[0]++;
			case rank::_2		: su[1]++;
			case rank::_3		: su[2]++;
			case rank::_4		: su[3]++;
			case rank::_5		: su[4]++;
			case rank::_6		: su[5]++;
			case rank::_7		: su[6]++;
			case rank::_8		: su[7]++;
			case rank::_9		: su[8]++;
			case rank::_10		: su[9]++;
			case rank::J		: su[10]++;
			case rank::Q		: su[11]++;
			case rank::K		: su[12]++;
		}
	int sum = 0;
	for (int t: su)
		sum += t/4;
	return sum;
}

bool isROYAL_FLUSH(std::vector<Card> vec) {
	if (vec.size() < 5)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[4] = {0};
	suit s;
	for (Card tmp : vec)
		switch (tmp.getSuit()) {
			case suit::SPADES		: su[0]++;
			case suit::HEARTS		: su[1]++;
			case suit::DIAMONDS		: su[2]++;
			case suit::CLUBS		: su[3]++;
		}
	if ((int)su[0] >= 5) {
		s = suit::SPADES;
		goto counting_ranks;
	}
	if ((int)su[1] >= 5) {
		s = suit::HEARTS;
		goto counting_ranks;
	}
	if ((int)su[2] >= 5) {
		s = suit::DIAMONDS;
		goto counting_ranks;
	}
	if ((int)su[3] >= 5) {
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

combination findPowerComb (std::vector<Card> vec) {
	if (isROYAL_FLUSH(vec)) return combination::ROYAL_FLUSH;
	//if (isSTRAIGHT_FLUSH(vec)) return combination::STRAIGHT_FLUSH;
	if (isFOUR_OF_A_KIND(vec)) return combination::FOUR_OF_A_KIND;
	//if (isFULL_HOUSE(vec)) return combination::FULL_HOUSE;
	if (isFLUSH(vec)) return combination::FLUSH;
	//if (isSTRAIGHT(vec)) return combination::STRAIGHT;
	if (isTHREE_OF_A_KIND(vec)) return combination::THREE_OF_A_KIND;
	if (isTWO_PAIR(vec)) return combination::TWO_PAIR;
	if (isONE_PAIR(vec)) return combination::ONE_PAIR;
	return combination::HIGH_CARD;
}



#endif // COMBINATIONS_HPP_INCLUDED
