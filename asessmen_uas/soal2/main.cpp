#include <iostream>
#include "bioskop.h"

using namespace std;

int main() {
    ListParent LP;
    createListParent(LP);
    
    NodeParent* G004 = alokasiNodeParent("G004", "Romance");
    NodeParent* G003 = alokasiNodeParent("G003", "Horror");
    NodeParent* G002 = alokasiNodeParent("G002", "Comedy");
    NodeParent* G001 = alokasiNodeParent("G001", "Action");

    insertFirstParent(LP, G004);
    insertFirstParent(LP, G003);
    insertFirstParent(LP, G002);
    insertFirstParent(LP, G001);

    insertLastChild(G001->child, alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6f));

    insertLastChild(G002->child, alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0f));
    insertLastChild(G002->child, alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8f));

    insertLastChild(G003->child, alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4f));

    insertLastChild(G004->child, alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6f));
    insertLastChild(G004->child, alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6f));

    cout << "===== AWALL =====\n";
    printStrukturMLL(LP);

    cout << "\n===== SEARCH RATING 8.0 - 8.5 =====\n";
    searchFilmByRatingRange(LP, 8.0f, 8.5f);

    cout << "===== HAPUS =====\n";
    deleteAfterParent(LP, LP.first);

    cout << "\n===== SETELAH HAPUS =====\n";
    printStrukturMLL(LP);

    clearAll(LP);
    return 0;
}