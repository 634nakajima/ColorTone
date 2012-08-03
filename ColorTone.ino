//YMZ294
int D0 = 0;
int D1 = 1;
int D2 = 2;
int D3 = 3;
int D4 = 4;
int D5 = 6;
int D6 = 7;
int D7 = 8;

int WR = 16;//25
int CS = 15;//24
int Ao = 14;//23
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

void updateLED() {
    analogWrite(R, rgb[0]);
    analogWrite(G, rgb[1]);
    analogWrite(B, rgb[2]);
}

void updateSound() {
    set_vol_chA(rgb[0]>>4);
    //set_vol_chB(rgb[1]>>4);
    //set_vol_chC(rgb[2]>>4);   
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
  
    getColor(10);
    updateLED();
    updateSound();
}
