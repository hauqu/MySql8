#include <stdio.h>
#include <WinSock.h>
#include <Windows.h>
#include <mysql.h>
#include<iostream>
using namespace std;

/// <summary>
/// 
/// </summary>
MYSQL mysql;  //mysql连接
MYSQL_RES* res; //一个结果集结构体   
MYSQL_ROW row; //char** 二维数组，存放一条条记录  

const char DataBase_UserName[] = "root";    //数据库用户名username
const char DataBase_Password[] = "207868";   //数据库密码，填自己的密码
const char DataBase_Host[] = "localhost";  //数据库连接地址
//注意有时候使用主机ip会报错，此时可以将ip改为localhost
const char DataBase_Name[] = "mysql";  //database name
unsigned int DataBase_Port = 3306;            //server port

bool ConnectDatabase(); //函数申明
void FreeConnect();   //释放资源
void main()
{
	ConnectDatabase();	//连接数据库
	//查询数据
	mysql_query(&mysql, "SELECT * from sheet8");
	//获取结果集
	res = mysql_store_result(&mysql);
	//显示数据
	//给ROW赋值，判断ROW是否为空，不为空就打印数据。
	while (row = mysql_fetch_row(res))
	{
		printf("%s ", row[0]);//打印ID
		printf("%s ", row[1]);//打印ID
		cout << endl;
	}

	getchar();
}
bool ConnectDatabase()
{
	//初始化mysql
	mysql_init(&mysql);   //连接mysql，数据库
	if (!(mysql_real_connect(&mysql, DataBase_Host, DataBase_UserName, DataBase_Password, DataBase_Name, DataBase_Port, NULL, 0))) //中间分别是主机，用户名，密码，数据库名，端口号（可以写默认0或者3306等），可以先写成参数再传进去
	{
		printf("Error connecting to database:%s\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		MessageBoxA(NULL, "连接MYSQL数据成功！", "消息", MB_OK);
		printf("Connected...\n");
		return true;
	}
}
//释放资源
void FreeConnect()
{
	//释放资源
	//mysql_free_result(res);
	mysql_close(&mysql);
}
