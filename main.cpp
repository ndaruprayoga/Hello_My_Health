#include <iostream>
using namespace std;


float berat = 0, tinggi = 0, bmi = 0;
int gelas = 0, kalori = 0;

void kalkulattorBMI();
void kebutuhanasupanTubuh();
void kebutuhancairanTubuh();
void kualitasTidur();
void indexKesehatan();
void menuUtama();

int beratKarbo;
int beratProtein;
int beratlemak;
int jamTidur;
int jamBangun;
int umur;

int main() {
    menuUtama();
    return 0;
}
void menuUtama() {
    int pilihan;
    cout << "Selamat datang di Aplikasi Hello My Health!" << endl;6
    cout << "=== Menu Utama ===" << endl;
    cout << "1. Kalkulattor BMI" << endl;
    cout << "2. Kebutuhan Cairan Tubuh" << endl;
    cout << "3. Kebutuhan Asupan Tubuh" << endl;
    cout << "4. Kualitas Tidur" << endl;
    cout << "5. Index Kesehatan" << endl;
    cout << "6. Keluar" << endl;
    cout << "Pilih menu (1-6): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            kalkulattorBMI();
            break;
        case 2:
            kebutuhancairanTubuh();
            break;
        case 3:
            kebutuhanasupanTubuh();
            break;
        case 4:
            kualitasTidur();
            break;
        case 5:
            indexKesehatan();
            break;
        case 6:
            cout << "Terima kasih telah menggunakan aplikasi ini!, Sehat selaluu:)" << endl;
            return;
        default:
            cout << "Pilihan kamu gak valid. coba lagiii." << endl;
    }
    menuUtama();
}

void kalkulattorBMI() {
    cout << "=== Kalkulattor BMI ===" << endl;
    cout << "Masukkan berat badan (kg): ";
    cin >> berat;
    cout << "Masukkan tinggi badan (m): ";
    cin >> tinggi;
    bmi = berat / (tinggi * tinggi);
    cout << "BMI Anda adalah: " << bmi << endl;
    if (bmi < 18.5) {
        cout << "Kamu masih terlalu Kurus" << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "Selamat kamu Normal" << endl;
    } else if (bmi >= 25 && bmi < 29.9) {
        cout << "kamu masih terlihat Gemuk" << endl;
    } else {
        cout << "WADUHH KAMU MASUK KATEGORI OBESITAS" << endl;
    }
    cout << "\n";
}

void kebutuhancairanTubuh() {
    cout << "=== Kebutuhan Cairan Tubuh ===" << endl;
    cout << "Masukkan jumlah gelas air yang Anda minum hari ini: ";
    cin >> gelas;
    cout << "Anda telah minum " << gelas << " gelas air hari ini." << endl;
    cout << "Jumlah ideal adalah 8 gelas per hari." << endl;
    if (gelas < 8) {
        cout << "Ingat untuk minum lebih banyak air!" << endl;
        if (gelas < 4) {
            cout << "Anda sangat kurang minum air. Pastikan untuk minum setidaknya 8 gelas sehari." << endl;
        }
    } else {
        cout << "Bagus! Anda sudah cukup minum air hari ini." << endl;
    }
    cout << "\n";
}

void kebutuhanasupanTubuh(){
    cout << "Masukan berat karbohidrat yang Anda konsumsi : ";
    cin >> beratKarbo;
    int kaloriKarbo = beratKarbo * 4;
    cout << "Kalori dari karbohidrat: " << kaloriKarbo << " kalori" << endl;

    cout << "Masukan berat protein yang Anda konsumsi (dalam gram): ";
    cin >> beratProtein;
    int kaloriProtein = beratProtein * 4;
    cout << "Kalori dari protein: " << kaloriProtein << " kalori" << endl;

    cout << "berat lemak yang Anda konsumsi (dalam gram): ";
    cin >> beratlemak;
    int kalorilemak = beratlemak * 9;
    cout << "Kalori dari lemak: " << kalorilemak << " kalori" << endl;

    kalori = kaloriKarbo + kaloriProtein + kalorilemak;
    cout << "Total kalori yang Anda konsumsi: " << kalori << " kalori" << endl;
    if (kalori < 2000) {
        cout << "Kalori Anda di bawah kebutuhan harian." << endl;
    } else if (kalori == 2000) {
        cout << "Kalori Anda sesuai dengan kebutuhan harian." << endl;
    } else {
        cout << "Kalori Anda melebihi kebutuhan harian." << endl;
    }
}

