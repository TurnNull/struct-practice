#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

void menu() {
    system("cls");
    cout<<"Aplikasi Struct Data"<<"\n";       
    cout<<"1. Menu Buat Data"<<"\n";            
    cout<<"2. Menu Lihat Data"<<"\n";            
    cout<<"3. Menu Ubah"<<"\n";           
    cout<<"4. Menu Keempat"<<"\n";            
    cout<<"5. Exit"<<"\n";           
    cout<<"Masukan angka :";        
}

struct mahasiswa {
    string nim;
    string nama;
    string alamat;
    float ipk;
};

mahasiswa sikc[30];
int pos=-1;
int userNp;
void buatData() {
    system("cls");
    cout<<"Masukan panjang data : ";
    cin>>userNp;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    for (pos++; pos < userNp; pos++) { 
    cout<<"\n---- ssss ----\n";
        cout << "Masukan NIM: ";
        getline(cin, sikc[pos].nim);

        cout << "Masukan Nama: ";
        getline(cin, sikc[pos].nama);

        cout << "Masukan Alamat: ";
        getline(cin, sikc[pos].alamat);

        cout << "Masukan IPK: ";
        cin >> sikc[pos].ipk;

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

void tampilkanData(int pos) {
  for (int i = 0; i < pos; i++) {
        cout << "\nData ke-" << (i + 1) << ":\n";
        cout << "NIM    : " << sikc[i].nim << "\n";
        cout << "Nama   : " << sikc[i].nama << "\n";
        cout << "Alamat : " << sikc[i].alamat << "\n";
        cout << "IPK    : " << sikc[i].ipk << "\n";
    }
    cout << "\n--------------------------------\n";
    getch();
}

void ubahData(int pos) {
    int nomor;
    cout << "Masukkan nomor data yang ingin diubah: ";
    cin >> nomor;

    int index = nomor - 1;
    cout << "\n---- Data Lama ----\n";
    cout << "NIM    : " << sikc[index].nim << "\n";
    cout << "Nama   : " << sikc[index].nama << "\n";
    cout << "Alamat : " << sikc[index].alamat << "\n";
    cout << "IPK    : " << sikc[index].ipk << "\n";

    cout << "\nMasukkan data baru:\n";

    cout << "Masukan NIM: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, sikc[index].nim);

    cout << "Masukan Nama: ";
    getline(cin, sikc[index].nama);

    cout << "Masukan Alamat: ";
    getline(cin, sikc[index].alamat);

    cout << "Masukan IPK: ";
    while (!(cin >> sikc[index].ipk) || sikc[index].ipk < 0.0 || sikc[index].ipk > 4.0) {
        cout << "Input IPK tidak valid. Masukkan angka antara 0.0 dan 4.0: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cout << "\nData berhasil diubah!\n";
}

int main() {
char pl;
do {
  menu();
  pl=getch();
  switch (pl) {
    case '1':
      buatData();
      /* code */
      break;
    case '2':
      tampilkanData(pos);
      /* code */ 
      break;  
    case '3':
      /* code */
      ubahData(pos);
      break;  
    case '4':
      /* code */
      break;  
    case '5':
      /* code */
      break;
    default:
      system("cls");
      cout<<"Pilihan Tidak Tersedia";
      getch();
      break;
    }
  } while (pl!='5');
    return 0;
}