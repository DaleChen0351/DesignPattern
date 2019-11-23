#ifndef _ABS_FACTORY_H_
# define _ABS_FACTORY_H_

//���ݿ�����йصĻ���
class IDBConnection {
protected:
	std::string name_;
public:
	IDBConnection(): name_("IDBConnection"){}
	virtual void ConnectionString(std::string str)
	{
		std::cout << str << "  order  " << name_ <<" to connect!"<< std::endl;
	}
	virtual ~IDBConnection(){}
};

class IDBCommand {
protected:
	std::string name_;
public:
	IDBCommand() : name_("IDBCommand") {}
	virtual void SetConnection(IDBConnection* dbCon)
	{
		dbCon->ConnectionString(name_);
	}
	virtual ~IDBCommand() {}
};



// ��������������������ԣ�������һ������       ���ھ� �����
class IDBFactory {
public:
	virtual IDBConnection* CreateDBConnection() = 0;
	virtual IDBCommand* CreateDBCommand() = 0;
};


//֧��SQL Server
class SqlConnection : public IDBConnection 
{
public:
	SqlConnection() {  name_ = "SqlConnection"; }
};

class SqlCommand : public IDBCommand 
{
public:
	SqlCommand()  { name_ = "SqlCommand";}
};


class SqlDBFactory :public IDBFactory {
public:
	virtual IDBConnection* CreateDBConnection()
	{
		return new SqlConnection();
	}
	virtual IDBCommand* CreateDBCommand()
	{
		return new SqlCommand();
	}
};

class EmployeeDAO {
	
public:
	IDBFactory* dbFactory;
	void run()
	{
		IDBConnection* connection = dbFactory->CreateDBConnection();
		IDBCommand* command = dbFactory->CreateDBCommand();
		command->SetConnection(connection); //������
	}
	~EmployeeDAO()
	{
		if (dbFactory != nullptr)
		{
			delete dbFactory;
		}
	}
};

// ���幤��



#endif // !_ABS_FACTORY_H_


