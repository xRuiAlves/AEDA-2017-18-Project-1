#ifndef ASSALTO_H_
#define ASSALTO_H_
#include <string>
#include "Acidente.h"

/**
 * Acidente do tipo Assalto. Classe derivada da classe Acidente.
 */
class Assalto : public Acidente {
private:
	const std::string tipoCasa;			/**< Tipo de casa em que decorreu o Assalto. Pode ser "Particular" ou "Comercial" */
	const bool haferidos;				/**< Indica se houve feridos neste Assalto. Se sim, é necessária a ação de uma Ambulância */
public:
	/**
	 * @brief Construtor da classe Assalto
	 * @param data - Data da ocorrência no formato DD-MM-AAAA
	 * @param local - Apontador para o local onde teve lugar o acidente
	 * @param numOcorrencia - Numero atribuído à ocorrência
	 * @param tipoCasa - Tipo de casa em que decorreu o Assalto
	 * @param haferidos - Indica se houve ou não feridos no decurso do Assalto
	 */
	Assalto(const std::string &data, const Local* local, unsigned int numOcorrencia, const std::string &tipoCasa, bool haferidos);

	/**
	 * @brief Destrutor da classe Assalto
	 */
	~Assalto();

	/**
	 * @brief Permite obter o tipo de casa em que decorreu o Assalto. Pode ser "Particular" ou "Comercial"
	 * @return Retorna "Particular" ou "Comercial", consoante o tipo de casa em que decorreu o Assalto
	 */
	const std::string getTipoCasa() const;

	/**
	 * @brief Permite obter informação quanto à existência de feridos no Assalto
	 * @return Retorna true caso haja feridos e false caso contrário
	 */
	bool haFeridos() const;

	/**
	 * @brief Permite obter o tipo de acidente em questão.
	 * @return Retorna "Assalto"
	 */
	std::string getTipoAcidente() const;

	/**
	 * @brief Imprime no ecrã toda a informação relativa a este Assalto.
	 */
	void printInfoAcidente() const;

	/**
	 * @brief Imprime numa stream o conteudo simplificado de um Assalto
	 * @param os - Stream para a qual o conteúdo do Assalto é impresso
	 */
	void printSimplifiedInfo(std::ostream & os) const;
};

#endif /* ASSALTO_H_ */
