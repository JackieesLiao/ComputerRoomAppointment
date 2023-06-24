#ifndef  _IDENTITY_
#define _IDENTITY_
/*³éÏó»ùÀà*/
#include<string>
#include<fstream>
class Identity
{
public:
	virtual void operateMenu() = 0;
	std::string m_name;
	std::string m_password;
};
#endif // ! _IDENTITY_
