#ifndef LOCAL_H_
#define LOCAL_H_
#include <string>

class Local {
private:
	const std::string nome;
	const unsigned int x_coord;
	const unsigned int y_coord;
public:
	Local(const std::string nome, unsigned int x_coord, unsigned int y_coord);
	~Local();
	const std::string getNome() const;
	const unsigned int getXcoord() const;
	const unsigned int getYcoord() const;
};

#endif /* LOCAL_H_ */
