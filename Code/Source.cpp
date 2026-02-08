
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>


using namespace sf;
using namespace std;


//class Level;
//class Player;
//class Tails;
//class Knuckles;
//class Score;
//class Bullet;
//class Enemy; 
//class EnemyManager;
//class BatBrain;
//class BeeBot;
//class Crabmeat;
//class MotoBug;
//class RingManager;
//class ObstacleManager;
//class ItemManager;
//class BoosterManager;
//class GameMechanics;
//class Game;
//class LevelTimer;
//class AudioManager;
//

class GameMechanics {
public:
    static const int WIN_W;
    static const int WIN_H;
    static const int CELL;
    static const int ROWS;
    static const int WORLD_H;
    static const int V_OFFSET;
    static const int SCORE_PER_LEVEL;
    static const int MAX_LEVELS;
    static const float TERM_V;
    static const float JUMP_V;
    static const int RAW_W;
    static const int RAW_H;
    static const int FRAME_W;
    static const int FRAME_H;
    static const int VISIBLE_FRAMES;
    static const int FRAME_DELAY;
    static const float FOLLOW_LERP_FACTOR;
    static const float FOLLOWER_SPACING;
    static const int TAILS_FLY_FRAMES;
    static const int TAILS_FLY_FRAME_DELAY;
    static const float KNUCKLES_BREAK_COOLDOWN;
    static const float KNUCKLES_REACH;
    static const int BAT_SPEED_PIXELS_PER_FRAME;
    static const int BAT_ANIM_FRAMES;
    static const int BAT_FRAME_WIDTH;
    static const int BAT_FRAME_HEIGHT;
    static const int BAT_ANIM_DELAY;
    static const int MAX_BAT_BULLETS;
    static const int BAT_RANDOM_SHOOT_MIN_FRAMES;
    static const int BAT_RANDOM_SHOOT_MAX_FRAMES;
    static const int BEEBOT_SPEED_PIXELS_PER_FRAME;
    static const int BEEBOT_MIN_Y_ROW;
    static const int BEEBOT_MAX_Y_ROW;
    static const int BEEBOT_SHOOT_INTERVAL_FRAMES;
    static const int MAX_BEEBOT_BULLETS;
    static const int CRABMEAT_SPEED_PIXELS_PER_FRAME;
    static const int CRABMEAT_ANIM_DELAY;
    static const int CRABMEAT_ANIM_FRAMES;
    static const int MAX_CRABMEAT_BULLETS;
    static const int CRAB_SHOOT_INTERVAL_FRAMES;
    static const float CRAB_PROJ_INITIAL_VY;
    static const float CRAB_PROJ_INITIAL_VX;
    static const int MOTOBUG_VERTICAL_SPEED;
    static const int MOTOBUG_HORIZONTAL_SPEED;
    static const int MOTOBUG_MIN_Y_ROW;
    static const int MOTOBUG_MAX_Y_ROW;
    static const int MOTOBUG_SHOOT_INTERVAL_FRAMES;
    static const int MAX_MOTOBUG_BULLETS;
    static const int MOTOBUG_BULLET_SPEED;
    static const int BULLET_SPEED_PIXELS_PER_FRAME;
    static const float BULLET_GRAVITY;
    static const int MAX_LIFE_HEALTH;
    static const int ENEMY_DEFAULT_HEALTH;
    static const int MAX_ENEMIES;
    static const int EGG_STINGER_HEALTH;
    static const float EGG_STINGER_ATTACK_INTERVAL_SECONDS;
    static const float EGG_STINGER_DIVE_SPEED;
    static const float EGG_STINGER_PATROL_SPEED;
    static const int EGG_STINGER_PATROL_Y_ROW;
    static const int EGG_STINGER_TARGET_ROW;
    static const int EGG_STINGER_BOSS_AREA_COLS;
    static const int EGG_STINGER_FRAME_WIDTH;
    static const int EGG_STINGER_FRAME_HEIGHT;
    static const int EGG_STINGER_ANIM_FRAMES;
    static const int EGG_STINGER_ANIM_DELAY_MS;
    static const float PLAYER_BOUNCE_VX;
    static const float PLAYER_BOUNCE_VY;
    static int sharedHealth;
    static int sharedLifeHealth[3];
    static int sharedCurrentLifeIndex;
    static void initializeHealth(int lives);
    static void initializeHealth();
    static int getHealth();
    static int getLives();
    static void applyDamage(int amount);
    static bool loseLife();

    static int getCurrentLevelCols(int levelNum);
    static float getCurrentLevelAcc(int levelNum);
    static float getCurrentLevelGravity(int levelNum);
};
// Initalizing the static values outside the class
const int GameMechanics::WIN_W = 1600;
const int GameMechanics::WIN_H = 900;
const int GameMechanics::CELL = 64;
const int GameMechanics::ROWS = 14;
const int GameMechanics::WORLD_H = GameMechanics::ROWS * GameMechanics::CELL;
const int GameMechanics::V_OFFSET = GameMechanics::WIN_H - GameMechanics::WORLD_H;
const int GameMechanics::SCORE_PER_LEVEL = 1800; ///////////////////////-------------->>>   Score 
const int GameMechanics::MAX_LEVELS = 4;


const float GameMechanics::TERM_V = 20.f;
const float GameMechanics::JUMP_V = -30.f;


const int GameMechanics::RAW_W = 24;
const int GameMechanics::RAW_H = 35;
const int GameMechanics::FRAME_W = 32;
const int GameMechanics::FRAME_H = 40;
const int GameMechanics::VISIBLE_FRAMES = 5;
const int GameMechanics::FRAME_DELAY = 6;


const float GameMechanics::FOLLOW_LERP_FACTOR = 0.15f;
const float GameMechanics::FOLLOWER_SPACING = 5.0f;


const int GameMechanics::TAILS_FLY_FRAMES = 4;
const int GameMechanics::TAILS_FLY_FRAME_DELAY = 5;


const float GameMechanics::KNUCKLES_BREAK_COOLDOWN = 0.15f;
const float GameMechanics::KNUCKLES_REACH = 5.0f;


const int GameMechanics::BAT_SPEED_PIXELS_PER_FRAME = 4;
const int GameMechanics::BAT_ANIM_FRAMES = 8;
const int GameMechanics::BAT_FRAME_WIDTH = 49;
const int GameMechanics::BAT_FRAME_HEIGHT = 43;
const int GameMechanics::BAT_ANIM_DELAY = 5;
const int GameMechanics::MAX_BAT_BULLETS = 10;
const int GameMechanics::BAT_RANDOM_SHOOT_MIN_FRAMES = 120;
const int GameMechanics::BAT_RANDOM_SHOOT_MAX_FRAMES = 300;


const int GameMechanics::BEEBOT_SPEED_PIXELS_PER_FRAME = 3;
const int GameMechanics::BEEBOT_MIN_Y_ROW = 2;
const int GameMechanics::BEEBOT_MAX_Y_ROW = 6;
const int GameMechanics::BEEBOT_SHOOT_INTERVAL_FRAMES = 300;
const int GameMechanics::MAX_BEEBOT_BULLETS = 5;


const int GameMechanics::CRABMEAT_SPEED_PIXELS_PER_FRAME = 2;
const int GameMechanics::CRABMEAT_ANIM_DELAY = 15;
const int GameMechanics::CRABMEAT_ANIM_FRAMES = 2;
const int GameMechanics::MAX_CRABMEAT_BULLETS = 3;
const int GameMechanics::CRAB_SHOOT_INTERVAL_FRAMES = 180;
const float GameMechanics::CRAB_PROJ_INITIAL_VY = -15.0f;
const float GameMechanics::CRAB_PROJ_INITIAL_VX = 7.0f;


const int GameMechanics::MOTOBUG_VERTICAL_SPEED = 3;
const int GameMechanics::MOTOBUG_HORIZONTAL_SPEED = 2;
const int GameMechanics::MOTOBUG_MIN_Y_ROW = 1;
const int GameMechanics::MOTOBUG_MAX_Y_ROW = 10;
const int GameMechanics::MOTOBUG_SHOOT_INTERVAL_FRAMES = 120;
const int GameMechanics::MAX_MOTOBUG_BULLETS = 4;
const int GameMechanics::MOTOBUG_BULLET_SPEED = 8;


const int GameMechanics::BULLET_SPEED_PIXELS_PER_FRAME = 5;
const float GameMechanics::BULLET_GRAVITY = 0.5f;


const int GameMechanics::MAX_LIFE_HEALTH = 10;
const int GameMechanics::ENEMY_DEFAULT_HEALTH = 3;
const int GameMechanics::MAX_ENEMIES = 5;


const int GameMechanics::EGG_STINGER_HEALTH = 10;
const float GameMechanics::EGG_STINGER_ATTACK_INTERVAL_SECONDS = 2.0f;
const float GameMechanics::EGG_STINGER_DIVE_SPEED = 15.0f;
const float GameMechanics::EGG_STINGER_PATROL_SPEED = 4.0f;
const int GameMechanics::EGG_STINGER_PATROL_Y_ROW = 3;
const int GameMechanics::EGG_STINGER_TARGET_ROW = 10;
const int GameMechanics::EGG_STINGER_BOSS_AREA_COLS = 30;
const int GameMechanics::EGG_STINGER_FRAME_WIDTH = 96;
const int GameMechanics::EGG_STINGER_FRAME_HEIGHT = 96;
const int GameMechanics::EGG_STINGER_ANIM_FRAMES = 2;
const int GameMechanics::EGG_STINGER_ANIM_DELAY_MS = 100;

const float GameMechanics::PLAYER_BOUNCE_VX = 8.0f;
const float GameMechanics::PLAYER_BOUNCE_VY = -12.0f;


int GameMechanics::sharedHealth = 3;
int GameMechanics::sharedLifeHealth[3] = {
    GameMechanics::MAX_LIFE_HEALTH,
    GameMechanics::MAX_LIFE_HEALTH,
    GameMechanics::MAX_LIFE_HEALTH
};
// intilizing the health 
int GameMechanics::sharedCurrentLifeIndex = GameMechanics::sharedHealth > 0 ? GameMechanics::sharedHealth - 1 : 0;




void GameMechanics::initializeHealth(int lives) {
    sharedHealth = lives;
    for (int i = 0; i < 3; ++i) { // 3 live of all the players 

        sharedLifeHealth[i] = MAX_LIFE_HEALTH;

    }



    if (sharedHealth > 0 && sharedHealth <= 3) {

        sharedCurrentLifeIndex = sharedHealth - 1;

    }

    else if (sharedHealth > 3) {

        sharedCurrentLifeIndex = 2;

    }
    else {

        sharedCurrentLifeIndex = 0;

    }

}

void GameMechanics::initializeHealth() {
    sharedHealth = 3; // Default to 3 lives

    for (int i = 0; i < 3; ++i) {

        sharedLifeHealth[i] = MAX_LIFE_HEALTH;

    }

    sharedCurrentLifeIndex = sharedHealth - 1; // Index for the 3rd life (0, 1, 2)

}

int GameMechanics::getHealth() {

    if (sharedCurrentLifeIndex >= 0 && sharedCurrentLifeIndex < 3 && sharedHealth > 0) {

        return sharedLifeHealth[sharedCurrentLifeIndex];
    }

    return 0;


}

int GameMechanics::getLives() {



    return sharedHealth;

}

void GameMechanics::applyDamage(int amount) {

    if (sharedCurrentLifeIndex >= 0 && sharedCurrentLifeIndex < 3 && sharedHealth > 0) {

        sharedLifeHealth[sharedCurrentLifeIndex] -= amount;

        if (sharedLifeHealth[sharedCurrentLifeIndex] < 0) {


            sharedLifeHealth[sharedCurrentLifeIndex] = 0;


        }


    }

}

bool GameMechanics::loseLife() {

    if (sharedHealth > 0) {

        sharedHealth--;

        if (sharedHealth > 0) {


            sharedCurrentLifeIndex = sharedHealth - 1;


            return true;
        }
        else {
            // No lives left
            sharedCurrentLifeIndex = 0;


            if (sharedCurrentLifeIndex < 3 && sharedCurrentLifeIndex >= 0) // boundary check

                sharedLifeHealth[sharedCurrentLifeIndex] = 0;


            return false;

        }

    }

    return false;
}



int GameMechanics::getCurrentLevelCols(int levelNum) {


    switch (levelNum) {


    case 1:

        return 300;

    case 2:

        return 250;

    case 3:

        return 300;

    case 4:

        return 150;

    default:

        return 300;
    }
}

float GameMechanics::getCurrentLevelAcc(int levelNum) {

    switch (levelNum) {

    case 1:
        return 2.0f;
    case 2:
        return 0.5f;

    case 3:
        return 2.0f;
    case 4:
        return 2.0f;
    default:

        return 2.0f;
    }
}



// PLayer gravity according to each lvl
float GameMechanics::getCurrentLevelGravity(int levelNum) {
    switch (levelNum) {
    case 1:
        return 2.0f;
    case 2:
        return 2.0f;
    case 3:

        return 2.0f;
    case 4:


        return 1.35f;
    default:

        return 2.0f;
    }
}
class LevelTimer {


private:
    float timeLimit;
    float elapsedTime;  // The time that has passed in the level

public:


    LevelTimer(float limit) : timeLimit(limit), elapsedTime(0.0f) {}

    void update(float deltaTime) {
        elapsedTime += deltaTime;
    }

    bool isTimeUp() const {
        return elapsedTime >= timeLimit;
    }

    float getRemainingTime() const {
        return timeLimit - elapsedTime;
    }

    void reset() {
        elapsedTime = 0.0f;
    }
};
class AudioManager {
public:
    AudioManager() : currentlyPlayingLevelMusic(-1) {

        if (GameMechanics::MAX_LEVELS > 0) musicFilePaths[0] = "Data/labrynth.ogg";


        if (GameMechanics::MAX_LEVELS > 1) musicFilePaths[1] = "Data/Ice.ogg";


        if (GameMechanics::MAX_LEVELS > 2) musicFilePaths[2] = "Data/Egg.ogg";


        if (GameMechanics::MAX_LEVELS > 3) musicFilePaths[3] = "Data/Boss.ogg";



        // Load sound effects
        if (!loadSoundEffect(sb_damage, sound_damage, "Data/Spikes.wav")) {
          
        }
        if (!loadSoundEffect(sb_levelComplete, sound_levelComplete, "Data/level_complete.wav")) {
          
        }
        if (!loadSoundEffect(sb_charSwitch, sound_charSwitch, "Data/Switch.wav")) {
          
        }
        if (!loadSoundEffect(sb_ringCollect, sound_ringCollect, "Data/Ring.wav")) {
          
        }



        setMusicVolume(50.0f);
        setSoundEffectsVolume(75.0f);
    }

    ~AudioManager() {
        stopCurrentMusic();
    }

    // --- Music Control ---
    void playMusicForLevel(int levelNumber) {

        if (levelNumber < 1 || levelNumber > GameMechanics::MAX_LEVELS) {


            stopCurrentMusic();

            return;
        }

        if (currentlyPlayingLevelMusic == levelNumber && backgroundMusic.getStatus() == Music::Playing) {

            return;
        }

        stopCurrentMusic();
        string& musicPath = musicFilePaths[levelNumber - 1];

        if (!backgroundMusic.openFromFile(musicPath)) {


            currentlyPlayingLevelMusic = -1;

            return;
        }

        backgroundMusic.setLoop(true);

        backgroundMusic.play();

        currentlyPlayingLevelMusic = levelNumber;


    }

    void stopCurrentMusic() {
        if (backgroundMusic.getStatus() != Music::Stopped) {

            backgroundMusic.stop();

        }
        currentlyPlayingLevelMusic = -1;
    }

    void setMusicVolume(float volume) {

        if (volume < 0.0f)
            volume = 0.0f;

        if (volume > 100.0f)
            volume = 100.0f;

        backgroundMusic.setVolume(volume);
    }

    // Sound Effects Playback 
    void playDamageSound() {

        if (sound_damage.getBuffer()) {

            sound_damage.play();

        }

    }

    void playLevelCompleteSound() {

        if (sound_levelComplete.getBuffer()) {
            sound_levelComplete.play();
        }
        else {

        }
    }

    void playCharacterSwitchSound() {
        if (sound_charSwitch.getBuffer()) {
            sound_charSwitch.play();
        }
        else {

        }
    }

    void playRingCollectSound() {
        if (sound_ringCollect.getBuffer()) {

            sound_ringCollect.play();

        }
        else {

        }
    }

    void setSoundEffectsVolume(float volume) {

        if (volume < 0.0f)
            volume = 0.0f;
        if (volume > 100.0f)
            volume = 100.0f;

        sound_damage.setVolume(volume);

        sound_levelComplete.setVolume(volume);

        sound_charSwitch.setVolume(volume);

        sound_ringCollect.setVolume(volume);
    }

private:

    Music backgroundMusic;

    string musicFilePaths[GameMechanics::MAX_LEVELS];


    int currentlyPlayingLevelMusic;

    SoundBuffer sb_damage;


    SoundBuffer sb_levelComplete;

    SoundBuffer sb_charSwitch;

    SoundBuffer sb_ringCollect;

    Sound sound_damage;

    Sound sound_levelComplete;


    Sound sound_charSwitch;

    Sound sound_ringCollect;


    bool loadSoundEffect(SoundBuffer& buffer, Sound& sound, const  string& filePath) {

        if (!buffer.loadFromFile(filePath)) {


            return false;
        }
        sound.setBuffer(buffer);
        return true;
    }
};

// Level design for each level 
class Level {

private:

    char** grid;

    Texture b1T, b2T, b3T, bgT, crystalT;

    Texture b4T, b5T;


    Sprite b1, b2, b3, bg, crystal;

    Sprite b4, b5;
    // Function having different layouts for dif/ernt levels 
    void loadGrid();

public:

    Level();

    ~Level();



    void loadLevel(int levelNum);

    void draw(RenderWindow& window, float camX, float remainingTime);


    bool isSolid(int row, int col) const;

    bool isSolidPx(float px, float py) const;

    bool breakTile(int row, int col);

    void loadTextures(int levelNum);

    int currentLevelNumber;

    int getCurrentLevelNumber() const {

        return currentLevelNumber;
    }
};

Level::Level() : currentLevelNumber(1) {


    grid = new char* [GameMechanics::ROWS];


    for (int r = 0; r < GameMechanics::ROWS; ++r) {

        grid[r] = new char[300] {};

    }

}

Level::~Level() {


    for (int r = 0; r < GameMechanics::ROWS; ++r) {


        delete[] grid[r];

    }

    delete[] grid;

}
void Level::loadTextures(int levelNum) {
    string default_b1Path = "Data/brick1.png";
    string default_b2Path = "Data/brick2.png";
    string default_b3Path = "Data/brick3.png";
    string default_bgPath = "Data/bg_1.png";

    string b1Path = default_b1Path;
    string b2Path = default_b2Path;
    string b3Path = default_b3Path;
    string bgPath = default_bgPath;
    string crystalPath = "Data/crystal.png";

    switch (levelNum) {
    case 2:
        b1Path = "Data/brick1_2.png";
        b2Path = "Data/brick2_2.png";
        b3Path = "Data/brick3_2.png";
        bgPath = "Data/bg_2.png";

        break;
    case 3:
        b1Path = "Data/brick1_3.png";
        b2Path = "Data/brick2_3.png";
        b3Path = "Data/brick3_3.png";
        bgPath = "Data/bg_3.png";

        break;
    case 4:
        b1Path = "Data/brick1_4.png";
        b2Path = "Data/brick2_4.png";
        b3Path = "Data/brick3_4.png";
        bgPath = "Data/bg_4.png";

        break;

    }


    if (!b1T.loadFromFile(b1Path)) { 
       
        if (!b1T.loadFromFile(default_b1Path)) { 
          
        }
    }
    b1.setTexture(b1T);

   
    if (!b2T.loadFromFile(b2Path)) {
       
        if (!b2T.loadFromFile(default_b2Path)) {
           
        }
    }
    b2.setTexture(b2T);


    if (!b3T.loadFromFile(b3Path)) {
      
        if (!b3T.loadFromFile(default_b3Path)) {
           
        }
    }
    b3.setTexture(b3T);

  
    if (!bgT.loadFromFile(bgPath)) {
       
        if (!bgT.loadFromFile(default_bgPath)) {
           
        }
    }
    bg.setTexture(bgT);

   
    if (!crystalT.loadFromFile(crystalPath)) {
      
    }
    crystal.setTexture(crystalT);

}
void Level::loadLevel(int levelNum) {

    if (levelNum < 1 || levelNum > GameMechanics::MAX_LEVELS) {

        currentLevelNumber = 1;
    }
    else {


        currentLevelNumber = levelNum;


    }
    currentLevelNumber = levelNum;
    loadTextures(currentLevelNumber);
    loadGrid();
}


