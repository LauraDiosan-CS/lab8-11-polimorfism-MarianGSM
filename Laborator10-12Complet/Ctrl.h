#pragma once
#include "Repo.h"
#include "Artist.h"
#include "Film.h"
#include "Utilizator.h"
#include "RepoEvent.h"
#include <vector>
class Ctrl {
private:
	Repo<Artist> artisti;
	Repo<Film> filme;
	RepoEvent events;
	Repo<Utilizator> useri;
public:
	Ctrl(vector<Artist> artisti, vector<Film> filme, vector<Utilizator> useri) {
		this->artisti.setElemente(artisti);
		this->filme.setElemente(filme);
	}
	void citireArtisti() { artisti.citireArtisti(); }
	void citireFilme() { filme.citireFilme(); }
	void citireUseri() { useri.citireUseri(); }
	Repo<Utilizator> getUseri() { return this->useri; }
	void populareEvents() {
		char nume[20], data[15], locatie[30]; int nr = 0, i;
		for (i = 0; i < artisti.getAll().size(); i++) {
			strcpy_s(nume, artisti.getAll()[i].getNume());
			strcpy_s(data, artisti.getAll()[i].getData());
			strcpy_s(locatie, artisti.getAll()[i].getLocatie());
			int locDisp = artisti.getAll()[i].getLocDisp();
			int locOcup = artisti.getAll()[i].getLocOcup();
			Event* e = new Artist(nume, data, locatie, locDisp, locOcup);
			events.getAll()[nr] = e; nr++;
		}
		char titlu[30], actori[100], loc[20];
		for (i = 0; i < filme.getAll().size(); i++) {
			strcpy_s(titlu, filme.getAll()[i].getTitlu());
			strcpy_s(actori, filme.getAll()[i].getActori());
			strcpy_s(data, filme.getAll()[i].getData());
			strcpy_s(loc, filme.getAll()[i].getLoc());
			int locDisp = filme.getAll()[i].getLocDisp();
			int locOcup = filme.getAll()[i].getLocOcup();
			Event* e = new Film(titlu, actori, data, loc, locDisp, locOcup);
			events.getAll()[nr] = e; nr++;
		}
	}
	void afisareFisier(ofstream& g) {
		g << "concerte";
		g << endl; char* s;
		vector<Event*> all = events.getAll();
		for (Event* e : all) {
			g << e->toString() << endl;
		}
		char head[100] = "nume artist,data spetacol,locatie,locuri disponibile,locuri ocupate";
		char head2[50] = "titlu film,actori,data,locatia,locDisp,locOcup";
		artisti.afisareFisier(g, head);
		g << "filme" << endl;
		filme.afisareFisier(g, head2);
	}
	void afisareEvents(ofstream& g) {
		char head3[15] = "evenimente";
		g << head3;
	}
	bool Login(char* user) {
		char pass[20];
		for (int i = 0; i < useri.getAll().size(); i++)
			if (strcmp(user, useri.getAll()[i].getUser()) == 0) {
				cout << "dati parola: ";
				cin >> pass;
				if (strcmp(pass, useri.getAll()[i].getPass()) == 0)
					return true;
			}
		return false;
	}
	void cautareEvenimente(Event* events[], char* numeEvent, ofstream& g) {
		int nr = 0;
		int i;
		for (i = 0; i < artisti.getAll().size(); i++)
			if (strcmp(numeEvent, artisti.getAll()[i].getNume()) == 0) {
				char nume[20], data[15], locatie[30];
				strcpy_s(nume, artisti.getAll()[i].getNume());
				strcpy_s(data, artisti.getAll()[i].getData());
				strcpy_s(locatie, artisti.getAll()[i].getLocatie());
				int locDisp = artisti.getAll()[i].getLocDisp();
				int locOcup = artisti.getAll()[i].getLocOcup();
				Event* e = new Artist(nume, data, locatie, locDisp, locOcup);
				events[nr] = e;
				nr++;
			}
		for (i = 0; i < filme.getAll().size(); i++)
			if (strcmp(numeEvent, filme.getAll()[i].getTitlu()) == 0) {
				char titlu[30], actori[100], data[15], loc[20];
				strcpy_s(titlu, filme.getAll()[i].getTitlu());
				strcpy_s(actori, filme.getAll()[i].getActori());
				strcpy_s(data, filme.getAll()[i].getData());
				strcpy_s(loc, filme.getAll()[i].getLoc());
				int locDisp = filme.getAll()[i].getLocDisp();
				int locOcup = filme.getAll()[i].getLocOcup();
				Event* e = new Film(titlu, actori, data, loc, locDisp, locOcup);
				events[nr] = e;
				nr++;
			}
		g << endl << "evenimentele cu denumirea precizata" << endl;
		for (i = 0; i < artisti.getAll().size(); i++)
			if (strcmp(numeEvent, artisti.getAll()[i].getNume()) == 0)
				g << artisti.getAll()[i] << endl;
		for (i = 0; i < filme.getAll().size(); i++)
			if (strcmp(numeEvent, filme.getAll()[i].getTitlu()) == 0)
				g << filme.getAll()[i] << endl;
	}
	void cumparare(Event* events[], char* numeEvent, int nrBilete, ofstream& g) {
		int i = 0; bool ok = false, ok2 = false;
		g << endl << "lista de evenimente actuala: " << endl;
		while (i < artisti.getAll().size()) {
			if (strcmp(numeEvent, artisti.getAll()[i].getNume()) == 0 && ok == false) {
				if (nrBilete <= artisti.getAll()[i].getLocDisp()) {
					ok = true;
					Artist a = artisti.getAll()[i];
					a.setLocDisp(artisti.getAll()[i].getLocDisp() - nrBilete);
					a.setLocOcup(artisti.getAll()[i].getLocOcup() + nrBilete);
					g << a << endl;
				}
				else g << artisti.getAll()[i] << endl;
				ok2 = true;
			}
			else g << artisti.getAll()[i] << endl;
			i++;
		}
		if (ok2 == true && ok == false)g << "Nu sunt locuri disponibile la concert!";
		i = 0; ok = false; ok2 = false;
		while (i < filme.getAll().size()) {
			if (strcmp(numeEvent, filme.getAll()[i].getTitlu()) == 0 && ok == false) {
				if (nrBilete <= filme.getAll()[i].getLocDisp()) {
					ok = true;
					Film f = filme.getAll()[i];
					f.setLocDisp(filme.getAll()[i].getLocDisp() - nrBilete);
					f.setLocOcup(filme.getAll()[i].getLocOcup() + nrBilete);
					g << f << endl;
				}
				else g << filme.getAll()[i] << endl;
				ok2 = true;
			}
			else g << filme.getAll()[i] << endl;
			i++;
		}
		if (ok2 == true && ok == false)g << "Nu mai sunt locuri disponibile la film!";
	}
};