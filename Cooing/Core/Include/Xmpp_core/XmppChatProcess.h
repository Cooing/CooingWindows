#ifndef _XMPP_CHAT_PROCESS
#define _XMPP_CHAT_PROCESS

#include <windows.h>
#include <memory>

#include "XmppGeneralChatProcess.h"
#include "XmppChat.h"

namespace SecureChat
{
	class XmppChatProcess : public XmppGeneralChatProcess
	{
	public:
		XmppChatProcess();

		void ThreadConnect();
		bool Login(string server, string host, string username, string password);
		void Logout();

		void SendMsg(string toJid, string msg);

		map<string, string> GetFriendList();

		void SendFriendRequest(string jid);
	};
}

#endif _XMPP_CHAT_PROCESS