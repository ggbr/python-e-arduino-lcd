

//Autor: Gabriel Sousa Dos Santos


#include <LiquidCrystal.h>
#include <IRremote.h>  
#include <Servo.h>
 
#define SERVO 6 // Porta Digital 6 PWM
 
Servo s; // Variável Servo
int pos; // Posição Servo

  
int RECV_PIN = 10;  
float armazenavalor;  

  
IRrecv irrecv(RECV_PIN);  
decode_results results;  

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
long byteRead;
int ini  = 0;

// alto falante 

int speakerPin = 9;
 
int length = 15; // número de notas
char notes[] = "ccggaagffeeddc "; // espaços representam pausas
int beats[] = { 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 2, 4 };
int tempo = 300;
 
void playTone(int tone, int duration) {
  for (long i = 0; i < duration * 1000L; i += tone * 2) {
    digitalWrite(speakerPin, HIGH);
    delayMicroseconds(tone);
    digitalWrite(speakerPin, LOW);
    delayMicroseconds(tone);
  }
}
 
void playNote(char note, int duration) {
  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 };
 
  // toque o tom correspondente ao nome da nota
  for (int i = 0; i < 8; i++) {
    if (names[i] == note) {
      playTone(tones[i], duration);
    }
  }
}







void setup()
{
   pinMode(speakerPin, OUTPUT);
  s.attach(SERVO);
  irrecv.enableIRIn(); // Inicializa o receptor IR  
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
  s.write(0); // Inicia motor posição zero
}



/**
 * Função que lê uma string da Serial
 * e retorna-a
 */
String leStringSerial(){
  String conteudo = "";
  char caractere;
  
  // Enquanto receber algo pela serial
  while(Serial.available() > 0) {
    // Lê byte da serial
    caractere = Serial.read();
    // Ignora caractere de quebra de linha
    if (caractere != '\n'){
      // Concatena valores
      conteudo.concat(caractere);
    }
    // Aguarda buffer serial ler próximo caractere
    delay(10);
  }
    
  Serial.print("Recebi: ");
  Serial.println(conteudo);
    
  return conteudo;
}


void loop()
{
  // primeiro programa a rodar quando o arduino liga 
  if(ini == 0){
      //Limpa a tela
      lcd.clear();
      //Posiciona o cursor na coluna 3, linha 0;
      lcd.setCursor(3, 0);
      //Envia o texto entre aspas para o LCD
      lcd.print("Fab Lab");
      lcd.setCursor(3, 1);
      lcd.print(" COMUJUV");
      delay(5000);
      ini = 1;
    }
    // -##################################################


//########  Leitura da porta USB ##########################
if (Serial.available()){  //verifica se tem dados diponível para leitura
   String recebido = leStringSerial();
   switch(recebido[0]){ 
        case '2' :
          lcd.setCursor(0, 0);
        break;
        case '3':
          lcd.setCursor(0, 1);
          break;
        case '4':
          lcd.clear();
          break;
        case '5':
          lcd.clear();
          break;
         case '6':
          

            for(pos = 0; pos < 90; pos++){
                    s.write(pos);
                    delay(10);
                  }
                for(pos = 90; pos >= 0; pos--)  {
                 s.write(pos);
                 delay(10);
                }for(pos = 0; pos < 90; pos++){
                    s.write(pos);
                    delay(10);
                  }
                for(pos = 90; pos >= 0; pos--)  {
                 s.write(pos);
                 delay(10);
                }for(pos = 0; pos < 90; pos++){
                    s.write(pos);
                    delay(10);
                  }
                for(pos = 90; pos >= 0; pos--)  {
                 s.write(pos);
                 delay(10);
                }


          break;
          case '7':
          for (int i = 0; i < length; i++) {
              if (notes[i] == ' ') {
                delay(beats[i] * tempo); // rest
              } else {
                playNote(notes[i], beats[i] * tempo);
              }
           
              // pausa entre notas
              delay(tempo / 2);
            }

        break;
        default:
          lcd.print(recebido);
        break;
      }     
  } 

if (irrecv.decode(&results)){  
    Serial.print("Valor lido : ");  
    Serial.println(results.value, HEX);  
    armazenavalor = (results.value);  
     if (armazenavalor == 0xFFA857) //Verifica se a tecla 9 foi acionada  
    {  
          //Rolagem para a esquerda
      for (int posicao = 0; posicao < 3; posicao++)
      {
        lcd.scrollDisplayLeft();
        delay(300);
      }
    }  

       if (armazenavalor == 0xFFE01F) //Verifica se a tecla 9 foi acionada  
    {  
          //Rolagem para a direita
      for (int posicao = 0; posicao < 6; posicao++)
      {
        lcd.scrollDisplayRight();
        delay(300);
      }
    } 

 if (armazenavalor == 0xFF6897) //Verifica se a tecla 9 foi acionada  
    {  

   //Limpa a tela
      lcd.clear();
      //Posiciona o cursor na coluna 3, linha 0;
      lcd.setCursor(3, 0);
      lcd.print("Meu Nome  e");
      lcd.setCursor(3, 1);
      lcd.print("ComuTech");

    }  
   
    
 if (armazenavalor == 0xFF02FD) //Verifica se a tecla 9 foi acionada  
    {  
    
  }  




    
     irrecv.resume(); //Le o próximo valor 
      
  }  

}
