/*
relaizovati klasu Racun koja ima privatne atribute:
operandi,operandi2 i operacija
metode: konstruktor bez argumenata koji postavlja  da je raccun 1+1
izracunaj() koja vraca vredbnost racuna (npr za 1+1 vratila bi 2)
U glavnom programu naprvaiti jedan objekat klase racun i izracunati izraz
    2 * 5
*/
#include<iostream>
using namespace std;

class Racun{
    private:
    int operandi1,operandi2;
    char operacija;
    public:
    Racun(){
        operandi1 = 1;
        operandi2 = 1;
        operacija = 
    }
    float Izracunaj(){
        switch(operacija){
            case "+" return operand1 + operand2;
            case "-" return operand1 - operand2;
             case "*" return operand1 * operand2;
              case "/" return operand1 / operand2;
        }
    }
    void setOp1(int a){ operandi1 = a; }
     void setOp2(int a){ operandi2 = a; }
      void setOp(){ operacija = c; }
      int getOp1(){return operandi1;}
      int getOp2(){return operandi2;}
      int getOp(){return operacija;}
};
int main(){
    Racun r;
    r.setOp1(2);
    r.setOp2(5);
    
}