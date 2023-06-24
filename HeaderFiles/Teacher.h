#ifndef  _TEACHER_
#define _TEACHER_
#include<vector>
#include<string>
#include"Identity.h"
#include"GlobalFile.h"
class Teacher:public Identity
{
public:
	Teacher();
	Teacher(int empId, std::string name, std::string password);
	virtual void operateMenu();

	/*查看所有预约*/
	void displayAllOrders();
	/*审核预约*/
	void validOrder();

public:
	int empId; //教师编号
	
};
#endif 