typedef unsigned char byte;
typedef unsigned int u32;

class ZUC {
	private:
		u32 S[17];
		u32 R[2];
		u32 X[4];
		byte *Sbox_0;
		byte *Sbox_1;
		byte *DefaultKey;
		u32 *ConstArray;
		void LFSR_InitMode(u32 u);
		void LFSR_WorkMode();
		void BR();
		u32 L1(u32 X);
		u32 L2(u32 X);
		u32 F();
		void Init(byte *Key);
		u32* GenerateKeyStream(byte *Key, long long kLength);
		u32* GenerateKeyStream(long long kLength);
	public:
		ZUC();
		~ZUC();
		byte* Encrypt(byte* iMessage, long long &mLength);
		byte* Decrypt(byte* iMessage, long long &mLength);
		byte* Encrypt(byte* iMessage, byte *Key, long long &mLength);
		byte* Decrypt(byte* iMessage, byte *Key, long long &mLength);
		byte* Encrypt_BlockMode(byte* iMessage, long long &mLength);
		byte* Decrypt_BlockMode(byte* iMessage, long long &mLength);
		byte* Encrypt_BlockMode(byte* iMessage, byte *Key, long long &mLength);
		byte* Decrypt_BlockMode(byte* iMessage, byte *Key, long long &mLength);
};
