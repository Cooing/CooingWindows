#include "Global.h"
#include <QtWidgets/QApplication>

bool isLoggedIn = false;

Cooing *Global::mainForm = NULL;
SignIn *Global::signinForm = NULL;
Register *Global::registerForm = NULL;
UploadAvatar *Global::uploadavatarForm = NULL;
ForgotPassword *Global::forgotpasswordForm = NULL;
BrowseAvatar *Global::browseavatarForm = NULL;

string Global::server = ""; //"192.168.10.110";
string Global::host = "localhost";
SecureChat::XmppChatProcess *Global::chat = NULL;
Adapter *Global::adapter = NULL;

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	isLoggedIn = true;
	if (isLoggedIn) {
		Global::mainForm = new Cooing();
		Global::mainForm->show();
	}
	else {
		Global::signinForm = new SignIn();
		Global::signinForm->show();
	}

	return a.exec();
}
