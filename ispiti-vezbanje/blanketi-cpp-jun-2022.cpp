/*Задатак 1. (24 поена) потребно је направити софтвер за вођење евиденције о једном кругу такмичења талената.
За сваког учесника се памти редни број, име презиме и поени публике. Учесник може бити глумац или певач Глумца карактерише
број потребних реквизита, број поена жирија за идеју и број поена жирија за извођење за певача се води евиденција о 
песми коју пева, броју пратећих инструмената, броју пратећих вокала и поенима музичког жирија Учесник пролази у наредни круг
такмичења уколико има минимум 50% поена оцењивана жирија и ако у укупном броју поена има више од 100 поена. Музички жири 
додељује после од 0 до 100, док жири за идеју и жири за извођење додељује поене од 0 до 50. Поени публике су у опсегу од 0 до 100.
Укупан број поена за глумце се рачуна као сума гласова публике, поена жирија за идеју и поена жирија за извођење, док се укупан 
број поена за певаче рачуна као збир гласова публике и поена музичког жирија: спречити креирање такмичара да невалидним бројем poena


Омогућити додавање новог и брисаnje постојећег учесника на основу учесниковог редног броја Могуће је одредити средњу вредност
укупног броја поена учесника који су се пласирали у следећи круг и учесника који је освоји највећи број поена жирија. 
Могуће је приказати евиденцију учесника уписом свих података у фајл Омогућити сортираье учесника у опадајући редослед по броју
помоћног особља за извођење наступа. Број помоћног особља за глумца се рачуна као 1% броја реквизита, док се број помоћног 
особља за певача рачуна као збир пратећих инструмената и пратећих вокала

*/

#include <cmath>
#include <cstdio>
#include <cxxabi.h>
#include <exception>
#include<iostream>
#include <iterator>
#include <list>
#include <stdexcept>
#include<string>
#include <type_traits>
#include<stdlib.h>
#include <typeinfo>
#include <utility>

using namespace std;

class Ucesnik{
    protected:
    int redniBroj;
    string imeIPrezime;
    int poeniPublike;
    int ukupanBrPoena;
   
    public:
    Ucesnik (){}
    Ucesnik(int redniBroj, string imeIPrezime, int poeniPublike){
        this->redniBroj = redniBroj;
        this->imeIPrezime = imeIPrezime;
        this->poeniPublike = poeniPublike;
        if(poeniPublike >= 0 && poeniPublike <= 100){
            this->poeniPublike = poeniPublike;
        }
        else{
            cout<<"Uneli ste pogresan br poena publike"<<endl;
        }
    }
    string get_ime_i_prezime(){
        return imeIPrezime;
    }
    int getRedniBr(){
        return redniBroj;
    }
    virtual bool daLiJeProsao(){
        ukupanBrPoena = poeniPublike;
        if(ukupanBrPoena > 100){
            cout<<"Ucesnik je polozio"<<endl;
            return true;
        }
        return false;
         cout<<"Ucesnik nije polozio"<<endl;

    }
    int getUkupanBrPoena(){
        ukupanBrPoena = poeniPublike;
        return ukupanBrPoena;
    }
    
    

};

