class MainForm : public Form, public IProgress  // 单继承真正的父类，及多个接口
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;

	ProgressBar* progressBar;

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		ConsoleNotifier cn;// 另外一个观察者

		FileSplitter splitter(filePath, number);// 应定义成基类指针

		splitter.addIProgress(this); //订阅通知  毕竟MainForm 继承了IProgress接口之后，也算是一个IProgress的子类了
		splitter.addIProgress(&cn)； //订阅通知

		splitter.split();

		splitter.removeIProgress(this);

	}

	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
};


// 这是另外一个观察者，继承了接口
class ConsoleNotifier : public IProgress {
public:
	virtual void DoProgress(float value){
		cout << ".";
	}
};

