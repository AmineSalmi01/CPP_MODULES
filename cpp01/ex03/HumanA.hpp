#pragma once

#include "Weapon.hpp"

class HumanA {
private:
	std::string name;
	Weapon &weapon;

public:
	void attack( void );
	HumanA(std::string name, Weapon &_weapon);
	~HumanA();
};