#include <iostream>
#include <iomanip>
#include <limits>
using namespace std;

struct Node {
    int nrp;
    string nama;
    string kelas;
    Node* next;
};

Node* top = NULL;

void push(int nrp, string nama, string kelas);
void pop(int nrp);
void update(int nrp, string nama, string kelas);
void display();

void bingkai(string text, char lineChar = '=', int width = 30) {
    cout << setfill(lineChar) << setw(width) << "" << endl;
    cout << text << endl;
    cout << setfill(lineChar) << setw(width) << "" << endl;
}

int main() {
    int kode, nrp;
    string nama, kelas;

    do {
        cout << "\033[1;36m";
        bingkai("===       MENU UTAMA       ===", '=');
        cout << "\033[0m";
        cout << "1. Tambah Data (Push)\n";
        cout << "2. Hapus Data (Pop berdasarkan NRP)\n";
        cout << "3. Update Data (Nama dan Kelas berdasarkan NRP)\n";
        cout << "4. Tampilkan Data (Display))\n";
        cout << "5. Keluar\n";
        cout << "==============================\n";
        cout << "Masukkan Pilihan (1-5): ";
        cin >> kode;

        switch (kode) {
            case 1:
                while (true) {
                    cout << "\033[1;33mNRP : \033[0m";
                    cin >> nrp;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        cout << "\n\033[1;31mInput tidak valid! Masukkan angka.\033[0m\n\n\n\n";
                    } else {
                        break;
                    }
                }
                cin.ignore();
                cout << "\033[1;33mNama : \033[0m";
                getline(cin, nama);
                cout << "\033[1;33mKelas : \033[0m";
                getline(cin, kelas);
                push(nrp, nama, kelas);
                break;
            case 2:
            	if (top == NULL) {
			        cout << "\033[1;31mStack kosong, tidak ada data untuk dihapus!\033[0m\n\n\n\n";
			    } else {
			    	display();
			    	cout << "\033[1;33mMasukkan NRP yang ingin dihapus: \033[0m";
	                cin >> nrp;
	                pop(nrp);	
				}
                break;
            case 3:
            	if (top == NULL) {
			        cout << "\033[1;31mStack kosong, tidak ada data untuk diupdate!\033[0m\n\n\n\n";
			    } else {
			    	display();
			    	cout << "\033[1;33mMasukkan NRP yang ingin diupdate: \033[0m";
	                cin >> nrp;
	                cin.ignore();
	                cout << "\033[1;33mNama Baru : \033[0m";
	                getline(cin, nama);
	                cout << "\033[1;33mKelas Baru : \033[0m";
	                getline(cin, kelas);
	                update(nrp, nama, kelas);	
				}
                break;
            case 4:
                display();
                break;
            case 5:
                cout << "\033[1;32mKeluar dari program. Terima kasih!\033[0m" << endl;
                break;
            default:
                cout << "\033[1;31mKode yang diinput salah! Masukkan angka 1-5.\033[0m\n\n\n\n";
        }
    } while (kode != 5);
}

void push(int nrp, string nama, string kelas) {
    Node* nodeBaru = new Node();
    nodeBaru->nrp = nrp;
    nodeBaru->nama = nama;
    nodeBaru->kelas = kelas;
    nodeBaru->next = top;
    top = nodeBaru;

    cout << "\033[1;32mData berhasil ditambahkan!\033[0m\n\n\n\n";
}

void pop(int nrp) {
    if (top == NULL) {
        cout << "\033[1;31mStack kosong, tidak ada data untuk dihapus!\033[0m\n\n\n\n";
        return;
    }

    Node* temp = top;
    Node* prev = NULL;

    while (temp != NULL && temp->nrp != nrp) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\033[1;31mNRP tidak ditemukan!\033[0m\n\n\n\n";
        return;
    }

    if (prev == NULL) {
        top = temp->next;
    } else {
        prev->next = temp->next;
    }

    delete temp;
    cout << "\033[1;32mData dengan NRP " << nrp << " berhasil dihapus!\033[0m\n\n\n\n";
}

void update(int nrp, string nama, string kelas) {
    if (top == NULL) {
        cout << "\033[1;31mStack kosong, tidak ada data untuk diupdate!\033[0m\n\n\n\n";
        return;
    }

    Node* temp = top;

    while (temp != NULL && temp->nrp != nrp) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "\033[1;31mNRP tidak ditemukan!\033[0m\n\n\n\n";
        return;
    }

    temp->nama = nama;
    temp->kelas = kelas;
    cout << "\033[1;32mData dengan NRP " << nrp << " berhasil diupdate!\033[0m\n\n\n\n";
}

void display() {
    if (top == NULL) {
        cout << "\033[1;31mStack kosong, tidak ada data untuk ditampilkan!\033[0m\n\n\n\n";
    } else {
        Node* temp = top;
        cout << "\033[1;34m";
        bingkai("---       DATA STACK       ---", '-');
        cout << "\033[0m";

        while (temp != NULL) {
            cout << "\033[1;33mNRP   : \033[0m" << temp->nrp << endl;
            cout << "\033[1;33mNama  : \033[0m" << temp->nama << endl;
            cout << "\033[1;33mKelas : \033[0m" << temp->kelas << endl;
            cout << "------------------------------\n";
            temp = temp->next;
        }

        cout << "==============================\n\n\n\n";
    }
}

