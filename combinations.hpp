#ifndef COMBINATIONS_HPP_INCLUDED
#define COMBINATIONS_HPP_INCLUDED

#include "card.hpp"

enum class combination {
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

bool isONE_PAIR(std::vector<Card> vec) {
	if (vec.size() < 2)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[13] = {0};
	for (Card tmp : vec)
		switch (tmp.getRank()) {
			case rank::_2		: su[0]++; break;
			case rank::_3		: su[1]++; break;
			case rank::_4		: su[2]++; break;
			case rank::_5		: su[3]++; break;
			case rank::_6		: su[4]++; break;
			case rank::_7		: su[5]++; break;
			case rank::_8		: su[6]++; break;
			case rank::_9		: su[7]++; break;
			case rank::_10		: su[8]++; break;
			case rank::J		: su[9]++; break;
			case rank::Q		: su[10]++; break;
			case rank::K		: su[11]++; break;
			case rank::A		: su[12]++; break;
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
			case rank::_2		: su[0]++; break;
			case rank::_3		: su[1]++; break;
			case rank::_4		: su[2]++; break;
			case rank::_5		: su[3]++; break;
			case rank::_6		: su[4]++; break;
			case rank::_7		: su[5]++; break;
			case rank::_8		: su[6]++; break;
			case rank::_9		: su[7]++; break;
			case rank::_10		: su[8]++; break;
			case rank::J		: su[9]++; break;
			case rank::Q		: su[10]++; break;
			case rank::K		: su[11]++; break;
			case rank::A		: su[12]++; break;
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
			case rank::_2		: su[0]++; break;
			case rank::_3		: su[1]++; break;
			case rank::_4		: su[2]++; break;
			case rank::_5		: su[3]++; break;
			case rank::_6		: su[4]++; break;
			case rank::_7		: su[5]++; break;
			case rank::_8		: su[6]++; break;
			case rank::_9		: su[7]++; break;
			case rank::_10		: su[8]++; break;
			case rank::J		: su[9]++; break;
			case rank::Q		: su[10]++; break;
			case rank::K		: su[11]++; break;
			case rank::A		: su[12]++; break;
		}
	int sum = 0;
	for (int t: su)
		sum += t/3;
	return sum;
}

bool isSTRAIGHT(std::vector<Card> vec) {
	if (vec.size() < 5)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[13] = {0};
	for (Card tmp : vec)
		switch (tmp.getRank()) {
			case rank::_2		: su[0]++; break;
			case rank::_3		: su[1]++; break;
			case rank::_4		: su[2]++; break;
			case rank::_5		: su[3]++; break;
			case rank::_6		: su[4]++; break;
			case rank::_7		: su[5]++; break;
			case rank::_8		: su[6]++; break;
			case rank::_9		: su[7]++; break;
			case rank::_10		: su[8]++; break;
			case rank::J		: su[9]++; break;
			case rank::Q		: su[10]++; break;
			case rank::K		: su[11]++; break;
			case rank::A		: su[12]++; break;
		}
	for (int i=0; i < 9; ++i)
		if (su[i] != 0 && su[i+1] != 0 && su[i+2] != 0 && su[i+3] != 0 && su[i+4] != 0)
			return 1;
	if (su[0] != 0 && su[1] != 0 && su[2] != 0 && su[3] != 0 && su[12] != 0)
		return 1;
	return 0;
}

bool isFLUSH(std::vector<Card> vec) {
	if (vec.size() < 5)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[4] = {0};
	for (Card tmp : vec)
		switch (tmp.getSuit()) {
			case suit::SPADES		: su[0]++; break;
			case suit::HEARTS		: su[1]++; break;
			case suit::DIAMONDS		: su[2]++; break;
			case suit::CLUBS		: su[3]++; break;
		}
	return su[0]/5 + su[1]/5 + su[2]/5 + su[3]/5;
}

bool isFULL_HOUSE(std::vector<Card> vec) {
	if (vec.size() < 5)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[13] = {0};
	for (Card tmp : vec)
		switch (tmp.getRank()) {
			case rank::_2		: su[0]++; break;
			case rank::_3		: su[1]++; break;
			case rank::_4		: su[2]++; break;
			case rank::_5		: su[3]++; break;
			case rank::_6		: su[4]++; break;
			case rank::_7		: su[5]++; break;
			case rank::_8		: su[6]++; break;
			case rank::_9		: su[7]++; break;
			case rank::_10		: su[8]++; break;
			case rank::J		: su[9]++; break;
			case rank::Q		: su[10]++; break;
			case rank::K		: su[11]++; break;
			case rank::A		: su[12]++; break;
		}
	int p = 0, t = 0;
	for (int i=0; i < 13; i++) {
		if (su[i] >= 3) {
			t = i;
			break;
		}
	}
	for (int i=0; i < 13; i++) {
		if (su[i] >= 2 && i != t)
			p = i;
	}
	return p*t;
}

bool isFOUR_OF_A_KIND(std::vector<Card> vec) {
	if (vec.size() < 4)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[13] = {0};
	for (Card tmp : vec)
		switch (tmp.getRank()) {
			case rank::_2		: su[0]++; break;
			case rank::_3		: su[1]++; break;
			case rank::_4		: su[2]++; break;
			case rank::_5		: su[3]++; break;
			case rank::_6		: su[4]++; break;
			case rank::_7		: su[5]++; break;
			case rank::_8		: su[6]++; break;
			case rank::_9		: su[7]++; break;
			case rank::_10		: su[8]++; break;
			case rank::J		: su[9]++; break;
			case rank::Q		: su[10]++; break;
			case rank::K		: su[11]++; break;
			case rank::A		: su[12]++; break;
		}
	int sum = 0;
	for (int t: su)
		sum += t/4;
	return sum;
}

bool isSTRAIGHT_FLUSH(std::vector<Card> vec) {
	if (vec.size() < 5)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[4] = {0};
	suit s;
	for (Card tmp : vec)
		switch (tmp.getSuit()) {
			case suit::SPADES		: su[0]++; break;
			case suit::HEARTS		: su[1]++; break;
			case suit::DIAMONDS		: su[2]++; break;
			case suit::CLUBS		: su[3]++; break;
		}
	if ((int)su[0] >= 5) {
		s = suit::SPADES;
		goto counting_rk;
	}
	if ((int)su[1] >= 5) {
		s = suit::HEARTS;
		goto counting_rk;
	}
	if ((int)su[2] >= 5) {
		s = suit::DIAMONDS;
		goto counting_rk;
	}
	if ((int)su[3] >= 5) {
		s = suit::CLUBS;
		goto counting_rk;
	}
	return 0;
counting_rk:
	int rk[13] = {0};
	for (Card tmp : vec)
		if (tmp.getSuit() == s)
			switch (tmp.getRank()) {
				case rank::_2		: rk[0]++; break;
				case rank::_3		: rk[1]++; break;
				case rank::_4		: rk[2]++; break;
				case rank::_5		: rk[3]++; break;
				case rank::_6		: rk[4]++; break;
				case rank::_7		: rk[5]++; break;
				case rank::_8		: rk[6]++; break;
				case rank::_9		: rk[7]++; break;
				case rank::_10		: rk[8]++; break;
				case rank::J		: rk[9]++; break;
				case rank::Q		: rk[10]++; break;
				case rank::K		: rk[11]++; break;
				case rank::A		: rk[12]++; break;
			}
	for (int i=0; i < 9; ++i)
		if (rk[i] != 0 && rk[i+1] != 0 && rk[i+2] != 0 && rk[i+3] != 0 && rk[i+4] != 0)
			return 1;
	if (rk[0] != 0 && rk[1] != 0 && rk[2] != 0 && rk[3] != 0 && rk[12] != 0)
		return 1;
	return 0;
}


bool isROYAL_FLUSH(std::vector<Card> vec) {
	if (vec.size() < 5)															// add check NO MORE THAN 7 CARDS
		return 0;
	int su[4] = {0};
	suit s;
	for (Card tmp : vec)
		switch (tmp.getSuit()) {
			case suit::SPADES		: su[0]++; break;
			case suit::HEARTS		: su[1]++; break;
			case suit::DIAMONDS		: su[2]++; break;
			case suit::CLUBS		: su[3]++; break;
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
	if (isSTRAIGHT_FLUSH(vec)) return combination::STRAIGHT_FLUSH;
	if (isFOUR_OF_A_KIND(vec)) return combination::FOUR_OF_A_KIND;
	if (isFULL_HOUSE(vec)) return combination::FULL_HOUSE;
	if (isFLUSH(vec)) return combination::FLUSH;
	if (isSTRAIGHT(vec)) return combination::STRAIGHT;
	if (isTHREE_OF_A_KIND(vec)) return combination::THREE_OF_A_KIND;
	if (isTWO_PAIR(vec)) return combination::TWO_PAIR;
	if (isONE_PAIR(vec)) return combination::ONE_PAIR;
	return combination::HIGH_CARD;
}



#endif // COMBINATIONS_HPP_INCLUDED