class Glumac : public Ucesnik{
    protected:
    int brojPotrebnihRekvizita;
    int brojPoenaZirijaZaIdeju;
    int brojPoenaZirijaZaIzvodjenje;
    int trenutni_broj_glumaca;
    Ucesnik *ucesnik;
    public:
    Glumac(){
        trenutni_broj_glumaca = 0;
    }
    Glumac(int redniBroj, string imeIPrezime, int poeniPublike,int brojPotrebnihRekvizita, int brojPoenaZirijaZaIzvodjenje,int brojPoenaZirijaZaIdeju): Ucesnik(redniBroj,imeIPrezime,poeniPublike){
        this->brojPotrebnihRekvizita =  brojPotrebnihRekvizita;
        if(brojPoenaZirijaZaIdeju >= 0 && brojPoenaZirijaZaIdeju <= 50){
                this->brojPoenaZirijaZaIdeju = brojPoenaZirijaZaIdeju;
            }
        else if(brojPoenaZirijaZaIdeju > 50){
            cout<<"Uneli ste pogresan br poena za zirija za ideju "<<endl;
        }
        if(brojPoenaZirijaZaIzvodjenje >= 0 && brojPoenaZirijaZaIzvodjenje <= 50){
            this->brojPoenaZirijaZaIzvodjenje = brojPoenaZirijaZaIzvodjenje;
    }
        else if(brojPoenaZirijaZaIzvodjenje > 50){
            cout<<"Uneli ste pogresan br poena za zirija za izvodjenje "<<endl;
        }
        if(poeniPublike >= 0 && poeniPublike <= 100){
            this->poeniPublike = poeniPublike;
        }
        else{ 
            cout<<"Uneli ste pogresan br poena publike"<<endl;
        }
        trenutni_broj_glumaca = 0;
    }
    Glumac operator+=(Ucesnik &u1){
        Ucesnik *pomocni = new Ucesnik[trenutni_broj_glumaca];
        for(int i = 0;i < trenutni_broj_glumaca;i++){
            pomocni[i] = ucesnik[i];
        }
        trenutni_broj_glumaca++;
        ucesnik = new Ucesnik[trenutni_broj_glumaca];
        for(int i = 0;i < trenutni_broj_glumaca-1;i++){
            ucesnik[i] = pomocni[i];
        }
        ucesnik[trenutni_broj_glumaca-1] = u1;
        return *this;
    }

    //Za izbacivanje ucesnika

    //Kreira se pomocni niz za -1 gde ako smo dodali 3 objekta u pomocni staju 2
    //Stavimo brojac za pomocni na 0
    //Prekopiramo jedan po jedan element u pomocni br++ gde ce se prekopirati 2 obj
    //Zatim u taj niz stvaimo ta 2 obj iz pomocnog
    //Smanjimo duzinu niza -- ako je bila 3 sada je 2 da bi u sledecoj interaciji moli da smanjimo vise objekata


    Glumac operator-=(int rednibr){
        Ucesnik *pomocni = new Ucesnik[trenutni_broj_glumaca-1];
        int brojac = 0;
        for(int i=0; i<trenutni_broj_glumaca; i++){
            if(rednibr != ucesnik[i].getRedniBr()){
                pomocni[brojac] = ucesnik[i];
                brojac++;
            }
            
        }
        ucesnik = pomocni;
        trenutni_broj_glumaca--;
        return *this;

    }
    int srednjaVrednost(){
        int maks = 0;
        int s = 0;
        for(int i=0; i<trenutni_broj_glumaca; i++){
            if(ucesnik[i].daLiJeProsao()){
                s += ucesnik[i].getUkupanBrPoena();
            }
        }
        return s / trenutni_broj_glumaca;
    }
    void sortiraniUcesnici(){
        for(int i=0; i<trenutni_broj_glumaca-1;i++){
            for(int j=0; j<trenutni_broj_glumaca-i-1; j++){
                if(ucesnik[j].getUkupanBrPoena() > ucesnik[j+1].getUkupanBrPoena()){
                    // // swap ucenik[j] and ucenik[j+1]  using xor
                    Ucesnik temp = ucesnik[j];
                    ucesnik[j] = ucesnik[j+1];
                    ucesnik[j+1] = temp;
                }
            }
        }
    }




