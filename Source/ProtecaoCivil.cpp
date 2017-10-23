#include "ProtecaoCivil.h"

ProtecaoCivil::ProtecaoCivil(const std::string &ficheiroPostos, const std::string &ficheiroAcidentes, const std::string &ficheiroLocais)
	: ficheiroPostos(ficheiroPostos) , ficheiroAcidentes(ficheiroAcidentes) , ficheiroLocais(ficheiroLocais) {}

void ProtecaoCivil::openFiles(){
	std::ifstream istr;

	////////////////////////////
	// Ler ficheiro de locais //
	////////////////////////////

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

	////////////////////////////
	// Ler ficheiro de postos //
	////////////////////////////

	istr.open(ficheiroPostos);

	if(!istr.is_open())	// ficheiro nao foi aberto com sucesso
		throw Erro("Falha ao abrir o ficheiro \"" + ficheiroPostos + "\" no construtor de ProtecaoCivil.");

	// Preencher o vetor de postos com o conteudo do ficheiro
	std::string tipoPosto, tipoVeiculo;
	unsigned int numSocorristas, numVeiculos, numAutotanques, numAmbulancias, id;
	int indexLocal;
	while(getline(istr,line)){
		// obter o id do local
		dashIndex = line.find_first_of('/');
		id = std::stoi(line.substr(0,dashIndex));
		line.erase(0,dashIndex+1);

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

			postos.push_back(new Policia(id,&locais.at(indexLocal),numSocorristas,numVeiculos,tipoVeiculo));
		}
		else if(tipoPosto == "Inem"){
			// obter tipo de veiculo
			dashIndex = line.find_first_of('/');
			tipoVeiculo = line.substr(0,dashIndex);

			postos.push_back(new Inem(id,&locais.at(indexLocal),numSocorristas,numVeiculos,tipoVeiculo));
		}
		else {		// tipoPosto = Bombeiros
			// obter num. de autotanques
			dashIndex = line.find_first_of('/');
			numAutotanques = std::stoi(line.substr(0,dashIndex));
			line.erase(0,dashIndex+1);

			// obter num. de ambulancias
			dashIndex = line.find_first_of('/');
			numAmbulancias = std::stoi(line.substr(0,dashIndex));

			postos.push_back(new Bombeiros(id,&locais.at(indexLocal),numSocorristas,numAutotanques,numAmbulancias));
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

int ProtecaoCivil::findLocal(const std::string &nomeLocal) const{
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
		std::cout << "Nao ha quaisquer postos em nenhuma localidade.";
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

	// Caso não haja postos na localidade desejada, informar o utilizador
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

void ProtecaoCivil::printTodosAcidentes() const{
	for (unsigned int i=0 ; i<acidentes.size() ; i++){
		acidentes.at(i)->printInfoAcidente();
		std::cout << std::endl;
	}
}

void ProtecaoCivil::printAcidentesTipo(const std::string &tipo) const{
	// ASSUMINDO VETOR JA ORDENADO POR TIPO DE ACIDENTE

	// Se o vetor de acidentes estiver vazio, nenhuma das seguintes verificacoes sao necessarias, retornar
	if(acidentes.size() == 0)
		return;

	// Encontrar o primeiro acidente com o tipo desejado
	unsigned int index = 0;
	while(index < acidentes.size()){
		if(acidentes.at(index)->getTipoAcidente() != tipo)
			index++;
		else 		// encontramos o primeiro acidente com carateristicas desejadas! sair do loop
			break;
	}

	// Imprimir todos os acidentes do tipo desejado
	for (unsigned int i=index ; i<acidentes.size() ; i++){
		if(acidentes.at(i)->getTipoAcidente() == tipo){	// Enquanto ainda estiver na secção do vetor de acidentes do tipo desejado
			acidentes.at(i)->printInfoAcidente();
			std::cout << std::endl;
		} else {
			break;	// Os acidentes seguintes já não são acidentes do tipo desejado
		}
	}
}

void ProtecaoCivil::printAcidentesLocal(const std::string &local) const{
	// ASSUMINDO VETOR JA ORDENADO POR LOCAL DO ACIDENTE

	// Se o vetor de acidentes estiver vazio, nenhuma das seguintes verificacoes sao necessarias, retornar
	if(acidentes.size() == 0){
		std::cout << "Nao ha quaisquer acidentes em nenhuma localidade.";
		return;
	}

	// Encontrar o primeiro acidente com o local desejado
	unsigned int index = 0;
	while(index < acidentes.size()){
		if(acidentes.at(index)->getLocal()->getNome() != local)
			index++;
		else 		// encontramos o primeiro acidente com carateristicas desejadas! sair do loop
			break;
	}

	// Contar o número de acidentes que existem no local desejado
	unsigned int acidentesCounter = 0;

	// Imprimir todos os acidentes no local desejado
	for (unsigned int i=index ; i<acidentes.size() ; i++){
		if(acidentes.at(i)->getLocal()->getNome() == local){	// Enquanto ainda estiver na secção do vetor de acidentes do local desejado
			acidentesCounter++;
			acidentes.at(i)->printInfoAcidente();
			std::cout << std::endl;
		} else {
			break;	// Os acidentes seguintes já não são acidentes do local desejado
		}
	}

	// Caso não haja acidentes na localidade desejada, informar o utilizador
	if (acidentesCounter == 0){
		std::cout << "Nao ha quaisquer acidentes na localidade introduzida.";
		return;
	}
}

void ProtecaoCivil::printAcidentesData(const std::string &data) const{
	// ASSUMINDO VETOR JA ORDENADO POR DATA DO ACIDENTE

	// Se o vetor de acidentes estiver vazio, nenhuma das seguintes verificacoes sao necessarias, retornar
	if(acidentes.size() == 0){
		std::cout << "Nao ha quaisquer acidentes em nenhuma localidade.";
		return;
	}

	// Encontrar o primeiro acidente com a data desejada
	unsigned int index = 0;
	while(index < acidentes.size()){
		if(acidentes.at(index)->getData().getData() != data)
			index++;
		else 		// encontramos o primeiro acidente com carateristicas desejadas! sair do loop
			break;
	}

	// Contar o número de acidentes que existem com a data desejada
	unsigned int acidentesCounter = 0;

	// Imprimir todos os acidentes com a data desejada
	for (unsigned int i=index ; i<acidentes.size() ; i++){
		if(acidentes.at(i)->getData().getData() == data){	// Enquanto ainda estiver na secção do vetor de acidentes com a data desejada
			acidentesCounter++;
			acidentes.at(i)->printInfoAcidente();
			std::cout << std::endl;
		} else {
			break;	// Os acidentes seguintes já não são acidentes com a data desejada
		}
	}

	// Caso não haja acidentes com a data desejada, informar o utilizador
	if (acidentesCounter == 0){
		std::cout << "Nao ha quaisquer acidentes que tenham ocorrido na data introduzida.";
		return;
	}
}

double ProtecaoCivil::getDistLocais(const std::string &nomeLocal1, const std::string &nomeLocal2){
	int indiceLocal1 = findLocal(nomeLocal1);
	int indiceLocal2 = findLocal(nomeLocal2);

	if(indiceLocal1==-1 || indiceLocal2==-1)	// Um dos locais nao existe no vetor de locais
		return -1;

	// Obter as coordenadas do vetor
	double vecX = locais.at(indiceLocal2).getXcoord() - locais.at(indiceLocal1).getXcoord();
	double vecY = locais.at(indiceLocal2).getYcoord() - locais.at(indiceLocal1).getYcoord();

	// calcular norma do vetor e retornar esse valor
	return sqrt(vecX*vecX + vecY*vecY);
}
