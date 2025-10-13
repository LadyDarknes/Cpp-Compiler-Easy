#include <iostream>
#include <string>
#include <cstdlib>
#include <io.h>
#include <windows.h>

enum Lang { EN = 1, TR = 2, JP = 3 };

std::string lokal(const std::string& key, int lang) {
    if (key == "banner_line") {
        return "=============================================";
    }
    if (key == "title") {
        if (lang == EN) return "     Universal C++ Compiler";
        if (lang == TR) return "     Evrensel C++ Derleyici";
        return "     ユニバーサル C++ コンパイラ";
    }
    if (key == "usage") {
        if (lang == EN) return "Usage: ";
        if (lang == TR) return "Kullanim: ";
        return "使い方: ";
    }
    if (key == "drag_drop") {
        if (lang == EN) return "Or drag and drop the file.";
        if (lang == TR) return "Veya dosyayi surukleyip birakin.";
        return "またはファイルをドラッグ＆ドロップしてください。";
    }
    if (key == "file_not_found") {
        if (lang == EN) return "Error: File not found - ";
        if (lang == TR) return "Hata: Dosya bulunamadi - ";
        return "エラー: ファイルが見つかりません - ";
    }
    if (key == "unsupported") {
        if (lang == EN) return "Error: Supported file types: .cpp, .c, .cxx, .cc";
        if (lang == TR) return "Hata: Desteklenen dosya turleri: .cpp, .c, .cxx, .cc";
        return "エラー: サポートされているファイル形式: .cpp, .c, .cxx, .cc";
    }
    if (key == "file_label") {
        if (lang == EN) return "File: ";
        if (lang == TR) return "Dosya: ";
        return "ファイル: ";
    }
    if (key == "output_label") {
        if (lang == EN) return "Output: ";
        if (lang == TR) return "Cikti: ";
        return "出力: ";
    }
    if (key == "dir_label") {
        if (lang == EN) return "Folder: ";
        if (lang == TR) return "Klasor: ";
        return "フォルダ: ";
    }
    if (key == "gcc_missing") {
        if (lang == EN) return "GCC not found, starting automatic installation...";
        if (lang == TR) return "GCC bulunamadi, otomatik kurulum baslatiliyor...";
        return "GCCが見つかりません。自動インストールを開始します...";
    }
    if (key == "downloading") {
        if (lang == EN) return "Downloading MinGW-w64...";
        if (lang == TR) return "MinGW-w64 indiriliyor...";
        return "MinGW-w64 をダウンロードしています...";
    }
    if (key == "extracting") {
        if (lang == EN) return "Extracting archive...";
        if (lang == TR) return "Arsiv aciliyor...";
        return "アーカイブを展開しています...";
    }
    if (key == "path_updating") {
        if (lang == EN) return "Updating PATH variable...";
        if (lang == TR) return "PATH degiskeni guncelleniyor...";
        return "PATH 変数を更新しています...";
    }
    if (key == "cleanup") {
        if (lang == EN) return "Cleaning temporary files...";
        if (lang == TR) return "Gecici dosyalar temizleniyor...";
        return "一時ファイルをクリーンアップしています...";
    }
    if (key == "install_done") {
        if (lang == EN) return "Installation complete! Please open a new terminal.";
        if (lang == TR) return "Kurulum tamamlandi! Lutfen yeni bir terminal acin.";
        return "インストールが完了しました。新しいターミナルを開いてください。";
    }
    if (key == "path_fixing") {
        if (lang == EN) return "Fixing PATH issue...";
        if (lang == TR) return "PATH sorunu duzeltiliyor...";
        return "PATH の問題を修正しています...";
    }
    if (key == "path_updated") {
        if (lang == EN) return "PATH updated. New terminal required.";
        if (lang == TR) return "PATH guncellendi. Yeni terminal gerekli.";
        return "PATH が更新されました。新しいターミナルが必要です。";
    }
    if (key == "compile_start") {
        if (lang == EN) return "Starting compilation...";
        if (lang == TR) return "Derleme basliyor...";
        return "コンパイルを開始します...";
    }
    if (key == "compile_command") {
        if (lang == EN) return "Compile command: ";
        if (lang == TR) return "Derleme komutu: ";
        return "コンパイルコマンド: ";
    }
    if (key == "compile_error") {
        if (lang == EN) return "Compilation error!";
        if (lang == TR) return "Derleme hatasi!";
        return "コンパイルエラー！";
    }
    if (key == "path_fixed_prompt") {
        if (lang == EN) return "PATH fixed. Please run the program again.";
        if (lang == TR) return "PATH duzeltildi. Lutfen programi tekrar calistirin.";
        return "PATH が修正されました。プログラムを再実行してください。";
    }
    if (key == "check_code") {
        if (lang == EN) return "Check your code:";
        if (lang == TR) return "Kod kontrol edin:";
        return "コードを確認してください:";
    }
    if (key == "syntax") {
        if (lang == EN) return "1. Syntax errors";
        if (lang == TR) return "1. Syntax hatalari";
        return "1. 構文エラー";
    }
    if (key == "libs") {
        if (lang == EN) return "2. Missing libraries";
        if (lang == TR) return "2. Eksik kutuphaneler";
        return "2. ライブラリが不足しています";
    }
    if (key == "wrong_path") {
        if (lang == EN) return "3. Wrong file path";
        if (lang == TR) return "3. Yanlis dosya yolu";
        return "3. ファイルパスが間違っています";
    }
    if (key == "success_prefix") {
        if (lang == EN) return "Success! ";
        if (lang == TR) return "Basarili! ";
        return "成功！ ";
    }
    if (key == "success_suffix") {
        if (lang == EN) return " created.";
        if (lang == TR) return " olusturuldu.";
        return " が作成されました。";
    }
    if (key == "size") {
        if (lang == EN) return "Size: ";
        if (lang == TR) return "Boyut: ";
        return "サイズ: ";
    }
    if (key == "location") {
        if (lang == EN) return "Location: ";
        if (lang == TR) return "Konum: ";
        return "場所: ";
    }
    if (key == "press_key") {
        if (lang == EN) return "Press any key to exit...";
        if (lang == TR) return "Cikmak icin bir tusa basin...";
        return "終了するには任意のキーを押してください...";
    }
    if (key == "select_lang") {
        if (lang == EN) return "Select language:\n1 English\n2 Turkish\n3 Japanese\nChoice: ";
        if (lang == TR) return "Dil secin:\n1 Ingilizce\n2 Turkce\n3 Japonca\nSecim: ";
        return "言語を選択してください:\n1 英語\n2 トルコ語\n3 日本語\n選択: ";
    }

    return std::string();
}

