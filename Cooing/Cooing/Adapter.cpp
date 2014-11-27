#include "Global.h"

void Adapter::ReceiveMsgHandle(string msg, string from)
{
	// Global::mainForm->receiveMessage(msg, from);
	emit ReceiveMsgSignal(QString(msg.c_str()), QString(from.c_str()));
}