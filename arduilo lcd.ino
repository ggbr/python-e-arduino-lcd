//Programa: Teste de Display LCD 16 x 2
//Autor: FILIPEFLOP

//Carrega a biblioteca LiquidCrystal
#include <LiquidCrystal.h>

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
long byteRead;
int ini  = 0;
void setup()
{
  //Define o número de colunas e linhas do LCD
  lcd.begin(16, 2);
  Serial.begin(9600);
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



if (Serial.available())  //verifica se tem dados diponível para leitura
  {
   String recebido = leStringSerial();
     lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print(recebido);
    
  }
    
  
}