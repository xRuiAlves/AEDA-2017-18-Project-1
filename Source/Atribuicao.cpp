#include "Atribuicao.h"

Atribuicao::Atribuicao(const Posto* posto, const unsigned int numSocorristas, const unsigned int numVeiculos, const std::string &tipoVeiculos)
	: posto(posto) , numSocorristas(numSocorristas) , numVeiculos(numVeiculos) , tipoVeiculos(tipoVeiculos) {}

Atribuicao::~Atribuicao(){}

const Posto* Atribuicao::getPosto() const{
	return posto;
}
const unsigned int Atribuicao::getNumSocorristas() const{
	return numSocorristas;
}
const unsigned int Atribuicao::getNumVeiculos() const{
	return numVeiculos;
}
const std::string Atribuicao::getTipoVeiculos() const{
	return tipoVeiculos;
}

