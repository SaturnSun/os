/*
 *����:ʢ���
 *��д����:2014.6.24
 *��������ȡ�����ļ�����
 *���ܣ�1.��ȡ�����ļ�����Ϣ��
 *      2.getConfig(string key):�ṩ���ݹؼ��ֲ�ѯ�������ݵĹ���
 *
 */
#include<string>
#include<map>
#include<stdlib.h>
#include<fstream>
#include<iostream>
using namespace std;


/*
 *���������ļ�
 */
class config
{
private :
	map<string, string> configMap;

	/*
	 *��ȡ�����ļ�
	 */
	void readFile();
public :
	config();



	/*
	 *���ݹؼ�������ֵ
	 */
	void setConfig(string key, string value);


	/*
	 *���ݹؼ��ַ���ֵ
	 */
	string getConfig(string key);
};


config::config()
{
	readFile();
}

void config::readFile()
{
	
	ifstream inFile("config.ini");
	if (!inFile){
		cout << "�����ļ�����" << endl;
	}
	while (!inFile.eof()){
		string tmp;
		string key;
		string value;
	
		inFile >> tmp;
		if (tmp[0] == '#' || tmp[0] == ' ' || tmp[0] == '\n')//���б�ע��,���ұ��붥��д
			continue;
		int loc = tmp.find("=");

		key = tmp.substr(0,loc);
		value = tmp.substr(loc + 1, tmp.length() - 1);
		configMap.insert(pair<string, string>(key,value));
	}
}

string config::getConfig(string key)
{
	map < string, string >::iterator result;
	result = configMap.find(key);
	return result->second;
}

void config::setConfig(string key, string value)
{
}