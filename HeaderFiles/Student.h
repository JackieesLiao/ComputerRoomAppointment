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

	/*����ԤԼ*/
	void applyOrder();
	/*�鿴����ԤԼ*/
	void displayMyOrder();
	/*�鿴����ԤԼ*/
	void displayAllOrders();
	/*ȡ��ԤԼ*/
	void cancelOrder();
public:
	std::vector<ComputerRoom> vector_computer_room;//��Ż��������Ϣ
	int m_id;//ѧ��
};
#endif 