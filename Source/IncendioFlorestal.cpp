#include "IncendioFlorestal.h"

IncendioFlorestal::IncendioFlorestal(const std::string &data, const std::string &local, unsigned int numOcorrencia, unsigned int numCarrosNecess, unsigned int numAutotanquesNecess, unsigned int areaChamas)
	: Incendio(data,local,numOcorrencia,numCarrosNecess,numAutotanquesNecess) , areaChamas(areaChamas) {}


IncendioFlorestal::~IncendioFlorestal() {
	// TODO Auto-generated destructor stub
}

