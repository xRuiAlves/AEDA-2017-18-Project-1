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
		throw FicheiroNaoEncontrado("Falha ao abrir o ficheiro \"" + ficheiroLocais + "\" no construtor de ProtecaoCivil.");

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
		throw FicheiroNaoEncontrado("Falha ao abrir o ficheiro \"" + ficheiroPostos + "\" no construtor de ProtecaoCivil.");

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
			throw LocalidadeInexistente("O local \"" + nomeLocal + "\" nao foi encontrado no vetor de locais da Protecao Civil, no construtor de ProtecaoCivil.");
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
			tipoVeiculo = line;

			postos.push_back(new Policia(id,&locais.at(indexLocal),numSocorristas,numVeiculos,tipoVeiculo));
		}
		else if(tipoPosto == "Inem"){
			// obter tipo de veiculo
			tipoVeiculo = line;

			postos.push_back(new Inem(id,&locais.at(indexLocal),numSocorristas,numVeiculos,tipoVeiculo));
		}
		else {		// tipoPosto = Bombeiros
			// obter num. de autotanques
			dashIndex = line.find_first_of('/');
			numAutotanques = std::stoi(line.substr(0,dashIndex));
			line.erase(0,dashIndex+1);

			// obter num. de ambulancias
			numAmbulancias = std::stoi(line);

			postos.push_back(new Bombeiros(id,&locais.at(indexLocal),numSocorristas,numAutotanques,numAmbulancias));
		}
	}
	istr.close();

	///////////////////////////////
	// Ler Ficheiro de Acidentes //
	///////////////////////////////

	istr.open(ficheiroAcidentes);

	if(!istr.is_open())	// ficheiro nao foi aberto com sucesso
		throw FicheiroNaoEncontrado("Falha ao abrir o ficheiro \"" + ficheiroAcidentes + "\" no construtor de ProtecaoCivil.");

	// Preencher o vetor de Acidentes com o conteúdo do ficheiro
	std::string data, tipoAcidente, tipoIncendio, tipoCasa, tipoEstrada, atribuicao, tipoVeiculos;
	unsigned int numAutotanquesNecess, numBombeirosNecess, areaChamas, numFeridos, numVeiculosEnvolvidos, numAtribuicoes;
	bool haFeridos;
	Acidente* acidente;
	unsigned int numOcorrencia = 1;	// Sera incrementado sempre que um novo acidente for criado

	while(getline(istr,line)){
		// obter nome do local
		dashIndex = line.find_first_of('/');
		nomeLocal = line.substr(0,dashIndex);
		line.erase(0,dashIndex+1);

		// obter indice do local no vetor
		indexLocal = findLocal(nomeLocal);
		if(indexLocal == -1){		// Este local nao foi encontrado no vetor de locais da protecao civil
			throw LocalidadeInexistente("O local \"" + nomeLocal + "\" nao foi encontrado no vetor de locais da Protecao Civil, no construtor de ProtecaoCivil.");
		}

		// obter a data
		dashIndex = line.find_first_of('/');
		data = line.substr(0,dashIndex);
		line.erase(0,dashIndex+1);

		// obter o tipo de acidente
		dashIndex = line.find_first_of('/');
		tipoAcidente = line.substr(0,dashIndex);
		line.erase(0,dashIndex+1);

		// Incendios
		if (tipoAcidente == "Incendio"){
			// obter o numero de autotanques necessarios
			dashIndex = line.find_first_of('/');
			numAutotanquesNecess = std::stoi(line.substr(0,dashIndex));
			line.erase(0,dashIndex+1);

			// obter o numero de bombeiros necessarios
			dashIndex = line.find_first_of('/');
			numBombeirosNecess = std::stoi(line.substr(0,dashIndex));
			line.erase(0,dashIndex+1);

			// obter o tipo de incendio
			dashIndex = line.find_first_of('/');
			tipoIncendio = line.substr(0,dashIndex);
			line.erase(0,dashIndex+1);

			// Incendio Florestal
			if (tipoIncendio == "Florestal"){
				// obter a area de chamas
				dashIndex = line.find_first_of('/');
				areaChamas = std::stoi(line.substr(0,dashIndex));
				line.erase(0,dashIndex+1);

				acidente = new IncendioFlorestal(data,&locais.at(indexLocal),numOcorrencia,numBombeirosNecess,numAutotanquesNecess,areaChamas);
			}
			// Incendio Domestico
			else {
				// obter o tipo de casa
				dashIndex = line.find_first_of('/');
				tipoCasa = line.substr(0,dashIndex);
				line.erase(0,dashIndex+1);

				acidente = new IncendioDomestico(data,&locais.at(indexLocal),numOcorrencia,numBombeirosNecess,numAutotanquesNecess,tipoCasa);
			}
		}

		// Acidentes de Viacao
		else if (tipoAcidente == "Viacao"){
			// obter o numero de feridos
			dashIndex = line.find_first_of('/');
			numFeridos = std::stoi(line.substr(0,dashIndex));
			line.erase(0,dashIndex+1);

			// obter o numero de veiculos envolvidos
			dashIndex = line.find_first_of('/');
			numVeiculosEnvolvidos = std::stoi(line.substr(0,dashIndex));
			line.erase(0,dashIndex+1);

			// obter o tipo de estrada
			dashIndex = line.find_first_of('/');
			tipoEstrada = line.substr(0,dashIndex);
			line.erase(0,dashIndex+1);

			acidente = new AcidenteViacao(data,&locais.at(indexLocal),numOcorrencia,tipoEstrada,numFeridos,numVeiculosEnvolvidos);
		}

		// Assaltos
		else if (tipoAcidente == "Assalto"){
			// obter o tipo de casa
			dashIndex = line.find_first_of('/');
			tipoCasa = line.substr(0,dashIndex);
			line.erase(0,dashIndex+1);

			// obter a existencia de feridos
			dashIndex = line.find_first_of('/');
			haFeridos = ((line.substr(0,dashIndex) == "1") ? true : false);
			line.erase(0,dashIndex+1);

			acidente = new Assalto(data,&locais.at(indexLocal),numOcorrencia,tipoCasa,haFeridos);
		}

		// obter o numero de atribuicoes
		numAtribuicoes = std::stoi(line);

		// colocar as atribuicoes no acidente em questao
		for (unsigned int i=0 ; i<numAtribuicoes ; i++){
			getline(istr, atribuicao);	// obter a atribuicao

			// ler o id do posto a que ao qual atribuicao se refere
			dashIndex = atribuicao.find_first_of('/');
			id = std::stoi(atribuicao.substr(0,dashIndex));
			atribuicao.erase(0,dashIndex+1);

			// ler o numero de socorristas na atribuicao
			dashIndex = atribuicao.find_first_of('/');
			numSocorristas = std::stoi(atribuicao.substr(0,dashIndex));
			atribuicao.erase(0,dashIndex+1);

			// ler o numero de veiculos na atribuicao
			dashIndex = atribuicao.find_first_of('/');
			numVeiculos = std::stoi(atribuicao.substr(0,dashIndex));
			atribuicao.erase(0,dashIndex+1);

			// obter o tipo de veiculos da atribuicao
			tipoVeiculos = atribuicao;

			// adicionar a atribuicao ao acidente
			acidente->addAtribuicao(Atribuicao(id, numSocorristas, numVeiculos, tipoVeiculos));
		}

		// Adicionar o novo acidente à base de dados da Protecao Civil
		acidentes.push_back(acidente);

		numOcorrencia++;
	}

	// Fechar a stream
	istr.close();
}

