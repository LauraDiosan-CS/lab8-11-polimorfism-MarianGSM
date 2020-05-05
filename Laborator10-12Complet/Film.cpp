#include "Film.h"
#include "MyException.h"
using namespace std;

Film::Film() {
	titlu = NULL;
	actori = NULL;
	data = NULL;
	loc = NULL;
	locDisp = -1;
	locOcup = -1;
}
Film::Film(char* titlu, char* actori, char* data, char* loc, int locDisp, int locOcup) {
	char* a; int x;
	if (typeid(titlu) != typeid(a))
		throw MyException("titlul nu e sir de caractere");
	this->titlu = new char[strlen(titlu) + 1];
	strcpy_s(this->titlu, strlen(titlu) + 1, titlu);
	this->actori = new char[strlen(actori) + 1];
	strcpy_s(this->actori, strlen(actori) + 1, actori);
	this->data = new char[strlen(data) + 1];
	strcpy_s(this->data, strlen(data) + 1, data);
	this->loc = new char[strlen(loc) + 1];
	strcpy_s(this->loc, strlen(loc) + 1, loc);
	if (typeid(locDisp) != typeid(x))
		throw MyException("numarul de locuri trebuie sa fie un numar natural");
	this->locDisp = locDisp;
	this->locOcup = locOcup;
}
Film::Film(const Film& f) {
	this->titlu = new char[strlen(f.titlu) + 1];
	strcpy_s(this->titlu, strlen(f.titlu) + 1, f.titlu);
	this->actori = new char[strlen(f.actori) + 1];
	strcpy_s(this->actori, strlen(f.actori) + 1, f.actori);
	this->data = new char[strlen(f.data) + 1];
	strcpy_s(this->data, strlen(f.data) + 1, f.data);
	this->loc = new char[strlen(f.loc) + 1];
	strcpy_s(this->loc, strlen(f.loc) + 1, f.loc);
	this->locDisp = f.locDisp;
	this->locOcup = f.locOcup;
}
Film& Film::operator=(const Film& f) {
	if (this != &f) {
		this->setTitlu(f.titlu);
		this->setActori(f.actori);
		this->setData(f.data);
		this->setLoc(f.loc);
		this->setLocDisp(f.locDisp);
		this->setLocOcup(f.locOcup);
	}
	return *this;
}
ostream& operator<<(ostream& os, Film& f) {
	os << f.getTitlu() << "," << f.getActori() << "," << f.getData() << "," << f.getLoc() << "," << f.getLocDisp() << "," << f.getLocOcup();
	return os;
}
Film::~Film() {}