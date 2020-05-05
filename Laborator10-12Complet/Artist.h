#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Event.h"
using namespace std;

class Artist :public Event {
private:
	char* nume;
	char* data;
	char* locatie;
	int locDisp;
	int locOcup;
public:
	Artist();
	Artist(char*, char*, char*, int, int);
	Artist(const Artist&);
	char* getNume() { return this->nume; }
	char* getData() { return this->data; }
	char* getLocatie() { return this->locatie; }
	int getLocDisp() { return this->locDisp; }
	int getLocOcup() { return this->locOcup; }
	void setNume(char* nume) {
		if (this->nume)delete[] this->nume;
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);
	}
	void setData(char* data) {
		if (this->data)delete[] this->data;
		this->data = new char[strlen(data) + 1];
		strcpy_s(this->data, strlen(data) + 1, data);
	}
	void setLocatie(char* locatie) {
		if (this->locatie)delete[] this->locatie;
		this->locatie = new char[strlen(locatie) + 1];
		strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
	}
	void setLocDisp(int locDisp) { this->locDisp = locDisp; }
	void setLocOcup(int locOcup) { this->locOcup = locOcup; }
	Artist& operator=(const Artist&);
	char* toString() {
		char* s = new char[70]; char* aux = new char[10];
		strcat_s(s, strlen(this->nume) + 1, this->nume);
		strcat_s(s, 1, ","); strcat_s(s, strlen(this->data) + 1, this->data);
		strcat_s(s, 1, ","); strcat_s(s, strlen(this->locatie) + 1, this->locatie);
		_itoa_s(this->locDisp, aux, strlen(aux), 10);
		strcat_s(s, 1, ","); strcat_s(s, strlen(aux) + 1, aux);
		_itoa_s(this->locOcup, aux, strlen(aux), 10);
		strcat_s(s, 1, ","); strcat_s(s, strlen(aux) + 1, aux);
		return s;
	}
	friend ostream& operator<<(ostream& os, Artist& a);
	friend istream& operator>>(istream& is, Artist& a);
	~Artist();
};