void Level::loadGrid() {

    for (int r = 0; r < GameMechanics::ROWS; ++r) {

        for (int c = 0; c < GameMechanics::getCurrentLevelCols(currentLevelNumber); ++c) {

            grid[r][c] = 'g';
        }
    }
    for (int c = 0; c < GameMechanics::getCurrentLevelCols(currentLevelNumber); ++c) {

        grid[0][c] = '1';

    }
    for (int r = 0; r < GameMechanics::ROWS; ++r) {

        grid[r][0] = '1';

    }

    if (currentLevelNumber == 1) {

        for (int c = 0; c < GameMechanics::getCurrentLevelCols(currentLevelNumber); ++c)
        {

            grid[11][c] = '1';

            grid[12][c] = '2';

            grid[13][c] = '3';
        }

       
        int vPos[] = { 15, 40, 96 };
        for (int p : vPos) { if (p < GameMechanics::getCurrentLevelCols(currentLevelNumber)) { grid[9][p] = '1'; grid[10][p] = '1'; } }
        int hPos[] = { 20,25,65,79,84,92,100 };
        for (int i = 0; i < 7; i++) { int row = (i == 2 || i == 5) ? 8 : (i == 3 || i == 6) ? 7 : 9; for (int k = 0; k < 3; k++) { if (hPos[i] + k < GameMechanics::getCurrentLevelCols(currentLevelNumber)) grid[row][hPos[i] + k] = '1'; } }
        int crystalCols[] = { 25, 55, 85, 105 };
        for (int c : crystalCols) { if (c < GameMechanics::getCurrentLevelCols(currentLevelNumber)) grid[10][c] = 'c'; }

        for (int i = 0;i < 18;i++)
            grid[8][i + 100] = '1';


        grid[9][122] = '1';
        grid[9][123] = '1';
        grid[9][124] = '1';

        grid[8][126] = '1';
        grid[8][127] = '1';
        grid[8][128] = '1';


        grid[7][130] = '1';
        grid[7][131] = '1';
        grid[7][132] = '1';

        grid[7][134] = '1';
        grid[7][135] = '1';
        grid[7][136] = '1';

        grid[6][138] = '1';
       
        grid[6][139] = '1';
        grid[6][140] = '1';

        grid[10][53] = '1';

        grid[10][155] = '1';

        grid[9][155] = '1';

        grid[8][155] = '1';


        for (int i = 0; i < 5;i++)
            grid[8][153 + i] = '1';



        grid[10][161] = '1';

        grid[9][161] = '1';

        grid[8][161] = '1';

        grid[7][161] = '1';

        for (int i = 0; i < 5;i++)
            grid[7][159 + i] = '1';




        grid[10][167] = '1';

        grid[9][167] = '1';

        grid[8][167] = '1';

        grid[7][167] = '1';

        grid[6][167] = '1';

        for (int i = 0; i < 5;i++)
            grid[6][165 + i] = '1';



        grid[10][174] = '1';

        grid[9][174] = '1';

        grid[8][174] = '1';

        grid[7][174] = '1';

        grid[6][174] = '1';

        grid[5][174] = '1';



        for (int i = 0; i < 5;i++)
            grid[5][172 + i] = '1';









        grid[10][182] = '1';

        grid[9][182] = '1';

        grid[8][182] = '1';

        grid[7][182] = '1';

        grid[6][182] = '1';

        for (int i = 0; i < 5;i++)
            grid[6][180 + i] = '1';






        grid[10][190] = '1';

        grid[9][190] = '1';

        grid[8][190] = '1';

        grid[7][190] = '1';

        for (int i = 0; i < 5;i++)
            grid[7][188 + i] = '1';



    }
    else if (currentLevelNumber == 2) {
       
        for (int c = 0; c < GameMechanics::getCurrentLevelCols(currentLevelNumber); ++c)
        {
            if (c > 35 && c < 55)
                continue;
            grid[11][c] = '1';
            grid[12][c] = '2';
            grid[13][c] = '3';
        }
        grid[10][35] = '1';
        grid[10][36] = '1';
        grid[9][36] = '1';
        grid[9][37] = '1';
        grid[8][37] = '1';
        grid[8][38] = '1';
        grid[7][38] = '1';
        grid[7][39] = '1';
        grid[6][39] = '1';
        grid[6][40] = '1';
        grid[10][60] = '1';
        grid[10][59] = '1';
        grid[9][59] = '1';
        grid[9][58] = '1';
        grid[8][58] = '1';
        grid[8][57] = '1';
        grid[7][57] = '1';
        grid[7][56] = '1';
        grid[6][56] = '1';
        grid[6][55] = '1';
        grid[7][95] = '2';
        grid[7][96] = '2';
        grid[7][97] = '2';
        for (int i = 5; i <= 10; i++) grid[i][95] = '1';
        for (int i = 5; i <= 10; i++) grid[i][94] = '2';
        for (int i = 95; i < 102; i++) grid[5][i] = '1';
        for (int i = 94; i < 101; i++) grid[6][i] = '1';
        for (int i = 5; i <= 10; i++) grid[i][101] = '1';
        for (int i = 5; i <= 10; i++) grid[i][102] = '2';


        for (int i = 3; i < 9; i++)
        {
            grid[i][105 + i] = '1';
        }


        for (int i = 3; i < 9; i++)
        {
            grid[i][105 + 9 + i] = '1';
        }


        for (int i = 0; i < 3; i++)

        {
            grid[9][125 + i] = '1';
        }

        for (int i = 0; i < 3; i++)

        {
            grid[7][125 + 3 + i] = '1';
        }

        for (int i = 0; i < 3; i++)

        {
            grid[5][125 + 6 + i] = '1';
        }


        for (int i = 0; i < 3; i++)

        {
            grid[3][125 + 9 + i] = '1';
        }





        for (int i = 150; i < 190; i++) {
            grid[9][i] = '1';
            grid[10][i] = '1';
            grid[6][i] = '1';

            grid[3][i] = '1';




        }

        grid[8][191] = '1';
        grid[8][192] = '1';
        grid[8][193] = '1';

        grid[7][194] = '1';
        grid[7][195] = '1';
        grid[7][196] = '1';



        grid[8][155] = 'c';

        grid[8][160] = 'c';

        grid[8][165] = 'c';

        grid[8][170] = 'c';

        grid[8][175] = 'c';

        grid[8][180] = 'c';


        grid[5][155 + 3] = 'c';

        grid[5][160 + 4] = 'c';

        grid[5][165 + 3] = 'c';

        grid[5][170 + 4] = 'c';

        grid[5][175 + 3] = 'c';

        grid[5][180 + 4] = 'c';


        grid[2][155 + 2] = 'c';

        grid[2][160 + 2] = 'c';

        grid[2][165 + 6] = 'c';

        grid[2][170 + 3] = 'c';

        grid[2][175 + 7] = 'c';

        grid[2][180 - 1] = 'c';

        for (int i = 5; i < 30; i += 5) {
            grid[10][i] = 'c';
        }


        int crystalCols[] = { 25, 55, 85, 105,330,40,70 };
        for (int c : crystalCols) {

            if (c < GameMechanics::getCurrentLevelCols(currentLevelNumber))


                grid[10][c] = 'c';
        }
    }
    else if (currentLevelNumber == 3) {





       
        for (int c = 0; c < GameMechanics::getCurrentLevelCols(currentLevelNumber); ++c) {
            if (c > 260 && c < 286)
                continue;

            grid[13][c] = '3';
        }


        grid[12][21] = '1';
        grid[12][22] = '1';
        grid[12][23] = '1';
        grid[11][23] = '1';
        grid[11][24] = '1';
        grid[11][25] = '1';
        grid[10][25] = '1';
        grid[10][26] = '1';
        grid[10][27] = '1';
        grid[9][27] = '1';
        grid[9][28] = '1';
        grid[9][29] = '1';
        grid[8][29] = '1';
        grid[8][30] = '1';
        grid[7][31] = '1';
        grid[7][32] = '1';
        grid[6][33] = '1';
        grid[6][34] = '1';
        grid[6][35] = '1';
        grid[5][35] = '1';
        grid[5][36] = '1';
        grid[5][37] = '1';
        grid[4][37] = '1';
        grid[4][38] = '1';
        grid[4][39] = '1';
        grid[4][39] = '1';
        grid[4][40] = '1';
        grid[4][41] = '1';
        grid[5][41] = '1';
        grid[5][42] = '1';
        grid[5][43] = '1';
        grid[6][43] = '1';
        grid[6][44] = '1';
        grid[6][45] = '1';
        grid[7][45] = '1';
        grid[7][46] = '1';
        grid[7][47] = '1';
        grid[8][47] = '1';
        grid[8][48] = '1';
        grid[8][49] = '1';
        grid[9][49] = '1';
        grid[9][50] = '1';
        grid[9][51] = '1';
        grid[10][51] = '1';
        grid[10][52] = '1';
        grid[10][53] = '1';
        grid[11][53] = '1';
        grid[11][54] = '1';
        grid[11][55] = '1';
        grid[12][55] = '1';
        grid[12][56] = '1';
        grid[12][57] = '1';
        for (int i = 0; i < 16; i++) grid[8][31 + i] = '1';
        for (int i = 0; i < 12; i++) grid[6][34 + i] = '1';
        for (int i = 0; i < 25; i++) grid[10][27 + i] = '1';
        for (int i = 7; i <= 12; i++) grid[i][58] = '2';
        for (int i = 0; i < 7; i++) { grid[7][58 + i] = '1'; grid[12][58 + i] = '1'; }
        for (int i = 7; i <= 12; i++) grid[i][65] = '2';
        for (int i = 1; i <= 7; i++) grid[i][65] = '2';
        for (int i = 0; i < 7; i++) { grid[1][65 + i] = '1'; grid[7][65 + i] = '1'; }
        for (int i = 1; i <= 7; i++) grid[i][71] = '2';
        for (int i = 7; i <= 12; i++) grid[i][72] = '2';
        for (int i = 0; i < 7; i++) { grid[7][72 + i] = '1'; grid[12][72 + i] = '1'; }
        for (int i = 7; i <= 12; i++) grid[i][79] = '2';
        for (int i = 3; i <= 12; i++) grid[i][100] = '1';
        grid[10][97] = '1';
        grid[10][98] = '1';
        grid[10][99] = '1';
        grid[7][98] = '1';
        grid[7][99] = '1';
        grid[4][99] = '1';
        grid[10][103] = '1';
        grid[10][102] = '1';
        grid[10][101] = '1';
        grid[7][102] = '1';
        grid[7][101] = '1';
        grid[4][101] = '1';





        grid[10][105] = '1';

        grid[9][106] = '1';

        grid[8][107] = '1';

        grid[7][108] = '1';

        grid[6][109] = '1';

        grid[5][110] = '1';

        grid[4][111] = '1';

        grid[3][112] = '1';

        grid[3][113] = '1';

        grid[4][114] = '1';

        grid[5][115] = '1';

        grid[6][116] = '1';

        grid[7][117] = '1';

        grid[8][118] = '1';

        grid[9][119] = '1';














        grid[10][125] = '1';

        grid[9][126] = '1';

        grid[8][127] = '1';

        grid[7][128] = '1';

        grid[6][129] = '1';

        grid[5][130] = '1';

        grid[4][131] = '1';

        grid[3][132] = '1';

        grid[3][133] = '1';

        grid[4][134] = '1';

        grid[5][135] = '1';

        grid[6][136] = '1';

        grid[7][137] = '1';

        grid[8][138] = '1';

        grid[9][139] = '1';


        grid[12][145] = '1';

        for (int i = 0; i < 15;i++)
            grid[12][148 + i] = '1';


        for (int i = 0; i < 15;i++)
            grid[6][148 + i] = '1';


        for (int i = 0; i <= 6;i++) {
            grid[13 - i][148] = '1';
        }
        for (int i = 0; i <= 7;i++) {


            grid[13 - i][148 + 15] = '1';


        }


        for (int i = 0; i < 20;i++) {
            grid[8][170 + i] = '1';
        }



        for (int i = 0; i < 20;i++) {
            grid[12][170 + i] = '1';
        }




        for (int i = 0; i < 20;i++) {
            grid[9][190 + i] = '1';
        }



        for (int i = 0; i < 20;i++) {
            grid[12][190 + i] = '1';
        }

        for (int i = 0; i < 5;i++) {
            grid[11][215 + i] = '1';

        }




        for (int i = 0; i < 5;i++) {
            grid[10][215 + 7 + i] = '1';

        }


        for (int i = 0; i < 5;i++) {
            grid[9][215 + 7 + 7 + i] = '1';

        }


        for (int i = 0; i < 5;i++) {
            grid[8][215 + 7 + 7 + 7 + i] = '1';

        }



        for (int i = 0; i < 6;i++) {
            grid[12 - i][260 + i] = '1';
        }


        //

        for (int i = 0; i <= 6;i++) {
            grid[6 + i][280 + i] = '1';
        }

        //








    }
    else if (currentLevelNumber == 4) {
     
        for (int c = 0; c < GameMechanics::getCurrentLevelCols(currentLevelNumber); ++c) {
            if (c > 120 && c <= 150)
            {
                continue;
            }


            grid[12][c] = '2'; grid[13][c] = '3';
            grid[11][c] = '1';

            if (c > 35 && c < 40)
                //   continue;
                grid[11][c] = '1';


        } // Base floor



        for (int i = 125;i < 145;i++)
            grid[11][125 + i] = '1';





        for (int i = 0; i < 10; i++) grid[10 - i][20 + i] = '1';
        for (int i = 0; i < 3; i++) grid[12 - i][30 + i] = '1';
        grid[10][33] = '1';
        grid[10][34] = '1';
        grid[10][35] = '1';
        grid[9][36] = '1';
        grid[9][37] = '1';
        grid[9][38] = '1';
        grid[8][39] = '1';
        grid[8][40] = '1';
        grid[8][41] = '1';
        for (int i = 7; i >= 3; i--) grid[i][41] = '1';
        grid[5][43] = '1';
        grid[5][44] = '1';
        grid[5][45] = '1';
        grid[8][47] = '1';
        grid[8][48] = '1';
        grid[8][49] = '1';
        grid[10][50] = '1';
        grid[10][51] = '1';
        grid[10][52] = '1';
        for (int i = 0; i < 10; i++) { grid[1][55 + i] = '1'; grid[2][55 + i] = '1'; grid[3][55 + i] = '1'; grid[4][55 + i] = '1'; grid[5][55 + i] = '1'; grid[9][55 + i] = '1'; grid[10][55 + i] = '1'; grid[11][55 + i] = '1'; grid[12][55 + i] = '1'; }
        grid[11][66] = '1';
        grid[11][67] = '1';
        grid[9][68] = '1';
        grid[9][69] = '1';
        grid[7][70] = '1';
        grid[7][71] = '1';
        grid[5][72] = '1';
        grid[5][73] = '1';
        grid[3][74] = '1';
        grid[3][75] = '1';
        for (int i = 0; i < 5; i++) grid[3][75 + i] = '1';
        for (int i = 3; i < 6; i++) grid[i][80] = '1';
        for (int i = 0; i < 6; i++) grid[6][80 - i] = '1';
        for (int i = 6; i < 12; i++) grid[i][75] = '1';
        for (int i = 0; i < 8; i++) grid[12][75 + i] = '1';
        for (int i = 1; i < 9; i++) grid[i][83] = '1';
        for (int i = 0; i < 6; i++) grid[9][83 - i] = '1';
        grid[11][23] = '1';
        grid[10][24] = '1';
        grid[9][25] = '1';
        grid[8][26] = '1';
        grid[7][27] = '1';
        grid[6][28] = '1';
        grid[5][29] = '1';
        grid[4][30] = '1';
        grid[3][31] = '1';
        grid[3][32] = '1';
        grid[3][33] = '1';
        grid[3][34] = '1';
        grid[3][35] = '1';
        grid[3][36] = '1';
        for (int i = 0; i < 5; i++) grid[3 + i][37] = '1';
        for (int i = 0; i < 10; i++) grid[7][28 + i] = '1';


        for (int i = 0; i < 35;i++)
            grid[10][115 + i] = '1';


     
        int startBossCol = 10;

        if (startBossCol < 0) startBossCol = 0;








    }
}






bool Level::isSolid(int row, int col) const {

    if (row < 0 || row >= GameMechanics::ROWS || col < 0 || col >= GameMechanics::getCurrentLevelCols(currentLevelNumber)) {
        return false;
    }


    char cell = grid[row][col];


    return (cell == '1' || cell == 'c' || cell == '2' || cell == '3' || cell == '4' || cell == '5');

}



bool Level::isSolidPx(float px, float py) const {
    if (px < 0 || px >= GameMechanics::getCurrentLevelCols(currentLevelNumber) * GameMechanics::CELL || py < 0) {
        return false;
    }
    if (py >= GameMechanics::WORLD_H) {
        return true;
    }
    int col = static_cast<int>(px / GameMechanics::CELL);
    int row = static_cast<int>(py / GameMechanics::CELL);
    return isSolid(row, col);
}

void Level::draw(RenderWindow& window, float camX, float remainingTime) {
    int startCol = max(0, static_cast<int>(camX / GameMechanics::CELL));
    int endCol = min(GameMechanics::getCurrentLevelCols(currentLevelNumber), startCol + (GameMechanics::WIN_W / GameMechanics::CELL) + 2);

    // Draw the level grid
    for (int r = 0; r < GameMechanics::ROWS; ++r) {
        for (int c = startCol; c < endCol; ++c) {
            Sprite* s = nullptr;
            switch (grid[r][c]) {
            case '1':
                s = &b1;
                break;
            case '2':
                s = &b2;
                break;
            case '3':
                s = &b3;
                break;
            case 'g':
                s = &bg;
                break;
            case 'c':
                s = &crystal;
                break;
            case '4':
                s = &b4;
                break;
            case '5':
                s = &b5;
                break;
            }
            if (s) {

                s->setPosition(c * GameMechanics::CELL - camX, r * GameMechanics::CELL - GameMechanics::V_OFFSET);

                window.draw(*s);
            }
        }
    }

}

bool Level::breakTile(int row, int col) {
    if (row < 0 || row >= GameMechanics::ROWS || col < 0 || col >= GameMechanics::getCurrentLevelCols(currentLevelNumber)) {
        return false;
    }
    char currentTile = grid[row][col];

    if (currentTile == 'c' || currentTile == '4' || currentTile == '5' || currentTile == '1' || currentTile == '2' || currentTile == '3') {
        \

            grid[row][col] = 'g';


        return true;
    }
    return false;
}


class Player {
protected:
    float px;
    float py;
    float vx;
    float vy;
    bool facingRight;
    bool pushing;
    bool onEdge;
    bool isRolling;
    int visF;
    int tick;
    Sprite sprite;
    Texture Lstill;
    Texture Rstill;
    Texture Lrun;
    Texture Rrun;
    Texture Lpush;
    Texture Rpush;
    Texture Ledge;
    Texture Redge;
    Texture Lroll;
    Texture Rroll;
    float invTime;
    float boostTime;
    float desiredScale;
    void handleMovement(Level& level);
    void applyGravity(const Level& level);
    virtual void animate(float camX);
    void applyInvincibility();
    void applyBoostTimer();
    bool boost;
    bool forcedStill = false;
    bool forcedStillFacingRight = true;
    GameMechanics gamemechanics;
public:
    int hitX;
    int hitY;
    int pW;
    int pH;
    bool onGround;
    bool isInvincible;
    bool fellInPit;

    void handleGenericPitfall();

    void performPhysicsStep(const Level& level);

    float speed = 18.0f;
    bool checkCollisionWithBooster(float boosterX, float boosterY, float boosterW, float boosterH) const;
    Player();
    virtual ~Player() {}
    virtual string getName() const;
    virtual void update(Level& level, const Time& et);
    virtual void updateFollowing(const Player& leader, const Level& level, int followerIndex, const Time& et);
    void draw(RenderWindow& window, float camX);
    float getX() const;
    float getY() const;
    float getVx() const;
    float getVy() const;
    bool isOnGround() const;
    int getHealth() const;
    void setInvincibilityTime(float t);
    void addLife();
    void takeDamage();
    void takeBulletDamage(int amount);
    void startBoost(float s);
    bool isBoosted() const;
    bool checkCollision(float otherX, float otherY, float otherW, float otherH) const;
    bool getFacingRight() const;
    bool getIsRolling() const;
    virtual void setPosition(float newX, float newY);
    virtual void setVelocity(float newVx, float newVy);
    virtual void setForcedStill(bool still, bool faceRight);
    virtual void updateTimers();
    void handleHorizontalCollision(const Level& lvl);
    void handleVerticalCollision(const Level& lvl);


};


Player::Player() {
    px = 150;
    py = 600;
    vx = 0;
    vy = 0;
    facingRight = true;
    pushing = false;
    onEdge = false;
    isRolling = false;
    visF = 0;
    tick = 0;
    onGround = false;
    isInvincible = false;
    invTime = 0;
    boostTime = 0;
    fellInPit = false;
    desiredScale = 2.5f;
    speed = 18.0f;

    Lstill.loadFromFile("Data/0left_still.png");


    Rstill.loadFromFile("Data/0right_still.png");

    Lrun.loadFromFile("Data/0left_run.png");

    Rrun.loadFromFile("Data/0right_run.png");


    Lpush.loadFromFile("Data/0pushL.png");

    Rpush.loadFromFile("Data/0pushR.png");

    Ledge.loadFromFile("Data/0edgeL.png");
    Redge.loadFromFile("Data/0edgeR.png");
    Lroll.loadFromFile("Data/0upL.png");

    Rroll.loadFromFile("Data/0upR.png");


    sprite.setTexture(Rstill);

    sprite.setScale(desiredScale, desiredScale);
    hitX = int(8 * desiredScale);
    hitY = int(5 * desiredScale);
    pW = int(GameMechanics::RAW_W * desiredScale);
    pH = int(GameMechanics::RAW_H * desiredScale);
    boost = false;
}

void Player::performPhysicsStep(const Level& level) {

    px += vx;
    handleHorizontalCollision(level);


    py += vy;
    handleVerticalCollision(level);
}
void Player::setInvincibilityTime(float t) {


    invTime = t;

    isInvincible = (t > 0);

}
void Player::addLife() {

    if (GameMechanics::sharedHealth < 3) {

        GameMechanics::sharedHealth++;

        GameMechanics::sharedCurrentLifeIndex = GameMechanics::sharedHealth - 1;

        GameMechanics::sharedLifeHealth[GameMechanics::sharedCurrentLifeIndex] = GameMechanics::MAX_LIFE_HEALTH;

    }

}
void Player::takeDamage() {

    if (GameMechanics::sharedHealth > 0 && !isInvincible) {

        GameMechanics::sharedHealth--;


        if (GameMechanics::sharedHealth > 0) {

            GameMechanics::sharedCurrentLifeIndex = GameMechanics::sharedHealth - 1;

            GameMechanics::sharedLifeHealth[GameMechanics::sharedCurrentLifeIndex] = GameMechanics::MAX_LIFE_HEALTH;

            setInvincibilityTime(120.f);

        }
        else {

            GameMechanics::sharedCurrentLifeIndex = -1;

            setInvincibilityTime(120.f);

        }
    }
}

void Player::takeBulletDamage(int amount) {

    if (isInvincible || GameMechanics::sharedHealth <= 0)
        return;

    if (GameMechanics::sharedCurrentLifeIndex < 0)
        return;

    GameMechanics::sharedLifeHealth[GameMechanics::sharedCurrentLifeIndex] -= amount;


    if (GameMechanics::sharedLifeHealth[GameMechanics::sharedCurrentLifeIndex] <= 0) {

        takeDamage();

    }

    else {

        setInvincibilityTime(60.f);
    }

}

bool Player::checkCollision(float ox, float oy, float ow, float oh) const {

    float pl = px + hitX;

    float pr = pl + pW;

    float pt = py + hitY;


    float pb = pt + pH;

    float ol = ox;

    float orr = ox + ow;

    float ot = oy;

    float ob = oy + oh;

    return (pl < orr && pr > ol && pt < ob && pb > ot);
}

void Player::startBoost(float s) {

    if (this->getName() == "Sonic") {

        this->boostTime = s;

    }
    else if (this->getName() == "Knuckles") {
        isInvincible = false;
        float invincibilityDurationSeconds = 15.0f;
        float framesPerSecond = 60.0f;
        this->invTime = invincibilityDurationSeconds * framesPerSecond;
        this->isInvincible = true;
    }
    else if (this->getName() == "Tails") {
        this->boostTime = s;

    }

}

bool Player::isBoosted() const {

    return boostTime > 0;

}

