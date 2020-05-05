#include "Artist.h"
using namespace  std;

Artist::Artist() {
	nume = NULL;
	data = NULL;
	locatie = NULL;
	locDisp = -1;
	locOcup = -1;
}
Artist::Artist(char* nume, char* data, char* locatie, int locDisp, int locOcup) {
	this->nume = new char[strlen(nume) + 1];
	strcpy_s(this->nume, strlen(nume) + 1, nume);
	this->data = new char[strlen(data) + 1];
	strcpy_s(this->data, strlen(data) + 1, data);
	this->locatie = new char[strlen(locatie) + 1];
	strcpy_s(this->locatie, strlen(locatie) + 1, locatie);
	this->locDisp = locDisp;
	this->locOcup = locOcup;
}

Artist::Artist(const Artist& a) {
	this->nume = new char[strlen(a.nume) + 1];
	strcpy_s(this->nume, strlen(a.nume) + 1, a.nume);
	this->data = new char[strlen(a.data) + 1];
	strcpy_s(this->data, strlen(a.data) + 1, a.data);
	this->locatie = new char[strlen(a.locatie) + 1];
	strcpy_s(this->locatie, strlen(a.locatie) + 1, a.locatie);
	this->locDisp = a.locDisp;
	this->locOcup = a.locOcup;


}
Artist& Artist::operator=(const Artist& a) {
	if (this != &a) {
		this->setNume(a.nume);
		this->setData(a.data);
		this->setLocatie(a.locatie);
		this->setLocDisp(a.locDisp);
		this->setLocOcup(a.locOcup);
	}
	return *this;
}
ostream& operator<<(ostream& os, Artist& a) {
	os << a.getNume() << ',' << a.getData() << ',' << a.getLocatie() << ',' << a.getLocDisp() << ',' << a.getLocOcup();
	return os;
}
istream& operator>>(istream& is, Artist& a) {
	is >> a.getNume() >> a.getData() >> a.getLocatie();
	return is;
}
Artist::~Artist() {}