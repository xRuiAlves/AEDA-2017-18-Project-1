#include "IncendioFlorestal.h"

IncendioFlorestal::IncendioFlorestal(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numCarrosNecess, unsigned int numAutotanquesNecess, unsigned int areaChamas)
	: Incendio(data,local,numOcorrencia,numCarrosNecess,numAutotanquesNecess) , areaChamas(areaChamas) {}


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
	std::cout << "Área das Chamas: " << areaChamas << std::endl;
}
