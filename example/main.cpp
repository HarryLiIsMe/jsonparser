#include <string>
#include <iostream>
#include <vector>
#include "jsonparser/jsonparser.hpp"

struct testA
{
	int a = 0;
	double b = 0;
	bool c = 0;
	std::vector<std::string> d;
};
REFLECTION(testA, a, b, c, d)

struct testB
{
	int a = 0;
	double b = 0;
	std::vector<testA> c;
	std::string d;
};
REFLECTION(testB, a, b, c, d)


int main(void)
{
	std::string jsonstr1 = R"({
		"a": 10,
		"b" : 10.1,
		"c" : [{
			"a": 20,
			"b" : 20.1,
			"c" : true,
			"d": ["test1","test2"]
 			},
			{
			"a": 10,
			"b" : 10.1,
			"c" : false,
			"d": ["test3","test4"]
			}] ,
		"d": "test"})";


	testB a;
	bool b = json_from_str(a, jsonstr1);
	std::cout << std::boolalpha << b << std::endl;
	std::cout << a.a << std::endl;
	std::cout << a.b << std::endl;
	for (auto it = a.c.begin(); it != a.c.end(); ++it)
	{
		std::cout << it->a << std::endl;
		std::cout << it->b << std::endl;
		std::cout << it->c << std::endl;
		for (auto it2 = it->d.begin(); it2 != it->d.end(); ++it2)
		{
			std::cout << *it2 << std::endl;
		}
	}
	std::cout << std::boolalpha << a.d << std::endl;
	std::string jsonstr2 = json_to_str(a);
	std::cout << jsonstr2 << std::endl;
	return 0;
}
