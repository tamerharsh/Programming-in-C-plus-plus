#ifndef UHFDRIVER_H
#define UHFDRIVER_H

#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <limits>
#include "json.hpp"
#include <memory>

namespace UHF
{
	using json = nlohmann::json;
	
	/**
		* @brief UHFDriver class is the Abstract class which defines the various functionality related to UHF-Devices.
	*/	
	class UHFDriver
	{
	public:
	/**
		* @brief ReadAllTags function reads all the tags present in the range.
		* @retval std::string
	*/
		virtual std::vector<std::string>ReadAllTags()const=0;

	/**
		* @brief ReadSpecificTag function reads specifies tag.
		* @retval std::string
	*/
		virtual std::string ReadSpecificTag(int)=0;		
	
	/**
		* @brief WriteToTag function writes data on a specified tag.
		* @Param int : tag number.
		* @Param std::string : data to be written on the specified tag.
		* @retval std::string
	*/
		virtual  std::string WriteToTag(int&,std::string&)=0;
	
	/**
		* @brief ReadDiagnostics function reads the diagonitics related to device such as NO_ERROR CONFIGURATION_ERROR etc.
		* @retval std::string
	*/
		virtual std::string	ReadDiagnostics()const=0;
			
	/**
		* @brief Connect function connects the device using its dedicated protocol.
		* @Param std::string : IP Address. 
		* @Param int : Port.
		* @retval std::string 
	*/
		virtual bool Connect(std::string, int)= 0;
		
	/**
		* @brief Disconnect function disconnects the connection using its dedicated protocol.
		* @retval std::string
	*/
		virtual std::string	Disconnect()const = 0;
		
	/**
		* @brief Configuration function sets the configuration for the UHF device.
		* @param json : Configuration Parameters in JSON file format.
		* @retval std::string
	*/
		virtual std::string Configuration(json&)= 0;

	/**
		* @brief  IsConnected function test the connectivity of the device;
	*/
		virtual bool IsConnected()=0;
	private:
		
	};
};

#endif UHFDRIVER_H

