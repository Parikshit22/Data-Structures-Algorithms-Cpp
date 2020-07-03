#include <iostream>
#include <cstring>
using namespace std;
class CAR{
public:
    char *model_no;
    int price;
    char *name;
    const int tyres;
    CAR():tyres(4){};
    CAR(char *m,int p,char *n):tyres(4){
    int ln = strlen(n);
    int lm = strlen(m);
    model_no = new char[lm+1];
    strcpy(model_no,m);
    price = p;
    name = new char[ln+1];
    strcpy(name,n);
    }
    /*
    CAR(CAR &X){
        price = X.price;
        int lm = strlen(X.model_no);
        model_no = new char[lm+1];
        strcpy(model_no,X.model_no);
        int ln = strlen(X.name);
        name = new char[ln+1];
        strcpy(name,X.name);
    }*/

    void SetModelNo(char *m){
        int lm = strlen(m);
        model_no = new char[lm+1];
        strcpy(model_no,m);
    }
    void SetPrice(int p){
        price = p;
    }
    void MyCars(){
    cout<<"Welcome Parikshit, you have "<<name<<" Model no. "<< model_no<<" Of Price Rs "<<price<<" with tyres "<<tyres<<endl;}
    //Destructor
    ~CAR(){
        cout<<"To Free the Space of "<<name<<endl;
        if(name!=NULL){
                delete[] name;
                delete[] model_no;
        }


    }
};
int main()
{
    CAR cars[3] = {CAR("A8",25000000,"AUDI\0"),CAR("RangeRoverEvoque\0",5300000,"LAND ROVER\0"),
                   CAR("X6",9500000,"BMW\0")};
    CAR *B = new CAR("Ghibli",15000000,"Maserati");

    for(int i=0;i<3;i++){
        cars[i].MyCars();
    }
    (*B).MyCars();
    CAR A(cars[0]);
    A.SetModelNo("Q7");
    A.SetPrice(9215655);
    A.MyCars();

    return 0;
}
