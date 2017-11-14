/** @file */

#include <iostream>
#include "ProtecaoCivil.h"
#include "generic-functions.h"


/**
 * @brief Main Function
 * @return 0 on successfull run
 */
int main(){


	///////////////////////////////////////////////////////////////////////
	// Criar Proteção Civil e verificar se não houve erros na sua abertura

	printWelcomeMenu();

	std::string ficheiroPostos, ficheiroAcidentes, ficheiroLocais;

	ficheiroPostos = lerFicheiroPostos();
	ficheiroAcidentes = lerFicheiroAcidentes();
	ficheiroLocais = lerFicheiroLocais();

	ProtecaoCivil protecaoCivil("postos","acidentes","locais");
	try{	// Ler info dos ficheiros e verificar que nao ha erros na sua abertura
		protecaoCivil.openFiles();
	}
	catch(FicheiroNaoEncontrado &e){
		std::cerr << e.getInfo();
		return 1;
	}


	int opt;

	// Perguntar ao utilizador o que quer fazer até este indicar que deseja sair
	while(true){
		printMainMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try{
			opt = getOption(1,5);
		}
		catch(InputInvalido &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1)
			declararOcorrencia(protecaoCivil);
		else if (opt == 2)
			terminarOcorrencia(protecaoCivil);
		else if (opt == 3)
			infoOcorrencia(protecaoCivil);
		else if (opt == 4)
			pesquisarPostos(protecaoCivil);
		else
			break;	// opt = 5, o utilizador quer sair
	}

	return 0;
}


int getOption(int min, int max){
	int opt;

	// Get the option
	std::cout << ">>> ";
	std::cin >> opt;

	// Check if not a number was entered
	if(std::cin.fail()){
		// Clear the cin error flags and the stream content, throw the error
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		throw (InputInvalido("Input Invalido!"));
	}

	// Clear the cin stream even if no error occured, to ensure the stream always stays clean
	std::cin.ignore(1000,'\n');

	// Check if the option is valid
	if(opt>=min && opt<=max)
		return opt;
	else
		throw (InputInvalido("Opcao Invalida!"));
}

void declararOcorrencia(ProtecaoCivil &protecaoCivil){
	std::string localidade, data, tipoCasa, tipoEstrada;
	int tipoAcidente;
	bool existenciaFeridos;
	unsigned int numFeridos, numVeiculos, numBombeirosNecess, numAutotanquesNecess, areaChamas;
	Acidente* acidente;

	try{
		localidade = obterLocalidade(protecaoCivil);
		data = lerData();
		tipoAcidente = obterTipoAcidente();

		// Obter o apontador para o local do acidente
		const Local* local = protecaoCivil.getLocal(localidade);

		switch(tipoAcidente){
		case 1:		// Assaltos
			tipoCasa = assaltoObterTipoCasa();
			existenciaFeridos = assaltoObterExistenciaFeridos();
			acidente = new Assalto(data,local,protecaoCivil.getMaxNumOcorrencia()+1,tipoCasa,existenciaFeridos);
			break;
		case 2:		// Acidentes de Viacao
			tipoEstrada = viacaoObterTipoEstrada();
			numFeridos = viacaoObterNumFeridos();
			numVeiculos = viacaoObterNumVeiculos();
			acidente = new AcidenteViacao(data,local,protecaoCivil.getMaxNumOcorrencia()+1,tipoEstrada,numFeridos,numVeiculos);
			break;
		case 3:		// Incendios Florestais
			areaChamas = incendioObterAreaChamas();
			numAutotanquesNecess = areaChamas;	// 1 Autotanque por cada km quadrado
			numBombeirosNecess = numAutotanquesNecess * 3;		// Cada autotanque leva 3 bombeiros
			acidente = new IncendioFlorestal(data,local,protecaoCivil.getMaxNumOcorrencia()+1,numBombeirosNecess,numAutotanquesNecess,areaChamas);
			break;	// Incendios Domesticos
		case 4:
			tipoCasa = incendioObterTipoCasa();
			numAutotanquesNecess = 1;	// Um incendio Domestico necessita de 1 autotanque
			numBombeirosNecess = 3;		// Cada autotanque leva 3 bombeiros
			acidente = new IncendioDomestico(data,local,protecaoCivil.getMaxNumOcorrencia()+1,numBombeirosNecess,numAutotanquesNecess,tipoCasa);
			break;
		}
	}
	catch(Erro &e){
		std::cout << '\n' << e.getInfo() << std::endl << std::endl;
		pause();
		return;
	}

	// Adicionar o acidente à protecao civil
	try{
		protecaoCivil.addAcidente(acidente);
	}
	catch(MeiosInsuficientes &e){
		std::cout << '\n' << e.getInfo() << std::endl << std::endl;
		pause();
		return;
	}
	catch(MeiosInexistentes &e){
		std::cout << '\n' << e.getInfo() << std::endl << std::endl;
		pause();
		return;
	}

	// Nao ocorreu qualquer erro! A adicao teve sucesso total!
	std::cout << "\nO acidente foi adicionado com sucesso e todos os meios necessarios foram devidamente acionados.\n\n";
	pause();
}

