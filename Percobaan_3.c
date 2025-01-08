#include <stdio.h>
#include <stdlib.h>

// Struktur untuk menyimpan informasi tentang ayam
struct chicken {
    char kode;         // Kode untuk jenis ayam (D, P, S)
    char jenis[30];    // Jenis ayam (Dada, Paha, Sayap)
    int harga;         // Harga per potong ayam
};

// Struktur untuk menyimpan informasi pesanan
struct pesanan {
    char kode;         // Kode untuk jenis ayam yang dipesan
    int qty;           // Jumlah potong ayam yang dipesan
    int jumlah;        // Jumlah harga untuk pesanan tersebut
};

// Daftar ayam yang tersedia di toko
struct chicken ayam[3] = {{'D', "Dada", 5000}, {'P', "Paha", 4000}, {'S', "Sayap", 3000}};

// Daftar pesanan yang dimasukkan oleh pelanggan
struct pesanan pesan[30];

// Fungsi untuk menghitung harga total berdasarkan jenis ayam dan jumlah yang dipesan
int hitungHarga(char jenis, int jmlOrd);

int main() {
    int i, j;  // Variabel untuk iterasi
    printf("Toko GFC - Gerobak Fried Chicken\n");
    printf("DAFTAR HARGA\n");
    printf("Kode\tJenis\tHarga per potong\n");

    // Menampilkan daftar harga ayam
    for (i = 0; i < 3; i++) {
        printf("%c\t%s\tRp. %d.00\n", ayam[i].kode, ayam[i].jenis, ayam[i].harga);
    }

    printf("Harga belum termasuk pajak: 10%%\n\n");
    printf("Masukkan Pesanan Anda\n");

    char lanjut = 't';  // Variabel untuk cek apakah pelanggan ingin melanjutkan pesanan
    int numOrd = 0;     // Nomor urut pesanan
    int jmlBayar = 0;   // Total harga yang harus dibayar

    do {
        printf("Pesanan ke-%d\n", numOrd + 1);

        fflush(stdin);

        // Memasukkan jenis ayam yang dipesan
        printf("Jenis [D/P/S]: ");
        scanf("%c", &pesan[numOrd].kode);

        // Memasukkan jumlah ayam yang dipesan
        printf("Jumlah: ");
        scanf("%d", &pesan[numOrd].qty);

        // Menghitung total harga untuk pesanan ini
        pesan[numOrd].jumlah = hitungHarga(pesan[numOrd].kode, pesan[numOrd].qty);

        // Menambahkan total harga ke jumlah pembayaran
        jmlBayar += pesan[numOrd].jumlah;
        numOrd++;  // Menambah nomor pesanan

        fflush(stdin);

        // Menanyakan apakah pelanggan ingin memesan lagi
        printf("Ada lagi (y/t)?: ");
        scanf("%c", &lanjut);

    } while (lanjut == 'Y' || lanjut == 'y');  // Loop berlanjut jika jawaban 'Y' atau 'y'

    // Menampilkan nota belanja
    printf("\n\nNota Belanja Anda:\n");
    printf("\t\t\tGEROBAK FRIED CHICKEN\n");
    printf("===============================================================\n");
    printf(" No\tJenis Potong\tHarga Satuan\tQty\tJumlah Harga\n");
    printf("===============================================================\n");

    // Menampilkan setiap pesanan yang telah dimasukkan
    for (i = 0; i < numOrd; i++) {
        printf(" %d\t", i + 1);

        // Mencocokkan kode ayam dengan daftar ayam yang tersedia
        for (j = 0; j < 3; j++) {
            if (pesan[i].kode == ayam[j].kode) {
                printf("%s\t", ayam[j].jenis);  // Menampilkan jenis ayam
                printf("\tRp. %d.00\t", ayam[j].harga);  // Menampilkan harga ayam
            }
        }

        // Menampilkan jumlah ayam yang dipesan dan total harga untuk pesanan tersebut
        printf("%d\t", pesan[i].qty);
        printf("Rp. %d.00\n", pesan[i].jumlah);
    }

    // Menampilkan total harga sebelum pajak
    printf("\n\t\t\tJumlah sebelum pajak\tRp. %d.00\n", jmlBayar);

    // Menghitung pajak 10% dan menampilkan hasilnya
    int pajak = jmlBayar * 0.1;
    printf("\t\t\t\tPajak 10%% \tRp. %d.00\n", pajak);

    // Menghitung total bayar setelah pajak
    int bayar = jmlBayar + pajak;
    printf("\t\t\t\tTotal Bayar\tRp. %d.00\n", bayar);

    printf("\n\t\tTERIMA KASIH ATAS KUNJUNGAN ANDA\n");

    return 0;
}

// Fungsi untuk menghitung harga berdasarkan jenis ayam dan jumlah yang dipesan
int hitungHarga(char jenis, int jmlOrd) {
    int i;
    for (i = 0; i < 3; i++) {
        if (ayam[i].kode == jenis) {
            return jmlOrd * ayam[i].harga;  // Mengembalikan total harga (jumlah * harga per potong)
        }
    }
    return 0;  // Jika jenis ayam tidak ditemukan
}
