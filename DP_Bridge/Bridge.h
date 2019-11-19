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
class Payment // �����ǲ�����ֱ�����ɶ���ģ�ֻ�����ɻ���ָ��
{
protected:
	IPaymentSystem* m_Ipayment; 
public:
	Payment(IPaymentSystem* Ipayment) : m_Ipayment(Ipayment) {};
	virtual void MakePayment() = 0;
	~Payment() { delete m_Ipayment; }
};

// RefinedAbstraction
class CardPayment :public Payment
{
public:
	CardPayment(IPaymentSystem* Ipayment) :Payment(Ipayment) {}; // ��ʹ��protected�� ʹ��֮ǰ��Ҫ�ȵ��û���Ĺ��캯��
	virtual void MakePayment()
	{
		m_Ipayment->ProcessPayment("Card Payment");
	}
	// ���������ļ̳е��ȣ�
};
class NetBankPayment :public Payment
{
public:
	NetBankPayment(IPaymentSystem *Ipayment) : Payment(Ipayment) {};
	virtual void MakePayment()
	{
		m_Ipayment->ProcessPayment("NetBank Payment");
	}
};

// �ֱ�������ά�ȵı仯���ɽ���������ϵ�����£�һ��ά���ǳ����ά�ȣ���һ���Ǿ���ʵʩ��ά�ȡ�


// ��� һ���� ��Ҫ����ļ������裬�����ж���ʵ�ַ�ʽ����Ϸ�ʽ




#endif // !_BRIDGE_H_



