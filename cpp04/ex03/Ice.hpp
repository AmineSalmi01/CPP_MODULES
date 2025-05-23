#pragma once

#include "AMateria.hpp"

class Ice : public AMateria {
public:
	Ice();
	Ice(std::string const &type);
	Ice(const Ice &copy);
	~Ice();

	Ice &operator=(const Ice &src);
    AMateria* clone() const;
    void use(ICharacter& target);
};