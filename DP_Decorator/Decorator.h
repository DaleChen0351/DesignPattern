#ifndef _DECORATOR_H_
#define _DECORATOR_H_

class ISgnlQualityDetector
{
public:
	virtual void LongTermInvaildCondtion() = 0; // 判断信号长期有效的条件
	virtual void VaildSignalAtCurCycle() = 0; // 判断该信号当前周期是否有效
	virtual ~ISgnlQualityDetector() {};
};


// 主体类：
class TrackingDetector :public ISgnlQualityDetector
{
public:
	virtual void LongTermInvaildCondtion()
	{
		std::cout << " tracking: long term condition meet " << std::endl;
	}

	virtual void VaildSignalAtCurCycle()
	{
		std::cout << " tracking: the signal vaild in this cycle " << std::endl;
	}
};

class PMWDetector :public ISgnlQualityDetector
{
public:
	virtual void LongTermInvaildCondtion()
	{
		std::cout << " pmw: long term condition meet " << std::endl;
	}

	virtual void VaildSignalAtCurCycle()
	{
		std::cout << " pmw: the signal vaild in this cycle " << std::endl;
	}

};

// 扩展 装饰    其实相当于是对继承自基类的所有子类都可以进行二次修饰 
// is a : 是为了符合接口规范
// has a : 获得需要修饰的对象输入 。（输出是经过修饰后的新的对象类型）
class Expandclass : public ISgnlQualityDetector
{
private:
	ISgnlQualityDetector* m_Isgnl;

public:
	Expandclass(ISgnlQualityDetector* Isgnl) : m_Isgnl(Isgnl) {}
	virtual void LongTermInvaildCondtion()
	{
		m_Isgnl->LongTermInvaildCondtion();
		std::cout << " expaned: long term condition meet " << std::endl;
	}
	// 是否需要将所有接口全部实现？是的，必须全部实现，因为是抽象基类，如果不全部实现，若被调用到会报错的
	virtual void VaildSignalAtCurCycle()
	{
		m_Isgnl->VaildSignalAtCurCycle();
		std::cout << " expaned: the signal vaild in this cycle " << std::endl;
	}
};



#endif // _DECORATOR_H_


