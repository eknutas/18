/* Message.h homework 18.12 */

#pragma once
#include <fstream>
#include <iostream>

class Message {
	std::string _text;
	std::string _sender;
	std::string _receiver;
public:
	Message(const std::string& text, const std::string& sender, const std::string& receiver);

	Message() = default;

	~Message() = default;

	friend std::fstream& operator >> (std::fstream& is, Message& _msg);

	friend std::ostream& operator << (std::ostream& os, const Message& _msg);
};
