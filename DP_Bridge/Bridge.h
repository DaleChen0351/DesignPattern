#ifndef _BRIDGE_H_
#define _BRIDGE_H_
using namespace std;
class Messager {
public:
	// ҵ���߼�������ܳ��ֵı仯
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture( ) = 0;
	// ƽ̨�߼�������ܳ��ֵı仯
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~Messager() {}
};


//ƽ̨ʵ��
class PCMessagerBase : public Messager {
public:

	virtual void PlaySound() {
		//**********
	}
	virtual void DrawShape() {
		//**********
	}
	virtual void WriteText() {
		//**********
	}
	virtual void Connect() {
		//**********
	}
};

class MobileMessagerBase : public Messager {
public:

	virtual void PlaySound() {
		//==========
	}
	virtual void DrawShape() {
		//==========
	}
	virtual void WriteText() {
		//==========
	}
	virtual void Connect() {
		//==========
	}
};


//ҵ�����
// ������
class PCMessagerLite {
	Messager * Messager;
public:
	
	virtual void Login(string username, string password) {

		Messager->Connect();
		//........
	}
	virtual void SendMessage(string message) {

		Messager->WriteText();
		//........
	}
	virtual void SendPicture( ) {

		Messager->DrawShape();
		//........
	}
};

class MobileMessagerLite  {
	Messager* Messager;
public:

	virtual void Login(string username, string password) {

		Messager->Connect();
		//........
	}
	virtual void SendMessage(string message) {

		Messager->WriteText();
		//........
	}
	virtual void SendPicture() {

		Messager->DrawShape();
		//........
	}
};

// ��ȫ�� 
class PCMessagerPerfect : public PCMessagerBase {
public:

	virtual void Login(string username, string password) {

		PCMessagerBase::PlaySound(); // ��ȫ�� �����˲�������
		//********
		PCMessagerBase::Connect();
		//........
	}
	virtual void SendMessage(string message) {

		PCMessagerBase::PlaySound();
		//********
		PCMessagerBase::WriteText();
		//........
	}
	virtual void SendPicture() {

		PCMessagerBase::PlaySound();
		//********
		PCMessagerBase::DrawShape();
		//........
	}
};





class MobileMessagerPerfect : public MobileMessagerBase {
public:

	virtual void Login(string username, string password) {

		MobileMessagerBase::PlaySound();
		//********
		MobileMessagerBase::Connect();
		//........
	}
	virtual void SendMessage(string message) {

		MobileMessagerBase::PlaySound();
		//********
		MobileMessagerBase::WriteText();
		//........
	}
	virtual void SendPicture() {

		MobileMessagerBase::PlaySound();
		//********
		MobileMessagerBase::DrawShape();
		//........
	}
};


void Process() {
	//����ʱװ��
	Messager *m =
		new MobileMessagerPerfect();
}



#endif // !_BRIDGE_H_



