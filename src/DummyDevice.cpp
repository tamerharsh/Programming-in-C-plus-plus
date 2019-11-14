#include "DummyDevice.h"

std::vector<std::string> DummyDevice::ReadAllTags() const
{
	return std::vector<std::string>();
}

std::string DummyDevice::ReadSpecificTag(int)
{
	return std::string();
}

std::string DummyDevice::WriteToTag(int &, std::string &)
{
	return std::string();
}

std::string DummyDevice::ReadDiagnostics() const
{
	return std::string();
}

bool DummyDevice::Connect(std::string ip_, int port_)
{
	IP = ip_;
	port = port_;
	return true;
}

std::string DummyDevice::Disconnect() const
{
	return std::string();
}

std::string DummyDevice::Configuration(UHF::json & input)
{
	return std::string();
}

bool DummyDevice::IsConnected()
{
	return false;
}
