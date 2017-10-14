#include "Inem.h"

Inem::Inem(const Local* local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo)
	: Posto(local,numSocorristas,numVeiculos) , tipoVeiculo(tipoVeiculo) {}


Inem::~Inem() {
	// TODO Auto-generated destructor stub
}

const std::string Inem::getTipoVeiculo() const{
	return tipoVeiculo;
}

std::string Inem::getTipoPosto() const{
	return "Inem";
}
