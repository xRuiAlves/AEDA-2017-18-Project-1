#ifndef ATRIBUICAO_H_
#define ATRIBUICAO_H_
#include <iostream>
#include <string>
#include "Posto.h"

/**
 * Representa uma atribuição de meios de um posto para um acidente.
 */
class Atribuicao {
private:
	const unsigned int postoId;					/**< Número de identificação do posto de onde originam os meios de apoio 	*/
	const unsigned int numSocorristas;			/**< Número de socorristas entrevenientes na atribuição						*/
	const unsigned int numVeiculos;				/**< Número de veículos entrevenientes na atribuição						*/
	const std::string tipoVeiculos;				/**< Tipo de veículos entrevenientes na atribuição							*/
public:
	/**
	 * @brief Construtor da classe Atribuicao
	 * @param postoId - Número de identificação do posto de onde originam os meios de apoio
	 * @param numSocorristas - Número de socorristas entrevenientes na atribuição
	 * @param numVeiculos - Número de veículos entrevenientes na atribuição
	 * @param tipoVeiculos - Tipo de veículos entrevenientes na atribuição
	 */
	Atribuicao(unsigned int postoId, const unsigned int numSocorristas, const unsigned int numVeiculos, const std::string &tipoVeiculos);

	/**
	 * @brief Destrutor da classe Atribuicao
	 */
	~Atribuicao();

	/**
	 * @brief Permite obter o posto de onde originam os meios de apoio
	 * @return Retorna o número de identificação do posto de onde originam os meios de apoio
	 */
	const unsigned int getPostoId() const;

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

	/**
	 * @brief Imprime as informações sobre esta atribuição de uma forma agradável e legível para o utilizador
	 */
	void printInfo() const;

	/**
	 * @brief Overload do operador de inserção para a classe Atribuicao
	 * @param os - Stream passada por referência para a qual será efetuada a escrita
	 * @param atribuicao - Atribuição a ser enviada para a stream
	 * @return Retorna referência de stream de output
	 */
	friend std::ostream & operator<<(std::ostream & os, const Atribuicao& atribuicao);
};



#endif /* ATRIBUICAO_H_ */
