#ifndef _DECORATOR_H_
#define _DECORATOR_H_

class ISgnlQualityDetector
{
public:
	virtual void LongTermInvaildCondtion() = 0; // �ж��źų�����Ч������
	virtual void VaildSignalAtCurCycle() = 0; // �жϸ��źŵ�ǰ�����Ƿ���Ч
	virtual ~ISgnlQualityDetector() {};
};


// �����ࣺ
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

// ��չ װ��    ��ʵ�൱���ǶԼ̳��Ի�����������඼���Խ��ж������� 
// is a : ��Ϊ�˷��Ͻӿڹ淶
// has a : �����Ҫ���εĶ������� ��������Ǿ������κ���µĶ������ͣ�
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
	// �Ƿ���Ҫ�����нӿ�ȫ��ʵ�֣��ǵģ�����ȫ��ʵ�֣���Ϊ�ǳ�����࣬�����ȫ��ʵ�֣��������õ��ᱨ���
	virtual void VaildSignalAtCurCycle()
	{
		m_Isgnl->VaildSignalAtCurCycle();
		std::cout << " expaned: the signal vaild in this cycle " << std::endl;
	}
};



#endif // _DECORATOR_H_