ProtecaoCivil::~ProtecaoCivil() {
	// gravar ocorrencias
	gravar();

	// apagar memória alocada para postos
	for (unsigned int i=0 ; i<postos.size() ; i++){
		delete postos.at(i);
	}

	// apagar memória alocada para postos
	for (unsigned int i=0 ; i<acidentes.size() ; i++){
		delete acidentes.at(i);
	}
}

void ProtecaoCivil::addAcidente(Acidente* acidente){
	// Ordenar os postos por distancia ao local onde ocorreu este acidente
	ordenarPostosDistLocal(acidente->getLocal()->getNome());

	unsigned short addSuccess;

	// Acidentes de Viacao
	if (acidente->getTipoAcidente() == "Acidente de Viacao"){
		addSuccess = addAcidenteViacao(dynamic_cast<AcidenteViacao*>(acidente));
	}

	// Incendios
	else if ((acidente->getTipoAcidente() == "Incendio Florestal") || (acidente->getTipoAcidente() == "Incendio Domestico")){
		addSuccess =  addIncendio(dynamic_cast<Incendio*>(acidente));
	}

	// Assaltos
	else {
		addSuccess = addAssalto(dynamic_cast<Assalto*>(acidente));
	}

	// Verificar o grau de sucesso da adicao de meios para tratar a ocorrencia
	if (addSuccess == 0){	// Se foram acionados todos os meios para este acidente, ele pertence agora à protecao civil
		acidentes.push_back(acidente);
		return;
	}
	else if (addSuccess == 1){	// Foram acionados alguns meios para este acidente, mas não todos. Adicionar o acidente à proteção civil, mas notificar lançando uma exceção
		acidentes.push_back(acidente);
		throw MeiosInsuficientes("O acidente foi adicionado a' base de dados da Protecao Civil, mas nem todas as necessidades do acidente foram supridas.");
	}
	else{	// Nao foram acionados quaisquer meios para este acidente, pelo que este nao foi adicionado ha base de dados da proteção civil
		throw MeiosInexistentes("Nao ha quaisquer meios capazes de suprir as necessidades deste acidente, pelo que nao foi adicionado a' base de dados da Protecao Civil");
	}
}

