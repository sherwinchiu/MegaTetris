#include <avr/wdt.h>
#define   SS1pin   48 // whatever number
#define   SS2pin   46 // whatever number
#define   dataPin     51
#define   clockPin    52

#define   moveLeftPin     35 
#define   moveRightPin    37
#define   rotatePin   33 
#define   fallFasterPin   39
#define   reset  31

#define   OE1              44
#define   OE2              42

#define   BOARD_WIDTH     8
#define   BOARD_HEIGHT    8

byte printBlocks[2][8] = {{
   B00000000, // x = 0
   B00000000, // x = 1
   B00000000, // x = 2
   B00000000, // x = 3 - block[x]; y = 7 + block[y] // bitSet(printBlocks[x], y 
   B00000000,
   B00000000,
   B00000000,
   B00000000,}
  ,{
   B00000000, // x = 0
   B00000000, // x = 1
   B00000000, // x = 2
   B00000000, // x = 3 - block[x]; y = 7 + block[y] // bitSet(printBlocks[x], y 
   B00000000,
   B00000000,
   B00000000,
   B00000000,}};
byte stationaryBlocks[2][8] = {{
   B00000000,
   B00000000, 
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,}
   ,{
   B00000000, // x = 0
   B00000000, // x = 1
   B00000000, // x = 2
   B00000000, // x = 3 - block[x]; y = 7 + block[y] // bitSet(printBlocks[x], y 
   B00000000,
   B00000000,
   B00000000,
   B00000000,}};
byte losingBlocks[8] = {
   B00000000, // x = 0
   B00000000, // x = 1
   B01111100, // x = 2
   B00000100, // x = 3 - block[x]; y = 7 + block[y] // bitSet(printBlocks[x], y 
   B00000100,
   B00000100,
   B00000000,
   B00000000,
  };
unsigned long lastDebounceTime[4] = {0, 0, 0, 0};
unsigned long debounceTime[4] = {0, 0, 0, 0};
boolean currentMatrix = false; //False for top, true for bottom
byte rowNum = 0;
int8_t orientation = 1;
const byte Y = 1; 
const byte X = 0;
// 1, randBlock, 2, which rotation, 3, block placement, 4, coordinates 
int8_t blocks[7][4][4][2] = {   
  {
    //           (default rotation)
    //   o             o o                o
    // o x               x o            x o          o x
    // o                                o              o o
    {{-1, 1}, {-1, 0}, {0, 0}, {0, -1}},
    {{-1, -1}, {0, -1}, {0, 0}, {1, 0}},
    {{1, -1}, {1, 0}, {0, 0}, {0, 1}},
    {{1, 1}, {0, 1}, {0, 0}, {-1, 0}}
  }, {
    //
    // o                 o o           o
    // o x             o x             x o             x o
    //   o                               o           o o
    {{-1, -1}, {-1, 0}, {0, 0}, {0, 1}},
    {{1, -1}, {0, -1}, {0, 0}, {-1, 0}},
    {{1, 1}, {1, 0}, {0, 0}, {0, -1}},
    {{-1, 1}, {0, 1}, {0, 0}, {1, 0}}
  }, {
    //
    //   o             o                o o
    //   x             o x o            x           o x o
    // o o                              o               o
    {{-1, 1}, {0, 1}, {0, 0}, {0, -1}},
    {{-1, -1}, {-1, 0}, {0, 0}, {1, 0}},
    {{1, -1}, {0, -1}, {0, 0}, {0, 1}},
    {{1, 1}, {1, 0}, {0, 0}, {-1, 0}}
  }, {
    //
    // o o                o             o
    //   x            o x o             x           o x o
    //   o                              o o         o
    {{-1, -1}, {0, -1}, {0, 0}, {0, 1}},
    {{1, -1}, {1, 0}, {0, 0}, {-1, 0}},
    {{1, 1}, {0, 1}, {0, 0}, {0, -1}},
    {{-1, 1}, {-1, 0}, {0, 0}, {1, 0}}
  }, {
    //   o                              o
    //   o                              x
    //   x            o x o o           o          o o x o
    //   o                              o
    {{0, -2}, {0, -1}, {0, 0}, {0, 1}},
    {{2, 0}, {1, 0}, {0, 0}, {-1, 0}},
    {{0, 2}, {0, 1}, {0, 0}, {0, -1}},
    {{-2, 0}, {-1, 0}, {0, 0}, {1, 0}}
  }, {
    //
    //   o              o                o
    // o x            o x o              x o         o x o
    //   o                               o             o
    {{0, 1}, {-1, 0}, {0, 0}, {0, -1}},
    {{-1, 0}, {0, -1}, {0, 0}, {1, 0}},
    {{0, -1}, {1, 0}, {0, 0}, {0, 1}},
    {{1, 0}, {0, 1}, {0, 0}, {-1, 0}}
  }, {
    //
    // o o            o o               o o          o o
    // o x            o x               o x          o x
    //
    {{-1, 0}, {-1, -1}, {0, 0}, {0, -1}},
    {{-1, 0}, {-1, -1}, {0, 0}, {0, -1}},
    {{-1, 0}, {-1, -1}, {0, 0}, {0, -1}},
    {{-1, 0}, {-1, -1}, {0, 0}, {0, -1}}
  }
};

