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
	virtual void Match() = 0; // hm匹配 或者 矩阵匹配
	virtual ~Implementor() {}; // 基类的析构函数是必须写的，且是virtual的。
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
	std::string m_name; // 写一个名字，方便后面的调试
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
// 可扩展性啊
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
	virtual void Match() override 	// hm匹配 或者 矩阵匹配
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
	virtual void Match() override 	// hm匹配 或者 矩阵匹配
	{
		std::cout << "Matrix match" << std::endl;
	}
};
// 继承关系
class UKF_ImageMease_Exp :public UKF_Matrix_Exp
{
	virtual void Measurement() // 父类对子类的同名覆盖
	{
		std::cout << "ImageObj Measurement" << std::endl;
	}
};
// Decorator: 既是 is-a 又是 has-a
class RadarMeasement:public Implementor
{
public:
	Implementor* m_Isgnl; // 注意析构函数

	RadarMeasement(Implementor* pimp) : m_Isgnl(pimp) {};
	virtual std::string Name() const override
	{
		return "RadarMeasement";
	}
	virtual void Measurement() // 装饰工作
	{
		m_Isgnl->Measurement();
		std::cout << "RaadarObj Measurement" << std::endl;
	}
	// 是否需要将所有接口全部实现？是的，必须全部实现，因为是抽象基类，如果不全部实现，若被调用到会报错的
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

