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
