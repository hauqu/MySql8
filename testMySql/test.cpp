#include <stdio.h>
#include <WinSock.h>
#include <Windows.h>
#include <mysql.h>
#include<iostream>
using namespace std;

/// <summary>
/// 
/// </summary>
MYSQL mysql;  //mysql����
MYSQL_RES* res; //һ��������ṹ��   
MYSQL_ROW row; //char** ��ά���飬���һ������¼  

const char DataBase_UserName[] = "root";    //���ݿ��û���username
const char DataBase_Password[] = "207868";   //���ݿ����룬���Լ�������
const char DataBase_Host[] = "localhost";  //���ݿ����ӵ�ַ
//ע����ʱ��ʹ������ip�ᱨ����ʱ���Խ�ip��Ϊlocalhost
const char DataBase_Name[] = "mysql";  //database name
unsigned int DataBase_Port = 3306;            //server port

bool ConnectDatabase(); //��������
void FreeConnect();   //�ͷ���Դ
void main()
{
	ConnectDatabase();	//�������ݿ�
	//��ѯ����
	mysql_query(&mysql, "SELECT * from sheet8");
	//��ȡ�����
	res = mysql_store_result(&mysql);
	//��ʾ����
	//��ROW��ֵ���ж�ROW�Ƿ�Ϊ�գ���Ϊ�վʹ�ӡ���ݡ�
	while (row = mysql_fetch_row(res))
	{
		printf("%s ", row[0]);//��ӡID
		printf("%s ", row[1]);//��ӡID
		cout << endl;
	}

	getchar();
}
bool ConnectDatabase()
{
	//��ʼ��mysql
	mysql_init(&mysql);   //����mysql�����ݿ�
	if (!(mysql_real_connect(&mysql, DataBase_Host, DataBase_UserName, DataBase_Password, DataBase_Name, DataBase_Port, NULL, 0))) //�м�ֱ����������û��������룬���ݿ������˿ںţ�����дĬ��0����3306�ȣ���������д�ɲ����ٴ���ȥ
	{
		printf("Error connecting to database:%s\n", mysql_error(&mysql));
		return false;
	}
	else
	{
		MessageBoxA(NULL, "����MYSQL���ݳɹ���", "��Ϣ", MB_OK);
		printf("Connected...\n");
		return true;
	}
}
//�ͷ���Դ
void FreeConnect()
{
	//�ͷ���Դ
	//mysql_free_result(res);
	mysql_close(&mysql);
}
