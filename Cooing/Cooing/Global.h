#ifndef GLOBAL_H
#define GLOBAL_H

#include "SignIn.h"
#include "Cooing.h"
#include "Register.h"
#include "UploadAvatar.h"
#include "ForgotPassword.h"
#include "BrowseAvatar.h"
#include "Xmpp_core/XmppChatProcess.h"
#include "Adapter.h"

class Global {
	public:
		static SignIn *signinForm;
		static Cooing *mainForm;
		static Register *registerForm;
		static UploadAvatar *uploadavatarForm;
		static BrowseAvatar *browseavatarForm;
		static ForgotPassword *forgotpasswordForm;

		static string server;
		static string host; 
		static SecureChat::XmppChatProcess *chat;
		static Adapter *adapter;
};

#endif // GLOBAL_H
