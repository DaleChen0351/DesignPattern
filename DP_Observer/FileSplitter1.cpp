class IProgress {
public:
	virtual void 
};


class FileSplitter // �߲�ģ�������Ͳ�ģ�飨��������
{
	string m_filePath;
	int m_fileNumber;
	ProgressBar* m_progressBar; // �ײ�ʵ�֣�Υ����DIPԭ����������ԭ��
								//���ÿؼ��Ļ���Ҳ����  ���ǣ�Ҳ������������ȫ�ĳ��� 

public:
	FileSplitter(const string& filePath, int fileNumber, ProgressBar* progressBar) :
		m_filePath(filePath), 
		m_fileNumber(fileNumber),
		m_progressBar(progressBar){

	}

	void split(){

		//1.��ȡ���ļ�

		//2.��������С�ļ���д��
		for (int i = 0; i < m_fileNumber; i++){
			//...
			float progressValue = m_fileNumber;
			m_progressBar->setValue(progressValue); // ���½�����
		}

	}
};