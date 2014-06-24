/*
 *作者:盛旭辉
 *编写日期:2014.6.24
 *描述：读取配置文件的类
 *功能：1.读取配置文件内信息，
 *      2.getConfig(string key):提供根据关键字查询配置内容的功能
 *
 */
#include<string>
#include<map>
#include<stdlib.h>
#include<fstream>
#include<iostream>
using namespace std;


/*
 *处理配置文件
 */
class config
{
private :
	map<string, string> configMap;

	/*
	 *读取配置文件
	 */
	void readFile();
public :
	config();



	/*
	 *根据关键字设置值
	 */
	void setConfig(string key, string value);


	/*
	 *根据关键字返回值
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
		cout << "配置文件错误" << endl;
	}
	while (!inFile.eof()){
		string tmp;
		string key;
		string value;
	
		inFile >> tmp;
		if (tmp[0] == '#' || tmp[0] == ' ' || tmp[0] == '\n')//该行被注释,而且必须顶格写
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