unsigned short ProtecaoCivil::addAcidenteViacao(AcidenteViacao* acidenteViacao){
	unsigned int numVeiculosAtribuidos = 0;
	unsigned int numeroFeridos = acidenteViacao->getNumFeridos();

	// Procurar postos (por ordem de proximidade, vetor de postos ja ordernado) do Inem ou dos Bombeiros para suprir as necessidades do acidente
	// Cada ferido necessita de uma equipa de assistencia (ou seja, um veículo, seja ele uma Moto com 1 socorrista, um carro com 2 socorristas ou uma ambulancia com 2 socorristas)
	for (unsigned int i=0 ; i<postos.size() ; i++){

		// Verificar se o posto é um posto do Inem
		if(postos.at(i)->getTipoPosto() == "Inem"){
			// É um posto do Inem
			Inem* postoInem = dynamic_cast<Inem*>(postos.at(i));

			while (postoInem->getNumVeiculos() > 0){
				// Posto de Inem com Motos
				if (postoInem->getTipoVeiculo()=="Moto"){	// Cada moto leva 1 medico
					if (postoInem->rmSocorristas(1)){
						postoInem->rmVeiculos(1);
						numVeiculosAtribuidos += 1;

						// Adicionar a atribuicao
						acidenteViacao->addAtribuicao(Atribuicao(postoInem->getId(),1,1,"Moto"));

						// Verificar se ja foram supridas as necessidades do acidente
						if(numVeiculosAtribuidos == numeroFeridos)
							return 0;	// Todos as necessidades foram supridas!!!
					}
					else{	// Apesar de haver motos, não há medicos suficientes para o seu uso!
						break;
					}
				}

				// Posto do Inem com Carros / Ambulancias
				else{
					if (postoInem->rmSocorristas(2)){	// Cada carro / ambulancia leva 2 medicos
						postoInem->rmVeiculos(1);
						numVeiculosAtribuidos += 1;

						// Adicionar a atribuicao
						acidenteViacao->addAtribuicao(Atribuicao(postoInem->getId(),2,1,postoInem->getTipoVeiculo()));

						// Verificar se ja foram supridas as necessidades do acidente
						if(numVeiculosAtribuidos == numeroFeridos)
						return 0;	// Todos as necessidades foram supridas!!!
					}
					else{	// Apesar de haver carros/ambulancias, não há medicos suficientes para o seu uso!
						break;
					}
				}
			}
		}


		// Verificar se é um posto dos bombeiros
		else if (postos.at(i)->getTipoPosto() == "Bombeiros"){
			// É um posto de bombeiros
			Bombeiros* postoBombeiros = dynamic_cast<Bombeiros*>(postos.at(i));

			while (postoBombeiros->getNumAmbulancias() > 0){
				if(postoBombeiros->rmSocorristas(2)){	// Cada ambulancia leva 2 medicos
					postoBombeiros->rmAmbulancias(1);
					numVeiculosAtribuidos+=1;

					// Adicionar a atribuicao
					acidenteViacao->addAtribuicao(Atribuicao(postoBombeiros->getId(),2,1,"Ambulancia"));

					// Verificar se ja foram supridas as necessidades do acidente
					if(numVeiculosAtribuidos == numeroFeridos)
						return 0;	// Todos as necessidades foram supridas!!!
				}
				else{	// Apesar de haver ambulancias, não há bombeiros suficientes para o seu uso!
					break;
				}
			}
		}

		// É um posto da Policia , na0 é pertinente para o tipo de acidente em questao
		else {
			continue;
		}
	}

	// Todos os postos foram percorridos, mas as necessidades do acidente nao foram totalmente supridas!

	// Verificar se foram parcialmente supridas
	if (numVeiculosAtribuidos != 0)
		return 1;

	// Nao houve uma unica atribuicao com sucesso, nenhumas necessidades foram supridas
	else
		return 2;
}

