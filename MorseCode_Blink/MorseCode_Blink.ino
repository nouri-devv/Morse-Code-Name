#include <iostream>
#include <map>
#include <string>
using namespace std;

void setup() {

  // put your setup code here, to run once:
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  MorseName("MOSTAFA");
}

void Dot(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100*1);
  digitalWrite(LED_BUILTIN, LOW);
}

void Dash () {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(100*3);
  digitalWrite(LED_BUILTIN, LOW);
}

void LetterSpace (){
  delay(100*3);
}

void WordSpace (){
  delay(100*7);
}

void IDK (std::string m){
  int n = sizeof(m);

  for (int i = 0; i < n; i++){
    if (m[i] == '-'){
      Dash();
    }
    if (m[i] == '.'){
      Dot();
    }
  }
}

void MorseName (std::string name){
  std::map<std::string, std::string> lettersMap = {
        {"A", ".-"}, {"B", "-..."}, {"C", "-.-."}, {"D", "-.."}, {"E", "."}, {"F", "..-."},
        {"G", "--."}, {"H", "...."}, {"I", ".."}, {"J", ".---"}, {"K", "-.-"}, {"L", ".-.."},
        {"M", "--"}, {"N", "-."}, {"O", "---"}, {"P", ".--."}, {"Q", "--.-"}, {"R", ".-."},
        {"S", "..."}, {"T", "-"}, {"U", "..-"}, {"V", "...-"}, {"W", ".--"}, {"X", "-..-"},
        {"Y", "-.--"}, {"Z", "--.."}, {" ", "+"}
    };

  int n = sizeof(name);

  for (int i = 0; i < n; i++){
    //Serial.println(name);
    std::string letter = lettersMap[name.substr(i, 1)];
    IDK(letter);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(250);
    digitalWrite(LED_BUILTIN, LOW);
    LetterSpace();
  }
}
