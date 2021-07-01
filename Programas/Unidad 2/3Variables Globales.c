#include <stdio.h>
int eCuenta;

void func1();     //prototipos de
void func2();     //funciones

int main(){
    eCuenta = 100;
    func1();
    
    getchar();
    return 0;
}

void func1(){
     int eTemp;
     eTemp = eCuenta;
     func2();
     printf("Cuenta = %d", eCuenta);    //Imprime 100
}

void func2(){
     int eCuenta;
     
     for(eCuenta = 1; eCuenta < 10; eCuenta ++){
                 putchar('*');
     }
}
