#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur data produk
struct Produk {
    char nama[50];

    float harga;
    struct Produk* next;
};

// Buat node baru
struct Produk* buatProduk(char nama[], float harga) {
    struct Produk* baru = (struct Produk*)malloc(sizeof(struct Produk));
    strcpy(baru->nama, nama);
    baru->harga = harga;
    baru->next = NULL;
    return baru;
}

// Tambah produk ke akhir list
void tambahProduk(struct Produk** head, char nama[], float harga) {
    struct Produk* baru = buatProduk(nama, harga);
    if (*head == NULL) {
        *head = baru;
        return;
    }
    struct Produk* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = baru;
}

// Tampilkan daftar produk
void tampilkanProduk(struct Produk* head) {
    if (head == NULL) {
        printf("Daftar produk kosong.\n");
        return;
    }

    printf("\nDaftar Produk:\n");
    while (head != NULL) {
        printf("- %s: Rp %.2f\n", head->nama, head->harga);
        head = head->next;
    }
}

// Urutkan produk berdasarkan harga (bubble sort for linked list)
void urutkanProduk(struct Produk* head) {
    int swapped;
    struct Produk *ptr1, *lptr = NULL;

    if (head == NULL)
        return;

    do {
        swapped = 0;
        ptr1 = head;

        while (ptr1->next != lptr) {
            if (ptr1->harga > ptr1->next->harga) {
                // Tukar isi node
                float tempHarga = ptr1->harga;
                char tempNama[50];
                strcpy(tempNama, ptr1->nama);

                ptr1->harga = ptr1->next->harga;
                strcpy(ptr1->nama, ptr1->next->nama);

                ptr1->next->harga = tempHarga;
                strcpy(ptr1->next->nama, tempNama);

                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        lptr = ptr1;
    } while (swapped);
}

// Fungsi utama
int main() {
    struct Produk* daftar = NULL;
    int pilihan;
    char nama[50];
    float harga;

    do {
        printf("\n=== Menu Produk ===\n");
        printf("1. Tambah Produk\n");
        printf("2. Tampilkan Produk\n");
        printf("3. Urutkan Berdasarkan Harga\n");
        printf("4. Keluar\n");
        printf("Pilih: ");
        scanf("%d", &pilihan);
        getchar(); // Bersihkan newline

        switch (pilihan) {
            case 1:
                printf("Nama produk: ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
                printf("Harga produk: Rp ");
                scanf("%f", &harga);
                getchar();
                tambahProduk(&daftar, nama, harga);
                break;

            case 2:
                tampilkanProduk(daftar);
                break;

            case 3:
                urutkanProduk(daftar);
                printf("Produk berhasil diurutkan berdasarkan harga.\n");
                break;

            case 4:
                printf("Terima kasih telah mengunakan program kelompok 5:)\n");
                break;

            default:
                printf("Pilihan tidak valid.\n");
        }

    } while (pilihan != 4);

    return 0;
}





