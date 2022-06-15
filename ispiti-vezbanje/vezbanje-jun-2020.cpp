// Napisati na jeziku C++ sledeće klase :
// (klase opremiti onim konstruktorima, destruktorom, set i get metodama i operatorima
// dodele koji su potrebni za bezbedno i efikasno korišćenje klasa):
// 1.	
//     (30 poena) Klasa Ponuđeni odgovor se sastoji od teksta odgovora(string), 
//     koji se zadaje pri stvaranju (podrazumevano ""), informacije da li je tačan i procentualnog
//     udela poena koji taj odgovor nosi (u opsegu od -100 do 100).
//     Svi podaci su privatni. Svi podaci se mogu dohvatiti, a informacija o tačnosti i procentualni udeo se 
//     mogu postavljati(prilikom postavljanja proveriti da li su uneti ispravni procenti).
//     Odgovor može da se ispiše na glavnom izlazu (out<<odgovor) u obliku tekst: udeo%.

// 2.	(30 poena)
//     Klasa Pitanje sadrži zadate podatke koji su zaštićeni: 
//     tekst, broj poena koji nosi, broj ponuđenih odgovora (podrazumevano 5),
//     kao i ponuđene odgovore(dinamičko alocirani niz odgovora). 
//     Stvara se bez ponuđenih odgovora, nakon čega se oni dodaju pojedinačno (pitanje+=odgovor).
//     Prilikom dodavanja ponuđenog odgovora računaju se jednaki procentualni udeli svih tačnih odgovora dodatih 
//     u dato pitanje(u zbiru daju 100%), dok svaki netačan odgovor nosi -100%.
//     Pomoću polimorfne metode može da se odgovori na pitanje, tada se zadaje niz koji 
//     sadrži redne brojeve ponuđenih odgovora koje ispitanik smatra tačnim i dužina tog 
//     niza(odgovori(int niz[],int br);). 
//     Tada se računa koliko je procentualno tačno odgovoreno na to pitanje. 
//     Na glavnom izlazu se ispisuje (out<<pitanje) tako što se u prvom redu ispiše tekst: poeni(maksimalni koje pitanje nosi), 
//     a potom se u zasebnim redovima ispišu sadržani ponuđeni odgovori.

// 3.	
//     (30 poena) Klasa Student nasleđuje klasu Pitanje i dodaje privatne podatke: broj indeksa(int), 
//     ime studenta (string) i broj osvojenih poena (double).
//     Mogu da se dohvate svi podaci. Preklopiti metodu odgovori(int niz[].int br) 
//     tako da nakon što izračuna procenat tačnosti na odgovoreno pitanje izračuna broj osvojenih poena na tom pitanju i 
//     taj broj doda na broj osvojenih poena. Na glavnom izlazu se ispisuje (out<<student) tako što se u prvom redu ispiše broj indeksa,
//     ime i broj osvojenih poena studenta,
//     u drugom redu se ispiše tekst: poeni(maksimalni koje pitanje nosi),
//     a potom se u zasebnim redovima ispišu sadržani ponuđeni odgovori.

// (10 poena) Napisati main funkciju u kojoj ćete kreirati 7 odgovora,
//     2 pitanja i 1 studenta. U prvom pitanju dodati 4 odgovora(3 tačnih i 1 netačno), 
//     a u drugom pitanju 6(4 tačnih i 2 netačnih). 
//     Student neka bude isti kao drugo pitanje uz dodato ime, 
//     broj indeksa i broj osvojenih poena.
//     Za podatke o odgovorima, pitanjima i studentu uneti  koristiti fiksne parameter 
//     (nije potrebno unositi vrednosti sa standardnog ulaza).


#include<iostream>
#include <ostream>
#include <string>

using namespace std;

