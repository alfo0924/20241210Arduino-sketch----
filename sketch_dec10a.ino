const int ledPin = 4;  // LED連接到Pin 4
unsigned long previousMillis = 0;
const long interval = 1000;  // 閃爍間隔為1秒
unsigned long totalSeconds = 0;  // 新增累計秒數變數

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  // 初始化Serial通訊
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
        totalSeconds++;  // 每次間隔增加一秒
    digitalWrite(ledPin, HIGH);  // LED開啟
    Serial.print(totalSeconds);  // 輸出累計秒數
    Serial.println(" seconds");  // 輸出單位
    delay(100);                  // LED亮100毫秒
    digitalWrite(ledPin, LOW);   // LED關閉
  }
}
