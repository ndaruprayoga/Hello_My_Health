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
void pauseScreen();

int beratKarbo;
int beratProtein;
int beratlemak;
int jamTidur;
int jamBangun;
int umur;

bool inputAngkaValid() {
    if (cin.fail()) {
        cin.clear();        // reset error input
        cin.ignore(1000, '\n'); 
        cout << "Input tidak valid! Harap masukkan angka.\n";
        return false;
    }
    return true;
}

bool inputTidakNegatif(float x) {
    if (x < 0) {
        cout << "⚠ Input tidak boleh negatif!\n";
        return false;
    }
    return true;
}

bool inputRange(int x, int min, int max) {
    if (x < min || x > max) {
        cout << "Input harus berada pada rentang " << min << " - " << max << ".\n";
        return false;
    }
    return true;
}


int main() {
    menuUtama();
    return 0;
}
void menuUtama() {
    int pilihan;

    do {
        cout << "\n=== MENU UTAMA ===\n";
        cout << "1. Kalkulator BMI\n";
        cout << "2. Kebutuhan Cairan Tubuh\n";
        cout << "3. Kebutuhan Asupan Tubuh\n";
        cout << "4. Kualitas Tidur\n";
        cout << "5. Index Kesehatan\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cout << "\n";

        cin.ignore(); // supaya pauseScreen tidak kelewat

        switch(pilihan){
            case 1: kalkulattorBMI();
            break;
            case 2: kebutuhancairanTubuh();
            break;
            case 3: kebutuhanasupanTubuh();
            break;
            case 4: kualitasTidur();
            break;
            case 5: indexKesehatan();
            break;
            case 6: cout << "Keluar...\n";
            return;
            default: cout << "Pilihan tidak valid!\n";
        }

    } while(pilihan != 0);
    menuUtama();
}

