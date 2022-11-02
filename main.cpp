#include "LCD.h"
#include "mbed.h"
#include <cstdio>
#include "string"
#include "TextLCD.h"

DigitalOut myled(LED1);
AnalogIn datain(A0);
Thread thread1;
Thread thread2;
int data=0;
char Ans;

void generate_morsecode(){

    //A F K = “.- ..-. -.-” 11331111311331113
    //A
    ThisThread::sleep_for(1000ms);
    myled = 1;
    ThisThread::sleep_for(1000ms);
    myled = 0;
    ThisThread::sleep_for(1000ms);
    myled = 1;
    ThisThread::sleep_for(3000ms);
    //space
    myled = 0;
    ThisThread::sleep_for(3000ms);

    // //F
    // myled = 1;
    // ThisThread::sleep_for(1000ms);
    // myled = 0;
    // ThisThread::sleep_for(1000ms);
    // myled = 1;
    // ThisThread::sleep_for(1000ms);
    // myled = 0;
    // ThisThread::sleep_for(1000ms);
    // myled = 1;
    // ThisThread::sleep_for(3000ms);
    // myled = 0;
    // ThisThread::sleep_for(1000ms);
    // myled = 1;
    // ThisThread::sleep_for(1000ms);
    // //space
    // myled = 0;
    // ThisThread::sleep_for(3000ms);
    // //K
    // myled = 1;
    // ThisThread::sleep_for(3000ms);
    // myled = 0;
    // ThisThread::sleep_for(1000ms);
    // myled = 1;
    // ThisThread::sleep_for(1000ms);
    // myled = 0;
    // ThisThread::sleep_for(1000ms);
    // myled = 1;
    // ThisThread::sleep_for(3000ms);
    // myled = 0;
}
void scan(){
    ThisThread::sleep_for(500ms);
    for(int i=0;i<10;i++){

        ThisThread::sleep_for(1000ms);
        if(datain.read()<0.5){
            data=(data*10)+1;
        }
        else{
            data=(data*10)+0;
        }
        printf("%f\n",datain.read());
        printf("%d\n",data);
    }
    if(data==1011100000){
        Ans='a';
        printf("%c\n",Ans);
        
    }
        if(Ans=='a'){
        LCD_init();
        display_to_LCD(0x61);
        printf("%c\n",Ans);
    }

}
int main()
{
   // check that myled object is initialized and connected to a pin
   if (myled.is_connected()) {
      printf("myled is initialized and connected!\n\r");
   }
    thread1.start(generate_morsecode);
    thread2.start(scan);

    
    


}