#include "Atribuicao.h"

Atribuicao::Atribuicao(const Posto* posto, const unsigned int numSocorristas, const unsigned int numVeiculos, const std::string &tipoVeiculos)
	: posto(posto) , numSocorristas(numSocorristas) , numVeiculos(numVeiculos) , tipoVeiculos(tipoVeiculos) {}

const unsigned int getPosto() const{
	return posto;
}
const unsigned int getNumSocorristas() const{
	return numSocorristas;
}
const unsigned int getNumVeiculos() const{
	return numVeiculos;
}
const std::string getTipoVeiculos() const{
	return tipoVeiculos;
}

