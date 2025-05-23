#include "Fixed.hpp"

const int Fixed::scale = 8;

Fixed::Fixed() {
	this->value = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	this->value = other.value;
	std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
	if (this != &other)
		this->value = other.getRawBits();
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return (value);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->value = raw;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}