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

	/*�鿴����ԤԼ*/
	void displayAllOrders();
	/*���ԤԼ*/
	void validOrder();

public:
	int empId; //��ʦ���
	
};
#endif 