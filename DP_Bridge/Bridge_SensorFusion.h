#ifndef _SENSOR_FUSION_H_
#define _SENSOR_FUSION_H_

// Implementor
class Implementor
{
public:
	virtual void Prediction() = 0;
	virtual void Measurement() = 0;
	virtual void Update() = 0;
	virtual void CalcSimul() = 0;
	virtual void Match() = 0; // hmƥ�� ���� ����ƥ��
	virtual ~Implementor() {}; // ��������������Ǳ���д�ģ�����virtual�ġ�
	virtual std::string Name() const = 0;
};

// Abstraction 
class Tracking
{
public:
	Implementor* m_imp;

	Tracking() : m_name("BaseTracking"){}
	virtual void Association() = 0;
	virtual void AssignedTrack() = 0;
	virtual void UnassignedTrack() {
		std::cout << "UnassignedTrack" << std::endl;
	}
	virtual void CreateNewTrack()
	{
		std::cout << "CreateNewTrack" << std::endl;
	}
	virtual void DeleteOneTrack() {
		std::cout << "DeleteOneTrack" << std::endl;
	}

	
	virtual ~Tracking()
	{
		if (m_imp != nullptr)
		{
			delete m_imp;
		}
	}
protected:
	std::string m_name; // дһ�����֣��������ĵ���
};


// Refined Absraction
class BasicTracking : public Tracking
{
public:

	BasicTracking() {
		m_name = "BasicTracking";
	}
	virtual void Association()
	{
		m_imp->Measurement();
		m_imp->Prediction();
		m_imp->CalcSimul();
		m_imp->Match();
	}
	virtual void AssignedTrack()
	{
		m_imp->Update();
	}
	
};
// ����չ�԰�
class NewTracking : public BasicTracking
{
public:
	virtual void AssignedTrack()
	{
		m_imp->Update();
		std::cout<<" Filter Operation"<<std::endl;
	}
};


// ConcreteImplementor

class KF_HM_Exp :public Implementor
{
public:
	virtual std::string Name() const override
	{
		return "KF_HM_Exp";
	}
	virtual void Prediction() override 
	{
		std::cout << "KF prediction" << std::endl;
	}
	virtual void Measurement() override 
	{
		std::cout << "Normal Measurement" << std::endl;
	}
	virtual void Update() override 
	{
		std::cout << "KF update" << std::endl;
	}
	virtual void CalcSimul() override
	{
		std::cout << "Exp CalcSimul"<<std::endl;
	}
	virtual void Match() override 	// hmƥ�� ���� ����ƥ��
	{
		std::cout << "HM match" << std::endl;
	}
};

class UKF_Matrix_Exp :public Implementor
{
public:
	virtual std::string Name() const override
	{
		return "UKF_Matrix_Exp";
	}
	virtual void Prediction() override 
	{
		std::cout << "UKF prediction" << std::endl;
	}
	virtual void Measurement() override 
	{
		std::cout << "Normal Measurement" << std::endl;
	}
	virtual void Update() override 
	{
		std::cout << "ukf update" << std::endl;
	}
	virtual void CalcSimul() override 
	{
		std::cout << "Exp CalcSimul" << std::endl;
	}
	virtual void Match() override 	// hmƥ�� ���� ����ƥ��
	{
		std::cout << "Matrix match" << std::endl;
	}
};
// �̳й�ϵ
class UKF_ImageMease_Exp :public UKF_Matrix_Exp
{
	virtual void Measurement() // ����������ͬ������
	{
		std::cout << "ImageObj Measurement" << std::endl;
	}
};
// Decorator: ���� is-a ���� has-a
class RadarMeasement:public Implementor
{
public:
	Implementor* m_Isgnl; // ע����������

	RadarMeasement(Implementor* pimp) : m_Isgnl(pimp) {};
	virtual std::string Name() const override
	{
		return "RadarMeasement";
	}
	virtual void Measurement() // װ�ι���
	{
		m_Isgnl->Measurement();
		std::cout << "RaadarObj Measurement" << std::endl;
	}
	// �Ƿ���Ҫ�����нӿ�ȫ��ʵ�֣��ǵģ�����ȫ��ʵ�֣���Ϊ�ǳ�����࣬�����ȫ��ʵ�֣��������õ��ᱨ���
	virtual void Prediction()
	{
		m_Isgnl->Prediction();
	}
	virtual void Update()
	{
		m_Isgnl->Update();
	}
	virtual void CalcSimul()
	{
		m_Isgnl->CalcSimul();
	}
	virtual void Match()
	{
		m_Isgnl->Match();
	}
};



















#endif // !_SENSOR_FUSION_H