void terminarOcorrencia(ProtecaoCivil &protecaoCivil){
	unsigned int numOcorrencia;

	// Obter o número de ocorrência por parte do utilizador e lidar com eventual erro
	try{
		numOcorrencia = obterNumOcorrencia();
	}
	catch(InputInvalido &e){
		std::cout << '\n' << e.getInfo() << std::endl << std::endl;
		pause();
		return;
	}

	// Apagar a ocorrência, caso ela exista na base de dados da proteção civil
	if(protecaoCivil.rmAcidente(numOcorrencia)){
		std::cout << "\nA ocorrencia foi terminada com sucesso!\n\n";
	}
	else{
		std::cout << "\nO numero de identificacao inserido nao corresponde a nenhuma ocorrencia em aberto!\n\n";
	}

	// Esperar que o utilizador prima enter para retorna ao menu principal
	pause();
}

void infoOcorrencia(ProtecaoCivil &protecaoCivil){

	int opt;

	// Perguntar ao utilizador o que quer fazer até estes querer voltar ao menu anterior
	while(true){
		printInfoOcorrenciasMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try{
			opt = getOption(1,11);
		}
		catch(InputInvalido &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		std::cout << std::endl;

		if (opt == 1){
			// Ordenenar os Acidentes por local e imprimi-los a todos
			protecaoCivil.ordenarAcidentes(compararAcidentesLocal);
			protecaoCivil.printTodosAcidentes();
			pause();
			break;
		}
		else if (opt == 2){
			// Pedir ao utilizador que introduzar uma Localidade
			std::string localidade;

			try{
				localidade = obterLocalidade(protecaoCivil);
			}
			catch(LocalidadeInexistente &e){
				std::cout << '\n' << e.getInfo() << std::endl << std::endl;
				pause();
				return;
			}

			// Ordenar os acidentes por localidade
			protecaoCivil.ordenarAcidentes(compararAcidentesLocal);

			std::cout << std::endl;

			// Imprimir todos os acidentes que existem nesse local ; caso não haja nenhum, informar o utilizador
			protecaoCivil.printAcidentesLocal(localidade);

			std::cout << std::endl << std::endl;

			pause();
			break;
		}
		else if (opt == 3){
			// Ordenenar os Acidentes por data e imprimi-los a todos
			protecaoCivil.ordenarAcidentes(compararAcidentesData);
			protecaoCivil.printTodosAcidentes();
			pause();
			break;
		}
		else if (opt == 4){
			// Pedir ao utilizador que introduzar uma Data
			std::string data;

			try{
				data = lerData();
			}
			catch(DataInvalida &e){
				std::cout << "\n" << e.getInfo() << std::endl << std::endl;
				pause();
				break;
			}

			// Ordenar os acidentes por data
			protecaoCivil.ordenarAcidentes(compararAcidentesData);

			std::cout << std::endl;

			// Imprimir todos os acidentes que existem nessa data ; caso não haja nenhum, informar o utilizador
			protecaoCivil.printAcidentesData(data);

			std::cout << std::endl << std::endl;

			pause();
			break;
		}
		else if (opt == 5){
			// Ordenenar os Acidentes por tipo e imprimi-los a todos
			protecaoCivil.ordenarAcidentes(compararAcidentesTipo);
			protecaoCivil.printTodosAcidentes();
			pause();
			break;
		}
		else if (opt == 6){
			// Ordenar os acidentes por tipo e imprimir os Assaltos
			protecaoCivil.ordenarAcidentes(compararAcidentesTipo);
			protecaoCivil.printAcidentesTipo("Assalto");
			pause();
			break;
		}
		else if (opt == 7){
			// Ordenar os acidentes por tipo e imprimir os Acidentes de Viacao
			protecaoCivil.ordenarAcidentes(compararAcidentesTipo);
			protecaoCivil.printAcidentesTipo("Acidente de Viacao");
			pause();
			break;
		}
		else if (opt == 8){
			// Ordenar os acidentes por tipo e imprimir os Incendios (quer Domesticos, quer Florestais)
			protecaoCivil.ordenarAcidentes(compararAcidentesTipo);
			protecaoCivil.printAcidentesTipo("Incendio Domestico");
			protecaoCivil.printAcidentesTipo("Incendio Florestal");
			pause();
			break;
		}
		else if (opt == 9){
			// Pedir ao utilizador que insira o numero de identificacao do acidente e comunicar eventual erro
			unsigned int acidenteId;
			try{
				acidenteId = obterIdAcidente();
			}
			catch(InputInvalido &e){
				std::cout << "\n\n" << e.getInfo();
				std::cout << std::endl << std::endl;
				pause();
				break;
			}

			// Imprimir o acidente com o id pretendido
			std::cout << std::endl;
			protecaoCivil.printAcidentesId(acidenteId);
			std::cout << std::endl;

			pause();
			break;
		}
		else if (opt == 10){
			// Pedir ao utilizador que insira o numero de identificacao do acidente e comunicar eventual erro
			unsigned int acidenteId;
			try{
				acidenteId = obterIdAcidente();
			}
			catch(InputInvalido &e){
				std::cout << "\n\n" << e.getInfo();
				std::cout << std::endl << std::endl;
				pause();
				break;
			}

			// Imprimir o acidente com o id pretendido
			std::cout << std::endl;
			protecaoCivil.printAtribuicoesAcidente(acidenteId);
			std::cout << std::endl;

			pause();
			break;
		}
		else
			break;	// opt = 11, o utilizador quer voltar
	}



}

void pesquisarPostos(ProtecaoCivil &protecaoCivil){

	int opt;

	// Perguntar ao utilizador o que quer fazer até estes querer voltar ao menu anterior
	while(true){
		printPesquisarPostosMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try{
			opt = getOption(1,8);
		}
		catch(InputInvalido &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		std::cout << std::endl;

		if (opt == 1){
			// Ordenar os postos por local e imprimi-los a todos
			protecaoCivil.ordenarPostos(compararPostosLocal);
			protecaoCivil.printTodosPostos();
			pause();
			break;
		}
		else if (opt == 2){
			// Pedir ao utilizador que introduzar uma Localidade
			std::string localidade;
			std::cout << "Insira a localidade que deseja: ";
			getline(std::cin,localidade);

			// Ordenar os postos por localidade
			protecaoCivil.ordenarPostos(compararPostosLocal);

			std::cout << std::endl;

			// Imprimir todos os postos que existem nesse local ; caso não haja nenhum, informar o utilizador
			protecaoCivil.printPostosLocal(localidade);

			std::cout << std::endl << std::endl;

			pause();
			break;
		}
		else if (opt == 3){
			// Ordenar os postos por tipo e imprimi-los a todos
			protecaoCivil.ordenarPostos(compararPostosTipo);
			protecaoCivil.printTodosPostos();
			pause();
			break;
		}
		else if (opt == 4){
			// Ordenar os postos por tipo e imprimir os postos de Bombeiros
			protecaoCivil.ordenarPostos(compararPostosTipo);
			protecaoCivil.printPostosTipo("Bombeiros");
			pause();
			break;
		}
		else if (opt == 5){
			// Ordenar os postos por tipo e imprimir os postos de Policia
			protecaoCivil.ordenarPostos(compararPostosTipo);
			protecaoCivil.printPostosTipo("Policia");
			pause();
			break;
		}
		else if (opt == 6){
			// Ordenar os postos por tipo e imprimir os postos de Inem
			protecaoCivil.ordenarPostos(compararPostosTipo);
			protecaoCivil.printPostosTipo("Inem");
			pause();
			break;
		}
		else if (opt == 7){
			// Pedir ao utilizador que insira o numero de identificacao do posto e comunicar eventual erro
			unsigned int postoId;
			try{
				postoId = obterIdPosto();
			}
			catch(InputInvalido &e){
				std::cout << "\n\n" << e.getInfo();
				std::cout << std::endl << std::endl;
				pause();
				break;
			}

			// Imprimir o posto com o id pretendido
			std::cout << std::endl;
			protecaoCivil.printPostosId(postoId);
			std::cout << std::endl;

			pause();
			break;
		}
		else
			break;	// opt = 8, o utilizador quer voltar
	}

}

bool compararPostosLocal(Posto* p1, Posto* p2){
	return (p1->getLocal()->getNome() < p2->getLocal()->getNome());
}

bool compararPostosTipo(Posto* p1, Posto* p2){
	return (p1->getTipoPosto() < p2->getTipoPosto());
}

bool compararAcidentesLocal(Acidente* a1, Acidente* a2){
	return (a1->getLocal()->getNome() < a2->getLocal()->getNome());
}

bool compararAcidentesTipo(Acidente* a1, Acidente* a2){
	return (a1->getTipoAcidente() < a2->getTipoAcidente());
}

bool compararAcidentesData(Acidente* a1, Acidente* a2){
	return (a1->getData() < a2->getData());
}

void printMainMenu(){
	// Draw the header
	printHeader("Protecao Civil");

	// Draw the options
	std::cout << "1. Declarar Ocorrencia" << std::endl;
	std::cout << "2. Terminar Ocorrencia" << std::endl;
	std::cout << "3. Informacoes sobre Ocorrencias" << std::endl;
	std::cout << "4. Pesquisar Postos" << std::endl;
	std::cout << "5. Sair" << std::endl << std::endl;
}

void printPesquisarPostosMenu(){
	// Draw the header
	printHeader("Pesquisar Postos");

	// Draw the options
	std::cout << "1. Pesquisar por Localidade (totalidade)" << std::endl;
	std::cout << "2. Pesquisar por Localidade (especifico)" << std::endl;
	std::cout << "3. Pesquisar por Tipo de Posto" << std::endl;
	std::cout << "4. Pesquisar por Postos de Bombeiros" << std::endl;
	std::cout << "5. Pesquisar por Postos da Policia" << std::endl;
	std::cout << "6. Pesquisar por Postos do Inem" << std::endl;
	std::cout << "7. Pesquisar por Numero de Identificacao" << std::endl;
	std::cout << "8. Voltar" << std::endl << std::endl;
}

void printInfoOcorrenciasMenu(){
	// Draw the header
	printHeader("Informacoes sobre Ocorrencias");

	// Draw the options
	std::cout << "1. Pesquisar por Localidade (totalidade)" << std::endl;
	std::cout << "2. Pesquisar por Localidade (especifico)" << std::endl;
	std::cout << "3. Pesquisar por Data (totalidade)" << std::endl;
	std::cout << "4. Pesquisar por Data (especifica)" << std::endl;
	std::cout << "5. Pesquisar por Tipo de Ocorrencia" << std::endl;
	std::cout << "6. Pesquisar por Assaltos" << std::endl;
	std::cout << "7. Pesquisar por Acidentes de Viacao" << std::endl;
	std::cout << "8. Pesquisar por Incendios" << std::endl;
	std::cout << "9. Pesquisar por Numero de Identificacao" << std::endl;
	std::cout << "10. Pesquisar por Meios Atribuidos a um Acidente" << std::endl;
	std::cout << "11. Voltar" << std::endl << std::endl;
}

void printHeader(const std::string &header){
	unsigned int headerSize = 80;
	unsigned int headerLeftSpaces = (headerSize - header.size()) / 2;

	// Give some space from previous menu print
	std::cout << "\n\n";

	// Draw the Menu Header
	for(unsigned int i=0 ; i<headerSize ; i++) { std::cout << "-"; }
	std::cout << std::endl;
	for(unsigned int i=0 ; i<headerLeftSpaces ; i++) { std::cout << " "; }
	std::cout << header << std::endl;
	for(unsigned int i=0 ; i<headerSize ; i++) { std::cout << "-"; }
	std::cout << std::endl << std::endl;
}

std::string lerData(){
	std::string data;
	std::cout << "\nInsira a data em que ocorreu o acidente (Formato DD-MM-AAAA): ";
	getline(std::cin,data);

	// Verificar se está no formato válido (DD-MM-AAAA)
	if(data.size() != 10)											// Verificar se a data tem o tamanho correto
		throw (DataInvalida("Data Invalida!"));
	else if ((data.at(2) != '-') || (data.at(5) != '-'))			// Verificar se dia, mes e ano estao separados por um traco
		throw (DataInvalida("Data Invalida!"));
	else if ((data.at(0) < '0') || (data.at(0) > '9'))				// Verificar se Dx é um digito
		throw (DataInvalida("Data Invalida!"));
	else if ((data.at(1) < '0') || (data.at(1) > '9'))				// Verificar se xD é um digito
		throw (DataInvalida("Data Invalida!"));
	else if ((data.at(3) < '0') || (data.at(3) > '9'))				// Verificar se Mx é um digito
		throw (DataInvalida("Data Invalida!"));
	else if ((data.at(4) < '0') || (data.at(4) > '9'))				// Verificar se xM é um digito
		throw (DataInvalida("Data Invalida!"));
	else if ((data.at(6) < '0') || (data.at(6) > '9'))				// Verificar se Axxx é um dígito
		throw (DataInvalida("Data Invalida!"));
	else if ((data.at(7) < '0') || (data.at(7) > '9'))				// Verificar se xAxx é um dígito
		throw (DataInvalida("Data Invalida!"));
	else if ((data.at(8) < '0') || (data.at(8) > '9'))				// Verificar se xxAx é um dígito
		throw (DataInvalida("Data Invalida!"));
	else if ((data.at(9) < '0') || (data.at(9) > '9'))				// Verificar se xxxA é um dígito
		throw (DataInvalida("Data Invalida!"));

	// Verificar se a data segue os padrões normais de datas
	int dia = stoi(data.substr(0,2));
	int mes = stoi(data.substr(3,2));
	int ano = stoi(data.substr(6,4));

	// Verificar se o mes esta dentro dos limites reais
	if(mes<0 || mes>12)
		throw (DataInvalida("Data Invalida!"));

	switch(mes){
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:		// Meses com 31 dias
		if ((dia<0) || (dia>31))
			throw (DataInvalida("Data Incorreta!"));
		break;
	case 4: case 6: case 9: case 11:								// Meses com 30 dias
		if ((dia<0) || (dia>30))
			throw (DataInvalida("Data Incorreta!"));
		break;
	case 2:															// Fevereiro
		if ((dia<0) || (dia>29))
			throw (DataInvalida("Data Incorreta!"));
		else if ((dia == 29) && (ano%4 != 0))	// Se o dia for 29 de Fevereiro e o ano não for bissexto -> erro
			throw (DataInvalida("Data Incorreta!"));
		break;
	}

	// Data válidade
	return data;
}

std::string obterLocalidade(ProtecaoCivil &protecaoCivil){
	std::string localidade;
	std::cout << "\nInsira a localidade em que a ocorrencia teve lugar: ";
	getline(std::cin,localidade);

	// Verificar se o local existe na base de dados da Protecao Civil
	if(protecaoCivil.findLocal(localidade) == -1)		// local não existe no vetor de locais
		throw (LocalidadeInexistente("A localidade introduzida nao existe na base de dados da Protecao Civil"));
	else
		return localidade;
}

int obterTipoAcidente(){
	int opt;
	std::cout << "\nInsira o tipo de Acidente:" << std::endl;
	std::cout << "1. Assalto" << std::endl;
	std::cout << "2. Acidente de Viacao" << std::endl;
	std::cout << "3. Incendio Florestal" << std::endl;
	std::cout << "4. Incendio Domestico" << std::endl << std::endl;
	try{
		opt = getOption(1,4);
	}
	catch(InputInvalido &e){
		throw TipoAcidenteInvalido(e.getInfo());
	}

	return opt;		// Sucesso na leitura
}
std::string assaltoObterTipoCasa(){
	std::string tipoCasa;
	std::cout << "\nIndique o tipo de casa em que o assalto teve lugar (Partiular ou Comercial): ";
	getline(std::cin, tipoCasa);

	// Aceitar "Particular" de várias formas diferentes
	if ((tipoCasa=="p") || (tipoCasa=="P") || (tipoCasa=="particular") || (tipoCasa=="Particular") || (tipoCasa=="1"))
		return "Particular";

	// Aceitar "Comercial" de várias formas diferentes
	else if ((tipoCasa=="c") || (tipoCasa=="C") || (tipoCasa=="comercial") || (tipoCasa=="Comercial") || (tipoCasa=="2"))
		return "Comercial";

	// Input Invalido
	else
		throw (TipoCasaInvalido("Tipo de casa invalido!"));
}

bool assaltoObterExistenciaFeridos(){
	std::string feridos;
	std::cout << "\nIndique se houve feridos no decorrer do assalto (Sim ou Nao): ";
	getline(std::cin, feridos);

	// Aceitar "Sim" de várias formas diferentes
	if ((feridos=="s") || (feridos=="S") || (feridos=="sim") || (feridos=="Sim") || (feridos=="SIM") || (feridos=="1"))
		return true;

	// Aceitar "Nao" de várias formas diferentes
	else if ((feridos=="n") || (feridos=="N") || (feridos=="nao") || (feridos=="Nao") || (feridos=="NAO") || (feridos=="2"))
		return false;

	// Input Invalido
	else
		throw (InputInvalido("Resposta invalida!"));
}

std::string viacaoObterTipoEstrada(){
	std::string tipoEstrada;
	std::cout << "\nIndique o tipo de estrada em que ocorreu o acidente (Estrada Nacional ou Auto-Estrada): ";
	getline(std::cin, tipoEstrada);

	// Aceitar "Estrada Nacional" de várias formas diferentes
	if ((tipoEstrada=="Estrada Nacional") || (tipoEstrada=="estrada nacional") || (tipoEstrada=="en") || (tipoEstrada=="EN") || (tipoEstrada=="1"))
		return "Estrada Nacional";

	// Aceitar "Auto-Estrada" de várias formas diferentes
	else if ((tipoEstrada=="Auto-Estrada") || (tipoEstrada=="auto-estrada") || (tipoEstrada=="ae") || (tipoEstrada=="AE") || (tipoEstrada=="2"))
		return "Auto-Estrada";

	// Input Invalido
	else
		throw (InputInvalido("Tipo de estrada invalido!"));
}

unsigned int viacaoObterNumFeridos(){
	int numFeridos;
	std::cout << "\nInsira o numero de feridos envolvidos no acidente: ";
	std::cin >> numFeridos;

	// Verificar se foi introduzido um numero
	if(std::cin.fail()){
		// Limpar as flags de erro e limpar a stream, lançar a exceção
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		throw (InputInvalido("Input Invalido!"));
	}

	// Limpar a stream mesmo que não tenha ocorrido qualquer erro, para garantir que está sempre limpa e vazia
	std::cin.ignore(1000,'\n');

	// Verificar se o numero de feridos introduzido nao foi absurdo
	if (numFeridos < 0)
		throw (InputInvalido("Numero de feridos nao pode ser negativo!"));
	else if (numFeridos == 0)
		throw (InputInvalido("Numero de feridos nao pode ser nulo!"));
	else
		return ((unsigned int) numFeridos);
}

unsigned int viacaoObterNumVeiculos(){
	int numVeiculos;
	std::cout << "\nInsira o numero de veiculos envolvidos no acidente: ";
	std::cin >> numVeiculos;

	// Verificar se foi introduzido um numero
	if(std::cin.fail()){
		// Limpar as flags de erro e limpar a stream, lançar a exceção
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		throw (InputInvalido("Input Invalido!"));
	}

	// Limpar a stream mesmo que não tenha ocorrido qualquer erro, para garantir que está sempre limpa e vazia
	std::cin.ignore(1000,'\n');

	// Verificar se o numero de veiculos introduzido nao foi absurdo
	if (numVeiculos < 0)
		throw (InputInvalido("Numero de veiculos nao pode ser negativo!"));
	else if (numVeiculos == 0)
		throw (InputInvalido("Numero de veiculos nao pode ser nulo!"));
	else
		return ((unsigned int) numVeiculos);
}

unsigned int incendioObterAreaChamas(){
	int areaChamas;
	std::cout << "\nInsira a area de chamas deste incendio (em Kilometros Quadrados): ";
	std::cin >> areaChamas;

	// Verificar se foi introduzido um numero
	if(std::cin.fail()){
		// Limpar as flags de erro e limpar a stream, lançar a exceção
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		throw (InputInvalido("Input Invalido!"));
	}

	// Limpar a stream mesmo que não tenha ocorrido qualquer erro, para garantir que está sempre limpa e vazia
	std::cin.ignore(1000,'\n');

	// Verificar se a area de chamas introduzida nao foi absurda
	if (areaChamas < 0)
		throw (InputInvalido("Area de chamas nao pode ser negativa!"));
	else if (areaChamas == 0)
		throw (InputInvalido("Area de chamas nao pode ser nula!"));
	else
		return ((unsigned int) areaChamas);
}

std::string incendioObterTipoCasa(){
	std::string tipoCasa;
	std::cout << "\nIndique o tipo de casa em que o incendio teve lugar (Apartamento ou Moradia): ";
	getline(std::cin, tipoCasa);

	// Aceitar "Apartamento" de várias formas diferentes
	if ((tipoCasa=="a") || (tipoCasa=="A") || (tipoCasa=="apartamento") || (tipoCasa=="Apartamento") || (tipoCasa=="1"))
		return "Apartamento";

	// Aceitar "Moradia" de várias formas diferentes
	else if ((tipoCasa=="m") || (tipoCasa=="M") || (tipoCasa=="moradia") || (tipoCasa=="Moradia") || (tipoCasa=="2"))
		return "Moradia";

	// Input Invalido
	else
		throw (TipoCasaInvalido("Tipo de casa invalido!"));
}

unsigned int obterNumOcorrencia(){
	int numOcorrencia;
	std::cout << "\nInsira o numero da ocorrencia que deseja dar por terminada: ";
	std::cin >> numOcorrencia;

	// Verificar se foi introduzido um numero
	if(std::cin.fail()){
		// Limpar as flags de erro e limpar a stream, lançar a exceção
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		throw (InputInvalido("Input Invalido!"));
	}

	// Limpar a stream mesmo que não tenha ocorrido qualquer erro, para garantir que está sempre limpa e vazia
	std::cin.ignore(1000,'\n');

	// Verificar se a area de chamas introduzida nao foi absurda
	if (numOcorrencia <= 0)
		throw (InputInvalido("O numero de ocorrencia nao pode ser nulo nem negativo!"));
	else
		return ((unsigned int) numOcorrencia);
}

unsigned int obterIdPosto(){
	int numId;
	std::cout << "\nInsira o numero de identificacao do posto: ";
	std::cin >> numId;

	// Verificar se foi introduzido um numero
	if(std::cin.fail()){
		// Limpar as flags de erro e limpar a stream, lançar a exceção
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		throw (InputInvalido("Input Invalido!"));
	}

	// Limpar a stream mesmo que não tenha ocorrido qualquer erro, para garantir que está sempre limpa e vazia
	std::cin.ignore(1000,'\n');

	// Verificar se o numero de identificacao introduzido nao foi absurdo
	if (numId <= 0)
		throw (InputInvalido("O numero de identificacao do posto nao pode ser nulo nem negativo!"));
	else
		return ((unsigned int) numId);

}

unsigned int obterIdAcidente(){
	int numId;
	std::cout << "\nInsira o numero de identificacao do acidente: ";
	std::cin >> numId;

	// Verificar se foi introduzido um numero
	if(std::cin.fail()){
		// Limpar as flags de erro e limpar a stream, lançar a exceção
		std::cin.clear();
		std::cin.ignore(1000,'\n');
		throw (InputInvalido("Input Invalido!"));
	}

	// Limpar a stream mesmo que não tenha ocorrido qualquer erro, para garantir que está sempre limpa e vazia
	std::cin.ignore(1000,'\n');

	// Verificar se o numero de identificacao introduzido nao foi absurdo
	if (numId <= 0)
		throw (InputInvalido("O numero de identificacao do acidente nao pode ser nulo nem negativo!"));
	else
		return ((unsigned int) numId);

}

void pause(){
	std::cout << "Prima <ENTER> para continuar ...";
	int c = getchar();	// Wait for user to press enter and check if only enter was pressed!

	if(c == 10)			// The user pressed only the enter key
		return;
	else 				// The user pressed keys other than enter, clear the stream from that input
		std::cin.ignore(1000,'\n');
}

void printWelcomeMenu(){
	unsigned int headerSize = 80;
	std::string welcomeMessage = "PROTECAO CIVIL";

	// Escrever uma mensagem de bem-vindo
	for (unsigned int i=0 ; i<headerSize ; i++) { std::cout << '-'; }
	std::cout << std::endl;
	for (unsigned int i=0 ; i<headerSize ; i++) { std::cout << '-'; }
	std::cout << std::endl << std::endl;
	for (unsigned int i=0 ; i<(headerSize-welcomeMessage.size())/2 ; i++) { std::cout << ' '; }
	std::cout << welcomeMessage << std::endl << std::endl;
	for (unsigned int i=0 ; i<headerSize ; i++) { std::cout << '-'; }
	std::cout << std::endl;
	for (unsigned int i=0 ; i<headerSize ; i++) { std::cout << '-'; }
	std::cout << std::endl << std::endl;
}

std::string lerFicheiroPostos(){
	std::string ficheiroPostos;
	std::cout << "\nIndique o nome do ficheiro de postos: ";
	getline(std::cin, ficheiroPostos);

	return ficheiroPostos;
}

std::string lerFicheiroAcidentes(){
	std::string ficheiroAcidentes;
	std::cout << "\nIndique o nome do ficheiro de acidentes: ";
	getline(std::cin, ficheiroAcidentes);

	return ficheiroAcidentes;
}

std::string lerFicheiroLocais(){
	std::string ficheiroLocais;
	std::cout << "\nIndique o nome do ficheiro de locais: ";
	getline(std::cin, ficheiroLocais);

	return ficheiroLocais;
}
