#include "Atribuicao.h"

Atribuicao::Atribuicao(unsigned int postoId, const unsigned int numSocorristas, const unsigned int numVeiculos, const std::string &tipoVeiculos)
	: postoId(postoId) , numSocorristas(numSocorristas) , numVeiculos(numVeiculos) , tipoVeiculos(tipoVeiculos) {}

Atribuicao::~Atribuicao(){}

const unsigned int Atribuicao::getPostoId() const{
	return postoId;
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

std::ostream & operator<<(std::ostream & os, const Atribuicao& atribuicao){
	// Escrever para a stream no formato postoId/numSocorristas/numVeiculos/tipoVeiculos
	os << atribuicao.getPostoId() << '/' << atribuicao.getNumSocorristas() << '/' << atribuicao.getNumVeiculos() << '/' << atribuicao.getTipoVeiculos();


	return os;
}
