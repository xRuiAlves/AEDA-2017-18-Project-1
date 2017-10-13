#include "ProtecaoCivil.h"

ProtecaoCivil::ProtecaoCivil(const std::string &ficheiroPostos, const std::string &ficheiroAcidentes, const std::string &ficheiroLocais)
	: ficheiroPostos(ficheiroPostos) , ficheiroAcidentes(ficheiroAcidentes) , ficheiroLocais(ficheiroLocais) {}

void ProtecaoCivil::openFiles(){
	std::ifstream istr;

	///////////////////////////////
	// TODO: Ler Ficheiro Locais //
	///////////////////////////////

	// Ler ficheiro de postos
	istr.open(ficheiroPostos);

	if(!istr.is_open())	// ficheiro nao foi aberto com sucesso
		throw Erro("Falha ao abrir o ficheiro \"" + ficheiroPostos + "\" no construtor de ProtecaoCivil.");

	// Preencher o vetor de postos com o conteudo do ficheiro
	std::string line, local, tipoPosto, tipoVeiculo;
	unsigned int numSocorristas, numVeiculos, numAutotanques, numAmbulancias;
	int dashIndex;
	while(getline(istr,line)){
		// obter local
		dashIndex = line.find_first_of('/');
		local = line.substr(0,dashIndex);
		line.erase(0,dashIndex+1);

		// obter num. de socorristas
		dashIndex = line.find_first_of('/');
		numSocorristas = std::stoi(line.substr(0,dashIndex));
		line.erase(0,dashIndex+1);

		// obter num. de veiculos
		dashIndex = line.find_first_of('/');
		numVeiculos = std::stoi(line.substr(0,dashIndex));
		line.erase(0,dashIndex+1);

		// obter tipo de posto
		dashIndex = line.find_first_of('/');
		tipoPosto = line.substr(0,dashIndex);
		line.erase(0,dashIndex+1);

		if(tipoPosto == "Policia"){
			// obter tipo de veiculo
			dashIndex = line.find_first_of('/');
			tipoVeiculo = line.substr(0,dashIndex);

			postos.push_back(new Policia(local,numSocorristas,numVeiculos,tipoVeiculo));
		}
		else if(tipoPosto == "Inem"){
			// obter tipo de veiculo
			dashIndex = line.find_first_of('/');
			tipoVeiculo = line.substr(0,dashIndex);

			postos.push_back(new Inem(local,numSocorristas,numVeiculos,tipoVeiculo));
		}
		else {		// tipoPosto = Bombeiros
			// obter num. de autotanques
			dashIndex = line.find_first_of('/');
			numAutotanques = std::stoi(line.substr(0,dashIndex));
			line.erase(0,dashIndex+1);

			// obter num. de ambulancias
			dashIndex = line.find_first_of('/');
			numAmbulancias = std::stoi(line.substr(0,dashIndex));

			postos.push_back(new Bombeiros(local,numSocorristas,numAutotanques,numAmbulancias));
		}
	}

	//////////////////////////////////
	// TODO: Ler Ficheiro Acidentes //
	//////////////////////////////////
}

ProtecaoCivil::~ProtecaoCivil() {
	// delete allocated memory for postos
	for (unsigned int i=0 ; i<postos.size() ; i++){
		delete postos.at(i);
	}

	// delete allocated memory for acidentes
	for (unsigned int i=0 ; i<acidentes.size() ; i++){
		delete acidentes.at(i);
	}

	// gravar ocorrencias
	// TODO Call gravar()
}

