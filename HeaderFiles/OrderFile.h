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

	/*更新预约记录*/
	void UpdateOrder();
	/*
	* key--预约记录的条数
	* value--某一条预约记录的所有信息：{{date:5},{interval:2}, {student_id:190611116}, {student_name:liaojunjian},{ room_id:2 status:1}}
	* 其中date、interval...均为key，5，2..为value
	*/
	std::map<int, std::map<std::string, std::string>> m_order_data;

	int m_order_count;//记录条数

};


#endif 