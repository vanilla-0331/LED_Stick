#include <FastLED.h>

/* マクロ定義 */
#define NUM_LEDS 45
#define SW1_PIN 12
#define SW2_PIN 8
#define DIN_PIN 4

/* 変数の宣言 */
int color = 1;         // 初期値メンバーカラー用
int s = 100;           // LEDのスピード制御用
int brightness = 50;   // LEDの光量制御用
bool setLED = true;    // LEDの発光制御用
bool mode1 = false;    // sw1の制御用
bool mode2 = false;    // sw2の制御用 

/* 各色の定義 */
CRGB leds[NUM_LEDS];
CRGB black        = CRGB(0, 0, 0);
CRGB red          = CRGB(255, 0, 0);
CRGB dark_orange  = CRGB(255, 40, 0);
CRGB light_orange = CRGB(255, 80, 0);
CRGB orange       = CRGB(255, 160, 0);
CRGB yellow       = CRGB(255, 255, 0);
CRGB light_yellow = CRGB(160, 255, 0);
CRGB yellow_green = CRGB(128, 255, 0);
CRGB light_green  = CRGB(60, 255, 0);
CRGB green        = CRGB(0, 255, 0);
CRGB cyan_green   = CRGB(0, 255, 40);
CRGB blue_green   = CRGB(0, 255, 128);
CRGB cyan         = CRGB(0, 255, 255);
CRGB sky_blue     = CRGB(0, 128, 255);
CRGB blue         = CRGB(0, 0, 255);
CRGB light_blue   = CRGB(40, 0, 255);
CRGB violet       = CRGB(128, 0, 255);
CRGB purple       = CRGB(255, 0, 255);
CRGB light_purple = CRGB(255, 0, 160);
CRGB pink         = CRGB(255, 0, 80);
CRGB light_pink   = CRGB(255, 0, 40);

/* 各メンバー色の定義 */
CRGB ayumu    = CRGB(255, 100, 120);
CRGB kasumi   = CRGB(255, 255, 40);
CRGB shizuku  = CRGB(120, 120, 255);
CRGB karin    = CRGB(0, 0, 255);
CRGB ai       = CRGB(255, 50, 0);
CRGB kanata   = CRGB(255, 80, 255);
CRGB setsuna  = CRGB(255, 0 ,0);
CRGB ema      = CRGB(120, 255, 40);
CRGB rina     = CRGB(255, 0, 120);
CRGB shioriko = CRGB(40, 255, 80);
CRGB taylor   = CRGB(255, 255, 255);
CRGB lanzhu   = CRGB(255, 90, 90); 


void setup() 
{
  FastLED.addLeds < WS2811, DIN_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(brightness);
  pinMode(SW1_PIN, INPUT_PULLUP);
  pinMode(SW2_PIN, INPUT_PULLUP);
}

void loop() 
{
  if(mode1)
  {
    /* 光量調節 */
    brightness = (brightness + 20) % 100;
    FastLED.setBrightness(brightness);
    FastLED.show();
    mode1 = false;
  }
  if(setLED)
  {
    /* 色変更 */
    sw1();
  }
  /* スイッチの動作 */
  switch_judge();
  delay(50);  
}

/* スイッチを読み取りフラグ操作 */
void switch_judge()
{
  /* sw1の判定 */
  if(digitalRead(SW1_PIN) == LOW)
  {
    int time_counter = 0;   // 短押しか長押しかを判定する用のカウンター
    while(digitalRead(SW1_PIN) == LOW)
    {
      time_counter++;
      delay(5);   
    }
    /* 長押ししたら，光量調節モード */
    if(time_counter > 50){
      mode1 = true;
    }
    else
    {
      /* sw1を押して離すと，色を１つ進める */
      color++;
      /* 再度，点灯しなおす */
      setLED = true;
    }
  }

  /* sw2の判定 */
  if(digitalRead(SW2_PIN) == LOW)
  {
    int time_counter = 0;   // 短押しか長押しかを判定する用のカウンター
    while(digitalRead(SW2_PIN) == LOW)
    {
      time_counter++;
      delay(5);
    }         
    /* 長押ししたら，スピード調節モード */
    if(time_counter > 50)
    {
      if(s > 15)
      {
        s = (s - 45);
      }
      else
      {
        if(s == 10)
        {
          /* スピード調節は現在3段階 */
          s = 100;
        }
      }
    }
    else
    {
      if(!mode2)
      {
        /* sw2を押して離すと，色を１つ戻す */
        color--;
        /* 再度，点灯しなおす */
        setLED = true;
      }
    }
  }
  /* もし虹色でsw1を単押ししたら赤色に進む */
  if(color > 35)
  {
    color = 1;
  }
  /* もし赤色でsw2を単押ししたら虹色に戻る */
  if(color < 1)
  {
    color = 35;
  }
}

