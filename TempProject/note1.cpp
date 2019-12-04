#include "pch.h"

#include <memory>

// C++11 ����ڴ����ĸĽ��� new and delete
void version_one()
{
	int* age = new int(25);
	delete age;
// verson one for C
	int* ageC = (int*)malloc(sizeof(int)); // malloc �ķ���ֵ��void* �ģ� ����ָ���κζ���
	free(ageC); // �����ͷ��κζ���

	char* c = (char*)malloc(100);
	free(c);
// Q1 : free �����������һ��void* ��ָ�룬 ϵͳ���֪��Ҫ�ͷŶ����ڴ�ռ��أ�

}
// Q2 ΪɶC++û������free �� malloc�����أ�
// 


//����ֻ���������������޷�ȷ���Ƿ���Ҫ�����ֶ��ͷ�ָ�룺��Ƶ�ȱ�ݵ��µ�
	// 1 ����Ҫ�ͷ�ָ������
const char*  getName() // const ָ�벻�ܸı�ָ��,����������еڶ��ε���ʱ��ָ��ָ���ֵ�ͱ��ˣ�
{
	static char valueGroup[100];
	//
	return valueGroup;
}
	// 2 ��Ҫ�����ͷ�ָ�������� ��Ϊ��malloc����ģ���Ҫfree������new������һ����
const char* getName2()// 
{
	char* value = (char*)malloc(100);// ��̬����ģ���Ҫ�ͷ�
	return value;
}
	// 3 �Ƿ��ͷ��ɺ������ⲿ�ƿ�
char* getName(char* v, size_t bufferSize)
{
	return v;
}

// delete and delete[]

// ��ؼ����Ǽ�ʹû���߼����󣬵��������쳣�׳������п�������ڴ�й©

void throwout()
{
	int* c = new int(8);
	// throw out
	
	delete c;// �����ٴε���delete��
}
// ���ù���������ɶԳ���������������
// ��ȫ�� �ֲڰ汾�ģ������ʱ��̬�����ڴ� ������ʱ���ͷŵ�
class SaveIntPointer
{
public:
	explicit SaveIntPointer(int v) : m_value(new int(v)), m_used(1){}
	~SaveIntPointer() { 
		// ���߳�û�����⣬���߳��Ǵ����
		m_used--;
		if(m_used <=0)
			delete m_value;// ���߳�������п��ܱ�delete����
	}
	// ��ȷʵ�� copy ctor
	// operator = 
	int* get() { return m_value; }
private:
	int m_used;
	int* m_value;
};

//C++ 11�� ���ָ������ shard_pointer ��ר�Ž����������
// Ч�� 
// ���ù�������������������򣬾�һ�����Զ��������������������м��׳����쳣