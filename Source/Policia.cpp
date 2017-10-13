#include "Policia.h"

Policia::Policia(const std::string &local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo)
	: Posto(local,numSocorristas,numVeiculos) , tipoVeiculo(tipoVeiculo) {}


Policia::~Policia() {
	// TODO Auto-generated destructor stub
}

const std::string Policia::getTipoVeiculo() const{
	return tipoVeiculo;
}

void Policia::printSimplifiedInfo(std::ostream &os) const{
	os << local << "/" << numSocorristas << "/" << numVeiculos << "/Policia/" << tipoVeiculo;
}

