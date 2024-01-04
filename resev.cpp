#include "template.hpp"

void createListPelanggan(ListPelanggan& L)
{
    first(L) = NULL;
}

void createListKamar(ListKamar& L)
{
    first(L) = NULL;
}

addrPelanggan allocate(pelanggan p)
{
    addrPelanggan x = new ElmPelanggan;
    info(x) = p;
    hasRelation(x) = NULL;
    next(x) = NULL;
    return x;
}

addrKamar allocate2(kamar p)
{
    addrKamar x = new ElmKamar;
    info(x) = p;
    next(x) = NULL;
    return x;
}

void insertFirstPelanggan(ListPelanggan &L, addrPelanggan p){
    if (first(L) == NULL){
        first(L) = p;
    }else{
        next(p) = first(L);
        first(L) = p;
    }
}
void insertLastPelanggan(ListPelanggan& L, addrPelanggan p)
{
    if (first(L) == NULL){
        first(L) = p;
    }else{
        addrPelanggan j = first(L);
        while (next(j) != NULL){
            j = next(j);
        }
        next(j) = p;
    }
}
void insertFirstKamar(ListKamar &L, addrKamar p){
    if (first(L) == NULL){
        first(L) = p;
    }else{
        next(p) = first(L);
        first(L) = p;
    }
}
void insertLastKamar(ListKamar& L, addrKamar p)
{
    if (first(L) == NULL){
        first(L) = p;
    }else{
        addrKamar j = first(L);
        while (next(j) != NULL){
            j = next(j);
        }
        next(j) = p;
    }
}

addrPelanggan findPelangganByID(ListPelanggan L, pelanggan p)
{
    if (first(L) == NULL){
        cout << "List Pelanggan Kosong" << endl;
        return NULL;
    }else{
        addrPelanggan j = first(L);
        while (j != NULL && info(j).id != p.id){
            j = next(j);
        }

        if(info(j).id == p.id){
            return j;
        }else{
            return NULL;
        }

    }
}

void DeleteLastPelanggan(ListPelanggan &L, addrPelanggan p){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        addrPelanggan j = first(L);
        while (next(next(j)) != NULL){
            j = next(j);
        }
        p = j;
        next(j) = NULL;
    }
}

void DeleteFirstPelanggan(ListPelanggan &L, addrPelanggan p){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
    }
}
void deleteAfterPelanggan(ListPelanggan &L,addrPelanggan &prec){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        if (prec != NULL){
            addrPelanggan p = prec;
            next(prec) = next(p);
        }
    }
}
void DeleteFirstKamar(ListKamar &L, addrKamar p){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        p = first(L);
        first(L) = next(p);
        next(p) = NULL;
    }
}

void DeleteLastKamar(ListKamar &L, addrKamar p){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        addrKamar j = first(L);
        while (next(next(j)) != NULL){
            j = next(j);
        }
        p = j;
        next(j) = NULL;
    }
}


void deleteAfterKamar(ListKamar &L,addrKamar &prec){
    if (next(first(L)) == NULL){
        first(L) = NULL;
    }else{
        if (prec != NULL){
            addrKamar p = prec;
            next(prec) = next(p);
        }
    }

}

void DeletePelanggan(ListPelanggan &L, pelanggan p){
     addrPelanggan FindP = findPelangganByID(L, p);
    if (FindP != NULL) { // Check if the pelanggan is found
        hasRelation(FindP) = NULL;
        if (FindP == first(L)){
            DeleteFirstPelanggan(L,FindP);
        }else{
            deleteAfterPelanggan(L,FindP);
        }
         cout << "Pelanggan Bernama " << info(FindP).nama << " Sudah berhasil di hapus" << endl;
    } else {
        cout << "Pelanggan tidak di temukan" << endl;
    }
}

addrKamar findKamarByIDKamar(ListKamar L, kamar p)
{
    if (first(L) == NULL){
        cout << "List Kamar Kosong" << endl;
        return NULL;
    }else{
        addrKamar j = first(L);
        while (j != NULL && info(j).idKamar != p.idKamar){
            j = next(j);
        }

        if(info(j).idKamar == p.idKamar){
            return j;
        }else{
            return NULL;
        }

    }
}

addrKamar findKamarByJenis(ListKamar L, kamar p)
{
    if (first(L) == NULL){
        cout << "List Kamar Kosong" << endl;
        return NULL;
    }else{
        addrKamar j = first(L);
        while (j != NULL && info(j).jenis != p.jenis){
            j = next(j);
        }

        if(info(j).jenis == p.jenis){
            return j;
        }else{
            return NULL;
        }

    }
}

addrKamar cekKamarByPelanggan(ListPelanggan L, pelanggan pel, string idkamar){
      addrPelanggan FindP = findPelangganByID(L, pel);
    if (FindP != NULL) { // Check if the pelanggan is found
        addreRelation rl = hasRelation(FindP);
        cout << "relation" << endl;
        while (rl != NULL && info(relationPelanggan(rl)).id != pel.id) {
            rl = next(rl);
        }

        if (rl != NULL) {
            while (rl != NULL && info(relationKamar(rl)).idKamar != idkamar) {
                rl = next(rl);
            }

            if (rl != NULL) {
                return relationKamar(rl);
            } else {
                cout << "data kamar tidak di temukan" << endl;
            }
        } else {
            cout << "Pelanggan belum memesan kamar" << endl;
        }
    } else {
        cout << "Pelanggan tidak di temukan" << endl;
    }

    return NULL;
};

