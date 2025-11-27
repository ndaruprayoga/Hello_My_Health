#include <iostream>
using namespace std;


float berat = 0, tinggi = 0, bmi = 0;
int gelas = 0, kalori = 0;

void kalkulattorBMI();
void kebutuhanasupanTubuh();
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
    cout << "Selamat datang di Aplikasi Hello My Health!" << endl;
    cout << "=== Menu Utama ===" << endl;
    cout << "1. Kalkulattor BMI" << endl;
    cout << "2. Kebutuhan Asupan Tubuh" << endl;
    cout << "3. Kualitas Tidur" << endl;
    cout << "4. MCU Sederhana" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilih menu (1-5): ";
    cin >> pilihan;

    switch (pilihan) {
        case 1:
            kalkulattorBMI();
            break;
        case 2:
            kebutuhanasupanTubuh();
            break;
        case 3:
            kualitasTidur();
            break;
        case 4:
            indexKesehatan();
            break;
        case 5:
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

void kebutuhanasupanTubuh() {
    cout << "=== Reminder Water Intake ===" << endl;
    cout << "Masukkan jumlah gelas air yang Anda minum hari ini: ";
    cin >> gelas;
    cout << "Anda telah minum " << gelas << " gelas air hari ini." << endl;
    cout << "Jumlah ideal adalah 8 gelas per hari." << endl;
    
    cout << "Masukan berat karbohidrat yang Anda konsumsi : ";
    cin >> beratKarbo;
    int kaloriKarbo = beratKarbo * 4; // Asumsi 1 gram nasi mengandung 1.3 kalori
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

void kualitasTidur() {
    cout << "========= Kualitas Tidur ==========" << endl;
    cout << "Masukan Umur: ";
    cin >> umur;
    cout << "Masukan jam saat mulai tertidur: ";
    cin >> jamTidur;
    cout << "Masukan jam saat mulai terbangun: ";
    cin >> jamBangun;

    int mulai = jamTidur * 60;
    int bangun = jamBangun * 60;

    if (bangun < mulai){
        bangun += 24 * 60;
    }
    int durasi = bangun - mulai;
    int jam = durasi / 60;
    cout << "Durasi tidur: " << jam << " jam" << endl;

    bool durasiCukup = false;
    if (umur < 12){
        durasiCukup = (jam >= 11);
    }
    else {
        durasiCukup = (jam >= 7);
    }

    cout << "Penilaian durasi Tidur: ";
    if (durasiCukup) cout << "Cukup" << endl;
    else cout << "Kurang" << endl;
    
    cout << "Jam mulai tidur: " << jamTidur << endl;

    string kategoriJam;

    if(jamTidur >= 21 && jamTidur <= 22) {
        kategoriJam = "Ideal";
        cout << "Ideal" << endl;
    }
    else if (jamTidur >= 23 || jamTidur <= 1){
        kategoriJam = "Terlalu malam";
        cout << "Terlalu malam" << endl;
    }
    else if (jamTidur >= 2 && jamTidur <= 5){
        kategoriJam = "Sangat tidak sehat";
        cout << "Sangat tidak sehat" << endl;
    }
    else {
        kategoriJam = "Kurang Ideal";
        cout << "Kurang Ideal" << endl;
    }
    cout << "\n";
    
}

void indexKesehatan() {
    cout << "========Index Kesehatan========" << endl;

    if (bmi == 0 || gelas == 0 || kalori == 0 || jamTidur == 0 || jamBangun == 0){
        cout << "Data belum lengkap, isi BMI, isi Kebutuhan Asupan Tubuh, dan isi Kualitas Tidur" << endl;
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
}
