#include "Date.h"

Date::Date(const std::string &date) {

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
  std::string tempString = std::to_string(dia) + "-" + std::to_string(mes) + "-" + std::to_string(ano);
  return tempString;
}
 bool operator < (const Date &otherDate) const {
   return this->getCompleteData() < otherDate.getCompleteData();
 }


Date::~Date() {
	// TODO Auto-generated destructor stub
}