void Player::applyInvincibility() {


    if (isInvincible) {
        invTime -= 1;
        if (invTime <= 0) {
            invTime = 0;
            isInvincible = false;
        }
    }
}

void Player::applyBoostTimer() {
    if (boostTime > 0) {
        boostTime -= 1;
        if (boostTime <= 0) {
            boostTime = 0;
            if (this->getName() == "Sonic")
                this->speed = 18.0f;
        }
    }
}

void Player::animate(float camX) {


    const  Texture* targetTex = nullptr;

    IntRect targetRect;

    bool useRunAnim = false;

    float currentScaleX = desiredScale;

    float currentScaleY = desiredScale;

    if (forcedStill) {

        targetTex = forcedStillFacingRight ? &Rstill : &Lstill;

        targetRect = IntRect(0, 0, 40, 40);

        tick = 0;

        visF = 0;

    }
    else if (isRolling) {
        targetTex = facingRight ? &Rroll : &Lroll;
        targetRect = IntRect(0, 0, 40, 40);
        currentScaleX = 3.0f;
        currentScaleY = 3.0f;
    }
    else if (onEdge) {
        targetTex = facingRight ? &Redge : &Ledge;
        targetRect = IntRect(0, 0, 40, 40);
    }
    else if (pushing) {
        targetTex = facingRight ? &Rpush : &Lpush;
        targetRect = IntRect(0, 0, 40, 40);
    }
    else if (fabs(vx) > 0.1f && onGround) {
        targetTex = facingRight ? &Rrun : &Lrun;
        useRunAnim = true;
    }
    else if (!onGround) {
        targetTex = facingRight ? &Rstill : &Lstill;
        targetRect = IntRect(0, 0, 40, 40);
        tick = 0;
        visF = 0;
    }
    else { // Standing still
        targetTex = facingRight ? &Rstill : &Lstill;
        targetRect = IntRect(0, 0, 40, 40);
        tick = 0;
        visF = 0;
    }
    if (useRunAnim && !forcedStill) {
        if (++tick >= GameMechanics::FRAME_DELAY) {
            tick = 0;
            visF = (visF + 1) % GameMechanics::VISIBLE_FRAMES;
        }
        targetRect = IntRect(visF * GameMechanics::FRAME_W, 0, 40, 40);
    }
    if (targetTex && sprite.getTexture() != targetTex) {
        sprite.setTexture(*targetTex);
    }
    sprite.setTextureRect(targetRect);
    sprite.setScale(currentScaleX, currentScaleY);
    if (isInvincible) {
        const int blinkFrames = 5;
        bool dim = (static_cast<int>(invTime) % (blinkFrames * 2) < blinkFrames);
        sprite.setColor(dim ? Color(255, 255, 255, 100) : Color::White);
    }
    else {
        sprite.setColor(Color::White);
    }
    sprite.setPosition(px - camX, py - GameMechanics::V_OFFSET);
}
bool Player::checkCollisionWithBooster(float boosterX, float boosterY, float boosterW, float boosterH) const {

    float pl = px + hitX;
    //  left position
    float pr = pl + pW;
    //  right position
    float pt = py + hitY;
    //  top position
    float pb = pt + pH;
    // bottom position



    // Booster's bounding box
    float bl = boosterX;
    float br = boosterX + boosterW;
    float bt = boosterY;
    float bb = boosterY + boosterH;

    //checking boundaRY
    return (pl < br && pr > bl && pt < bb && pb > bt);
}

void Player::handleMovement(Level& lvl) {
    bool moving = false;
    float effects = 0.0f;
    float acc = GameMechanics::getCurrentLevelAcc(lvl.getCurrentLevelNumber());
    if (this->getName() == "Sonic") {
        speed = 18.0f;
    }
    else if (this->getName() == "Knuckles") {
        speed = 12.0f;
    }
    else {
        speed = 10.0f;
    }
    if (this->getName() == "Sonic" && this->isBoosted()) {
       
        speed = 22.0f;
    }

    if (Keyboard::isKeyPressed(Keyboard::Right)) {

        vx = min(vx + acc, speed);  // Apply acceleration
        facingRight = true;
        moving = true;
    }

    // Left movement
    if (Keyboard::isKeyPressed(Keyboard::Left)) {

        vx = max(vx - acc, -speed);  // Apply acceleration

        facingRight = false;

        moving = true;
    }


    if (!moving && onGround) {
        if (vx > 0) {
            vx = max(vx - acc, 0.f);  // Smooth deceleration to 0
        }
        if (vx < 0) {
            vx = min(vx + acc, 0.f);  // Smooth deceleration to 0
        }
    }

    else if (!moving && !onGround) {
        if (vx > 0) {

            vx = max(vx - acc * 0.5f, 0.f);

        }
        if (vx < 0) {

            vx = min(vx + acc * 0.5f, 0.f);
        }
    }


    if (Keyboard::isKeyPressed(Keyboard::Up) && onGround) {

        vy = GameMechanics::JUMP_V;

        onGround = false;

    }


    isRolling = (!onGround && Keyboard::isKeyPressed(Keyboard::Up) &&
        (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::Right)));


    px += vx;
    handleHorizontalCollision(lvl);
}

void Player::handleHorizontalCollision(const Level& lvl) {

    int l = int((px + hitX) / GameMechanics::CELL);

    int r = int((px + hitX + pW) / GameMechanics::CELL);

    int t = int((py + hitY) / GameMechanics::CELL);

    int b = int((py + hitY + pH) / GameMechanics::CELL);

    pushing = false;


    for (int row = t; row <= b; ++row) {

        if (row < 0 || row >= GameMechanics::ROWS) {

            continue;
        }
        if (vx > 0 && lvl.isSolid(row, r)) {

            px = r * GameMechanics::CELL - hitX - pW - 0.1f;

            vx = 0;

            pushing = facingRight;

            break;

        }
        else if (vx < 0 && lvl.isSolid(row, l)) {
            px = (l + 1) * GameMechanics::CELL - hitX;
            vx = 0;
            pushing = !facingRight;
            break;
        }
    }

    if (px + hitX < 0) {

        px = -hitX;

        vx = 0;

    }
    else if (px + hitX + pW > GameMechanics::getCurrentLevelCols(lvl.getCurrentLevelNumber()) * GameMechanics::CELL) {

        px = GameMechanics::getCurrentLevelCols(lvl.getCurrentLevelNumber()) * GameMechanics::CELL - hitX - pW;

        vx = 0;
    }
}
void Player::handleVerticalCollision(const Level& lvl) {

    int l = int((px + hitX) / GameMechanics::CELL);

    int r = int((px + hitX + pW) / GameMechanics::CELL);

    int t = int((py + hitY) / GameMechanics::CELL);

    int b = int((py + hitY + pH) / GameMechanics::CELL);
    bool landedOnSolid = false;
    for (int c = l; c <= r; ++c) {
        if (c < 0 || c >= GameMechanics::getCurrentLevelCols(lvl.getCurrentLevelNumber())) {
            continue;
        }
        if (vy < 0 && lvl.isSolid(t, c)) {
            py = (t + 1) * GameMechanics::CELL - hitY;
            vy = 0;
        }
        else if (vy >= 0 && lvl.isSolid(b, c)) {
            py = b * GameMechanics::CELL - hitY - pH - 0.1f;
            vy = 0;
            landedOnSolid = true;
        }
    }
    onGround = landedOnSolid;

    if (onGround) {
        int rb = b + 1;
        if (rb < GameMechanics::ROWS) {
            bool gl = (l >= 0 && l < GameMechanics::getCurrentLevelCols(lvl.getCurrentLevelNumber())) ? lvl.isSolid(rb, l) : false; // Tile below left foot
            bool gr = (r >= 0 && r < GameMechanics::getCurrentLevelCols(lvl.getCurrentLevelNumber())) ? lvl.isSolid(rb, r) : false; // Tile below right foot

            onEdge = (gl && !gr) || (!gl && gr);
        }
        else {
            onEdge = false;
        }
    }
    else {
        onEdge = false;
    }
    if (py + hitY + pH > GameMechanics::WORLD_H) {

        py = GameMechanics::WORLD_H - hitY - pH;
        vy = 0;
        onGround = true;
        onEdge = false;
        fellInPit = true;

    }
}

void Player::handleGenericPitfall() {
    if (isInvincible) return;


    takeDamage();
}

void Player::applyGravity(const Level& lvl) {
    if (!onGround) {
        vy += GameMechanics::getCurrentLevelGravity(lvl.getCurrentLevelNumber());
        if (vy > GameMechanics::TERM_V) {
            vy = GameMechanics::TERM_V;
        }
    }
    py += vy;
    handleVerticalCollision(lvl); // Check collision *after* applying gravity/velocity
}

void Player::update(Level& lvl, const Time& et) {
    forcedStill = false; // Reset forced state
    applyInvincibility();
    applyBoostTimer();
    handleMovement(lvl); // Handles input and horizontal collision
    applyGravity(lvl);   // Handles gravity and vertical collision
}

void Player::draw(RenderWindow& w, float camX) {
    animate(camX);
    w.draw(sprite);
}

float Player::getX() const
{
    return px;
}
float Player::getY() const
{
    return py;
}
float Player::getVx() const
{
    return vx;
}
float Player::getVy() const
{
    return vy;
}
int Player::getHealth() const
{
    return GameMechanics::sharedHealth;
}
bool Player::getFacingRight() const
{
    return facingRight;
}
bool Player::getIsRolling() const
{
    return isRolling;
}
bool Player::isOnGround() const {
    return onGround;
}

void Player::updateFollowing(const Player& leader, const Level& level, int followerIndex, const Time& et) {
    forcedStill = false;
    facingRight = leader.getFacingRight();
    isRolling = leader.getIsRolling();


    float targetOffsetX = (GameMechanics::CELL * 0.8f) * followerIndex * (leader.getFacingRight() ? -1.0f : 1.0f);

    float leaderCenterX = leader.getX() + leader.hitX + (leader.pW / 2.0f);

    float leaderCenterY = leader.getY() + leader.hitY + (leader.pH / 2.0f);

    float targetX = leaderCenterX + targetOffsetX - (hitX + pW / 2.0f);

    float targetY = leader.getY();


    float distanceX = targetX - px;
    float distanceY = targetY - py;


    float currentLerpFactor = GameMechanics::FOLLOW_LERP_FACTOR;

    if (fabs(distanceX) > GameMechanics::WIN_W * 0.5f) currentLerpFactor *= 3.0f;

    else if (fabs(distanceX) > GameMechanics::WIN_W * 0.2f) currentLerpFactor *= 1.5f;



    vx = distanceX * currentLerpFactor;


    if (leader.getVy() < -5.0f && !leader.isOnGround() && onGround) {
        vy = GameMechanics::JUMP_V * 0.9f; // Jump slightly less high?
        onGround = false;
    }


    updateTimers();
    px += vx;

    handleHorizontalCollision(level);

    applyGravity(level);
}


void Player::setPosition(float newX, float newY) {

    px = newX;

    py = newY;

    vx = 0;

    vy = 0;

    onGround = false;
}

void Player::setForcedStill(bool still, bool faceRight) {
    forcedStill = still;
    forcedStillFacingRight = faceRight;

    if (still) {

        isRolling = false;
        vx = 0;

    }
}

void Player::updateTimers() {
    applyInvincibility();
    applyBoostTimer();
}

void Player::setVelocity(float newVx, float newVy) {
    vx = newVx;
    vy = newVy;
    if (newVy < 0) {
        onGround = false;
    }
}

string Player::getName() const { return "Sonic"; }



class Tails : public Player {
private:
    bool isFlying = false;
    float flightTimer = 0.0f;
    Texture flySheetTex;
    int flyFrame = 0;
    int flyTick = 0;
    float flyTimer = 0.0f;
    int flyFrameWidth = 0;
    int flyFrameHeight = 0;

public:
    Tails();
    void update(Level& level, const Time& et) override;
    void updateFollowing(const Player& leader, const Level& level, int followerIndex, const Time& et) override;
    string getName() const override;
    void animate(float camX) override;
    bool isCurrentlyFlying() const;
};

Tails::Tails() {
    Lstill.loadFromFile("Data/0left_still_y.png");
    Rstill.loadFromFile("Data/0right_still_y.png");
    Lrun.loadFromFile("Data/0left_run_y.png");
    Rrun.loadFromFile("Data/0right_run_y.png");
    Lpush.loadFromFile("Data/0pushL_y.png");
    Rpush.loadFromFile("Data/0pushR_y.png");
    Ledge.loadFromFile("Data/0edgeL_y.png");

    Redge.loadFromFile("Data/0edgeR_y.png");
    Lroll.loadFromFile("Data/0upL_y.png");
    Rroll.loadFromFile("Data/0upR_y.png");


    sprite.setTexture(Rstill);

    px = 120; py = 600;

    speed = 10.0f;

    boost = false;
}

void Tails::animate(float camX) {
    if (isFlying && flySheetTex.getSize().x > 0) {

        const Texture* targetTex = &flySheetTex;
        if (++flyTick >= GameMechanics::TAILS_FLY_FRAME_DELAY) {
            flyTick = 0;
            flyFrame = (flyFrame + 1) % GameMechanics::TAILS_FLY_FRAMES;
        }

        if (sprite.getTexture() != targetTex) {
            sprite.setTexture(*targetTex);
        }
        IntRect targetRect = IntRect(flyFrame * flyFrameWidth, 0, flyFrameWidth, flyFrameHeight);
        sprite.setTextureRect(targetRect);


        sprite.setOrigin(flyFrameWidth / 2.0f, flyFrameHeight / 2.0f);
        float flightScale = 2.0f;
        sprite.setScale(facingRight ? flightScale : -flightScale, flightScale);


        if (isInvincible) {
            const int blinkFrames = 5;
            bool dim = (static_cast<int>(invTime) % (blinkFrames * 2) < blinkFrames);

            sprite.setColor(dim ? Color(255, 255, 255, 100) : Color::White);
        }
        else {
            sprite.setColor(Color::White);
        }

        sprite.setPosition(px + (hitX + pW / 2.0f) - camX, py + (hitY + pH / 2.0f) - GameMechanics::V_OFFSET);

    }
    else {

        sprite.setOrigin(0, 0);
        Player::animate(camX);
    }
}






void Tails::update(Level& lvl, const Time& et) {

    forcedStill = false;

    applyInvincibility();

    applyBoostTimer();

    float dt = et.asSeconds();


    if (isFlying) {
        this->flightTimer -= dt;




        if (this->flightTimer <= 0.0f) {

            isFlying = false;
            this->flightTimer = 0.0f;
            flyFrame = 0;
            flyTick = 0;



            vy = 2.f;
            return;
        }


        vx = 0;
        vy = 0;
        const float flightSpeed = 7.0f;


        if (Keyboard::isKeyPressed(Keyboard::Up))    vy = -flightSpeed;
        if (Keyboard::isKeyPressed(Keyboard::Down))  vy = flightSpeed;
        if (Keyboard::isKeyPressed(Keyboard::Left)) { vx = -flightSpeed; facingRight = false; }
        if (Keyboard::isKeyPressed(Keyboard::Right)) { vx = flightSpeed;  facingRight = true; }


        px += vx;
        handleHorizontalCollision(lvl);
        py += vy;
        handleVerticalCollision(lvl);

        return;
    }


    if (!isFlying && !onGround) {

        vy += 2.f;


        if (onGround) {

            vy = 0;
        }
    }



    if (!isFlying && Keyboard::isKeyPressed(Keyboard::Space) && !onGround) {
        isFlying = true;
        this->flightTimer = 7.0f;
      
        if (this->isBoosted()) {
            this->flightTimer += 4.0f;
        }
     

        vy = GameMechanics::JUMP_V * 0.5f;
        flyFrame = 0;
        flyTick = 0;
      
        return;
    }


    handleMovement(lvl);
    applyGravity(lvl);
}



void Tails::updateFollowing(const Player& leader, const Level& level, int followerIndex, const Time& et) {
    forcedStill = false;

    isFlying = false;

    flightTimer = 0.0f;

    flyFrame = 0;

    flyTick = 0;

    Player::updateFollowing(leader, level, followerIndex, et);
}

string Tails::getName() const { return "Tails"; }

bool Tails::isCurrentlyFlying() const { return isFlying; }




class Knuckles : public Player {
private:
    float breakCooldown = 0.0f;

public:
    Knuckles();
    void update(Level& level, const Time& et) override;
    void updateFollowing(const Player& leader, const Level& level, int followerIndex, const Time& et) override;
    string getName() const override;


private:
    void tryBreakWall(Level& level);
};

Knuckles::Knuckles() {
    Lstill.loadFromFile("Data/0left_still_p.png");
    Rstill.loadFromFile("Data/0right_still_p.png");
    Lrun.loadFromFile("Data/0left_run_p.png");
    Rrun.loadFromFile("Data/0right_run_p.png");
    Lpush.loadFromFile("Data/0pushL_p.png");
    Rpush.loadFromFile("Data/0pushR_p.png");
    Ledge.loadFromFile("Data/0edgeL_p.png");
    Redge.loadFromFile("Data/0edgeR_p.png");
    Lroll.loadFromFile("Data/0upL_p.png");
    Rroll.loadFromFile("Data/0upR_p.png");

    sprite.setTexture(Rstill);
    px = 100; py = 600;

    breakCooldown = 0.0f;

    speed = 12.0f;
    boost = false;
}

void Knuckles::update(Level& level, const Time& et) {
    forcedStill = false;

    if (breakCooldown > 0.0f) {

        breakCooldown -= et.asSeconds();

    }


    if (Keyboard::isKeyPressed(Keyboard::Space) && breakCooldown <= 0.0f) {
        tryBreakWall(level);

    }


    Player::update(level, et);
}


void Knuckles::updateFollowing(const Player& leader, const Level& level, int followerIndex, const Time& et) {
    forcedStill = false;
    breakCooldown = GameMechanics::KNUCKLES_BREAK_COOLDOWN;

    Player::updateFollowing(leader, level, followerIndex, et);
}


void Knuckles::tryBreakWall(Level& level) {
    float checkX = px + hitX + (facingRight ? pW + GameMechanics::KNUCKLES_REACH : -GameMechanics::KNUCKLES_REACH);
    float checkY = py + hitY + (pH / 2.0f);

    int checkCol = static_cast<int>(checkX / GameMechanics::CELL);
    int checkRow = static_cast<int>(checkY / GameMechanics::CELL);

    

    if (checkRow >= 0 && checkRow < GameMechanics::ROWS && checkCol >= 0 && checkCol < GameMechanics::getCurrentLevelCols(level.getCurrentLevelNumber())) {
        if (level.breakTile(checkRow, checkCol)) {
            breakCooldown = GameMechanics::KNUCKLES_BREAK_COOLDOWN;
          
        }
        
    }
   
}

string Knuckles::getName() const { return "Knuckles"; }



class Score {
private:
    int score;
    Texture lifeIconTexture;
    Sprite lifeSprites[3];
    Font font;
    Text scoreText;
    Text levelText;
    RectangleShape currentHealthBarOutline;
    RectangleShape currentHealthBarSegments[GameMechanics::MAX_LIFE_HEALTH]; // Ensure MAX_LIFE_HEALTH is defined
    float healthBarWidth = 80.f;
    float healthBarHeight = 20.f;
    float healthBarSpacing = 8.f;
    float segmentWidth;
    Text playerNameText;


    float lifeIconScaledWidth;
    float lifeIconScaledHeight;

public:
    Score();
    void addPoints(int pts);
    void draw(RenderWindow& w, const Player& player, const string& playerName);
    int getScore() const;
    void resetScore();
    void updateLevelDisplay(int level);
    void setPlayerName(const string& name);
};

Score::Score() : score(0), lifeIconScaledWidth(0.0f), lifeIconScaledHeight(0.0f) {
    if (!lifeIconTexture.loadFromFile("Data/extra_life.png")) {
       
    }
    lifeIconTexture.setSmooth(false);

    float iconScale = 0.25f;

    for (int i = 0; i < 3; ++i) {
        lifeSprites[i].setTexture(lifeIconTexture);
        lifeSprites[i].setScale(iconScale, iconScale);

    }


    if (lifeIconTexture.getSize().x > 0 && lifeIconTexture.getSize().y > 0) {
        lifeIconScaledWidth = static_cast<float>(lifeIconTexture.getSize().x) * iconScale;
        lifeIconScaledHeight = static_cast<float>(lifeIconTexture.getSize().y) * iconScale;
    }
    else {



        float unscaledPlaceholderSizeX = 64.f;
        float unscaledPlaceholderSizeY = 64.f;
        lifeIconScaledWidth = unscaledPlaceholderSizeX * iconScale;
        lifeIconScaledHeight = unscaledPlaceholderSizeY * iconScale;
        if (lifeIconTexture.getSize().x == 0 || lifeIconTexture.getSize().y == 0) {

        }
    }

    segmentWidth = healthBarWidth / GameMechanics::MAX_LIFE_HEALTH;

    Vector2f healthBarOutlineSize(healthBarWidth, healthBarHeight);
    currentHealthBarOutline.setSize(healthBarOutlineSize);
    currentHealthBarOutline.setFillColor(Color::Transparent);
    currentHealthBarOutline.setOutlineColor(Color::White);
    currentHealthBarOutline.setOutlineThickness(1.f);

    Vector2f healthBarSegmentSize(segmentWidth, healthBarHeight);
    for (int j = 0; j < GameMechanics::MAX_LIFE_HEALTH; ++j) {
        currentHealthBarSegments[j].setSize(healthBarSegmentSize);
        currentHealthBarSegments[j].setFillColor(Color::Green);
    }

    font.loadFromFile("Data/Huglove.ttf");




    scoreText.setFont(font);

    scoreText.setCharacterSize(40);

    scoreText.setFillColor(Color::Yellow);

    scoreText.setPosition(20.f, 20.f);

    scoreText.setString("Score: 0");

    levelText.setFont(font);

    levelText.setCharacterSize(40);

    levelText.setFillColor(Color::Cyan);

    levelText.setPosition(GameMechanics::WIN_W / 2.f - 70.f, 20.f);
    levelText.setString("Level: 1");

    playerNameText.setFont(font);

    playerNameText.setCharacterSize(30);

    playerNameText.setFillColor(Color::White);

    playerNameText.setPosition(GameMechanics::WIN_W - 250.f, 20.f);
    playerNameText.setString("Player: ---");
}

void Score::addPoints(int pts) {
    score += pts;
    scoreText.setString("Score: " + to_string(score));
}

int Score::getScore() const {
    return score;
}

void Score::resetScore() {
    score = 0;
    scoreText.setString("Score: 0");
   

}

void Score::updateLevelDisplay(int level) {
    if (level > 0) {
        levelText.setString("Level: " + std::to_string(level));
    }
    else {
        levelText.setString("Level: ?");
    }
}

