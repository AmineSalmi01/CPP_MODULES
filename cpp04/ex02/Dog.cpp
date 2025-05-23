#include "Dog.hpp"

Dog::Dog() : Animal() {
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Default constructor for Dog is called" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy) {
	this->brain = new Brain();
	for (int i = 0; i < 100; i++) {
		this->brain->setIdea(i, copy.brain->getIdea(i));
	}
	std::cout << "Copy constructor for Dog is called" << std::endl;
}

Dog &Dog::operator=(const Dog& src) {
	Animal::operator=(src);
	std::cout << "Assignment operator for Dog is called " << std::endl;
	return (*this);
}

void Dog::makeSound( void ) const {
	std::cout << "Dog: Wooooof!!" << std::endl;
}

void Dog::setIdea(int index, const std::string idea) {
	if (index < 100 && index >= 0)
		this->brain->setIdea(index, idea);
}

std::string Dog::getIdea(int index) {
	if (index < 0 || index > 100)
	{
		std::cout << "No Idea ...." << std::endl;
		return (NULL);
	}
	return (this->brain->getIdea(index));
}

Dog::~Dog() {
	delete this->brain;
	std::cout << "Destructor for Dog is called" << std::endl;
}
