#ifndef _CLIENT_H_
#define _CLIENT_H_

class MainForm
{
	ISplitter*  prototype;//原型对象

public:

	MainForm(ISplitter*  prototype) {
		this->prototype = prototype;
	}

	void Button_Click() 
	{
		ISplitter * splitter = prototype->clone(); //克隆原型, 每次按键按下，都是创建一个新的对象
		splitter->split();
		delete splitter;
	}
};
#endif // !_CLIENT_H_

// zhi

