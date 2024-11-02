#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    int npm;
    string nama;
    float nilaiMid;
    float nilaiSemester;
    float nilaiAkhir;
    char nilaiHuruf;
};

// Fungsi untuk menghitung nilai akhir
float hitungNilaiAkhir(float nilaiMid, float nilaiSemester) {
    return (0.4 * nilaiMid) + (0.6 * nilaiSemester);
}

// Fungsi untuk menentukan nilai huruf
char tentukanNilaiHuruf(float nilaiAkhir) {
    if (nilaiAkhir >= 80 && nilaiAkhir <= 100) {
        return 'A';
    } else if (nilaiAkhir >= 70 && nilaiAkhir < 80) {
        return 'B';
    } else if (nilaiAkhir >= 55 && nilaiAkhir < 70) {
        return 'C';
    } else if (nilaiAkhir >= 40 && nilaiAkhir < 55) {
        return 'D';
    } else {
        return 'E';
    }
}

// Fungsi untuk menginput data mahasiswa
void inputDataMahasiswa(Mahasiswa &m) {
    cout << "NPM: ";
    cin >> m.npm;
    cin.ignore();  // Menghapus sisa input buffer
    cout << "Nama: ";
    getline(cin, m.nama);
    cout << "Nilai Mid: ";
    cin >> m.nilaiMid;
    cout << "Nilai Semester: ";
    cin >> m.nilaiSemester;

    // Hitung nilai akhir dan tentukan nilai huruf
    m.nilaiAkhir = hitungNilaiAkhir(m.nilaiMid, m.nilaiSemester);
    m.nilaiHuruf = tentukanNilaiHuruf(m.nilaiAkhir);
}

// Fungsi untuk menampilkan data mahasiswa
void tampilkanDataMahasiswa(const Mahasiswa &m) {
    cout << m.npm << "\t" << m.nama << "\t" << m.nilaiAkhir << "\t\t" << m.nilaiHuruf << endl;
}

int main() {
    Mahasiswa mahasiswa[100];
    int n;

    cout << "Masukkan jumlah mahasiswa (max 100): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData Mahasiswa " << i + 1 << ":\n";
        inputDataMahasiswa(mahasiswa[i]);
    }

    // Menampilkan hasil
    cout << "\nData Nilai Mahasiswa:\n";
    cout << "NPM\tNama\tNilai Akhir\tNilai Huruf\n";
    for (int i = 0; i < n; i++) {
        tampilkanDataMahasiswa(mahasiswa[i]);
    }

    return 0;
}
