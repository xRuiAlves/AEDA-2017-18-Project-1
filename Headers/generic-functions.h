#ifndef GENERIC_FUNCTIONS_H_
#define GENERIC_FUNCTIONS_H_

/**
 * @param min - O valor mínimo que o utilizador pode introduzir.
 * @param max - O valor máximo que o utilizador pode introduzir.
 * @brief Recebe do utilizador um número no intervalo [min,max]. Se o utilizador introduzir um número fora do intervalo / input errado, lança um exceção (objeto Erro).
 * @return Retorna o numero que o utilizador introduziu, se o número estiver dentro do intrevalo / se não tiver ocorrido erro de input.
 */
int getOption(int min, int max);

/**
 * @param protecaoCivil - O objeto protecaoCivil com o qual se está a trabalhar.
 * @brief Permite ao utilizador declarar um acidente que tenha decorrido, bem como todas as suas especificações.
 */
void declararOcorrencia(ProtecaoCivil &protecaoCivil);

/**
 * @param protecaoCivil - O objeto protecaoCivil com o qual se está a trabalhar.
 * @brief Permite ao utilizador dar por terminada um ocorrência que esteja em decurso.
 */
void terminarOcorrencia(ProtecaoCivil &protecaoCivil);

/**
 * @param protecaoCivil - O objeto protecaoCivil com o qual se está a trabalhar.
 * @brief Permite ao utilizador pesquisar sobre as várias ocorrências em aberto, utilizando diversos critérios de procura diferentes.
 */
void infoOcorrencia(ProtecaoCivil &protecaoCivil);

/**
 * @param protecaoCivil - O objeto protecaoCivil com o qual se está a trabalhar.
 * @brief Permite ao utilizador pesquisar sobre os vários postos da Proteção Civil, utilizando diversos critério de procura diferentes.
 */
void pesquisarPostos(ProtecaoCivil &protecaoCivil);

/**
 * @param p1 - Apontador para um posto genérico.
 * @param p2 - Apontador para um posto genérico.
 * @brief Permite comparar dois postos pelo local (ordem alfabética) em que estão. Esta função é utilizada com "função auxiliar" em algorítmos de ordenação.
 * @return Retorna true se o local do posto p1 for menor que o local do posto p2 (ordem alfabética) e false caso contrário.
 */
bool compararPostosLocal(Posto* p1, Posto* p2);

/**
 * @param p1 - Apontador para um posto genérico.
 * @param p2 - Apontador para um posto genérico.
 * @brief Permite comparar dois postos pelo tipo de posto (ordem alfabética). Esta função é utilizada com "função auxiliar" em algorítmos de ordenação.
 * @return Retorna true se o tipo de posto p1 for menor que o tipo de posto p2 (ordem alfabética) e false caso contrário.
 */
bool compararPostosTipo(Posto* p1, Posto* p2);


bool compararAcidentesLocal(Acidente* a1, Acidente* a2);
bool compararAcidentesTipo(Acidente* a1, Acidente* a2);
bool compararAcidentesData(Acidente* a1, Acidente* a2);
void printMainMenu();
void printPesquisarPostosMenu();
void printInfoOcorrenciasMenu();
void printHeader(const std::string &header);
std::string lerData();
void pause();



#endif /* GENERIC_FUNCTIONS_H_ */
