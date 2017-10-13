#include <iostream>
#include "ProtecaoCivil.h"


void printMenu();
int getOption();	// Retorna int de 1..5 com base na opcao selecionada OU -1 caso a opcao nao seja valida
void declararOcorrencia(ProtecaoCivil &protecaoCivil);
void terminarOcorrencia(ProtecaoCivil &protecaoCivil);
void infoOcorrencia(ProtecaoCivil &protecaoCivil);
void pesquisarPostos(ProtecaoCivil &protecaoCivil);


int main(){

	ProtecaoCivil protecaoCivil("postos","TODO","locais");
	try{	// Ler info dos ficheiros e verificar que nao ha erros na sua abertura
		protecaoCivil.openFiles();
	}
	catch(Erro &e){
		std::cerr << e.getInfo();
	}

	int opt;

	// Perguntar ao utilizador o que quer fazer até este indicar que deseja sair
	while(true){
		printMenu();

		// Get the option from the user and deal with input errors
		try{
			opt = getOption();
		}
		catch(Erro &e){
			std::cout << "\n" << e.getInfo();
			continue;	// Go to the next loop
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
			break;	// opt = 5, the user wants to leave
	}

	return 0;
}

void printMenu(){
	unsigned int headerSize = 80;

	// Give some space from previous menu print
	std::cout << "\n\n";

	// Draw the Menu Header
	for(unsigned int i=0 ; i<headerSize ; i++) { std::cout << "-"; }
	std::cout << std::endl;
	for(unsigned int i=0 ; i<32 ; i++) { std::cout << " "; }
	std::cout << "PROTECAO CIVIL" << std::endl;
	for(unsigned int i=0 ; i<headerSize ; i++) { std::cout << "-"; }
	std::cout << std::endl << std::endl;

	// Draw the option
	std::cout << "1. Declarar Ocorrencia" << std::endl;
	std::cout << "2. Terminar Ocorrencia" << std::endl;
	std::cout << "3. Informacoes sobre Ocorrencias" << std::endl;
	std::cout << "4. Pesquisar Postos" << std::endl;
	std::cout << "5. Sair" << std::endl << std::endl;
}

int getOption(){
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
	if(opt>=1 && opt<=5)
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

	std::cout << "\n\nThis is a STUB!!" << std::endl;
	std::cout << "We are Inside pesquisarPostos()";

	///////////////////////////////////
	// TODO: IMPLEMENT THIS FUNCTION //
	///////////////////////////////////


}
