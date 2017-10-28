#include "IncendioFlorestal.h"

IncendioFlorestal::IncendioFlorestal(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numBombeirosNecess, unsigned int numAutotanquesNecess, unsigned int areaChamas)
	: Incendio(data,local,numOcorrencia,numBombeirosNecess,numAutotanquesNecess) , areaChamas(areaChamas) {}


IncendioFlorestal::~IncendioFlorestal() {
	// TODO Auto-generated destructor stub
}

const unsigned int IncendioFlorestal::getAreaChamas() const{
	return areaChamas;
}

std::string IncendioFlorestal::getTipoAcidente() const{
	return "Incendio Florestal";
}

void IncendioFlorestal::printInfoAcidente() const {
	std::cout << "***  INCENDIO FLORESTAL  ***" << std::endl;
	std::cout << "Local: " << local->getNome() << std::endl;
	std::cout << "Data: " << data.getData() << std::endl;
	std::cout << "Numero da Ocorrencia: " << numOcorrencia << std::endl;
	std::cout << "Numero de Bombeiros necessarios: " << getNumBombeirosNecess() << std::endl;
	std::cout << "Numero de Autotanques necessarios: " << getNumAutotanquesNecess() << std::endl;
	std::cout << "Área das Chamas: " << areaChamas << std::endl;
}

void IncendioFlorestal::printSimplifiedInfo(std::ostream & os) const{
	// Imprimir os dados do incendio propriamente dito
	os << local->getNome() << '/' << data.getData() << "/Incendio/" << numAutotanquesNecess << '/' << numBombeirosNecess << "/Florestal/" << areaChamas << '/' << atribuicoes.size();

	// Imprimir info sob atribuições relativas a esta ocorrência
	for (unsigned int i=0 ; i<atribuicoes.size() ; i++){
		// Mudar de linha, fazer um tab para indexar e imprimir informação da atribuição
		os << "\n\t" << atribuicoes.at(i);
	}
}
