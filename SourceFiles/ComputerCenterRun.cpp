#include<iostream>
#include<vector>
#include<string>
#include"Admin.h"
#include"Student.h"
#include"Teacher.h"
#include"GlobalFile.h"
using std::cout;
using std::endl;
using std::cin;
int select = 0;
/*管理员子界面*/
void AdminMenuFunc(Identity* &admin)//对父类Identity* 指针对象的引用
{
    Admin* man = (Admin*)(admin);
	int select = 0;
	while (true)
	{
	/*调用管理员子菜单，多态实现*/
		admin->operateMenu();
		cin >> select;
		if (select == 1)
		{
			/*添加账号*/
		
			man->addPerson();
		}
		else if (select == 2)
		{
			/*查看账号*/
		
			man->showPerson();
		}
		else if (select == 3)
		{
			/*查看机房*/
		
			man->showComputer();
		}
		else if (select == 4)
		{
			/*清空预约*/
			man->cleanFile();
		}
		else
		{
			/*默认情况：注销登录*/
			delete admin;
			cout << "注销登录。" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
/*学生子界面*/
void StudentMenuFunc(Identity*& stu)//对父类Identity* 指针对象的引用
{
	Student* student = (Student*)stu;
	int select = 0;
	while (true)
	{
		/*调用学生子菜单，多态实现*/
		stu->operateMenu();
		cin >> select;
		if (select == 1)
		{
			/*申请预约*/
			student->applyOrder();
		
		}
		else if (select == 2)
		{
			/*查看自身预约*/
			student->displayMyOrder();
			
		}
		else if (select == 3)
		{
			/*查看所有预约*/
		    student->displayAllOrders();
			
		}
		else if (select == 4)
		{
			/*取消预约*/
			student->cancelOrder();
		}
		else
		{
			/*默认情况：注销登录*/
			delete student;
			cout << "注销登录。" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

/*老师子界面*/
void TeacherMenuFunc(Identity*& man)
{
	Teacher* teacher = (Teacher*)(man);
	int select = 0;
	while (true)
	{
		/*调用老师职工子菜单，多态实现*/
		teacher->operateMenu();
		cin >> select;
		if (select == 1)
		{
			/*查看所有预约*/

			teacher->displayAllOrders();
		}
		else if (select == 2)
		{
			/*审核预约*/

			teacher->validOrder();
		}
		else
		{
			/*默认情况：注销登录*/
			delete teacher;
			cout << "注销登录。" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
/*
* 登录功能
* 参数1 文件名
* 参数2 身份类型
*/
void LoginFunc(std::string file_name, int info_type)
{
	//基类指针指向其派生类用于实现多态
	Identity* person = NULL;
	std::ifstream ifs;
	ifs.open(file_name, std::ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在。" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	std::string name;//姓名
	std::string password;//密码
	if (info_type == 1)
	{
		/*学生*/
		cout << "请输入学号：" << endl;
		cin >> id;
	}
	else if (info_type == 2)
	{
		/*老师*/
		cout << "请输入职工号：" << endl;
		cin >> id;
	}
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> password;

	if (info_type == 1)
	{
		/*学生身份验证*/
		//从文件中获取
		int student_id;//学号
		std::string student_name;
		std::string student_password;
		while (ifs >> student_id && ifs >> student_name && ifs >> student_password)
		{
			cout << student_id << " " << student_name << " " << student_password<<endl;
			if (id == student_id && name == student_name && password == student_password)
			{
				cout << "学生信息验证登陆成功。" << endl;
				system("pause");
				system("cls");

				person = new Student(id, name, password);
				/*学生子界面*/
				StudentMenuFunc(person);
				return;
			}
		}
	}
	else if (info_type == 2)
	{
		/*老师身份验证*/
		//从文件中获取
		int teacher_id;//职工号
		std::string teacher_name;
		std::string teacher_password;
		
		while (ifs >> teacher_id && ifs >> teacher_name && ifs >> teacher_password)
		{
			cout << "职工号" << teacher_id << " " << teacher_name << " " << teacher_password << endl;
			if (id == teacher_id && name == teacher_name && password == teacher_password)
			{
				cout << "老师信息验证登陆成功。" << endl;
				system("pause");
				system("cls");

				person = new Teacher(id, name, password);
				/*老师子界面*/
				TeacherMenuFunc(person);
				return;
			}
		}
	}
	else if (info_type == 3)
	{
		/*管理员身份验证*/
		//从文件中获取
		std::string admin_name;
		std::string admin_password;
	
		while (ifs >> admin_name && ifs >> admin_password)
		{
			cout << admin_name << " " << admin_password;
			if (name == admin_name && password == admin_password)
			{
				cout << "管理员信息验证登陆成功。" << endl;
				system("pause");
				system("cls");

				person = new Admin(name, password);
				/*管理员子界面*/
				AdminMenuFunc(person);
				return;
			}
		}
	}
	/*输入其他数字*/
	cout<<"输入有误，重新输入。" << endl;
	system("pause");
	system("cls");
	
}
int main()
{
	while (true)
	{
	
		std::vector<std::string> funcions =
		{
			
			"\t学生代表    \t",
			"\t老    师    \t",
			"\t管 理 员     \t",
			"\t退出程序     \t"
			
		};
		cout << " \t\t\t------------------WELCOME机房预约系统------------------- \t\t\t" << endl;
		for (int i = 0; i < funcions.size(); i++)
		{
			cout << " \t\t\t\----------------" << i + 1 << "." << funcions[i] << "---------------- \t\t\t" << endl;
		}
		cout << " \t\t\t------------------END机房预约系统----------------------- \t\t\t" << endl;
		cout << "输入你的选择:";
		cin >> select;
		switch (select)
		{
		case 1://学生
		
			LoginFunc(STUDENT_FILE, 1);
			break;
		case 2://老师
			LoginFunc(TEACHER_FILE, 2);
			break;
		case 3://管理员
			LoginFunc(ADMIN_FILE, 3);
			
			break;
		case 4:
			cout << "已退出。" << endl;
			system("pause");
			return 0;
		default:
			cout << "输入有误，重新输入。" << endl;
			system("pause");
			system("cls");
			break;
		}
	}

	return 0;
}
