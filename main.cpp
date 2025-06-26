//import std;
#include <iostream>
#include "card.hpp"
#include "game.hpp"
#include "combinations.hpp"

int main () {
	suit s = suit::CLUBS;
	rank r = rank::Q;
	Card ca(s, r);
	std::pair<suit, rank> mypair = ca.getVal();
	std::cout << (int)mypair.first << " " << (int)mypair.second << "\n";
	availCards avai;
	std::cout << avai.numUnknCards() << "\n";
	avai.erase(ca);
	std::cout << avai.numUnknCards() << "\n";
}
