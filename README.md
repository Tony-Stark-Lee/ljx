# -17030130043 李俊潇
## 第一天
## 第二天

#### 学习内容：编程

· Morse.h

#ifndef Morse_h
#define Morse_h

#include "Arduino.h"

class Morse{
public:
    Morse(int pin);
    void dot();
    void dash();
    void w_space();
    void c_space();
private:
    int _pin;
};

#endif

· Morse.cpp

#include"Arduino.h"
#include"Morse.h"

Morse::Morse(int pin){
    pinMode(pin,OUTPUT);
    _pin=pin;
}

void Morse::dot(){
    digitalWrite(_pin,HIGH);
    delay(250);
    digitalWrite(_pin,LOW);
    delay(250);
}

void Morse::dash(){
    digitalWrite(_pin,HIGH);
    delay(1000);
    digitalWrite(_pin,LOW);
    delay(250);
}

void Morse::w_space(){
    digitalWrite(_pin,LOW);
    delay(1000);
}

void Morse::c_space(){
    digitalWrite(_pin,LOW);
    delay(250);
}

· Morse.ino

#include <Morse.h>

Morse morse(13);

char MORSE[][4]={
  {'.','_','*','*'},//A
  {'_','.','.','.'},//B
  {'_','.','_','.'},//C
  {'_','.','.','*'},//D
  {'.','*','*','*'},//E
  {'.','.','_','.'},//F
  {'_','_','.','*'},//G
  {'.','.','.','.'},//H
  {'.','.','*','*'},//I
  {'.','_','_','_'},//J
  {'_','.','_','*'},//K
  {'.','_','.','.'},//L
  {'_','_','*','*'},//M
  {'_','.','*','*'},//N
  {'_','_','_','*'},//O
  {'.','_','_','.'},//P
  {'_','_','.','_'},//Q
  {'.','_','.','*'},//R
  {'.','.','.','*'},//S
  {'_','*','*','*'},//T
  {'.','.','_','*'},//U
  {'.','.','.','_'},//V
  {'.','_','_','*'},//W
  {'_','.','.','_'},//X
  {'_','.','_','_'},//Y
  {'_','_','.','.'},//Z
  };

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  String str="";
  String morse_s="";
  int i,t,temp=0;
  int n=0;
  while(Serial.available()>0){
    temp=1;
    str+=char(Serial.read());
    delay(2);
    n++;
    }

  if(temp){
    for(i=0;i<n;i++){
      for(t=0;t<4;t++){
        if(str[i]>=97&&str[i]<=122){
          morse_s+=char(MORSE[int(str[i]-97)][t]);
          }
        }
        morse_s+=' ';
      }
    Serial.println(morse_s);
    for(i=0;morse_s[i]!='\0';i++){
      if(morse_s[i]=='.') morse.dot();
      else if(morse_s[i]=='_') morse.dash();
      else if(morse_s[i]==' ') morse.w_space();
      if(morse_s[i]!=' '&&str[i]!='*') morse.c_space();
      }  
      Serial.println("Sending successed");
      delay(2);
    }
}

## 第三天
摩斯密码：7月3日作业
小车：7月4日课堂作业
CD4511: 7月4日作业
