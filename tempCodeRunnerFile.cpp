
    };
    int mulai = jamTidur * 60;
    int bangun = jamBangun * 60;
    int durasi = bangun - mulai;
    int jam = durasi / 60;


    cout << "\nJam Berapa Anda Tidur: ";
    cin >> jamTidur;
    cout << "Jam Berapa Anda Bangun: ";
    cin >> jamBangun;

    cout << "\n=== Rekomendasi Durasi Tidur Berdasarkan Usia ===\n";
    cout << "Kelompok Usia | Minimum | Maksimum (jam)\n";
    cout << "-------------------------------------------\n";
    cout << "1. Balita      : " << rekomendasiTidur[0][0] << " - " << rekomendasiTidur[0][1] << endl;
    cout << "2. Anak-anak   : " << rekomendasiTidur[1][0] << " - " << rekomendasiTidur[1][1] << endl;
    cout << "3. Remaja      : " << rekomendasiTidur[2][0] << " - " << rekomendasiTidur[2][1] << endl;
    cout << "4. Dewasa      : " << rekomendasiTidur[3][0] << " - " << rekomendasiTidur[3][1] << endl;

    int durasiTidur = 0;
    if (jamBangun >= jamTidur) {
        durasiTidur = jamBangun - jamTidur;
    } else {
        durasiTidur = (24 - jamTidur) + jamBangun;
    }
