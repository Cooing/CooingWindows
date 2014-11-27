#ifndef _XMPP_CHAT_ADAPTER
#define _XMPP_CHAT_ADAPTER

//#include <stdio.h>
//#include <string>
//using namespace std;

#include "XmppGeneralChatAdapter.h"

namespace SecureChat
{
	class XmppChatAdapter  : XmppGeneralChatAdapter
	{
	public:
		XmppChatAdapter(){};
		~XmppChatAdapter(){};

		// ========= HANDLE execution =========
		virtual void ReceiveMsgHandle(string msg, string from) {};
		virtual void ChangeStatusHandle(string jid, int status) {};

		// --------- subscription (friend request) -----------
		virtual void ItemSubcribedHandle(string jid) {};
		virtual void ItemUnsubcribedHandle(string jid) {};
		virtual bool SubscriptionRequestHandle(string jid) {return false;};
	};
}
#endif