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
	std::cout << avai.numUnknCards() << "\n";*/

	/*std::vector<Card> vec;
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_7));
	vec.push_back(std::make_pair(suit::CLUBS, rank::_9));
	combination com = findPowerComb(vec);
	std::cout << (int)com << '\n';
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_9));
	com = findPowerComb(vec);
	std::cout << (int)com << '\n';
	vec.push_back(std::make_pair(suit::HEARTS, rank::_7));
	com = findPowerComb(vec);
	std::cout << (int)com << '\n';
	vec.push_back(std::make_pair(suit::HEARTS, rank::_9));
	com = findPowerComb(vec);
	std::cout << (int)com << '\n';*/
	
	/*std::vector<Card> vec;
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_9));
	vec.push_back(std::make_pair(suit::CLUBS, rank::_9));
	vec.push_back(std::make_pair(suit::HEARTS, rank::_9));
	combination com = findPowerComb(vec);
	std::cout << (int)com << '\n';
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_8));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_7));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_6));
	vec.push_back(std::make_pair(suit::CLUBS, rank::_10));
	com = findPowerComb(vec);
	std::cout << (int)com << '\n';*/
	
	/*std::vector<Card> vec;
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_9));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_8));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_7));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::A));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_10));
	combination com = findPowerComb(vec);
	std::cout << (int)com << '\n';
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::J));
	com = findPowerComb(vec);
	std::cout << (int)com << '\n';*/
	
	/*std::vector<Card> vec;
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_9));
	vec.push_back(std::make_pair(suit::HEARTS, rank::_9));
	vec.push_back(std::make_pair(suit::CLUBS, rank::_9));
	vec.push_back(std::make_pair(suit::SPADES, rank::_9));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_6));
	combination com = findPowerComb(vec);
	std::cout << (int)com << '\n';*/

	/*std::vector<Card> vec;
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_3));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_2));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::A));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_4));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_5));
	combination com = findPowerComb(vec);
	std::cout << (int)com << '\n';*/
	
	std::vector<Card> vec;
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::_10));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::Q));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::A));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::J));
	vec.push_back(std::make_pair(suit::DIAMONDS, rank::K));
	combination com = findPowerComb(vec);
	std::cout << (int)com << '\n';
		
	return 0;
}
