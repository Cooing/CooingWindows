#ifndef _HTTP_RESPONSE
#define _HTTP_RESPONSE

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
#include <iostream>

#include <string.h>
using namespace std;
using namespace rapidjson;

class HTTP_Response
{
private:
	string status;
	string reason;
	string body;

public:
	HTTP_Response(){}
	HTTP_Response(string _status, string _reason, string _body){status = _status; reason = _reason; body = _body;}
	string GetStatus(){return status;}
	string GetReason(){return reason;}
	string GetBody(){return body;}
};

#endif