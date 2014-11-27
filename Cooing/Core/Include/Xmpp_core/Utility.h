#ifndef _UTILITY
#define _UTILITY

#include <vector>

#include "HTTPRequestProvider/HTTP_Request.h"
#include "User.h"

class Utility
{
private:
	string server;
	string port;

public:
	Utility(string _server = "localhost", string _port = "8008")
	{
		server = _server;
		port = _port;
	}

	vector<User *> GetContactList(string searchUser)
	{
		vector<User *> users;

		string request = "http://" + server + ":" + port + "/XMPP.Server/api/users/search/" + searchUser;
		HTTP_Response *response = HTTP_Request::Get(request);

		Document *document = new Document();

		if (document->Parse(response->GetBody().c_str()).HasParseError()) {
			// Fail
		}

		const Value& data = (*document)["data"]; 
		int len = data.Size();
		for (SizeType i = 0; i < len; i++) 
			users.push_back(new User(data[i]["username"].GetString(), 
				(data[i]["name"].IsString() == NULL) ? "" : data[i]["name"].GetString(), 
				(data[i]["email"].IsString() == NULL) ? "" : data[i]["email"].GetString()));

		return users;
	}
};

#endif