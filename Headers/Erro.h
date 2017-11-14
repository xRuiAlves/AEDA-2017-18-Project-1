#ifndef ERRO_H_
#define ERRO_H_
#include <string>

/**
 * Classe Erro utilizada para tratamento de exceções no decorrer do programa.
 */
class Erro {
private:
	const std::string info;		/**< Informação do erro que ocorreu aquando uma exceção */
public:
	/**
	 * @brief Construtor da classe Erro
	 * @param info - Descrição do tipo de erro que aconteceu aquando o lancamento de uma exceção
	 */
	Erro(const std::string &info) : info(info) {}

	/**
	 * @brief Permite obter a descrição do Erro
	 * @return Retorna a descrição do Erro
	 */
	const std::string getInfo() const { return info; }
};



/**
 * Classe utilizada para lançar exceções do tipo Data Inválida
 */
class DataInvalida : public Erro {
public:
	/**
	 * @brief Construtor da classe DataInvalida
	 */
	DataInvalida(const std::string &info) : Erro(info) { }
};



/**
 * Classe utilizada para lançar exceções do tipo Localidade Inexistente
 */
class LocalidadeInexistente : public Erro {
public:
	/**
	 * @brief Construtor da classe LocalidadeInexistente
	 */
	LocalidadeInexistente(const std::string &info) : Erro(info) { }
};



/**
 * Classe utilizada para lançar exceções do tipo Input Inválido
 */
class InputInvalido : public Erro {
public:
	/**
	 * @brief Construtor da classe InputInvalido
	 */
	InputInvalido(const std::string &info) : Erro(info) { }
};



/**
 * Classe utilizada para lançar exceções do tipo Tipo de Acidente Inválido
 */
class TipoAcidenteInvalido : public Erro {
public:
	/**
	 * @brief Construtor da classe TipoAcidenteInvalido
	 */
	TipoAcidenteInvalido(const std::string &info) : Erro(info) { }
};



/**
 * Classe utilizada para lançar exceções do tipo Tipo de Casa Invalido
 */
class TipoCasaInvalido : public Erro {
public:
	/**
	 * @brief Construtor da classe TipoCasaInvalido
	 */
	TipoCasaInvalido(const std::string &info) : Erro(info) { }
};



/**
 * Classe utilizada para lançar exceções do tipo Ficheiro não Encontrado
 */
class FicheiroNaoEncontrado : public Erro {
public:
	/**
	 * @brief Construtor da classe FicheiroNaoEncontrado
	 */
	FicheiroNaoEncontrado(const std::string &info) : Erro(info) { }
};



/**
 * Classe utilizada para lançar exceções do tipo Meios Insuficientes
 */
class MeiosInsuficientes : public Erro {
public:
	/**
	 * @brief Construtor da classe MeiosInsuficientes
	 */
	MeiosInsuficientes(const std::string &info) : Erro(info) { }
};



/**
 * Classe utilizada para lançar exceções do tipo Meios Inexistentes
 */
class MeiosInexistentes : public Erro {
public:
	/**
	 * @brief Construtor da classe MeiosInexistentes
	 */
	MeiosInexistentes(const std::string &info) : Erro(info) { }
};

#endif /* ERRO_H_ */
