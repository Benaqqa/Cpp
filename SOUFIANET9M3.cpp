#include <iostream>
using namespace std;

typedef struct {  //Exemple d'une class en analogie avec C
    int mass;
    int speed;
    char* name;
} ClassExp;


int main(){
    //Exp d'un constructeur de class
    ClassExp* Car = (ClassExp *)malloc(sizeof(ClassExp));
    return 0;
}