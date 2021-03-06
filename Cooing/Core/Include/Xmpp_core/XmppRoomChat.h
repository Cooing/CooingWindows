#ifndef _XMPP_ROOM
#define _XMPP_ROOM

#include "gloox/mucroomhandler.h"
#include "gloox/mucroom.h"

#include "XmppGeneralChat.h"
#include "XmppRoomChatAdapter.h"

namespace SecureChat
{
	class XmppRoomChat : public XmppGeneralChat, gloox::MUCRoomHandler
	{
	private:
		gloox::MUCRoom *m_room;
	public:
		XmppRoomChat() : XmppGeneralChat(){};
		void StartRoom(string server, string host, string username, string  password, string roomID);
		virtual void onConnect();

		void SendMsg(string s);

		virtual void handleMUCParticipantPresence( gloox::MUCRoom* room, const gloox::MUCRoomParticipant participant,
			const gloox::Presence& presence );
		virtual void handleMUCMessage( gloox::MUCRoom* room, const gloox::Message& msg, bool priv );
		virtual bool handleMUCRoomCreation( gloox::MUCRoom* room );
		virtual void handleMUCSubject( gloox::MUCRoom* room, const std::string& nick,
			const std::string& subject );
		virtual void handleMUCInviteDecline( gloox::MUCRoom* room, const gloox::JID& invitee,
			const std::string& reason );
		virtual void handleMUCError( gloox::MUCRoom* room, gloox::StanzaError error );
		virtual void handleMUCInfo( gloox::MUCRoom* room, int features, const std::string& name,
			const gloox::DataForm* infoForm );
		virtual void handleMUCItems( gloox::MUCRoom* room, const gloox::Disco::ItemList& items );
	};
}

#endif