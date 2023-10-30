#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

namespace FileHandlers {

    class FileDisplayer {
    public:
        void Display(const char* path) {
            ifstream file(path);
            if (!file.is_open()) {
                cout << "Error opening the file!" << endl;
                return;
            }

            char ch;
            while (file.get(ch)) {
                cout << ch;
            }

            file.close();
        }
    };

    class AsciiDisplayer : public FileDisplayer {
    public:
        void Display(const char* path) {
            ifstream file(path);
            if (!file.is_open()) {
                cout << "Error opening the file!" << endl;
                return;
            }

            char ch;
            while (file.get(ch)) {
                cout << static_cast<int>(ch) << " ";
            }

            file.close();
        }
    };

    class BinaryDisplayer : public FileDisplayer {
    public:
        void Display(const char* path) {
            ifstream file(path, ios::binary);
            if (!file.is_open()) {
                cout << "Error opening the file!" << endl;
                return;
            }

            char ch;
            while (file.get(ch)) {
                for (int i = 7; i >= 0; --i) {
                    cout << ((ch >> i) & 1);
                }
                cout << " ";
            }

            file.close();
        }
    };

} 

int main() {
    using namespace FileHandlers;

    FileDisplayer basicDisplayer;
    AsciiDisplayer asciiDisplayer;
    BinaryDisplayer binaryDisplayer;

    const char* path = "text.txt"; 

    basicDisplayer.Display(path);
    cout << "\n\n";

    asciiDisplayer.Display(path);
    cout << "\n\n";

    binaryDisplayer.Display(path);
    cout << "\n\n";

}