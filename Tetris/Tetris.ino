#define   SS1pin   48 // whatever number
#define   SS2pin   46 // whatever number
#define   dataPin     51
#define   clockPin    52

#define   moveLeftPin     37 
#define   moveRightPin    35
#define   rotateLeftPin   33
#define   rotateRightPin  31 
#define   fallFasterPin   39
byte printBlocks[8] = {
   B00000000, // x = 0
   B00000000, // x = 1
   B00000000, // x = 2
   B00000000, // x = 3 - block[x]; y = 7 + block[y] // bitSet(printBlocks[x], y 
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   };
byte stationaryBlocks[8] = {
   B00000000,
   B00000000, 
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,
   B00000000,// place blocks onto this 
  };
unsigned long lastDebounceTime[4] = {0, 0, 0, 0};
unsigned long debounceTime[4] = {0, 0, 0, 0};
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
int8_t blockY = 7;

byte maxY = 7;
byte maxX = 3;
unsigned long timeStart = 0;
unsigned long timeElapsed = 0;

int fallTime = 1000;

const byte MOVE_LEFT = 1;
const byte MOVE_RIGHT = 2;
const byte ROTATE = 1;
const byte FALL_FASTER = 1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  DDRA = B11111111; // all pins are set as outputs
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(SS1pin, OUTPUT);
  pinMode(SS2pin, OUTPUT);
  pinMode(moveLeftPin, INPUT);
  pinMode(moveRightPin, INPUT);
  pinMode(rotateLeftPin, INPUT);
  pinMode(rotateRightPin, INPUT);
  pinMode(fallFasterPin, INPUT);
  createBlock();
  drawBlock(printBlocks);
}
void loop() {
  // put your main code here, to run repeatedly:
  timeStart = millis(); // check current time
  outputColumn();   // draw column
  outputRow();      // draw row
  if((timeStart - timeElapsed) > fallTime){
    blockY--;                           // increment (move block by 1)
    if(downwardCollision()){                      // if collision
      blockY++;                         // move it back
      drawBlock(stationaryBlocks);      // draw current block to the stationaryBlock array
      createBlock();            // create a new block
    }
    copyStationary();           // copy printBlocks array into stationary blocks
    drawBlock(printBlocks);     // draw the block to print blocks
    timeElapsed = timeStart;    // set the timer once more
  }
  moveLeft();   // move left
  moveRight();  // move right
  rotate();
  fallFaster(); // fall faster
}
//---------------------------------------------------------|
//                      Output Functions                   |
//---------------------------------------------------------|
void outputRow(){
  shiftData(SS1pin, round(pow(2, rowNum)));
  rowNum++;
  if (rowNum > sizeof(printBlocks)){
    rowNum = 0;
  }
}
void outputColumn(){
  PORTA = ~printBlocks[rowNum];
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
      if(digitalRead(fallFasterPin))
        fallTime = 100;
      else
        fallTime = 1000;
    }
  lastDebounceTime[dir] = debounceTime[dir];
  }
} // checkDebounce function end 
void moveLeft(){
  if (digitalRead(moveLeftPin))
    checkDebounce(MOVE_LEFT);
}
void moveRight(){
  if (digitalRead(moveRightPin))
    checkDebounce(MOVE_RIGHT);
}
void rotate(){
  if(digitalRead(rotateLeftPin)){
    checkDebounce(ROTATE);
  }
}
void rotateRight(){
  if(digitalRead(rotateRightPin)){
    checkDebounce(ROTATE);
  }
}
void fallFaster(){
  if(digitalRead(fallFasterPin))
    checkDebounce(FALL_FASTER);
}
//---------------------------------------------------------|
//                      Block Functions                    |
//---------------------------------------------------------|
void drawBlock(byte copyBlocks[]){
  for(int p = 0; p < 4; p++){
    bitSet(copyBlocks[blockX- blocks[randBlock][orientation][p][X]], blockY + blocks[randBlock][orientation][p][Y]);
  }
}
void copyStationary(){
  // destination, source, numbytes
  memcpy(printBlocks, stationaryBlocks, 8);
}
void createBlock(){
  randBlock = random(7);
  orientation = 1;
  blockX = maxX;
  blockY = maxY;
}
void clearBlocks(){
  byte checkFullRow = 0;
  for(int i = 0; i < sizeof(stationaryBlocks); i++){
    for(int j = 0; j < 7; j++){
      checkFullRow = checkFullRow +bitRead(stationaryBlocks[i], j);    
      if (checkFullRow == 8){
        for(int b = 0; b < sizeof(stationaryBlocks); b++)
          bitClear(stationaryBlocks[b], j);
        for(int c = j; c < (sizeof(stationaryBlocks)-c); c++)
          stationaryBlocks[c] = stationaryBlocks[c+1];  
      }
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


 
