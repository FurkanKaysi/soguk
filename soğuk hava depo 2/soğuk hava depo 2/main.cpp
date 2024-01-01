#include <iostream>
#include <cmath>
using namespace std;

class Oda {
public:
    float uzunluk, genislik, yukseklik;
    float panelKalinlik;

    Oda(float u, float g, float y) : uzunluk(u), genislik(g), yukseklik(y) {}

    void hesaplaPanelSayisi(int& tavanPanelleri, int& zeminPanelleri, int& duvarPanelleri, bool uzunlukBazli) {
        float tavanPanelUzunluk, zeminPanelUzunluk;

        if (uzunlukBazli) {
            tavanPanelUzunluk = uzunluk - panelKalinlik;
            zeminPanelUzunluk = uzunluk - (2.0 * panelKalinlik);
        } else {
            tavanPanelUzunluk = genislik - panelKalinlik;
            zeminPanelUzunluk = genislik - (panelKalinlik * 2.0);
        }

        // Tavan ve zemin panel sayıları
        tavanPanelleri = static_cast<int>(round(tavanPanelUzunluk / 111.0)); // Tavan panellerinin adedi
        zeminPanelleri = static_cast<int>(round(zeminPanelUzunluk / 111.0)); // Zemin panellerinin adedi

        // Duvar panel sayısı hesaplanıyor
        float odaninCevresi = 2 * (uzunluk + genislik);
        duvarPanelleri = static_cast<int>(round(odaninCevresi / 111.0));
    }

    void panelBoyutlari(float& uzunluk, float& genislik, float& kalinlik) {
        uzunluk = this->uzunluk - panelKalinlik;
        genislik = 111.0;
        kalinlik = panelKalinlik;
    }
};

int main() {
    float uzunluk, genislik, yukseklik, panelKalinlik;
    bool uzunlukBazli;

    cout << "Oda uzunlugunu girin (cm): ";
    cin >> uzunluk;

    cout << "Oda genisligini girin (cm): ";
    cin >> genislik;

    cout << "Oda yuksekligini girin (cm): ";
    cin >> yukseklik;

    cout << "Panel kalınlığını seçin (8, 10 veya 12 cm): ";
    cin >> panelKalinlik;

    cout << "Tavan ve zemin panellerini odanın uzunluğuna mı (1) yoksa genişliğine mi (0) göre hesaplamak istiyorsunuz? ";
    cin >> uzunlukBazli;

    Oda oda(uzunluk, genislik, yukseklik);
    oda.panelKalinlik = panelKalinlik;

    int tavanPanelleri, zeminPanelleri, duvarPanelleri;
    oda.hesaplaPanelSayisi(tavanPanelleri, zeminPanelleri, duvarPanelleri, uzunlukBazli);

    cout << "Toplam " << tavanPanelleri << " adet tavan paneli gerekiyor. Boyutları: ";
    float tavanUzunluk, tavanGenislik, tavanKalinlik;
    oda.panelBoyutlari(tavanUzunluk, tavanGenislik, tavanKalinlik);
    cout << tavanPanelleri << " adet " << tavanUzunluk << "x" << tavanGenislik << "x" << tavanKalinlik << " (uzunluk x genislik x kalınlık)" << endl;

    cout << "Toplam " << zeminPanelleri << " adet zemin paneli gerekiyor. Boyutları: ";
    float zeminUzunluk, zeminGenislik, zeminKalinlik;
    oda.panelBoyutlari(zeminUzunluk, zeminGenislik, zeminKalinlik);
    cout << zeminPanelleri << " adet " << zeminUzunluk << "x" << zeminGenislik << "x" << zeminKalinlik << " (uzunluk x genislik x kalınlık)" << endl;

    cout << "Toplam " << duvarPanelleri << " adet duvar paneli gerekiyor." << endl;

    return 0;
}