void pauseScreen() {
    cout << "\n----------------------------------------\n";
    cout << "Tekan ENTER untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

void kalkulattorBMI() {
    cout << "=== Kalkulattor BMI ===" << endl;
    cout << "Masukkan berat badan (kg): ";
    cin >> berat;
    if (!inputAngkaValid() || !inputTidakNegatif(berat)) return pauseScreen();
    cout << "Masukkan tinggi badan (m): ";
    cin >> tinggi;
    if (!inputAngkaValid() || !inputTidakNegatif(tinggi)) return pauseScreen();
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
    pauseScreen();
}

void kebutuhancairanTubuh() {
    cout << "=== Kebutuhan Cairan Tubuh ===" << endl;
    cout << "Masukkan jumlah gelas air yang Anda minum hari ini: ";
    cin >> gelas;
    if (!inputAngkaValid() || !inputTidakNegatif(gelas)) return pauseScreen();
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
    pauseScreen();
}

void kebutuhanasupanTubuh(){
    cout << "Masukan berat karbohidrat yang Anda konsumsi : ";
    cin >> beratKarbo;
    if (!inputAngkaValid() || !inputTidakNegatif(beratKarbo)) return pauseScreen();
    int kaloriKarbo = beratKarbo * 4;
    cout << "Kalori dari karbohidrat: " << kaloriKarbo << " kalori" << endl;

    cout << "Masukan berat protein yang Anda konsumsi (dalam gram): ";
    cin >> beratProtein;
    if (!inputAngkaValid() || !inputTidakNegatif(beratProtein)) return pauseScreen();
    int kaloriProtein = beratProtein * 4;
    cout << "Kalori dari protein: " << kaloriProtein << " kalori" << endl;

    cout << "berat lemak yang Anda konsumsi (dalam gram): ";
    cin >> beratlemak;
    if (!inputAngkaValid() || !inputTidakNegatif(beratKarbo)) return pauseScreen();
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
    pauseScreen();
}

void kualitasTidur() {
    cout << "========= Kualitas Tidur ==========" << endl;
    cout << "Masukkan Umur: ";
    cin >> umur;
    if (!inputAngkaValid() || !inputRange(umur, 1, 100)) return;

    // Rekomendasi durasi tidur berdasarkan umur
    int rekomendasiTidur[4][2] = {
        {10, 12},   // Balita 1–5 tahun
        {9, 11},    // Anak-anak 6–12 tahun
        {8, 10},    // Remaja 13–17 tahun
        {7, 9}      // Dewasa 18+
    };

    cout << "\nJam Berapa Anda Tidur: ";
    cin >> jamTidur;
    if (!inputAngkaValid() || !inputRange(jamTidur, 0, 23)) return;
    cout << "Jam Berapa Anda Bangun: ";
    cin >> jamBangun;
    if (!inputAngkaValid() || !inputRange(jamBangun, 0, 23)) return;

    // Hitung durasi tidur SESUNGGUHNYA
    int durasiTidur;
    if (jamBangun >= jamTidur) {
        durasiTidur = jamBangun - jamTidur;
    } else {
        durasiTidur = (24 - jamTidur) + jamBangun;
    }

    cout << "\n=== Rekomendasi Durasi Tidur Berdasarkan Usia ===\n";
    cout << "Kelompok Usia | Minimum | Maksimum (jam)\n";
    cout << "-------------------------------------------\n";
    cout << "1. Balita      : " << rekomendasiTidur[0][0] << " - " << rekomendasiTidur[0][1] << endl;
    cout << "2. Anak-anak   : " << rekomendasiTidur[1][0] << " - " << rekomendasiTidur[1][1] << endl;
    cout << "3. Remaja      : " << rekomendasiTidur[2][0] << " - " << rekomendasiTidur[2][1] << endl;
    cout << "4. Dewasa      : " << rekomendasiTidur[3][0] << " - " << rekomendasiTidur[3][1] << endl;
    cout << "\n";

    cout << "Durasi Tidur Anda: " << durasiTidur << " jam" << endl;

    // ---------------------------
    // CEK DENGAN Rekomendasi Usia
    // ---------------------------

    int minTidur;
    if (umur <= 5) minTidur = rekomendasiTidur[0][0];
    else if (umur <= 12) minTidur = rekomendasiTidur[1][0];
    else if (umur <= 17) minTidur = rekomendasiTidur[2][0];
    else minTidur = rekomendasiTidur[3][0];

    bool durasiCukup = (durasiTidur >= minTidur);

    cout << "Penilaian durasi tidur: ";
    if (durasiCukup) cout << "Cukup" << endl;
    else cout << "Kurang" << endl;

    // ---------------------------
    // ANALISIS JAM MULAI TIDUR
    // ---------------------------
    cout << "Jam mulai tidur: " << jamTidur << ":00 - ";

    string kategoriJam;

    if (jamTidur >= 21 && jamTidur <= 22) {
        kategoriJam = "Ideal";
        cout << "Ideal" << endl;
    } 
    else if (jamTidur >= 23 || jamTidur <= 1) {
        kategoriJam = "Terlalu malam";
        cout << "Terlalu malam" << endl;
    }
    else if (jamTidur >= 2 && jamTidur <= 5) {
        kategoriJam = "Sangat tidak sehat";
        cout << "Sangat tidak sehat" << endl;
    } 
    else {
        kategoriJam = "Kurang ideal";
        cout << "Kurang ideal" << endl;
    }

    cout << "\n=== KESIMPULAN KUALITAS TIDUR ===\n";

    if (durasiCukup && kategoriJam == "Ideal") {
        cout << "Kualitas tidur Anda sangat baik." << endl;
    }
    else if (durasiCukup && kategoriJam == "Kurang ideal") {
        cout << "Tidur cukup, namun jam tidur perlu diperbaiki." << endl;
    }
    else if (!durasiCukup && kategoriJam == "Ideal") {
        cout << "Jam tidur ideal, namun durasinya kurang." << endl;
    }
    else if (!durasiCukup && kategoriJam == "Terlalu malam") {
        cout << "Kualitas tidur kurang. Perbaiki jam tidur dan durasi tidur Anda." << endl;
    }
    else if (!durasiCukup && kategoriJam == "Sangat tidak sehat") {
        cout << "Kualitas tidur sangat buruk. Segera perbaiki pola tidur Anda!" << endl;
    }
    else {
        cout << "Kualitas tidur kurang optimal." << endl;
    }

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
    pauseScreen();
}
