#ifndef ERRO_H_
#define ERRO_H_
#include <string>

class Erro {
	const std::string info;
public:
	Erro(const std::string &info) : info(info) {}
	const std::string getInfo() const { return info; }
};

#endif /* ERRO_H_ */
