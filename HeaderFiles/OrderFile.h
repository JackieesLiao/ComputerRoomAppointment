#pragma once
#ifndef _ORDERFILE_
#define _ORDERFILE_
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
#include"GlobalFile.h"
class OrderFile
{
public:
	OrderFile();

	/*����ԤԼ��¼*/
	void UpdateOrder();
	/*
	* key--ԤԼ��¼������
	* value--ĳһ��ԤԼ��¼��������Ϣ��{{date:5},{interval:2}, {student_id:190611116}, {student_name:liaojunjian},{ room_id:2 status:1}}
	* ����date��interval...��Ϊkey��5��2..Ϊvalue
	*/
	std::map<int, std::map<std::string, std::string>> m_order_data;

	int m_order_count;//��¼����

};


#endif 