void Score::setPlayerName(const string& name) {

    playerNameText.setString("Player: " + name);

    playerNameText.setPosition(GameMechanics::WIN_W - 450.f, 20.f);
}

void Score::draw(RenderWindow& w, const Player& player, const string& playerName) {
    w.draw(scoreText);
    w.draw(levelText);


    setPlayerName(playerName);
    w.draw(playerNameText);

    int lives = player.getHealth();
    for (int i = 0; i < lives; ++i) {

        lifeSprites[i].setPosition(20.f + i * (lifeIconScaledWidth + 5.f), 70.f);
        w.draw(lifeSprites[i]);
    }


    if (lives > 0 && GameMechanics::sharedCurrentLifeIndex >= 0 && GameMechanics::sharedCurrentLifeIndex < lives) {

        int currentLifeSpriteVisualIndex = GameMechanics::sharedCurrentLifeIndex;

        float iconX = lifeSprites[currentLifeSpriteVisualIndex].getPosition().x;
        float iconY = lifeSprites[currentLifeSpriteVisualIndex].getPosition().y;


        float iconW = lifeIconScaledWidth;
        float iconH = lifeIconScaledHeight;

        float hbx = iconX + iconW + healthBarSpacing;
        float hby = iconY + (iconH / 2.f) - (healthBarHeight / 2.f);

        currentHealthBarOutline.setPosition(hbx, hby);
        w.draw(currentHealthBarOutline);


        int segs = GameMechanics::sharedLifeHealth[GameMechanics::sharedCurrentLifeIndex];
        if (segs < 0) segs = 0;
        if (segs > GameMechanics::MAX_LIFE_HEALTH) segs = GameMechanics::MAX_LIFE_HEALTH; // Cap at max

        float hpRatio = static_cast<float>(segs) / GameMechanics::MAX_LIFE_HEALTH;
        Color barColor = (hpRatio <= 0.3f) ? Color::Red : (hpRatio <= 0.6f) ? Color::Yellow : Color::Green;

        for (int j = 0; j < segs; ++j) {
            currentHealthBarSegments[j].setPosition(hbx + (j * segmentWidth), hby);
            currentHealthBarSegments[j].setFillColor(barColor);
            w.draw(currentHealthBarSegments[j]);
        }
    }
}

class RingManager {
public:
    RingManager();
    void update(Player& p, Score& s);
    void draw(RenderWindow& w, float camX);
    void reset(int level_number);

private:
    static const int MAX_RINGS = 100;
    Texture ringT;
    Sprite rings[MAX_RINGS];
    bool alive[MAX_RINGS];
    int pos[MAX_RINGS][2];
    int frame; int tick;
    void initializeRings(int level_number);
    AudioManager audioManager;
};

RingManager::RingManager() {
    frame = 0; tick = 0;
    ringT.loadFromFile("Data/collect.png");



    int P[MAX_RINGS][2] = {
        {500,600},{700,600},{900,500},{1200,400},{1500,600},
        {1800,550},{2000,500},{2200,600},{2500,500},{2800,600},
        {3100,600},{3400,550},{3700,500},{4000,600},{4300,550},
        {4600,500},{4900,600},{5200,600},{5500,550},{5800,500}
    };
    for (int i = 0; i < MAX_RINGS; ++i) {
        pos[i][0] = P[i][0];
        pos[i][1] = P[i][1];


        rings[i].setTexture(ringT);

        rings[i].setScale(0.5f, 0.5f);

        rings[i].setOrigin(ringT.getSize().x / 2.0f, ringT.getSize().y / 2.0f);


        alive[i] = false;
    }

}

void RingManager::initializeRings(int levelNum) {
 


    for (int i = 0; i < MAX_RINGS; ++i) {
        alive[i] = false;
    }


    int ringsPlaced = 0;
    if (levelNum == 1) {
        int level1_pos[][2] = {
            {500, 600},{900, 500}, {1200, 400}, {1500, 600},
            {1800, 550}, {2000, 500},  {2500, 500},




              {100 * 64,8 * 64 - 50},
            {161 * 64,7 * 64 - 50},
            {127 * 64,7 * 64 - 50},
            {111 * 64,8 * 64 - 50},
            {120 * 64,9 * 64 - 50},
            {130 * 64 * 64 - 50},
           {113 * 64,6 * 64 - 50},







            {155 * 64,8 * 64 - 50},
            {161 * 64,7 * 64 - 50},
            {167 * 64,6 * 64 - 50},
            {174 * 64,5 * 64 - 50},
            {182 * 64,6 * 64 - 50},
            {189 * 64,7 * 64 - 50},
            {167 * 64,6 * 64 - 50}





        };
        ringsPlaced = sizeof(level1_pos) / sizeof(level1_pos[0]);



        for (int i = 0; i < ringsPlaced && i < MAX_RINGS; ++i) {

            pos[i][0] = level1_pos[i][0];

            pos[i][1] = level1_pos[i][1];


            rings[i].setPosition((float)pos[i][0], (float)pos[i][1]);

            alive[i] = true;
        }
    }
    else if (levelNum == 2) {
        int level1_pos[][2] = {
              {400, 400}, {1500, 600},


              // bottom less pitch coinss
               {35 * 64,6 * 64 - 50},
               {55 * 64,6 * 64 - 50},
                {(55 + 97) * 64,11 * 64 - 50},
                 {(55 + 98) * 64,10 * 64 - 50},


                 //coins row of first flor  
                 {157 * 64,1 * 64 - 50},
                  {160 * 64,1 * 64 - 50},
                   {165 * 64,1 * 64 - 50},
                    {165 * 64,1 * 64 - 50},
                     {172 * 64,1 * 64 - 50},
                      {179 * 64,1 * 64 - 50},

                      // //coins row of second flor  

                   {159 * 64,4 * 64 - 50},
                  {162 * 64,4 * 64 - 50},
                   {166 * 64,4 * 64 - 50},
                    {169 * 64,4 * 64 - 50},
                     {173 * 64,4 * 64 - 50},
                      {180 * 64,4 * 64 - 50},


                      // //coins row of third flor  

                 {160 * 64,7 * 64 - 50},
                {165 * 64,7 * 64 - 50},
                 {170 * 64,8 * 64 - 50},
                  {173 * 64,7 * 64 - 50},
                   {176 * 64,8 * 64 - 50},
                    {180 * 64,8 * 64 - 50},

                    // Add more for level 1 if needed, up to MAX_RINGS
        };
        ringsPlaced = sizeof(level1_pos) / sizeof(level1_pos[0]); // Number of rings for this level

        for (int i = 0; i < ringsPlaced && i < MAX_RINGS; ++i) {

            pos[i][0] = level1_pos[i][0];

            pos[i][1] = level1_pos[i][1];

            rings[i].setPosition((float)pos[i][0], (float)pos[i][1]);

            alive[i] = true;
        }


        int level2_pixel_pos[][2] = {

             {(55 + 97) * 64, 9 * 64}, {(55 + 97) * 64, 8 * 64}, {(55 + 97) * 64 * 2,  9 * 64},


            {127 * 64,9 * 64 - 50},{130 * 64,7 * 64 - 50},{133 * 64,5 * 64 - 50},{137 * 64,3 * 64 - 50},
            {192 * 64,8 * 64 - 50},{195 * 64,7 * 64 - 50},{170 * 64,8 * 64 - 50},{220 * 64,9 * 64},{230 * 64,64 * 10},{240 * 64,9 * 64},


             {99 * 64,9 * 64},

              {97 * 64,9 * 64},

              // bottom less pitch coinss
               {37 * 64,6 * 64 - 50},
               {55 * 64,6 * 64 - 50},

               //coins row of first flor  

                {160 * 64,2 * 64 - 50},
                 {165 * 64,2 * 64 - 50},
                  {165 * 64,2 * 64 - 50},
                   {172 * 64,2 * 64 - 50},

                   // //coins row of second flor  

                {159 * 64,5 * 64 - 50},
               {162 * 64,5 * 64 - 50},

                 {169 * 64,5 * 64 - 50},

                   {180 * 64,5 * 64 - 50},


                   // //coins row of third flor  

              {160 * 64,8 * 64 - 50},

              {170 * 64,8 * 64 - 50},
               {173 * 64,8 * 64 - 50},

                 {180 * 64,8 * 64 - 50},

        };

        ringsPlaced = sizeof(level2_pixel_pos) / sizeof(level2_pixel_pos[0]);


        if (ringsPlaced > MAX_RINGS) {

            ringsPlaced = MAX_RINGS;
        }


        for (int i = 0; i < ringsPlaced; ++i) {
            pos[i][0] = level2_pixel_pos[i][0];
            pos[i][1] = level2_pixel_pos[i][1];

            rings[i].setPosition((float)pos[i][0], (float)pos[i][1]);
            alive[i] = true;
        }
    }



    else if (levelNum == 3) {
        int level1_pos[][2] = {

             {1800, 550}, {2000, 500}, {2200, 600}, {2500, 500}, {2800, 600},


               {40 * 64,64 * 3},
               {64 * 64,64 * 10},
               {70 * 64,64 * 4},
               {75 * 64,64 * 10},



                {(75 + 25) * 64,64 * 3},
                 {(75 + 38) * 64,64 * 3},
                  {(75 + 38 + 13) * 64,64 * 3},




               {152 * 64,9 * 64},{173 * 64,9 * 64}






        };
        ringsPlaced = sizeof(level1_pos) / sizeof(level1_pos[0]);

        for (int i = 0; i < ringsPlaced && i < MAX_RINGS; ++i) {
            pos[i][0] = level1_pos[i][0];
            pos[i][1] = level1_pos[i][1];
            rings[i].setPosition((float)pos[i][0], (float)pos[i][1]);
            alive[i] = true;
        }
    }
    else if (levelNum == 4) {
        int level1_pos[][2] = {

             {500, 600}, {700, 600}, {900, 500}, {1200, 400}, {1500, 600},
             {1800, 550}, {2000, 500}, {2200, 600}, {2500, 500}, {2800, 600},
       {100 * 64,9 * 64},{90 * 64,9 * 64},{95 * 64,9 * 64},{105 * 64,9 * 64},{108 * 64,9 * 64},{125 * 74,10 * 64},{130 * 74,10 * 64},{135 * 74,10 * 64},{140 * 74,10 * 64},{145 * 74,10 * 64}
        };
        ringsPlaced = sizeof(level1_pos) / sizeof(level1_pos[0]);

        for (int i = 0; i < ringsPlaced && i < MAX_RINGS; ++i) {
            pos[i][0] = level1_pos[i][0];
            pos[i][1] = level1_pos[i][1];

            rings[i].setPosition((float)pos[i][0], (float)pos[i][1]);
            alive[i] = true;
        }
    }

    frame = 0; tick = 0;

}

void RingManager::reset(int level_number) {

    initializeRings(level_number);
}

void RingManager::update(Player& p, Score& s) {



    float ringWidth = 0.f;
    float ringHeight = 0.f;
    if (ringT.getSize().x > 0 && ringT.getSize().y > 0) {
        ringWidth = ringT.getSize().x * rings[0].getScale().x;
        ringHeight = ringT.getSize().y * rings[0].getScale().y;
    }
    else {

        ringWidth = 32.f;
        ringHeight = 32.f;
    }

    float originOffsetX = ringWidth / 2.0f;
    float originOffsetY = ringHeight / 2.0f;



    for (int i = 0; i < MAX_RINGS; ++i) {
        if (alive[i]) {

            float ringWorldLeft = (float)pos[i][0] - originOffsetX;
            float ringWorldTop = (float)pos[i][1] - originOffsetY;


            bool collided = p.checkCollision(ringWorldLeft, ringWorldTop, ringWidth, ringHeight);

            if (collided) {
                alive[i] = false;
                s.addPoints(100);
                audioManager.playRingCollectSound();

            }
        }
    }


}




void RingManager::draw(RenderWindow& w, float camX) {
    for (int i = 0; i < MAX_RINGS; ++i) {
        if (alive[i]) {

            rings[i].setPosition(pos[i][0] - camX, pos[i][1] - GameMechanics::V_OFFSET);


            w.draw(rings[i]);
        }
    }
}


class ObstacleManager {
public:
    ObstacleManager();
    void update(Player& p, Score& s);
    void draw(RenderWindow& w, float camX);
    void reset(int level_number);
    void initializeObstacles(int level_number);
private:
    static const int MAX_S = 60;
    Texture spikeT;
    Sprite spikes[MAX_S];
    bool active[MAX_S];
    int pos[MAX_S][2];
    AudioManager audioManager;
};

ObstacleManager::ObstacleManager() {

    int gy = 11 * GameMechanics::CELL;

    int P[MAX_S][2] = {
        {1200,gy},{2200,gy},{4500,gy},{4564,gy},{4628,gy},
        {4692,gy},{4756,gy},{4820,gy},{4884,gy},{4948,gy}
    };

    spikeT.loadFromFile("Data/spike.png");
    spikeT.setSmooth(false);

    float spikeTextureHeight = spikeT.getSize().y;

    for (int i = 0; i < MAX_S; ++i) {
        pos[i][0] = P[i][0];

        pos[i][1] = gy - spikeTextureHeight;


        spikes[i].setTexture(spikeT);

        spikes[i].setScale(1.0f, 1.0f);


        active[i] = false;
    }

}

void ObstacleManager::initializeObstacles(int levelNum) {



    for (int i = 0; i < MAX_S; ++i) {
        active[i] = false;
    }


    int spikesPlaced = 0;
    float spikeHeight = spikeT.getSize().y * spikes[0].getScale().y;
    float groundY = (11 * GameMechanics::CELL);

    if (levelNum == 1) {

        int level1_pos_x[] = { 1200, 2200, 4500, 4564, 4628, 4692, 4756, 4820, 4884, 4948, 156 * 64,156 * 64 + 64,156 * 64 + 64 * 2,156 * 64 + 64 * 3,156 * 64 + 64 * 4,156 * 64 + 64 * 5,156 * 64 + 64 * 6,156 * 64 + 64 * 7,156 * 64 + 64 * 8,156 * 64 + 64 * 9,156 * 64 + 64 * 10,156 * 64 + 64 * 11,156 * 64 + 64 * 12,156 * 64 + 64 * 13,156 * 64 + 64 * 14,156 * 64 + 64 * 15,156 * 64 + 64 * 16,156 * 64 + 64 * 17,156 * 64 + 64 * 18,156 * 64 + 64 * 19,
            156 * 64 + 64 * 20,156 * 64 + 64 * 21,156 * 64 + 64 * 22,156 * 64 + 64 * 23,156 * 64 + 64 * 24,156 * 64 + 64 * 25,156 * 64 + 64 * 26,156 * 64 + 64 * 27,156 * 64 + 64 * 27,156 * 64 + 64 * 28,156 * 64 + 64 * 29,156 * 64 + 64 * 30,156 * 64 + 64 * 31,156 * 64 + 64 * 32,156 * 64 + 64 * 33,156 * 64 + 64 * 34,156 * 64 + 64 * 35
        };
        spikesPlaced = sizeof(level1_pos_x) / sizeof(level1_pos_x[0]);
        for (int i = 0; i < spikesPlaced && i < MAX_S; ++i) {
            pos[i][0] = level1_pos_x[i];
            pos[i][1] = (int)(groundY - spikeHeight);
            spikes[i].setPosition((float)pos[i][0], (float)pos[i][1]);
            active[i] = true;

        }
    }
    else if (levelNum == 2) {

        int level2_pos[][2] = { {500,650},{564,650 },{200,650},{800,650},{864,650 },{750,650},{190,650} };


        spikesPlaced = sizeof(level2_pos) / sizeof(level2_pos[0]);
        for (int i = 0; i < spikesPlaced && i < MAX_S; ++i) {
            pos[i][0] = level2_pos[i][0];
            pos[i][1] = level2_pos[i][1];
            spikes[i].setPosition((float)pos[i][0], (float)pos[i][1]);
            active[i] = true;
        }
    }
    else if (levelNum == 3) {
        int level3_pos[][2] = {


           {550, (int)(groundY - spikeHeight)},

           {5100, (int)(groundY - spikeHeight)},

           {5164, (int)(groundY - spikeHeight)},

           {5228, (int)(groundY - spikeHeight)},
           {3000, (int)((9 * GameMechanics::CELL) - spikeHeight)}
        };
        spikesPlaced = sizeof(level3_pos) / sizeof(level3_pos[0]);
        for (int i = 0; i < spikesPlaced && i < MAX_S; ++i) {
            pos[i][0] = level3_pos[i][0];
            pos[i][1] = level3_pos[i][1];
            spikes[i].setPosition((float)pos[i][0], (float)pos[i][1]);
            active[i] = true;
        }
    }
    else if (levelNum == 4) {
        int level4_pos[][2] = {
            {2500, (int)(groundY - spikeHeight)},

            {2564, (int)(groundY - spikeHeight)},

            {2628, (int)(groundY - spikeHeight)},

            {4000, (int)((9 * GameMechanics::CELL) - spikeHeight)},


            {5000, (int)((4 * GameMechanics::CELL) - spikeHeight)},
            {5064, (int)((4 * GameMechanics::CELL) - spikeHeight)},
        };
        spikesPlaced = sizeof(level4_pos) / sizeof(level4_pos[0]);
        for (int i = 0; i < spikesPlaced && i < MAX_S; ++i) {
            pos[i][0] = level4_pos[i][0];
            pos[i][1] = level4_pos[i][1];
            spikes[i].setPosition((float)pos[i][0], (float)pos[i][1]);
            active[i] = true;
        }
    }

}

void ObstacleManager::reset(int level_number) {

    initializeObstacles(level_number);
}


void ObstacleManager::update(Player& p, Score& s) {

    float spikeWidth = 0.f;
    float spikeHeight = 0.f;
    if (spikeT.getSize().x > 0 && spikeT.getSize().y > 0) {
        spikeWidth = spikeT.getSize().x * spikes[0].getScale().x;
        spikeHeight = spikeT.getSize().y * spikes[0].getScale().y;
    }
    else {

        spikeWidth = 64.f;
        spikeHeight = 64.f;
    }
    \


        for (int i = 0; i < MAX_S; ++i) {

            if (active[i] && !p.isInvincible) {


                float spikeWorldLeft = (float)pos[i][0];
                float spikeWorldTop = (float)pos[i][1];


                bool collided = p.checkCollision(spikeWorldLeft, spikeWorldTop, spikeWidth, spikeHeight);

                if (collided) {
                    audioManager.playDamageSound();
                    p.takeDamage();

                }
            }
        }

}

void ObstacleManager::draw(RenderWindow& w, float camX) {
    for (int i = 0; i < MAX_S; ++i) {
        if (active[i]) {

            spikes[i].setPosition(pos[i][0] - camX, pos[i][1] - GameMechanics::V_OFFSET);

            w.draw(spikes[i]);
        }
    }
}


class ItemManager {
public:
    ItemManager();
    void update(Player& p, Score& s);
    void draw(RenderWindow& w, float camX);
    void reset();
private:
    static const int MAX_I = 3;
    Texture lifeT;
    Sprite lives[MAX_I];
    bool active[MAX_I];
    int pos[MAX_I][2];
    void initializeItems();
};

ItemManager::ItemManager() {
    // Example positions
    int P[MAX_I][2] = { {500,450},{1700,450},{3900,450} };
    lifeT.loadFromFile("Data/extra_life.png");

    lifeT.setSmooth(false);

    for (int i = 0; i < MAX_I; ++i) {

        pos[i][0] = P[i][0];

        pos[i][1] = P[i][1];

    }
    initializeItems();
}

void ItemManager::initializeItems() {

    for (int i = 0; i < MAX_I; ++i) {
        lives[i].setTexture(lifeT);

        lives[i].setScale(0.15f, 0.15f);

        lives[i].setOrigin(lifeT.getSize().x / 2.0f, lifeT.getSize().y / 2.0f); // Center origin

        lives[i].setPosition((float)pos[i][0], (float)pos[i][1]);
        active[i] = true;
    }
}

void ItemManager::reset() {

    initializeItems();
}


void ItemManager::update(Player& p, Score& s) {

    float itemWidth = 0.f;
    float itemHeight = 0.f;
    if (lifeT.getSize().x > 0 && lifeT.getSize().y > 0) {
        itemWidth = lifeT.getSize().x * lives[0].getScale().x;
        itemHeight = lifeT.getSize().y * lives[0].getScale().y;
    }
    else {

        itemWidth = 30.f;
        itemHeight = 30.f;
    }


    float originOffsetX = itemWidth / 2.0f;
    float originOffsetY = itemHeight / 2.0f;



    for (int i = 0; i < MAX_I; ++i) {
        if (active[i]) {


            float itemWorldLeft = (float)pos[i][0] - originOffsetX;
            float itemWorldTop = (float)pos[i][1] - originOffsetY;



            bool collided = p.checkCollision(itemWorldLeft, itemWorldTop, itemWidth, itemHeight);
            int currentHealth = p.getHealth();


            if (collided && currentHealth < 3) {
                active[i] = false;
                p.addLife();


            }

        }
    }
}
void ItemManager::draw(RenderWindow& w, float camX) {
    for (int i = 0; i < MAX_I; ++i) {
        if (active[i]) {

            lives[i].setPosition(pos[i][0] - camX, pos[i][1] - GameMechanics::V_OFFSET);
            w.draw(lives[i]);
        }
    }
}


class BoosterManager {
public:
    BoosterManager();
    void update(Player& p);
    void draw(RenderWindow& w, float camX);
    void reset();
private:
    static const int MAX_B = 1;
    Texture boostT;
    Sprite boosts[MAX_B];
    bool active[MAX_B];
    int pos[MAX_B][2];
    void initializeBoosters();
};

BoosterManager::BoosterManager() {
    // Example position
    int P[MAX_B][2] = { {2100,550} };
    boostT.loadFromFile("Data/boost.png");
    boostT.setSmooth(false);
    for (int i = 0; i < MAX_B; ++i) {
        pos[i][0] = P[i][0];
        pos[i][1] = P[i][1];
    }
    initializeBoosters();
}

void BoosterManager::initializeBoosters() {

    for (int i = 0; i < MAX_B; ++i) {
        boosts[i].setTexture(boostT);
        boosts[i].setScale(0.3f, 0.3f);
        boosts[i].setOrigin(boostT.getSize().x / 2.0f, boostT.getSize().y / 2.0f);
        boosts[i].setPosition((float)pos[i][0], (float)pos[i][1]);
        active[i] = true;
    }
}

void BoosterManager::reset() {

    initializeBoosters(); // Re-initialize positions and active status
}


