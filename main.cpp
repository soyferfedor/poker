//import std;
#include <iostream>
#include "card.hpp"
#include "game.hpp"
#include "combinations.hpp"

int main () {
	/*suit s = suit::CLUBS;
	rank r = rank::Q;
	Card ca(s, r);
	std::pair<suit, rank> mypair = ca.getVal();
	std::cout << (int)mypair.first << " " << (int)mypair.second << "\n";
	availCards avai;
	std::cout << avai.numUnknCards() << "\n";
	avai.erase(ca);
	std::cout << avai.numUnknCards() << "\n";
*/
	std::vector<Card> vec;
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_7));
	vec.push_back(std::make_pair(suit::CLUBS, rank::_9));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_9));
	combination com = findPowerComb(vec);
	std::cout << (int)combination::ONE_PAIR << '\n';
	std::cout << (int)com << '\n';
}
