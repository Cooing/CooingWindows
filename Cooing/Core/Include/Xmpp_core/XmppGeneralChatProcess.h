#ifndef _XMPP_GENERAL_CHAT_PROCESS
#define _XMPP_GENERAL_CHAT_PROCESS

#include <string>
using namespace std;

#include "XmppGeneralChatAdapter.h"
#include "XmppGeneralChat.h"

namespace SecureChat
{
	class MyThread;

	class XmppGeneralChatProcess
	{
	protected:
		string server, host, username, password;
		MyThread *thread_connect;
		XmppGeneralChatAdapter *adapter;
		XmppGeneralChat *generalChat;
	public:
		void Disconnect(){generalChat->Disconnect();};

		void SetXmppAdapter(XmppGeneralChatAdapter *_adapter) {
			adapter = _adapter;
			generalChat->SetXmppAdapter((XmppGeneralChatAdapter *)adapter);
		}
	};
}

#endif