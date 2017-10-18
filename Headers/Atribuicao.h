#ifndef ATRIBUICAO_H_
#define ATRIBUICAO_H_
#include <string>
#include "Posto.h"

class Atribuicao {
private:
	const Posto* posto ;
	const unsigned int numSocorristas;
	const unsigned int numVeiculos;
	const std::string tipoVeiculos;
public:
	Atribuicao::Atribuicao(const Posto* posto, const unsigned int numSocorristas, const unsigned int numVeiculos, const std::string &tipoVeiculos);
	const unsigned int getPosto() const;
	const unsigned int getNumSocorristas() const;
	const unsigned int getNumVeiculos() const;
	const std::string getTipoVeiculos() const;


};





/*
 * Posto*
 * num  socor
 * numveoi
 * string tipo de veic
 *TODOS PODE SWER COST
 */
