#include<iostream>
#include"Admin.h"
#include"Student.h"
#include"Teacher.h"
using std::cout;
using std::endl;
using std::cin;
Admin::Admin()
{

}
Admin::Admin(std::string name, std::string password)
{
	this->m_name = name;
	this->m_password = password;
	this->InitContainers();//��ʼ����������--���ļ��ж�
	this->InitComputerRoom();
}
void Admin::operateMenu()
{
    std::cout << "\t\t\t\t\t��ӭ����Ա" << this->m_name << "��¼��\t\t\t\t" << std::endl;
   
	std::vector<std::string> funcions =
	{

		"\t����˺�    \t",
		"\t�鿴�˺�    \t",
		"\t�鿴����    \t",
		"\t���ԤԼ    \t",
		"\tע����¼    \t"

	};
	
	for (int i = 0; i < funcions.size(); i++)
	{
		std::cout << " \t\t\t\----------------" << i + 1 << "." << funcions[i] << "---------------- \t\t\t" << std::endl;
	}
	
	std::cout << "�������ѡ��:"<<std::endl;
}
/*����˺�*/
void Admin::addPerson()
{
	int id;
	std::string name;
	std::string password;
	std::ofstream ofs;

	std::string error_tips;

	while (true)
	{
		this->operateMenu();
		cout << "�������ѧ�������ͣ�" << endl;
		cout << "1.���ѧ��" << endl;
		cout << "2.�����ʦ" << endl;

		std::string file_name;
		std::string tip;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			file_name = STUDENT_FILE;
			tip = "������ѧ��ѧ�ţ�";
			error_tips = "ѧ���ظ������������롣";	
			while (true)
			{	
				cout << tip << endl;
				cin >> id;	
			    bool return_ans = IsHaveRepeat(id, select);	
				if (return_ans)
				{
					cout << error_tips << endl;
					continue;
				}
				else
				{
					break;
				}
			
			}
			
			cout << "������������" << endl;
			cin >> name;
			cout << "���������룺" << endl;
			cin >> password;

			ofs.open(file_name, std::ios::out|std::ios::app);
			if (!ofs.is_open()) {
				throw std::runtime_error("�޷����ļ�: " + file_name);
			}

			ofs << id << " " << name << " " << password << " " << endl;
			cout << "��ӳɹ���" << endl;
			system("pause");
			system("cls");
			ofs.close();
			this->InitContainers();//��ʱ��������
		}
		else if (select == 2)
		{
			file_name = TEACHER_FILE;
			tip = "������ְ����ţ�";
			error_tips = "ְ�����ظ������������롣";
			
			while (true)
			{
				cout << tip << endl;
				cin >> id;
				bool return_ans = IsHaveRepeat(id, select);
				if (return_ans)
				{
					cout << error_tips << endl;
					continue;
				}
				else
				{
					break;
				}
			}
			cout << "������������" << endl;
			cin >> name;
			cout << "���������룺" << endl;
			cin >> password;
			ofs.open(file_name, std::ios::out | std::ios::app);
			if (!ofs.is_open()) {
				throw std::runtime_error("�޷����ļ�: " + file_name);
			}

			ofs << id << " " << name << " " << password << " " << endl;
			cout << "��ӳɹ���" << endl;
			system("pause");
			system("cls");
			ofs.close();
			this->InitContainers();//��ʱ��������
		}
		else
		{
			cout << "�����������������롣" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}
/*��ӡѧ����Ϣ*/
void PrintStudent(Student& student)
{
	cout << "id:" << student.m_id << " " << "name:" << student.m_name << "  password:" << student.m_password << endl;
}
/*��ӡ��ʦ��Ϣ*/
void PrintTeacher(Teacher& teacher)
{
	cout << "id:" << teacher.empId << " " << "name:" << teacher.m_name << "  password:" << teacher.m_password << endl;
}
/*�鿴�˺�*/
void Admin::showPerson()
{
	cout << "ѡ��鿴���ͣ�" << endl;
	cout << "1.�鿴ѧ��" << endl;
	cout << "2.�鿴��ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ������Ϣ���¡�" << endl;
		std::for_each(vector_student.begin(), vector_student.end(), PrintStudent);
	}
	else if(select == 2)
	{
		cout << "������ʦ����Ϣ���¡�" << endl;
		std::for_each(vector_teacher.begin(), vector_teacher.end(), PrintTeacher);
	}
	else
	{
		system("pause");
		system("cls");
		return;
	}
	system("pause");
	system("cls");
}
/*�鿴������Ϣ*/
void Admin::showComputer()
{
	cout << "������Ϣ���¡�" << endl;
	for (std::vector<ComputerRoom>::iterator it = vector_computer_room.begin(); it != vector_computer_room.end(); it++)
	{
		cout << "������ţ�" << it->m_computer_id << " �������������" << it->m_max_room << endl;
	}
	system("pause");
	system("cls");
}
/*���ԤԼ��¼*/
void Admin::cleanFile()
{
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::trunc);
	cout << "ԤԼ��¼��ճɹ���" << endl;
	ofs.close();
	system("pause");
	system("cls");
}
/*��ʼ��ѧ������ʦ����*/
void Admin::InitContainers()
{
	/*��ȡѧ���ļ�����Ϣ*/
	std::ifstream ifs;
	ifs.open(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ʧ�ܡ�" << endl;
		return;
	}
	/*ȷ���������*/
	vector_student.clear();
	vector_teacher.clear();
	Student student;
	while (ifs >> student.m_id && ifs >> student.m_name && ifs >> student.m_password)
	{
		vector_student.push_back(student);
	}

	cout << "��ǰѧ������Ϊ��" << vector_student.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, std::ios::in);
	Teacher teacher;
	while (ifs >> teacher.empId && ifs >> teacher.m_name&& ifs >> teacher.m_password)
	{
		
		vector_teacher.push_back(teacher);
	}
	cout << "��ǰ��ʦ����Ϊ��" << vector_teacher.size() << endl;
	ifs.close();

}
/*��ʼ����������*/
void Admin::InitComputerRoom()
{
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	ComputerRoom computer_room;
	while (ifs >> computer_room.m_computer_id && ifs >> computer_room.m_max_room )
	{

		vector_computer_room.push_back(computer_room);
	}
	cout << "��ǰ��������Ϊ��" << vector_computer_room.size() << endl;
	ifs.close();
}
//id�ظ����
/*
* id: ѧ��ѧ�Ż�ְ�����
* type: 1--student
*       2--teacher
* return value:
*   if true : repeat
*      false:not repeat
*/
bool Admin::IsHaveRepeat(int id,int type)
{
	if (type == 1)
	{
		for (auto it = vector_student.begin(); it != vector_student.end(); it++)
		{
			if (id == it->m_id)
			{
				return true;//�ظ�
			}
		}

	}
	else if(type == 2)
	{
		for (auto it = vector_teacher.begin(); it != vector_teacher.end(); it++)
		{
			if (id == it->empId)
			{
				return true;//�ظ�
			}
		}
	}
	return false;
}

bool Admin::operator==(const Admin& other) const
{
	return false;
}
