/* main.cpp homework 18.12 */

#include <filesystem>
#include <string>
#include "User.h"
#include "Message.h"

int main() 
{
	User _usr;
	std::fstream user_file = std::fstream("users.txt", std::ios::in | std::ios::out);
	if (!user_file) {
		// Для создания файла используем параметр ios::trunc
		user_file = std::fstream("users.txt", std::ios::in | std::ios::out | std::ios::trunc);
	}
	if (!user_file) {
		std::cout << "Could not open file users.txt !" << '\n';
		return 0;
	}
	// Считываем данные из файла
	user_file >> _usr;
	user_file.seekg(0, std::ios_base::beg);
	std::string str;
	while (getline(user_file, str))
	{
		std::cout << str << '\n';
	}
 
	Message _msg;
	std::fstream user_file2 = std::fstream("messages.txt", std::ios::in | std::ios::out);
	if (!user_file2) {
		// Для создания файла используем параметр ios::trunc
		user_file2 = std::fstream("messages.txt", std::ios::in | std::ios::out | std::ios::trunc);
	}
	if (!user_file2) {
		std::cout << "Could not open file messagess.txt !" << '\n';
		return 0;
	}
	// Считываем данные из файла
	user_file2 >> _msg;
	user_file2.seekg(0, std::ios_base::beg);
	while (getline(user_file2, str))
	{
		std::cout << str << '\n';
	}

	// Запишем данные в файл
	user_file = std::fstream("users.txt", std::ios::out);
	_usr = User("Alex", "qwerty", "12345");
	user_file << _usr << '\n';
	_usr = User("Boris", "asdfgh", "67890");
	user_file << _usr << '\n';
	_usr = User("Clara", "zxcvbn", "01234");
	user_file << _usr << '\n';
	_usr = User("David", "qazwsx", "56789");
	user_file << _usr << '\n';
	user_file.close();
	std::filesystem::permissions("users.txt", std::filesystem::perms::owner_exec |
		std::filesystem::perms::group_all | std::filesystem::perms::others_all,
		std::filesystem::perm_options::remove);

	// Запишем данные в файл
	user_file2 = std::fstream("messages.txt", std::ios::out);
	_msg = Message("Hello, Alex!", "Boris", "Clara");
	user_file2 << _msg << '\n';
	_msg = Message("Hello, Boris!", "Clara", "Alex");
	user_file2 << _msg << '\n';
	_msg = Message("Hello, Clara!", "Boris", "Alex");
	user_file2 << _msg << '\n';
	user_file2.close();
	std::filesystem::permissions("messages.txt", std::filesystem::perms::owner_exec |
		std::filesystem::perms::group_all | std::filesystem::perms::others_all,
		std::filesystem::perm_options::remove);
}
