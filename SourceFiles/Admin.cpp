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
	this->InitContainers();//初始化两个容器--从文件中读
	this->InitComputerRoom();
}
void Admin::operateMenu()
{
    std::cout << "\t\t\t\t\t欢迎管理员" << this->m_name << "登录。\t\t\t\t" << std::endl;
   
	std::vector<std::string> funcions =
	{

		"\t添加账号    \t",
		"\t查看账号    \t",
		"\t查看机房    \t",
		"\t清空预约    \t",
		"\t注销登录    \t"

	};
	
	for (int i = 0; i < funcions.size(); i++)
	{
		std::cout << " \t\t\t\----------------" << i + 1 << "." << funcions[i] << "---------------- \t\t\t" << std::endl;
	}
	
	std::cout << "输入你的选择:"<<std::endl;
}
/*添加账号*/
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
		cout << "输入添加学生的类型：" << endl;
		cout << "1.添加学生" << endl;
		cout << "2.添加老师" << endl;

		std::string file_name;
		std::string tip;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			file_name = STUDENT_FILE;
			tip = "请输入学生学号：";
			error_tips = "学号重复，请重新输入。";	
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
			
			cout << "请输入姓名：" << endl;
			cin >> name;
			cout << "请输入密码：" << endl;
			cin >> password;

			ofs.open(file_name, std::ios::out|std::ios::app);
			if (!ofs.is_open()) {
				throw std::runtime_error("无法打开文件: " + file_name);
			}

			ofs << id << " " << name << " " << password << " " << endl;
			cout << "添加成功。" << endl;
			system("pause");
			system("cls");
			ofs.close();
			this->InitContainers();//及时更新容器
		}
		else if (select == 2)
		{
			file_name = TEACHER_FILE;
			tip = "请输入职工编号：";
			error_tips = "职工号重复，请重新输入。";
			
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
			cout << "请输入姓名：" << endl;
			cin >> name;
			cout << "请输入密码：" << endl;
			cin >> password;
			ofs.open(file_name, std::ios::out | std::ios::app);
			if (!ofs.is_open()) {
				throw std::runtime_error("无法打开文件: " + file_name);
			}

			ofs << id << " " << name << " " << password << " " << endl;
			cout << "添加成功。" << endl;
			system("pause");
			system("cls");
			ofs.close();
			this->InitContainers();//及时更新容器
		}
		else
		{
			cout << "输入有误，请重新输入。" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	
}
/*打印学生信息*/
void PrintStudent(Student& student)
{
	cout << "id:" << student.m_id << " " << "name:" << student.m_name << "  password:" << student.m_password << endl;
}
/*打印老师信息*/
void PrintTeacher(Teacher& teacher)
{
	cout << "id:" << teacher.empId << " " << "name:" << teacher.m_name << "  password:" << teacher.m_password << endl;
}
/*查看账号*/
void Admin::showPerson()
{
	cout << "选择查看类型：" << endl;
	cout << "1.查看学生" << endl;
	cout << "2.查看老师" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "所有学生的信息如下。" << endl;
		std::for_each(vector_student.begin(), vector_student.end(), PrintStudent);
	}
	else if(select == 2)
	{
		cout << "所有老师的信息如下。" << endl;
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
/*查看机房信息*/
void Admin::showComputer()
{
	cout << "机房信息如下。" << endl;
	for (std::vector<ComputerRoom>::iterator it = vector_computer_room.begin(); it != vector_computer_room.end(); it++)
	{
		cout << "机房编号：" << it->m_computer_id << " 机房最大容量：" << it->m_max_room << endl;
	}
	system("pause");
	system("cls");
}
/*清空预约记录*/
void Admin::cleanFile()
{
	std::ofstream ofs;
	ofs.open(ORDER_FILE, std::ios::trunc);
	cout << "预约记录清空成功。" << endl;
	ofs.close();
	system("pause");
	system("cls");
}
/*初始化学生和老师容器*/
void Admin::InitContainers()
{
	/*读取学生文件中信息*/
	std::ifstream ifs;
	ifs.open(STUDENT_FILE, std::ios::in);
	if (!ifs.is_open())
	{
		cout << "文件打开失败。" << endl;
		return;
	}
	/*确保容器清空*/
	vector_student.clear();
	vector_teacher.clear();
	Student student;
	while (ifs >> student.m_id && ifs >> student.m_name && ifs >> student.m_password)
	{
		vector_student.push_back(student);
	}

	cout << "当前学生数量为：" << vector_student.size() << endl;
	ifs.close();

	ifs.open(TEACHER_FILE, std::ios::in);
	Teacher teacher;
	while (ifs >> teacher.empId && ifs >> teacher.m_name&& ifs >> teacher.m_password)
	{
		
		vector_teacher.push_back(teacher);
	}
	cout << "当前老师数量为：" << vector_teacher.size() << endl;
	ifs.close();

}
/*初始化机房容器*/
void Admin::InitComputerRoom()
{
	std::ifstream ifs;
	ifs.open(COMPUTER_FILE, std::ios::in);
	ComputerRoom computer_room;
	while (ifs >> computer_room.m_computer_id && ifs >> computer_room.m_max_room )
	{

		vector_computer_room.push_back(computer_room);
	}
	cout << "当前机房数量为：" << vector_computer_room.size() << endl;
	ifs.close();
}
//id重复检测
/*
* id: 学生学号或职工编号
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
				return true;//重复
			}
		}

	}
	else if(type == 2)
	{
		for (auto it = vector_teacher.begin(); it != vector_teacher.end(); it++)
		{
			if (id == it->empId)
			{
				return true;//重复
			}
		}
	}
	return false;
}

bool Admin::operator==(const Admin& other) const
{
	return false;
}