void sw1()
{ 
  switch(color)
  {
    case 1: Ayumu();
            break;
    case 2: Kasumi();
            break;
    case 3: Shizuku();
            break;
    case 4: Karin();
            break;
    case 5: Ai();
            break;
    case 6: Kanata();
            break;
    case 7: Setsuna();
            break;
    case 8: Ema();
            break;
    case 9: Rina();
            break;
    case 10: Shioriko();
            break;
    case 11: Taylor();
            break;
    case 12: Lanzhu();
            break; 
    case 13: DiverDiva_1();
            break;
    case 14: DiverDiva_2();
            break;
    case 15: AZUNA();
            break;
    case 16: QU4RTZ_1();
            break;
    case 17: QU4RTZ_2();
            break;
    case 18: R3BIRTH();
            break;  
    case 19: first_grade_1();
            break;
    case 20: first_grade_2();
            break;
    case 21: second_grade();
            break;
    case 22: third_grade();
            break;               
    case 23: rainbow();
            break;   
    case 24: Ayumu_night_rider();
            break;
    case 25: Kasumi_night_rider();
            break;
    case 26: Shizuku_night_rider();
            break;
    case 27: Karin_night_rider();
            break;
    case 28: Ai_night_rider();
            break;
    case 29: Kanata_night_rider();
            break;   
    case 30: Setsuna_night_rider();
            break;
    case 31: Ema_night_rider();
            break;
    case 32: Rina_night_rider();
            break;
    case 33: Shioriko_night_rider();
            break;
    case 34: Taylor_night_rider();
            break;
    case 35: Lanzhu_night_rider();     
            break;
  }
}

void sw2(bool long_judge)
{ 
  /* 短押し時は1つ色を戻す */
  if(!long_judge)
  {
    color--;
    sw1();
  }
}

void LED_show()
{
  FastLED.show();
  delay(s);
}

void sw_judge()
{
  int count = 0;
  while(true)
  {
    /* 表示中でもボタン操作を受けつける */
    switch_judge();
    //delay(10);
    time_counter++;
    if(time_counter > 100)
    {
      break;
    }
  }
}

