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
/*教师子菜单*/
void Teacher::operateMenu()
{
   
	std::cout << "\t\t\t\t\t欢迎老师" << this->m_name<< "登录。\t\t\t\t" << std::endl;

	std::vector<std::string> funcions =
	{

		"\t查看所有预约\t",
		"\t审核预约    \t",
		"\t注销登录    \t"

	};

	for (int i = 0; i < funcions.size(); i++)
	{
		std::cout << " \t\t\t\----------------" << i + 1 << "." << funcions[i] << "---------------- \t\t\t" << std::endl;
	}

	std::cout << "输入你的选择:" << std::endl;
 
}

/*查看所有预约*/
void Teacher::displayAllOrders()
{
	OrderFile of;
	if (of.m_order_count == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_order_count; i++)
	{
		cout << "第" << i + 1 << "条预约记录：";
		/*显示各种信息*/
		cout << "预约日期：周" << of.m_order_data[i]["date"] << " ";
		cout << "时间段：" << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午") << " ";
		cout << "学生学号：" << of.m_order_data[i]["student_id"] << " ";
		cout << "学生姓名：" << of.m_order_data[i]["student_name"] << " ";
		cout << "机房号：" << of.m_order_data[i]["room_id"] << " ";
		/*
		* 1--审核中
		* 2--已经预约
		* -1 --预约失败
		*/
		std::string status = "状态： ";
		if (of.m_order_data[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_order_data[i]["status"] == "2")
		{
			status += "已经预约";
		}
		else if (of.m_order_data[i]["status"] == "-1")
		{
			status += "审核不通过，预约失败";
		}
		else
		{
			status += "预约已经取消";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}
/*审核预约*/
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_order_count == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	std::vector<int> vector_i;
	int index = 1;//提示
	cout << "所有待审核的记录如下。" << endl;
	for (int i = 0; i < of.m_order_count; i++)
	{
		if (of.m_order_data[i]["status"] == "1")
		{
			vector_i.push_back(i);

			cout << index++ << "、" << endl;
			/*显示各种信息*/
			cout << "预约日期：周" << of.m_order_data[i]["date"] << " ";
			cout << "时间段：" << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午") << " ";
	
			cout << "机房号：" << of.m_order_data[i]["room_id"] << " ";
			/*
			* 1--审核中
			* 2--已经预约
			* -1 --预约失败
			*/
			std::string status = "状态： ";
			if (of.m_order_data[i]["status"] == "1")
			{
				status += "审核中";
			}
			cout << status << endl;
		}
		
	}
	cout << "输入要审核的记录编号，0表示返回。" << endl;
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
				cout << "请输入审核结果。" << endl;
				cout << "1.审核通过" << endl;
				cout << "2.审核失败" << endl;
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
				cout << "审核完毕。" << endl;
				break;
			}

		}
		cout << "输入错误，请重新输入。" << endl;
	}
	system("pause");
	system("cls");
}