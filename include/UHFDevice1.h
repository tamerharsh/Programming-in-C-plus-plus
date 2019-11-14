#include "UHFDriver.h"

class UHFDevice1:public UHF::UHFDriver
{
public :
bool IsConnected();
bool Disconnect();
void hello();
};
