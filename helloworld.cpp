#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to encrypt text using Caesar cipher
string caesarEncrypt(const string& text, int shift) {  //: Определение функции для шифрования текста шифром Цезаря.

    string result = "";
    for (char ch : text) { // Цикл, проходящий по каждому символу в тексте
        if (isalpha(ch)) { // Проверка, является ли символ буквой.
            char base = isupper(ch) ? 'A' : 'a'; //Определение базового символа ('A' или 'a') в зависимости от регистра.
            result += static_cast<char>((ch - base + shift) % 26 + base); //Шифрование символа методом Цезаря и добавление его к результату.
        } else {
            result += ch; //Если символ не буква, добавить его к результату без изменений
        }
    }
    return result;
}

// Функция для расшифровки текста с помощью шифра Цезаря
string caesarDecrypt(const string& text, int shift) {  // Определение функции для шифрования текста шифром Виженера.
    return caesarEncrypt(text, 26 - shift); // Дешифрование - это просто шифрование с обратным сдвигом
}

// Функция для шифрования текста с использованием шифра Виженера
string vigenereEncrypt(const string& text, const string& key) {
    string result = "";
    for (size_t i = 0; i < text.length(); ++i) {
        char ch = text[i]; // Определение символа ключа для текущего символа текста
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyChar = key[i % key.length()];
            result += static_cast<char>((ch - base + keyChar - base) % 26 + base); //Шифрование символа методом Виженера и добавление его к результату
        } else {
            result += ch;
        }
    }
    return result;
}

// Функция для расшифровки текста с использованием шифра Виженера
string vigenereDecrypt(const string& text, const string& key) {
    string result = "";
    for (size_t i = 0; i < text.length(); ++i) {
        char ch = text[i];
        if (isalpha(ch)) {
            char base = isupper(ch) ? 'A' : 'a';
            char keyChar = key[i % key.length()];
            result += static_cast<char>((ch - base - keyChar + base + 26) % 26 + base); // Шифрование символа методом Виженера и добавление его к результату
        } else {
            result += ch;
        }
    }
    return result;
}

int main() {
    // Получать вводимые пользователем данные
    string text;
    int shift;
    string key;

    cout << "Enter the text to encrypt/decrypt: ";
    getline(cin, text);

    cout << "Enter the shift value for Caesar cipher: ";
    cin >> shift;

    cout << "Enter the key for Vigenere cipher: ";
    cin >> key;

    // Шифрование и дешифрование с помощью шифра Цезаря
    string encryptedCaesar = caesarEncrypt(text, shift);
    string decryptedCaesar = caesarDecrypt(encryptedCaesar, shift);

    // Шифрование и дешифрование с помощью шифра Виженера
    string encryptedVigenere = vigenereEncrypt(text, key);
    string decryptedVigenere = vigenereDecrypt(encryptedVigenere, key);

    // результат
    cout << "\nCaesar Cipher:" << endl;
    cout << "Encrypted: " << encryptedCaesar << endl;
    cout << "Decrypted: " << decryptedCaesar << endl;

    cout << "\nVigenere Cipher:" << endl;
    cout << "Encrypted: " << encryptedVigenere << endl;
    cout << "Decrypted: " << decryptedVigenere << endl;

    // сохранение
    ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "Caesar Cipher:\n";
        outputFile << "Encrypted: " << encryptedCaesar << "\n";
        outputFile << "Decrypted: " << decryptedCaesar << "\n\n";
        outputFile << "Vigenere Cipher:\n";
        outputFile << "Encrypted: " << encryptedVigenere << "\n";
        outputFile << "Decrypted: " << decryptedVigenere << "\n";
        outputFile.close();
        cout << "\nResults saved to 'output.txt'\n";
    } else {
        cerr << "Error: Unable to open output file." << endl;
    }

    return 0;
}
