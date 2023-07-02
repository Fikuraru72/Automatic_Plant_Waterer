//Penyiram tanaman otomatis

const int pinDigital = A0; //inisialisasi pin sensor
const int relay = 8;       //inisialisasi pin relay 

void setup() {
Serial.begin (9600);          //memanggil serial monitor
pinMode(pinDigital, INPUT);   //menetapkan pin A0 sebagai input
pinMode(relay, OUTPUT);       //menetapkan pin 6 sebagai output

}

void loop() {
int dataAnalog = analogRead (pinDigital);  //membaca nilai dari pin sensor
//print hasil ke serial monitor
Serial.print ("A0 : ");
Serial.print (dataAnalog);

//jika nilai A0 kurang dari 500, print kata serta nyalakan led hijau dan matikan led kuning, merah dan juga relay
if (dataAnalog < 350) { 
  Serial.println(". Media Masih Basah"); 
  digitalWrite (relay, LOW);
  }

 //tetapi, jika nilai A0 kurang dari 900, print kata serta nyalakan led kuning dan relay kemudian matikan led hijau dan juga merah
 else if (dataAnalog  <762 ) {
  Serial.println(". Kelembaban Tanah Masih Cukup"); 
  digitalWrite (relay, LOW);
  }

 //selain dari itu, hanya nyalakan led merah dan juga relay
 else if (dataAnalog > 827)
 { Serial.println ("Kekurangan Air"); 
  digitalWrite (relay, HIGH);
  }

 delay (500);
}
