/* Message.cpp homework 18.12 */

#include "Message.h"

Message::Message(const std::string& text, const std::string& sender, const std::string& receiver) :_text(text), _sender(sender), _receiver(receiver)
{
}

std::fstream& operator >> (std::fstream& is, Message& _msg)
{
	is >> _msg._text;
	is >> _msg._sender;
	is >> _msg._receiver;
	return is;
}

std::ostream& operator << (std::ostream& os, const Message& _msg)
{
	os << _msg._text;
	os << ' ';
	os << _msg._sender;
	os << ' ';
	os << _msg._receiver;
	return os;
}
