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
	std::cout << "Numero de Bombeiros necessarios: " << numBombeirosNecess << std::endl;
	std::cout << "Numero de Autotanques necessarios: " << numAutotanquesNecess << std::endl;
	std::cout << "Tipo de Casa: " << tipoCasa << std::endl;
}

void IncendioDomestico::printSimplifiedInfo(std::ostream & os) const{
	// Imprimir os dados do incendio propriamente dito
	os << local->getNome() << '/' << data.getData() << "/Incendio/" << numAutotanquesNecess << '/' << numBombeirosNecess << "/Domestico/" << tipoCasa << '/' << atribuicoes.size();

	// Imprimir info sob atribuições relativas a esta ocorrência
	for (unsigned int i=0 ; i<atribuicoes.size() ; i++){
		// Mudar de linha, fazer um tab para indexar e imprimir informação da atribuição
		os << "\n\t" << atribuicoes.at(i);
	}
}
