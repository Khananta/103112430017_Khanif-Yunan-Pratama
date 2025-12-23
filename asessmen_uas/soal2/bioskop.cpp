#include "bioskop.h"
#include <iostream>
#include <cmath>

using namespace std;

static bool isIntegerFloat(float x) {
    return fabs(x - round(x)) < 1e-6;
}

static void printRating(float r) {
    if (isIntegerFloat(r)) cout << (int)round(r);
    else {
        cout.setf(std::ios::fixed);
        cout.precision(1);
        cout << r;
        cout.unsetf(std::ios::fixed);
        cout.precision(6);
    }
}

void createListParent(ListParent &LP) {
    LP.first = nullptr;
    LP.last  = nullptr;
}

void createListChild(ListChild &LC) {
    LC.first = nullptr;
    LC.last  = nullptr;
}

NodeParent* alokasiNodeParent(const string &idGenre, const string &namaGenre) {
    NodeParent* p = new NodeParent;
    p->idGenre = idGenre;
    p->namaGenre = namaGenre;
    p->next = nullptr;
    p->prev = nullptr;
    createListChild(p->child);
    return p;
}

NodeChild* alokasiNodeChild(const string &idFilm, const string &judulFilm,
                            int durasiFilm, int tahunTayang, float ratingFilm) {
    NodeChild* c = new NodeChild;
    c->idFilm = idFilm;
    c->judulFilm = judulFilm;
    c->durasiFilm = durasiFilm;
    c->tahunTayang = tahunTayang;
    c->ratingFilm = ratingFilm;
    c->next = nullptr;
    c->prev = nullptr;
    return c;
}

void dealokasiNodeParent(NodeParent* &p) {
    delete p;
    p = nullptr;
}

void dealokasiNodeChild(NodeChild* &c) {
    delete c;
    c = nullptr;
}

void insertFirstParent(ListParent &LP, NodeParent* p) {
    if (!LP.first) {
        LP.first = LP.last = p;
    } else {
        p->next = LP.first;
        LP.first->prev = p;
        LP.first = p;
    }
}

void insertLastChild(ListChild &LC, NodeChild* c) {
    if (!LC.first) {
        LC.first = LC.last = c;
    } else {
        c->prev = LC.last;
        LC.last->next = c;
        LC.last = c;
    }
}

void hapusListChild(ListChild &LC) {
    NodeChild* cur = LC.first;
    while (cur) {
        NodeChild* del = cur;
        cur = cur->next;
        dealokasiNodeChild(del);
    }
    LC.first = LC.last = nullptr;
}

void deleteAfterParent(ListParent &LP, NodeParent* prevParent) {
    if (!prevParent) return;
    NodeParent* target = prevParent->next;
    if (!target) return;

    hapusListChild(target->child);

    prevParent->next = target->next;
    if (target->next) target->next->prev = prevParent;
    else LP.last = prevParent;

    dealokasiNodeParent(target);
}

void searchFilmByRatingRange(const ListParent &LP, float minR, float maxR) {
    int posParent = 1;
    NodeParent* p = LP.first;

    while (p) {
        int posChild = 1;
        NodeChild* c = p->child.first;

        while (c) {
            if (c->ratingFilm >= minR && c->ratingFilm <= maxR) {
                cout << "Data Film ditemukan pada list child dari node parent "
                     << p->namaGenre << " pada posisi ke-" << posChild << "!\n";
                cout << "--- Data Film (Child) ---\n";
                cout << "Judul Film : " << c->judulFilm << "\n";
                cout << "Posisi dalam list child : posisi ke-" << posChild << "\n";
                cout << "ID Film : " << c->idFilm << "\n";
                cout << "Durasi Film : " << c->durasiFilm << " menit\n";
                cout << "Tahun Tayang : " << c->tahunTayang << "\n";
                cout << "Rating Film : ";
                printRating(c->ratingFilm);
                cout << "\n";
                cout << "--------------------------\n";
                cout << "--- Data Genre (Parent) ---\n";
                cout << "ID Genre : " << p->idGenre << "\n";
                cout << "Posisi dalam list parent : posisi ke-" << posParent << "\n";
                cout << "Nama Genre : " << p->namaGenre << "\n";
                cout << "===========================\n\n";
            }
            c = c->next;
            posChild++;
        }

        p = p->next;
        posParent++;
    }
}

void printStrukturMLL(const ListParent &LP) {
    int idxParent = 1;
    NodeParent* p = LP.first;

    while (p) {
        cout << "=== Parent " << idxParent << " ===\n";
        cout << "ID Genre : " << p->idGenre << "\n";
        cout << "Nama Genre : " << p->namaGenre << "\n";

        int idxChild = 1;
        NodeChild* c = p->child.first;

        while (c) {
            cout << "  - Child " << idxChild << " :\n";
            cout << "      ID Film : " << c->idFilm << "\n";
            cout << "      Judul Film : " << c->judulFilm << "\n";
            cout << "      Durasi Film : " << c->durasiFilm << " menit\n";
            cout << "      Tahun Tayang : " << c->tahunTayang << "\n";
            cout << "      Rating Film : ";
            printRating(c->ratingFilm);
            cout << "\n";
            c = c->next;
            idxChild++;
        }

        cout << "------------------------------\n";
        p = p->next;
        idxParent++;
    }
}

void clearAll(ListParent &LP) {
    while (LP.first) {
        if (LP.first->next) {
            deleteAfterParent(LP, LP.first);
        } else {
            hapusListChild(LP.first->child);
            NodeParent* last = LP.first;
            LP.first = LP.last = nullptr;
            dealokasiNodeParent(last);
        }
    }
}