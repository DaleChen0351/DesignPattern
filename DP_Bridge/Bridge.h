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
class Payment // �����ǲ�����ֱ�����ɶ���ģ�ֻ�����ɻ���ָ��
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
	// ���������ļ̳е��ȣ�// 
	~CardPayment(){}  // ������������������Զ����û������������


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

// �ֱ�������ά�ȵı仯���ɽ���������ϵ�����£�һ��ά���ǳ����ά�ȣ���һ���Ǿ���ʵʩ��ά�ȡ�


// ��� һ���� ��Ҫ����ļ������裬�����ж���ʵ�ַ�ʽ����Ϸ�ʽ

// netbank dtor
//base ipayment
//citybank
// base ipaymentsystem


#endif // !_BRIDGE_H_



