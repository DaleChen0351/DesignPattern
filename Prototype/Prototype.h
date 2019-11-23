#ifndef _PROTOTYPE_H_
#define _PROTOTYPE_H_
//������
class ISplitter {
protected:
	std::string  name_;
public:
	int test_num;
	ISplitter():test_num(0){ std::cout << "base ctor has been called! ISplitter" << std::endl; }
	virtual void split() = 0;// ҵ�����ķ��� // Ҫ�����ȶ��Ľӿ�
	virtual ISplitter* clone() = 0; //ͨ����¡�Լ����������� 
	virtual ~ISplitter() {}

};
// �����Ʋ⣬�Ѷ�����Ĺ��̷ŵ��ͻ�����ⲿ����ԭ�Ͷ����ڲ�ֻ�����ƣ�������Ĺ���������ȶ��ƻ��Ĳ����ɿͻ���ɡ������������

//������
class BinarySplitter : public ISplitter {
public:
	BinarySplitter() { name_ = "BinarySplitter"; }
	virtual void split()
	{
		std::cout << name_ << " : "<<test_num<<std::endl;
	}
	virtual ISplitter* clone() {
		return new BinarySplitter(*this);// clone �Լ�  ����ʹ��Ĭ�ϵĸ��ƹ��캯������Ϊû���漰��ָ��Ĳ���
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










