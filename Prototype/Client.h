#ifndef _CLIENT_H_
#define _CLIENT_H_

class MainForm
{
	ISplitter*  prototype;//ԭ�Ͷ���

public:

	MainForm(ISplitter*  prototype) {
		this->prototype = prototype;
	}

	void Button_Click() 
	{
		ISplitter * splitter = prototype->clone(); //��¡ԭ��, ÿ�ΰ������£����Ǵ���һ���µĶ���
		splitter->split();
		delete splitter;
	}
};
#endif // !_CLIENT_H_

// zhi

