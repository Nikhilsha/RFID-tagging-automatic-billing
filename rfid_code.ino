#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
String list[10];
int i=0;
void setup() 
{
  Serial.begin(9600);   // Initiate a serial communication
  SPI.begin();      // Initiate  SPI bus
  mfrc522.PCD_Init();   // Initiate MFRC522
  Serial.println("Approximate your card to the reader...");
  Serial.println();

}
void loop() 

{ String response = "";
  while (Serial.available()) {
    response = Serial.read();
    if(response=='s')
    {  printbill();
      }
}
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Show UID on serial monitor
  Serial.print("UID tag :");
  String content= "";
  byte letter;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
     Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
     Serial.print(mfrc522.uid.uidByte[i], HEX);
     content.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     content.concat(String(mfrc522.uid.uidByte[i], HEX));
  }
  content.toUpperCase();
 list[i]=content.substring(1)
 i++;
}
void printbill()
{
 int sum=0
 String list2[3]={"4D 75 D5 E5","FB AF D4 E5","0C 88 D4 E5"};
 int price[3]={100,50,40};
 String product[3]={"limca","pepsi","coke"};
  for(int j=0;j<3;j++)
     {
       for(int k=0;k<3;k++)
       { 
        if(list[j]==list2[k])
          {
            Serial.println(product[k]+"   "+(String)price[k]);
            sum=sum+price[k];
            }
        }
      }
      Serial.println("total:");
      Serial.println(sum);
  }  
  
