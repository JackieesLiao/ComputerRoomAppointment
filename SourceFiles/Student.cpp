#include<iostream>

#include"Student.h"
#include"OrderFile.h"
using std::cout;
using std::endl;
using std::cin;
Student::Student()
{

}
Student::Student(int id, std::string name, std::string password)
{
	this->m_id = id;
	this->m_name = name;
	this->m_password = password;

	std::fstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	ComputerRoom computer_room;
	while (ifs >> computer_room.m_computer_id && ifs >> computer_room.m_max_room)
	{

		vector_computer_room.push_back(computer_room);
	}
	cout << "��ǰ��������Ϊ��" << vector_computer_room.size() << endl;
	ifs.close();
}
void Student::operateMenu()
{
	std::cout << "\t\t\t\t\t��ӭѧ��" << this->m_name << "��¼��\t\t\t\t" << std::endl;

	std::vector<std::string> funcions =
	{

		"\t����ԤԼ    \t",
		"\t�鿴����ԤԼ\t",
		"\t�鿴����ԤԼ\t",
		"\tȡ��ԤԼ    \t",
		"\tע����¼    \t"

	};

	for (int i = 0; i < funcions.size(); i++)
	{
		std::cout << " \t\t\t\----------------" << i + 1 << "." << funcions[i] << "---------------- \t\t\t" << std::endl;
	}

	std::cout << "�������ѡ��:" << std::endl;
}
/*����ԤԼ*/
void Student::applyOrder()
{
	int date = 0;
	int interval = 0;
	int room = 0;
	cout << "��������ʱ��Ϊ��һ�����塣" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	std::vector<std::string> funcions =
	{

		"\t��һ    \t",
		"\t�ܶ�    \t",
		"\t����    \t",
		"\t����   \t",
		"\t����    \t"

	};

	for (int i = 0; i < funcions.size(); i++)
	{
		std::cout << " \t\t\t\----------------" << i + 1 << "." << funcions[i] << "---------------- \t\t\t" << std::endl;
	}
	
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "�����������������롣" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1.����" << endl;
	cout << "2.����" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "�����������������롣" << endl;
	}
	
	cout << "��ѡ�������" << endl;
	for (int i = 0; i < vector_computer_room.size(); i++)
	{
		cout <<i+1<<":"<<vector_computer_room[i].m_computer_id << "�Ż���������" << vector_computer_room[i].m_max_room << endl;
	}

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "�����������������롣" << endl;
	}
	
	cout << "ԤԼ�ɹ�������У�����" << endl;
	std::ofstream ofs;
	
	ofs.open(ORDER_FILE, std::ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "student_id:" << m_id << " ";
	ofs << "student_name:" << m_name << " ";
	ofs << "room_id:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();
	system("pause");
	system("cls");
}

/*�鿴����ԤԼ*/
void  Student::displayMyOrder()
{
	OrderFile of;
	if (of.m_order_count == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_order_count; i++)
	{
		/*���ԤԼ��¼�е�ѧ������ö����ѧ����ͬ*/
		if (std::atoi(of.m_order_data[i]["student_id"].c_str()) == this->m_id)
		{
			/*��ʾ������Ϣ*/
			cout << "ԤԼ���ڣ���" << of.m_order_data[i]["date"]<<" ";
			cout << "ʱ��Σ�" << (of.m_order_data[i]["interval"] == "1" ? "����" : "����");
			cout << " ";
			cout << "�����ţ�" << of.m_order_data[i]["room_id"] << " ";
			/*
			* 1--�����
			* 2--�Ѿ�ԤԼ
			* -1 --ԤԼʧ��
			*/
			std::string status="״̬�� ";
			if (of.m_order_data[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_order_data[i]["status"] == "2")
			{
				status += "�Ѿ�ԤԼ";
			}
			else if (of.m_order_data[i]["status"] == "-1")
			{
				status += "ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ�Ѿ�ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

/*�鿴����ԤԼ*/
void Student::displayAllOrders()
{
	OrderFile of;
	if (of.m_order_count == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_order_count; i++)
	{
		cout << "��" << i + 1 << "��ԤԼ��¼��";
		/*��ʾ������Ϣ*/
		cout << "ԤԼ���ڣ���" << of.m_order_data[i]["date"] << " ";
		cout << "ʱ��Σ�" << (of.m_order_data[i]["interval"] =="1" ? "����" : "����")<<" ";
		cout << "ѧ��ѧ�ţ�" << of.m_order_data[i]["student_id"] << " ";
		cout << "ѧ��������" << of.m_order_data[i]["student_name"] << " ";
		cout << "�����ţ�" << of.m_order_data[i]["room_id"] << " ";
		/*
		* 1--�����
		* 2--�Ѿ�ԤԼ
		* -1 --ԤԼʧ��
		*/
		std::string status = "״̬�� ";
		if (of.m_order_data[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_order_data[i]["status"] == "2")
		{
			status += "�Ѿ�ԤԼ";
		}
		else if (of.m_order_data[i]["status"] == "-1")
		{
			status += "ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ�Ѿ�ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
/*ȡ��ԤԼ*/
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_order_count == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л���ԤԼ�ɹ��ļ�¼����ȡ������������ȡ���ļ�¼��" << endl;
	/*
	* index ����ļ���ͬһ��ѧ�ŵļ�¼����i��¼ʵ���ļ���ͬһ��ѧ�ŵ������¼��λ�ã�
	* 1                                       0
	* 2                                       1
	* ...����ѧ�ŵ�ԤԼ��¼                   2
	* 3                                       3
	* ���ӦΪ
	* index  i
	* 1      0
	* 2      1
	* 3      3
	* 
	*/
	std::vector<int> vector_i;
	int index = 1;//��ʾ����1��ʼ

	for (int i = 0; i < of.m_order_count; i++)
	{
		/*���ԤԼ��¼�е�ѧ������ö����ѧ����ͬ*/
		if (std::atoi(of.m_order_data[i]["student_id"].c_str()) == this->m_id)
		{
			/*ɸѡ״̬*/
			if (of.m_order_data[i]["status"]=="1"|| of.m_order_data[i]["status"] == "2")
			{
				/*������ű��*/
			
				vector_i.push_back(i);
			
				cout << index++ << "��" << endl;
				/*��ʾ������Ϣ*/
				cout << "ԤԼ���ڣ���" << of.m_order_data[i]["date"] << " ";
				cout << "ʱ��Σ�" << (of.m_order_data[i]["interval"] == "1" ? "����" : "����");
				cout << " ";
				cout << "�����ţ�" << of.m_order_data[i]["room_id"] << " ";
				/*
				* 1--�����
				* 2--�Ѿ�ԤԼ
				* -1 --ԤԼʧ��
				*/
				std::string status = "״̬�� ";
				if (of.m_order_data[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_order_data[i]["status"] == "2")
				{
					status += "�Ѿ�ԤԼ";
				}
				cout << status << endl;
			}
			
		}
	}
	cout << "����Ҫȡ����ԤԼ��¼��0�����ء�" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= vector_i.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				of.m_order_data[ vector_i[select-1] ]["status"] = "0";
				of.UpdateOrder();
				cout << "��ȡ��ԤԼ��" << endl;
				break;
			}
			
		}
		cout << "����������������롣" << endl;
		
	}
	system("pause");
	system("cls");

}