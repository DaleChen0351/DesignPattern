
//抽象类
class ISplitter{
public:
    virtual void split()=0;// 业务基类的方法
    virtual ISplitter* clone()=0; //通过克隆自己来创建对象
    
    virtual ~ISplitter(){}

};



