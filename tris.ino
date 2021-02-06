#include <Elegoo_TFTLCD.h>
#include <Elegoo_GFX.h>
#include <TouchScreen.h>

//PINS
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
#define TS_MINX 120
#define TS_MINY 71
#define TS_MAXX 910
#define TS_MAXY 910
#define YP A3
#define XM A2
#define YM 9
#define XP 8
//COLORI
#define  BLACK     0x0000
#define RED       0xF800
#define GREEN     0x07E0
#define YELLOW    0xFFE0
#define WHITE     0xFFFF
#define BLUE      0x979D
#define ORANGE    0xFD20
#define GREY      0x428C
#define GREEN2    0xAFE5

//INIZIALIZZAZIONE LIBRERIE
Elegoo_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
TouchScreen ts = TouchScreen(XP, YP, XM, YM, 364);

//VARIABILI
//var. pulsante
boolean buttonState = true;
boolean buttonStateP1 = false;
boolean buttonStateP2 = false;
boolean buttonStateP3 = false;
boolean buttonStateP4 = false;
boolean buttonStateP5 = false;
boolean buttonStateP6 = false;
boolean buttonStateP7 = false;
boolean buttonStateP8 = false;
boolean buttonStateP9 = false;
boolean buttonStateP10 = false;
boolean buttonStateP11 = false;
boolean buttonStateP12 = false;
boolean buttonStateP13 = false;
boolean buttonStateP14 = false;
boolean buttonStateP15 = false;
boolean buttonStateP16 = false;
boolean buttonStateP17 = false;

//numero pagina
int numPage = 0;

//turno giocatore
int turn = 1;

//modalità
int mode;

//numero mosse
int mosse1 = 0;
int mosse2 = 0;

//Numero casuale
int randcas;
int randX;

//mossa 1 cpu
boolean first = true;

//mossa random cpu
boolean RmossaCPU = true;

//riempimento caselle
boolean cas1 = false;
boolean cas2 = false;
boolean cas3 = false;
boolean cas4 = false;
boolean cas5 = false;
boolean cas6 = false;
boolean cas7 = false;
boolean cas8 = false;
boolean cas9 = false;

//riempimento caselle giocatore
int cas1p;
int cas2p;
int cas3p;
int cas4p;
int cas5p;
int cas6p;
int cas7p;
int cas8p;
int cas9p;


void Page1() {
  tft.fillScreen(GREY);
  tft.drawRect(0, 0, 320, 240, WHITE);
  tft.drawRect(1, 1, 318, 238, WHITE);
  tft.drawRect(2, 2, 316, 236, WHITE);
  tft.setCursor(90, 40);
  tft.setTextColor(YELLOW);
  tft.setTextSize(6);
  tft.print("TRIS");

  tft.fillRect(30, 115, 260, 40, ORANGE);
  tft.drawRect(29, 114, 262, 42, WHITE);
  tft.setCursor(41, 129);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(String("Modalit") + String((char)133) + String(" 2 giocatori"));
  tft.fillRect(30, 175, 260, 40, ORANGE);
  tft.drawRect(29, 174, 262, 42, WHITE);
  tft.setCursor(65, 188);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(String("Modalit") + String((char)133) + String(" singolo"));
}

void griglia() {
  tft.fillScreen(GREY);
  tft.fillRect(114, 20, 3, 200, WHITE);//verticale
  tft.fillRect(201, 20, 3, 200, WHITE);//verticale
  tft.fillRect(30, 78, 260, 3, WHITE);//orizzontale
  tft.fillRect(30, 159, 260, 3, WHITE);//orizzontale
}

void player1() {
  tft.setTextColor(BLUE);
  tft.setTextSize(6);
  tft.print("X");
  turn = 2;
}

void player2() {
  tft.setTextColor(RED);
  tft.setTextSize(8);
  tft.print("o");
  turn = 1;
}

void player1_R() {
  tft.setTextColor(BLUE);
  tft.setTextSize(6);
  tft.print("X");
}

void player2_R() {
  tft.setTextColor(RED);
  tft.setTextSize(8);
  tft.print("o");
}

void p1_win() {
  tft.fillScreen(GREY);
  tft.drawRect(0, 0, 320, 240, WHITE);
  tft.setCursor(10, 25);
  tft.setTextColor(YELLOW);
  tft.setTextSize(5);
  tft.print("VITTORIA");
  tft.setCursor(268, 20);
  tft.setTextColor(BLUE);
  tft.setTextSize(6);
  tft.print("X");

  tft.setCursor(20, 85);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Il giocatore 1 ha vinto");
  tft.setCursor(20, 110);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("con   mosse");
  tft.setCursor(68, 110);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(mosse1);

  tft.setCursor(235, 110);
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("R");
  tft.drawRect(228, 104, 25, 25, YELLOW);

  tft.fillRect(30, 145, 260, 30, ORANGE);
  tft.drawRect(29, 144, 262, 32, WHITE);
  tft.setCursor(68, 153);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Torna alla Home");
  tft.fillRect(30, 185, 260, 30, ORANGE);
  tft.drawRect(29, 184, 262, 32, WHITE);
  tft.setCursor(120, 193);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Rigioca");
}

