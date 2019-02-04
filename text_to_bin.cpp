#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void main(int argc, char** argv){
    std::string mkdir = "mkdir ";
    system("mkdir OUTPUTS 1>NUL 2>NUL");
    std::string SESSION_NAME;
    std::cout << "Name output folder: ";
    std::cin >> SESSION_NAME;
    std::cout << std::endl;
    system((mkdir + std::string("OUTPUTS\\") + SESSION_NAME).c_str());

    std::ifstream f;
    int filelen;
    if(!(argc-1))
        f.open("source.txt");
    else
       f.open(argv[1]);
    f.seekg(0, std::ios::end);
    filelen = f.tellg();
    char* buf = (char*)calloc(filelen, sizeof(char));
    f.seekg(0, std::ios::beg);
    f.read(buf, filelen);
    f.close();

    std::stringstream buffer;
    for(int i = 0; i < filelen; i++){
        buffer << std::hex << (int)buf[i];
    }

    std::ofstream input_save;
    input_save.open(std::string("./OUTPUTS/") + SESSION_NAME + std::string("/output.asc.txt"));
    input_save << buf;
    input_save.close();

    std::string dat = buffer.str();
    std::ofstream hexdata;
    hexdata.open(std::string("./OUTPUTS/") + SESSION_NAME + std::string("/output.hex.txt"));
    hexdata << dat;
    hexdata.close();

    std::ofstream file;
    file.open(std::string("./OUTPUTS/") + SESSION_NAME + std::string("/output.bin.txt"));
    for(int i = 0; i < dat.size(); i++){
        char* c;
        switch((char)dat[i]){
            case '0': c = "0000"; break;
            case '1': c = "0001"; break;
            case '2': c = "0010"; break;
            case '3': c = "0011"; break;
            case '4': c = "0100"; break;
            case '5': c = "0101"; break;
            case '6': c = "0110"; break;
            case '7': c = "0111"; break;
            case '8': c = "1000"; break;
            case '9': c = "1001"; break;
            case 'a': c = "1010"; break;
            case 'b': c = "1011"; break;
            case 'c': c = "1100"; break;
            case 'd': c = "1101"; break;
            case 'e': c = "1110"; break;
            case 'f': c = "1111"; break;
        }
        file << c;
    }
    file.close();
}