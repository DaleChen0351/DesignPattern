#ifndef _BRIDGE_H_
#define _BRIDGE_H_
using namespace std;
class Messager {
public:
	// 业务逻辑层面可能出现的变化
	virtual void Login(string username, string password) = 0;
	virtual void SendMessage(string message) = 0;
	virtual void SendPicture( ) = 0;
	// 平台逻辑层面可能出现的变化
	virtual void PlaySound() = 0;
	virtual void DrawShape() = 0;
	virtual void WriteText() = 0;
	virtual void Connect() = 0;

	virtual ~Messager() {}
};


//平台实现
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


//业务抽象
// 轻量级
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

// 完全版 
class PCMessagerPerfect : public PCMessagerBase {
public:

	virtual void Login(string username, string password) {

		PCMessagerBase::PlaySound(); // 完全版 增加了播放声音
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
	//编译时装配
	Messager *m =
		new MobileMessagerPerfect();
}



#endif // !_BRIDGE_H_



