#ifndef _XMPP_ROOM_CHAT_ADAPTER
#define _XMPP_ROOM_CHAT_ADAPTER

#include "XmppGeneralChatAdapter.h"

namespace SecureChat
{
	class XmppRoomChatAdapter : public XmppGeneralChatAdapter
	{
	public:
		XmppRoomChatAdapter(){};
		~XmppRoomChatAdapter(){};

		virtual void handleMUCParticipantPresence(string jid, int status, int other) {};
		virtual void handleMUCMessage(string from, string msg, bool history, bool priv) {};
		virtual void handleMUCRoomCreation(string roomID) {};
	};
}

#endif