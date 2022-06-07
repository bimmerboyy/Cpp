/*Универзитет у Нишу

Електронски факултет у Нишу

Катедра за рачунарств

Објектно оријентисано програмирање

Априлски испитни рок

31.03.2022

Опште напомене за гораду задатака

• Атрибути не смеју бити јаvni

• креирати свe norpetine januе методе које ће обезбедити да програм рад Туучу и конструкторе и деструктор).

. Избегавати дуплиране (но one) кода

• Придржавата се основих принципа обектно ориено со прогр (енкапсулација, модуларност, наслеђе полиморфизам)

Задатак 1. (24 бодова) Асистент води евиденцију о броју бодова студената на излазе на испит 
и предмета Програмиране Студенти освају болон 10 лабораторијске вежбе писали и усмени део испита,
 при чему па део испита могу полагати у целину или путем два колоквиума. За све студе де памти се по индекса, 
 број бодова за лабораторијске ребе и број бодова на усменом испиту за Студенте који пола у писани испит
у целини памти се освојени број бодова на њему. док се за оне који пола у путем колоквијума памти број
бодова та сваки колок Укупан број бодов. се одређује као збир сик бодова које је студент со пр чему
је највећи број бодова на лабораторијским небама 20 капсу испиту 40 и на колоквијумима 20. Студент
који пола писани испит у це је положно испит ко је на писаном, усменом и целом испиту освојио од 50%
од максималног броја бодова. Студент који полаже писани испит прекоме положно испит ако је на усменом
и целом испиту освојио више од 50% од максималног броја бодова и на сваком од колоквијума освојио више од 25%,
а у збиру на оба колоквиума више од 50% од максималног броја бодова

У евиденцију је могуће додати новог студента и уклонити постојеће на основу задатог броја индекса
након преглед радова woryhe jе изменити број бодо студента на писаном делу испита и на било ком од 
колоквиума на основу задато броја индекса студента и броја додатих бодова. У сваком тренутку може
се направити списан студената са свием подацима о сваком од тих Евиденција омогућава лако одређивање (не приказ)
студента са највећим бројем бодова на писаном делу испита и студента санајвећим бројем бодова на целом испиту (једним
просом and ca cracyhe jе одредине работу та број студената испит

направите идеи и одит бар 6 студента (бар 2 спа от типа, обрати редное студента и noushame
број бодова 12 студеnt, a другом за 1. колок и тате и не осуден дрва и промен број бодову
д на већим бројем бодова написан и студента са норвег бр бодова на целом испиту број студената и се
полот и пребро водов дека он су положили испит

Задатак 2. 116 более) креира у истомогућава рад са обрестилка или могу сти Monte le sonian елементарна
постојећи (брице свако појави стол елемент у листи игнорисати овy Dtiony Пусть пари не дае ли сте и права
тако креирану кому е елемената са се потако што се на нумо клементи на една затим и друге листе се до to
oryhe lос листовала по броју елементаta), елементи дуже ле
Креирани класу листа от употреби и у обе расп трии Такмичар је описан целобројним идентификатором
стро регатом Приликом поређења такмичара, сматрати да је исти кол има дети идентификатор 1

Крехрану су и ориз с еленсе бро За демонстрацију употребе креираме класе Листа употребити целе бројеве, затим
4 класу Така направити по две инстант обе додати колико елемената (барем 4) табацити бар један сат
 спојити то дост рез прати елементе така писта по овити поступа Такмичар, при чему је потребно креирати барем приде


*/

#include<iostream>

using namespace std;

// Задатак 1. (24 бодова) Асистент води евиденцију о броју бодова студената на излазе на испит 
// и предмета Програмиране Студенти освају болон 10 лабораторијске вежбе писали и усмени део испита,
//  при чему па део испита могу полагати у целину или путем два колоквиума. За све студе де памти се по индекса, 
//  број бодова за лабораторијске ребе и број бодова на усменом испиту за Студенте који пола у писани испит
// у целини памти се освојени број бодова на њему. док се за оне који пола у путем колоквијума памти број
// бодова та сваки колок Укупан број бодов. се одређује као збир сик бодова које је студент со пр чему
// је највећи број бодова на лабораторијским небама 20 капсу испиту 40 и на колоквијумима 20. Студент
// који пола писани испит у це је положно испит ко је на писаном, усменом и целом испиту освојио од 50%
// од максималног броја бодова. Студент који полаже писани испит прекоме положно испит ако је на усменом
// и целом испиту освојио више од 50% од максималног броја бодова и на сваком од колоквијума освојио више од 25%,
// а у збиру на оба колоквиума више од 50% од максималног броја бодова

class Student{
    private:
    int brIndeksa;
    int brBodovazaLabvezbe;
    int brBodovanaUsmenom;
    int brBodovanaPismenom;
    int BrBodovanaKolokvijumu1;
    int BrBodovanaKolokvijumu2;
    public:
    Student(int brIndeksa,int brBodovazaLabvezbe,int brBodovanaUsmenom,int brBodovanaPismenom){
        this->brIndeksa = brIndeksa;
        
         if(brBodovazaLabvezbe <= 20){
            this->brBodovazaLabvezbe = brBodovazaLabvezbe;
            
        }
        else{
            cout<<"Uneli ste pogresan br bodova"<<endl;
            
        }
        if(brBodovanaPismenom + brBodovanaPismenom <= 40){
            this->brBodovanaPismenom = brBodovanaPismenom;
            this->brBodovanaUsmenom = brBodovanaUsmenom;
        }
        else{
            cout<<"Uneli ste pogresan br bodova"<<endl;
        }
       
    }
    int Kolokvijumi(int BrBodovanaKolokvijumu1,int BrBodovanaKolokvijumu2){
        this->BrBodovanaKolokvijumu1 = BrBodovanaKolokvijumu1;
        this->BrBodovanaKolokvijumu2 = BrBodovanaKolokvijumu2;
        return BrBodovanaKolokvijumu1 + BrBodovanaKolokvijumu2;
    }
    int ukupanBrBodova(){
        int ukupanBrBodova = 0;
        ukupanBrBodova = brBodovazaLabvezbe + brBodovanaPismenom + brBodovanaUsmenom + Kolokvijumi(BrBodovanaKolokvijumu1,BrBodovanaKolokvijumu2);
        return ukupanBrBodova;
    }
    bool daLiJePolozio(){
        int maxBrBodova = 80;
        int procenat = 50;
        int brPoenaStudenta = brBodovanaPismenom + brBodovanaPismenom;
        float brPoenaZaProlaz;
        //Polaganje preko pismenog i usmenog dela
        brPoenaZaProlaz = (float)maxBrBodova * procenat / 100;
        if(brPoenaStudenta >= brPoenaZaProlaz){
            cout<<"Student je polozio"<<endl;
            return true;
        }
        else{
             cout<<"Student nije polozio"<<endl;
             return false;
        }
        //POlaganje preko kolokvijuma
        if(Kolokvijumi(BrBodovanaKolokvijumu1,BrBodovanaKolokvijumu2)){
            if(Kolokvijumi(BrBodovanaKolokvijumu1,BrBodovanaKolokvijumu2) + brBodovanaUsmenom >= brPoenaZaProlaz){


            }
        }
        


    }
   

};

int main(){

    return 0;
}
