#include "Serializer.hpp"
#include <iostream>

int	main(void)
{
	Data		data;
	uintptr_t	raw;
	Data		*ptr;

	data.id = 42;
	data.name = "hkonte";
	raw = Serializer::serialize(&data);
	ptr = Serializer::deserialize(raw);
	std::cout << "original address: " << &data << std::endl;
	std::cout << "serialized value:  " << raw << std::endl;
	std::cout << "deserialized addr: " << ptr << std::endl;
	if (ptr == &data)
		std::cout << "pointers are equal" << std::endl;
	else
		std::cout << "pointers are different" << std::endl;
	std::cout << "id: " << ptr->id << ", name: " << ptr->name << std::endl;
	return (0);
}