unsigned short ProtecaoCivil::addIncendio(Incendio* incendio){
	unsigned int numBombeirosAtribuidos = 0;
	unsigned int numAutotanquesAtribuidos = 0;
	unsigned int numBombeirosNecess = incendio->getNumBombeirosNecess();
	unsigned int numAutotanquesNecess= incendio->getNumAutotanquesNecess();

	// Procurar postos (por ordem de proximidade, vetor de postos ja ordernado) de bombeiros para suprir as necessidades do incendio
	// Cada autotanque leva até 4 bombeiros
	for (unsigned int i=0 ; i<postos.size() ; i++){

		// Verificar se o posto é um posto de bombeiros
		if(postos.at(i)->getTipoPosto() != "Bombeiros")
			continue;	// Nao é. Continuar para o proximo posto

		// É um posto de bombeiros
		Bombeiros* postoBombeiros = dynamic_cast<Bombeiros*>(postos.at(i));

		while (postoBombeiros->getNumAutotanques() > 0){
			if(postoBombeiros->rmSocorristas(3)){	// Cada autotanque leva 3 bombeiros
				postoBombeiros->rmAutotanques(1);
				numBombeirosAtribuidos+=3;
				numAutotanquesAtribuidos+=1;

				// Adicionar a atribuicao
				incendio->addAtribuicao(Atribuicao(postoBombeiros->getId(),3,1,"Autotanque"));

				// Verificar se ja foram supridas as necessidades do acidente
				if((numBombeirosAtribuidos == numBombeirosNecess) && (numAutotanquesAtribuidos==numAutotanquesNecess))
					return 0;	// Todos as necessidades foram supridas!!!
			}
			else{	// Apesar de haver autotanques, não há bombeiros suficientes para o seu uso!
				break;
			}
		}
	}

	// Todos os postos foram percorridos, mas as necessidades do acidente nao foram totalmente supridas!

	// Verificar se foram parcialmente supridas
	if ((numBombeirosAtribuidos != 0) && (numAutotanquesAtribuidos != 0))
		return 1;

	// Nao houve uma unica atribuicao com sucesso, nenhumas necessidades foram supridas
	else
		return 2;
}

