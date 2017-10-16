#ifndef DATE_H_
#define DATE_H_
#include <string>

class Date {
private:
	unsigned int dia;
	unsigned int mes;
	unsigned int ano;
public:
	Date(const std::string &date);
	unsigned int getDia() const;
	unsigned int getMes() const;
	unsigned int getAno() const;
	std::string getData() const;	// retorna string DD-MM-AAAA
	bool operator<(const Date &otherDate) const;
	Date();
};

#endif /* DATE_H_ */
