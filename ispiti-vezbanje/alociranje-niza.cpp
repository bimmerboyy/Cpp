#include<iostream>
#include<stdlib.h>

using namespace std;


class Niz{
    private:
    int duzinaNiza;
    int *niz;
    public:
    Niz(){

    }
    Niz(int duzinaNiza = 5){
        niz = new int[ duzinaNiza];
        for(int i = 0; i < duzinaNiza;i++){
            niz[i] = 0;
        }
        this->duzinaNiza = duzinaNiza;
    }

    void unosNiza(){
        niz = new int[duzinaNiza];
        cout<<"Unesite elemente niza:";
        for(int i = 0; i < duzinaNiza;i++){
            cin >> niz[i];
        }
    }
    void dodajElement(int index,int element){
        niz[index] = element;
    }
    int getElement(int index){
        return niz[index];
    }
    void operator()(int index,int element){
        niz[index] = element;

    }
    int &operator () (int index){

        return niz[index];

    }
    // Niz(const Niz &n1){
       
    //     duzinaNiza = n1.duzinaNiza;
         
    //     cout<<"Duzina drugog je"<<n1.duzinaNiza<<endl;
    //     for(int i = 0;i < duzinaNiza;i++){
    //         niz[i] = n1.niz[i];
    //     }
    // }

    Niz operator = (Niz &n1){

        if(this == &n1){
            return *this;
        }
        else{
            delete [] niz;
        }
        int *temp;
        duzinaNiza = 0;
        temp = new int[duzinaNiza];
        for(int i = 0; i < duzinaNiza; i++){
            temp[i] = n1.niz[i];
        }
       // *temp = *n1.niz;

        return *this;
    }
   
    friend ostream&  operator<<(ostream& COUT,Niz n1){
        COUT<<"Niz je:"<<endl;
        for(int i = 0; i < n1.duzinaNiza; i++){
            COUT<<n1.niz[i]<<" ";
        }
        COUT<<endl;
        return COUT;

    }
    void ispis() {
        for(int i = 0;i < duzinaNiza;i++){
            cout<<niz[i];
        }
    }
    //  ~Niz(){
    //     delete []niz;
    //     niz = nullptr;
    //     cout<<"Obrisao sam niz pomocu destrutor"<<endl;
    // }
};

int main(){
    Niz n1(3);
    Niz n2(3);
    n1.dodajElement(0, 1);
    n1.dodajElement(1, 2);
    n1.dodajElement(2, 3);
    n2 = n1;
    cout<<n2(1);   
   

 
    //cout <<n1;
    return 0;

}