unsigned short ProtecaoCivil::addAssalto(Assalto* assalto){
	bool haFeridos = assalto->haFeridos();
	bool haApoioMedico = false;	// Se houver feridos, esta variavel indica se foi encontrado apoio médico
	bool haApoioPolicial = false;	// Se for encontrado um posto da policia que forneca apoio policial, esta variavel fica a true

	// Procurar postos (por ordem de proximidade, vetor de postos ja ordernado) da policia para suprir as necessidades do assalto
	// Cada assalto necissita de uma equipa policial ( Seja um carro com 2 Policias ou uma mota com 1 Policia )
	for (unsigned int i=0 ; i<postos.size() ; i++){

		// Verificar se o posto é um posto da policia
		if(postos.at(i)->getTipoPosto() != "Policia")
			continue;	// Nao é. Continuar para o proximo posto

		// É um posto da policia
		Policia* postoPolicia = dynamic_cast<Policia*>(postos.at(i));

		if(postoPolicia->getNumVeiculos()>0){
			// Posto de Motos
			if(postoPolicia->getTipoVeiculo()=="Moto"){
				if(postoPolicia->rmSocorristas(1)){		// Cada moto leva 1 policia
					postoPolicia->rmVeiculos(1);

					// Adicionar a atribuicao
					assalto->addAtribuicao(Atribuicao(postoPolicia->getId(),1,1,"Moto"));

					// Foi encontrado apoio policial!
					haApoioPolicial = true;
					break;
				}
			}
			// Posto de Carros
			else{
				if(postoPolicia->rmSocorristas(2)){		// Cada carro leva 2 policias
					postoPolicia->rmVeiculos(1);

					// Adicionar a atribuicao
					assalto->addAtribuicao(Atribuicao(postoPolicia->getId(),2,1,"Carro"));

					// Foi encontrado apoio policial!
					haApoioPolicial = true;
					break;
				}
			}
		}
	}

	// Se houver feridos, procurar por uma equipa de apoio medico (1 moto com 1 médico, ou um carro/ambulancia com 2 medicos)
	if(haFeridos){
		for(unsigned int i=0 ; i<postos.size() ; i++){
			if(postos.at(i)->getTipoPosto()=="Inem"){
				// É um posto do Inem
				Inem* postoInem = dynamic_cast<Inem*>(postos.at(i));

				if (postoInem->getNumVeiculos() > 0){
					// Posto de Motos
					if(postoInem->getTipoVeiculo() == "Moto"){
						if(postoInem->rmSocorristas(1)){  // uma moto leva 1 medico
							postoInem->rmVeiculos(1);

							// Adicionar a atribuicao
							assalto->addAtribuicao(Atribuicao(postoInem->getId(),1,1,"Moto"));

							// Foi encontrado apoio medico!
							haApoioMedico = true;
							break;
						}
					}

					// Posto de Carros / Ambulancias
					else {
						if(postoInem->rmSocorristas(2)){  // um carro/ambulancia leva 2 medicos
							postoInem->rmVeiculos(1);

							// Adicionar a atribuicao
							assalto->addAtribuicao(Atribuicao(postoInem->getId(),2,1,postoInem->getTipoVeiculo()));

							// Foi encontrado apoio medico!
							haApoioMedico = true;
							break;
						}
					}
				}
			}

			else if(postos.at(i)->getTipoPosto()=="Bombeiros"){
				// É um posto dos Bombeiros
				Bombeiros* postoBombeiros = dynamic_cast<Bombeiros*>(postos.at(i));

				if(postoBombeiros->getNumAmbulancias() > 0){
					if(postoBombeiros->rmSocorristas(2)){	// Cada ambulancia leva 2 bombeiros
						postoBombeiros->rmAmbulancias(1);

						// Adicionar a atribuicao
						assalto->addAtribuicao(Atribuicao(postoBombeiros->getId(),2,1,"Ambulancia"));

						// Foi encontrado apoio medico!
						haApoioMedico = true;
						break;
					}
				}
			}

			else{	// Posto da Policia, nao contem medicos
				continue;
			}
		}
	}

	// No caso de haver feridos
	if (haFeridos){
		if(haApoioMedico && haApoioPolicial){
			return 0;	// Todas as necessidades supridas!
		}
		else if(haApoioMedico || haApoioPolicial){
			return 1;	// Parte das necessidades supridas!
		}
		else{
			return 2;	// Nenhumas necessidades supridas...
		}
	}

	// No caso de nao haver feridos
	else{
		if (haApoioPolicial)	// Necessidades supridas!
			return 0;
		else					// Necessidades nao supridas...
			return 2;
	}
}



