#include "resev.h"

int main()
{
    ListPelanggan LP;
    ListKamar LK;

    createListPelanggan(LP);
    createListKamar(LK);

    pelanggan pel;
    kamar km;

    int choice;
    do {
        cout << "Menu:\n";
        cout << "1. Tambah data ke ListPelanggan\n";
        cout << "2. Tambah data ke ListKamar\n";
        cout << "3. Hubungkan data dari ListPelanggan ke ListKamar\n";
        cout << "4. Tampilkan ListPelanggan\n";
        cout << "5. Tampilkan ListKamar\n";
        cout << "6. Tampilkan relasi List pelanggan dan kamar\n";
        cout << "7. Cek kamar yang tersedia bedasarkan pelanggan\n";
        cout << "8. Hapus data pelanggan\n";
        cout << "9. Hapus data Kamar\n";
        cout << "10. Hitung pemasukan\n";
        cout << "0. Keluar\n";
        cout << "Pilihan Anda: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                // Tambah data ke ListP1
                pelanggan pel;
                cout << "Masukkan data untuk ListPelanggan: \n";
                cout << "ID: ";
                cin >> pel.id;
                cout << "Nama: ";
                cin >> pel.nama;
                cout << "Alamat: ";
                cin >> pel.alamat;
                cout << "Nomer Telepon: ";
                cin >> pel.noTelp;
                addrPelanggan PointPel = allocate(pel);
                insertLastPelanggan(LP, PointPel);
                break;
            }
            case 2: {
                // Tambah data ke ListP2
                kamar km;
                cout << "Masukkan data untuk ListKamar:\n";
                cout << "Nomer Kamar: ";
                cin >> km.idKamar;
                cout << "Jenis kamar: ";
                cin >> km.jenis;
                cout << "Harga: ";
                cin >> km.harga;
                km.total_pemasukan = 0;
                addrKamar PointKm = allocate2(km);
                insertLastKamar(LK,PointKm);
                break;
            }
            case 3: {
                // Hubungkan data dari ListP1 ke ListP2
                pelanggan infoP;
                kamar infoK;

                cout << "Masukan data id pelanggan dan nomer kamar untuk di reservasi \n";
                cout << "Masukan id Pelanggan:\n";
                cout << "Id Pelanggan: ";
                cin >> infoP.id;

                cout << "Masukan Nomer Kamar: ";
                cin >> infoK.idKamar;

                connect(LP, LK, infoP, infoK);
                break;
            }
            case 4:
                // Tampilkan ListP1
                showPelanggan(LP);
                break;
            case 5:
                // Tampilkan ListP2
                showKamar(LK);
                break;
            case 6:
                // Tampilkan parameternya parent nya
                showAll(LP);
                break;
            case 7:
                addrKamar terdaftar;
                cout << "Masukkan data pelanggan: \n";
                cout << "ID: ";
                cin >> pel.id;
                cout << "Nama: ";
                cin >> pel.nama;
                cout << "Alamat: ";
                cin >> pel.alamat;
                cout << "Masukkan data untuk ListKamar:\n";
                cout << "Nomer Kamar: ";
                cin >> km.idKamar;
                terdaftar = cekKamarByPelanggan(LP,pel,km.idKamar);
                if (terdaftar != NULL){
                    cout << "Pelanggan terdaftar di kamar tersebut" << endl;
                }else{
                    cout << "Pelanggan tidak tedaftar di kamar tersebut" << endl;
                }
                break;
            case 8:
                cout << "Masukkan data pelanggan: \n";
                cout << "ID: ";
                cin >> pel.id;
                cout << "Nama: ";
                cin >> pel.nama;
                cout << "Alamat: ";
                cin >> pel.alamat;
                DeletePelanggan(LP,pel);
            case 9:
                cout << "Masukkan data kamar yang ingin di hapus: \n";
                cout << "Id Kamar: ";
                cin >> km.idKamar;
                cout << "Jenis Kamar: ";
                cin >> km.jenis;
                DeleteKamar(LP,LK,km);
             case 10:
                cout << "Pemasukan setiap jenis kamar: \n";
                hitungPemasukan(LP,LK);
            case 0:
                cout << "Program selesai.\n";
                break;
            default:
                cout << "Pilihan tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 0);

    return 0;
}
