#ifndef ATRIBUICAO_H_
#define ATRIBUICAO_H_
#include <string>
#include "Posto.h"

/**
 * Representa uma atribuição de meios de um posto para um acidente.
 */
class Atribuicao {
private:
	const Posto* posto ;					/**< Apontador para o posto de onde originam os meios de apoio 	*/
	const unsigned int numSocorristas;		/**< Número de socorristas entrevenientes na atribuição			*/
	const unsigned int numVeiculos;			/**< Número de veículos entrevenientes na atribuição			*/
	const std::string tipoVeiculos;			/**< Tipo de veículos entrevenientes na atribuição				*/
public:
	/**
	 * @brief Construtor da classe Atribuicao
	 * @param posto - Apontador para o posto de onde originam os meios de apoio
	 * @param numSocorristas - Número de socorristas entrevenientes na atribuição
	 * @param numVeiculos - Número de veículos entrevenientes na atribuição
	 * @param tipoVeiculos - Tipo de veículos entrevenientes na atribuição
	 */
	Atribuicao(const Posto* posto, const unsigned int numSocorristas, const unsigned int numVeiculos, const std::string &tipoVeiculos);

	/**
	 * @brief Destrutor da classe Atribuicao
	 */
	~Atribuicao();

	/**
	 * @brief Permite obter o posto de onde originam os meios de apoio
	 * @return Retorna o apontador para o posto de onde originam os meios de apoio
	 */
	const Posto* getPosto() const;

	/**
	 * @brief Permite obter o número de socorristas entrevenientes na atribuição
	 * @return Retorna o número de socorristas entrevenientes na atribuição
	 */
	const unsigned int getNumSocorristas() const;

	/**
	 * @brief Permite obter o número de veículos entrevenientes na atribuição
	 * @return Retorna o número de veículos entrevenientes na atribuição
	 */
	const unsigned int getNumVeiculos() const;

	/**
	 * @brief Permite obter o tipo de veículos entrevenientes na atribuição
	 * @return Retorna o tipo de veículos entrevenientes na atribuição
	 */
	const std::string getTipoVeiculos() const;
};



#endif /* ATRIBUICAO_H_ */
