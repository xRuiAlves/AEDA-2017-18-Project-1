#ifndef POSTO_H_
#define POSTO_H_
#include <string>
#include <iostream>

class Posto {
protected:
	const std::string local;
	unsigned int numSocorristas;
	unsigned int numVeiculos;
public:
	Posto(const std::string &local, unsigned int numSocorristas, unsigned int numVeiculos);
	virtual ~Posto();
	void addVeiculos(unsigned int num);
	void addSocorristas(unsigned int num);
	bool rmVeiculos(unsigned int num);
	bool rmSocorristas(unsigned int num);
	unsigned int getNumVeiculos() const;
	unsigned int getNumSocorristas() const;
	const std::string getLocal() const;
	virtual void printSimplifiedInfo(std::ostream &os) const = 0;
};

#endif /* POSTO_H_ */
