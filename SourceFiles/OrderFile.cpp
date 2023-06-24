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
		cout << "�ļ���ʧ�ܡ�" << endl;
		return;
	}
	std::string date;        //ԤԼʱ��
	std::string interval;    //����ʱ���
	std::string student_id;  //ѧ��
	std::string student_name;//ѧ������
	std::string room_id;     //�������
	std::string status;      //ԤԼ����״̬

	this->m_order_count = 0;
	while (ifs>>date&&ifs>>interval&&ifs>>student_id&&ifs>>student_name&&ifs>>room_id&&ifs>>status)
	{
		/*Ҫ��":"��key��value�зֱ�ȡ����*/
		std::string key;
		std::string value;
		std::map<std::string, std::string> m_order;
		/*��ȡԤԼʱ��*/
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);
			value = date.substr(pos + 1, date.size() - pos);
			m_order.insert(std::make_pair(key,value));

		}
		/*��ȡ����ʱ���*/
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);
			value = interval.substr(pos + 1, interval.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		/*��ȡѧ��*/
		pos = student_id.find(":");
		if (pos != -1)
		{
			key = student_id.substr(0, pos);
			value = student_id.substr(pos + 1, student_id.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		/*��ȡѧ������*/
		pos = student_name.find(":");
		if (pos != -1)
		{
			key = student_name.substr(0, pos);
			value = student_name.substr(pos + 1, student_name.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		/*��ȡ�������*/
		pos = room_id.find(":");
		if (pos != -1)
		{
			key = room_id.substr(0, pos);
			value = room_id.substr(pos + 1, room_id.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		/*��ȡ״̬*/
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);
			/*�ָ�:*/
			value = status.substr(pos + 1, status.size() - pos);
			m_order.insert(std::make_pair(key, value));

		}
		m_order_data.insert(std::make_pair(this->m_order_count,m_order));
		this->m_order_count++;
	}
	ifs.close();
	/*for (auto it = m_order_data.begin(); it != m_order_data.end(); it++)
	{
		cout << "ԤԼ��¼������" << it->first<< endl;
		for (auto itx = (*it).second.begin(); itx != (*it).second.end(); itx++)
		{
			cout << "Key:" << itx->first << "  Value:" << itx->second<< endl;
		}
	}*/
}
/*����ԤԼ��¼*/
void OrderFile::UpdateOrder()
{
	if (this->m_order_count == 0)
	{
		/*�޼�¼*/
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