#pragma once
#include <iostream>
class Event {
public:
	Event();
	virtual char* toString() {
		char* n = new char[1];
		strcpy_s(n, 1, " ");
		return n;
	}
	virtual ~Event();
};