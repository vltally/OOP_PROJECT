#pragma once
#include <string>
#include <iostream>
class Person
{
public:
	virtual void showInfo() const = 0;
	virtual ~Person() {
		std::cout << "Person destructor\n";
	}
	virtual void Write(const std::string& filename) const = 0; // ����������� ����� ������ � ����
	virtual void Read(const std::string& filename) = 0;         // ����������� ����� ������� � �����
};