int randBlock = 0;

int8_t blockX = 3;
int8_t blockY = 15;

const byte MAX_Y = 15;
const byte MAX_X = 3;
unsigned long timeStart = 0;
unsigned long timeElapsed = 0;

int fallTime = 300;
int losingCounter = 0;

const byte MOVE_RIGHT = 1;
const byte MOVE_LEFT = 2;
const byte ROTATE = 3;
const byte FALL_FASTER = 4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRA = B11111111; // all pins are set as outputs
  pinMode(OE1, OUTPUT);
  pinMode(OE2, OUTPUT);
  digitalWrite(OE1, LOW);
  digitalWrite(OE2, LOW);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(SS1pin, OUTPUT);
  pinMode(SS2pin, OUTPUT);
  pinMode(moveLeftPin, INPUT);
  pinMode(moveRightPin, INPUT);
  pinMode(rotatePin, INPUT);
  pinMode(reset, INPUT);
  pinMode(fallFasterPin, INPUT);
  pinMode(A0, INPUT);
  randomSeed(analogRead(A0));
  createBlock();
  drawBlock(printBlocks);
}
void loop() {
  // put your main code here, to run repeatedly:
  timeStart = millis(); // check current time
  losingScreen();
  outputColumn();   // draw column
  outputRow();      // draw row
  copyStationary();           // copy printBlocks array into stationary blocks
  sidewardCollision();        // Check for sideward collision and correct for it.
  drawMatrixes();
  if((timeStart - timeElapsed) > fallTime){
    blockY--;                           // increment (move block by 1)
    if(downwardCollision()){                      // if collision
      blockY++;                         // move it back
      copyMatrixes();
      createBlock();                    // create a new block
    }
    timeElapsed = timeStart;    // set the timer once more
  }
  moveLeft();   // move left
  moveRight();  // move right
  rotate();     // rotate
  fallFaster(); // fall faster
  resetGame();     // reboot program
}
//---------------------------------------------------------|
//                      Output Functions                   |
//---------------------------------------------------------|
void outputRow(){
  if(currentMatrix)
    shiftData(SS2pin, round(pow(2, rowNum)));
  else if(!currentMatrix)
    shiftData(SS1pin, round(pow(2, rowNum)));
  rowNum++;
  if (rowNum > sizeof(printBlocks[0])){
    currentMatrix=!currentMatrix;
    rowNum = 0;
  }
}
void outputColumn(){
  if(currentMatrix)
    PORTA = ~printBlocks[0][rowNum];
  else if (!currentMatrix)
    PORTA = ~printBlocks[1][rowNum];
}
void shiftData(byte storage, byte data){
  digitalWrite(storage, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, data);
  digitalWrite(storage, HIGH);
  digitalWrite(storage, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 0);
  digitalWrite(storage, HIGH);
}
//---------------------------------------------------------|
//                      Player Functions                   |
//---------------------------------------------------------|
void checkDebounce(byte dir){
  debounceTime[dir] = millis();
  if (debounceTime[dir] - lastDebounceTime[dir] > 200){
    if(dir == MOVE_LEFT)
      blockX++;
    else if(dir == MOVE_RIGHT)
      blockX--;
    else if(dir == ROTATE){
      orientation--;
      if (orientation == -1)
        orientation = 3;
    }
    else if(dir == FALL_FASTER){
      blockY--;
    }
    lastDebounceTime[dir] = debounceTime[dir];
    outputColumn();   // draw column
    outputRow();      // draw row
  }
} // checkDebounce function end 
//--------------------------------------------------------
void moveLeft(){
  if (digitalRead(moveLeftPin))
    checkDebounce(MOVE_LEFT);
}
void moveRight(){
  if (digitalRead(moveRightPin))
    checkDebounce(MOVE_RIGHT);
}
void rotate(){
  if(digitalRead(rotatePin)){
    checkDebounce(ROTATE);
  }
}
void fallFaster(){
  if(digitalRead(fallFasterPin))
    checkDebounce(FALL_FASTER);
}

