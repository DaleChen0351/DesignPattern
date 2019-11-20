class IProgress {
public:
	virtual void 
};


class FileSplitter // 高层模块依赖低层模块（进度条）
{
	string m_filePath;
	int m_fileNumber;
	ProgressBar* m_progressBar; // 底层实现，违背了DIP原则。依赖倒置原则。
								//采用控件的基类也可以  但是，也可以是依赖完全的抽象 

public:
	FileSplitter(const string& filePath, int fileNumber, ProgressBar* progressBar) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber),
		m_progressBar(progressBar){

	}

	void split(){

		//1.读取大文件

		//2.分批次向小文件中写入
		for (int i = 0; i < m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			m_progressBar->setValue(progressValue); // 更新进度条
		}

	}
};