    bool daLiJeProsao(){
        int procenat = 50;
        int brojPoenaZirija = brojPoenaZirijaZaIdeju + brojPoenaZirijaZaIzvodjenje;
        int minPolozio = brojPoenaZirija * procenat / 100;
        ukupanBrPoena = brojPoenaZirijaZaIdeju + brojPoenaZirijaZaIzvodjenje + poeniPublike;
        if(brojPoenaZirija > minPolozio && ukupanBrPoena > 100){
            cout<<"Glumac je prosao"<<endl;
            return true;
        }
        cout<<"Glumac nije prosao"<<endl;
        return false;
    }
   friend ostream& operator<<(ostream& out,Glumac &g1){
    for(int i=0;i<g1.trenutni_broj_glumaca; i++){
        out<<"Glumac je :"<<g1.ucesnik[i].get_ime_i_prezime()<<endl;
    }
    return out;

    
   }

};
// Омогућити додавање новог и брисаnje постојећег учесника на основу учесниковог редног броја Могуће је одредити средњу вредност
// укупног броја поена учесника који су се пласирали у следећи круг и учесника који је освоји највећи број поена жирија. 
// Могуће је приказати евиденцију учесника уписом свих података у фајл Омогућити сортираье учесника у опадајући редослед по броју
// помоћног особља за извођење наступа. Број помоћног особља за глумца се рачуна као 1% броја реквизита, док се број помоћног 
// особља за певача рачуна као збир пратећих инструмената и пратећих вокала



class Pevac : public Ucesnik{
    protected:
    string Pesma;
    int brojInstrumenata;
    int brojVokala;
    int brojPoenaMuzickogZirija;
    int trenutni_broj_pevaca;
    Ucesnik *ucesnik;
    public:
    Pevac(int redniBroj, string imeIPrezime, int poeniPublike,string Pesma, int brojInstrumenata, int brojVokala,int brojPoenaMuzickogZirija):Ucesnik( redniBroj,imeIPrezime,poeniPublike){
        this->Pesma = Pesma;    
        this->brojInstrumenata = brojInstrumenata;
        this->brojVokala = brojVokala;
        if(brojPoenaMuzickogZirija >= 0 && brojPoenaMuzickogZirija <= 100){
            this->brojPoenaMuzickogZirija = brojPoenaMuzickogZirija;
        }
        else{
            cout<<"Uneli ste pogresan br poena muzickog zirija"<<endl;
        }
        if(poeniPublike >= 0 && poeniPublike <= 100){
            this->poeniPublike = poeniPublike;
        }
        else{
            cout<<"Uneli ste pogresan br poena publike"<<endl;
        }
        trenutni_broj_pevaca = 0;

    }
    Pevac operator+=(Ucesnik &u1){
        Ucesnik *pomocni = new Ucesnik[trenutni_broj_pevaca];
        for(int i = 0;i < trenutni_broj_pevaca;i++){
            pomocni[i] = ucesnik[i];
        }
        trenutni_broj_pevaca++;
        Ucesnik *ucesnik = new Ucesnik[trenutni_broj_pevaca];
        for(int i = 0;i < trenutni_broj_pevaca-1;i++){
            ucesnik[i] = pomocni[i];
        }
       ucesnik[trenutni_broj_pevaca-1] = u1;
        return *this;
    }
    bool daLiJeProsao(){
        int procenat = 50;
        int brojPoenaZirija = brojPoenaMuzickogZirija;
        int minPolozio = brojPoenaZirija * procenat / 100;
        ukupanBrPoena = brojPoenaMuzickogZirija + poeniPublike;
        if(brojPoenaZirija > minPolozio && ukupanBrPoena > 100){
            cout<<"Glumac je prosao"<<endl;
            return true;
        }
        cout<<"Glumac nije prosao"<<endl;
        return false;
    }

};

int main(){
    Glumac g1;                       //trenutni broj glumaca = 0
    Ucesnik u1(2,"Vin Diesel",50);
    Ucesnik u2(3,"Dzeki Cen",70);   //#2   ime i prezime = Vin Diesel , poeni publike = 40
    Ucesnik u3(2,"Kit Harington",60);
    g1+=u1;
    g1+=u2;
    g1+=u3;
    g1.sortiraniUcesnici();
    cout<<g1;

    return 0;
}