#ifndef _XMPP_GENERAL_CHAT
#define _XMPP_GENERAL_CHAT

#include "gloox/gloox.h"
#include "gloox/connectionlistener.h"
#include "gloox/loghandler.h"
#include "gloox/client.h"
#include "gloox/message.h"

#include "XmppGeneralChatAdapter.h"

using namespace std;

namespace SecureChat 
{
	class XmppGeneralChat : public gloox::ConnectionListener, gloox::LogHandler
	{
	protected:
		bool isConnected;
		bool loginOK;
		gloox::Client *m_client;
		XmppGeneralChatAdapter *adapter;
	public:
		XmppGeneralChat();

		void SetXmppAdapter(XmppGeneralChatAdapter *adapter) {this->adapter = adapter;}

		bool GetConnected();
		bool GetLoginOK();

		void Disconnect(){m_client->disconnect();};

		virtual void onConnect();
		virtual void onDisconnect( gloox::ConnectionError e );
		virtual bool onTLSConnect( const gloox::CertInfo& info );
		virtual void handleLog( gloox::LogLevel level, gloox::LogArea area, const std::string& message );
	};
}

#endif