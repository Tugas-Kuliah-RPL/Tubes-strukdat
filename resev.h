#ifndef RESEV_H_INCLUDED
#define RESEV_H_INCLUDED

#include <iostream>

using namespace std;

#define first(L)(L.first)
#define last(L)(L.last)
#define info(p)(p->info)
#define next(p)p->next
#define hasRelation(p)(p->reliatons)
#define relationPelanggan(p)p->infoPelanggan
#define relationKamar(p)p->infoKamar

typedef struct ElmPelanggan *addrPelanggan;
typedef struct ElmKamar *addrKamar;
typedef struct relations *addreRelation;

struct pelanggan{
  int id;
  string nama;
  string alamat;
  int noTelp;
};

struct kamar {
    string idKamar;
    string jenis;
    int harga;
    int total_pemasukan;
};
struct ElmPelanggan {
    pelanggan info;
    addreRelation reliatons;
    addrPelanggan next;
};

struct ElmKamar {
    kamar info;
    addrKamar next;
};

struct relations {
    addrPelanggan infoPelanggan;
    addrKamar infoKamar;
    addreRelation next;
};

struct ListPelanggan {
    addrPelanggan first;
};

struct ListKamar {
    addrKamar first;
};

void createListPelanggan(ListPelanggan &L);
void createListKamar(ListKamar &L);
addrPelanggan allocate(pelanggan p);
addrKamar allocate2(kamar p);
void insertFirstPelanggan(ListPelanggan &L, addrPelanggan p);
void insertLastPelanggan(ListPelanggan &L, addrPelanggan p);
void insertFirstKamar(ListKamar &L, addrKamar p);
void insertLastKamar(ListKamar &L, addrKamar p);
void DeleteFirstPelanggan(ListPelanggan &L, addrPelanggan p);
void DeleteLastPelanggan(ListPelanggan &L, addrPelanggan p);
void deleteAfterPelanggan(ListPelanggan &L,addrPelanggan &prec);
void DeletePelanggan(ListPelanggan &L, pelanggan p);
void DeleteFirstKamar(ListKamar &L, addrKamar p);
void DeleteLastKamar(ListKamar &L, addrKamar p);
void deleteAfterKamar(ListKamar &L,addrKamar &prec);
void DeleteKamar(ListPelanggan &L, ListKamar &L2, kamar infoKamar);
addrPelanggan findPelangganByID(ListPelanggan P1, pelanggan p);
addrKamar findKamarByIDKamar(ListKamar P2, kamar p);
addrKamar cekKamarByPelanggan(ListPelanggan L, pelanggan pel, string idkamar);
void showPelanggan(ListPelanggan P1);
void showKamar(ListKamar p2);
void connect(ListPelanggan &L1, ListKamar L2,pelanggan infoP1, kamar infoP2);
void showAll(ListPelanggan L);
void hitungPemasukan(ListPelanggan L, ListKamar &L2);

#endif // RESEV_H_INCLUDED
