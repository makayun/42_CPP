#include <iostream>

class test
{
	private:
		std::string name;

	public:
		test() : name("bububu") {};
		~test() {};
		virtual std::string getName(void) {return name;};
};

typedef struct s_blast : test {} blast;

class best : test {};

typedef struct s_last : blast, best {} last;

int main()
{
	last bbb;

	std::cout << bbb.getName() << std::endl;
}