bool ProtecaoCivil::rmAcidente(unsigned int numOcorrencia){
	// Encontrar o acidente no vetor de acidentes
	int indiceAcidente = -1;
	for (unsigned int i=0 ; i<acidentes.size() ; i++){
		if(acidentes.at(i)->getNumOcorrencia()==numOcorrencia){
			indiceAcidente=i;	// Encontrado!
			break;
		}
	}

	// O acidente nao foi encontrado , retornar false
	if (indiceAcidente==-1)
		return false;

	// Obter todas as atribuicoes a esse acidente
	std::vector<Atribuicao> atribuicoes = acidentes.at(indiceAcidente)->getAtribuicoes();

	// Retornar os meios das atribuicoes de volta para os seus respetivos postos
	for (unsigned int i=0 ; i<atribuicoes.size() ; i++){
		retornarAtribuicao(atribuicoes.at(i));
	}

	// Apagar o acidente da base de dados da protecao civil
	acidentes.erase(acidentes.begin()+indiceAcidente);

	return true;
}

int ProtecaoCivil::findLocal(const std::string &nomeLocal) const{
	for(unsigned int i=0 ; i<locais.size() ; i++){
		if(locais.at(i).getNome() == nomeLocal){
			return i;
		}
	}

	return -1;	// local nao foi encontrado
}

