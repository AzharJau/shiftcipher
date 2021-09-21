/*
Nama        : Azhar Jauharul Umam
NPM         : 1408101900430
Kelas       : B
Desk        : Program Shift Cipher
*/

#include <iostream>
#include <string.h>
using namespace std;

string enkripsi(string text, int key) {
        char ch;
        for(int i = 0; text[i] != '\0'; ++i) {
            ch = text[i];
            // Enkripsi Lowercase Letter
            if (ch >= 'a' && ch <= 'z') {
                ch = ch + key;
                if (ch > 'z') {
                    ch = ch - 'z' + 'a' - 1;
                }  
                text[i] = ch;
            }
            // Enkripsi Uppercase Letter
            else if (ch >= 'A' && ch <= 'Z') {
                ch = ch + key;
                if (ch > 'Z') {
                    ch = ch - 'Z' + 'A' - 1;
                }
                text[i] = ch;
            }
        }
        return text;
}
string dekripsi(string text, int key){
        char ch;
        // Algoritma Dekripsi
        for(int i = 0; text[i] != '\0'; ++i) {
            ch = text[i];
            // Dekripsi Lowercase Letter
            if(ch >= 'a' && ch <= 'z') {
                ch = ch - key;
                if(ch < 'a') {
                    ch = ch + 'z' - 'a' + 1;
                }
            text[i] = ch;
            }
            // Dekripsi Uppercase Letter
            else if(ch >= 'A' && ch <= 'Z') {
                ch = ch - key;
                if(ch < 'A') {
                    ch = ch + 'Z' - 'A' + 1;
                }
                text[i] = ch;
            }
        }
        return text;
}

main() {
    string menu;
    int key; 

    do {
        cout << "Input Text     : ";
        string text = "";
        getline(cin >> ws, text);


        cout << "Input Key      : ";
        cin >> key;
        string ciphertext = enkripsi(text, key);

        cout << endl << "Hasil Enkripsi: " << ciphertext << endl;
        cout << "Hasil Dekripsi: " << dekripsi(ciphertext, key);


        cout << "\nBack to menu? (Y/N) : ";
        cin >> menu;
    } while(menu == "Y" || menu == "y");

    return 0;
}