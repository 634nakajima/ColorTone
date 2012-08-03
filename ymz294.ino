//ymz294

int tp[] = {//MIDI note number
  15289, 14431, 13621, 12856, 12135, 11454, 10811, 10204,//0-7
  9631, 9091, 8581, 8099, 7645, 7215, 6810, 6428,//8-15
  6067, 5727, 5405, 5102, 4816, 4545, 4290, 4050,//16-23
  3822, 3608, 3405, 3214, 3034, 2863, 2703, 2551,//24-31
  2408, 2273, 2145, 2025, 1911, 1804, 1703, 1607,//32-39
  1517, 1432, 1351, 1276, 1204, 1136, 1073, 1012,//40-47
  956, 902, 851, 804, 758, 716, 676, 638,//48-55
  602, 568, 536, 506, 478, 451, 426, 402,//56-63
  379, 358, 338, 319, 301, 284, 268, 253,//64-71
  239, 225, 213, 201, 190, 179, 169, 159,//72-79
  150, 142, 134, 127, 119, 113, 106, 100,//80-87
  95, 89, 84, 80, 75, 71, 67, 63,//88-95
  60, 56, 53, 50, 47, 45, 42, 40,//96-103
  38, 36, 34, 32, 30, 28, 27, 25,//104-111
  24, 22, 21, 20, 19, 18, 17, 16,//112-119
  15, 14, 13, 13, 12, 11, 11, 10,//120-127
  0//off
};

void setupYMZ() {
    //digitalWrite(RESET, LOW);
    //digitalWrite(RESET, HIGH);

    set_noise(0x00);
    set_mixer(0x37);  //A:noise
    /*
    set_vol_chA(0x00);
    set_vol_chB(0x00);
    set_vol_chC(0x00);
    
    set_chA_MIDI(60);
    set_chB_MIDI(64);
    set_chC_MIDI(67);
    */
    
}

void write_data(unsigned char address, unsigned char data)
{
  //write address
  digitalWrite(WR, LOW);
  digitalWrite(CS, LOW);
  digitalWrite(Ao, LOW);
  
  digitalWrite(D0, address&0x01);
  digitalWrite(D1, (address >> 1)&0x01);
  digitalWrite(D2, (address >> 2)&0x01);
  digitalWrite(D3, (address >> 3)&0x01);
  digitalWrite(D4, (address >> 4)&0x01);
  digitalWrite(D5, (address >> 5)&0x01);
  digitalWrite(D6, (address >> 6)&0x01);
  digitalWrite(D7, (address >> 7)&0x01);
  
  digitalWrite(WR, HIGH);
  digitalWrite(CS, HIGH);
  //write data
  digitalWrite(WR, LOW);
  digitalWrite(CS, LOW);
  digitalWrite(Ao, HIGH);
  
  digitalWrite(D0, address&0x01);
  digitalWrite(D1, (data >> 1)&0x01);
  digitalWrite(D2, (data >> 2)&0x01);
  digitalWrite(D3, (data >> 3)&0x01);
  digitalWrite(D4, (data >> 4)&0x01);
  digitalWrite(D5, (data >> 5)&0x01);
  digitalWrite(D6, (data >> 6)&0x01);
  digitalWrite(D7, (data >> 7)&0x01);
  
  digitalWrite(WR, HIGH);
  digitalWrite(CS, HIGH);
}

void set_chA_MIDI(int i)
{
    write_data(0x00, tp[i]&0xff);
    write_data(0x01, (tp[i] >> 8)&0x0f);
}

void set_chB_MIDI(int i)
{
    write_data(0x02, tp[i]&0xff);
    write_data(0x03, (tp[i] >> 8)&0x0f);
}

void set_chC_MIDI(int i)
{
    write_data(0x04, tp[i]&0xff);
    write_data(0x05, (tp[i] >> 8)&0x0f);
}

void set_chA_period(int i)
{
    write_data(0x00, i&0xff);
    write_data(0x01, (i >> 8)&0x0f);
}

void set_chB_period(int i)
{
    write_data(0x02, i&0xff);
    write_data(0x03, (i >> 8)&0x0f);
}

void set_chC_period(int i)
{
    write_data(0x04, i&0xff);
    write_data(0x05, (i >> 8)&0x0f);
}

void set_noise(int i)
{
    write_data(0x06, i&0x1f);
}

void set_mixer(int i)
{
    write_data(0x07, i);
}

void set_vol_chA(int i)
{
    write_data(0x08, i);
}

void set_vol_chB(int i)
{
    write_data(0x09, i);
}

void set_vol_chC(int i)
{
    write_data(0x0A, i);
}

void set_env_ctl(int i)
{
    write_data(0x0D, i);
}

void set_env_period(int i)
{
    write_data(0x0B, i&0xff);
    write_data(0x0C, (i >> 8)&0xff);
}

