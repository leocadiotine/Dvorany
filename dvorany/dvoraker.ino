void translate_to_dvorak(uint8_t *buf)
{
  uint8_t i;
  for (i=2; i<8; i++) {

    /** Number line **/
    if (buf[i] == 0x2D) { //-
      buf[i] = 0x2f; //[
    }
    else if (buf[i] == 0x2E) { //+
      buf[i] = 0x30; //]
    }
    
    /** 1st line **/
    else if (buf[i] == 0x14) { //Q
      buf[i] = 0x34;
    } 
    else if (buf[i] == 0x1A) { //w
      buf[i] = 0x36;
    } 
    else if (buf[i] == 0x08) { //e
      buf[i] = 0x37;
    }
    else if (buf[i] == 0x15) { //r
      buf[i] = 0x13;
    }
    else if (buf[i] == 0x17) { //t
      buf[i] = 0x1C;
    }
    else if (buf[i] == 0x1C) { //y
      buf[i] = 0x09;
    }
    else if (buf[i] == 0x18) { //u
      buf[i] = 0x0A;
    }
    else if (buf[i] == 0x0C) { //I
      buf[i] = 0x06;
    }
    else if (buf[i] == 0x12) { //O
      buf[i] = 0x15;
    }
    else if (buf[i] == 0x13) { //P
      buf[i] = 0x0F;
    }
    else if (buf[i] == 0x2F) { //[
      buf[i] = 0x38;
    }
    else if (buf[i] == 0x30) { //]
      buf[i] = 0x2E;
    }
    
    /** 2nd line **/
    else if (buf[i] == 0x16) { //S
      buf[i] = 0x12;
    }
    else if (buf[i] == 0x07) { //D
      buf[i] = 0x08;
    }
    else if (buf[i] == 0x09) { //F
      buf[i] = 0x18;
    }
    else if (buf[i] == 0x0A) { //G
      buf[i] = 0x0C;
    }
    else if (buf[i] == 0x0B) { //H
      buf[i] = 0x07; //D
    }
    else if (buf[i] == 0x0D) { //J
      buf[i] = 0x0B; //H
    }
    else if (buf[i] == 0x0E) { //K
      buf[i] = 0x17; //T
    }
    else if (buf[i] == 0x0F) { //L
      buf[i] = 0x11; //N
    }
    else if (buf[i] == 0x33) { //;
      buf[i] = 0x16; //S
    }
    else if (buf[i] == 0x34) { //"
      buf[i] = 0x2D; //-
    }
    
    /** 3rd line **/
    else if (buf[i] == 0x1D) { //Z
      buf[i] = 0x33; //:
    }
    else if (buf[i] == 0x1B) { //X
      buf[i] = 0x14; //Q
    }
    else if (buf[i] == 0x06) { //C
      buf[i] = 0x0D; //J
    }
    else if (buf[i] == 0x19) { //V
      buf[i] = 0x0E; //K
    }
    else if (buf[i] == 0x05) { //B
      buf[i] = 0x1B; //X
    }
    else if (buf[i] == 0x11) { //N
      buf[i] = 0x05; //B
    }
    else if (buf[i] == 0x36) { //<
      buf[i] = 0x1A; //W
    }
    else if (buf[i] == 0x37) { //>
      buf[i] = 0x19; //V
    }
    else if (buf[i] == 0x38) { //?
      buf[i] = 0x1D; //Z
    }
    
  } 
}

