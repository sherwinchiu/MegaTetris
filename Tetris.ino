/* Title: Tetris
 * Author: Sherwin Chiu
 * Description: An easier version of tetris (with an 8x8 LED Matrix)
 * Date: 1/22/2020
 */
#define   latchPin        53 
#define   dataPin         51
#define   clockPin        52

#define   moveLeftPin     21
#define   moveRightPin    20
#define   rotatePin       19
#define   fallFasterPin   18
// Used to determine current row num, and to display to matrix
byte rowNum = 0;
byte printBlocks[8] = {
   B00000000, 
   B00000000, 
   B00000000, 
   B00000000, 
   B00000000,
   B00000000,
   B00000000,
   B00000000
   };
byte stationaryBlocks[8] = {
   B00000000,
   B00000000, 
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000
  };
byte loseArray[8] = {
   B00000000,
   B00000000, 
   B00000010, 
   B00000010, 
   B00000010, 
   B01111110, 
   B00000000, 
   B00000000 
 };
// used to determine which orientation block is
int8_t orientation = 1;
const byte Y = 1; 
const byte X = 0;
// Block Orientations
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
// Block functions used 
int randBlock = 0;
int blockX = 3;
int blockY = 7;

const byte MAX_Y = 7;
const byte MAX_X = 3;
// Button Debouncing Variables
const byte MOVE_LEFT = 0;
const byte MOVE_RIGHT = 1;
const byte ROTATE = 2;
const byte FALL_FASTER = 3;
unsigned long lastDebounceTime[4] = {0, 0, 0, 0};
unsigned long debounceTime[4] = {0, 0, 0, 0};
// Gameplay Variables
boolean inPlay = true;
unsigned long frameCounter = 0;
void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  DDRA = B11111111;                   // all pins are set as outputs
  pinMode(dataPin, OUTPUT);     
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(moveLeftPin, INPUT_PULLUP);
  pinMode(moveRightPin, INPUT_PULLUP);
  pinMode(rotatePin, INPUT_PULLUP);
  pinMode(fallFasterPin, INPUT_PULLUP);
// Setup timer interrupt
  cli();
  TCCR1A = 0;
  TCCR1B = 0;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TCNT1 = 0;
  OCR1A = 25;
  TIMSK1 |= (1 << OCIE1A);
// Input Interrupt 1
  EICRA |= (1 << ISC01) | (0 <<ISC00);
  EIMSK |= (1 << INT0);
// Input Interrupt 2
  EICRA |= (1 << ISC11) | (0 << ISC10);
  EIMSK |= (1 << INT1);
// Input Interrupt 3
  EICRA |= (1 << ISC21) | (0 << ISC20);
  EIMSK |= (1 << INT2);
