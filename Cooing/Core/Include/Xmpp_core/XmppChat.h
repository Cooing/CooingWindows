#ifndef _XMPP_CLIENT
#define _XMPP_CLIENT

#include "gloox/messagesessionhandler.h"
#include "gloox/messageeventhandler.h"
#include "gloox/messageeventfilter.h"
#include "gloox/chatstatehandler.h"
#include "gloox/chatstatefilter.h"
#include "gloox/disco.h"
#include "gloox/lastactivity.h"
#include "gloox/logsink.h"
#include "gloox/connectiontcpclient.h"
#include "gloox/connectionsocks5proxy.h"
#include "gloox/connectionhttpproxy.h"
#include "gloox/messagehandler.h"
#include "gloox/rostermanager.h"
#include "gloox/presence.h"

#include "MessageFrame.h"
#include "XmppChatAdapter.h"

#include "XmppGeneralChat.h"

#include <stdio.h>
#include <iostream>
#include <windows.h> // WinApi header#include <windows.h> // WinApi header
using namespace std;
// using namespace gloox;

namespace SecureChat {
	class XmppChat:public XmppGeneralChat, gloox::RosterListener, gloox::MessageSessionHandler,
		gloox::MessageEventHandler, gloox::MessageHandler, gloox::ChatStateHandler {

			// XmppChatAdapter *adapter;

			gloox::MessageSession *m_session;
			gloox::MessageEventFilter *m_messageEventFilter;
			gloox::ChatStateFilter *m_chatStateFilter;

			string msgSent;

			map<string, string> friendList;
	public:
		map<string, string> GetFriendList() {return friendList;};

		XmppChat() : XmppGeneralChat(), m_session( 0 ), m_messageEventFilter( 0 ), m_chatStateFilter( 0 ) {adapter = NULL;}

		// void SetXmppAdapter(XmppChatAdapter *adapter) {this->adapter = (XmppGeneralChatAdapter *)adapter;}

		void start();
		void start(string host, string server, string username, string password);

		gloox::MessageSession* newSession( const gloox::JID& to );

		string Encrypt(string input);
		string Decrypt(string input);
		void SendMsg(string host, string toJid, string msg);

		void disconnect();

		void SendSubscriptionRequest(string jid);

		// ============= message session =====================
		virtual void handleMessageSession( gloox::MessageSession* session );
		virtual void handleMessage( const gloox::Message& msg, gloox::MessageSession * /*session*/ );
		virtual void handleMessageEvent( const gloox::JID& from, gloox::MessageEventType event );
		virtual void handleChatState( const gloox::JID& from, gloox::ChatStateType state );

		// ================= roster ==========================
		virtual void handleRoster( const gloox::Roster& roster );
		virtual void handleItemAdded( const gloox::JID& jid );
		virtual void handleItemSubscribed( const gloox::JID& jid );
		virtual void handleItemRemoved( const gloox::JID& jid );
		virtual void handleItemUpdated( const gloox::JID& jid );
		virtual void handleItemUnsubscribed( const gloox::JID& jid );
		virtual void handleRosterPresence( const gloox::RosterItem& item, const std::string& resource,
			gloox::Presence::PresenceType presence, const std::string& msg );
		virtual void handleSelfPresence( const gloox::RosterItem& item, const std::string& resource,
			gloox::Presence::PresenceType presence, const std::string& msg );
		virtual bool handleSubscriptionRequest( const gloox::JID& jid, const std::string& msg );
		virtual bool handleUnsubscriptionRequest( const gloox::JID& jid, const std::string& msg );
		virtual void handleNonrosterPresence( const gloox::Presence& presence );
		virtual void handleRosterError( const gloox::IQ& iq );
	};
}

#endif