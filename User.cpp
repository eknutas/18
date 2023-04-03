/* User.cpp homework 18.12 */

#include "User.h"

User::User(const std::string& name, const std::string& login, const std::string& password) :_name(name), _login(login), _password(password)
{
}

std::fstream& operator >> (std::fstream& is, User& _usr)
{
	is >> _usr._name;
	is >> _usr._login;
	is >> _usr._password;
	return is;
}

std::ostream& operator << (std::ostream& os, const User& _usr)
{
	os << _usr._name;
	os << ' ';
	os << _usr._login;
	os << ' ';
	os << _usr._password;
	return os;
}
