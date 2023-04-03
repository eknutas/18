/* User.h homework 18.12 */

#pragma once
#include <fstream>
#include <iostream>

class User {
	std::string _name;
	std::string _login;
	std::string _password;

public:
	User(const  std::string& name, const std::string& login, const std::string& password);

	User() = default;

	~User() = default;

	friend std::fstream& operator >> (std::fstream& is, User& _usr);

	friend std::ostream& operator << (std::ostream& os, const User& _usr);
};


