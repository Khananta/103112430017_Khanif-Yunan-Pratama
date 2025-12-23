#ifndef BIOSKOP_H
#define BIOSKOP_H

#include <string>

using std::string;

struct NodeChild {
    string idFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeChild* next;
    NodeChild* prev;
};

struct ListChild {
    NodeChild* first;
    NodeChild* last;
};

struct NodeParent {
    string idGenre;
    string namaGenre;
    NodeParent* next;
    NodeParent* prev;
    ListChild child;
};

struct ListParent {
    NodeParent* first;
    NodeParent* last;
};

void createListParent(ListParent &LP);
void createListChild(ListChild &LC);

NodeParent* alokasiNodeParent(const string &idGenre, const string &namaGenre);
NodeChild*  alokasiNodeChild(const string &idFilm, const string &judulFilm, int durasiFilm, int tahunTayang, float ratingFilm);

void dealokasiNodeParent(NodeParent* &p);
void dealokasiNodeChild(NodeChild* &c);

void insertFirstParent(ListParent &LP, NodeParent* p);
void insertLastChild(ListChild &LC, NodeChild* c);

void deleteAfterParent(ListParent &LP, NodeParent* prevParent);
void hapusListChild(ListChild &LC);

void searchFilmByRatingRange(const ListParent &LP, float minR, float maxR);
void printStrukturMLL(const ListParent &LP);

void clearAll(ListParent &LP);

#endif