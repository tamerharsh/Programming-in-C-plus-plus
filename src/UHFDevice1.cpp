#include "UHFDevice1.h"

bool UHFDevice1::IsConnected()
{
std::cout<<"Device1 IsConnected Function ";
return true;
}

bool UHFDevice1::Disconnect()
{
	std::cout << "Device 1 Disconnect Fucntion ";
	return false;
}

void UHFDevice1::hello()
{
	std::cout << "hello FROM UHFDEVICE 1";
}
