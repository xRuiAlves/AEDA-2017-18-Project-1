#include "Date.h"

Date::Date(const std::string &date) {		// formato DD-MM-AAAA
	dia = std::stoi(date.substr(0,2));
	mes = std::stoi(date.substr(3,2));
	ano = std::stoi(date.substr(6,4));
}

unsigned int getDia() const {
  return dia;
}

unsigned int getMes() const{
  return mes;
}

unsigned int getAno() const {
  return ano;
}

unsigned int getCompleteData() const {
  unsigned int tempAno = ano * 10000, tempMes = mes * 100, tempData = 0;
  tempData = tempAno + tempMes + dia;
  return tempData;

}

std::string getData() const {
	std::string dia, mes, ano;
	
	// Obter dia
	if (dia < 10)			// tem apenas um digito
		dia = "0" + std::stoi(dia);
	else 
		dia = std::stoi(dia);
	
	// Obter mes
	if (mes < 10)			// tem apenas um digito
		mes = "0" + std::stoi(mes);
	else
		mes = std::stoi(mes);
	
	// Obter ano
	if (ano < 10)			// tem apenas um digito
		ano = "000" + std::stoi(ano);
	else if (ano < 100)		// tem apenas dois digitos
		ano = "00" + std::stoi(ano);
	else if (ano < 1000)		// tem apenas tres digitos
		ano = "0" + std::stoi(ano);
	else
		ano = std::stoi(ano);
	
	return (dia + mes + ano);
}

 bool operator < (const Date &otherDate) const {
   return this->getCompleteData() < otherDate.getCompleteData();
 }


Date::~Date() {
	// TODO Auto-generated destructor stub
}
