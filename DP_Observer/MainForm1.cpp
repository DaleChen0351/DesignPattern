class MainForm : public Form 
{
	TextBox* txtFilePath;
	TextBox* txtFileNumber;
	ProgressBar* progressBar;// 进度条

public:
	void Button1_Click(){

		string filePath = txtFilePath->getText();
		int number = atoi(txtFileNumber->getText().c_str());

		FileSplitter splitter(filePath, number, progressBar); // 调用控件显示进度，会造成fileSplitt类 依赖一个进度条控件

		splitter.split();

	}
};

