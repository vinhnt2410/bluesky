#include <iostream>
#include <memory>

class Descriptor
{
	// int type;
public:
	Descriptor() {};
	virtual void printDes() {};
	virtual ~Descriptor() {};
};

class TCPDescriptor: public Descriptor
{
	int type;
public:
	TCPDescriptor() {};
	TCPDescriptor(int aType) : type(aType) {
		std::cout << "TCPDescriptor constructor: type = " << type << std::endl;
	};
	~TCPDescriptor() {};

	// TCPDescriptor& operator=(TCPDescriptor& t)
	// {
	// 	*static_cast<TCPDescriptor*>(this) = t;
	// 	return *this;
	// };
	void printDes() {
		std::cout << "TCPDescriptor type = " << type << std::endl;
	};
};