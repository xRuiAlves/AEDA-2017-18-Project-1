#include "ProtecaoCivil.h"

ProtecaoCivil::ProtecaoCivil(const std::string &ficheiroPostos, const std::string &ficheiroAcidentes, const std::string &ficheiroLocais)
	: ficheiroPostos(ficheiroPostos) , ficheiroAcidentes(ficheiroAcidentes) , ficheiroLocais(ficheiroLocais) {}

void ProtecaoCivil::openFiles(){
	std::ifstream istr;

	// Ler ficheiro de locais
	istr.open(ficheiroLocais);

	if(!istr.is_open())	// ficheiro nao foi aberto com sucesso
		throw Erro("Falha ao abrir o ficheiro \"" + ficheiroLocais + "\" no construtor de ProtecaoCivil.");

	// Preencher o vetor de locais com o conteudo do ficheiro
	std::string line, nomeLocal;
	unsigned int x_coord, y_coord;
	int dashIndex;
	while(getline(istr,line)){
		// obter nome do local
		dashIndex = line.find_first_of('/');
		nomeLocal = line.substr(0,dashIndex);
		line.erase(0,dashIndex+1);

		// obter a coordenada X do local
		dashIndex = line.find_first_of('/');
		x_coord = std::stoi(line.substr(0,dashIndex));
		line.erase(0,dashIndex+1);

		// obter a coordenada Ỹ do local
		dashIndex = line.find_first_of('/');
		y_coord = std::stoi(line.substr(0,dashIndex));

		// acrestar este local ao vetor de locais
		locais.push_back(Local(nomeLocal,x_coord,y_coord));
	}
	istr.close();	// Fechar a stream

	// Ler ficheiro de postos
	istr.open(ficheiroPostos);

	if(!istr.is_open())	// ficheiro nao foi aberto com sucesso
		throw Erro("Falha ao abrir o ficheiro \"" + ficheiroPostos + "\" no construtor de ProtecaoCivil.");

	// Preencher o vetor de postos com o conteudo do ficheiro
	std::string tipoPosto, tipoVeiculo;
	unsigned int numSocorristas, numVeiculos, numAutotanques, numAmbulancias, indexLocal;
	while(getline(istr,line)){
		// obter nome do local
		dashIndex = line.find_first_of('/');
		nomeLocal = line.substr(0,dashIndex);
		line.erase(0,dashIndex+1);

		// obter indice do local no vetor
		indexLocal = findLocal(nomeLocal);
		if(indexLocal == -1){		// Este local nao foi encontrado no vetor de locais da protecao civil
			throw Erro("O local \"" + nomeLocal + "\" nao foi encontrado no vetor de locais da Protecao Civil, no construtor de ProtecaoCivil.");
		}

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

			postos.push_back(new Policia(&locais.at(indexLocal),numSocorristas,numVeiculos,tipoVeiculo));
		}
		else if(tipoPosto == "Inem"){
			// obter tipo de veiculo
			dashIndex = line.find_first_of('/');
			tipoVeiculo = line.substr(0,dashIndex);

			postos.push_back(new Inem(&locais.at(indexLocal),numSocorristas,numVeiculos,tipoVeiculo));
		}
		else {		// tipoPosto = Bombeiros
			// obter num. de autotanques
			dashIndex = line.find_first_of('/');
			numAutotanques = std::stoi(line.substr(0,dashIndex));
			line.erase(0,dashIndex+1);

			// obter num. de ambulancias
			dashIndex = line.find_first_of('/');
			numAmbulancias = std::stoi(line.substr(0,dashIndex));

			postos.push_back(new Bombeiros(&locais.at(indexLocal),numSocorristas,numAutotanques,numAmbulancias));
		}
	}
	istr.close();

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

unsigned int ProtecaoCivil::findLocal(const std::string &nomeLocal) const{
	for(unsigned int i=0 ; i<locais.size() ; i++){
		if(locais.at(i).getNome() == nomeLocal){
			return i;
		}
	}

	return -1;	// local nao foi encontrado
}

