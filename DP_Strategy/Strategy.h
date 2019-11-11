#ifndef _STRATEGY_H_
#define  _STRATEGY_H_
#endif // !_STRATEGY_H_

#include <iostream>

class Context
{
public:
	double m_TotalMoney;
};




class TaxStrategy
{
public:
	virtual double CalculateTax(const Context& context) = 0;
	virtual ~TaxStrategy() {};
};

class FR_Tax : public TaxStrategy
{
public:
	virtual double CalculateTax(const Context& context)
	{
		std::cout <<"FR:"<<2* context.m_TotalMoney << std::endl;
		return 2 * context.m_TotalMoney;
	}

};

class CN_Tax : public TaxStrategy
{
public:
	virtual double CalculateTax(const Context& context)
	{
		std::cout << "CN:" << 8 * context.m_TotalMoney << std::endl;
		return  8 * context.m_TotalMoney;
	}

};

// new a clas
class US_Tax : public TaxStrategy
{
public:
	virtual double CalculateTax(const Context& context)
	{
		std::cout << "US:" << 5 * context.m_TotalMoney << std::endl;
		return 5 * context.m_TotalMoney;
	}
};



class SalesOrder {
	TaxStrategy* myStrategy;
	Context myContext;// 参数
public:
	SalesOrder()
	{
		myStrategy = new US_Tax; // 如果有工厂模式，这里可以使用工厂模式

	}
	double CalculateTax() {
		myContext.m_TotalMoney = 100;
		return myStrategy->CalculateTax(myContext);
	}
	~SalesOrder()
	{
		delete myStrategy;
	}

};

