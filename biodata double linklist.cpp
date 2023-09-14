#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

struct BiodataMahasiswa {
string nim;
string nama;
string alamat;
string no_telpon;

BiodataMahasiswa* prev;
BiodataMahasiswa* next;
};
void gotoxy(int x, int y) {
COORD coord;
coord.X = x;
coord.Y = y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
BiodataMahasiswa* head = NULL;
BiodataMahasiswa* tail = NULL;
void insertBiodataMahasiswa() {
BiodataMahasiswa* mhs = new BiodataMahasiswa();
system("cls");
gotoxy(35, 4); cout<<"===========================";
gotoxy(35, 5); cout<<"|      Masukkan Data!     |";
gotoxy(35, 6); cout<<"===========================";
gotoxy(35, 8); cout << "NIM : ";
cin >> mhs->nim;
gotoxy(35, 9); cout << "Nama : ";
cin.ignore();
getline(cin, mhs->nama);
gotoxy(35, 10); cout << "Alamat : ";
getline(cin, mhs->alamat);
gotoxy(35, 11); cout << "No. Telepon : ";
getline(cin, mhs->no_telpon);
BiodataMahasiswa* curr = head;
while (curr != NULL) {
if (curr->nim == mhs->nim) {
gotoxy(35, 14);
cout << "NIM SUDAH TERDAFTAR!" << endl;
gotoxy(35, 18);
system("pause");
return;
}
curr = curr->next;
}
if (head == NULL) {
head = tail = mhs;
}
else if (mhs->nim < head->nim) {
mhs->next = head;
head->prev = mhs;
head = mhs;
}
else if (mhs->nim > tail->nim) {
mhs->prev = tail;
tail->next = mhs;
tail = mhs;
}
else {
curr = head;
while (curr != NULL) {
if (curr->nim < mhs->nim && curr->next->nim > mhs->nim) {
mhs->prev = curr;
mhs->next = curr->next;
curr->next = mhs;
mhs->next->prev = mhs;
break;
}
curr = curr->next;
}
}
gotoxy(35, 14);
cout << "Data Berhasil Ditambahkan!" << endl;
gotoxy(35, 18);
system("pause");
}
void editMahasiswa() {
string nim;
system("cls");
gotoxy(38, 5);
cout << "Input NIM yang Diedit : ";
cin >> nim;
BiodataMahasiswa* curr = head;
while (curr != NULL) {
if (curr->nim == nim) {
gotoxy(38, 7); cout << "==========================";
gotoxy(38, 8); cout << "|      DATA DITEMUKAN!   |" << endl;
gotoxy(38, 9); cout << "==========================";
gotoxy(38, 10); cout << "Nama : " << curr->nama << endl;
gotoxy(38, 11); cout << "Alamat : " << curr->alamat << endl;
gotoxy(38, 12); cout << "No. Telepon : " << curr->no_telpon << endl;
gotoxy(38, 14); cout << "=========================";
gotoxy(38, 15); cout << "|    Input Data Baru!    |";
gotoxy(38, 16); cout << "=========================";
gotoxy(38, 17); cout << "Ubah Nama : ";
cin.ignore();
getline(cin, curr->nama);
gotoxy(38, 18); cout << "Ubah Alamat : ";
getline(cin, curr->alamat);
gotoxy(38, 19); cout << "Ubah No. Telepon : ";
getline(cin, curr->no_telpon);
gotoxy(38, 22);
cout << "DATA BERHASIL DIUBAH!" << endl;
gotoxy(38, 25);
system("pause");
return;
}
curr = curr->next;
}
system("cls");
gotoxy(40, 8);
cout << "DATA TIDAK TERSEDIA!" << endl;
gotoxy(40, 12);
system("pause");
}
void deleteMahasiswa() {
string nim;
system("cls");
gotoxy(35, 6);
cout << "Masukkan NIM yang akan dihapus : ";
cin >> nim;
BiodataMahasiswa* curr = head;
while (curr != NULL) {
if (curr->nim == nim) {
if (curr == head && curr == tail) {
head = tail = NULL;
}
else if (curr == head) {
head = curr->next;
head->prev = NULL;
}
else if (curr == tail) {
tail = curr->prev;
tail->next = NULL;
}
else {
curr->prev->next = curr->next;
curr->next->prev = curr->prev;
}
delete curr;
gotoxy(35, 10);
cout << "DATA BERHASIL DIHAPUS!" << endl;
gotoxy(35, 14);
system("pause");
return;
}
curr = curr->next;
}
system("cls");
gotoxy(35, 10);
cout << "DATA TIDAK DITEMUKAN!" << endl;
gotoxy(35, 14);
system("pause");
}
void searchMahasiswa() {
system("cls");
string nim;
gotoxy(35, 3);
cout << "Input NIM yang dicari : ";
cin >> nim;
BiodataMahasiswa* curr = head;
while (curr != NULL) {
if (curr->nim == nim) {
gotoxy(35, 4);
cout << "=============================================";
gotoxy (35,6); cout << "|     Data yang ditemukan    |";
cout << "=============================================";
gotoxy(35, 7); cout << "=============================================";
gotoxy(35, 8); cout << "|Nama|" << endl;
gotoxy(50, 8); cout << "|Alamat|" << endl;
gotoxy(65, 8); cout << "|No. Telepon|" << endl;
gotoxy(35, 9); cout << "============================================="
<< endl;
gotoxy(36, + 10); cout << curr->nama << endl;
gotoxy(52, + 10); cout << curr->alamat << endl;
gotoxy(67, + 10); cout << curr->no_telpon << endl;
gotoxy(41, 14);
system("pause");
return;
}
curr = curr->next;
}
system("cls");
gotoxy(35, 8);
cout << "DATA TIDAK DITEMUKAN!" << endl;
gotoxy(35, 12);
system("pause");
}
void displayMahasiswa() {
system("cls");
BiodataMahasiswa* curr = head;
while (curr != NULL) {
gotoxy(21, 3); cout
<<"==============================================================" <<
endl;
gotoxy(21, 4); cout << "|NIM|" << endl;
gotoxy(39, 4); cout << "|Nama|" << endl;
gotoxy(54, 4); cout << "|Alamat|" << endl;
gotoxy(70, 4); cout << "|No Telepon|" << endl;
gotoxy(21, 5); cout
<<"==============================================================" <<
endl;
gotoxy(22, + 6); cout << curr->nim << endl;
gotoxy(40, + 6); cout << curr->nama << endl;
gotoxy(55, + 6); cout << curr->alamat << endl;
gotoxy(71, + 6); cout << curr->no_telpon << endl << endl;
curr = curr->next;
gotoxy(37, 16);
system("pause");
}
}
int main() {
int choice;
do {
system("cls");
gotoxy(33, 1); cout << "===========================================";
gotoxy(33, 2); cout << "|               MENU BIODATA              |";
gotoxy(33, 3); cout << "===========================================";
gotoxy(38, 4); cout << "================================";
gotoxy(38, 5); cout << "| 1. Input data                |"<< endl;
gotoxy(38, 6); cout << "| 2. Edit data                 |"<< endl;
gotoxy(38, 7); cout << "| 3. Hapus data                |"<< endl;
gotoxy(38, 8); cout <<"| 4. Searching data            |"<< endl;
gotoxy(38, 9); cout <<"| 5. Tampilan data             |"<< endl;
gotoxy(38, 10); cout <<"| 6. Exit Program              |"<< endl;
gotoxy(38, 11); cout <<"================================";
gotoxy(38, 12); cout << "Masukkan Pilihan Anda : ";
cin >> choice;
switch (choice) {
case 1:
insertBiodataMahasiswa();
break;
case 2:
editMahasiswa();
break;
case 3:
deleteMahasiswa();
break;
case 4:
searchMahasiswa();
break;
case 5:
displayMahasiswa();
break;
case 6:
gotoxy(38, 18);
cout << "PROGRAM SELESAI!" << endl;
break;
default:
gotoxy(41, 18);
cout << "PILIHAN MENU TIDAK ADA!" << endl;
gotoxy(38, 20);
system("pause");
break;
}
cout << endl;
} while (choice != 6);
return 0;
}
