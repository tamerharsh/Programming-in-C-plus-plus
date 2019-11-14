#include "UHFDriver.h"

/**
	* @brief DummyDevice class is the Derived class which defines the various functionality related to DummyDevice Specific.
*/
class DummyDevice :public UHF::UHFDriver
{
public:

	/**
		* @brief ReadAllTags function reads all the tags present in the range.
		* @retval std::string
	*/
		std::vector<std::string>ReadAllTags()const;
	/**
		* @brief ReadSpecificTag function reads specifies tag.
		* @retval std::string
	*/
		 std::string ReadSpecificTag(int);

	/**
		* @brief WriteToTag function writes data on a specified tag.
		* @Param int : tag number.
		* @Param std::string : data to be written on the specified tag.
		* @retval std::string
	*/
		std::string WriteToTag(int&, std::string&);

	/**
		* @brief ReadDiagnostics function reads the diagonitics related to device such as NO_ERROR CONFIGURATION_ERROR etc.
		* @retval std::string
	*/
		std::string	ReadDiagnostics()const;

	/**
		* @brief Connect function connects the device using its dedicated protocol.
		* @Param std::string : IP Address.
		* @Param int : Port.
		* @retval bool
	*/
		bool Connect(std::string, int);

	/**
		* @brief Disconnect function disconnects the connection using its dedicated protocol.
		* @retval std::string
	*/
		std::string	Disconnect()const;

	/**
		* @brief Configuration function sets the configuration for the UHF device.
		* @param json : Configuration Parameters in JSON file format.
		* @retval std::string
	*/
		std::string Configuration(UHF::json &input) ;

	/**
		* @brief  IsConnected function test the connectivity of the device;
	*/
		 bool IsConnected();	

	private:

	std::vector<std::string>list_of_diagonsis{}, list_of_tags{};
	int tag_number{};
	std::string IP;
	int port;
};
