#ifndef _BRIDGE_H_
#define _BRIDGE_H_
using namespace std;

// Implementor
class IPaymentSystem
{
public:
	virtual void ProcessPayment(string paymentSystem) = 0;
	~IPaymentSystem() {};
};

// ConcreteImplementor
class CityPaymentSystem :public IPaymentSystem
{
public:
	virtual void ProcessPayment(string paymentSystem)
	{
		std::cout << "using Citybank gateway for " << paymentSystem << std::endl;
	}
};
class IDBAPaymentSystem :public IPaymentSystem
{
public:
	virtual void ProcessPayment(string paymentSystem)
	{
		std::cout << "using IDBA gateway for " << paymentSystem << std::endl;
	}
};
// Abstraction
class Payment
{
public:
	IPaymentSystem* m_Ipayment;
public:
	virtual void MakePayment() = 0;
	~Payment() { delete m_Ipayment; }
};

// RefinedAbstraction
class CardPayment :public Payment
{
public:
	virtual void MakePayment()
	{
		m_Ipayment->ProcessPayment("Card Payment");
	}
};
class NetBankPayment :public Payment
{
public:
	virtual void MakePayment()
	{
		m_Ipayment->ProcessPayment("NetBank Payment");
	}
};

// 分别往两个维度的变化，可进行排列组合的情况下，一个维度是抽象的维度，另一个是具体实施的维度。


// 完成 一件事 需要抽象的几个步骤，具体有多种实现方式和组合方式

// 买东西 抽象 ： 去  买 回
// 抽象的refined省钱    
// 抽象的费钱模式

// WaysOfRunning go  and back
// WaysOfPayment
//  打车去 打车回 现金支付
// 走路去 走路回  用花呗支付




#endif // !_BRIDGE_H_



