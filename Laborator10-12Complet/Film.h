#pragma once
#include <vector>
#include <iostream>
#include "Event.h"
using namespace std;
class Film :public Event {
private:
	char* titlu;
	char* actori;
	char* data;
	char* loc;
	int locDisp;
	int locOcup;
public:
	Film();
	Film(char*, char*, char*, char*, int, int);
	Film(const Film&);
	char* getTitlu() { return this->titlu; }
	char* getActori() { return this->actori; }
	char* getData() { return this->data; }
	char* getLoc() { return this->loc; }
	int getLocOcup() { return this->locOcup; }
	int getLocDisp() { return this->locDisp; }
	void setTitlu(char* titlu) {
		if (this->titlu)delete[] this->titlu;
		this->titlu = new char[strlen(titlu) + 1];
		strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
	}
	void setActori(char* actori) {
		if (this->actori)delete[] this->actori;
		this->actori = new char[strlen(actori) + 1];
		strcpy_s(this->actori, strlen(actori) + 1, actori);
	}
	void setData(char* data) {
		if (this->data)delete[] this->data;
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	void setLoc(char* loc) {
		if (this->loc)delete[] this->loc;
		this->loc = new char[strlen(loc) + 1];
		strcpy_s(this->loc, strlen(loc) + 1, loc);
	}
	void setLocDisp(int locDisp) { this->locDisp = locDisp; }
	void setLocOcup(int locOcup) { this->locOcup = locOcup; }
	Film& operator=(const Film&);
	char* toString() {
		char* s = new char[70]; char* aux = new char[10];
		strcat_s(s, strlen(this->titlu) + 1, this->titlu);
		strcat_s(s, 1, ","); strcat_s(s, strlen(this->actori), this->actori);
		strcat_s(s, 1, ","); strcat_s(s, strlen(this->data), this->data);
		strcat_s(s, 1, ","); strcat_s(s, strlen(this->loc), this->loc);
		_itoa_s(this->locDisp, aux, strlen(aux), 10);
		strcat_s(s, 1, ","); strcat_s(s, strlen(aux) + 1, aux);
		_itoa_s(this->locOcup, aux, strlen(aux), 10);
		strcat_s(s, 1, ","); strcat_s(s, strlen(aux) + 1, aux);
		return s;
	}
	friend ostream& operator<<(ostream& os, Film& f);
	~Film();
};