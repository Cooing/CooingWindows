#ifndef _XMPP_ROOM_CHAT_PROCESS
#define _XMPP_ROOM_CHAT_PROCESS

#include <iostream>

#include "XmppGeneralChatProcess.h"
#include "XmppRoomChat.h"

namespace SecureChat
{
	class XmppRoomChatProcess : public XmppGeneralChatProcess
	{
	private:
		string roomID;
	public:
		XmppRoomChatProcess();
		XmppRoomChatProcess(string server, string host, string username, string password, string roomID);
		void RoomChatThreadConnect();
		bool StartRoomChat();
		void SendRoomMsg(string msg);
	};
}

#endif