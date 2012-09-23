//YMZ294
int D0 = 0;
int D1 = 1;
int D2 = 2;
int D3 = 3;
int D4 = 4;
int D5 = 6;
int D6 = 7;
int D7 = 8;

int WR = 14;//23
int CS = 15;//24
int Ao = 16;//25
int RESET = 17;//26

//LED
int R = 9;//15
int G = 11;//17
int B = 10;//16

//ColorSensor
int DOUT = 19;//28
int RANGE = 13;//19
int CK = 12;//18
int GATE = 18;//27

unsigned int rgb[3];
unsigned int i=0;
int f;

void updateLED() {
    analogWrite(R, rgb[0]/16);
    analogWrite(G, rgb[1]/16);
    analogWrite(B, rgb[2]/16);
}

void updateSound() {

    f = rgb[2]/64 - (rgb[0]+rgb[1])/128;
    if(f < 2) f = 2;
    if(f>15) f = 15;
    set_vol_chA((unsigned int)f);
    set_noise(0x08);
}

void setup(){
    //init pins
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    pinMode(D4, OUTPUT);
    pinMode(D5, OUTPUT);
    pinMode(D6, OUTPUT);
    pinMode(D7, OUTPUT);
    
    pinMode(WR, OUTPUT);
    pinMode(CS, OUTPUT);
    pinMode(Ao, OUTPUT);
  
    pinMode(R, OUTPUT);
    pinMode(G, OUTPUT);
    pinMode(B, OUTPUT);

    pinMode(DOUT, INPUT);
    pinMode(RANGE, OUTPUT);
    pinMode(CK, OUTPUT);
    pinMode(GATE, OUTPUT);
    
    setupYMZ();
}

void loop(){
    /*set_vol_chA(0x0f);
    set_noise(i);
    delay(200);
    i++;
    if(i==32)
      i=0;*/
    getColor(100);
    updateLED();
    updateSound();
  
}
