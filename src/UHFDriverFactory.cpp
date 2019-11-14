#include "UHFDriverFactory.h"

std::shared_ptr<UHF::UHFDriver> UHF::MakeDriverInstance(UHF::DeviceName name_of_uhf_device)
{
	switch (name_of_uhf_device)
	{
	case UHF::DeviceName::DUMMY_DEVICE: return std::make_shared <DummyDevice>();
	default: return nullptr;
	}
}
