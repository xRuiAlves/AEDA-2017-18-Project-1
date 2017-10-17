#include "IncendioDomestico.h"

IncendioDomestico::IncendioDomestico(const std::string &data, const Local* local, unsigned int numOcorrencia, unsigned int numBombeirosNecess, unsigned int numAutotanquesNecess, const std::string &tipoCasa)
	: Incendio(data,local,numOcorrencia,numBombeirosNecess,numAutotanquesNecess) , tipoCasa(tipoCasa) {}


IncendioDomestico::~IncendioDomestico() {
	// TODO Auto-generated destructor stub
}

const std::string IncendioDomestico::getTipoCasa() const{
	return tipoCasa;
}

std::string IncendioDomestico::getTipoAcidente() const{
	return "Incendio Domestico";
}

void IncendioDomestico::printInfoAcidente() const {
	std::cout << "***  INCENDIO DOMÉSTICO ***" << std::endl;
	std::cout << "Local: " << local->getNome() << std::endl;
	std::cout << "Data: " << data.getData() << std::endl;
	std::cout << "Numero da Ocorrencia: " << numOcorrencia << std::endl;
	std::cout << "Numero de Bombeiros necessarios: " << getNumBombeirosNecess() << std::endl;
	std::cout << "Numero de Autotanques necessarios: " << getNumAutotanquesNecess() << std::endl;
	std::cout << "Tipo de Casa: " << tipoCasa << std::endl;
}
