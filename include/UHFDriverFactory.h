#ifndef UHFDRIVERFACTORY_H
#define UHFDRIVERFACTORY_H

#include "UHFDriver.h"
#include "UHFDevice1.h"
#include "DummyDevice.h"
namespace UHF
{
	/*
	@brief Register the Device Name here.
	*/
	enum class DeviceName { DUMMY_DEVICE=0};	
	
	/**
	* @brief MakeDriverInstance creates the instance of the input parameter.
	* @Param name_of_uhf_device Name of device for which instance is to be created.
	* @retval std::shared_ptr<UHFDriver>
	*/
	std::shared_ptr<UHF::UHFDriver> MakeDriverInstance(UHF::DeviceName name_of_uhf_device);
};
#endif  UHFDRIVERFACTORY_H


