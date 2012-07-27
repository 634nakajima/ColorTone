//YMZ294
//D0-D7 = 0-7pin
int WR = 16;//25
int CS = 15;//24
int Ao = 14;//23
int RESET = 18;//27

//LED
int R = 9;//15
int G = 10;//16
int B = 11;//17

//ColorSensor
int DOUT = 17;//26
int RANGE = 13;//19
int CK = 12;//18
int GATE = 8;//14

unsigned int rgb[3];

void updateLED() {
    analogWrite(R, rgb[0]);
    analogWrite(G, rgb[1]);
    analogWrite(B, rgb[2]);
}

void updateSound() {
    set_vol_chA(rgb[0]>>4);
    set_vol_chB(rgb[1]>>4);
    set_vol_chC(rgb[2]>>4);   
}

void setup(){
    //init pins
    for(int i=0; i < 8;i++){
      pinMode(i, OUTPUT);
    }
    
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
    
    //Serial.begin(9600);
    setupYMZ();

}

void loop(){
  
    getColor(10);
    updateLED();
    updateSound();
}
