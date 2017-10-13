#include "Local.h"

Local::Local(const std::string nome, unsigned int x_coord, unsigned int y_coord)
	: nome(nome) , x_coord(x_coord) , y_coord(y_coord) {}


Local::~Local() {}

const std::string Local::getNome() const{
	return nome;
}

const unsigned int Local::getXcoord() const{
	return x_coord;
}

const unsigned int Local::getYcoord() const{
	return y_coord;
}
