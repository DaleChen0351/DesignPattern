// ��house��������ṹ�ĳ��� �ײ㣺�����
class House{
    //door
	// windows
};

class StoneHouse : public House {

};
// ��house��ͬ��������ṹ�Ĺ����ĳ��� �в㣺ʵʩ��
class HouseBuilder {
public:
    House* GetResult(){
        return pHouse;
    }
    virtual ~HouseBuilder(){}
protected:
    
    House* pHouse;// �ڲ�ʹ��
	virtual void BuildPart1()=0; // ��Ӧ��ͬ������������
    virtual void BuildPart2()=0;
    virtual void BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;
	
};



class StoneHouseBuilder: public HouseBuilder{
protected:
    
    virtual void BuildPart1(){
        //pHouse->Part1 = ...; �ڲ�ʹ�����ָ�� new ����
    }
    virtual void BuildPart2(){
        
    }
    virtual void BuildPart3(){
        
    }
    virtual void BuildPart4(){
        
    }
    virtual void BuildPart5(){
        
    }
    
};
// �Է��ӹ������̵ĳ��� �߲㣺�������̵ĳ���
// house init() ���� �����
class HouseDirector{
    
public:
    HouseBuilder* pHouseBuilder;
    
    HouseDirector(HouseBuilder* pHouseBuilder){
        this->pHouseBuilder=pHouseBuilder;
    }
    
    House* Construct(){
        
        pHouseBuilder->BuildPart1();
        
        for (int i = 0; i < 4; i++){
            pHouseBuilder->BuildPart2();
        }
        
        bool flag=pHouseBuilder->BuildPart3();
        
        if(flag){
            pHouseBuilder->BuildPart4();
        }
        
        pHouseBuilder->BuildPart5();
        
        return pHouseBuilder->GetResult();
    }
};



// ���򣬶���һ����������Ĵ���ʵ�֣���Ĺ���Ӧ�Ӳ�ͬ�ĽǶȷֱ𹹽�
// 1 ���Ȿ���������ɣ���Ҫ����ʲô
// 2 ÿ���������Ӧ��ξ������ɣ�����
// 3 �������ĳ������������ģ��߼���ϵ���


// build part : 


