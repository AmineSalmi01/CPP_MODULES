#include "Fixed.hpp"

const int Fixed::scaleBits = 8;

Fixed::Fixed()
{
	this->value = 0;
	// std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n)
{
	// std::cout << "int constructor called" << std::endl;
	this->value = n << scaleBits;
}

Fixed::Fixed(const float n)
{
	// std::cout << "float constructor called" << std::endl;
	this->value = roundf(n * (1 << this->scaleBits));
}

Fixed::Fixed(const Fixed &other)
{
	this->value = other.value;
	// std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this != &other)
		this->value = other.getRawBits();
	// std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

int Fixed::getRawBits( void ) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->value);
}

void Fixed::setRawBits(int const value)
{
	this->value = value;
}

int Fixed::toInt(void) const
{
	return (this->value >> this->scaleBits);
}

float Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->scaleBits));
}


std::ostream &operator<<(std::ostream &out, Fixed const &object)
{
	out << object.toFloat();
	return (out);
}

Fixed Fixed::operator+(Fixed const &obj)
{
	Fixed res;
	res.value = this->value + obj.value;
	return (res);
}

Fixed Fixed::operator-(Fixed const &obj)
{
	Fixed res;
	res.value = this->value - obj.value;
	return (res);
}

Fixed Fixed::operator*(Fixed const &obj)
{
	Fixed res;
	res.value = (this->value * obj.value) >> this->scaleBits;
	return (res);
}

Fixed Fixed::operator/(Fixed const &obj)
{
	Fixed res;
	res.value = (this->value << this->scaleBits) / obj.value;
	return (res);
}

bool Fixed::operator>(Fixed const &obj)
{
	if (this->value > obj.value)
		return (true);
	return (false);
}

bool Fixed::operator>=(Fixed const &obj)
{
	if (this->value >= obj.value)
		return (true);
	return (false);
}

bool Fixed::operator<(Fixed const &obj)
{
	if (this->value < obj.value)
		return (true);
	return (false);

}

bool Fixed::operator<=(Fixed const &obj)
{
	if (this->value <= obj.value)
		return (true);
	return (false);
}

bool Fixed::operator==(Fixed const &obj)
{
	if (this->value == obj.value)
		return (true);
	return (false);
}

bool Fixed::operator!=(Fixed const &obj)
{
	if (this->value != obj.value)
		return (true);
	return (false);
}

Fixed Fixed::operator++(int)
{
	Fixed tmp(*this);
	++this->value;
	return (tmp);
}

Fixed Fixed::operator--(int)
{
	Fixed tmp(*this);
	--this->value;
	return (tmp);
}

Fixed Fixed::operator++()
{
	++this->value;
	return (*this);
}

Fixed Fixed::operator--()
{
	--this->value;
	return (*this);
}

Fixed &Fixed::min(Fixed &first, Fixed &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed const &Fixed::min(Fixed const &first, Fixed const &second)
{
	if (first.toFloat() <= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed &Fixed::max(Fixed &first, Fixed &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed const &Fixed::max(Fixed const &first, Fixed const &second)
{
	if (first.toFloat() >= second.toFloat())
		return (first);
	else
		return (second);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}