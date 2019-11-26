// 对house本身物理结构的抽象 底层：物理层
class House{
    //door
	// windows
};

class StoneHouse : public House {

};
// 对house不同部分物理结构的构建的抽象 中层：实施层
class HouseBuilder {
public:
    House* GetResult(){
        return pHouse;
    }
    virtual ~HouseBuilder(){}
protected:
    
    House* pHouse;// 内部使用
	virtual void BuildPart1()=0; // 对应不同的类对象的生成
    virtual void BuildPart2()=0;
    virtual void BuildPart3()=0;
    virtual void BuildPart4()=0;
    virtual void BuildPart5()=0;
	
};



class StoneHouseBuilder: public HouseBuilder{
protected:
    
    virtual void BuildPart1(){
        //pHouse->Part1 = ...; 内部使用这个指针 new 对象
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
// 对房子构建过程的抽象 高层：构建流程的抽象
// house init() 部分 拆出来
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



// 感悟，对于一个复杂问题的代码实现，类的构建应从不同的角度分别构建
// 1 问题本身的物理组成，主要包含什么
// 2 每个物理组成应如何具体生成，定制
// 3 解决问题的抽象步骤是怎样的？逻辑关系如何


// build part : 


