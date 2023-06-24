#ifndef  _STUDENT_
#define _STUDENT_
#include<vector>
#include<string>
#include"ComputerRoom.h"
#include"Identity.h"
#include"GlobalFile.h"

class Student :public Identity
{
public:
	Student();
	Student(int id, std::string name, std::string password);
	
	virtual void operateMenu() ;

	/*申请预约*/
	void applyOrder();
	/*查看自身预约*/
	void displayMyOrder();
	/*查看所有预约*/
	void displayAllOrders();
	/*取消预约*/
	void cancelOrder();
public:
	std::vector<ComputerRoom> vector_computer_room;//存放机房相关信息
	int m_id;//学号
};
#endif 