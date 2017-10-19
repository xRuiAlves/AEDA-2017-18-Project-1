#ifndef DATE_H_
#define DATE_H_
#include <string>

/**
 * Classe Data utilizada para comparar datas de ocorrencias.
 */
class Date {
private:
	unsigned int dia;	/**< Dia referente à data. */
	unsigned int mes;	/**< Mês referente à data. */
	unsigned int ano;	/**< Ano referente à data. */
public:
	/**
	 * @brief Construtor da classe Date.
	 * @param date - string que representa a data no formato DD-MM-AAAA.
	 */
	Date(const std::string &date);

	/**
	 * @brief Permite obter o dia da data.
	 * @return Retorna o dia da data.
	 */
	unsigned int getDia() const;

	/**
	 * @brief Permite obter o mês data.
	 * @return Retorna o mês da data.
	 */
	unsigned int getMes() const;

	/**
	 * @brief Permite obter o ano da data.
	 * @return Retorna o ano da data.
	 */
	unsigned int getAno() const;

	/**
	 * @brief Permite obter a data num formato útil para comparar datas.
	 * @return Retorna a data em formato numérico AAAAMMDD, útil para comparar datas diretamente.
	 */
	unsigned int getCompleteData() const;

	/**
	 * @brief Permite obter a data num formato agradável para o utilizador.
	 * @return Retorna a data no formato DD-MM-AAAA.
	 */
	std::string getData() const;

	/**
	 * @brief Operador < para comparar datas.
	 * @param otherDate - uma outra data para comparar à data em questão.
	 * @return Retorna true caso a data em questão seja anterior à data a comparar, false caso contrário.
	 */
	bool operator<(const Date &otherDate) const;

	/**
	 * @brief Destrutor da classe Date.
	 */
	~Date();
};

#endif /* DATE_H_ */
