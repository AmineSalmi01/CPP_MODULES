#pragma once

#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap {
private:
    std::string name;
public:
    DiamondTrap();
    DiamondTrap(const std::string &name);
    DiamondTrap(const DiamondTrap &copy);
    ~DiamondTrap();

    DiamondTrap &operator=(const DiamondTrap &src);

	void attack(const std::string& target);
    void whoAmI();
};