bool checkGCC() {
    return system("g++ --version >nul 2>&1") == 0;
}

void installGCC(int lang) {
    std::cout << lokal("gcc_missing", lang) << "\n";
    std::cout << lokal("downloading", lang) << "\n";
    
    system("powershell -Command \"Invoke-WebRequest -Uri 'https://github.com/niXman/mingw-builds-binaries/releases/download/13.2.0-rt_v11-rev1/winlibs-x86_64-posix-seh-gcc-13.2.0-mingw-w64-11.0.0-r1.zip' -OutFile 'mingw.zip'\"");
    
    std::cout << lokal("extracting", lang) << "\n";
    system("powershell -Command \"Expand-Archive -Path 'mingw.zip' -DestinationPath 'C:\\\\mingw64' -Force\"");
    
    std::cout << lokal("path_updating", lang) << "\n";
    system("setx PATH \"%PATH%;C:\\\\mingw64\\\\bin\" /M");
    
    std::cout << lokal("cleanup", lang) << "\n";
    system("del mingw.zip");
    
    std::cout << lokal("install_done", lang) << "\n";
}

bool fixPath(int lang) {
    std::cout << lokal("path_fixing", lang) << "\n";
    
    std::string mevcutPath;
    char* pathDegiskeni = getenv("PATH");
    if (pathDegiskeni) {
        mevcutPath = pathDegiskeni;
    }
    
    if (mevcutPath.find("mingw64\\bin") == std::string::npos) {
        system("setx PATH \"%PATH%;C:\\mingw64\\bin\" /M");
        std::cout << lokal("path_updated", lang) << "\n";
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

bool compileFile(const std::string& girisDosya, const std::string& ciktiDosya, int lang) {
    std::string komut = "g++ \"" + girisDosya + "\" -o \"" + ciktiDosya + "\" -static-libgcc -static-libstdc++";
    
    std::cout << lokal("compile_command", lang) << komut << "\n";
    int sonuc = system(komut.c_str());
    
    return sonuc == 0;
}

int main(int argc, char* argv[]) {
    // Konsol için UTF-8 desteği gerekliydi...
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    setlocale(LC_ALL, "Turkish");
    
    std::cout << "=============================================\n";
    std::cout << "     Universal C++ Compiler\n";
    std::cout << "=============================================\n\n";
    
    std::cout << "Select language:\n";
    std::cout << "1 English\n";
    std::cout << "2 Turkish\n";
    std::cout << "3 Japanese\n";
    std::cout << "Choice: ";
    
    int secim = 2;
    if (!(std::cin >> secim) || secim < 1 || secim > 3) {
        secim = 2;
    }
    
    int lang = TR;
    if (secim == 1) lang = EN;
    else if (secim == 3) lang = JP;
    else lang = TR;
    

    std::cout << "\n" << lokal("banner_line", lang) << "\n";
    std::cout << lokal("title", lang) << "\n";
    std::cout << lokal("banner_line", lang) << "\n\n";
    
    if (argc < 2) {
        std::cout << lokal("usage", lang) << argv[0] << " <dosya.cpp>\n";
        std::cout << lokal("drag_drop", lang) << "\n\n";
        system("pause");
        return 1;
    }
    
    std::string inputFile = argv[1];
    
    if (_access(inputFile.c_str(), 0) != 0) {
        std::cout << lokal("file_not_found", lang) << inputFile << "\n";
        system("pause");
        return 1;
    }
    
    std::string ext = getFileExtension(inputFile);
    if (ext != ".cpp" && ext != ".c" && ext != ".cxx" && ext != ".cc") {
        std::cout << lokal("unsupported", lang) << "\n";
        std::cout << "File: " << inputFile << "\n";
        system("pause");
        return 1;
    }
    
    std::string outputFile = inputFile.substr(0, inputFile.find_last_of(".")) + ".exe";
    std::string inputName = getFileName(inputFile);
    std::string outputName = getFileName(outputFile);
    std::string dir = getFileDir(inputFile);
    
    std::cout << lokal("file_label", lang) << inputName << "\n";
    std::cout << lokal("output_label", lang) << outputName << "\n";
    std::cout << lokal("dir_label", lang) << dir << "\n\n";
    
    if (!checkGCC()) {
        installGCC(lang);
        if (!checkGCC()) {
            std::cout << lokal("gcc_missing", lang) << " " << "Manual installation required." << "\n";
            system("pause");
            return 1;
        }
    }
    
    std::cout << lokal("compile_start", lang) << "\n";

    if (!compileFile(inputFile, outputFile, lang)) {
        std::cout << "\n" << lokal("compile_error", lang) << "\n";

        if (!fixPath(lang)) {
            std::cout << lokal("path_fixed_prompt", lang) << "\n";
        } else {
            std::cout << lokal("check_code", lang) << "\n";
            std::cout << lokal("syntax", lang) << "\n";
            std::cout << lokal("libs", lang) << "\n";
            std::cout << lokal("wrong_path", lang) << "\n";//kesin hatayı nasıl göreceğimizi bulamadım :(
        }

        system("pause");
        return 1;
    }
    
    std::cout << "\n" << lokal("success_prefix", lang) << outputName << lokal("success_suffix", lang) << "\n";
    
    if (_access(outputFile.c_str(), 0) == 0) {
        long size = getFileSize(outputFile);
        std::cout << lokal("size", lang) << size << " byte\n";
        std::cout << lokal("location", lang) << outputFile << "\n";
    }
    
    std::cout << "\n" << lokal("press_key", lang) << "\n";
    system("pause >nul");
    
    return 0;
}