// Input Interrupt 4
  EICRA |= (1 << ISC31) | (0 << ISC30);
  EIMSK |= (1<< INT3);
  sei();
  createBlock();
  drawBlock(printBlocks);
}
//--------------------------------------------
ISR (TIMER1_COMPA_vect){
  if(inPlay){
    frameCounter++;                                 // increase frame counter
    outputColumn();                                 // draw column
    outputRow();                                    // draw row
    if(frameCounter >= 500){
      frameCounter = 0;                             // reset frame counter
      blockY--;                                     // increment (move block by 1)
      if(downwardCollision()){                      // if collision on the bottom of blocks 
        blockY++;                                   // move it back
        drawBlock(stationaryBlocks);                // draw current block to the stationaryBlock array
        createBlock();                              // create a new block
      }
    }
    copyStationary();                               // copy printBlocks array into stationary blocks
    drawBlock(printBlocks);                         // draw the block to print blocks
    clearBlocks();                                  // clears row if full
    sidewardCollision();  // check for any collision on the side
  }
  else{
    loseScreen();
    outputColumn();
    outputRow();
  }
} // ISR Timer interrupt end
//--------------------------------------------
ISR (INT0_vect){
  checkDebounce(MOVE_LEFT);
} // ISR INT0 interrupt end
//------------------------------------------
ISR (INT1_vect){
  checkDebounce(MOVE_RIGHT);
} // ISR INT1 interrupt end
//-------------------------------------------
ISR (INT2_vect){
  checkDebounce(ROTATE);
} // ISR INT2 interrupt end
//-------------------------------------------
ISR (INT3_vect){
  checkDebounce(FALL_FASTER);
} // ISR INT3 interrupt end
//-------------------------------------------
void loop() {
  
} // main loop end
//---------------------------------------------------------|
//               Output Screen Functions                   |
//---------------------------------------------------------|
void outputRow(){
  shiftData(latchPin, round(pow(2, rowNum)));
  rowNum++;
  if (rowNum > sizeof(printBlocks)){
    rowNum = 0;
  }
} // outputRow function end
//----------------------------------------------------------
void outputColumn(){
  PORTA = ~printBlocks[rowNum];
} // outputColumn function end
//----------------------------------------------------------
void shiftData(byte shiftPin, byte data){
  digitalWrite(shiftPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, data);
  digitalWrite(shiftPin, HIGH);
  digitalWrite(shiftPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, 0);
  digitalWrite(shiftPin, HIGH);
} // shiftData function end
//----------------------------------------------------------
void loseScreen(){
  for(int i = 0; i < sizeof(printBlocks); i++){
    printBlocks[i] = 0; 
  }
  memcpy(printBlocks, loseArray, 8);
} // loseScreen function end
//---------------------------------------------------------|
//                      Player Functions                   |
//---------------------------------------------------------|
void checkDebounce(byte dir){
  debounceTime[dir] = millis();
  if (debounceTime[dir] - lastDebounceTime[dir] > 200){
    if(dir == MOVE_LEFT)
      moveLeft();
    else if(dir == MOVE_RIGHT)
      moveRight();
    else if(dir == ROTATE)
      rotate();
    else if(dir == FALL_FASTER)
      fallFaster();
  lastDebounceTime[dir] = debounceTime[dir];
  }
} // checkDebounce function end 
//----------------------------------------------------------
void moveLeft(){
  blockX--;
} // moveLeft function end 
//----------------------------------------------------------
void moveRight(){
  blockX++;
} // moveRight function end
//----------------------------------------------------------
void rotate(){
  orientation++;
  if (orientation == 4)
    orientation = 0;
} // rotate function end
//----------------------------------------------------------
void fallFaster(){
  blockY--;                                     // move it down one more
  if (downwardCollision()){
    blockY++;                                   // move it back
    drawBlock(stationaryBlocks);                // draw current block to the stationaryBlock array
    createBlock();                              // create a new block
  }
} // fallFaster function end
//---------------------------------------------------------|
//                      Block Functions                    |
//---------------------------------------------------------|
void copyStationary(){
  // destination, source, numbytes
  memcpy(printBlocks, stationaryBlocks, 8);
} // copyStationary function end
//----------------------------------------------------------
void drawBlock(byte copyBlocks[]){
  for(int p = 0; p < sizeof(copyBlocks[randBlock][orientation]); p++){
    bitSet(copyBlocks[blockX- blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y]);
  }
} // drawBlock function end
//----------------------------------------------------------
void createBlock(){
  randBlock = random(7);
  orientation = 1;
  blockX = MAX_X;
  blockY = MAX_Y;
  gameOver(stationaryBlocks);
} // createBlock function end
//----------------------------------------------------------
void clearBlocks(){
  int fullRow = 0;
  for(int i = 0; i < sizeof(stationaryBlocks); i++){
    for(int j = 0; j < 8; j++){
      fullRow += bitRead(stationaryBlocks[j], i);  
      if (fullRow >= 8){
        for(int b = 0; b < sizeof(stationaryBlocks); b++){
          bitClear(printBlocks[b],i);
          bitClear(stationaryBlocks[b], i);
          for(int r = 0; r < 8-i; r++){
            if(bitRead(stationaryBlocks[b],i+r)){
              bitClear(stationaryBlocks[b],i+r);
              bitSet(stationaryBlocks[b],i);
            } 
          }
        } 
      }
    }
    fullRow = 0;
  }
} // clearBlocks function end 
//---------------------------------------------------------|
//                      Collision Functions                |
//---------------------------------------------------------|
boolean downwardCollision(){
  for(int p = 0; p < 4; p++){
    if(blockY + blocks[randBlock][orientation][p][Y] < 0)
      return true;
    if(bitRead(stationaryBlocks[blockX- blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y]))
      return true;
  }
  return false;
} // downwardCollision function end
//----------------------------------------------------------
void sidewardCollision(){
  for(int p = 0; p < 4; p++){
    // Checking for collision with walls
    if((blockX- blocks[randBlock][orientation][p][X]) >7)
      blockX--;
    else if ((blockX- blocks[randBlock][orientation][p][X]) < 0)
      blockX++;      
    // Checking for collision with other blocks
    if (bitRead(stationaryBlocks[blockX-blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y]))
      blockX--;
    else if (bitRead(stationaryBlocks[blockX-blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y]))
      blockX++;
  }
} // sidewardsCollision function end
//----------------------------------------------------------
void gameOver(byte copyBlocks[]){
  for(int p = 0; p < 4; p++){
    if(bitRead(copyBlocks[blockX- blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y])){
      inPlay = false;
      Serial.println("You lose!");
    }
  }
} // gameOver function end
