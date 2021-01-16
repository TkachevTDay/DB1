#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;
ifstream in; //file input stream
ofstream out;//file output stream
int str_num = 0;
string cmd;
string in_str; string close;
string address = "..\\data.txt"; //address to main file (cannot be changed)
class functions { //creating class for our functions
public:
    void printFile() {
        string adrForPrint;
        string forPrint;
        cout << "Enter full path to file: ";
        cin >> adrForPrint;
        getFrom(forPrint);
    }
    void upload() {
        char accept;
        string ForCopy; //uploading data storage
        string adrForCopy; //address to file to uploaded data
        cout << "Enter full path to file for upload> ";
        cin >> adrForCopy;
        in.open(address, ios::beg);
        in.seekg(0, ios_base::beg);
        //copying
        out.open(adrForCopy, ios::beg);
        while (getline(in, ForCopy)) {
            out << ForCopy << '\n';
        }
        in.close();
        out.close();
        //erasing main data
        out.open(address, ios::trunc);
        cout << "Successefuly done!" << '\n';
        out.close();
    }
    void download() {
        string adrForDownload; //adress to file for download
        string ForDownload; //data storage for downloading
        char accept; //acception character y/n
        cout << "Are u really want to download data from another file, current data will be erased" << '\n';
        cout << "y/n =--> ";
        cin >> accept;
        //acception changes
        if (accept == 'y') {
            cout << "Enter full path to file for download> ";
            cin >> adrForDownload;
            in.open(adrForDownload, ios::beg);
            //opening file for downloading
            out.open(address, ios::trunc);
            //opening file with erasing
            while (getline(in, ForDownload)) {
                out << ForDownload << '\n';
            }
            in.close();
            out.close();
            //cloasing streams
            cout << "Download complete";
            
        }
        else if (accept == 'n') {
            cout << "Downloading canceled";
        }
    }
    void help() {
        //printing promt, maybe it will help.
        cout << "    add - add string to file" << '\n';
        cout << "    find - finds string by number" << '\n';
        cout << "    print - prints all data" << '\n';
        cout << "    erase - deleting all data" << '\n';
        cout << "    exit - close a program" << '\n';
        cout << "    clear - clears console" << '\n';
        cout << "    size - prints size of file" << '\n';
        cout << "    upload - moving data to anoyher file with erasing main file" << '\n';
        cout << "    download - downloading data from another file with auto erasing current data in main file." << '\n';
    }
    void add() {
        out.open(address, ios::app);
        //opening main file in end for editing
        string a;
        cout << "enter string > ";
        getline(cin, a);
        out << a;
        out << '\n';
        out.seekp(0, ios_base::beg);
        cout << "Add successeful.";
        out.close();
    }
    void find() {
        in.open(address);
        in.seekg(0, ios_base::beg);
        cout << "Insert number of string to open." << '\n';
        int num = 0;
        cout << "---> ";
        cin >> str_num;
        //founding string
        while (getline(in, in_str)) {
            if (++num == str_num)
                cout << "Founded successefuly, string contains: " << in_str << '\n';
        }
        in.clear();
        in.close();
    }
    void erase() {
        char accept;
        cout << "Are u really want to delete all data?" << '\n' << "Print y/n to continue." << '\n' << "---> ";
        //accepting changes
        cin >> accept;
        if (accept == 'y') {
            out.open(address, ios::trunc);
            //opening file with data deleting
            cout << "Successefuly done!" << '\n';
            out.close();
        }
        else if (accept == 'n') {
            cout << "Operation canceled." << '\n';
        }
    }
    void print() {
        string printIn;
        getFrom(printIn);
    }
    void exit() {
        system("color 4");
        cout << "EXIT SUCCESSEFUL.";
        _Exit(EXIT_SUCCESS); //right terminating with "_Exit"
    }
    void clear() {
        //using "cls" for cleaning console
        system("cls");
        cout << "---<help - for help>---";
    }
    void size() {
        //a bit of misunderstanding
        //but i know: IT'S WORKS
        streampos begin, end;
        in.open(address, ios::binary);
        begin = in.tellg();
        in.seekg(0, ios::end);
        end = in.tellg();
        in.close();
        cout << "size is: " << (end - begin) << " bytes.\n";
    }
    private:
        void getFrom(string a) {
            in.seekg(0, ios_base::beg);
            int j = 0;
            in.open(address, ios::beg);
            while (getline(in, a)) {
                cout << j << "---> " << a << '\n';
                j++;
            }
            in.close();
        }
};
int main()
{
    functions func;
    cout << "---<help - for help>---";
    do {
        cout << '\n' << "what operation u want to do?" << '\n';
        cout << "---> ";
        cin >> cmd;
        cin.get();
        //reading cmd with cleaning input stream
        if (cmd == "find") {
            func.find();
        }
        else if (cmd == "erase") {
            func.erase();
        }
        else if (cmd == "add") {
            func.add();
        }
        else if (cmd == "print") {
            func.print();
        }
        else if (cmd == "exit") {
            func.exit();
        }
        else if (cmd == "clear") {
            func.clear();
        }
        else if (cmd == "help") {
            func.help();
        }
        else if (cmd == "size") {
            func.size();
        }
        else if (cmd == "upload") {
            func.upload();
        }
        else if (cmd == "download") {
            func.download();
        }
        else if (cmd == "print-file") {
            func.printFile();
        }
    } while (true);
}