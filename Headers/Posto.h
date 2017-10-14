#ifndef POSTO_H_
#define POSTO_H_
#include <string>
#include <iostream>
#include "Local.h"

class Posto {
protected:
	const Local* local;
	unsigned int numSocorristas;
	unsigned int numVeiculos;
public:
	Posto(const Local* local, unsigned int numSocorristas, unsigned int numVeiculos);
	virtual ~Posto();
	void addVeiculos(unsigned int num);
	void addSocorristas(unsigned int num);
	bool rmVeiculos(unsigned int num);
	bool rmSocorristas(unsigned int num);
	unsigned int getNumVeiculos() const;
	unsigned int getNumSocorristas() const;
	const Local* getLocal() const;
	virtual std::string getTipoPosto() const = 0;
	virtual void printInfoPosto() const = 0;
};

#endif /* POSTO_H_ */
