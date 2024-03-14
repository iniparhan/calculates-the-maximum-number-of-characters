#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20
#define MIN_LENGTH 10

// Fungsi ini mencetak pesan panjang teks kurang dari yang ditentukan dan mengatur lengthOfText ke MIN_LENGTH
void lessThanRequired (int* lengthOfText){
    // TODO
    printf("The length of your text is less than specified, please update your text");
    *lengthOfText = MIN_LENGTH;

}

// Fungsi ini mencetak pesan panjang teks sudah benar.
void equalThanRequired (){
    // TODO
    printf("Thank you, Your text length is correct");
}

// Fungsi ini mencetak pesan teks terlalu panjang dan mengatur lengthOfText ke MIN_LENGTH
void moreThanRequired (int* lengthOfText){
    // TODO
    printf("Your text is to long, please reduce the text");
    *lengthOfText = MIN_LENGTH;
}

// Fungsi ini memeriksa panjang teks 
int checkLenghtRequirement(char* text){
    int length = strlen(text);
    // mengembalikan 0 jika kurang dari MIN_LENGTH
    if (length < MIN_LENGTH)
        return 0;
    // mengembalikan 1 jika sama dengan MIN_LENGTH
    else if (length == MIN_LENGTH)
        return 1;
    // mengembalikan 2 jika lebih dari MIN_LENGTH
    else
        return 2;
}

int main() {
    // Mendeklarasikan variabel
    int length, lengthOfText, selectOption;
    
    // Mendeklarasikan pointer `fptr` dari tipe data `FILE`. digunakan untuk menangani file.
    FILE *fptr = NULL;

    // Variabel penampung teks dari file
    char text[MAX_LENGTH];

    //  Membuka file bernama `file.txt.txt` dalam mode baca (`r`). 
    fptr = fopen("file.txt", "r");

    // //  Mengecek apakah file berhasil dibuka atau tidak. Jika tidak, program akan mencetak pesan 'error'
    if(fptr == NULL){
        printf("Error");
        exit(1);
    }

    // Membaca teks dari file dan menyimpannya dalam array 'text'
    fgets(text, MAX_LENGTH, fptr);

    // Menutup file
    fclose(fptr);

    // memanggil fungsi 'checkLenghtRequirement' dan menyimpan hasil ke variabel 'selectOption' 
    selectOption = checkLenghtRequirement(text);
    
    // array yang berisi fungsi
    void (*functions[3])(int*) = {lessThanRequired, equalThanRequired, moreThanRequired};
    // Fungsi yang dipanggil dari nilai selectOption. Jika selectOption adalah 0, maka lessThanRequired dipanggil, dst. Argumen fungsi ini adalah alamat dari lengthOfText
    (*functions[selectOption])(&lengthOfText);
    
    // mencetak pesan bahwa panjang teks telah diperbarui ke nilai 'lengthOfText'
    printf("\nThe Lenght is updated to %d", lengthOfText);

    // TODO
    // Pada fungsi checkLenghtRequirement akan mengembalikan sebuah angka
    // angka tersebut digunakan untuk memilih secara otomatis salah satu fungsi yang harus diisi
    // jika fungsi checkLenghtRequirement() mengembalikan nilai 0, maka
    //      tampilkan - > The length of your text is less than specified, please update your text
    
    //      update nilai lengthOfText ke minimum requirement melalui pointer menggunakan operasi aritmatika

    // jika fungsi checkLenghtRequirement() mengembalikan nilai 1, maka
    //      tampilkan - > Thank you, Your text length is correct
    

    // jika fungsi checkLenghtRequirement() mengembalikan nilai 2, maka
    //      tampilkan - > Your text is to long, please reduce the text
    //      update nilai lengthOfText ke minimum requirement melalui pointer menggunakan operasi aritmatika
    //
    // Catatan :
    //      - tidak diperkenankan menggunakan if atau switch dalam perpindahan fungsi
    //        sesuai dengan requirement diatas.
    //      - baris kode tidak lebih dari 100 (include comment ini)
    //      - tidak diperkenankan mengganti yang tertera pada starter code dalam alasan apapun

    return 0;
}