void BoosterManager::update(Player& p) {


    float boosterWidth = 0.f;


    float boosterHeight = 0.f;

    if (boostT.getSize().x > 0 && boostT.getSize().y > 0) {

        boosterWidth = boostT.getSize().x * boosts[0].getScale().x;

        boosterHeight = boostT.getSize().y * boosts[0].getScale().y;
    }
    else {
        ;
        boosterWidth = 40.f;
        boosterHeight = 40.f;
    }

    float originOffsetX = boosterWidth / 2.0f;
    float originOffsetY = boosterHeight / 2.0f;


    for (int i = 0; i < MAX_B; ++i) {

        if (active[i]) {


            float boosterWorldLeft = (float)pos[i][0] - originOffsetX;

            float boosterWorldTop = (float)pos[i][1] - originOffsetY;


            bool collided = p.checkCollision(boosterWorldLeft, boosterWorldTop, boosterWidth, boosterHeight);


            if (collided) {
                p.startBoost(300.0f);
                active[i] = false;



                break;
            }
        }
    }
}
void BoosterManager::draw(RenderWindow& w, float camX) {
    for (int i = 0; i < MAX_B; ++i) {
        if (active[i]) {

            boosts[i].setPosition(pos[i][0] - camX, pos[i][1] - GameMechanics::V_OFFSET);
            w.draw(boosts[i]);
        }
    }
}


class Bullet {
public:
    float px;
    float py;
    float vx;
    float vy;
    bool active;
    bool isProjectile;
    Sprite sprite;
    Texture* bulletTexturePtr;
    float width;
    float height;
    Bullet(Texture& tex, float x, float y, float initialVx = 0.f, float initialVy = 0.f, bool projectile = false);
    void update(const Level& level);
    void draw(RenderWindow& window, float camX);
};

Bullet::Bullet(Texture& tex, float x, float y, float iVx, float iVy, bool proj)
    : px(x), py(y), vx(iVx), vy(iVy), active(true), isProjectile(proj), bulletTexturePtr(&tex) {
    sprite.setTexture(tex);
    sprite.setScale(0.25f, 0.25f);
    width = tex.getSize().x * sprite.getScale().x;
    height = tex.getSize().y * sprite.getScale().y;

    sprite.setOrigin(tex.getSize().x / 2.f, tex.getSize().y / 2.f);
    sprite.setPosition(px, py);
}

void Bullet::update(const Level& level) {
    if (!active) return;

    px += vx;
    py += vy;


    if (isProjectile) {
        vy += GameMechanics::BULLET_GRAVITY;
    }


    float worldEndX = GameMechanics::getCurrentLevelCols(level.getCurrentLevelNumber()) * GameMechanics::CELL;
    if (py > GameMechanics::WORLD_H + 2 * GameMechanics::CELL || py < -2 * GameMechanics::CELL || px < -2 * GameMechanics::CELL || px > worldEndX + 2 * GameMechanics::CELL) {
        active = false;
        return;
    }


    if (level.isSolidPx(px, py)) {
        active = false;

    }
}

void Bullet::draw(RenderWindow& w, float camX) {
    if (!active) return;

    sprite.setPosition(px - camX, py - GameMechanics::V_OFFSET);
    w.draw(sprite);
}


class Enemy {
protected:
    int health;
    bool alive;
public:
    Enemy() : health(GameMechanics::ENEMY_DEFAULT_HEALTH), alive(true) {}
    virtual ~Enemy() {}

    virtual void draw(RenderWindow& window, float camX) = 0;
    virtual bool isActive() const;
    virtual void takeDamage(int amount = 1);
    virtual Bullet** getBullets() = 0;
    virtual int getMaxBullets() const = 0;

    virtual float getX() const = 0;
    virtual float getY() const = 0;
    virtual float getWidth() const = 0;
    virtual float getHeight() const = 0;
    virtual string getName() const;
    virtual void update(Level& level, Player& player, const  Time& elapsedTime) = 0;
    virtual bool isStompable() const { return true; }



};

bool Enemy::isActive() const { return alive; }

void Enemy::takeDamage(int amount) {
    if (alive) {
        health -= amount;

        if (health <= 0) {
            health = 0;
            alive = false;
        }

    }
}

string Enemy::getName() const { return "EnemyBase"; }


class BatBrain : public Enemy {
public:
    Bullet* bullets[GameMechanics::MAX_BAT_BULLETS];
private:
    float px;
    float py;
    float vx;
    Texture& bulletTextureRef;
    Texture& animTextureRef;
    Sprite sprite;
    int shootCooldown;
    int currentAnimFrame;
    int animTick;
    float baseScaleX;
    int bulletCount;
    Clock timerClock;
    float spriteWidth;
    float spriteHeight;
public:
    BatBrain(Texture& batAnimTex, Texture& bulletTex, float startX, float fixedCenterY);
    ~BatBrain() override;
    void update(Level& level, Player& player, const Time& elapsedTime) override;
    void resetShootCooldown();

    void shoot();
    void draw(RenderWindow& window, float camX) override;

    Bullet** getBullets() override;
    int getMaxBullets() const override;

    float getX() const override;

    float getY() const override;

    float getWidth() const override;

    float getHeight() const override;

    string getName() const override;
};

BatBrain::BatBrain(Texture& bTex, Texture& buTex, float sx, float sy)
    : Enemy(), animTextureRef(bTex), bulletTextureRef(buTex), px(sx), py(sy),
    shootCooldown(0), currentAnimFrame(0), animTick(0), bulletCount(0), vx(0) {
    alive = true;
    sprite.setTexture(animTextureRef);
    sprite.setTextureRect(IntRect(0, 0, GameMechanics::BAT_FRAME_WIDTH, GameMechanics::BAT_FRAME_HEIGHT));
    baseScaleX = 1.5f;
    sprite.setScale(baseScaleX, baseScaleX);
    spriteWidth = GameMechanics::BAT_FRAME_WIDTH * baseScaleX;
    spriteHeight = GameMechanics::BAT_FRAME_HEIGHT * baseScaleX;

    sprite.setOrigin(GameMechanics::BAT_FRAME_WIDTH / 2.f, GameMechanics::BAT_FRAME_HEIGHT / 2.f);
    sprite.setPosition(px, py);


    for (int i = 0; i < GameMechanics::MAX_BAT_BULLETS; ++i) {
        bullets[i] = nullptr;
    }
    resetShootCooldown();

}

BatBrain::~BatBrain() {

    for (int i = 0; i < GameMechanics::MAX_BAT_BULLETS; ++i) {
        delete bullets[i];
    }
}

void BatBrain::update(Level& level, Player& player, const Time& et) {
    if (!alive) return;


    float playerCenterX = player.getX() + player.hitX + player.pW / 2.0f;
    float moveSpeed = (float)GameMechanics::BAT_SPEED_PIXELS_PER_FRAME;
    if (px < playerCenterX - moveSpeed) {
        vx = moveSpeed;
    }
    else if (px > playerCenterX + moveSpeed) {
        vx = -moveSpeed;
    }
    else {
        vx = 0;
        px = playerCenterX;
    }
    px += vx;

    if (shootCooldown > 0) {
        shootCooldown--;
    }
    else {
        shoot();
        resetShootCooldown();
    }


    for (int i = 0; i < GameMechanics::MAX_BAT_BULLETS; ++i) {
        if (bullets[i]) {
            bullets[i]->update(level);
            if (!bullets[i]->active) { // If bullet became inactive (hit wall, out of bounds)
                delete bullets[i];
                bullets[i] = nullptr;
                bulletCount--;
            }
        }
    }


    animTick++;
    if (animTick >= GameMechanics::BAT_ANIM_DELAY) {
        animTick = 0;
        currentAnimFrame = (currentAnimFrame + 1) % GameMechanics::BAT_ANIM_FRAMES;
        sprite.setTextureRect(IntRect(currentAnimFrame * GameMechanics::BAT_FRAME_WIDTH, 0, GameMechanics::BAT_FRAME_WIDTH, GameMechanics::BAT_FRAME_HEIGHT));
    }


    sprite.setPosition(px, py);
    sprite.setScale((vx >= 0 ? baseScaleX : -baseScaleX), baseScaleX);
}


void BatBrain::resetShootCooldown() {

    int minF = GameMechanics::BAT_RANDOM_SHOOT_MIN_FRAMES;
    int maxF = GameMechanics::BAT_RANDOM_SHOOT_MAX_FRAMES;
    int range = maxF - minF + 1;
    if (range <= 0) {
        shootCooldown = minF;
    }
    else {
        shootCooldown = minF + (rand() % range);
    }
}


void BatBrain::shoot() {
    if (bulletCount >= GameMechanics::MAX_BAT_BULLETS) return;


    int slot = -1;
    for (int i = 0; i < GameMechanics::MAX_BAT_BULLETS; ++i) {
        if (!bullets[i]) {
            slot = i;
            break;
        }
    }

    if (slot != -1) {

        float spawnX = px;
        float spawnY = py + spriteHeight / 2.f;
        bullets[slot] = new Bullet(bulletTextureRef, spawnX, spawnY, 0.f, GameMechanics::BULLET_SPEED_PIXELS_PER_FRAME, false);
        bulletCount++;

    }
}

void BatBrain::draw(RenderWindow& w, float cX) {
    if (!alive) return;

    sprite.setPosition(px - cX, py - GameMechanics::V_OFFSET);

    w.draw(sprite);


    for (int i = 0; i < GameMechanics::MAX_BAT_BULLETS; ++i) {

        if (bullets[i]) {

            bullets[i]->draw(w, cX);

        }
    }
}

Bullet** BatBrain::getBullets() { return bullets; }

int BatBrain::getMaxBullets() const { return GameMechanics::MAX_BAT_BULLETS; }

float BatBrain::getX() const { return px; }

float BatBrain::getY() const { return py; }

float BatBrain::getWidth() const { return spriteWidth; }

float BatBrain::getHeight() const { return spriteHeight; }

string BatBrain::getName() const { return "BatBrain"; }


class BeeBot : public Enemy {
public:
    Bullet* bullets[GameMechanics::MAX_BEEBOT_BULLETS];
private:
    float px;
    float py;
    float vx;
    float vy;
    Texture& beeTextureRef;
    Texture& bulletTextureRef;
    Sprite sprite;
    int shootCooldown;
    int bulletCount;
    float minY;
    float maxY;
    float baseScale;
    float spriteWidth;
    float spriteHeight;

public:
    BeeBot(Texture& beeTex, Texture& bulletTex, float startX, float startCenterY);
    ~BeeBot() override;
    void update(Level& level, Player& player, const Time& elapsedTime) override;
    void shoot();
    void draw(RenderWindow& window, float camX) override;
    Bullet** getBullets() override;
    int getMaxBullets() const override;
    float getX() const override;
    float getY() const override;
    float getWidth() const override;
    float getHeight() const override;
    string getName() const override;
};

BeeBot::BeeBot(Texture& bTex, Texture& buTex, float sx, float sy)
    : Enemy(), beeTextureRef(bTex), bulletTextureRef(buTex), px(sx), py(sy),
    shootCooldown(GameMechanics::BEEBOT_SHOOT_INTERVAL_FRAMES), bulletCount(0) {
    alive = true;

    vx = (rand() % 2 == 0 ? 1 : -1) * GameMechanics::BEEBOT_SPEED_PIXELS_PER_FRAME;
    vy = (rand() % 2 == 0 ? 1 : -1) * GameMechanics::BEEBOT_SPEED_PIXELS_PER_FRAME;

    sprite.setTexture(beeTextureRef);
    baseScale = 1.5f;
    sprite.setScale(baseScale, baseScale);

    float tw = beeTextureRef.getSize().x;
    float th = beeTextureRef.getSize().y;
    spriteWidth = tw * baseScale;
    spriteHeight = th * baseScale;
    sprite.setOrigin(tw / 2.f, th / 2.f);
    sprite.setPosition(px, py);


    minY = GameMechanics::BEEBOT_MIN_Y_ROW * GameMechanics::CELL + spriteHeight / 2.f;
    maxY = GameMechanics::BEEBOT_MAX_Y_ROW * GameMechanics::CELL + GameMechanics::CELL - spriteHeight / 2.f;

    py = max(minY, min(py, maxY));

    for (int i = 0; i < GameMechanics::MAX_BEEBOT_BULLETS; ++i) {
        bullets[i] = nullptr;
    }
}

BeeBot::~BeeBot() {
    for (int i = 0; i < GameMechanics::MAX_BEEBOT_BULLETS; ++i) {
        delete bullets[i];
    }
}

void BeeBot::update(Level& level, Player& player, const Time& et) {
    if (!alive) return;


    px += vx;
    py += vy;


    float worldEndX = GameMechanics::getCurrentLevelCols(level.getCurrentLevelNumber()) * GameMechanics::CELL;
    if (px - spriteWidth / 2.f < 0) {
        px = spriteWidth / 2.f;
        vx *= -1.f;
    }
    else if (px + spriteWidth / 2.f > worldEndX) {
        px = worldEndX - spriteWidth / 2.f;
        vx *= -1.f;
    }


    if (py < minY) {
        py = minY;
        vy *= -1.f;
    }
    else if (py > maxY) {
        py = maxY;
        vy *= -1.f;
    }


    if (shootCooldown > 0) {
        shootCooldown--;
    }
    else {
        shoot();
        shootCooldown = GameMechanics::BEEBOT_SHOOT_INTERVAL_FRAMES;
    }


    for (int i = 0; i < GameMechanics::MAX_BEEBOT_BULLETS; ++i) {
        if (bullets[i]) {
            bullets[i]->update(level);
            if (!bullets[i]->active) {
                delete bullets[i];
                bullets[i] = nullptr;
                bulletCount--;
            }
        }
    }


    sprite.setPosition(px, py);
    sprite.setScale((vx >= 0 ? baseScale : -baseScale), baseScale);
}

void BeeBot::shoot() {
    if (bulletCount >= GameMechanics::MAX_BEEBOT_BULLETS) return;

    int slot = -1;
    for (int i = 0; i < GameMechanics::MAX_BEEBOT_BULLETS; ++i) {
        if (!bullets[i]) {
            slot = i;
            break;
        }
    }

    if (slot != -1) {

        float spawnX = px;
        float spawnY = py + spriteHeight / 2.f;
        bullets[slot] = new Bullet(bulletTextureRef, spawnX, spawnY, 0.f, GameMechanics::BULLET_SPEED_PIXELS_PER_FRAME, false);
        bulletCount++;

    }
}

void BeeBot::draw(RenderWindow& w, float cX) {
    if (!alive) return;
    sprite.setPosition(px - cX, py - GameMechanics::V_OFFSET);
    w.draw(sprite);

    for (int i = 0; i < GameMechanics::MAX_BEEBOT_BULLETS; ++i) {
        if (bullets[i]) {
            bullets[i]->draw(w, cX);
        }
    }
}

Bullet** BeeBot::getBullets() { return bullets; }
int BeeBot::getMaxBullets() const { return GameMechanics::MAX_BEEBOT_BULLETS; }
float BeeBot::getX() const { return px; }
float BeeBot::getY() const { return py; }
float BeeBot::getWidth() const { return spriteWidth; }
float BeeBot::getHeight() const { return spriteHeight; }
string BeeBot::getName() const { return "BeeBot"; }


class Crabmeat : public Enemy {
public:
    Bullet* bullets[GameMechanics::MAX_CRABMEAT_BULLETS];
private:
    float px;
    float py;
    float vx;
    float groundY;
    Texture& crabmeatTextureRef;
    Texture& bulletTextureRef;
    Sprite sprite;
    int animTick;
    int currentAnimFrame;
    bool facingRight;
    int shootCooldown;
    int bulletCount;
    float baseScale;
    float spriteWidth;
    float spriteHeight;
    float frameWidth;
public:
    Crabmeat(Texture& crabmeatTex, Texture& bulletTex, float startX, float groundPixelY);

    ~Crabmeat() override;

    void update(Level& level, Player& player, const Time& elapsedTime) override;

    void shoot();

    void draw(RenderWindow& window, float camX) override;

    Bullet** getBullets() override;
    int getMaxBullets() const override;


    float getX() const override;
    float getY() const override;

    float getWidth() const override;
    float getHeight() const override;
    string getName() const override;

};


Crabmeat::Crabmeat(Texture& cTex, Texture& bTex, float sx, float groundPixelY)
    : Enemy(), crabmeatTextureRef(cTex), bulletTextureRef(bTex), px(sx), vx(0),
    groundY(groundPixelY), animTick(0), currentAnimFrame(0), facingRight(true),
    shootCooldown(GameMechanics::CRAB_SHOOT_INTERVAL_FRAMES / 2), bulletCount(0) {
    alive = true;
    sprite.setTexture(crabmeatTextureRef);
    baseScale = 0.5f;
    sprite.setScale(baseScale, baseScale);


    frameWidth = crabmeatTextureRef.getSize().x / (float)GameMechanics::CRABMEAT_ANIM_FRAMES;
    float frameHeight = crabmeatTextureRef.getSize().y;
    spriteWidth = frameWidth * baseScale;
    spriteHeight = frameHeight * baseScale;


    sprite.setOrigin(frameWidth / 2.f, frameHeight);

    py = groundY;
    sprite.setPosition(px, py);

    for (int i = 0; i < GameMechanics::MAX_CRABMEAT_BULLETS; ++i) {
        bullets[i] = nullptr;
    }

    sprite.setTextureRect(IntRect(0, 0, (int)frameWidth, (int)frameHeight));
}


Crabmeat::~Crabmeat() {
    for (int i = 0; i < GameMechanics::MAX_CRABMEAT_BULLETS; ++i) {
        delete bullets[i];
    }
}

void Crabmeat::update(Level& level, Player& player, const Time& et) {
    if (!alive) return;


    float playerCenterX = player.getX() + player.hitX + player.pW / 2.0f;
    float moveSpeed = GameMechanics::CRABMEAT_SPEED_PIXELS_PER_FRAME;

    if (playerCenterX < px - moveSpeed * 2) {
        vx = -moveSpeed;
        facingRight = false;
    }
    else if (playerCenterX > px + moveSpeed * 2) {
        vx = moveSpeed;
        facingRight = true;
    }
    else {
        vx = 0;
    }


    if (vx != 0) {
        float nextPx = px + vx;

        float checkX = nextPx + (facingRight ? spriteWidth / 2.f : -spriteWidth / 2.f);
        float checkY = groundY - 5;


        int checkCol = static_cast<int>(checkX / GameMechanics::CELL);
        int checkRow = static_cast<int>(checkY / GameMechanics::CELL);
        int groundRow = static_cast<int>(groundY / GameMechanics::CELL);

        bool collisionAhead = level.isSolid(checkRow, checkCol) || level.isSolid(groundRow, checkCol);

        bool edgeAhead = !level.isSolid(groundRow + 1, static_cast<int>((nextPx) / GameMechanics::CELL));

        if (collisionAhead || edgeAhead) {
            vx = 0;

        }
    }

    px += vx;


    py = groundY;
    sprite.setPosition(px, py);



    if (shootCooldown > 0) {
        shootCooldown--;
    }
    else if (abs(playerCenterX - px) < GameMechanics::WIN_W / 2.f) {
        shoot();
        shootCooldown = GameMechanics::CRAB_SHOOT_INTERVAL_FRAMES;
    }

    for (int i = 0; i < GameMechanics::MAX_CRABMEAT_BULLETS; ++i) {
        if (bullets[i]) {
            bullets[i]->update(level);
            if (!bullets[i]->active) {
                delete bullets[i];
                bullets[i] = nullptr;
                bulletCount--;
            }
        }
    }

    if (vx != 0) {
        animTick++;
        if (animTick >= GameMechanics::CRABMEAT_ANIM_DELAY) {
            animTick = 0;
            currentAnimFrame = (currentAnimFrame + 1) % GameMechanics::CRABMEAT_ANIM_FRAMES;
        }
    }
    else {
        currentAnimFrame = 0;
        animTick = 0;
    }
    sprite.setTextureRect(IntRect(currentAnimFrame * frameWidth, 0, frameWidth, crabmeatTextureRef.getSize().y));


    sprite.setScale((facingRight ? baseScale : -baseScale), baseScale);
}


void Crabmeat::shoot() {
    if (bulletCount >= GameMechanics::MAX_CRABMEAT_BULLETS) return;

    int slot = -1;
    for (int i = 0; i < GameMechanics::MAX_CRABMEAT_BULLETS; ++i) {
        if (!bullets[i]) {
            slot = i;
            break;
        }
    }

    if (slot != -1) {

        float pvx = (facingRight ? 1.f : -1.f) * GameMechanics::CRAB_PROJ_INITIAL_VX;
        float pvy = GameMechanics::CRAB_PROJ_INITIAL_VY;

        float spawnX = px + (facingRight ? spriteWidth * 0.3f : -spriteWidth * 0.3f);

        float spawnY = groundY - spriteHeight * 0.8f;
        bullets[slot] = new Bullet(bulletTextureRef, spawnX, spawnY, pvx, pvy, true);
        bulletCount++;

    }
}

void Crabmeat::draw(RenderWindow& w, float cX) {
    if (!alive) return;
    sprite.setPosition(px - cX, py - GameMechanics::V_OFFSET);
    w.draw(sprite);

    for (int i = 0; i < GameMechanics::MAX_CRABMEAT_BULLETS; ++i) {
        if (bullets[i]) {
            bullets[i]->draw(w, cX);
        }
    }
}

Bullet** Crabmeat::getBullets() { return bullets; }
int Crabmeat::getMaxBullets() const { return GameMechanics::MAX_CRABMEAT_BULLETS; }

float Crabmeat::getX() const { return px; }
float Crabmeat::getY() const { return groundY - spriteHeight / 2.f; }
float Crabmeat::getWidth() const { return spriteWidth; }
float Crabmeat::getHeight() const { return spriteHeight; }
string Crabmeat::getName() const { return "Crabmeat"; }


class MotoBug : public Enemy {
public:
    Bullet* bullets[GameMechanics::MAX_MOTOBUG_BULLETS];
private:
    float px;
    float py;
    float vx;
    float vy;
    Texture& motoBugTextureRef;
    Texture& bulletTextureRef;
    Sprite sprite;
    int shootCooldown;
    int bulletCount;
    float minY;
    float maxY;
    float baseScale;
    float spriteWidth;
    float spriteHeight;
    bool facingRight;

public:
    MotoBug(Texture& motoTex, Texture& bulletTex, float startX, float startCenterY);
    ~MotoBug() override;
    void update(Level& level, Player& player, const Time& elapsedTime) override;
    void shoot(float playerX);
    void draw(RenderWindow& window, float camX) override;
    Bullet** getBullets() override;
    int getMaxBullets() const override;
    float getX() const override;
    float getY() const override;
    float getWidth() const override;
    float getHeight() const override;
    string getName() const override;
};

