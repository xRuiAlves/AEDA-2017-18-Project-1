#include "Bombeiros.h"

Bombeiros::Bombeiros(const std::string &local, unsigned int numSocorristas, unsigned int numAutotanques, unsigned int numAmbulancias)
	: Posto(local,numSocorristas,numAutotanques+numAmbulancias) , numAutotanques(numAutotanques) , numAmbulancias(numAmbulancias) {}


Bombeiros::~Bombeiros() {
	// TODO Auto-generated destructor stub
}

