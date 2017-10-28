#include "AcidenteViacao.h"

AcidenteViacao::AcidenteViacao(const std::string &data, const Local* local, unsigned int numOcorrencia, const std::string &tipoEstrada, unsigned int numFeridos, unsigned int numVeiculos)
	: Acidente(data,local,numOcorrencia) , tipoEstrada(tipoEstrada) , numFeridos(numFeridos) , numVeiculos(numVeiculos) {}

const std::string AcidenteViacao::getTipoEstrada() const{
	return tipoEstrada;
}
const unsigned int AcidenteViacao::getNumFeridos() const{
	return numFeridos;
}
const unsigned int AcidenteViacao::getNumVeiculos() const {
	return numVeiculos;
}

AcidenteViacao::~AcidenteViacao() {
	// TODO Auto-generated destructor stub
}

std::string AcidenteViacao::getTipoAcidente() const{
	return "Acidente de Viacao";
}

void AcidenteViacao::printInfoAcidente() const {
	std::cout << "***  ACIDENTE DE VIACAO  ***" << std::endl;
	std::cout << "Local: " << local->getNome() << std::endl;
	std::cout << "Data: " << data.getData() << std::endl;
	std::cout << "Numero da Ocorrencia: " << numOcorrencia << std::endl;
	std::cout << "Tipo de Estrada: " << tipoEstrada << std::endl;
	std::cout << "Numero de Feridos: " << numFeridos << std::endl;
	std::cout << "Numero Veiculos: " << numVeiculos << std::endl;
}

void AcidenteViacao::printSimplifiedInfo(std::ostream & os) const{
	// Imprimir os dados do assalto propriamente dito
	os << local->getNome() << '/' << data.getData() << "/Viacao/" << numFeridos << '/' << numVeiculos << '/' << tipoEstrada << '/' << atribuicoes.size();

	// Imprimir info sob atribuições relativas a esta ocorrência
	for (unsigned int i=0 ; i<atribuicoes.size() ; i++){
		// Mudar de linha, fazer um tab para indexar e imprimir informação da atribuição
		os << "\n\t" << atribuicoes.at(i);
	}
}
