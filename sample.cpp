#include "UHFDriverFactory.h"

int  main()
{
	std::shared_ptr<UHF::UHFDriver> sample_device = UHF::MakeDriverInstance(UHF::DeviceName::DUMMY_DEVICE);
	sample_device->IsConnected();
	std::cout<<sample_device->Connect("192.13.05.92", 5261);
	
	return 0;
}