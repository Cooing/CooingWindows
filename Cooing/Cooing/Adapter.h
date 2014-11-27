#ifndef _ADAPTER
#define _ADAPTER

// #include "Global.h"
#include "Xmpp_core/XmppChatProcess.h"

#include <qobject.h>

class Adapter : public QObject, public SecureChat::XmppChatAdapter{
Q_OBJECT

public:
	virtual void ReceiveMsgHandle(string msg, string from);

	virtual void ChangeStatusHandle(string jid, int status) {
	}

	virtual void ItemSubcribedHandle(string jid) {
	}

	virtual void ItemUnsubcribedHandle(string jid) {
	}

	virtual bool SubscriptionRequestHandle(string jid) {
		return true;
	}

signals:
	void ReceiveMsgSignal(QString msg, QString from);
};

#endif