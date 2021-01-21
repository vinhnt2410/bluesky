#include <iostream>
#include <memory>
#include "smart_pointer.hpp"

typedef std::shared_ptr< Descriptor > sp_descriptor_t;

void ProcessTCPDescriptor(sp_descriptor_t aDescriptor);

int main()
{
	sp_descriptor_t spDescriptor = nullptr;

	spDescriptor = std::make_shared< TCPDescriptor >(5);
	// spDescriptor.printDes();
	ProcessTCPDescriptor(spDescriptor);

}

void ProcessTCPDescriptor(sp_descriptor_t aDescriptor)
{
	std::shared_ptr< TCPDescriptor > lTCPDescriptor = std::dynamic_pointer_cast<TCPDescriptor>(aDescriptor);
	lTCPDescriptor->printDes();
}