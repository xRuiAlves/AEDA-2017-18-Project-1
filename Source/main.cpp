#include <iostream>
#include "ProtecaoCivil.h"


int getOption(int min, int max);	// Aceita uma opção entre [min , max] e lança erro em caso de mau input / input fora de range
void declararOcorrencia(ProtecaoCivil &protecaoCivil);
void terminarOcorrencia(ProtecaoCivil &protecaoCivil);
void infoOcorrencia(ProtecaoCivil &protecaoCivil);
void pesquisarPostos(ProtecaoCivil &protecaoCivil);
bool compararPostosLocal(Posto* p1, Posto* p2);
bool compararPostosTipo(Posto* p1, Posto* p2);
void printMainMenu();
void printPesquisarPostosMenu();
void printHeader(const std::string &header);
void pause();


int main(){


	///////////////////////////////////////////////////////////////////////
	// Criar Proteção Civil e verificar se não houve erros na sua abertura

	ProtecaoCivil protecaoCivil("postos","TODO","locais");
	try{	// Ler info dos ficheiros e verificar que nao ha erros na sua abertura
		protecaoCivil.openFiles();
	}
	catch(Erro &e){
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
		catch(Erro &e){
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
		throw (Erro("Invalid Input!"));
	}

	// Clear the cin stream even if no error occured, to ensure the stream always stays clean
	std::cin.ignore(1000,'\n');

	// Check if the option is valid
	if(opt>=min && opt<=max)
		return opt;
	else
		throw (Erro("Invalid Option!"));
}

void declararOcorrencia(ProtecaoCivil &protecaoCivil){

	std::cout << "\n\nThis is a STUB!!" << std::endl;
	std::cout << "We are Inside declararOcorrencia()";

	///////////////////////////////////
	// TODO: IMPLEMENT THIS FUNCTION //
	///////////////////////////////////


}

void terminarOcorrencia(ProtecaoCivil &protecaoCivil){

	std::cout << "\n\nThis is a STUB!!" << std::endl;
	std::cout << "We are Inside terminarOcorrencia()";

	///////////////////////////////////
	// TODO: IMPLEMENT THIS FUNCTION //
	///////////////////////////////////


}

void infoOcorrencia(ProtecaoCivil &protecaoCivil){

	std::cout << "\n\nThis is a STUB!!" << std::endl;
	std::cout << "We are Inside infoOcorrencia()";

	///////////////////////////////////
	// TODO: IMPLEMENT THIS FUNCTION //
	///////////////////////////////////


}

void pesquisarPostos(ProtecaoCivil &protecaoCivil){

	int opt;

	// Perguntar ao utilizador o que quer fazer até estes querer voltar ao menu anterior
	while(true){
		printPesquisarPostosMenu();

		// Pedir opcao ao utilizador e verificar se nao houve erro de input
		try{
			opt = getOption(1,6);
		}
		catch(Erro &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Ir para o proximo loop , pedir nova opcao
		}

		if (opt == 1){
			// Ordenar os postos por local e imprimi-los a todos
			protecaoCivil.ordernarPostos(compararPostosLocal);
			protecaoCivil.printTodosPostos();
			pause();
			break;
		}
		else if (opt == 2){
			// Ordenar os postos por tipo e imprimi-los a todos
			protecaoCivil.ordernarPostos(compararPostosTipo);
			protecaoCivil.printTodosPostos();
			pause();
			break;
		}
		else if (opt == 3){
			/////////////////////////
			///////// TODO //////////
			/////////////////////////
			pause();
			break;
		}
		else if (opt == 4){
			/////////////////////////
			///////// TODO //////////
			/////////////////////////
			pause();
			break;
		}
		else if (opt == 5){
			/////////////////////////
			///////// TODO //////////
			/////////////////////////
			pause();
			break;
		}
		else
			break;	// opt = 6, o utilizador quer voltar
	}

}

bool compararPostosLocal(Posto* p1, Posto* p2){
	return (p1->getLocal()->getNome() < p2->getLocal()->getNome());
}

bool compararPostosTipo(Posto* p1, Posto* p2){
	return (p1->getTipoPosto() < p2->getTipoPosto());
}

void printMainMenu(){
	// Draw the header
	printHeader("Main Menu");

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
	std::cout << "1. Pesquisar por Localidade" << std::endl;
	std::cout << "2. Pesquisar por Tipo de Posto" << std::endl;
	std::cout << "3. Pesquisar por Postos de Bombeiros" << std::endl;
	std::cout << "4. Pesquisar por Postos da Policia" << std::endl;
	std::cout << "5. Pesquisar por Postos do Inem" << std::endl;
	std::cout << "6. Sair" << std::endl << std::endl;
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

void pause(){
	std::cout << "Prima qualquer tecla para continuar ...";
	getchar();	// Wait for user to press enter
}
