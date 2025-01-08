#include <stdio.h>
#include <stdlib.h>

// Struktur untuk menyimpan tanggal (day, month, year)
struct date {
    int month, day, year;
} today, tomorrow;

// Fungsi untuk mengecek apakah tahun kabisat atau tidak
// Tahun kabisat adalah tahun yang habis dibagi 400 atau (habis dibagi 4 dan tidak habis dibagi 100)
int cekKabisat(int tahun) {
    if (tahun % 400 == 0) return 1;  // Tahun habis dibagi 400, maka kabisat
    else if (tahun % 100 == 0) return 0;  // Tahun habis dibagi 100, tetapi tidak kabisat
    else if (tahun % 4 == 0) return 1;  // Tahun habis dibagi 4, maka kabisat
    else return 0;  // Bukan tahun kabisat
}

int main() {
    int batas_hari = 0;  // Variabel untuk menyimpan batas hari dalam bulan
    int cekTahun = 0;    // Variabel untuk menyimpan hasil pengecekan tahun kabisat

    // Praktikum 5, no. 3
    printf("---------------------------------------------------------------------------------\n");
    printf("Program untuk mengecek hari besok berdasarkan input tanggal\n");
    printf("---------------------------------------------------------------------------------\n\n");

    // Input tanggal hari ini (day, month, year)
    printf("Today (Day Month Year):");
    scanf("%d %d %d", &today.day, &today.month, &today.year);

    // Menampilkan tanggal hari ini
    printf("\nToday is %d-%d-%d\n", today.day, today.month, today.year);

    // Mengecek jumlah hari dalam bulan yang diberikan
    switch (today.month) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            batas_hari = 31;  // Bulan-bulan dengan 31 hari
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            batas_hari = 30;  // Bulan-bulan dengan 30 hari
            break;

        case 2:
            cekTahun = cekKabisat(today.year);  // Mengecek tahun kabisat atau tidak
            if (cekTahun) batas_hari = 29;     // Februari 29 hari jika tahun kabisat
            else batas_hari = 28;               // Februari 28 hari jika bukan tahun kabisat
            break;

        default:
            printf("Bulan tidak valid\n");
            exit(0);  // Jika bulan tidak valid, program akan keluar
            break;
    }

    // Mengecek apakah tanggal hari ini valid (berada dalam rentang 1 sampai batas_hari)
    if (1 <= today.day && today.day <= batas_hari) {
        // Jika hari ini adalah hari terakhir dalam bulan
        if (today.day == batas_hari) {
            tomorrow.day = 1;  // Setel tanggal besok menjadi 1
            if (today.month == 12) {  // Jika bulan Desember, lanjut ke bulan Januari tahun depan
                tomorrow.month = 1;
                tomorrow.year = today.year + 1;  // Tahun bertambah 1
            }
            else {  // Jika bukan bulan Desember, lanjut ke bulan berikutnya dalam tahun yang sama
                tomorrow.month = today.month + 1;
                tomorrow.year = today.year;
            }
        }
        else {  // Jika bukan akhir bulan, hanya tambah 1 pada hari
            tomorrow.day = today.day + 1;
            tomorrow.month = today.month;
            tomorrow.year = today.year;
        }

        // Menampilkan tanggal besok
        printf("Tomorrow is %d-%d-%d \n", tomorrow.day, tomorrow.month, tomorrow.year);
    }
    else {  // Jika tanggal hari ini tidak valid
        printf("Tanggal tidak valid\n");
    }

    return 0;  // Program selesai
}
