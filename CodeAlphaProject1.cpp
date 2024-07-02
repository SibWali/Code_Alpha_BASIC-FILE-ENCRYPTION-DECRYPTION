#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class MyEncoder {
public:
    MyEncoder(); // Constructor
    virtual ~MyEncoder(); // Destructor

    // Getter and setter for 'file' member variable
    string Getfile() { return file; }
    void Setfile(string val) { file = val; }

    // Getter and setter for 'c' member variable
    char Getc() { return c; }
    void Setc(char val) { c = val; }

    // Getter and setter for 'key' member variable
    int Getkey() { return key; }
    void Setkey(int val) { key = val; }

    void encrypt(); // Method to encrypt a file
    void decrypt(); // Method to decrypt a file
    void fillDiary(); // Method to fill a diary file

private:
    string file; // Holds the filename for file operations
    char c; // Holds characters read from input streams
    int key; // Holds the encryption/decryption key
};

MyEncoder::MyEncoder() {
    // Default constructor
}

MyEncoder::~MyEncoder() {
    // Destructor
}

void MyEncoder::encrypt() {
    cout << "Enter filename to encrypt: ";
    cin >> file;
    cout << "Enter encryption key: ";
    cin >> key;

    // Input and output file streams
    fstream fin, fout;

    // Open input file for reading
    fin.open(file, fstream::in);

    // Open output file for writing
    fout.open("encrypted.txt", fstream::out);

    // Encrypting each character in the input file
    while (fin >> noskipws >> c) {
        int temp = (c + key); // Encryption process
        fout << (char)temp; // Write encrypted character to output file
    }

    // Close input and output files
    fin.close();
    fout.close();

    cout << "Encryption completed successfully." << endl;
}

void MyEncoder::decrypt() {
    cout << "Enter decryption key: ";
    cin >> key;

    // Input and output file streams
    fstream fin, fout;

    // Open encrypted input file for reading
    fin.open("encrypted.txt", fstream::in);

    // Open output file for decrypted text
    fout.open("decrypted.txt", fstream::out);

    // Decrypting each character in the input file
    while (fin >> noskipws >> c) {
        int temp = (c - key); // Decryption process
        fout << (char)temp; // Write decrypted character to output file
    }

    // Close input and output files
    fin.close();
    fout.close();

    cout << "Decryption completed successfully." << endl;
}

void MyEncoder::fillDiary() {
    cout << "Enter filename to write diary entries: ";
    string file, text;
    cin >> file;

    // Output file stream for writing diary entries
    fstream fout;
    fout.open(file, fstream::out);

    char loop = '#'; // Loop control variable
    while (loop != 's') {
        cout << "Enter diary entry (press enter to end line): ";
        cin.ignore(); // Ignore any leftover newline characters
        getline(cin, text); // Read a line of text from console input
        fout << text << endl; // Write text to file, followed by newline
        cout << "Type 's' to end, otherwise continue: ";
        cin >> loop; // Prompt user to continue or end loop
    }

    // Close the diary file
    fout.close();

    cout << "Diary entries written successfully." << endl;
}

int main() {
    MyEncoder encoder;
    int choice;

    do {
        // Menu for operations
        cout << "\nBasic File Encrypt/Decrypt Program\n";
        cout << "1. Encrypt\n";
        cout << "2. Decrypt\n";
        cout << "3. Enter the text in the file\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            encoder.encrypt();
            break;
        case 2:
            encoder.decrypt();
            break;
        case 3:
            encoder.fillDiary();
            break;
        case 4:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please enter a valid option.\n";
        }
    } while (choice != 4);
    system("pause");
    return 0;
}
