#ifndef BOMBEIROS_H_
#define BOMBEIROS_H_
#include "Posto.h"

/**
 * Posto ddos Bombeiros da Proteção Civil, classe derivada da classe Posto.
 */
class Bombeiros : public Posto {
private:
	unsigned int numAutotanques;		/**< Número de Autotanques neste Posto dos Bombeiros */
	unsigned int numAmbulancias;;		/**< Número de Ambulancias neste Posto dos Bombeiros */
public:
	/**
	 * @brief Construtor da classe Bombeiros
	 * @param id - Numero de identificação do Posto
	 * @param local - Apontador para o local onde o posto se encontra
	 * @param numSocorristas - Número de Socorristas do Posto
	 * @param numAutotanques - Número de Autotanques do Posto
	 * @param numAmbulancias - Número de Ambulâncias do Posto
	 */
	Bombeiros(const unsigned int id, const Local* local, unsigned int numSocorristas, unsigned int numAutotanques, unsigned int numAmbulancias);

	/**
	 * @brief Destrutor da classe Bombeiros
	 */
	~Bombeiros();

	/**
	 * @brief Adiciona um certo número de autotanques ao posto em questão.
	 * @param num - Número de autotanques a adicionar.
	 */
	void addAutotanques(unsigned int num);

	/**
	 * @brief Adiciona um certo número de ambulâncias ao posto em questão.
	 * @param num - Número de ambulâncias a adicionar.
	 */
	void addAmbulancias(unsigned int num);

	/**
	 * @brief Remove, se possível, um certo número de autotanques do posto.
	 * @param num - Número de autotanques a remover.
	 * @return Retorna true caso seja possível remover o número indicado de autotanques, e retorna false caso contrário (número de autotanques atual é menor do que o número de autotanques a remover.).
	 */
	bool rmAutotanques(unsigned int num);

	/**
	 * @brief Remove, se possível, um certo número de ambulâncias do posto.
	 * @param num - Número de ambulâncias a remover.
	 * @return Retorna true caso seja possível remover o número indicado de ambulâncias, e retorna false caso contrário (número de ambulâncias atual é menor do que o número de ambulâncias a remover.).
	 */
	bool rmAmbulancias(unsigned int num);

	/**
	 * @brief Permite obter o número de autotanques presentes no posto
	 * @return Retorna o número de autotanques
	 */
	unsigned int getNumAutotanques() const;

	/**
	 * @brief Permite obter o número de ambulâncias presentes no posto
	 * @return Retorna o número de ambulâncias
	 */
	unsigned int getNumAmbulancias() const;

	/**
	 * @brief Permite obter o tipo deste posto
	 * @return Retorna "Bombeiros"
	 */
	std::string getTipoPosto() const;

	/**
	 * @brief Imprime no ecrã toda a informação sobre este posto dos Bombeiros
	 */
	void printInfoPosto() const;

	/**
	 * @brief Imprime numa stream o conteudo simplificado de um posto dos Bombeiros
	 * @param os - Stream para a qual o conteúdo do posto de Bombeiros é impresso
	 */
	void printSimplifiedInfo(std::ostream & os) const;
};

#endif /* BOMBEIROS_H_ */
