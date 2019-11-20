#ifndef _BRIDGE_H_
#define _BRIDGE_H_
using namespace std;

// Implementor
class IPaymentSystem
{
public:
	virtual void ProcessPayment(string paymentSystem) = 0;
	virtual ~IPaymentSystem() {  
		std::cout << "base IPaymentSystem dtor" << std::endl;
	};
};


// ConcreteImplementor
class CityPaymentSystem :public IPaymentSystem
{
public:
	virtual void ProcessPayment(string paymentSystem) override
	{
		std::cout << "using Citybank gateway for " << paymentSystem << std::endl;
	}
	~CityPaymentSystem()
	{
		std::cout << "CityPaymentSystem dtor" << std::endl;
	}
};
class IDBAPaymentSystem :public IPaymentSystem
{
public:
	virtual void ProcessPayment(string paymentSystem) override
	{
		std::cout << "using IDBA gateway for " << paymentSystem << std::endl;
	}
};
// Abstraction
class Payment // 基类是不可以直接生成对象的，只能生成基类指针
{
protected:
	IPaymentSystem* m_Ipayment; 
public:
	Payment(IPaymentSystem* Ipayment) : m_Ipayment(Ipayment) {};
	virtual void MakePayment() = 0;
	virtual ~Payment() {
		std::cout << "base Payment dtor" << std::endl;
		if(m_Ipayment!=nullptr)
		delete m_Ipayment; 
	}
};

// RefinedAbstraction
class CardPayment :public Payment
{
public:
	CardPayment(IPaymentSystem* Ipayment) :Payment(Ipayment) {}
	virtual void MakePayment() override
	{
		m_Ipayment->ProcessPayment("Card Payment");
	}
	// 析构函数的继承调度？// 
	~CardPayment(){}  // 派生类的析构函数后自动调用基类的析构函数


};
class NetBankPayment :public Payment
{
public:
	NetBankPayment(IPaymentSystem *Ipayment) : Payment(Ipayment) {};
	virtual void MakePayment() override
	{
		m_Ipayment->ProcessPayment("NetBank Payment");
	}
	~NetBankPayment()
	{
		std::cout << "NetBankPayment dtor" << std::endl;
	}
};

// 分别往两个维度的变化，可进行排列组合的情况下，一个维度是抽象的维度，另一个是具体实施的维度。


// 完成 一件事 需要抽象的几个步骤，具体有多种实现方式和组合方式

// netbank dtor
//base ipayment
//citybank
// base ipaymentsystem


#endif // !_BRIDGE_H_



