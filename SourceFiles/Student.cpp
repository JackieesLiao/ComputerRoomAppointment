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
	cout << "当前机房数量为：" << vector_computer_room.size() << endl;
	ifs.close();
}
void Student::operateMenu()
{
	std::cout << "\t\t\t\t\t欢迎学生" << this->m_name << "登录。\t\t\t\t" << std::endl;

	std::vector<std::string> funcions =
	{

		"\t申请预约    \t",
		"\t查看自身预约\t",
		"\t查看所有预约\t",
		"\t取消预约    \t",
		"\t注销登录    \t"

	};

	for (int i = 0; i < funcions.size(); i++)
	{
		std::cout << " \t\t\t\----------------" << i + 1 << "." << funcions[i] << "---------------- \t\t\t" << std::endl;
	}

	std::cout << "输入你的选择:" << std::endl;
}
/*申请预约*/
void Student::applyOrder()
{
	int date = 0;
	int interval = 0;
	int room = 0;
	cout << "机房开放时间为周一至周五。" << endl;
	cout << "请输入申请预约的时间：" << endl;
	std::vector<std::string> funcions =
	{

		"\t周一    \t",
		"\t周二    \t",
		"\t周三    \t",
		"\t周四   \t",
		"\t周五    \t"

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
		cout << "输入有误，请重新输入。" << endl;
	}

	cout << "请输入申请预约的时间段：" << endl;
	cout << "1.上午" << endl;
	cout << "2.下午" << endl;
	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "输入有误，请重新输入。" << endl;
	}
	
	cout << "请选择机房。" << endl;
	for (int i = 0; i < vector_computer_room.size(); i++)
	{
		cout <<i+1<<":"<<vector_computer_room[i].m_computer_id << "号机房容量：" << vector_computer_room[i].m_max_room << endl;
	}

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "输入有误，请重新输入。" << endl;
	}
	
	cout << "预约成功，审核中！！！" << endl;
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

/*查看自身预约*/
void  Student::displayMyOrder()
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
		/*如果预约记录中的学号与调用对象的学号相同*/
		if (std::atoi(of.m_order_data[i]["student_id"].c_str()) == this->m_id)
		{
			/*显示各种信息*/
			cout << "预约日期：周" << of.m_order_data[i]["date"]<<" ";
			cout << "时间段：" << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午");
			cout << " ";
			cout << "机房号：" << of.m_order_data[i]["room_id"] << " ";
			/*
			* 1--审核中
			* 2--已经预约
			* -1 --预约失败
			*/
			std::string status="状态： ";
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
				status += "预约失败";
			}
			else
			{
				status += "预约已经取消";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

/*查看所有预约*/
void Student::displayAllOrders()
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
		cout << "时间段：" << (of.m_order_data[i]["interval"] =="1" ? "上午" : "下午")<<" ";
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
			status += "预约失败";
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
/*取消预约*/
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_order_count == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "审核中或者预约成功的记录可以取消，请输入想取消的记录。" << endl;
	/*
	* index 标记文件中同一个学号的记录，而i记录实际文件中同一个学号的申请记录的位置：
	* 1                                       0
	* 2                                       1
	* ...其他学号的预约记录                   2
	* 3                                       3
	* 则对应为
	* index  i
	* 1      0
	* 2      1
	* 3      3
	* 
	*/
	std::vector<int> vector_i;
	int index = 1;//提示，从1开始

	for (int i = 0; i < of.m_order_count; i++)
	{
		/*如果预约记录中的学号与调用对象的学号相同*/
		if (std::atoi(of.m_order_data[i]["student_id"].c_str()) == this->m_id)
		{
			/*筛选状态*/
			if (of.m_order_data[i]["status"]=="1"|| of.m_order_data[i]["status"] == "2")
			{
				/*容器存放编号*/
			
				vector_i.push_back(i);
			
				cout << index++ << "、" << endl;
				/*显示各种信息*/
				cout << "预约日期：周" << of.m_order_data[i]["date"] << " ";
				cout << "时间段：" << (of.m_order_data[i]["interval"] == "1" ? "上午" : "下午");
				cout << " ";
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
				cout << status << endl;
			}
			
		}
	}
	cout << "输入要取消的预约记录，0代表返回。" << endl;
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
				cout << "已取消预约。" << endl;
				break;
			}
			
		}
		cout << "输入错误，请重新输入。" << endl;
		
	}
	system("pause");
	system("cls");

}