void kualitasTidur() {
    cout << "========= Kualitas Tidur ==========" << endl;
    cout << "Masukkan Umur: ";
    cin >> umur;

    cout << "\n=== Rekomendasi Durasi Tidur Berdasarkan Usia ===\n";

    int rekomendasiTidur[4][2] = {
        {10, 12},   // Balita 1–5 tahun
        {9, 11},    // Anak-anak 6–12 tahun
        {8, 10},    // Remaja 13–17 tahun
        {7, 9}      // Dewasa 18+
    };

    cout << "Kelompok Usia | Minimum | Maksimum (jam)\n";
    cout << "-------------------------------------------\n";
    cout << "1. Balita      : " << rekomendasiTidur[0][0] << " - " << rekomendasiTidur[0][1] << endl;
    cout << "2. Anak-anak   : " << rekomendasiTidur[1][0] << " - " << rekomendasiTidur[1][1] << endl;
    cout << "3. Remaja      : " << rekomendasiTidur[2][0] << " - " << rekomendasiTidur[2][1] << endl;
    cout << "4. Dewasa      : " << rekomendasiTidur[3][0] << " - " << rekomendasiTidur[3][1] << endl;

    // ===== Bagian asli kualitas tidur (lanjutkan kode anda di bawah) =====
    cout << "\nJam Berapa Anda Tidur: ";
    cin >> jamTidur;
    cout << "Jam Berapa Anda Bangun: ";
    cin >> jamBangun;

    int durasiTidur = 0;
    if (jamBangun >= jamTidur) {
        durasiTidur = jamBangun - jamTidur;
    } else {
        durasiTidur = (24 - jamTidur) + jamBangun;
    }

    cout << "Durasi Tidur Anda: " << durasiTidur << " jam" << endl;

    cout << "\n";
}

void indexKesehatan() {
    cout << "========Index Kesehatan========" << endl;

    if (bmi == 0 || gelas == 0 || kalori == 0 || jamTidur == 0 || jamBangun == 0){
        cout << "Data belum lengkap, isi BMI,isi Kebutuhan Ciaran Tubuh, isi Kebutuhan Asupan Tubuh, dan isi Kualitas Tidur" << endl;
        return;
    }

    int skorTotal = 0;

    if (bmi >= 18.5 && bmi < 25){
        skorTotal += 30;
    }else if (bmi >= 25 && bmi < 30){
        skorTotal += 20;
    }else if (bmi >= 17 && bmi < 18.5){
        skorTotal += 15;
    }else{
        skorTotal += 5;
    }

    if (gelas >= 8){
        skorTotal += 20;
    }else if (gelas >= 5){
        skorTotal += 15;
    }else{
        skorTotal += 5;
    }

    if (kalori >= 1800 && kalori <= 2000){
        skorTotal += 25;
    }else if(kalori >= 1500 && kalori <= 1800){
        skorTotal += 15;
    }else if(kalori > 2200 && kalori <= 2600){
        skorTotal += 10;
    }else {
        skorTotal += 5;
    }

    int mulai = jamTidur * 60;
    int bangun = jamBangun * 60;

    if (bangun < mulai) {
        bangun += 24 * 60;
    }

    int durasi = (bangun - mulai) / 60; 

    if (durasi >= 7 && durasi <= 9) {
        skorTotal += 25;                
    } 
    else if (durasi >= 5 && durasi < 7) {
        skorTotal += 15;                
    }
    else {
        skorTotal += 5;                
    }

    cout << "\nSkor Total Anda: " << skorTotal << "/100" << endl;
    cout << "Kategori Kesehatan: ";

    if (skorTotal >= 80) {
        cout << "Baik" << endl;
    } else if (skorTotal >= 50) {
        cout << "Cukup" << endl;
    } else {
        cout << "Kurang" << endl;
    }

    cout << "========================================\n";
}
