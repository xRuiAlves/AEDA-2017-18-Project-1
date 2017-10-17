#include "Date.h"

Date::Date(const std::string &date) {		// formato DD-MM-AAAA
	dia = std::stoi(date.substr(0,2));
	mes = std::stoi(date.substr(3,2));
	ano = std::stoi(date.substr(6,4));
}

unsigned int Date::getDia() const {
  return dia;
}

unsigned int Date::getMes() const{
  return mes;
}

unsigned int Date::getAno() const {
  return ano;
}

unsigned int Date::getCompleteData() const {
  unsigned int tempAno = ano * 10000, tempMes = mes * 100, tempData = 0;
  tempData = tempAno + tempMes + dia;
  return tempData;

}

std::string Date::getData() const {
	std::string dia, mes, ano;
	
	// Obter dia
	if (this->dia < 10)			// tem apenas um digito
		dia = "0" + std::to_string(this->dia);
	else 
		dia = std::to_string(this->dia);
	
	// Obter mes
	if (this->mes < 10)			// tem apenas um digito
		mes = "0" + std::to_string(this->mes);
	else
		mes = std::to_string(this->mes);
	
	// Obter ano
	if (this->ano < 10)			// tem apenas um digito
		ano = "000" + std::to_string(this->ano);
	else if (this->ano < 100)		// tem apenas dois digitos
		ano = "00" + std::to_string(this->ano);
	else if (this->ano < 1000)		// tem apenas tres digitos
		ano = "0" + std::to_string(this->ano);
	else
		ano = std::to_string(this->ano);
	
	return (dia + "-" + mes + "-" + ano);
}

 bool Date::operator<(const Date &otherDate) const {
   return this->getCompleteData() < otherDate.getCompleteData();
 }


Date::~Date() {
	// TODO Auto-generated destructor stub
}
