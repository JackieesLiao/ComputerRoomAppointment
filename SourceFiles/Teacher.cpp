#include<iostream>
#include"Teacher.h"
#include"OrderFile.h"
using std::cout;
using std::endl;
using std::cin;
Teacher::Teacher()
{

}
Teacher::Teacher(int empId, std::string name, std::string password)
{
	this->empId = empId;
	this->m_name = name;
	this->m_password = password;
}
/*��ʦ�Ӳ˵�*/
void Teacher::operateMenu()
{
   
	std::cout << "\t\t\t\t\t��ӭ��ʦ" << this->m_name<< "��¼��\t\t\t\t" << std::endl;

	std::vector<std::string> funcions =
	{

		"\t�鿴����ԤԼ\t",
		"\t���ԤԼ    \t",
		"\tע����¼    \t"

	};

	for (int i = 0; i < funcions.size(); i++)
	{
		std::cout << " \t\t\t\----------------" << i + 1 << "." << funcions[i] << "---------------- \t\t\t" << std::endl;
	}

	std::cout << "�������ѡ��:" << std::endl;
 
}

/*�鿴����ԤԼ*/
void Teacher::displayAllOrders()
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
		cout << "ʱ��Σ�" << (of.m_order_data[i]["interval"] == "1" ? "����" : "����") << " ";
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
			status += "��˲�ͨ����ԤԼʧ��";
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
/*���ԤԼ*/
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_order_count == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	std::vector<int> vector_i;
	int index = 1;//��ʾ
	cout << "���д���˵ļ�¼���¡�" << endl;
	for (int i = 0; i < of.m_order_count; i++)
	{
		if (of.m_order_data[i]["status"] == "1")
		{
			vector_i.push_back(i);

			cout << index++ << "��" << endl;
			/*��ʾ������Ϣ*/
			cout << "ԤԼ���ڣ���" << of.m_order_data[i]["date"] << " ";
			cout << "ʱ��Σ�" << (of.m_order_data[i]["interval"] == "1" ? "����" : "����") << " ";
	
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
			cout << status << endl;
		}
		
	}
	cout << "����Ҫ��˵ļ�¼��ţ�0��ʾ���ء�" << endl;
	int select = 0;
	int ret = 0;
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
				cout << "��������˽����" << endl;
				cout << "1.���ͨ��" << endl;
				cout << "2.���ʧ��" << endl;
				cin >> ret;
				if (ret == 1)
				{
					of.m_order_data[vector_i[select - 1]]["status"] = "2";
				
				}
				else
				{
					of.m_order_data[vector_i[select - 1]]["status"] = "-1";
					
				}
				of.UpdateOrder();
				cout << "�����ϡ�" << endl;
				break;
			}

		}
		cout << "����������������롣" << endl;
	}
	system("pause");
	system("cls");
}