void p2_win() {
  tft.fillScreen(GREY);
  tft.drawRect(0, 0, 320, 240, WHITE);
  tft.setCursor(10, 25);
  tft.setTextColor(YELLOW);
  tft.setTextSize(5);
  tft.print("VITTORIA");
  tft.setCursor(264, 8);
  tft.setTextColor(RED);
  tft.setTextSize(8);
  tft.print("o");

  tft.setCursor(20, 85);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Il giocatore 2 ha vinto");
  tft.setCursor(20, 110);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("con   mosse");
  tft.setCursor(68, 110);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(mosse2);

  tft.setCursor(235, 110);
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("R");
  tft.drawRect(228, 104, 25, 25, YELLOW);

  tft.fillRect(30, 145, 260, 30, ORANGE);
  tft.drawRect(29, 144, 262, 32, WHITE);
  tft.setCursor(68, 153);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Torna alla Home");
  tft.fillRect(30, 185, 260, 30, ORANGE);
  tft.drawRect(29, 184, 262, 32, WHITE);
  tft.setCursor(120, 193);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Rigioca");
}

void cpu_win() {
  tft.fillScreen(GREY);
  tft.drawRect(0, 0, 320, 240, WHITE);
  tft.setCursor(10, 25);
  tft.setTextColor(YELLOW);
  tft.setTextSize(5);
  tft.print("VITTORIA");
  tft.setCursor(268, 20);
  tft.setTextColor(BLUE);
  tft.setTextSize(6);
  tft.print("X");

  tft.setCursor(20, 85);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("La CPU ha vinto");
  tft.setCursor(20, 110);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("con   mosse");
  tft.setCursor(68, 110);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print(mosse1);

  tft.setCursor(235, 110);
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("R");
  tft.drawRect(228, 104, 25, 25, YELLOW);

  tft.fillRect(30, 145, 260, 30, ORANGE);
  tft.drawRect(29, 144, 262, 32, WHITE);
  tft.setCursor(68, 153);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Torna alla Home");
  tft.fillRect(30, 185, 260, 30, ORANGE);
  tft.drawRect(29, 184, 262, 32, WHITE);
  tft.setCursor(120, 193);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Rigioca");
}

void no_win() {
  tft.fillScreen(GREY);
  tft.drawRect(0, 0, 320, 240, WHITE);
  tft.setCursor(10, 25);
  tft.setTextColor(YELLOW);
  tft.setTextSize(5);
  tft.print("TERMINATA");

  tft.setCursor(20, 97);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Nessuno ha vinto");

  tft.setCursor(255, 97);
  tft.setTextColor(YELLOW);
  tft.setTextSize(2);
  tft.print("R");
  tft.drawRect(248, 91, 25, 25, YELLOW);

  tft.fillRect(30, 145, 260, 30, ORANGE);
  tft.drawRect(29, 144, 262, 32, WHITE);
  tft.setCursor(68, 153);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Torna alla Home");
  tft.fillRect(30, 185, 260, 30, ORANGE);
  tft.drawRect(29, 184, 262, 32, WHITE);
  tft.setCursor(120, 193);
  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.print("Rigioca");
}

void riepilogo() {
  griglia();
  tft.setCursor(5, 5);
  tft.setTextColor(WHITE);
  tft.setTextSize(1);
  tft.print("<  Torna");

  if (cas1 == true) {
    if (cas1p == 1) {
      tft.setCursor(55, 25);
      player1_R();
    }
    else if (cas1p == 2) {
      tft.setCursor(50, 15);
      player2_R();
    }
  }
  else if (cas1 == false) {
    //empty
  }

  if (cas2 == true) {
    if (cas2p == 1) {
      tft.setCursor(142, 25);
      player1_R();
    }
    else if (cas2p == 2) {
      tft.setCursor(137, 15);
      player2_R();
    }
  }
  else if (cas2 == false) {
    //empty
  }

  if (cas3 == true) {
    if (cas3p == 1) {
      tft.setCursor(230, 25);
      player1_R();
    }
    else if (cas3p == 2) {
      tft.setCursor(224, 15);
      player2_R();
    }
  }
  else if (cas3 == false) {
    //empty
  }

  if (cas4 == true) {
    if (cas4p == 1) {
      tft.setCursor(55, 100);
      player1_R();
    }
    else if (cas4p == 2) {
      tft.setCursor(50, 90);
      player2_R();
    }
  }
  else if (cas4 == false) {
    //empty
  }

  if (cas5 == true) {
    if (cas5p == 1) {
      tft.setCursor(142, 100);
      player1_R();
    }
    else if (cas5p == 2) {
      tft.setCursor(137, 90);
      player2_R();
    }
  }
  else if (cas5 == false) {
    //empty
  }

  if (cas6 == true) {
    if (cas6p == 1) {
      tft.setCursor(230, 100);
      player1_R();
    }
    else if (cas6p == 2) {
      tft.setCursor(224, 90);
      player2_R();
    }
  }
  else if (cas6 == false) {
    //empty
  }

  if (cas7 == true) {
    if (cas7p == 1) {
      tft.setCursor(55, 170);
      player1_R();
    }
    else if (cas7p == 2) {
      tft.setCursor(50, 155);
      player2_R();
    }
  }
  else if (cas7 == false) {
    //empty
  }

  if (cas8 == true) {
    if (cas8p == 1) {
      tft.setCursor(142, 170);
      player1_R();
    }
    else if (cas8p == 2) {
      tft.setCursor(137, 155);
      player2_R();
    }
  }
  else if (cas8 == false) {
    //empty
  }

  if (cas9 == true) {
    if (cas9p == 1) {
      tft.setCursor(230, 170);
      player1_R();
    }
    else if (cas9p == 2) {
      tft.setCursor(224, 155);
      player2_R();
    }
  }
  else if (cas9 == false) {
    //empty
  }
}


