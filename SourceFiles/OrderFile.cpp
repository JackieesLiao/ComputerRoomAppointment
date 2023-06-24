#include<iostream>
#include<fstream>
#include"OrderFile.h"
using std::cout;
using std::endl;
using std::cin;
OrderFile::OrderFile()
{
	std::ifstream ifs;
	
	ifs.open(ORDER_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败。" << endl;
		return;
	}
	std::string date;        //预约时间
	std::string interval;    //具体时间段
	std::string student_id;  //学号
	std::string student_name;//学生姓名
	std::string room_id;     //机房编号
	std::string status;      //预约申请状态

	this->m_order_count = 0;
	while (ifs>>date&&ifs>>interval&&ifs>>student_id&&ifs>>student_name&&ifs>>room_id&&ifs>>status)
	{
		/*要用":"将key与value中分别取出来*/
		std::string key;
		std::string value;
		std::map<std::string, std::string> m_order;
		/*截取预约时间*/
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos);
			m_order.insert(std::make_pair(key,value));

		}
		/*截取具体时间段*/
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		/*截取学号*/
		pos = student_id.find(":");
		if (pos != -1)
		{
			key = student_id.substr(0, pos);
			value = student_id.substr(pos + 1, student_id.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		/*截取学生姓名*/
		pos = student_name.find(":");
		if (pos != -1)
		{
			key = student_name.substr(0, pos);
			value = student_name.substr(pos + 1, student_name.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		/*截取机房编号*/
		pos = room_id.find(":");
		if (pos != -1)
		{
			key = room_id.substr(0, pos);
			value = room_id.substr(pos + 1, room_id.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		/*截取状态*/
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			/*分割:*/
			value = status.substr(pos + 1, status.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		m_order_data.insert(std::make_pair(this->m_order_count,m_order));
		this->m_order_count++;
	}
	ifs.close();
	/*for (auto it = m_order_data.begin(); it != m_order_data.end(); it++)
	{
		cout << "预约记录条数：" << it->first<< endl;
		for (auto itx = (*it).second.begin(); itx != (*it).second.end(); itx++)
		{
			cout << "Key:" << itx->first << "  Value:" << itx->second<< endl;
		}
	}*/
}
/*更新预约记录*/
void OrderFile::UpdateOrder()
{
	if (this->m_order_count == 0)
	{
		/*无记录*/
		return;
	}
	std::ofstream ofs;
	ofs.open(ORDER_FILE,std::ios::out|std::ios::trunc);
	for (int i = 0; i < this->m_order_count; i++)
	{
		ofs << "date:" << this->m_order_data[i]["date"] << " ";
		ofs << "interval:" << this->m_order_data[i]["interval"] << " ";
		ofs << "student_id:" << this->m_order_data[i]["student_id:"] << " ";
		ofs << "student_name:" << this->m_order_data[i]["student_name:"] << " ";
		ofs << "room_id:" << this->m_order_data[i]["room_id"] << " ";
		ofs << "status:" << this->m_order_data[i]["status"] << " ";
		
	}
	ofs.close();
}