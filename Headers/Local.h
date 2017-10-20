#ifndef LOCAL_H_
#define LOCAL_H_
#include <string>

/**
 * Local para identificar espacialmente Postos e Acidentes
 */
class Local {
private:
	const std::string nome;				/**< Nome do local 															*/
	const unsigned int x_coord;			/**< Coordenada X do local, num referencial a começar num sudoeste do país	*/
	const unsigned int y_coord;			/**< Coordenada Y do local, num referencial a começar num sudoeste do país	*/
public:
	/**
	 * @brief Construtor da classe Local
	 * @param nome - Nome do local
	 * @param x_coord - Coordenada X do local
	 * @param y_coord - Coordenada Y do local
	 */
	Local(const std::string nome, unsigned int x_coord, unsigned int y_coord);

	/**
	 * @brief Destrutor da classe Local
	 */
	~Local();

	/**
	 * @brief Permite obter o nome do Local
	 * @return Retorna o nome do Local
	 */
	const std::string getNome() const;

	/**
	 * @brief Permite obter a coordenada X do Local (Abcissa)
	 * @return Retorna a coordenada X do local (Abcissa)
	 */
	const unsigned int getXcoord() const;

	/**
	 * @brief Permite obter a coordenada Y do Local (Ordenada)
	 * @return Retorna a coordenada Y do local (Ordenada)
	 */
	const unsigned int getYcoord() const;
};

#endif /* LOCAL_H_ */