void resetGame() {
  if(digitalRead(reset)){
    wdt_disable();
    wdt_enable(WDTO_15MS);
    while (1) {}
  }
}
//---------------------------------------------------------|
//                      Block Functions                    |
//---------------------------------------------------------|
void drawMatrixes(){
  drawBlock(printBlocks);     // draw the block to print blocks
  clearBlocks(stationaryBlocks);
}
void copyMatrixes(){
  drawBlock(stationaryBlocks);
//  for(int p = 0; p < 4; p++){
//    if(blockY+ blocks[randBlock][orientation][p][Y] > 7)
//      drawBlock(stationaryBlocks[0]);      // draw current block to the stationaryBlock array
//    else 
//      drawBlock(stationaryBlocks[1]);
//  }
}
void drawBlock(byte copyBlocks[2][8]){
  for(int p = 0; p < 4; p++){
    if(blockY+ blocks[randBlock][orientation][p][Y] > 7)
      bitSet(copyBlocks[0][blockX- blocks[randBlock][orientation][p][X]], blockY-8 + blocks[randBlock][orientation][p][Y]);
    else
      bitSet(copyBlocks[1][blockX- blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y]);
  }
}
void copyStationary(){
  // destination, source, numbytes
  for(int i = 0; i < 2; i++)
    memcpy(printBlocks[i], stationaryBlocks[i], 8);
 
}
void createBlock(){
  randBlock = random(7);
  orientation = 1;
  blockX = MAX_X;
  blockY = MAX_Y;
}
//--------------------------------------------------------
void clearBlocks(byte copyBlocks[2][8]){
  byte checkFullRow = 0;
  for(int q = 0; q < 2; q++){
    for(int i = 0; i < 7; i++){
      for(int j = 0; j < sizeof(copyBlocks[q]); j++){
        checkFullRow += bitRead(copyBlocks[q][j], i); 
      }
      if (checkFullRow == 8){
        checkFullRow = 0;
        for(int n = 0; n < 7; n++){
          bitWrite(copyBlocks[q][n], i, 0);
        }
        for(int j = i+1; j < 7; j++){
          for(int n = 0; n < sizeof(copyBlocks[q]); n++){
            bitWrite(copyBlocks[q][n], j-1, bitRead(copyBlocks[q][n], j));
            bitWrite(copyBlocks[q][n], j, 0);
          }
        }
      }
      checkFullRow = 0;
    } 
    checkFullRow = 0;
  }
}
//---------------------------------------------------------|
//                      Collision Functions                |
//---------------------------------------------------------|
boolean downwardCollision(){
  for(int p = 0; p < 4; p++){
    if(blockY + blocks[randBlock][orientation][p][Y] < 0)
      return true;
    if (blockY+ blocks[randBlock][orientation][p][Y] > 7){
      if(bitRead(stationaryBlocks[0][blockX- blocks[randBlock][orientation][p][X]], blockY-8 + blocks[randBlock][orientation][p][Y]))
        return true;
    } else{
      if(bitRead(stationaryBlocks[1][blockX- blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y]))
        return true;
    }
  }
  return false;
} // downwardCollision function end
//----------------------------------------------------------
void sidewardCollision(){
  for(int p = 0; p < 4; p++){
    // Checking for collision with walls
    if((blockX - blocks[randBlock][orientation][p][X]) >7){
      blockX--;
    }
    else if ((blockX - blocks[randBlock][orientation][p][X]) < 0){
      blockX++;    
    }
    // Checking for collision with other blocks
    if(blockY+ blocks[randBlock][orientation][p][Y] > 7){
      if (bitRead(stationaryBlocks[0][blockX-blocks[randBlock][orientation][p][X]], blockY-8 + blocks[randBlock][orientation][p][Y])){
        blockX--;
      }
      if (bitRead(stationaryBlocks[0][blockX-blocks[randBlock][orientation][p][X]], blockY-8 + blocks[randBlock][orientation][p][Y])){
        blockX+=2;
      }
    } else{
      if (bitRead(stationaryBlocks[1][blockX-blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y])){
        blockX--;
      }
      if (bitRead(stationaryBlocks[1][blockX-blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y])){
        blockX+=2;
      }
    }
  }
} // sidewardsCollision function end
//----------------------------------------------------------
void losingScreen(){
  for(int i = 0; i < 7; i++){
    losingCounter += bitRead(printBlocks[0][i], 7);
  } if (losingCounter > 6){
    memcpy(stationaryBlocks[0], losingBlocks, 8);
    memcpy(stationaryBlocks[1], losingBlocks, 8);
  } else{
    losingCounter = 0;
  }
  
}
