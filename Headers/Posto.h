#ifndef POSTO_H_
#define POSTO_H_
#include <string>
#include <iostream>
#include "Local.h"

/**
 * Posto da Proteção Civil
 */
class Posto {
protected:
	const unsigned int id;			/**< Numero de Identificação do Posto.						*/
	const Local* local;				/**< Apontador para o local em que o posto se encontra. 	*/
	unsigned int numSocorristas;	/**< Numero de Socorristas presentes no posto em questão.	*/
	unsigned int numVeiculos;		/**< Numero de Veículos presentes no posto em questão.		*/
public:
	/**
	 * @brief Construtor da classe Posto.
	 * @param id - Numero de identificação do Posto.
	 * @param local - Apontador para o local onde o posto se encontra.
	 * @param numSocorristas - Número de Socorristas do Posto.
	 * @param numVeiculos - Número de Veículos do Posto.
	 */
	Posto(const unsigned int id, const Local* local, unsigned int numSocorristas, unsigned int numVeiculos);

	/**
	 * @brief Destrutor da classe Posto.
	 */
	virtual ~Posto();

	/**
	 * @brief Adiciona um certo número de veículos ao posto em questão.
	 * @param num - Número de veículos a adicionar.
	 */
	void addVeiculos(unsigned int num);

	/**
	 * @brief Adiciona um certo número de socorristas ao posto em questão.
	 * @param num - Número de socorristas a adicionar.
	 */
	void addSocorristas(unsigned int num);

	/**
	 * @brief Remove, se possível, um certo número de veículos do posto.
	 * @param num - Número de veículos a remover.
	 * @return Retorna true caso seja possível remover o número indicado de veículos, e retorna false caso contrário (número de veículos atual é menor do que o número de veículos a remover.).
	 */
	bool rmVeiculos(unsigned int num);

	/**
	 * @brief Remove, se possível, um certo número de socorristas do posto.
	 * @param num - Número de socorristas a remover.
	 * @return Retorna true caso seja possível remover o número indicado de socorristas, e retorna false caso contrário (número de socorristas atual é menor do que o número de socorristas a remover.).
	 */
	bool rmSocorristas(unsigned int num);

	/**
	 * @brief Permite saber quantos veículos estão presentes no posto.
	 * @return Retorna o número de veículos do posto.
	 */
	unsigned int getNumVeiculos() const;

	/**
	 * @brief Permite saber quantos socorristas estão presentes no posto.
	 * @return Retorna o número de socorristas do posto.
	 */
	unsigned int getNumSocorristas() const;

	/**
	 * @brief Permite saber o local do posto.
	 * @return Retorna um apontador para o local do posto.
	 */
	const Local* getLocal() const;

	/**
	 * @brief Permite saber o número de identificação do posto.
	 * @return Retorna o número de identificação do posto.
	 */
	const unsigned int getId() const;

	/**
	 * @brief Método puramente virtual que permite saber o tipo de posto de que se trata. A implementação encontra-se nas classes derivadas: Inem , Policia e Bombeiros.
	 * @return Retorna "Bombeiros", "Policia" ou "Inem" consoante o tipo de posto de que se trata.
	 */
	virtual std::string getTipoPosto() const = 0;

	/**
	 * @brief Método puramente virtual que imprime no ecrã toda a informação do respetivo posto. A implementação encontra-se nas classes derivadas: Inem, Policia e Bombeiros.
	 */
	virtual void printInfoPosto() const = 0;

	/**
	 * @brief Método puramente virtual que imprime numa stream o conteudo simplificado de um posto. A implementação encontra-se nas classes derivadas: Inem, Policia e Bombeiros.
	 * @param os - Stream para a qual o conteúdo do posto é impresso
	 */
	virtual void printSimplifiedInfo(std::ostream & os) const = 0;
};

#endif /* POSTO_H_ */
