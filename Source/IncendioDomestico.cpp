#include "IncendioDomestico.h"

IncendioDomestico::IncendioDomestico(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numCarrosNecess, unsigned int numAutotanquesNecess, const std::string &tipoCasa)
	: Incendio(data,local,numOcorrencia,numCarrosNecess,numAutotanquesNecess) , tipoCasa(tipoCasa) {}


IncendioDomestico::~IncendioDomestico() {
	// TODO Auto-generated destructor stub
}

