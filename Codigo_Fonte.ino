
//PREPARANDO AS CONFIGURAÇÕES DO MODULO
#include <RTClib.h>               // BIBLIOTECA GERAL DOS MODULOS RTC 
#include <DS3231.h>               // BIBLIOTECA DO MODULO RTC DS3231

int Rele = 13;                    //PINO QUE SERÁ USADO O RELÉ
int led_vermelho = 12;            //PINO QUE SERÁ USADO NO LED DE DESLIGADO
int led_verde = 8;                //PINO QUE SERÁ USADO NO LED DE LIGADO

DS3231  rtc(SDA, SCL);            //APLICANDO A BIBLOTECA AO MODULO RTC DS3231
Time t;                           //DANDO UM NOME AO MODULO QUE SERÁ UTLIZADO

const int HorarioLigado = 23;      //HORA EM QUE ESTARÁ LIGADO O RELÉ
const int MinutoLigado = 18;       //MINUTO EM QUE ESTARÁ LIGADO O RELÉ
const int HorarioDesligado = 23;   //HORA EM QUE ESTARÁ DESLIGADO O RELÉ
const int MinutoDesligado = 20;    //MINUTO EM QUE ESTARÁ DESLIGADO O RELÉ

//_______________________________________________________________________________________________________________________________

//CONFIGURANDO PARAMETROS DO MODULO
void setup() 
  {
  Serial.begin(9600);              // CONFIGURAÇÃO PARA MOSTRAR DADOS NO MONITOR SERIAL
  rtc.begin();                     // AJUSTE DA SAÍDA DE DADOS
  pinMode(Rele, OUTPUT);           //O PINO DO RELÉ SERÁ DE SAIDA
  digitalWrite(Rele, LOW);         //O PINO COMEÇARA LIGADO
  }
  
//_______________________________________________________________________________________________________________________________

//CONFIGURANDO SAIDA DE DADOS DO MODULO
void loop() 
{
  t = rtc.getTime();               //CHAMANDO OS DADOS DO MUDULO
  Serial.print(t.hour);            //COMANDO PARA CHAMAR AS HORAS
  Serial.print(" Hora(s), ");      //SAIDA DE DADOS DAS HORAS NO MONITOR SERIAL
  Serial.print(t.min);             //COMANDO PARA CHAMAR OS MINUTOS
  Serial.print(" Minuto(s)");      //SAIDA DE DADOS DOS MINUTOS NO MONITOR SERIAL
  Serial.println(" ");             //AJUSTE NA SAIDA DE DADOS
  delay (1000);                    //ATUALIZAÇÃO DE DADOS A CADA 1 SEGUNDO

//_______________________________________________________________________________________________________________________________
 
  //CONDIÇÃO PARA LIGAR A LAMPADA
  if(t.hour == HorarioLigado && t.min == MinutoLigado)                   //COMPARAÇÃO DE DADOS PARA LIGAR RELE/LED
    {
    digitalWrite(Rele,HIGH);                  //LIGAR O RELE
    digitalWrite(led_verde,HIGH);             //LIGAR LED VERDE
    digitalWrite(led_vermelho,LOW);           //DESLIGAR LED VERMELHO
    Serial.println("Luz Ligada");             //SAÍDA DE DADOS NOMONITOR SERIAL
    }
    
    //CONDIÇÃO PARA DESLIGADA A LAMPADA
    else if(t.hour == HorarioDesligado && t.min == MinutoDesligado)      //COMPARAÇÃO DE DADOS PARA DESLIGAR RELE/LED
    {
      digitalWrite(Rele,LOW);                //DESLIGA O RELE
      digitalWrite(led_vermelho,HIGH);       //LIGAR LED VERMELHO 
      digitalWrite(led_verde,LOW);           //DESLIGAR LED VERDE
      Serial.println("Luz Desligada");       //SAÍDA DE DADOS NOMONITOR SERIAL
    }
}
