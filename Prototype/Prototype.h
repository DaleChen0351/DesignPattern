#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_
//抽象类
class ISplitter {
protected:
	std::string  name_;
public:
	int test_num;
	ISplitter():test_num(0){ std::cout << "base ctor has been called! ISplitter" << std::endl; }
	virtual void split() = 0;// 业务基类的方法 // 要求有稳定的接口
	virtual ISplitter* clone() = 0; //通过克隆自己来创建对象 
	virtual ~ISplitter() {}

};
// 个人推测，把对象构造的过程放到客户类的外部，而原型对象内部只做复制（深拷贝）的工作，构造等定制化的操作由客户完成。增加了灵活性

//具体类
class BinarySplitter : public ISplitter {
public:
	BinarySplitter() { name_ = "BinarySplitter"; }
	virtual void split()
	{
		std::cout << name_ << " : "<<test_num<<std::endl;
	}
	virtual ISplitter* clone() {
		return new BinarySplitter(*this);// clone 自己  可以使用默认的复制构造函数，因为没有涉及到指针的操作
	}
};

class TxtSplitter : public ISplitter {
public:
	TxtSplitter() { name_ = "TxtSplitter"; }
	virtual void split()
	{
		std::cout << name_ << " : " << test_num << std::endl;
	}
	virtual ISplitter* clone() {
		return new TxtSplitter(*this);
	}
};




#endif // !_PROTOTYPE_H_










