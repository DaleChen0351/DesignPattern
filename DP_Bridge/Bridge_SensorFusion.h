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
	virtual void Match() = 0; // hm∆•≈‰ ªÚ’ﬂ æÿ’Û∆•≈‰
	~Implementor() {};
};

// Abstraction 
class Tracking
{
public:
	Implementor* m_imp;
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
};


// Refined Absraction
class BasicTracking : public Tracking
{
public:
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
// ø…¿©’π–‘∞°
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
	virtual void Prediction()
	{
		std::cout << "KF prediction" << std::endl;
	}
	virtual void Measurement()
	{
		std::cout << "Normal Measurement" << std::endl;
	}
	virtual void Update()
	{
		std::cout << "KF update" << std::endl;
	}
	virtual void CalcSimul()
	{
		std::cout << "Exp CalcSimul"<<std::endl;
	}
	virtual void Match() 	// hm∆•≈‰ ªÚ’ﬂ æÿ’Û∆•≈‰
	{
		std::cout << "HM match" << std::endl;
	}
};

class UKF_Matrix_Exp :public Implementor
{
public:
	virtual void Prediction()
	{
		std::cout << "KF prediction" << std::endl;
	}
	virtual void Measurement()
	{
		std::cout << "Normal Measurement" << std::endl;
	}
	virtual void Update()
	{
		std::cout << "KF update" << std::endl;
	}
	virtual void CalcSimul()
	{
		std::cout << "Exp CalcSimul" << std::endl;
	}
	virtual void Match() 	// hm∆•≈‰ ªÚ’ﬂ æÿ’Û∆•≈‰
	{
		std::cout << "Matrix match" << std::endl;
	}
};

class UKF_ImageMease_Exp :public UKF_Matrix_Exp
{
	virtual void Measurement()
	{
		std::cout << "ImageObj Measurement" << std::endl;
	}
};

class RadarMeasement:public Implementor
{
public:
	Implementor* m_Isgnl;

	RadarMeasement(Implementor* pimp) : m_Isgnl(pimp) {};
	virtual void Measurement()
	{
		m_Isgnl->Measurement();
		std::cout << "RaadarObj Measurement" << std::endl;
	}
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