void randangle() {
  randcas = random(1, 4);
  //Serial.println(String("Numero Random = ") + String(randangle));
}

void randspace() {
  randX = random(1, 9);
  //Serial.println(String("Numero Random = ") + String(randX));
}


void tris_zero() {
  cas1 = false;
  cas2 = false;
  cas3 = false;
  cas4 = false;
  cas5 = false;
  cas6 = false;
  cas7 = false;
  cas8 = false;
  cas9 = false;
  cas1p = 0;
  cas2p = 0;
  cas3p = 0;
  cas4p = 0;
  cas5p = 0;
  cas6p = 0;
  cas7p = 0;
  cas8p = 0;
  cas9p = 0;
  mosse1 = 0;
  mosse2 = 0;
}

void setup() {
  Serial.begin(9600);
  tft.reset();
  uint16_t identifier = tft.readID();
  if(identifier==0x0101) {
    identifier=0x9341;
  }
  tft.begin(identifier);

  tft.setRotation(1);
  numPage = 0;
  Page1();
}

void loop() {
//MD 1
  if (mode == 1) {
    if ((cas1p==1 && cas2p==1 && cas3p==1) || (cas4p==1 && cas5p==1 && cas6p==1) || (cas7p==1 && cas8p==1 && cas9p==1) || (cas1p==1 && cas4p==1 && cas7p==1) || (cas2p==1 && cas5p==1 && cas8p==1) || (cas3p==1 && cas6p==1 && cas9p==1) || (cas3p==1 && cas5p==1 && cas7p==1) || (cas1p==1 && cas5p==1 && cas9p==1)) {
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

      p1_win();
      mode = 0;
      numPage = 2;
      turn = 0;
    }
    else if ((cas1p==2 && cas2p==2 && cas3p==2) || (cas4p==2 && cas5p==2 && cas6p==2) || (cas7p==2 && cas8p==2 && cas9p==2) || (cas1p==2 && cas4p==2 && cas7p==2) || (cas2p==2 && cas5p==2 && cas8p==2) || (cas3p==2 && cas6p==2 && cas9p==2) || (cas3p==2 && cas5p==2 && cas7p==2) || (cas1p==2 && cas5p==2 && cas9p==2)) {
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

      p2_win();
      mode = 0;
      numPage = 3;
      turn = 0;
    }
    else if ((cas1p==1 || cas1p==2) && (cas2p==1 || cas2p==2) && (cas3p==1 || cas3p==2) && (cas4p==1 || cas4p==2) && (cas5p==1 || cas5p==2) && (cas6p==1 || cas6p==2) && (cas7p==1 || cas7p==2) && (cas8p==1 || cas8p==2) && (cas9p==1 || cas9p==2)) {
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

      no_win();
      mode = 0;
      numPage = 4;
      turn = 0;
    }
  }

//MD 2
  if (mode == 2) {
    //riconoscimento tris
    if ((cas1p==1 && cas2p==1 && cas3p==1) || (cas4p==1 && cas5p==1 && cas6p==1) || (cas7p==1 && cas8p==1 && cas9p==1) || (cas1p==1 && cas4p==1 && cas7p==1) || (cas2p==1 && cas5p==1 && cas8p==1) || (cas3p==1 && cas6p==1 && cas9p==1) || (cas3p==1 && cas5p==1 && cas7p==1) || (cas1p==1 && cas5p==1 && cas9p==1)) {
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      delay(1000);
      cpu_win();
      mode = 0;
      numPage = 11;
      turn = 0;
    }
    else if ((cas1p==2 && cas2p==2 && cas3p==2) || (cas4p==2 && cas5p==2 && cas6p==2) || (cas7p==2 && cas8p==2 && cas9p==2) || (cas1p==2 && cas4p==2 && cas7p==2) || (cas2p==2 && cas5p==2 && cas8p==2) || (cas3p==2 && cas6p==2 && cas9p==2) || (cas3p==2 && cas5p==2 && cas7p==2) || (cas1p==2 && cas5p==2 && cas9p==2)) {
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      delay(1000);
      p2_win();
      mode = 0;
      numPage = 12;
      turn = 0;
    }
    else if ((cas1p==1 || cas1p==2) && (cas2p==1 || cas2p==2) && (cas3p==1 || cas3p==2) && (cas4p==1 || cas4p==2) && (cas5p==1 || cas5p==2) && (cas6p==1 || cas6p==2) && (cas7p==1 || cas7p==2) && (cas8p==1 || cas8p==2) && (cas9p==1 || cas9p==2)) {
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);
      delay(1000);
      no_win();
      mode = 0;
      numPage = 13;
      turn = 0;
    }


    if (first == true) {
      pinMode(XM, OUTPUT);
      pinMode(YP, OUTPUT);

      randangle();
      if (randcas == 1) {
        buttonStateP1 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(55, 25);
        player1();
        cas1 = true;
        cas1p = 1;
      }
      else if (randcas == 2) {
        buttonStateP3 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(230, 25);
        player1();
        cas3 = true;
        cas3p = 1;
      }

      else if (randcas == 3) {
        buttonStateP7 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(55, 170);
        player1();
        cas7 = true;
        cas7p = 1;
      }

      else if (randcas == 4) {
        buttonStateP9 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(230, 170);
        player1();
        cas9 = true;
        cas9p = 1;
      }

      mosse1 = mosse1 + 1;
      first = false;
    }

//RISPOSTA CPU
    if (turn == 1) {

      //TRIS X CPU

      if ((((cas2p == 1) && (cas3p == 1)) || ((cas5p == 1) && (cas9p == 1)) || ((cas4p == 1) && (cas7p == 1))) && (cas1 == false)) {
          buttonStateP1 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          cas1 = true;
          cas1p = 1;
          mosse1 = mosse1 + 1;
          tft.setCursor(55, 25);
          player1();
        }
      else if ((((cas1p == 1) && (cas3p == 1)) || ((cas5p == 1) && (cas8p == 1))) && (cas2 == false)) {
          buttonStateP2 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          cas2 = true;
          cas2p = 1;
          mosse1 = mosse1 + 1;
          tft.setCursor(142, 25);
          player1();
        }
      else if ((((cas1p == 1) && (cas2p == 1)) || ((cas6p == 1) && (cas9p == 1)) || ((cas5p == 1) && (cas7p == 1))) && (cas3 == false)) {
          buttonStateP3 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          cas3 = true;
          cas3p = 1;
          mosse1 = mosse1 + 1;
          tft.setCursor(230, 25);
          player1();
        }
      else if ((((cas1p == 1) && (cas7p == 1)) || ((cas5p == 1) && (cas6p == 1))) && (cas4 == false)) {
          buttonStateP4 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          cas4 = true;
          cas4p = 1;
          mosse1 = mosse1 + 1;
          tft.setCursor(55, 100);
          player1();
        }
      else if ((((cas4p == 1) && (cas6p == 1)) || ((cas3p == 1) && (cas7p == 1)) || ((cas1p == 1) && (cas9p == 1)) || ((cas2p == 1) && (cas8p == 1))) && (cas5 == false)) {
          buttonStateP5 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          cas5 = true;
          cas5p = 1;
          mosse1 = mosse1 + 1;
          tft.setCursor(142, 100);
          player1();
        }
      else if ((((cas4p == 1) && (cas5p == 1)) || ((cas3p == 1) && (cas9p == 1))) && (cas6 == false)) {
          buttonStateP6 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          cas6 = true;
          cas6p = 1;
          mosse1 = mosse1 + 1;
          tft.setCursor(230, 100);
          player1();
        }
      else if ((((cas1p == 1) && (cas4p == 1)) || ((cas3p == 1) && (cas5p == 1)) || ((cas8p == 1) && (cas9p == 1))) && (cas7 == false)) {
          buttonStateP7 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          cas7 = true;
          cas7p = 1;
          mosse1 = mosse1 + 1;
          tft.setCursor(55, 170);
          player1();
        }
      else if ((((cas2p == 1) && (cas5p == 1)) || ((cas7p == 1) && (cas9p == 1))) && (cas8 == false)) {
          buttonStateP8 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(142, 170);
          player1();
          cas8 = true;
          cas8p = 1;
          mosse1 = mosse1 + 1;
          tft.setCursor(142, 170);
          player1();
        }
      else if ((((cas1p == 1) && (cas5p == 1)) || ((cas7p == 1) && (cas8p == 1)) || ((cas3p == 1) && (cas6p == 1))) && (cas9 == false)) {
          buttonStateP9 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          cas9 = true;
          cas9p = 1;
          mosse1 = mosse1 + 1;
          tft.setCursor(230, 170);
          player1();
        }

      //BLOCCO TRIS CPU
      else if ((((cas2p == 2) && (cas3p == 2)) || ((cas5p == 2) && (cas9p == 2)) || ((cas4p == 2) && (cas7p == 2))) && (cas1 == false)) {
          buttonStateP1 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(55, 25);
          player1();
          cas1 = true;
          cas1p = 1;
          mosse1 = mosse1 + 1;
        }
      else if ((((cas1p == 2) && (cas3p == 2)) || ((cas5p == 2) && (cas8p == 2))) && (cas2 == false)) {
          buttonStateP2 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(142, 25);
          player1();
          cas2 = true;
          cas2p = 1;
          mosse1 = mosse1 + 1;
        }
      else if ((((cas1p == 2) && (cas2p == 2)) || ((cas6p == 2) && (cas9p == 2)) || ((cas5p == 2) && (cas7p == 2))) && (cas3 == false)) {
          buttonStateP3 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(230, 25);
          player1();
          cas3 = true;
          cas3p = 1;
          mosse1 = mosse1 + 1;
        }
      else if ((((cas1p == 2) && (cas7p == 2)) || ((cas5p == 2) && (cas6p == 2))) && (cas4 == false)) {
          buttonStateP4 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(55, 100);
          player1();
          cas4 = true;
          cas4p = 1;
          mosse1 = mosse1 + 1;
        }
      else if ((((cas4p == 2) && (cas6p == 2)) || ((cas3p == 2) && (cas7p == 2)) || ((cas1p == 2) && (cas9p == 2)) || ((cas2p == 2) && (cas8p == 2))) && (cas5 == false)) {
        buttonStateP5 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(142, 100);
        player1();
        cas5 = true;
        cas5p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((((cas4p == 2) && (cas5p == 2)) || ((cas3p == 2) && (cas9p == 2))) && (cas6 == false)) {
        buttonStateP6 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        cas6 = true;
        cas6p = 1;
        mosse1 = mosse1 + 1;
        tft.setCursor(230, 100);
        player1();
      }
      else if ((((cas1p == 2) && (cas4p == 2)) || ((cas3p == 2) && (cas5p == 2)) || ((cas8p == 2) && (cas9p == 2))) && (cas7 == false)) {
        buttonStateP7 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(55, 170);
        player1();
        cas7 = true;
        cas7p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((((cas2p == 2) && (cas5p == 2)) || ((cas7p == 2) && (cas9p == 2))) && (cas8 == false)) {
        buttonStateP8 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(142, 170);
        player1();
        cas8 = true;
        cas8p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((((cas1p == 2) && (cas5p == 2)) || ((cas7p == 2) && (cas8p == 2)) || ((cas3p == 2) && (cas6p == 2))) && (cas9 == false)) {
        buttonStateP9 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(230, 170);
        player1();
        cas9 = true;
        cas9p = 1;
        mosse1 = mosse1 + 1;
      }

      //RIEMPIMENTO CASELLE VUOTE CPU
      else if ((cas1 == false) && (cas2 == true) && (cas3 == true) && (cas4 == true) && (cas5 == true) && (cas6 == true) && (cas7 == true) && (cas8 == true) && (cas9 == true)) {
        buttonStateP1 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(55, 25);
        player1();
        cas1 = true;
        cas1p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((cas1 == true) && (cas2 == false) && (cas3 == true) && (cas4 == true) && (cas5 == true) && (cas6 == true) && (cas7 == true) && (cas8 == true) && (cas9 == true)) {
        buttonStateP2 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(142, 25);
        player1();
        cas2 = true;
        cas2p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((cas1 == true) && (cas2 == true) && (cas3 == false) && (cas4 == true) && (cas5 == true) && (cas6 == true) && (cas7 == true) && (cas8 == true) && (cas9 == true)) {
        buttonStateP3 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(230, 25);
        player1();
        cas3 = true;
        cas3p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((cas1 == true) && (cas2 == true) && (cas3 == true) && (cas4 == false) && (cas5 == true) && (cas6 == true) && (cas7 == true) && (cas8 == true) && (cas9 == true)) {
        buttonStateP4 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(55, 100);
        player1();
        cas4 = true;
        cas4p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((cas1 == true) && (cas2 == true) && (cas3 == true) && (cas4 == true) && (cas5 == false) && (cas6 == true) && (cas7 == true) && (cas8 == true) && (cas9 == true)) {
        buttonStateP5 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(142, 100);
        player1();
        cas5 = true;
        cas5p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((cas1 == true) && (cas2 == true) && (cas3 == true) && (cas4 == true) && (cas5 == true) && (cas6 == false) && (cas7 == true) && (cas8 == true) && (cas9 == true)) {
        buttonStateP6 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(230, 100);
        player1();
        cas6 = true;
        cas6p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((cas1 == true) && (cas2 == true) && (cas3 == true) && (cas4 == true) && (cas5 == true) && (cas6 == true) && (cas7 == false) && (cas8 == true) && (cas9 == true)) {
        buttonStateP7 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(55, 170);
        player1();
        cas7 = true;
        cas7p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((cas1 == true) && (cas2 == true) && (cas3 == true) && (cas4 == true) && (cas5 == true) && (cas6 == true) && (cas7 == true) && (cas8 == false) && (cas9 == true)) {
        buttonStateP8 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(142, 170);
        player1();
        cas8 = true;
        cas8p = 1;
        mosse1 = mosse1 + 1;
      }
      else if ((cas1 == true) && (cas2 == true) && (cas3 == true) && (cas4 == true) && (cas5 == true) && (cas6 == true) && (cas7 == true) && (cas8 == true) && (cas9 == false)) {
        buttonStateP9 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);
        delay(1000);
        tft.setCursor(230, 170);
        player1();
        cas9 = true;
        cas9p = 1;
        mosse1 = mosse1 + 1;
      }

      //RANDOM X CPU
      else if (turn == 1) {
        randspace();

        if ((randX == 1) && (cas1 == false)) {
          buttonStateP1 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(55, 25);
          player1();
          cas1 = true;
          cas1p = 1;
          mosse1 = mosse1 + 1;
        }
        else if ((randX == 2) && (cas2 == false)) {
          buttonStateP2 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(142, 25);
          player1();
          cas2 = true;
          cas2p = 1;
          mosse1 = mosse1 + 1;
        }
        else if ((randX == 3) && (cas3 == false)) {
          buttonStateP3 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(230, 25);
          player1();
          cas3 = true;
          cas3p = 1;
          mosse1 = mosse1 + 1;
        }
        else if ((randX == 4) && (cas4 == false)) {
          buttonStateP4 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(55, 100);
          player1();
          cas4 = true;
          cas4p = 1;
          mosse1 = mosse1 + 1;
          Serial.println("CASELLA 4 ESTRATTA");
        }
        else if ((randX == 5) && (cas5 == false)) {
          buttonStateP5 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(142, 100);
          player1();
          cas5 = true;
          cas5p = 1;
          mosse1 = mosse1 + 1;
        }
        else if ((randX == 6) && (cas6 == false)) {
          buttonStateP6 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(230, 100);
          player1();
          cas6 = true;
          cas6p = 1;
          mosse1 = mosse1 + 1;
        }
        else if ((randX == 7) && (cas7 == false)) {
          buttonStateP7 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(55, 170);
          player1();
          cas7 = true;
          cas7p = 1;
          mosse1 = mosse1 + 1;
          Serial.println("CASELLA 7 ESTRATTA");
        }
        else if ((randX == 8) && (cas8 == false)) {
          buttonStateP8 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(142, 170);
          player1();
          cas8 = true;
          cas8p = 1;
          mosse1 = mosse1 + 1;
        }
        else if ((randX == 9) && (cas2 == false)) {
          buttonStateP9 = false;

          pinMode(XM, OUTPUT);
          pinMode(YP, OUTPUT);
          delay(1000);
          tft.setCursor(230, 170);
          player1();
          cas9 = true;
          cas9p = 1;
          mosse1 = mosse1 + 1;
        }
      }

    }
  }

//INIZIO LOOP TOUCH
  TSPoint p = ts.getPoint();

  if (p.z > ts.pressureThreshhold) {
    p.x = map(p.x, TS_MAXX, TS_MINX, 0, 240);
    p.y = map(p.y, TS_MAXY, TS_MINY, 0, 320);
    //Serial.println(String("x map = ") + String(p.x));
    //Serial.println(String("y map = ") + String(p.y));
    //Serial.println(String("z = ") + String(p.z));

//pagina iniziale
    if (numPage == 0) {
      buttonState = true;
      if(p.y>29 && p.y<291 && p.x>114 && p.x<156 && buttonState) {
        buttonState = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 1;
        griglia();
        mode = 1;
        turn = 1;
      }

      else if(p.y>29 && p.y<291 && p.x>174 && p.x<216 && buttonState) {
        buttonState = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 10;
        griglia();
        mode = 2;
        turn = 1;
      }
    }

//PAGINA 1: pagina tris manuale
    else if (numPage == 1) {
    //TURNO 1
      if (turn == 1) {

        if(p.y>30 && p.y<114 && p.x>20 && p.x<78) {
          buttonStateP1 = true;
          if (cas1 == false) {
            buttonStateP1 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(55, 25);
            player1();
            cas1 = true;
            cas1p = 1;
            mosse1 = mosse1 + 1;
          }
        }

        if (p.y>117 && p.y<201 && p.x>20 && p.x<78) {
          buttonStateP2 = true;
          if (cas2 == false) {
            buttonStateP2 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(142, 25);
            player1();
            cas2 = true;
            cas2p = 1;
            mosse1 = mosse1 + 1;
          }
        }

        if (p.y>204 && p.y<290 && p.x>20 && p.x<78) {
          buttonStateP3 = true;
          if (cas3 == false) {
            buttonStateP3 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(230, 25);
            player1();
            cas3 = true;
            cas3p = 1;
            mosse1 = mosse1 + 1;
          }
        }

        if (p.y>30 && p.y<114 && p.x>81 && p.x<159) {
          buttonStateP4 = true;
          if (cas4 == false) {
            buttonStateP4 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(55, 100);
            player1();
            cas4 = true;
            cas4p = 1;
            mosse1 = mosse1 + 1;
          }
        }

        if (p.y>117 && p.y<201 && p.x>81 && p.x<159) {
          buttonStateP5 = true;
          if (cas5 == false) {
            buttonStateP5 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(142, 100);
            player1();
            cas5 = true;
            cas5p = 1;
            mosse1 = mosse1 + 1;
          }
        }

        if (p.y>204 && p.y<290 && p.x>81 && p.x<159) {
          buttonStateP6 = true;
          if (cas6 == false) {
            buttonStateP6 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(230, 100);
            player1();
            cas6 = true;
            cas6p = 1;
            mosse1 = mosse1 + 1;
          }
        }

        if (p.y>30 && p.y<114 && p.x>162 && p.x<220) {
          buttonStateP7 = true;
          if (cas7 == false) {
            buttonStateP7 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(55, 170);
            player1();
            cas7 = true;
            cas7p = 1;
            mosse1 = mosse1 + 1;
          }
        }

        if (p.y>117 && p.y<201 && p.x>162 && p.x<220) {
          buttonStateP8 = true;
          if (cas8 == false) {
            buttonStateP8 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(142, 170);
            player1();
            cas8 = true;
            cas8p = 1;
            mosse1 = mosse1 + 1;
          }
        }

        if (p.y>204 && p.y<290 && p.x>162 && p.x<220) {
          buttonStateP9 = true;
          if (cas9 == false) {
            buttonStateP9 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(230, 170);
            player1();
            cas9 = true;
            cas9p = 1;
            mosse1 = mosse1 + 1;
          }
        }

      }


    //TURNO 2
      else if (turn == 2) {

        if(p.y>30 && p.y<114 && p.x>20 && p.x<78) {
          buttonStateP1 = true;
          if (cas1 == false) {
            buttonStateP1 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(50, 15);
            player2();
            cas1 = true;
            cas1p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>117 && p.y<201 && p.x>20 && p.x<78) {
          buttonStateP2 = true;
          if (cas2 == false) {
            buttonStateP2 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(137, 15);
            player2();
            cas2 = true;
            cas2p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>204 && p.y<290 && p.x>20 && p.x<78) {
          buttonStateP3 = true;
          if (cas3 == false) {
            buttonStateP3 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(224, 15);
            player2();
            cas3 = true;
            cas3p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>30 && p.y<114 && p.x>81 && p.x<159) {
          buttonStateP4 = true;
          if (cas4 == false) {
            buttonStateP4 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(50, 90);
            player2();
            cas4 = true;
            cas4p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>117 && p.y<201 && p.x>81 && p.x<159) {
          buttonStateP5 = true;
          if (cas5 == false) {
            buttonStateP5 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(137, 90);
            player2();
            cas5 = true;
            cas5p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>204 && p.y<290 && p.x>81 && p.x<159) {
          buttonStateP6 = true;
          if (cas6 == false) {
            buttonStateP6 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(224, 90);
            player2();
            cas6 = true;
            cas6p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>30 && p.y<114 && p.x>162 && p.x<220) {
          buttonStateP7 = true;
          if (cas7 == false) {
            buttonStateP7 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(50, 155);
            player2();
            cas7 = true;
            cas7p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>117 && p.y<201 && p.x>162 && p.x<220) {
          buttonStateP8 = true;
          if (cas8 == false) {
            buttonStateP8 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(137, 155);
            player2();
            cas8 = true;
            cas8p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>204 && p.y<290 && p.x>162 && p.x<220) {
          buttonStateP9 = true;
          if (cas9 == false) {
            buttonStateP9 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(224, 155);
            player2();
            cas9 = true;
            cas9p = 2;
            mosse2 = mosse2 + 1;
          }
        }
      }

    }

//PAGINA 2
    else if (numPage == 2) {
      buttonStateP10 = true;
      if (p.y>30 && p.y<290 && p.x>145 && p.x<175 && buttonStateP10) {
        buttonStateP10 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        Page1();
        tris_zero();
      }
      else if (p.y>30 && p.y<290 && p.x>185 && p.x<215 && buttonStateP10) {
        buttonStateP10 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 1;
        griglia();
        mode = 1;
        turn = 1;
        tris_zero();
      }
      else if (p.y>228 && p.y<253 && p.x>104 && p.x<129 && buttonStateP10) {
        buttonStateP10 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 5;
        riepilogo();
      }
    }

//PAGINA 3
    else if (numPage == 3) {
      buttonStateP11 = true;
      if (p.y>30 && p.y<290 && p.x>145 && p.x<175 && buttonStateP11) {
        buttonStateP11 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        Page1();
        tris_zero();
      }
      else if (p.y>30 && p.y<290 && p.x>185 && p.x<215 && buttonStateP11) {
        buttonStateP11 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 1;
        griglia();
        mode = 1;
        turn = 1;
        tris_zero();
      }
      else if (p.y>228 && p.y<253 && p.x>104 && p.x<129 && buttonStateP11) {
        buttonStateP11 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 6;
        riepilogo();
      }
    }


//PAGINA 4
    else if (numPage == 4) {
      buttonStateP12 = true;
      if (p.y>30 && p.y<290 && p.x>145 && p.x<175 && buttonStateP12) {
        buttonStateP12 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        Page1();
        tris_zero();
      }
      else if (p.y>30 && p.y<290 && p.x>185 && p.x<215 && buttonStateP12) {
        buttonStateP12 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 1;
        griglia();
        mode = 1;
        turn = 1;
        tris_zero();
      }
      else if (p.y>248 && p.y<273 && p.x>91 && p.x<116 && buttonStateP12) {
        buttonStateP12 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 7;
        riepilogo();
      }
    }

//PAGINA 5: Pagina riepilogo tris X
    else if (numPage == 5) {
      buttonStateP13 = true;
      if (p.y>0 && p.y<15 && p.x>0 && p.x<15 && buttonStateP13) {
        buttonStateP13 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 2;
        p1_win();
      }
    }

//PAGINA 6: Pagina riepilogo tris o
    else if (numPage == 6) {
      buttonStateP13 = true;
      if (p.y>0 && p.y<15 && p.x>0 && p.x<15 && buttonStateP13) {
        buttonStateP13 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 3;
        p2_win();
      }
    }

//PAGINA 7: Pagina riepilogo nessuno
    else if (numPage == 7) {
      buttonStateP13 = true;
      if (p.y>0 && p.y<15 && p.x>0 && p.x<15 && buttonStateP13) {
        buttonStateP13 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 4;
        no_win();
      }
    }


//PAGINA 10: tris o automatico
    else if (numPage == 10) {

      if (turn == 2) {

        if(p.y>30 && p.y<114 && p.x>20 && p.x<78) {
          buttonStateP1 = true;
          if (cas1 == false) {
            buttonStateP1 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(50, 15);
            player2();
            cas1 = true;
            cas1p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>117 && p.y<201 && p.x>20 && p.x<78) {
          buttonStateP2 = true;
          if (cas2 == false) {
            buttonStateP2 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(137, 15);
            player2();
            cas2 = true;
            cas2p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>204 && p.y<290 && p.x>20 && p.x<78) {
          buttonStateP3 = true;
          if (cas3 == false) {
            buttonStateP3 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(224, 15);
            player2();
            cas3 = true;
            cas3p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>30 && p.y<114 && p.x>81 && p.x<159) {
          buttonStateP4 = true;
          if (cas4 == false) {
            buttonStateP4 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(50, 90);
            player2();
            cas4 = true;
            cas4p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>117 && p.y<201 && p.x>81 && p.x<159) {
          buttonStateP5 = true;
          if (cas5 == false) {
            buttonStateP5 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(137, 90);
            player2();
            cas5 = true;
            cas5p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>204 && p.y<290 && p.x>81 && p.x<159) {
          buttonStateP6 = true;
          if (cas6 == false) {
            buttonStateP6 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(224, 90);
            player2();
            cas6 = true;
            cas6p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>30 && p.y<114 && p.x>162 && p.x<220) {
          buttonStateP7 = true;
          if (cas7 == false) {
            buttonStateP7 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(50, 155);
            player2();
            cas7 = true;
            cas7p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>117 && p.y<201 && p.x>162 && p.x<220) {
          buttonStateP8 = true;
          if (cas8 == false) {
            buttonStateP8 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(137, 155);
            player2();
            cas8 = true;
            cas8p = 2;
            mosse2 = mosse2 + 1;
          }
        }

        if (p.y>204 && p.y<290 && p.x>162 && p.x<220) {
          buttonStateP9 = true;
          if (cas9 == false) {
            buttonStateP9 = false;

            pinMode(XM, OUTPUT);
            pinMode(YP, OUTPUT);

            tft.setCursor(224, 155);
            player2();
            cas9 = true;
            cas9p = 2;
            mosse2 = mosse2 + 1;
          }
        }
      }
    }

//PAGINA 11
    else if (numPage == 11) {
      buttonStateP14 = true;
      if (p.y>30 && p.y<290 && p.x>145 && p.x<175 && buttonStateP14) {
        buttonStateP14 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        Page1();
        tris_zero();
        first = true;
      }
      else if (p.y>30 && p.y<290 && p.x>185 && p.x<215 && buttonStateP14) {
        buttonStateP14 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 10;
        griglia();
        mode = 2;
        turn = 1;
        tris_zero();
        first = true;
      }
      else if (p.y>228 && p.y<253 && p.x>104 && p.x<129 && buttonStateP14) {
        buttonStateP14 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 14;
        riepilogo();
      }
    }

//PAGINA 12
    else if (numPage == 12) {
      buttonStateP15 = true;
      if (p.y>30 && p.y<290 && p.x>145 && p.x<175 && buttonStateP15) {
        buttonStateP15 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        Page1();
        tris_zero();
        first = true;
      }
      else if (p.y>30 && p.y<290 && p.x>185 && p.x<215 && buttonStateP15) {
        buttonStateP15 = false;
        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 10;
        griglia();
        mode = 2;
        turn = 1;
        tris_zero();
        first = true;
      }
      else if (p.y>228 && p.y<253 && p.x>104 && p.x<129 && buttonStateP15) {
        buttonStateP15 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 15;
        riepilogo();
      }
    }

//PAGINA 13
    else if (numPage == 13) {
      buttonStateP16 = true;
      if (p.y>30 && p.y<290 && p.x>145 && p.x<175 && buttonStateP16) {
        buttonStateP16 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 0;
        Page1();
        tris_zero();
        first = true;
      }
      else if (p.y>30 && p.y<290 && p.x>185 && p.x<215 && buttonStateP16) {
        buttonStateP16 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 1;
        griglia();
        mode = 2;
        turn = 1;
        tris_zero();
        first = true;
      }
      else if (p.y>248 && p.y<273 && p.x>91 && p.x<116 && buttonStateP16) {
        buttonStateP16 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 16;
        riepilogo();
      }
    }


//PAGINA 14: Pagina riepilogo tris cpu
    else if (numPage == 14) {
      buttonStateP17 = true;
      if (p.y>0 && p.y<15 && p.x>0 && p.x<15 && buttonStateP17) {
        buttonStateP17 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 11;
        cpu_win();
      }
    }

//PAGINA 15: Pagina riepilogo tris o
    else if (numPage == 15) {
      buttonStateP17 = true;
      if (p.y>0 && p.y<15 && p.x>0 && p.x<15 && buttonStateP17) {
        buttonStateP17 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 12;
        p2_win();
      }
    }

//PAGINA 16:
    else if (numPage == 16) {
      buttonStateP17 = true;
      if (p.y>0 && p.y<15 && p.x>0 && p.x<15 && buttonStateP17) {
        buttonStateP17 = false;

        pinMode(XM, OUTPUT);
        pinMode(YP, OUTPUT);

        numPage = 13;
        no_win();
      }
    }

  }
}
