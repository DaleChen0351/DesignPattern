class MainForm : public Form, public IProgress  // ���̳������ĸ��࣬������ӿ�
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;

	ProgressBar* progressBar;

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		ConsoleNotifier cn;// ����һ���۲���

		FileSplitter splitter(filePath, number);// Ӧ����ɻ���ָ��

		splitter.addIProgress(this); //����֪ͨ  �Ͼ�MainForm �̳���IProgress�ӿ�֮��Ҳ����һ��IProgress��������
		splitter.addIProgress(&cn)�� //����֪ͨ

		splitter.split();

		splitter.removeIProgress(this);

	}

	virtual void DoProgress(float value){
		progressBar->setValue(value);
	}
};


// ��������һ���۲��ߣ��̳��˽ӿ�
class ConsoleNotifier : public IProgress {
public:
	virtual void DoProgress(float value){
		cout << ".";
	}
};