MotoBug::MotoBug(Texture& mTex, Texture& bTex, float startX, float sy)
    : Enemy(), motoBugTextureRef(mTex), bulletTextureRef(bTex), px(startX), py(sy),
    vx(0), vy(0), shootCooldown(GameMechanics::MOTOBUG_SHOOT_INTERVAL_FRAMES / 2),
    bulletCount(0), facingRight(true) {
    alive = true;
    sprite.setTexture(motoBugTextureRef);
    baseScale = 0.9f;
    sprite.setScale(baseScale, baseScale);

    float fw = motoBugTextureRef.getSize().x;
    float fh = motoBugTextureRef.getSize().y;
    spriteWidth = fw * baseScale;
    spriteHeight = fh * baseScale;
    sprite.setOrigin(fw / 2.f, fh / 2.f);
    sprite.setPosition(px, py);


    minY = GameMechanics::MOTOBUG_MIN_Y_ROW * GameMechanics::CELL + spriteHeight / 2.f;
    maxY = GameMechanics::MOTOBUG_MAX_Y_ROW * GameMechanics::CELL + GameMechanics::CELL - spriteHeight / 2.f;

    py = max(minY, min(py, maxY));

    for (int i = 0; i < GameMechanics::MAX_MOTOBUG_BULLETS; ++i) {
        bullets[i] = nullptr;
    }

    facingRight = (px < GameMechanics::WIN_W / 2.f);
}

MotoBug::~MotoBug() {
    for (int i = 0; i < GameMechanics::MAX_MOTOBUG_BULLETS; ++i) {
        delete bullets[i];
    }
}

void MotoBug::update(Level& level, Player& player, const Time& et) {
    if (!alive) return;


    float targetY = player.getY() + player.hitY + player.pH / 2.0f;
    float vertSpeed = GameMechanics::MOTOBUG_VERTICAL_SPEED;
    float vertMargin = vertSpeed * 0.5f;
    if (py < targetY - vertMargin) {
        vy = vertSpeed;
    }
    else if (py > targetY + vertMargin) {
        vy = -vertSpeed;
    }
    else {
        vy = 0;
    }
    py += vy;
    py = max(minY, min(py, maxY)); \


        float targetX = player.getX() + player.hitX + player.pW / 2.0f;
    float horzSpeed = GameMechanics::MOTOBUG_HORIZONTAL_SPEED;
    float horzMargin = horzSpeed * 1.5f;
    if (px < targetX - horzMargin) {
        vx = horzSpeed;
        facingRight = true;
    }
    else if (px > targetX + horzMargin) {
        vx = -horzSpeed;
        facingRight = false;
    }
    else {
        vx = 0;
    }
    px += vx;

    float worldEndX = GameMechanics::getCurrentLevelCols(level.getCurrentLevelNumber()) * GameMechanics::CELL;
    px = max(spriteWidth / 2.f, min(px, worldEndX - spriteWidth / 2.f));


    if (shootCooldown > 0) {
        shootCooldown--;
    }
    else if (abs(targetX - px) < GameMechanics::WIN_W * 0.8f) {
        shoot(targetX);
        shootCooldown = GameMechanics::MOTOBUG_SHOOT_INTERVAL_FRAMES;
    }


    for (int i = 0; i < GameMechanics::MAX_MOTOBUG_BULLETS; ++i) {
        if (bullets[i] != nullptr) {


            bullets[i]->update(level);
            if (!bullets[i]->active) {

                delete bullets[i];

                bullets[i] = nullptr;

                bulletCount--;

            }
        }
    }


    sprite.setPosition(px, py);
    sprite.setScale(facingRight ? baseScale : -baseScale, baseScale);
}


void MotoBug::shoot(float pX) {
    if (bulletCount >= GameMechanics::MAX_MOTOBUG_BULLETS) return;

    int slot = -1;
    for (int i = 0; i < GameMechanics::MAX_MOTOBUG_BULLETS; ++i) {
        if (!bullets[i]) {
            slot = i;
            break;
        }
    }

    if (slot != -1) {

        float bvx = (pX < px) ? -GameMechanics::MOTOBUG_BULLET_SPEED : GameMechanics::MOTOBUG_BULLET_SPEED;
        float bvy = 0;

        float spawnX = px + ((bvx > 0) ? spriteWidth / 2.f : -spriteWidth / 2.f);
        float spawnY = py;
        bullets[slot] = new Bullet(bulletTextureRef, spawnX, spawnY, bvx, bvy, false);
        bulletCount++;

    }
}

void MotoBug::draw(RenderWindow& w, float cX) {
    if (!alive) return;
    sprite.setPosition(px - cX, py - GameMechanics::V_OFFSET);
    w.draw(sprite);

    for (int i = 0; i < GameMechanics::MAX_MOTOBUG_BULLETS; ++i) {
        if (bullets[i]) {
            bullets[i]->draw(w, cX);
        }
    }
}

Bullet** MotoBug::getBullets() { return bullets; }
int MotoBug::getMaxBullets() const { return GameMechanics::MAX_MOTOBUG_BULLETS; }
float MotoBug::getX() const { return px; }
float MotoBug::getY() const { return py; }
float MotoBug::getWidth() const { return spriteWidth; }
float MotoBug::getHeight() const { return spriteHeight; }
string MotoBug::getName() const { return "MotoBug"; }


class EggStinger : public Enemy {
private:

    struct EggStingerState {
        bool isPatrolling = true;
        bool isAiming = false;
        bool isDiving = false;
        bool isRising = false;


        void setPatrollingState() { resetAllStates(); isPatrolling = true; }
        void setAimingState() { resetAllStates(); isAiming = true; }
        void setDivingState() { resetAllStates(); isDiving = true; }
        void setRisingState() { resetAllStates(); isRising = true; }

    private:
        void resetAllStates() {
            isPatrolling = false;
            isAiming = false;
            isDiving = false;
            isRising = false;
        }
    };
    EggStingerState currentState;
    float px, py;
    float vx, vy;
    Sprite sprite;


    float patrolMinX, patrolMaxX;
    float patrolY;
    float diveTargetX;
    int targetColToBreak;

    Clock stateTimer;


    int currentAnimFrame;
    Clock animTimer;
    float baseScale;
    bool facingRight;

public:

    EggStinger(Texture& bossTexture, Level& lvlForArenaSetup, float startX, float patrolY_coord, float minX_bound, float maxX_bound);
    ~EggStinger() override = default;


    void update(Level& level, Player& player, const  Time& elapsedTime) override;
    void draw(RenderWindow& window, float camX) override;


    Bullet** getBullets() override { return nullptr; }
    int getMaxBullets() const override { return 0; }
    float getX() const override { return px; }
    float getY() const override { return py; }
    float getWidth() const override { return GameMechanics::EGG_STINGER_FRAME_WIDTH * baseScale; }
    float getHeight() const override { return GameMechanics::EGG_STINGER_FRAME_HEIGHT * baseScale; }
    std::string getName() const override { return "EggStinger"; }
    bool isStompable() const override { return true; }
};

EggStinger::EggStinger(Texture& bossTexture, Level& lvlForArenaSetup, float startX, float patrolY_coord, float minX_bound, float maxX_bound)
    : Enemy(), px(startX), py(patrolY_coord),
    vx(GameMechanics::EGG_STINGER_PATROL_SPEED), vy(0),
    patrolMinX(minX_bound), patrolMaxX(maxX_bound), patrolY(patrolY_coord),

    diveTargetX(startX), targetColToBreak(0),
    currentAnimFrame(0), baseScale(1.5f), facingRight(true)
{
    health = GameMechanics::EGG_STINGER_HEALTH;
    alive = true;

    sprite.setTexture(bossTexture);
    sprite.setTextureRect(IntRect(0, 0, 4, 4));
    sprite.setScale(baseScale, baseScale);
    sprite.setOrigin(GameMechanics::EGG_STINGER_FRAME_WIDTH / 2.0f, GameMechanics::EGG_STINGER_FRAME_HEIGHT / 2.0f);
    sprite.setPosition(px, py);

    stateTimer.restart();
    animTimer.restart();
    
}

void EggStinger::update(Level& level, Player& player, const  Time& elapsedTime) {
    if (!alive) return;


    if (currentState.isPatrolling) {
        px += vx;
        py = patrolY;
        vy = 0;

        if (px <= patrolMinX) {
            px = patrolMinX;
            vx = GameMechanics::EGG_STINGER_PATROL_SPEED;
            facingRight = true;
        }
        else if (px >= patrolMaxX) {
            px = patrolMaxX;
            vx = -GameMechanics::EGG_STINGER_PATROL_SPEED;
            facingRight = false;
        }

        if (stateTimer.getElapsedTime().asSeconds() >= GameMechanics::EGG_STINGER_ATTACK_INTERVAL_SECONDS) {
            currentState.setAimingState();
            diveTargetX = player.getX() + (player.pW / 2.0f);
            facingRight = (diveTargetX > px);
            targetColToBreak = static_cast<int>(diveTargetX / GameMechanics::CELL);


            int minGridCol = static_cast<int>(patrolMinX / GameMechanics::CELL);
            int maxGridCol = static_cast<int>(patrolMaxX / GameMechanics::CELL);

            if (minGridCol > maxGridCol) maxGridCol = minGridCol;

            targetColToBreak = std::max(minGridCol, std::min(targetColToBreak, maxGridCol));


            diveTargetX = (targetColToBreak * GameMechanics::CELL) + (GameMechanics::CELL / 2.0f);


            stateTimer.restart();
        }
    }
    else if (currentState.isAiming) {
        float aimSpeed = GameMechanics::EGG_STINGER_PATROL_SPEED;
        if (std::abs(px - diveTargetX) > aimSpeed * 0.5f) {
            float direction = (diveTargetX > px ? 1.0f : -1.0f);
            px += direction * aimSpeed;
            facingRight = (direction > 0);
        }
        else {
            px = diveTargetX;
            currentState.setDivingState();
            vy = GameMechanics::EGG_STINGER_DIVE_SPEED;

        }
    }
    else if (currentState.isDiving) {
        px = diveTargetX;
        py += vy;



        if (py + (getHeight() / 2.0f) >= GameMechanics::EGG_STINGER_TARGET_ROW * GameMechanics::CELL) {

            py = (GameMechanics::EGG_STINGER_TARGET_ROW * GameMechanics::CELL) - (getHeight() / 2.0f);

            int breakRow = GameMechanics::EGG_STINGER_TARGET_ROW;



            if (targetColToBreak >= 0 && targetColToBreak < GameMechanics::getCurrentLevelCols(level.getCurrentLevelNumber())) {

            }
            else {

            }

            currentState.setRisingState();
            vy = -GameMechanics::EGG_STINGER_DIVE_SPEED;

        }

        if (py > GameMechanics::WORLD_H + getHeight()) {
            currentState.setRisingState();
            vy = -GameMechanics::EGG_STINGER_DIVE_SPEED;

        }
    }
    else if (currentState.isRising) {
        px = diveTargetX;
        py += vy;


        if (py <= patrolY) {
            py = patrolY;
            vy = 0;
            currentState.setPatrollingState();


            stateTimer.restart();

        }
    }


    if (animTimer.getElapsedTime().asMilliseconds() > GameMechanics::EGG_STINGER_ANIM_DELAY_MS) {
        currentAnimFrame = (currentAnimFrame + 1) % GameMechanics::EGG_STINGER_ANIM_FRAMES;
        animTimer.restart();
    }
    sprite.setTextureRect(IntRect(
        currentAnimFrame * GameMechanics::EGG_STINGER_FRAME_WIDTH,
        0,
        GameMechanics::EGG_STINGER_FRAME_WIDTH,
        GameMechanics::EGG_STINGER_FRAME_HEIGHT
    ));

    if (facingRight) {
        sprite.setScale(baseScale, baseScale);
    }
    else {
        sprite.setScale(-baseScale, baseScale);
    }

    sprite.setPosition(px, py);
}

void EggStinger::draw(RenderWindow& window, float camX) {
    if (!alive) return;
    sprite.setPosition(px - camX, py - GameMechanics::V_OFFSET);
    window.draw(sprite);
}



class EnemyManager {
private:
    Enemy* enemies[GameMechanics::MAX_ENEMIES];
    int enemyCount;


    Texture batAnimTexture;

    Texture bulletTexture;

    Texture beeBotTexture;

    Texture crabmeatTexture;

    Texture motoBugTexture;

    Texture eggStingerTexture;

    AudioManager audioManager;

    float eggStingerBaseScale;

    void clearEnemies();

public:
    EnemyManager();
    ~EnemyManager();

    int getActiveEnemyCount() const;

    bool isSpecificEnemyActive(const string& enemyName) const;

    bool wasBossSpawned() const;

    void spawnEnemiesForLevel(int levelNum, Level& level);

    void resetEnemies(int levelNum, Level& level);

    void update(Level& level, Player& player, const  Time& et, Score& score);

    void draw(RenderWindow& w, float camX);


};



EnemyManager::EnemyManager() : enemyCount(0), eggStingerBaseScale(1.5f) {
    for (int i = 0; i < GameMechanics::MAX_ENEMIES; ++i) {
        enemies[i] = nullptr;
    }


    batAnimTexture.loadFromFile("Data/batbrain_flyanimation.png");
    bulletTexture.loadFromFile("Data/bullet.png");
    beeBotTexture.loadFromFile("Data/bee_bot.png");
    crabmeatTexture.loadFromFile("Data/crabmeat_left.png");
    motoBugTexture.loadFromFile("Data/motobug_normal.png");

    if (!eggStingerTexture.loadFromFile("Data/eggstinger_right.png")) {

        if (!eggStingerTexture.loadFromFile("Data/batbrain_flyanimation.png")) {

        }
    }

    batAnimTexture.setSmooth(false);
    bulletTexture.setSmooth(false);
    beeBotTexture.setSmooth(false);
    crabmeatTexture.setSmooth(false);
    motoBugTexture.setSmooth(false);
    eggStingerTexture.setSmooth(false);

}

EnemyManager::~EnemyManager() {

    clearEnemies();
}

int EnemyManager::getActiveEnemyCount() const {

    return enemyCount;
}

bool EnemyManager::isSpecificEnemyActive(const std::string& enemyName) const {

    for (int i = 0; i < enemyCount; ++i) {

        if (enemies[i] && enemies[i]->getName() == enemyName && enemies[i]->isActive()) {

            return true;

        }

    }

    return false;
}

bool EnemyManager::wasBossSpawned() const {

    for (int i = 0; i < enemyCount; ++i) {
        if (enemies[i] && enemies[i]->getName() == "EggStinger") {
            return true;
        }
    }
    return true;

}
void EnemyManager::clearEnemies() {

    for (int i = 0; i < enemyCount; ++i) {
        delete enemies[i];
        enemies[i] = nullptr;
    }
    enemyCount = 0;
}

