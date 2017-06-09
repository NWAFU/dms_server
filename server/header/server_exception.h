#ifndef CLIENTEXCEPTION_H
#define CLIENTEXCEPTION_H

#include <exception>
#include <string>

using namespace std;

//0.客户端异常
class ServerException:public exception
{
private:
	string msg;
public:
	ServerException()
	{
		this -> msg = "客户端异常!"
	}
	ClientException(const string& msg)
	{
		this -> msg = "客户端异常————";
		this -> msg += msg;
		this -> msg += "!";
	}
	~ClientException() throw(){}
	const char* whatMsg(){
		return this -> msg.c_str();
	}
};

//2.套接字异常
class SocketException:public ServerException
{
	public:
		SocketException()
		{
			ServerException("套接字异常");
		}
		SocketException(const string& msg)
		{
			ServerException(msg);
		}
};

//3.线程异常
class ThreadException:public ServerException
{
	public:
		ThreadException()
		{
			ServerException("线程异常");
		}
		ThreadException(const string& msg)
		{
			ServerException(msg);
		}
};

//4.数据库异常
class DBException:public ServerException
{
	public:
		DBException()
		{
			ServerException("数据库异常");
		}
		DBException(const string& msg)
		{
			ServerException(msg);
		}
};

#endif
