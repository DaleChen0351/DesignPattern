#ifndef _STRATEGY_SENSOR_FUSION_H_
#define _STRATEGY_SENSOR_FUSION_H_

class Object
{
private:
	int  m_id;
	float m_dx, m_dy;
	float m_vx, m_vy;
};
class SimuCalcStategy
{
public:
	virtual float CalsObjSimu(const Object& objA, const Object& objB) = 0;
	~SimuCalcStategy(){}
};

class Ma_distence :public SimuCalcStategy
{
public:
	virtual float CalsObjSimu(const Object& objA, const Object& objB)
	{
		return 0.6;
	}
};

class Sigmd_distence :public SimuCalcStategy
{
public:
	virtual float CalsObjSimu(const Object& objA, const Object& objB)
	{
		return 0.3;
	}
};

class Other_distence :public SimuCalcStategy
{
public:
	virtual float CalsObjSimu(const Object& objA, const Object& objB)
	{
		return 0.1;
	}
};


class AssociaClass
{
private:
	SimuCalcStategy* ss;
public:
	AssociaClass(){
		ss = new Ma_distence();
	}
	virtual bool MatchObj(const Object& objA, const Object& objB)
	{
		return (ss->CalsObjSimu(objA, objB) > 0.5 ? 0 : 1);
	}
	~AssociaClass()
	{
		delete ss;
	}
};




#endif // !_STRATEGY_SENSOR_FUSION_H_