void EnemyManager::spawnEnemiesForLevel(int levelNum, Level& level) {
    if (enemyCount > 0) {

        clearEnemies();
    }


    float groundLevelY = (11 * GameMechanics::CELL);

    if (levelNum == 1) {
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new Crabmeat(crabmeatTexture, bulletTexture, 5700.f, groundLevelY);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new MotoBug(motoBugTexture, bulletTexture, 800.f, groundLevelY - 100);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BatBrain(batAnimTexture, bulletTexture, 9500.f, 3.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BeeBot(beeBotTexture, bulletTexture, 1600.f, 4.5f * GameMechanics::CELL);
    }
    else if (levelNum == 2) {
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BeeBot(beeBotTexture, bulletTexture, 300.f, 3.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new Crabmeat(crabmeatTexture, bulletTexture, 3700.f, groundLevelY);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new Crabmeat(crabmeatTexture, bulletTexture, 8000.f, groundLevelY);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new MotoBug(motoBugTexture, bulletTexture, 11000.f, groundLevelY - 100);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BatBrain(batAnimTexture, bulletTexture, 6500.f, 3.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BeeBot(beeBotTexture, bulletTexture, 7600.f, 4.5f * GameMechanics::CELL);

    }
    else if (levelNum == 3) {
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new MotoBug(motoBugTexture, bulletTexture, 250.f, groundLevelY - 50);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BatBrain(batAnimTexture, bulletTexture, 600.f, 4.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BeeBot(beeBotTexture, bulletTexture, 300.f, 3.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new Crabmeat(crabmeatTexture, bulletTexture, 3700.f, groundLevelY);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new MotoBug(motoBugTexture, bulletTexture, 11000.f, groundLevelY - 200);

        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new MotoBug(motoBugTexture, bulletTexture, 11000.f, groundLevelY - 100);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BatBrain(batAnimTexture, bulletTexture, 6500.f, 3.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BeeBot(beeBotTexture, bulletTexture, 7600.f, 4.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BeeBot(beeBotTexture, bulletTexture, 300.f, 3.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new Crabmeat(crabmeatTexture, bulletTexture, 3700.f, groundLevelY);

        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new MotoBug(motoBugTexture, bulletTexture, 21000.f, groundLevelY - 100);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BatBrain(batAnimTexture, bulletTexture, 21500.f, 3.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BeeBot(beeBotTexture, bulletTexture, 19600.f, 4.5f * GameMechanics::CELL);

    }
    else if (levelNum == 4) {

        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new Crabmeat(crabmeatTexture, bulletTexture, 5700.f, groundLevelY);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new MotoBug(motoBugTexture, bulletTexture, 800.f, groundLevelY - 100);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BatBrain(batAnimTexture, bulletTexture, 9500.f, 3.5f * GameMechanics::CELL);
        if (enemyCount < GameMechanics::MAX_ENEMIES) enemies[enemyCount++] = new BeeBot(beeBotTexture, bulletTexture, 1600.f, 4.5f * GameMechanics::CELL);


        if (enemyCount < GameMechanics::MAX_ENEMIES) {
            int arenaStartColGrid = 150 - GameMechanics::EGG_STINGER_BOSS_AREA_COLS;


            float arenaMinPixelX_Edge = arenaStartColGrid * GameMechanics::CELL;

            float arenaMaxPixelX_Edge = 150 * GameMechanics::CELL;


            float bossSpriteWidth = GameMechanics::EGG_STINGER_FRAME_WIDTH * eggStingerBaseScale;
            float bossSpriteHeight = GameMechanics::EGG_STINGER_FRAME_HEIGHT * eggStingerBaseScale;


            float margin = GameMechanics::CELL * 0.25f;

            float patrolMinX_Center = arenaMinPixelX_Edge + (bossSpriteWidth / 2.0f) + margin;
            float patrolMaxX_Center = arenaMaxPixelX_Edge - (bossSpriteWidth / 2.0f) - margin;


            if (patrolMinX_Center >= patrolMaxX_Center) {
                patrolMinX_Center = arenaMinPixelX_Edge + (bossSpriteWidth / 2.0f);
                patrolMaxX_Center = arenaMaxPixelX_Edge - (bossSpriteWidth / 2.0f);
                if (patrolMinX_Center >= patrolMaxX_Center) {
                    patrolMaxX_Center = patrolMinX_Center + GameMechanics::CELL * 0.5f;
                    if (patrolMaxX_Center > arenaMaxPixelX_Edge - (bossSpriteWidth / 2.0f)) {
                        patrolMaxX_Center = arenaMaxPixelX_Edge - (bossSpriteWidth / 2.0f);
                    }
                    if (patrolMinX_Center >= patrolMaxX_Center && patrolMinX_Center > 0) {
                        patrolMinX_Center = patrolMaxX_Center - 1;
                    }
                    else if (patrolMinX_Center < 0) {
                        patrolMinX_Center = 0;
                        patrolMaxX_Center = bossSpriteWidth;
                    }
                }
            }


            float startBossX = patrolMinX_Center + (patrolMaxX_Center - patrolMinX_Center) / 2.0f;

            startBossX = max(patrolMinX_Center, min(startBossX, patrolMaxX_Center));



            float patrolActualY = GameMechanics::EGG_STINGER_PATROL_Y_ROW * GameMechanics::CELL + (bossSpriteHeight / 2.0f);

            enemies[enemyCount++] = new EggStinger(eggStingerTexture, level, startBossX, patrolActualY, patrolMinX_Center, patrolMaxX_Center);

        }

    }

}

void EnemyManager::resetEnemies(int levelNum, Level& level) {
    clearEnemies();
    spawnEnemiesForLevel(levelNum, level);
}
//
//void EnemyManager::update(Level& level, Player& player, const  Time& et, Score& score) {
//    for (int i = 0; i < enemyCount; ++i) {
//        if (enemies[i] == nullptr || !enemies[i]->isActive()) {
//            continue;
//        }
//
//        enemies[i]->update(level, player, et);
//
//        float enemyX = enemies[i]->getX();
//        float enemyY = enemies[i]->getY();
//        float enemyW = enemies[i]->getWidth();
//        float enemyH = enemies[i]->getHeight();
//        float enemyLeft = enemyX - enemyW / 2.0f;
//        float enemyTop = enemyY - enemyH / 2.0f;
//
//
//        if (player.checkCollision(enemyLeft, enemyTop, enemyW, enemyH)) {
//
//            bool stompedOrAttacked = false;
//
//
//            if (enemies[i]->isStompable() &&
//                player.getIsRolling())
//            {
//
//                enemies[i]->takeDamage(1);
//                player.setVelocity(player.getVx() * 0.5f, GameMechanics::PLAYER_BOUNCE_VY);
//                player.onGround = false;
//                stompedOrAttacked = true;
//
//                if (!enemies[i]->isActive()) {
//                    int points = (enemies[i]->getName() == "EggStinger") ? 1000 : 200;
//                    score.addPoints(points);
//
//                    if (enemies[i]->getName() == "EggStinger") {
//
//
//                    }
//                }
//            }
//
//
//            if (!stompedOrAttacked && !player.isInvincible) {
//                audioManager.playDamageSound();
//
//                player.takeBulletDamage(1);
//                if (player.getHealth() > 0) player.setInvincibilityTime(60.f); // Frames
//            }
//        }
//
//
//        if (!player.isInvincible) {
//            Bullet** bulletsArray = enemies[i]->getBullets();
//            if (bulletsArray) {
//                int maxBullets = enemies[i]->getMaxBullets();
//                for (int j = 0; j < maxBullets; ++j) {
//                    Bullet* b = bulletsArray[j];
//                    if (b && b->active) {
//
//                        float bulletLeft = b->px - b->width / 2.0f;
//                        float bulletTop = b->py - b->height / 2.0f;
//                        if (player.checkCollision(bulletLeft, bulletTop, b->width, b->height)) {
//
//                            audioManager.playDamageSound();
//                            player.takeBulletDamage(1);
//                            b->active = false;
//                            if (player.getHealth() > 0) player.setInvincibilityTime(45.f);
//                        }
//                    }
//                }
//            }
//        }
//    }
//    int aliveIndex = 0;
//    for (int i = 0; i < enemyCount; ++i) {
//        if (enemies[i] != nullptr && enemies[i]->isActive()) {
//            if (i != aliveIndex) {
//                enemies[aliveIndex] = enemies[i];
//            }
//            aliveIndex++;
//        }
//        else if (enemies[i] != nullptr && !enemies[i]->isActive()) {
//            delete enemies[i];
//            enemies[i] = nullptr;
//        }
//    }
//    if (enemyCount != aliveIndex) {
//
//    }
//    enemyCount = aliveIndex;
//
//}
void EnemyManager::update(Level& level, Player& player, const Time& et, Score& score) {
    for (int i = 0; i < enemyCount; ++i) {
        if (enemies[i] == nullptr || !enemies[i]->isActive()) {
            continue;
        }

        enemies[i]->update(level, player, et);

        if (!enemies[i]->isActive()) {
            continue;
        }

        float enemyX_center = enemies[i]->getX();
        float enemyY_center = enemies[i]->getY();
        float enemyW = enemies[i]->getWidth();
        float enemyH = enemies[i]->getHeight();
        float enemyLeft = enemyX_center - enemyW / 2.0f;
        float enemyTop = enemyY_center - enemyH / 2.0f;

        if (player.checkCollision(enemyLeft, enemyTop, enemyW, enemyH)) {
            bool interactionHappened = false;

            if (player.getIsRolling() && enemies[i]->isStompable()) {
                enemies[i]->takeDamage(1);
                interactionHappened = true;

                float playerCenterX = player.getX() + player.pW / 2.0f;
                float rollKnockbackMultiplierHorizontal = 2.0f; // Increased for significant horizontal
                float rollKnockbackMultiplierVertical = 0.8f;   // Increased for significant vertical

                float bounceVx_roll;
                if (playerCenterX < enemyX_center) {
                    bounceVx_roll = -GameMechanics::PLAYER_BOUNCE_VX * rollKnockbackMultiplierHorizontal;
                }
                else {
                    bounceVx_roll = GameMechanics::PLAYER_BOUNCE_VX * rollKnockbackMultiplierHorizontal;
                }

                if (std::abs(playerCenterX - enemyX_center) < player.pW * 0.5f) {
                    if (std::abs(player.getVx()) > 1.0f) {
                        bounceVx_roll = -player.getVx() * 1.2f;
                        if (std::abs(bounceVx_roll) < GameMechanics::PLAYER_BOUNCE_VX * (rollKnockbackMultiplierHorizontal * 0.8f)) {
                            bounceVx_roll = (player.getVx() > 0) ? -GameMechanics::PLAYER_BOUNCE_VX * (rollKnockbackMultiplierHorizontal * 0.8f) : GameMechanics::PLAYER_BOUNCE_VX * (rollKnockbackMultiplierHorizontal * 0.8f);
                        }
                    }
                    else {
                        bounceVx_roll = (playerCenterX < enemyX_center) ? -GameMechanics::PLAYER_BOUNCE_VX * (rollKnockbackMultiplierHorizontal * 0.9f) : GameMechanics::PLAYER_BOUNCE_VX * (rollKnockbackMultiplierHorizontal * 0.9f);
                    }
                }

                player.setVelocity(bounceVx_roll, GameMechanics::PLAYER_BOUNCE_VY * rollKnockbackMultiplierVertical);
                player.onGround = false;
                player.setInvincibilityTime(25.f);

                if (!enemies[i]->isActive()) {
                    int points = (enemies[i]->getName() == "EggStinger") ? 1000 : 200;
                    score.addPoints(points);
                    if (enemies[i]->getName() == "EggStinger") {
                        // Boss defeated
                    }
                }
            }

            if (!interactionHappened &&
                enemies[i]->isStompable() &&
                player.getVy() > 1.0f &&
                (player.getY() + player.hitY + player.pH) < (enemyY_center + enemyH * 0.35f))
            {
                enemies[i]->takeDamage(1);
                interactionHappened = true;

                float stompKnockbackMultiplierHorizontal = 0.5f; // Can add more horizontal if desired for stomps
                float stompKnockbackMultiplierVertical = 1.2f;   // Significant vertical for stomp

                float stompBounceVx;
                if (player.getX() + player.pW / 2.0f < enemyX_center) {
                    stompBounceVx = -GameMechanics::PLAYER_BOUNCE_VX * stompKnockbackMultiplierHorizontal;
                }
                else {
                    stompBounceVx = GameMechanics::PLAYER_BOUNCE_VX * stompKnockbackMultiplierHorizontal;
                }
                if (std::abs(player.getVx()) > 1.0f && std::abs((player.getX() + player.pW / 2.0f) - enemyX_center) < player.pW * 0.75f) {
                    stompBounceVx = -player.getVx() * 0.5f;
                }


                player.setVelocity(stompBounceVx, GameMechanics::PLAYER_BOUNCE_VY * stompKnockbackMultiplierVertical);
                player.onGround = false;
                player.setInvincibilityTime(20.f);

                if (!enemies[i]->isActive()) {
                    int points = (enemies[i]->getName() == "EggStinger") ? 1000 : 200;
                    score.addPoints(points);
                }
            }

            if (!interactionHappened && !player.isInvincible) {
                audioManager.playDamageSound();
                player.takeBulletDamage(1);

                float damageKnockbackMultiplierHorizontal = 1.5f;
                float damageKnockbackMultiplierVertical = 0.7f;
                float damageBounceVx;

                if (player.getX() + (player.pW / 2.0f) < enemyX_center) {
                    damageBounceVx = -GameMechanics::PLAYER_BOUNCE_VX * damageKnockbackMultiplierHorizontal;
                }
                else {
                    damageBounceVx = GameMechanics::PLAYER_BOUNCE_VX * damageKnockbackMultiplierHorizontal;
                }
                player.setVelocity(damageBounceVx, GameMechanics::PLAYER_BOUNCE_VY * damageKnockbackMultiplierVertical);
                player.onGround = false;

                if (GameMechanics::getLives() > 0) {
                    player.setInvincibilityTime(60.f);
                }
            }
        }

        if (!player.isInvincible) {
            Bullet** bulletsArray = enemies[i]->getBullets();
            if (bulletsArray) {
                int maxBullets = enemies[i]->getMaxBullets();
                for (int j = 0; j < maxBullets; ++j) {
                    Bullet* b = bulletsArray[j];
                    if (b && b->active) {
                        float bulletLeft = b->px - b->width / 2.0f;
                        float bulletTop = b->py - b->height / 2.0f;
                        if (player.checkCollision(bulletLeft, bulletTop, b->width, b->height)) {
                            audioManager.playDamageSound();
                            player.takeBulletDamage(1);
                            b->active = false;
                            if (GameMechanics::getLives() > 0) {
                                player.setInvincibilityTime(45.f);
                            }
                        }
                    }
                }
            }
        }
    }

    int aliveIndex = 0;
    for (int i = 0; i < enemyCount; ++i) {
        if (enemies[i] != nullptr) {
            if (enemies[i]->isActive()) {
                if (i != aliveIndex) {
                    enemies[aliveIndex] = enemies[i];
                }
                aliveIndex++;
            }
            else {
                delete enemies[i];
                enemies[i] = nullptr;
            }
        }
    }

    if (enemyCount != aliveIndex) {
        for (int i = aliveIndex; i < enemyCount; ++i) {
            enemies[i] = nullptr;
        }
    }
    enemyCount = aliveIndex;
}
void EnemyManager::draw(RenderWindow& w, float camX) {
    for (int i = 0; i < enemyCount; ++i) {
        if (enemies[i] != nullptr && enemies[i]->isActive()) { // Double check for safety
            enemies[i]->draw(w, camX);
        }
    }
}


class Game {
public:
    Game();  // Constructor
    ~Game(); // Destructor
    void run();

private:

    struct CurrentGameState {
        bool isShowingMenu = true;
        bool isEnteringName = false;
        bool isPlaying = false;
        bool isShowingOptions = false;
        bool isShowingLeaderboard = false;
        bool isGameOver = false;
        bool isLevelComplete = false;
        bool isGameComplete = false;

        void setMenuState() { resetAllStates(); isShowingMenu = true; }
        void setEnteringNameState() { resetAllStates(); isEnteringName = true; }
        void setPlayingState() { resetAllStates(); isPlaying = true; }
        void setShowingOptionsState() { resetAllStates(); isShowingOptions = true; }
        void setShowingLeaderboardState() { resetAllStates(); isShowingLeaderboard = true; }
        void setGameOverState() { resetAllStates(); isGameOver = true; }
        void setLevelCompleteState() { resetAllStates(); isLevelComplete = true; }
        void setGameCompleteState() { resetAllStates(); isGameComplete = true; }

    private:
        void resetAllStates() {
            isShowingMenu = false; isEnteringName = false; isPlaying = false;
            isShowingOptions = false; isShowingLeaderboard = false; isGameOver = false;
            isLevelComplete = false; isGameComplete = false;
        }
    };

    struct ScoreEntry {
        string name;
        int score;
    };

    RenderWindow window;
    Level level;
    Player player;
    Tails tails;
    Knuckles knuckles;
    Player* characterPtrs[3];
    int currentPlayerIndex;

    RingManager ringManager;
    ObstacleManager obstacleManager;
    ItemManager itemManager;
    BoosterManager boosterManager;
    EnemyManager enemyManager;
    Score scoreDisplay;
    AudioManager audioManager;

    float camX;
    Clock gameClock;
    Clock frameRateClock;
    bool zKeyPressedLastFrame;

    CurrentGameState currentState;
    string currentPlayerName;

    Font menuFont;

    Text menuTitle;
    static const int NUM_MENU_OPTIONS = 4;
    Text menuOptions[NUM_MENU_OPTIONS];
    int selectedMenuItem;
    Text menuInstructions;

    Text namePromptText;
    Text playerNameInputText;
    RectangleShape nameInputCursor;
    bool showCursor;
    Clock cursorClock;

    Text optionsTitleText;
    static const int NUM_OPTIONS_ITEMS = 2;
    Text optionsItems[NUM_OPTIONS_ITEMS];
    int selectedOptionsItem;
    bool soundEnabled;

    ScoreEntry leaderboard[10];
    int numEntriesInLeaderboard;
    Text leaderboardTitleText;
    Text leaderboardDisplayText;
    Text leaderboardBackText;

    Text statusMessageText;
    Text continuePromptText;

    int currentLevelNumber;
    bool levelTransitioning;
    LevelTimer* levelTimer;

    unsigned long long frameCount;

    void setupAllUI();
    void setupMenu();
    void setupNameInput();
    void setupOptions();
    void setupLeaderboardDisplay();
    void setupStatusScreen(const  string& message, const  string& prompt);
    void loadLeaderboardFromFile();
    void saveLeaderboardToFile();
    void addToLeaderboard(const  string& name, int scoreValue);


    void processEvents();
    void handleMenuInput(const  Event& event);
    void handleNameInput(const  Event& event);
    void handleOptionsInput(const  Event& event);
    void handleLeaderboardInput(const  Event& event);
    void handlePlayingInput(const  Event& event);
    void handleStatusScreenInput(const  Event& event);

    void update(const  Time& deltaTime);
    void updateMenu();
    void updateNameInput();
    void updateOptions();
    void updatePlaying(const  Time& gameDeltaTime);

    void render();
    void drawMenu();
    void drawNameInput();
    void drawOptions();
    void drawLeaderboardDisplay();
    void drawPlaying();
    void drawStatusScreen();

    void switchPlayer();
    void setupLevel(int levelNum);
    void checkLevelCompletion();
    void nextLevel();
    void resetGameForNewPlaythrough();
    void checkGameOverConditions();
    float estimateTextRenderWidth(const  Text& text);
    float estimateTextRenderHeight(const  Text& text);
};

Game::Game() :
    window(VideoMode(GameMechanics::WIN_W, GameMechanics::WIN_H), "Sonic Clone Adventure"),
    camX(0),
    zKeyPressedLastFrame(false),
    currentPlayerName("Player"),
    selectedMenuItem(0),
    selectedOptionsItem(0),
    soundEnabled(true),
    currentLevelNumber(0),
    levelTransitioning(false),
    currentPlayerIndex(0),
    showCursor(true),
    levelTimer(nullptr),
    frameCount(0),
    numEntriesInLeaderboard(0)
{
    window.setVerticalSyncEnabled(true);
    window.setFramerateLimit(60);
    srand(static_cast<unsigned int>(time(nullptr)));


    characterPtrs[0] = &player;
    characterPtrs[1] = &tails;
    characterPtrs[2] = &knuckles;
    if (!menuFont.loadFromFile("Data/Huglove.ttf")) {

        window.close();
        return;
    }

    loadLeaderboardFromFile();
    setupAllUI();


}
float Game::estimateTextRenderWidth(const  Text& text) {
    if (text.getString().isEmpty()) {
        return 0.f;
    }
    return static_cast<float>(text.getString().getSize()) * text.getCharacterSize() * 0.55f;
}

float Game::estimateTextRenderHeight(const  Text& text) {
    return static_cast<float>(text.getCharacterSize());
}
Game::~Game() {
    delete levelTimer;
}

void Game::setupAllUI() {
    setupMenu();
    setupNameInput();
    setupOptions();
    setupLeaderboardDisplay();
}

void Game::setupMenu() {
    menuTitle.setFont(menuFont);
    menuTitle.setString("SONIC CLONE ADVENTURE");
    menuTitle.setCharacterSize(72);
    menuTitle.setFillColor(Color::Yellow);
    float estTitleWidth = estimateTextRenderWidth(menuTitle);
    float estTitleHeight = estimateTextRenderHeight(menuTitle);
    menuTitle.setOrigin(0, 0);
    menuTitle.setPosition(
        GameMechanics::WIN_W / 2.0f - estTitleWidth / 2.0f,
        GameMechanics::WIN_H * 0.2f - estTitleHeight / 2.0f
    );


    const char* options[] = { "New Game", "Options", "Leaderboard", "Exit" };
    for (int i = 0; i < NUM_MENU_OPTIONS; ++i) {
        menuOptions[i].setFont(menuFont);
        menuOptions[i].setString(options[i]);
        menuOptions[i].setCharacterSize(48);
        menuOptions[i].setFillColor(Color::White);
        float estOptWidth = estimateTextRenderWidth(menuOptions[i]);
        float estOptHeight = estimateTextRenderHeight(menuOptions[i]);
        menuOptions[i].setOrigin(0, 0);
        menuOptions[i].setPosition(
            GameMechanics::WIN_W / 2.0f - estOptWidth / 2.0f,
            GameMechanics::WIN_H * 0.4f + i * 70.f - estOptHeight / 2.0f
        );
    }
    selectedMenuItem = 0;

    menuInstructions.setFont(menuFont);
    menuInstructions.setString("Use Arrow Keys and Enter");
    menuInstructions.setCharacterSize(24);
    menuInstructions.setFillColor(Color(180, 180, 180));
    float estInstWidth = estimateTextRenderWidth(menuInstructions);
    float estInstHeight = estimateTextRenderHeight(menuInstructions);
    menuInstructions.setOrigin(0, 0);
    menuInstructions.setPosition(
        GameMechanics::WIN_W / 2.0f - estInstWidth / 2.0f,
        GameMechanics::WIN_H * 0.85f - estInstHeight / 2.0f
    );
}

void Game::setupNameInput() {
    namePromptText.setFont(menuFont);
    namePromptText.setString("By Taha & Hassaan!");
    namePromptText.setCharacterSize(52);
    namePromptText.setFillColor(Color::Cyan);
    float estPromptWidth = estimateTextRenderWidth(namePromptText);
    float estPromptHeight = estimateTextRenderHeight(namePromptText);
    namePromptText.setOrigin(0, 0);
    namePromptText.setPosition(
        GameMechanics::WIN_W / 2.0f - estPromptWidth / 2.0f,
        GameMechanics::WIN_H * 0.3f - estPromptHeight / 2.0f
    );

    playerNameInputText.setFont(menuFont);
    playerNameInputText.setString(currentPlayerName);
    playerNameInputText.setCharacterSize(48);

    Vector2f cursorSize(3.f, 40.f);
    nameInputCursor.setSize(cursorSize);
    nameInputCursor.setFillColor(Color::White);
}

void Game::setupOptions() {
    optionsTitleText.setFont(menuFont);
    optionsTitleText.setString("Options");
    optionsTitleText.setCharacterSize(60);
    optionsTitleText.setFillColor(Color::Yellow);
    float estOptTitleWidth = estimateTextRenderWidth(optionsTitleText);
    float estOptTitleHeight = estimateTextRenderHeight(optionsTitleText);
    optionsTitleText.setOrigin(0, 0);
    optionsTitleText.setPosition(
        GameMechanics::WIN_W / 2.0f - estOptTitleWidth / 2.0f,
        GameMechanics::WIN_H * 0.2f - estOptTitleHeight / 2.0f
    );

    optionsItems[0].setFont(menuFont);

    optionsItems[0].setCharacterSize(48);
    optionsItems[0].setFillColor(Color::White);


    optionsItems[1].setFont(menuFont);
    optionsItems[1].setString("Back to Menu");
    optionsItems[1].setCharacterSize(48);
    optionsItems[1].setFillColor(Color::White);
    float estBackWidth = estimateTextRenderWidth(optionsItems[1]);
    float estBackHeight = estimateTextRenderHeight(optionsItems[1]);
    optionsItems[1].setOrigin(0, 0);
    optionsItems[1].setPosition(
        GameMechanics::WIN_W / 2.0f - estBackWidth / 2.0f,
        GameMechanics::WIN_H * 0.4f + 1 * 80.f - estBackHeight / 2.0f
    );
    selectedOptionsItem = 0;
}

void Game::setupLeaderboardDisplay() {
    leaderboardTitleText.setFont(menuFont);
    leaderboardTitleText.setString("High Scores");
    leaderboardTitleText.setCharacterSize(60);
    leaderboardTitleText.setFillColor(Color::Yellow);
    float estLbTitleWidth = estimateTextRenderWidth(leaderboardTitleText);
    float estLbTitleHeight = estimateTextRenderHeight(leaderboardTitleText);
    leaderboardTitleText.setOrigin(0, 0);
    leaderboardTitleText.setPosition(
        GameMechanics::WIN_W / 2.0f - estLbTitleWidth / 2.0f,
        GameMechanics::WIN_H * 0.1f - estLbTitleHeight / 2.0f
    );

    stringstream ss;
    ss << left;
    if (numEntriesInLeaderboard == 0) {
        ss << "\n\nNo scores recorded yet!";
    }
    else {
        for (int i = 0; i < numEntriesInLeaderboard; ++i) {
            ss << setw(3) << (i + 1) << ". "
                << setw(20) << leaderboard[i].name.substr(0, 18)
                << right << setw(8) << leaderboard[i].score << "\n";
        }
    }
    leaderboardDisplayText.setFont(menuFont);
    leaderboardDisplayText.setString(ss.str());
    leaderboardDisplayText.setCharacterSize(32);
    leaderboardDisplayText.setFillColor(Color::White);

    leaderboardDisplayText.setOrigin(0, 0);

    float approxBlockWidth = 30 * leaderboardDisplayText.getCharacterSize() * 0.55f;
    leaderboardDisplayText.setPosition(
        GameMechanics::WIN_W / 2.0f - approxBlockWidth / 2.0f,
        GameMechanics::WIN_H * 0.25f
    );


    leaderboardBackText.setFont(menuFont);
    leaderboardBackText.setString("Press Enter to Return");
    leaderboardBackText.setCharacterSize(30);
    leaderboardBackText.setFillColor(Color::Cyan);
    float estLbBackWidth = estimateTextRenderWidth(leaderboardBackText);
    float estLbBackHeight = estimateTextRenderHeight(leaderboardBackText);
    leaderboardBackText.setOrigin(0, 0);
    leaderboardBackText.setPosition(
        GameMechanics::WIN_W / 2.0f - estLbBackWidth / 2.0f,
        GameMechanics::WIN_H * 0.9f - estLbBackHeight / 2.0f
    );
}

void Game::setupStatusScreen(const  string& message, const  string& prompt) {
    statusMessageText.setFont(menuFont);
    statusMessageText.setString(message);
    statusMessageText.setCharacterSize(72);
    float estMsgWidth = estimateTextRenderWidth(statusMessageText);
    float estMsgHeight = estimateTextRenderHeight(statusMessageText);
    statusMessageText.setOrigin(0, 0);
    statusMessageText.setPosition(
        GameMechanics::WIN_W / 2.0f - estMsgWidth / 2.0f,
        GameMechanics::WIN_H * 0.4f - estMsgHeight / 2.0f
    );

    continuePromptText.setFont(menuFont);
    continuePromptText.setString(prompt);
    continuePromptText.setCharacterSize(40);
    continuePromptText.setFillColor(Color::White);
    float estPromptWidth = estimateTextRenderWidth(continuePromptText);
    float estPromptHeight = estimateTextRenderHeight(continuePromptText);
    continuePromptText.setOrigin(0, 0);
    continuePromptText.setPosition(
        GameMechanics::WIN_W / 2.0f - estPromptWidth / 2.0f,
        GameMechanics::WIN_H * 0.6f - estPromptHeight / 2.0f
    );
}

void Game::loadLeaderboardFromFile() {
    numEntriesInLeaderboard = 0;
    ifstream file("Leaderboard.txt");

    if (file.is_open()) {
        string line;

        while (numEntriesInLeaderboard < 10 && getline(file, line)) {
            if (line.empty()) {
                continue;
            }


            int scoreFromFile = 0;
            string nameFromFile;
            int spacePos = 0;


            for (int i = 0; i < line.length(); ++i) {
                if (line[i] == ' ') {
                    spacePos = i;
                    break;
                }
            }

            if (spacePos == 0 && !line.empty() && line[0] >= '0' && line[0] <= '9') {

                bool couldBeScoreOnly = true;
                for (int k = 0; k < line.length(); ++k) {
                    if (line[k] < '0' || line[k] > '9') {
                        couldBeScoreOnly = false;
                        break;
                    }
                }
                if (couldBeScoreOnly) {

                    for (int k = 0; k < line.length(); ++k) {
                        if (line[k] >= '0' && line[k] <= '9') {
                            scoreFromFile = scoreFromFile * 10 + (line[k] - '0');
                        }
                        else {
                            break;
                        }
                    }
                    nameFromFile = "Unknown";
                }
                else {


                    continue;
                }

            }
            else if (spacePos > 0) {
                for (int i = 0; i < spacePos; ++i) {
                    if (line[i] >= '0' && line[i] <= '9') {
                        scoreFromFile = scoreFromFile * 10 + (line[i] - '0');
                    }
                    else {


                        scoreFromFile = -1; // Mark as invalid
                        break;
                    }
                }
                if (scoreFromFile == -1) continue; // Skip this malformed line

                // Extract name part (everything after the first space)
                if (spacePos + 1 < line.length()) {
                    nameFromFile.assign(line.c_str() + spacePos + 1, line.length() - (spacePos + 1));
                }
                else {
                    nameFromFile = "Unknown";
                }
            }
            else {


                continue;
            }




            if (!nameFromFile.empty()) {
                int start = 0;

                for (int i = 0; i < nameFromFile.length(); ++i) {
                    char c = nameFromFile[i];
                    if (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\f' && c != '\v') {
                        start = i;
                        break;
                    }
                    if (i == nameFromFile.length() - 1) {
                        start = nameFromFile.length();
                    }
                }

                int end = nameFromFile.length();
                \
                    for (int i = nameFromFile.length(); i > 0; --i) {
                        char c = nameFromFile[i - 1];
                        if (c != ' ' && c != '\t' && c != '\n' && c != '\r' && c != '\f' && c != '\v') {
                            end = i;
                            break;
                        }
                        if (i - 1 == 0) {
                            end = 0;
                        }
                    }

                if (start >= end) {
                    nameFromFile = "";
                }
                else {

                    string trimmedName;
                    for (int i = start; i < end; ++i) {
                        trimmedName += nameFromFile[i];
                    }
                    nameFromFile = trimmedName;
                }
            }


            if (!nameFromFile.empty()) {
                leaderboard[numEntriesInLeaderboard].score = scoreFromFile;
                leaderboard[numEntriesInLeaderboard].name = nameFromFile;
                numEntriesInLeaderboard++;
            }
            else if (scoreFromFile != 0) {
                leaderboard[numEntriesInLeaderboard].score = scoreFromFile;
                leaderboard[numEntriesInLeaderboard].name = "Player";
                numEntriesInLeaderboard++;
            }
        }
        if (numEntriesInLeaderboard > 1) {
            for (int i = 0; i < numEntriesInLeaderboard - 1; ++i) {
                int maxIndex = i;
                for (int j = i + 1; j < numEntriesInLeaderboard; ++j) {
                    if (leaderboard[j].score > leaderboard[maxIndex].score) {
                        maxIndex = j;
                    }
                }
                if (maxIndex != i) {
                    ScoreEntry temp = leaderboard[i];
                    leaderboard[i] = leaderboard[maxIndex];
                    leaderboard[maxIndex] = temp;
                }
            }
            
        }


        
    }
   
}

void Game::saveLeaderboardToFile() {
    ofstream file("Leaderboard.txt");
    if (file.is_open()) {
        for (int i = 0; i < numEntriesInLeaderboard; i++) {
            file << leaderboard[i].score << " " << leaderboard[i].name << "\n";
        }
        file.close();
      
    }
  
}

void Game::addToLeaderboard(const  string& name, int scoreValue) {
    if (numEntriesInLeaderboard < 10 || scoreValue > leaderboard[9].score) {
        ScoreEntry newEntry = { name.substr(0, 20), scoreValue };
        if (numEntriesInLeaderboard < 10) {
            leaderboard[numEntriesInLeaderboard++] = newEntry;
        }
        else {
            leaderboard[9] = newEntry;
        }
        sort(leaderboard, leaderboard + numEntriesInLeaderboard, [](const ScoreEntry& a, const ScoreEntry& b) {
            return a.score > b.score;
            });
        saveLeaderboardToFile();
        setupLeaderboardDisplay();
    }
}

void Game::processEvents() {
    Event event;
    while (window.pollEvent(event)) {
        if (event.type == Event::Closed) {
            window.close();
        }

        if (currentState.isShowingMenu) { handleMenuInput(event); }
        else if (currentState.isEnteringName) { handleNameInput(event); }
        else if (currentState.isShowingOptions) { handleOptionsInput(event); }
        else if (currentState.isShowingLeaderboard) { handleLeaderboardInput(event); }
        else if (currentState.isPlaying) { handlePlayingInput(event); }
        else if (currentState.isGameOver ||
            currentState.isLevelComplete ||
            currentState.isGameComplete) {
            handleStatusScreenInput(event);
        }
    }
}

void Game::handleMenuInput(const Event& event) {
    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up) {
            selectedMenuItem = (selectedMenuItem - 1 + NUM_MENU_OPTIONS) % NUM_MENU_OPTIONS;
        }
        else if (event.key.code == Keyboard::Down) {
            selectedMenuItem = (selectedMenuItem + 1) % NUM_MENU_OPTIONS;
        }
        else if (event.key.code == Keyboard::Return) {
            switch (selectedMenuItem) {
            case 0:

                currentState.setEnteringNameState();
                currentPlayerName = "";
                playerNameInputText.setString(currentPlayerName);


                break;
            case 1:
                currentState.setShowingOptionsState();
                selectedOptionsItem = 0;

                break;
            case 2:
                setupLeaderboardDisplay();
                currentState.setShowingLeaderboardState();
                break;
            case 3:
                window.close();
                break;
            }
        }
    }
}

void Game::handleNameInput(const  Event& event) {
    if (event.type == Event::TextEntered) {
        if (event.text.unicode == 8) {
            if (!currentPlayerName.empty()) {

                currentPlayerName.erase(currentPlayerName.length() - 1, 1);
                playerNameInputText.setString(currentPlayerName);
            }
        }

        else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
            if (currentPlayerName.length() < 10) {
                currentPlayerName += static_cast<char>(event.text.unicode);
                playerNameInputText.setString(currentPlayerName);
            }
        }

    }
    else if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Return) {
            if (currentPlayerName.empty()) {
                currentPlayerName = "Player";
                playerNameInputText.setString(currentPlayerName);
            }


            resetGameForNewPlaythrough();
            nextLevel();
        }
        else if (event.key.code == Keyboard::Escape) {

            currentState.setMenuState();
        }
    }
}
void Game::handleOptionsInput(const  Event& event) {
    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Up) {
            selectedOptionsItem = (selectedOptionsItem - 1 + NUM_OPTIONS_ITEMS) % NUM_OPTIONS_ITEMS;
        }
        else if (event.key.code == Keyboard::Down) {
            selectedOptionsItem = (selectedOptionsItem + 1) % NUM_OPTIONS_ITEMS;
        }
        else if (event.key.code == Keyboard::Return) {
            if (selectedOptionsItem == 0) { // Sound Toggle
                soundEnabled = !soundEnabled;
           
                
            }
            else if (selectedOptionsItem == 1) { // Back
                currentState.setMenuState();
            }
        }
        else if (event.key.code == Keyboard::Escape) {
            currentState.setMenuState();
        }
    }
}

void Game::handleLeaderboardInput(const  Event& event) {
    if (event.type == Event::KeyPressed &&
        (event.key.code == Keyboard::Return || event.key.code == Keyboard::Escape)) {
        currentState.setMenuState();
    }
}

void Game::handlePlayingInput(const  Event& event) {
    if (event.type == Event::KeyPressed) {
        if (event.key.code == Keyboard::Escape) {
            audioManager.stopCurrentMusic();
            currentState.setMenuState(); // Go to main menu, game state pauses.
        }
        if (event.key.code == Keyboard::Z && !zKeyPressedLastFrame && !levelTransitioning) {
            switchPlayer();
            zKeyPressedLastFrame = true;
        }
    }
    if (event.type == Event::KeyReleased) {
        if (event.key.code == Keyboard::Z) {
            zKeyPressedLastFrame = false;
        }
    }
}

void Game::handleStatusScreenInput(const  Event& event) {
    if (event.type == Event::KeyPressed &&
        (event.key.code == Keyboard::Return || event.key.code == Keyboard::Escape)) {

        currentState.setMenuState();
    }
}


void Game::update(const  Time& deltaTime) {
    if (currentState.isShowingMenu) { updateMenu(); }
    else if (currentState.isEnteringName) { updateNameInput(); }
    else if (currentState.isShowingOptions) { updateOptions(); }

    else if (currentState.isPlaying) {
        if (levelTimer) levelTimer->update(deltaTime.asSeconds());

        updatePlaying(gameClock.restart());
    }

}

void Game::updateMenu() {
    for (int i = 0; i < NUM_MENU_OPTIONS; ++i) {
        if (i == selectedMenuItem) {
            menuOptions[i].setFillColor(Color::Yellow);
            menuOptions[i].setScale(1.1f, 1.1f); // Scale from its current origin (top-left)
        }
        else {
            menuOptions[i].setFillColor(Color::White);
            menuOptions[i].setScale(1.0f, 1.0f);
        }
    }
}

void Game::updateNameInput() {
    if (cursorClock.getElapsedTime().asSeconds() > 0.5f) {
        showCursor = !showCursor;
        cursorClock.restart();
    }

    float estPlayerNameWidth = estimateTextRenderWidth(playerNameInputText);
    float estPlayerNameHeight = estimateTextRenderHeight(playerNameInputText);
    playerNameInputText.setOrigin(0, 0);
    playerNameInputText.setPosition(
        GameMechanics::WIN_W / 2.0f - estPlayerNameWidth / 2.0f,
        GameMechanics::WIN_H * 0.5f - estPlayerNameHeight / 2.0f
    );


    nameInputCursor.setPosition(
        playerNameInputText.getPosition().x + estPlayerNameWidth + 5.f,
        playerNameInputText.getPosition().y
    );
}

void Game::updateOptions() {
    optionsItems[0].setString("Sound: " + string(soundEnabled ? "ON" : "OFF"));
    float estSoundOptWidth = estimateTextRenderWidth(optionsItems[0]);
    float estSoundOptHeight = estimateTextRenderHeight(optionsItems[0]);
    optionsItems[0].setOrigin(0, 0);
    optionsItems[0].setPosition(
        GameMechanics::WIN_W / 2.0f - estSoundOptWidth / 2.0f,
        GameMechanics::WIN_H * 0.4f + 0 * 80.f - estSoundOptHeight / 2.0f
    );

    for (int i = 0; i < NUM_OPTIONS_ITEMS; ++i) {
        if (i == selectedOptionsItem) {
            optionsItems[i].setFillColor(Color::Yellow);
            optionsItems[i].setScale(1.1f, 1.1f);
        }
        else {
            optionsItems[i].setFillColor(Color::White);
            optionsItems[i].setScale(1.0f, 1.0f);
        }
    }
}

void Game::updatePlaying(const  Time& gameDeltaTime) {
    if (levelTransitioning) return;

    Player* leader_ptr = characterPtrs[currentPlayerIndex];
    leader_ptr->update(level, gameDeltaTime);


    if (leader_ptr->fellInPit) {
        leader_ptr->fellInPit = false;

        if (currentLevelNumber == 2 || currentLevelNumber == 3) {
          
              
            addToLeaderboard(currentPlayerName, scoreDisplay.getScore());
            setupStatusScreen("GAME OVER", "Fell into a deadly pit!\nPress Enter for Main Menu");
            statusMessageText.setFillColor(Color::Red);
            currentState.setGameOverState();
            return;
        }
        else {

            leader_ptr->handleGenericPitfall();
            \
        }
    }

    bool leaderIsFlying = false;
    if (Tails* tailsLeader = dynamic_cast<Tails*>(leader_ptr)) {
        leaderIsFlying = tailsLeader->isCurrentlyFlying();
    }

    const Level& constLevelView = level;

    Player* followers_to_update[2] = {
        characterPtrs[(currentPlayerIndex + 1) % 3],
        characterPtrs[(currentPlayerIndex + 2) % 3]
    };

    for (int i = 0; i < 2; ++i) {
        Player* follower = followers_to_update[i];
        if (!follower) continue;

        float followerX_before_update = follower->getX();

        if (leaderIsFlying && leader_ptr->getName() == "Tails") {

            float carryBaseX = leader_ptr->getX();
            float carryBaseY_bottom_of_carrier;

            if (i == 0) {
                carryBaseY_bottom_of_carrier = leader_ptr->getY() + leader_ptr->pH;
            }
            else {
                Player* firstActualFollower = followers_to_update[0];
                carryBaseY_bottom_of_carrier = firstActualFollower->getY() + firstActualFollower->pH;
            }

            float followerNewTopY = carryBaseY_bottom_of_carrier + GameMechanics::FOLLOWER_SPACING;

            follower->setPosition(carryBaseX, followerNewTopY - follower->hitY);


            follower->setVelocity(0, 0);
            follower->setForcedStill(true, leader_ptr->getFacingRight());
            follower->onGround = false;
            follower->updateTimers();
            follower->fellInPit = false;
        }
        else {

            follower->setForcedStill(false, follower->getFacingRight());

            follower->updateFollowing(*leader_ptr, constLevelView, i + 1, gameDeltaTime);
        }


        if (follower->fellInPit) {
            follower->fellInPit = false;

            if (currentLevelNumber == 2 || currentLevelNumber == 3) {
                
                float leaderX = leader_ptr->getX();
                float leaderY = leader_ptr->getY(); // Leader's current Y (top of sprite)
                float respawnX = 0.f;
                \
                    float respawnY = leaderY - GameMechanics::CELL * 0.5f;

                float relativeX_at_fall = followerX_before_update - leaderX;

                if (relativeX_at_fall > GameMechanics::CELL * 0.5f) {
                    respawnX = leaderX - 100 * GameMechanics::CELL;

                }
                else {
                    respawnX = leaderX + 100 * GameMechanics::CELL;

                }


                float minLevelPixelX = GameMechanics::CELL; // Min X to avoid spawning in left wall
                float maxLevelPixelX = (GameMechanics::getCurrentLevelCols(currentLevelNumber) * GameMechanics::CELL) - follower->pW - GameMechanics::CELL; // Max X
                respawnX = max(minLevelPixelX, min(respawnX, maxLevelPixelX));


                float minLevelPixelY = GameMechanics::CELL; // Min Y
                respawnY = max(minLevelPixelY, respawnY);


                follower->setPosition(respawnX, respawnY);
                follower->setVelocity(0, 0);
                follower->setInvincibilityTime(120.f);
                follower->onGround = false;
            }
            else {

                follower->handleGenericPitfall();
            }
        }
    }


    enemyManager.update(level, *leader_ptr, gameDeltaTime, scoreDisplay);
    ringManager.update(*leader_ptr, scoreDisplay);
    obstacleManager.update(*leader_ptr, scoreDisplay);
    itemManager.update(*leader_ptr, scoreDisplay);
    boosterManager.update(*leader_ptr);

    camX = leader_ptr->getX() - GameMechanics::WIN_W / 2.f;
    camX = max(camX, 0.f);
    float maxCamX = (float)GameMechanics::getCurrentLevelCols(level.getCurrentLevelNumber()) * GameMechanics::CELL - GameMechanics::WIN_W;
    if (maxCamX < 0) maxCamX = 0;
    camX = min(camX, maxCamX);

    checkGameOverConditions();
    if (currentState.isPlaying) {
        checkLevelCompletion();
    }
}

void Game::render() {
    window.clear(Color(50, 50, 150)); // Default dark blue background

    if (currentState.isShowingMenu) { drawMenu(); }
    else if (currentState.isEnteringName) { drawNameInput(); }
    else if (currentState.isShowingOptions) { drawOptions(); }
    else if (currentState.isShowingLeaderboard) { drawLeaderboardDisplay(); }
    else if (currentState.isPlaying) { drawPlaying(); }
    else if (currentState.isGameOver ||
        currentState.isLevelComplete ||
        currentState.isGameComplete) {
        drawStatusScreen();
    }
    window.display();
}

void Game::drawMenu() {
    window.draw(menuTitle);
    for (int i = 0; i < NUM_MENU_OPTIONS; ++i) window.draw(menuOptions[i]);
    window.draw(menuInstructions);
}

void Game::drawNameInput() {
    window.draw(namePromptText);
    window.draw(playerNameInputText);
    if (showCursor) window.draw(nameInputCursor);
}

void Game::drawOptions() {
    window.draw(optionsTitleText);
    for (int i = 0; i < NUM_OPTIONS_ITEMS; ++i) window.draw(optionsItems[i]);
}

void Game::drawLeaderboardDisplay() {
    window.draw(leaderboardTitleText);
    window.draw(leaderboardDisplayText);
    window.draw(leaderboardBackText);
}

void Game::drawPlaying() {
    window.clear(Color(100, 149, 237));

    level.draw(window, camX, (levelTimer ? levelTimer->getRemainingTime() : 0.f));
    ringManager.draw(window, camX);
    obstacleManager.draw(window, camX);
    itemManager.draw(window, camX);
    boosterManager.draw(window, camX);
    enemyManager.draw(window, camX);


    if (3 == 3) {
        characterPtrs[(currentPlayerIndex + 2) % 3]->draw(window, camX);
        characterPtrs[(currentPlayerIndex + 1) % 3]->draw(window, camX);
    }
    characterPtrs[currentPlayerIndex]->draw(window, camX);

    scoreDisplay.draw(window, *characterPtrs[currentPlayerIndex], currentPlayerName);

    if (levelTimer) {
        Text timerText;
        timerText.setFont(menuFont);
        timerText.setCharacterSize(30);
        timerText.setFillColor(Color::White);
        stringstream ss;
        ss << "Time: " << static_cast<int>(levelTimer->getRemainingTime());
        timerText.setString(ss.str());


        float timerOffsetFromRight = 150.f;
        timerText.setPosition(GameMechanics::WIN_W - timerOffsetFromRight, 20.f);
        window.draw(timerText);
    }
}

void Game::drawStatusScreen() {

    window.draw(statusMessageText);
    window.draw(continuePromptText);
}


void Game::switchPlayer() {
    if (levelTransitioning || 3 < 2) return;
  
    audioManager.playCharacterSwitchSound();
    Player* oldLeader = characterPtrs[currentPlayerIndex];
    float oldX = oldLeader->getX();
    float oldY = oldLeader->getY();

    oldLeader->setForcedStill(false, oldLeader->getFacingRight()); // Allow normal animation for old leader
    if (Tails* t = dynamic_cast<Tails*>(oldLeader)) {

    }

    currentPlayerIndex = (currentPlayerIndex + 1) % 3;
    Player* newLeader = characterPtrs[currentPlayerIndex];

    newLeader->setPosition(oldX, oldY);
    newLeader->setVelocity(0, 0);
    newLeader->setForcedStill(false, newLeader->getFacingRight());

   
}

void Game::setupLevel(int levelNum) {
    if (levelNum > GameMechanics::MAX_LEVELS) {
        audioManager.stopCurrentMusic();

        addToLeaderboard(currentPlayerName, scoreDisplay.getScore());
        setupStatusScreen("CONGRATULATIONS! YOU WIN!", "Press Enter for Main Menu");
        statusMessageText.setFillColor(Color::Green);
        currentState.setGameCompleteState();
        return;
    }


    levelTransitioning = true;
    currentLevelNumber = levelNum;
    audioManager.playMusicForLevel(currentLevelNumber);


    level.loadLevel(currentLevelNumber); // Load terrain, textures for the level

    // --- Level Timer Setup ---
    float timeLimitForLevel = 120.0f; // Default
    switch (levelNum) {
    case 1: timeLimitForLevel = 120.0f; break;
    case 2: timeLimitForLevel = 150.0f; break;
    case 3: timeLimitForLevel = 180.0f; break;
    case 4: timeLimitForLevel = 240.0f; break;
    }
    if (levelTimer) {
        levelTimer->reset();
    }
    else {
        levelTimer = new LevelTimer(timeLimitForLevel);
    }


    scoreDisplay.updateLevelDisplay(currentLevelNumber);
    scoreDisplay.setPlayerName(currentPlayerName);

    float startX = 150.f, startY = 600.f;
    if (levelNum == 4) {
        startX = GameMechanics::CELL * 5.f;
        startY = GameMechanics::CELL * 10.f;
    }

    for (size_t i = 0; i < 3; ++i) {
        Player* p_char = characterPtrs[i];
        if (p_char) {
            p_char->setPosition(startX - i * 40.f, startY);
            p_char->setVelocity(0, 0);
            p_char->setInvincibilityTime(0);
            p_char->startBoost(0);
            p_char->setForcedStill(false, true);

            if (Tails* t = dynamic_cast<Tails*>(p_char)) {

            }
        }
    }
    currentPlayerIndex = 0;


    ringManager.reset(currentLevelNumber);
    obstacleManager.reset(currentLevelNumber);
    itemManager.reset();
    boosterManager.reset();
    enemyManager.resetEnemies(currentLevelNumber, level);

    camX = 0;
    gameClock.restart();



    levelTransitioning = false;
    currentState.setPlayingState();

}

void Game::checkLevelCompletion() {
    if (!currentState.isPlaying || levelTransitioning) return;

    bool conditionsMet = false;
    if (currentLevelNumber == 4) {
        if (enemyManager.wasBossSpawned() &&
            !enemyManager.isSpecificEnemyActive("EggStinger")) {

            conditionsMet = true;
        }
    }
    else {
        if (scoreDisplay.getScore() >= GameMechanics::SCORE_PER_LEVEL * currentLevelNumber) {

            Player* leader = characterPtrs[currentPlayerIndex];
            float levelEndThreshold = (GameMechanics::getCurrentLevelCols(currentLevelNumber) - 5) * GameMechanics::CELL; // Example: last 5 cells
            if (leader->getX() > levelEndThreshold) {
               
                conditionsMet = true;
            }
        }
    }

    if (conditionsMet) {
       
        audioManager.stopCurrentMusic();
        audioManager.playLevelCompleteSound();
        nextLevel();
    }
}

void Game::nextLevel() {

    setupLevel(currentLevelNumber + 1);
}

void Game::resetGameForNewPlaythrough() {
  
    GameMechanics::initializeHealth();
    currentLevelNumber = 0;
    currentPlayerIndex = 0;
    scoreDisplay.resetScore();

}

void Game::checkGameOverConditions() {
    if (!currentState.isPlaying || levelTransitioning) return;

    bool gameOverTriggered = false;
    string reason;
    audioManager.stopCurrentMusic();
    Player* leader = characterPtrs[currentPlayerIndex];
    if (leader && leader->getHealth() <= 0) {
        gameOverTriggered = true;
        reason = "Ran out of lives!";
    }
    else if (levelTimer && levelTimer->isTimeUp()) {
        gameOverTriggered = true;
        reason = "Time's Up!";
    }

    if (gameOverTriggered) {
     
        addToLeaderboard(currentPlayerName, scoreDisplay.getScore());
        setupStatusScreen("GAME OVER", reason + "\nPress Enter for Main Menu");
        statusMessageText.setFillColor(Color::Red);
        currentState.setGameOverState();
    }
}

void Game::run() {
    while (window.isOpen()) {
        frameCount++;
        processEvents();

        Time deltaTime = frameRateClock.restart();


        update(deltaTime);
        render();
    }
}

int main() {


    Game g;
    g.run();
    return 0;




}
