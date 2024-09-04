#include "Serializer.hpp"

int main(void)
{
	Data test;

	test._data = 55;
	uintptr_t res = Serializer::serialize(&test);
	std::cout << res << std::endl;
	Data *finishedData = Serializer::deserialize(res);
	std::cout << finishedData->_data << std::endl;

}
