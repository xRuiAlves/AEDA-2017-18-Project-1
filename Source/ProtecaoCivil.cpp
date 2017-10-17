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

void ProtecaoCivil::ordernarPostos(bool compareFunction(Posto* p1, Posto*p2)){
	std::sort(postos.begin(),postos.end(),compareFunction);
}

void ProtecaoCivil::printTodosPostos() const{
	for (unsigned int i=0 ; i<postos.size() ; i++){
		postos.at(i)->printInfoPosto();
		std::cout << std::endl;
	}
}

void ProtecaoCivil::printPostosTipo(const std::string &tipo) const{
	// ASSUMINDO VETOR JA ORDENADO POR TIPO DE POSTO

	// Se o vetor de postos estiver vazio, nenhuma das seguintes verificacoes sao necessarias, retornar
	if(postos.size() == 0)
		return;

	// Encontrar o primeiro posto com o tipo desejado
	unsigned int index = 0;
	while(index < postos.size()){
		if(postos.at(index)->getTipoPosto() != tipo)
			index++;
		else 		// encontramos o primeiro posto com carateristicas desejadas! sair do loop
			break;
	}

	// Imprimir todos os postos do tipo desejado
	for (unsigned int i=index ; i<postos.size() ; i++){
		if(postos.at(i)->getTipoPosto() == tipo){	// Enquanto ainda estiver na secção do vetor de postos do tipo desejado
			postos.at(i)->printInfoPosto();
			std::cout << std::endl;
		} else {
			break;	// Os postos seguintes já não são postos do tipo desejado
		}
	}
}

void ProtecaoCivil::printPostosLocal(const std::string &local) const{
	// ASSUMINDO VETOR JA ORDENADO POR LOCAL DO POSTO

	// Se o vetor de locais estiver vazio, nenhuma das seguintes verificacoes sao necessarias, retornar
	if(locais.size() == 0){
		std::cout << "Nao ha quaiquer postos em nenhuma localidade.";
		return;
	}

	// Encontrar o primeiro posto com o local desejado
	unsigned int index = 0;
	while(index < postos.size()){
		if(postos.at(index)->getLocal()->getNome() != local)
			index++;
		else 		// encontramos o primeiro posto com carateristicas desejadas! sair do loop
			break;
	}

	// Contar o número de postos que existem no local desejado
	unsigned int postoCounter = 0;

	// Imprimir todos os postos no local desejado
	for (unsigned int i=index ; i<postos.size() ; i++){
		if(postos.at(i)->getLocal()->getNome() == local){	// Enquanto ainda estiver na secção do vetor de postos do local desejado
			postoCounter++;
			postos.at(i)->printInfoPosto();
			std::cout << std::endl;
		} else {
			break;	// Os postos seguintes já não são postos do local desejado
		}
	}

	// Caso não haja postos na localidade desejada, dar throw a um erro com essa especificacao
	if (postoCounter == 0){
		std::cout << "Nao ha quaisquer postos na localidade introduzida.";
		return;
	}
}

unsigned int ProtecaoCivil::findAcidenteMaiorNum() const{
	unsigned int maiorNum = 0;
	for (unsigned int i=0 ; i<acidentes.size() ; i++){
		if (acidentes.at(i)->getNumOcorrencia() > maiorNum)
			maiorNum = acidentes.at(i)->getNumOcorrencia();
	}

	return maiorNum;
}

void ProtecaoCivil::ordernarAcidentes(bool compareFunction(Acidente* p1, Acidente*p2)){
	std::sort(acidentes.begin(),acidentes.end(),compareFunction);
}
