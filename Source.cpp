#include <iostream>
#include <string>
#include <cstdlib>
#include <io.h>
#include <windows.h>

bool checkGCC() {
    return system("g++ --version >nul 2>&1") == 0;
}

void installGCC() {
    std::cout << "GCC bulunamadi, otomatik kurulum baslatiliyor...\n";
    std::cout << "MinGW-w64 indiriliyor...\n";
    
    system("powershell -Command \"Invoke-WebRequest -Uri 'https://github.com/niXman/mingw-builds-binaries/releases/download/13.2.0-rt_v11-rev1/winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64-11.0.0-r1.zip' -OutFile 'mingw.zip'\"");
    
    std::cout << "Arsiv aciliyor...\n";
    system("powershell -Command \"Expand-Archive -Path 'mingw.zip' -DestinationPath 'C:\\mingw64' -Force\"");
    
    std::cout << "PATH degiskeni guncelleniyor...\n";
    system("setx PATH \"%PATH%;C:\\mingw64\\bin\" /M");
    
    std::cout << "Gecici dosyalar temizleniyor...\n";
    system("del mingw.zip");
    
    std::cout << "Kurulum tamamlandi! Lutfen yeni bir terminal acin.\n";
}

bool fixPath() {
    std::cout << "PATH sorunu duzeltiliyor...\n";
    
    std::string mevcutPath;
    char* pathDegiskeni = getenv("PATH");
    if (pathDegiskeni) {
        mevcutPath = pathDegiskeni;
    }
    
    if (mevcutPath.find("mingw64\\bin") == std::string::npos) {
        system("setx PATH \"%PATH%;C:\\mingw64\\bin\" /M");
        std::cout << "PATH guncellendi. Yeni terminal gerekli.\n";
        return false;
    }
    return true;
}

std::string getFileExtension(const std::string& dosyaAdi) {
    size_t pos = dosyaAdi.find_last_of(".");
    if (pos == std::string::npos) return "";
    return dosyaAdi.substr(pos);
}

std::string getFileName(const std::string& yol) {
    size_t pos = yol.find_last_of("\\/");
    if (pos == std::string::npos) return yol;
    return yol.substr(pos + 1);
}

std::string getFileDir(const std::string& yol) {
    size_t pos = yol.find_last_of("\\/");
    if (pos == std::string::npos) return "";
    return yol.substr(0, pos);
}

long getFileSize(const std::string& dosyaAdi) {
    FILE* dosya = fopen(dosyaAdi.c_str(), "rb");
    if (!dosya) return 0;
    
    fseek(dosya, 0, SEEK_END);
    long boyut = ftell(dosya);
    fclose(dosya);
    return boyut;
}

bool compileFile(const std::string& girisDosya, const std::string& ciktiDosya) {
    std::string komut = "g++ \"" + girisDosya + "\" -o \"" + ciktiDosya + "\" -static-libgcc -static-libstdc++";
    
    std::cout << "Derleme komutu: " << komut << "\n";
    int sonuc = system(komut.c_str());
    
    return sonuc == 0;
}

int main(int argc, char* argv[]) {
    setlocale(LC_ALL, "Turkish");
    
    std::cout << "=============================================\n";
    std::cout << "     Evrensel C++ Derleyici\n";
    std::cout << "=============================================\n\n";
    
    if (argc < 2) {
        std::cout << "Kullanim: " << argv[0] << " <dosya.cpp>\n";
        std::cout << "Veya dosyayi surukleyip birakin.\n\n";
        system("pause");
        return 1;
    }
    
    std::string inputFile = argv[1];
    
    if (_access(inputFile.c_str(), 0) != 0) {
        std::cout << "Hata: Dosya bulunamadi - " << inputFile << "\n";
        system("pause");
        return 1;
    }
    
    std::string ext = getFileExtension(inputFile);
    if (ext != ".cpp" && ext != ".c" && ext != ".cxx" && ext != ".cc") {
        std::cout << "Hata: Desteklenen dosya turleri: .cpp, .c, .cxx, .cc\n";
        std::cout << "Gelen dosya: " << inputFile << "\n";
        system("pause");
        return 1;
    }
    
    std::string outputFile = inputFile.substr(0, inputFile.find_last_of(".")) + ".exe";
    std::string inputName = getFileName(inputFile);
    std::string outputName = getFileName(outputFile);
    std::string dir = getFileDir(inputFile);
    
    std::cout << "Dosya: " << inputName << "\n";
    std::cout << "Cikti: " << outputName << "\n";
    std::cout << "Klasor: " << dir << "\n\n";
    
    if (!checkGCC()) {
        installGCC();
        if (!checkGCC()) {
            std::cout << "GCC kurulumu basarisiz. Manuel kurulum gerekli.\n";
            system("pause");
            return 1;
        }
    }
    
    std::cout << "Derleme basliyor...\n";
    
    if (!compileFile(inputFile, outputFile)) {
        std::cout << "\nDerleme hatasi!\n";
        
        if (!fixPath()) {
            std::cout << "PATH duzeltildi. Lutfen programi tekrar calistirin.\n";
        } else {
            std::cout << "Kod kontrol edin:\n";
            std::cout << "1. Syntax hatalari\n";
            std::cout << "2. Eksik kutuphaneler\n";
            std::cout << "3. Yanlis dosya yolu\n";
        }
        
        system("pause");
        return 1;
    }
    
    std::cout << "\nBasarili! " << outputName << " olusturuldu.\n";
    
    if (_access(outputFile.c_str(), 0) == 0) {
        long size = getFileSize(outputFile);
        std::cout << "Boyut: " << size << " byte\n";
        std::cout << "Konum: " << outputFile << "\n";
    }
    
    std::cout << "\nCikmak icin bir tusa basin...\n";
    system("pause >nul");
    
    return 0;
}