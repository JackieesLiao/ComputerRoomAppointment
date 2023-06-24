#ifndef  _ADMIN_
#define _ADMIN_
#include<string>
#include<vector>
#include<algorithm>
#include"Identity.h"
#include"Student.h"
#include"Teacher.h"
#include"ComputerRoom.h"
#include"GlobalFile.h"

class Admin :public Identity
{
public:
	Admin();
	Admin(std::string name, std::string password);
	virtual void operateMenu();
	/*添加账号*/
	void addPerson();
	/*查看账号*/
	void showPerson();
	/*查看机房信息*/
	void showComputer();
	/*清空预约记录*/
	void cleanFile();

	/*初始化容器*/
	void InitContainers();
	/*初始化机房容器*/
	void InitComputerRoom();
	/*去重：根据编号来看*/
	bool IsHaveRepeat(int id,int type);
	bool operator==(const Admin& other) const;
public:
	//学生和老师容器：存放相关信息
	std::vector<Student> vector_student;
	std::vector<Teacher> vector_teacher;

	std::vector<ComputerRoom> vector_computer_room;//存放机房相关信息
};


#endif 
