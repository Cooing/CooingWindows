#include "ZUC.h"
#include <string>
using namespace std;

class MessageFrame {
	private:
		static byte ConstArray[8];
	public:
		static string Pack(byte *messageArray, long long mLength);
		static string unPack(byte *messageArray, long long mLength);
};
