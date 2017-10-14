#include "Policia.h"

Policia::Policia(const Local* local, unsigned int numSocorristas, unsigned int numVeiculos, const std::string &tipoVeiculo)
	: Posto(local,numSocorristas,numVeiculos) , tipoVeiculo(tipoVeiculo) {}


Policia::~Policia() {
	// TODO Auto-generated destructor stub
}

const std::string Policia::getTipoVeiculo() const{
	return tipoVeiculo;
}

std::string Policia::getTipoPosto() const{
	return "Policia";
}

void Policia::printInfoPosto() const{
	std::cout << "***  POLICIA  ***" << std::endl;
	std::cout << "Localidade: " << local->getNome() << std::endl;
	std::cout << "Numero de Socorristas: " << numSocorristas << std::endl;
	std::cout << "Numero de Veiculos: " << numVeiculos << std::endl;
	std::cout << "Tipo de Veiculo usado: " << tipoVeiculo << std::endl;
}