void ProtecaoCivil::ordenarPostos(bool compareFunction(Posto* p1, Posto*p2)){
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

void ProtecaoCivil::printPostosId(unsigned int id) const{
	// Procurar o Postos
	for (unsigned int i=0 ; i<postos.size() ; i++){
		if (postos.at(i)->getId() == id){		// Encontrado
			postos.at(i)->printInfoPosto();
			return;
		}
	}

	// Nao ha postos com este id
	std::cout << "Nao ha nenhum posto com o numero de identificacao especificado.";
}

unsigned int ProtecaoCivil::findAcidenteMaiorNum() const{
	unsigned int maiorNum = 0;
	for (unsigned int i=0 ; i<acidentes.size() ; i++){
		if (acidentes.at(i)->getNumOcorrencia() > maiorNum)
			maiorNum = acidentes.at(i)->getNumOcorrencia();
	}

	return maiorNum;
}

void ProtecaoCivil::ordenarAcidentes(bool compareFunction(Acidente* p1, Acidente*p2)){
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

void ProtecaoCivil::printAcidentesId(unsigned int id) const{
	// Procurar o Acidente
	for (unsigned int i=0 ; i<acidentes.size() ; i++){
		if (acidentes.at(i)->getNumOcorrencia() == id){		// Encontrado
			acidentes.at(i)->printInfoAcidente();
			return;
		}
	}

	// Nao ha acidentes com este id
	std::cout << "Nao ha nenhum acidente com o numero de identificacao especificado.";
}

void ProtecaoCivil::printAtribuicoesAcidente(unsigned int id) const{
	// Procurar o Acidente
	for (unsigned int i=0 ; i<acidentes.size() ; i++){
		if (acidentes.at(i)->getNumOcorrencia() == id){		// Encontrado
			acidentes.at(i)->printAtribuicoes();
			return;
		}
	}

	// Nao ha acidentes com este id
	std::cout << "Nao ha nenhum acidente com o numero de identificacao especificado.";
}

double ProtecaoCivil::getDistLocais(const std::string &nomeLocal1, const std::string &nomeLocal2){
	int indiceLocal1 = findLocal(nomeLocal1);
	int indiceLocal2 = findLocal(nomeLocal2);

	if(indiceLocal1==-1 || indiceLocal2==-1)	// Um dos locais nao existe no vetor de locais
		return -1;

	// Obter as coordenadas do vetor
	double vecX = (double)locais.at(indiceLocal2).getXcoord() - locais.at(indiceLocal1).getXcoord();
	double vecY = (double)locais.at(indiceLocal2).getYcoord() - locais.at(indiceLocal1).getYcoord();

	// calcular norma do vetor e retornar esse valor
	return sqrt(vecX*vecX + vecY*vecY);
}

void ProtecaoCivil::ordenarPostosDistLocal(const std::string &nomeLocal){
	bool swapOccured = false;
	Posto* temp;

	// Ordenar o vetor de postos com base na distancia a este local (Bubble sort)
	for (unsigned int i=0 ; i < postos.size() ; i++){
		swapOccured = false;
		for(unsigned int j=0 ; j<postos.size()-1-i ; j++){
			if (getDistLocais(nomeLocal,postos.at(j+1)->getLocal()->getNome()) < getDistLocais(nomeLocal,postos.at(j)->getLocal()->getNome())){
				// Trocar elementos
				temp = postos.at(j);
				postos.at(j) = postos.at(j+1);
				postos.at(j+1) = temp;
				swapOccured = true;	// Ocorreu uma troca
			}
		}
		if (!swapOccured)	// Nao houve nenhuma troca, vetor ja esta ordenado!
			break;
	}
}

void ProtecaoCivil::gravar() const{
	// Escrever no ficheiro info. sobre os postos
	std::ofstream ostr;

	ostr.open(ficheiroPostos);	// Abrir o ficheiro em modo de escrita

	// Veficar se não houve erro ao abrir o ficheiro
	if(!ostr.is_open())
		throw LocalidadeInexistente("Falha ao abrir o ficheiro \"" + ficheiroPostos + "\" ao guardar o estado atual dos postos da Protecao Civil.");

	// Escrever no ficheiro a info. de todos os postos
	for (unsigned int i=0 ; i<postos.size() ; i++){
		postos.at(i)->printSimplifiedInfo(ostr);
		if(i != postos.size() - 1)	// So muda de linha se nao for o ultimo elemento do vec.
			ostr << '\n';
	}

	// Fechar a stream
	ostr.close();



	// Escrever no ficheiro info. sobre os acidentes
	ostr.open(ficheiroAcidentes);	// Abrir o ficheiro em modo de escrita

	// Verificar se não houve erro abrir o ficheiro
	if(!ostr.is_open())
		throw LocalidadeInexistente("Falha ao abrir o ficheiro \"" + ficheiroPostos + "\" ao guardar o estado atual dos acidentes ao abrigo da Protecao Civil.");

	// Escrever no ficheiro a info. de todos os acidentes
	for (unsigned int i=0 ; i<acidentes.size() ; i++){
		acidentes.at(i)->printSimplifiedInfo(ostr);
		if(i != acidentes.size() - 1)	// So muda de linha se nao for o ultimo elemento do vec.
			ostr << '\n';
	}

	// Fechar a stream
	ostr.close();
}


const Local * ProtecaoCivil::getLocal(const std::string &nomeLocal) const{
	// Procurar o local
	for(unsigned int i=0 ; i<locais.size() ; i++){
		if(locais.at(i).getNome() == nomeLocal){		// Encontrado!
			return &(locais.at(i));
		}
	}

	// Local nao foi encontrado
	return NULL;
}

unsigned int ProtecaoCivil::getMaxNumOcorrencia() const{
	unsigned int max = 0;

	// Procura o maior
	for(unsigned int i=0 ; i<acidentes.size() ; i++){
		if (acidentes.at(i)->getNumOcorrencia() > max)
			max = acidentes.at(i)->getNumOcorrencia();
	}

	// Retorna o maior
	return max;
}

void ProtecaoCivil::retornarAtribuicao(const Atribuicao & atribuicao){
	// Procurar pelo posto de onde originam os meios desta atribuicao
	Posto* posto;
	for (unsigned int i=0 ; i<postos.size() ; i++){
		if (postos.at(i)->getId()==atribuicao.getPostoId()){
			posto = postos.at(i);
			break;
		}
	}

	// Posto da Policia
	if (posto->getTipoPosto() == "Policia"){
		posto->addSocorristas(atribuicao.getNumSocorristas());
		posto->addVeiculos(atribuicao.getNumVeiculos());
	}

	// Posto do Inem
	else if (posto->getTipoPosto() == "Inem"){
		posto->addSocorristas(atribuicao.getNumSocorristas());
		posto->addVeiculos(atribuicao.getNumVeiculos());
	}

	// Posto dos Bombeiros
	else{
		posto->addSocorristas(atribuicao.getNumSocorristas());
		Bombeiros* postoBombeiros = dynamic_cast<Bombeiros*>(posto);

		// Atribuicao de autotanques
		if (atribuicao.getTipoVeiculos()=="Autotanque"){
			postoBombeiros->addAutotanques(atribuicao.getNumVeiculos());
		}

		// Atribuicao de Ambulancias
		else {
			postoBombeiros->addAmbulancias(atribuicao.getNumVeiculos());
		}
	}
}





