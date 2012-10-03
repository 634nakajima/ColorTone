//Color Sensor

void getColor(int tg){
    int i;
    
    digitalWrite(GATE ,LOW);
    digitalWrite(CK, LOW);
    delay(3);
    digitalWrite(RANGE, HIGH);
    digitalWrite(GATE, HIGH);
    delay(tg);
    digitalWrite(GATE, LOW);
    
    for (i=0;i<3;i++) {
        rgb[i] = 0;
        readDOUT(i);
    }
    
    delayMicroseconds(5);
    digitalWrite(GATE, HIGH);
    
    rgb[2] = rgb[2] * 0.60;
}

void readDOUT(int c) {
    int i;
    
    delayMicroseconds(5);
    for (i = 0; i < 12; i++) {
      
        digitalWrite(CK, HIGH);
        delayMicroseconds(1);
        digitalWrite(CK, LOW);
        
        if (digitalRead(DOUT) == HIGH) {
          bitSet(rgb[c],i);
        }
    }
}