addreRelation AllocateRelation(addrPelanggan p1, addrKamar p2){
    addreRelation p = new relations;
    relationPelanggan(p) = p1;
    relationKamar(p) = p2;
    next(p) = NULL;
    return p;
};

void connect(ListPelanggan &L1, ListKamar L2,pelanggan infoPelanggan, kamar infoKamar){
    addrPelanggan FindPL = findPelangganByID(L1,infoPelanggan);
    addrKamar FindKm = findKamarByIDKamar(L2,infoKamar);
    if (FindPL != NULL && FindKm != NULL){
        if (hasRelation(FindPL) == NULL){
            hasRelation(FindPL) = AllocateRelation(FindPL,FindKm);
        }else{
            addreRelation j =  AllocateRelation(FindPL,FindKm);
            addreRelation p = hasRelation(FindPL);
            while (next(p) != NULL){
                p = next(p);
            }
            next(p) = j;
        }
    }else{
        cout << "Reservasi gagal, di karenakan data tidak di temukan" << endl;
    }
};

void DeleteKamar(ListPelanggan &L, ListKamar &L2, kamar infoKamar){
    addrKamar findKamar = findKamarByIDKamar(L2,infoKamar);
    if (findKamar != NULL){
        addrPelanggan p = first(L);
        while(p != NULL){
            addreRelation child = hasRelation(p);
            if (child != NULL){
                while(child != NULL && findKamar != relationKamar(child)){
                    child = next(child);
                }
                if(hasRelation(p) == child){
                    hasRelation(p) = next(hasRelation(p)); // delete first
                }else if(next(hasRelation(p)) == NULL){
                    addreRelation j = hasRelation(p); // delete last
                    while (next(j) != NULL){
                        j = next(j);
                    }
                    next(j) = NULL;
                }else{
                  addreRelation k = next(child); // delete after
                  next(child) = next(k);
                }
            }
            p = next(p);
        }
        if(first(L2) == findKamar){
            DeleteFirstKamar(L2,findKamar);
        }else if(next(findKamar) == NULL){
            cout << "test" << endl;
            DeleteLastKamar(L2,findKamar);
        }else{
            deleteAfterKamar(L2,findKamar);
        }
    }
}

void showPelanggan(ListPelanggan L){
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    }else{
        addrPelanggan j = first(L);
        cout << "List Pelanggan" << endl;
        while (j != NULL){
            cout << endl;
            cout << "ID Pelanggan : " << info(j).id << endl;
            cout << "Nama : " << info(j).nama << endl;
            cout << "Alamat : " << info(j).alamat << endl;
            cout << "Nomor Telepon : " << info(j).noTelp << endl;
            j = next(j);
        }
    };
};

void showKamar(ListKamar L)
{
    if (first(L) == NULL){
        cout << "List Kosong" << endl;
    }else{
        addrKamar j = first(L);
        cout << "List Kamar" << endl;
        while (j != NULL){
            cout << endl;
            cout << "ID Kamar : " <<info(j).idKamar << endl;
            cout << "Jenis : " <<info(j).jenis << endl;
            cout << "Harga : " <<info(j).harga << endl;
            cout << "Total pemasukan : " <<info(j).total_pemasukan << endl;
            j = next(j);
        }
    }
}

void showAll(ListPelanggan L){
     if (first(L) == NULL){
        cout << "List Kosong" << endl;
    }else{
        addrPelanggan j = first(L);
        int counter = 1;
        cout << "Show All List" << endl;
        while (j != NULL){
            cout << endl;
            cout << "List ke " << counter++ << endl;
            cout << "List Pelanggan" << endl;
            cout << "Id Pelanggan : " << info(j).id << endl;
            cout << "Nama : " << info(j).nama << endl;
            cout << "Alamat : " << info(j).alamat << endl;
            cout << "Nomor Telepon : " << info(j).noTelp << endl;
            cout << endl;
            if (hasRelation(j) != NULL){
                cout << "List Kamar yang di pesan " << info(j).nama  << endl;
                addreRelation k = hasRelation(j);
                while (k != NULL){
                    cout << "ID Kamar : " <<info(relationKamar(k)).idKamar << endl;
                    cout << "Jenis : " <<info(relationKamar(k)).jenis << endl;
                    cout << "Harga : " <<info(relationKamar(k)).harga << endl;
                    k = next(k);
                }
            };
            cout << endl;
            j = next(j);
        }
    }
};

void hitungPemasukan(ListPelanggan L, ListKamar &L2){
    addrKamar kmr = first(L2);
    while (kmr != NULL) {
        int counter = 0;
        addrPelanggan pel = first(L);
        bool isError = false;
        while (pel != NULL) {
            if (hasRelation(pel) != NULL) {
                addreRelation relationPelanggan = hasRelation(pel);
                while (relationPelanggan != NULL){
                if (info(relationKamar(relationPelanggan)).jenis == info(kmr).jenis) {
                    //cout << info(pel).nama << "True" << endl;
                    counter += info(relationKamar(relationPelanggan)).harga;
                } else {
                   //cout << info(pel).nama << "False" << endl;
                }
                 relationPelanggan = next(relationPelanggan);
                }
            } else {
                cout << "relasi kosong" << endl;
            }
            pel = next(pel);
        }
       
        addrKamar find = findKamarByJenis(L2, info(kmr));
        
        if (find != NULL && find != kmr){
            info(kmr).total_pemasukan += counter;
        }else{
            cout << "Jenis kamar " << info(kmr).jenis << " Mempunyai total pemasukan " << counter << endl;
            if (info(kmr).total_pemasukan != counter){
                info(kmr).total_pemasukan += counter;
            }
        }
        
      
        kmr = next(kmr);
    }
}