class PonudjeniOdgovor{
    private:
    string odgovor;
    int procentualniUdeo;
    bool daLiJeTacan;
    public:
    PonudjeniOdgovor(string odgovor, int procentualniUdeo, bool daLiJeTacan){
        if(procentualniUdeo >= -100 && procentualniUdeo <= 100){
            this->odgovor = odgovor;
            this->procentualniUdeo = procentualniUdeo;
        }
        else{
            cout<<"Uneli ste netacan procentualni udeo: "<<endl;
            cout<<"Unesite ponovo"<<endl;
            int temp;
            cin>>temp;
            setProcentualniUdeo(temp);
        }
        this->daLiJeTacan = daLiJeTacan;    
    }
    PonudjeniOdgovor(){
        odgovor = "";
        procentualniUdeo = 0;
        daLiJeTacan = false;
    }
   void setDaLiJeTacan(bool daLiJeTacan){
        this->daLiJeTacan = daLiJeTacan;
    }
    void setProcentualniUdeo(int procentualniUdeo){
         if(procentualniUdeo >= -100 && procentualniUdeo <= 100){
            this->procentualniUdeo = procentualniUdeo;
         }
        else{
            cout<<"Uneli ste netacan procentualni udeo: "<<endl;
            cout<<"Unesite ponovo"<<endl;
            int temp;
            cin>>temp;
            setProcentualniUdeo(temp);
        }
    }
      bool getDaLiJeTacan(){
       return daLiJeTacan; 
    } 
        
    int getProcentualniUdeo(){
       return procentualniUdeo ;
    }
    string getOdgovor(){
        return odgovor;
    }
   friend ostream& operator<<(ostream& out,PonudjeniOdgovor &p1){
        // out<<"Odgovor:"<<p1.odgovor<<endl;
        // out<<"Procentualni udeo:"<<p1.procentualniUdeo<<endl;
        out<<"Tekst:"<<p1.odgovor<<"udeo:"<<p1.procentualniUdeo<<"%"<<endl;
        if(p1.daLiJeTacan){
            out<<"Odgovor je tacan"<<endl;
        }
        else{
            out<<"Odgovor nije tacan"<<endl;
        }
    } 
};
//Klasa Pitanje sadrži zadate podatke koji su zaštićeni: 
//     tekst, broj poena koji nosi, broj ponuđenih odgovora (podrazumevano 5),
//     kao i ponuđene odgovore(dinamičko alocirani niz odgovora). 
//     Stvara se bez ponuđenih odgovora, nakon čega se oni dodaju pojedinačno (pitanje+=odgovor).
//     Prilikom dodavanja ponuđenog odgovora računaju se jednaki procentualni udeli svih tačnih odgovora dodatih 
//     u dato pitanje(u zbiru daju 100%), dok svaki netačan odgovor nosi -100%.
//     Pomoću polimorfne metode može da se odgovori na pitanje, tada se zadaje niz koji 
//     sadrži redne brojeve ponuđenih odgovora koje ispitanik smatra tačnim i dužina tog 
//     niza(odgovori(int niz[],int br);). 
//     Tada se računa koliko je procentualno tačno odgovoreno na to pitanje. 
//     Na glavnom izlazu se ispisuje (out<<pitanje) tako što se u prvom redu ispiše tekst: poeni(maksimalni koje pitanje nosi), 
//     a potom se u zasebnim redovima ispišu sadržani ponuđeni odgovori.


class Pitanje{
    protected:
    string tekst;
    int brojPoena;
    int brojPonudjenihOdgovora;
    int trenutni_broj_odgovora;
    PonudjeniOdgovor *ponudjeniOdgovori;
    public:
    Pitanje(string tekst, int brojPonudjenihOdgovora, int brojPoena){
        this->tekst = tekst;
        this->brojPonudjenihOdgovora = brojPonudjenihOdgovora;
        this->brojPoena = brojPoena;
    }
    Pitanje(){
        brojPonudjenihOdgovora = 5;
        trenutni_broj_odgovora = 0;
    }
    Pitanje operator+=(PonudjeniOdgovor &p1){
        PonudjeniOdgovor *temp = new PonudjeniOdgovor[trenutni_broj_odgovora];
        for(int i=0; i<trenutni_broj_odgovora; i++){
            temp[i] = ponudjeniOdgovori[i];
        }
        trenutni_broj_odgovora++;
        ponudjeniOdgovori = new PonudjeniOdgovor[trenutni_broj_odgovora];
        for(int i = 0; i < trenutni_broj_odgovora - 1; i++){
            ponudjeniOdgovori[i] = temp[i];
        }
        ponudjeniOdgovori[trenutni_broj_odgovora - 1] = p1;
    }

};





int main(){

    return 0;
}

