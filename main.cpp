#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct nilai{
    float Mtk;
    float BIn;
    float Big;
    float IPA;
    float akhir;
};
struct siswa{
    string nama;
    string NISN;
    string jurusan;
    nilai Nilai; // struct in struct
};

float nilaiAkhir(nilai n){
    return (n.Mtk*0.4)+(n.BIn*0.2)+(n.IPA*0.3)+(n.BIn*0.2);
    
};

void tambahDataSiswa() {
    int jumlahSiswa;
    cout << "Berapa banyak siswa yang ingin anda tambahkan? ";
    cin >> jumlahSiswa;
    cin.ignore();

    ofstream fileOutput("Siswa.txt",ios::app);

    for(int i=0;i<jumlahSiswa;i++) {
    siswa data;
    cout << "Masukkan Data Siswa ke-" << i+1 << endl;
    cout << "Nama : ";
    getline(cin,data.nama);
    cout << "Nisn : ";
    getline(cin,data.NISN);
    cout << "Jurusan : ";
    getline(cin,data.jurusan);
    cout << "Nilai dari "<<data.nama<<endl;
    cout << "Nilai Matematika : ";
    cin >> data.Nilai.Mtk;
    cout << "Nilai Bahasa Indonesia : ";
    cin >> data.Nilai.BIn;
    cout << "Nilai Bahasa Inggris : ";
    cin >> data.Nilai.Big;
    cout << "Nilai IPA : ";
    cin >> data.Nilai.IPA;
    cin.ignore();

    data.Nilai.akhir = nilaiAkhir(data.Nilai);

    fileOutput << "Nama  : " << data.nama<< " - " << "NISN : " << data.NISN<< " - " << "Jurusan : "<< data.jurusan<<endl;
    fileOutput << "Nilai dari "<<data.nama<<" / "
               << "Matematika : "<<data.Nilai.Mtk<<", "
               << "Bahasa Indonesia : "<<data.Nilai.BIn<<", "
               << "Nilai Bahasa Inggris : "<<data.Nilai.Big<<", "
               << "Nilai IPA : "<<data.Nilai.IPA<<endl
               << "Nilai Akhir : "<<data.Nilai.akhir<<endl<<endl;

    
    }
    fileOutput.close();
    cout << "Data Tersimpan"<<endl;

}//menambahkan data (sudah)

void tampilDataSiswa(){
    ifstream fileOutput("Siswa.txt");
    string baris;

    if(!fileOutput.is_open()){
        cout << "File belum ada atau tidak bisa dibuka!" << endl;
        return;
    }

    while(getline(fileOutput,baris)){
        cout << baris << endl;
    }

    fileOutput.close();
}//membaca data dari file (sudah)

void cariSiswa(){
   void cariSiswa() {
    ifstream fileInput("Siswa.txt");
    if (!fileInput.is_open()) {
        cout << "File belum ada atau tidak bisa dibuka!" << endl;
        return;
    }

    string katakunci;
    cout << "Masukkan NISN yang ingin dicari: ";
    getline(cin, katakunci);

    string baris;
    bool ditemukan = false;

    cout << "\n=== Hasil Pencarian ===" << endl;

    while (getline(fileInput, baris)) {
        if (baris.size() >= 4 && 
            baris[0] == 'N' && baris[1] == 'a' && baris[2] == 'm' && baris[3] == 'a') {

            string nisn_ditemukan = "";
            int i = 0;

            while (i < baris.size() - 3) {
                if (baris[i] == 'N' && baris[i + 1] == 'I' && 
                    baris[i + 2] == 'S' && baris[i + 3] == 'N') {
                    i += 7; 

                    while (i < baris.size() && baris[i] != ' ' && baris[i] != '-') {
                        nisn_ditemukan = nisn_ditemukan + baris[i];
                        i++;
                    }
                    break;
                }
                i++;
            }

            bool sama = true;
            if (nisn_ditemukan.size() != katakunci.size()) {
                sama = false;
            } else {
                for (int k = 0; k < katakunci.size(); k++) {
                    if (nisn_ditemukan[k] != katakunci[k]) {
                        sama = false;
                        break;
                    }
                }
            }

            if (sama) {
                ditemukan = true;
                cout << baris << endl;

                for (int j = 0; j < 3 && getline(fileInput, baris); j++) {
                    cout << baris << endl;
                }

                cout << endl;
            }
        }
    }
}

};// berdasarkan NISN (sudah)

void ranking(); // menampilkan data siswa berdasarkan peringkatnya(belum)

int main()
{
    int menu;
    cout << "Masukkan Menu"<<endl;
    cout << "1. Tambah Data Siswa" << endl;
    cout << "2. Tampil Data Siswa" << endl;
    cout << "3. Cari Berdasarkan NISN"<<endl;
    cout << "Pilih menu : ";
    cin >> menu;
    cin.ignore();

    if(menu==1){
        tambahDataSiswa();
    }

    if(menu==2){
        tampilDataSiswa();
    }

    if(menu==3){
        cariSiswa();
    }

    return 0;
} //program ini belum selesai, yang baru selesai hanyalah fungsi Tambah Data Siswa dan Tampil Data Siswa

