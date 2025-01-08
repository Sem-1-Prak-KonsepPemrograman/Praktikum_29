#include <stdio.h>
#include <stdlib.h>

// Struktur untuk menyimpan informasi tanggal
struct date {
    int month, day, year;  // Bulan, hari, dan tahun
} today = {12, 25, 2006}, tomorrow;  // Tanggal hari ini (25 Desember 2006)

// Struktur untuk menyimpan informasi mahasiswa, termasuk nama dan tanggal lahir
struct student {
    char name[30];  // Nama mahasiswa
    struct date birthday;  // Tanggal lahir mahasiswa
} data_mhs[20];  // Array untuk menyimpan data mahasiswa sebanyak 20

struct student mhs;  // Struktur untuk menyimpan data mahasiswa satu per satu

int main() {
    // Inisialisasi tanggal lahir mahasiswa
    mhs.birthday.day = 12;
    mhs.birthday.month = 1;
    mhs.birthday.year = 2000;

    // Menyimpan tanggal lahir mahasiswa ke dalam variabel tgl
    int tgl = mhs.birthday.day;

    // Menampilkan tanggal hari ini
    printf("%d-%d-%d\n\n", today.day, today.month, today.year);

    // Menyimpan data mahasiswa secara langsung dengan nilai yang ditentukan
    struct student mhs = {"Muhammad", 2, 28, 1970};
    printf("%s\t%d-%d-%d\n\n", mhs.name, mhs.birthday.month, mhs.birthday.day, mhs.birthday.year);

    // Praktikum 5, no. 5
    printf("---------------------------------------------------------------------------------\n");
    printf("Input Data Mahasiswa\n");
    printf("---------------------------------------------------------------------------------\n");

    // Mendeklarasikan variabel i (indeks array) dan jml (jumlah data mahasiswa)
    int i = 0, jml;
    char lagi;  // Variabel untuk mengecek apakah pengguna ingin memasukkan data lagi

    do {
        // Memasukkan nama mahasiswa
        printf("Name : ");
        gets(data_mhs[i].name);  // Fungsi gets untuk input nama (sebaiknya hindari gets)
        
        // Memasukkan tanggal lahir mahasiswa
        printf("Birthday (mm-dd-yyyy): ");
        scanf("%d-%d-%d", &data_mhs[i].birthday.month, &data_mhs[i].birthday.day, &data_mhs[i].birthday.year);
        i++;  // Increment indeks untuk data mahasiswa berikutnya

        // Menghapus sisa data di buffer input
        fflush(stdin);

        // Menanyakan apakah ingin memasukkan data lagi
        printf("\nMau memasukkan data lagi [Y/T] ? ");
        lagi = getchar();  // Membaca pilihan pengguna
        fflush(stdin);  // Menghapus sisa data di buffer input

    } while(lagi == 'Y' || lagi == 'y');  // Looping selama pengguna memilih untuk memasukkan data lagi

    jml = i;  // Menyimpan jumlah data mahasiswa yang dimasukkan

    // Menampilkan data mahasiswa yang telah dimasukkan
    printf("\nDATA MAHASISWA\n");
    for (i = 0; i < jml; i++) {
        printf("%d. Name : %s", i + 1, data_mhs[i].name);  // Menampilkan nama mahasiswa
        printf("\n Birthday: %d-%d-%d\n\n", data_mhs[i].birthday.month, data_mhs[i].birthday.day, data_mhs[i].birthday.year);  // Menampilkan tanggal lahir mahasiswa
    }

    return 0;  // Program selesai
}