void Ayumu()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = ayumu; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Kasumi()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = kasumi; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Shizuku()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = shizuku; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Karin()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = karin; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Ai()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = ai; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Kanata()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = kanata; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Setsuna()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = setsuna; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Ema()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = ema; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Rina()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = rina; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Shioriko()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = shioriko; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Taylor()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = taylor; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Lanzhu()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < NUM_LEDS; i++)
    {
      leds[i] = lanzhu; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void DiverDiva_1()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      leds[i] = karin; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 16; i++)
    {
      leds[i] = karin; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 16; i < 22; i++)
    {
      leds[i] = ai; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    
    for(int i = 22; i < 39; i++)
    {
      leds[i] = ai; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = taylor;  //白色
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void DiverDiva_2()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      leds[i] = karin; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 22; i++)
    {
      leds[i] = ai; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    
    for(int i = 22; i < 39; i++)
    {
      leds[i] = karin; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = ai;
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void AZUNA()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      leds[i] = setsuna; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 22; i++)
    {
      leds[i] = shizuku; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 22; i < 39; i++)
    {
      leds[i] = ayumu; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = taylor;  //白色
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void QU4RTZ_1()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      //leds[i] = rina; 
      leds[i] = taylor; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 22; i++)
    {
      leds[i] = kanata; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 22; i < 39; i++)
    {
      leds[i] = ema; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = kasumi;
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void QU4RTZ_2()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      leds[i] = rina; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 22; i++)
    {
      leds[i] = kanata; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 22; i < 39; i++)
    {
      leds[i] = ema; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = kasumi;
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void R3BIRTH()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      leds[i] = lanzhu; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 22; i++)
    {
      leds[i] = taylor; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 22; i < 39; i++)
    {
      leds[i] = shioriko; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = taylor;
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void first_grade_1()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      leds[i] = shioriko; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 22; i++)
    {
      leds[i] = taylor; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 22; i < 39; i++)
    {
      leds[i] = shizuku; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = kasumi;
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void first_grade_2()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      leds[i] = shioriko; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 22; i++)
    {
      leds[i] = rina; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 22; i < 39; i++)
    {
      leds[i] = shizuku; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = kasumi;
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void second_grade()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      leds[i] = lanzhu; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 22; i++)
    {
      leds[i] = ai; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 22; i < 39; i++)
    {
      leds[i] = setsuna; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = ayumu;
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void third_grade()
{
  if(setLED)
  {
    FastLED.clear();  
    for(int i = 0; i < 9; i++)
    {
      leds[i] = taylor; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 9; i < 22; i++)
    {
      leds[i] = karin; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒
    }
    for(int i = 22; i < 39; i++)
    {
      leds[i] = kanata; 
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }
    for(int i = 39; i < NUM_LEDS; i++)
    {
      leds[i] = ema;
      FastLED.show(); 
      delay(s);               // 10ミリ秒＝0.01秒      
    }    
  }
  /* 点灯の制御処理を変更 */
  setLED = false;  
}

void rainbow()
{
  if(setLED)
  {
    FastLED.clear();
    leds[0] = red; LED_show();
    leds[1] = dark_orange; LED_show();
    leds[2] = light_orange; LED_show();
    leds[3] = orange; LED_show();
    leds[4] = yellow; LED_show();
    leds[5] = light_yellow; LED_show();
    leds[6] = yellow_green; LED_show();
    leds[7] = light_green; LED_show();
    leds[8] = green; LED_show();
    leds[9] = cyan_green; LED_show();
    leds[10] = blue_green; LED_show();
    leds[11] = cyan; LED_show();
    leds[12] = sky_blue; LED_show();
    leds[13] = blue; LED_show();
    leds[14] = light_blue; LED_show();
    leds[15] = violet; LED_show();
    leds[16] = purple; LED_show();
    leds[17] = light_purple; LED_show();
    leds[18] = pink; LED_show();
    leds[19] = light_pink; LED_show();
    leds[20] = red; LED_show();
    leds[21] = dark_orange; LED_show();
    leds[22] = light_orange; LED_show();
    leds[23] = orange; LED_show();
    leds[24] = yellow; LED_show();
    leds[25] = light_yellow; LED_show();
    leds[26] = yellow_green; LED_show();
    leds[27] = light_green; LED_show();
    leds[28] = green; LED_show();
    leds[29] = cyan_green; LED_show();
    leds[30] = blue_green; LED_show();
    leds[31] = cyan; LED_show();
    leds[32] = sky_blue; LED_show();
    leds[33] = blue; LED_show();
    leds[34] = light_blue; LED_show();
    leds[35] = violet; LED_show();
    leds[36] = purple; LED_show();
    leds[37] = light_purple; LED_show();
    leds[38] = pink; LED_show();
    leds[39] = light_pink; LED_show();
    leds[40] = red; LED_show();
    leds[41] = dark_orange; LED_show();
    leds[42] = light_orange; LED_show();
    leds[43] = orange; LED_show();
    leds[44] = yellow; LED_show();
  }
  /* 点灯の制御処理を変更 */
  setLED = false;
}

void Ayumu_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = ayumu;
    leds[i + 1] = ayumu;
    leds[i + 2] = ayumu;
    leds[i + 3] = ayumu;
    leds[i + 4] = ayumu;
    leds[i + 5] = ayumu;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = ayumu;
    leds[i + 1] = ayumu;
    leds[i + 2] = ayumu;
    leds[i + 3] = ayumu;
    leds[i + 4] = ayumu;
    leds[i + 5] = ayumu;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Kasumi_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = kasumi;
    leds[i + 1] = kasumi;
    leds[i + 2] = kasumi;
    leds[i + 3] = kasumi;
    leds[i + 4] = kasumi;
    leds[i + 5] = kasumi;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = kasumi;
    leds[i + 1] = kasumi;
    leds[i + 2] = kasumi;
    leds[i + 3] = kasumi;
    leds[i + 4] = kasumi;
    leds[i + 5] = kasumi;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Shizuku_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = shizuku;
    leds[i + 1] = shizuku;
    leds[i + 2] = shizuku;
    leds[i + 3] = shizuku;
    leds[i + 4] = shizuku;
    leds[i + 5] = shizuku;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = shizuku;
    leds[i + 1] = shizuku;
    leds[i + 2] = shizuku;
    leds[i + 3] = shizuku;
    leds[i + 4] = shizuku;
    leds[i + 5] = shizuku;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Karin_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = karin;
    leds[i + 1] = karin;
    leds[i + 2] = karin;
    leds[i + 3] = karin;
    leds[i + 4] = karin;
    leds[i + 5] = karin;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = karin;
    leds[i + 1] = karin;
    leds[i + 2] = karin;
    leds[i + 3] = karin;
    leds[i + 4] = karin;
    leds[i + 5] = karin;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Ai_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = ai;
    leds[i + 1] = ai;
    leds[i + 2] = ai;
    leds[i + 3] = ai;
    leds[i + 4] = ai;
    leds[i + 5] = ai;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = ai;
    leds[i + 1] = ai;
    leds[i + 2] = ai;
    leds[i + 3] = ai;
    leds[i + 4] = ai;
    leds[i + 5] = ai;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Kanata_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = kanata;
    leds[i + 1] = kanata;
    leds[i + 2] = kanata;
    leds[i + 3] = kanata;
    leds[i + 4] = kanata;
    leds[i + 5] = kanata;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = kanata;
    leds[i + 1] = kanata;
    leds[i + 2] = kanata;
    leds[i + 3] = kanata;
    leds[i + 4] = kanata;
    leds[i + 5] = kanata;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Setsuna_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = setsuna;
    leds[i + 1] = setsuna;
    leds[i + 2] = setsuna;
    leds[i + 3] = setsuna;
    leds[i + 4] = setsuna;
    leds[i + 5] = setsuna;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = setsuna;
    leds[i + 1] = setsuna;
    leds[i + 2] = setsuna;
    leds[i + 3] = setsuna;
    leds[i + 4] = setsuna;
    leds[i + 5] = setsuna;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Ema_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = ema;
    leds[i + 1] = ema;
    leds[i + 2] = ema;
    leds[i + 3] = ema;
    leds[i + 4] = ema;
    leds[i + 5] = ema;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = ema;
    leds[i + 1] = ema;
    leds[i + 2] = ema;
    leds[i + 3] = ema;
    leds[i + 4] = ema;
    leds[i + 5] = ema;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Rina_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = rina;
    leds[i + 1] = rina;
    leds[i + 2] = rina;
    leds[i + 3] = rina;
    leds[i + 4] = rina;
    leds[i + 5] = rina;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = rina;
    leds[i + 1] = rina;
    leds[i + 2] = rina;
    leds[i + 3] = rina;
    leds[i + 4] = rina;
    leds[i + 5] = rina;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Shioriko_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = shioriko;
    leds[i + 1] = shioriko;
    leds[i + 2] = shioriko;
    leds[i + 3] = shioriko;
    leds[i + 4] = shioriko;
    leds[i + 5] = shioriko;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = shioriko;
    leds[i + 1] = shioriko;
    leds[i + 2] = shioriko;
    leds[i + 3] = shioriko;
    leds[i + 4] = shioriko;
    leds[i + 5] = shioriko;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Taylor_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = taylor;
    leds[i + 1] = taylor;
    leds[i + 2] = taylor;
    leds[i + 3] = taylor;
    leds[i + 4] = taylor;
    leds[i + 5] = taylor;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = taylor;
    leds[i + 1] = taylor;
    leds[i + 2] = taylor;
    leds[i + 3] = taylor;
    leds[i + 4] = taylor;
    leds[i + 5] = taylor;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}

void Lanzhu_night_rider()
{
  for(int i = 0; i <= NUM_LEDS - 6; i++)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = lanzhu;
    leds[i + 1] = lanzhu;
    leds[i + 2] = lanzhu;
    leds[i + 3] = lanzhu;
    leds[i + 4] = lanzhu;
    leds[i + 5] = lanzhu;
    LED_show();
    leds[i] = black;
    LED_show();
  }

  for(int i = NUM_LEDS - 6; i >= 0; i--)
  {
    if(digitalRead(SW1_PIN) == LOW || digitalRead(SW2_PIN) == LOW)
    {
      sw_judge();
    }
    leds[i] = lanzhu;
    leds[i + 1] = lanzhu;
    leds[i + 2] = lanzhu;
    leds[i + 3] = lanzhu;
    leds[i + 4] = lanzhu;
    leds[i + 5] = lanzhu;
    LED_show();
    if(i > 0)
    {
      leds[i + 5] = black;
      FastLED.show();
    }
    else
    {
      break;
    }
    delay(5);
  }
}
