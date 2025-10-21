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

void tambahDataSiswa() {
    int jumlahSiswa;
    cout << "Berapa banyak siswa yang ingin anda tambahkan? ";
    cin >> jumlahSiswa;
    cin.ignore();

    ofstream fileOutput("Datasiswa.txt",ios::app);

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
    ifstream fileOutput("Datasiswa.txt");
    string baris;

    while(getline(fileOutput,baris)){
        cout << baris << endl;
    }

    fileOutput.close();
}//membaca data dari file (sudah)

void cariSiswa();// berdasarkan NISN (belum)

float nilaiAkhir(nilai n){
    return (n.Mtk*0.4)+(n.BIn*0.2)+(n.IPA*0.3)+(n.BIn*0.2);
    
};// nilai akhir = 40%matematika+30%IPA+20%B indonesia +20%B Inggris(belum)

void ranking(); // menampilkan data siswa berdasarkan peringkatnya(belum)

int main()
{
    int menu;
    cout << "Masukkan Menu"<<endl;
    cout << "1. Tambah Data Siswa" << endl;
    cout << "2. Tampil Data Siswa" << endl;
    cout << "Pilih menu : ";
    cin >> menu;

    if(menu==1){
        tambahDataSiswa();
    }

    if(menu==2){
        tampilDataSiswa();
    }
    return 0;
} //program ini belum selesai, yang baru selesai hanyalah fungsi Tambah Data Siswa dan Tampil Data Siswa

