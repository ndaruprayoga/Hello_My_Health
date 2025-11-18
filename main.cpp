#include <iostream>
#include <cstdlib>
using namespace std;


float berat = 0, tinggi = 0, bmi = 0;
int gelas = 0, kalori = 0;

void kalkulattorBMI();
void kebutuhanasupanTubuh();
void mcuSederhana();
void menuUtama();
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int beratNasi;
int beratLauk;
int beratSayur;

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
    cout << "3. MCU Sederhana" << endl;
    cout << "4. Keluar" << endl;
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
            mcuSederhana();
            break;
        case 4:
            cout << "Terima kasih telah menggunakan aplikasi ini!, Sehat selaluu:)" << endl;
            return;
        default:
            cout << "Pilihan kamu gak valid. coba lagiii." << endl;
    }
    menuUtama(); // Kembali ke menu utama setelah menyelesaikan pilihan
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
}

void kebutuhanasupanTubuh() {
    cout << "=== Reminder Water Intake ===" << endl;
    cout << "Masukkan jumlah gelas air yang Anda minum hari ini: ";
    cin >> gelas;
    cout << "Anda telah minum " << gelas << " gelas air hari ini." << endl;
    cout << "Jumlah ideal adalah 8 gelas per hari." << endl;
    cout << "Masukan berat nasi yang Anda konsumsi (minimal 100 gram): ";
    cin >> beratNasi;
    int kaloriNasi = beratNasi * 129; // Asumsi 1 gram nasi mengandung 1.3 kalori
    cout << "Kalori dari karbohidrat: " << kaloriNasi << " kalori" << endl;
    cout << "Masukan berat lauk yang Anda konsumsi (dalam gram): ";
    cin >> beratLauk;
    int kaloriLauk = beratLauk * 2.5;
    cout << "Kalori dari protein: " << kaloriLauk << " kalori" << endl;
    cout << "berat sayur yang Anda konsumsi (dalam gram): ";
    cin >> beratSayur;
    int kaloriSayur = beratSayur * 0.5;
    cout << "Kalori dari serat: " << kaloriSayur << " kalori" << endl;
    kalori = kaloriNasi + kaloriLauk + kaloriSayur;
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
}

void mcuSederhana() {
    cout << "=== MCU Sederhana ===" << endl;
    if (bmi == 0 || gelas == 0 || kalori == 0) {
        cout << "Data belum lengkap. Silakan isi data BMI, Water Intake, dan Calories terlebih dahulu." << endl;
        return;
    }
    cout << "Laporan Kesehatan Sederhana:" << endl;
    cout << "Berat Badan: " << berat << " kg" << endl;
    cout << "Tinggi Badan: " << tinggi << " m" << endl;
    cout << "BMI: " << bmi << " - ";
    if (bmi < 18.5) {
        cout << "Kurus" << endl;
    } else if (bmi >= 18.5 && bmi < 24.9) {
        cout << "Normal" << endl;
    } else if (bmi >= 25 && bmi < 29.9) {
        cout << "Gemuk" << endl;
    } else {
        cout << "Obesitas" << endl;
    }
    cout << "Jumlah Gelas Air: " << gelas << " gelas - ";
    if (gelas < 8) {
        cout << "Kurang" << endl;
    } else {
        cout << "Cukup" << endl;
    }
    cout << "Kalori Konsumsi: " << kalori << " kalori - ";
    if (kalori < 2000) {
        cout << "Di bawah kebutuhan" << endl;
    } else if (kalori == 2000) {
        cout << "Sesuai kebutuhan" << endl;
    } else {
        cout << "Melebihi kebutuhan" << endl;
    }
    cout << "Kesimpulan: ";
    if (bmi >= 18.5 && bmi < 24.9 && gelas >= 8 && kalori == 2000) {
        cout << "Kesehatan Anda baik!" << endl;
    } else {
        cout << "Perlu perbaikan pola hidup." << endl;
    }
}
