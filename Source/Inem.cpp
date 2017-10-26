#include "Inem.h"

Inem::Inem(const unsigned int id, const Local* local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo)
	: Posto(id,local,numSocorristas,numVeiculos) , tipoVeiculo(tipoVeiculo) {}


Inem::~Inem() {
	// TODO Auto-generated destructor stub
}

const std::string Inem::getTipoVeiculo() const{
	return tipoVeiculo;
}

std::string Inem::getTipoPosto() const{
	return "Inem";
}

void Inem::printInfoPosto() const{
	std::cout << "***  INEM  ***" << std::endl;
	std::cout << "Localidade: " << local->getNome() << std::endl;
	std::cout << "Numero de Identificacao: " << id << std::endl;
	std::cout << "Numero de Socorristas: " << numSocorristas << std::endl;
	std::cout << "Numero de Veiculos: " << numVeiculos << std::endl;
	std::cout << "Tipo de Veiculo usado: " << tipoVeiculo << std::endl;
}

void Inem::printSimplifiedInfo(std::ostream & os) const{
	os << id << '/' << local->getNome() << '/' << numSocorristas << '/' << numVeiculos << "/Inem/" << tipoVeiculo;
}
