#include <LiquidCrystal_I2C.h>
#include <Wire.h>
#include <string>

#define SDA 14                    //Define SDA pins
#define SCL 13                    //Define SCL pins

using namespace std;

/*
 * note:If lcd1602 uses PCF8574T, IIC's address is 0x27,
 *      or lcd1602 uses PCF8574AT, IIC's address is 0x3F.
*/
LiquidCrystal_I2C lcd(0x27,16,2); 


string ConstSong = "CIRCUS MAXIMUM (feat. The Weeknd & Swae Lee)";
string ConstArtist = "Travis Scott, The Weeknd, Swae Lee";

void setup() {
  Wire.begin(SDA, SCL);           // attach the IIC pin
  if (!i2CAddrTest(0x27)) {
    lcd = LiquidCrystal_I2C(0x3F, 16, 2);
  }
  lcd.init();                     // LCD driver initialization
  lcd.backlight();                // Open the backlight
}

void loop() {

  string Song = ConstSong;
  string Artist = ConstArtist;

  lcd.clear();

  lcd.setCursor(0,0);
  lcd.print(Song.c_str());

  lcd.setCursor(0, 1);
  lcd.print("By: ");
  lcd.print(Artist.c_str());

  delay(1000);

  if (Song.length() >= 16) {
    songDisplay(Song, Artist);
    }

  if (Artist.length()>=16){
    artistDisplay(Song, Artist);
  }

}

void songDisplay(string Song, string Artist) {
  Song+= " ";
    for (int i = 0; i < Song.length()+1; i++) { //for length of song
      delay(300); 

      // Shift the song title left
      Song = Song.substr(1) + Song[0];

      // Update LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(Song.c_str());

      lcd.setCursor(0, 1);
      lcd.print("By: ");
      lcd.print(Artist.c_str());
  }
}

void artistDisplay(string Song, string Artist) {
  Artist+= " ";
    for (int i = 0; i < Artist.length()+1; i++) { //for length of song
      delay(300); 

      // Shift the song title left
      Artist = Artist.substr(1) + Song[0];

      // Update LCD display
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print(Song.c_str());

      lcd.setCursor(0, 1);
      lcd.print("By: ");
      lcd.print(Artist.c_str());
  }
}

bool i2CAddrTest(uint8_t addr) {
  Wire.begin();
  Wire.beginTransmission(addr);
  if (Wire.endTransmission() == 0) {
    return true;
  }
  return false;
}