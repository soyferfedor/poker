#ifndef CARD_HPP_INCLUDED
#define CARD_HPP_INCLUDED

#include <utility>

constexpr unsigned int numCards = 52;
constexpr unsigned int suitVar = 4;
constexpr unsigned int rankVar = 13;

enum class suit {
        SPADES,
	HEARTS,
	DIAMONDS,
	CLUBS
};

enum class rank {
        A,
	_2,
	_3,
	_4,
	_5,
	_6,
	_7,
	_8,
	_9,
	_10,
	J,
	Q,
	K
};

class Card {
	std::pair<suit, rank> val;
public:
	Card(suit s, rank r): val(s, r)  {}
	Card(std::pair<suit, rank> input): val(input.first, input.second) {}
	Card() {}
	void setVal(suit s, rank r) {val=std::make_pair(s, r);}
	void setVal(std::pair<suit, rank> input) {val=input;}
	std::pair<suit, rank> getVal() const {return val;} 
	suit getSuit() const {return std::get<0>(val);}
	rank getRank() const {return std::get<1>(val);}
	~Card() {}
};

class myCards {
	Card card[2];
public:
	myCards(suit s1, rank r1, suit s2, rank r2) {card[0].setVal(s1, r1); card[1].setVal(s2, r2);}
	myCards() {}
	void setCards(suit s1, rank r1, suit s2, rank r2) {	card[0].setVal(std::make_pair(s1, r1));
														card[1].setVal(std::make_pair(s2, r2));}
	void setCards(std::pair<suit, rank> in1, std::pair<suit, rank> in2) {	card[0].setVal(in1);
																			card[1].setVal(in2);}
	void setCards(std::tuple<suit, rank, suit, rank> inTup) {	card[0].setVal(std::make_pair(std::get<0>(inTup), std::get<1>(inTup)));
																card[1].setVal(std::make_pair(std::get<2>(inTup), std::get<3>(inTup)));}
	void set1stCard(suit s, rank r) {card[0].setVal(std::make_pair(s, r));}
	void set1stCard(std::pair<suit, rank> input) {card[0].setVal(input);}
	void set2ndCard(suit s, rank r) {card[1].setVal(std::make_pair(s, r));}
	void set2ndCard(std::pair<suit, rank> input) {card[1].setVal(input);}
	std::tuple<suit, rank, suit, rank> getVal() const {return std::tuple<suit, rank, suit, rank>
																(card[0].getSuit(), card[0].getRank(), card[1].getSuit(), card[1].getRank());}
	std::pair<suit, rank> get1stCard() const {return card[0].getVal();}
	std::pair<suit, rank> get2ndCard() const {return card[1].getVal();}
	suit getSuit1() const {return card[0].getSuit();}
	suit getSuit2() const {return card[1].getSuit();}
	rank getRank1() const {return card[0].getRank();}
	rank getRank2() const {return card[1].getRank();}
	~myCards() {}
};





#endif // CARD_HPP_INCLUDED
