
// 引入DHT11所需的函式庫
#include "DHT.h"

// 宣告一個硬體計時器指標，初始值為空
hw_timer_t * timer = NULL;

// 宣告計數器變數
int counter = 0;

// 定義DHT11感測器
#define DHTPIN 16     // DHT11連接到腳位16
#define DHTTYPE DHT11 // 定義使用的是DHT11感測器
DHT dht(DHTPIN, DHTTYPE);

// 定義中斷服務程序（ISR）函數
void ARDUINO_ISR_ATTR interrupt_func() {
    digitalWrite(4, !digitalRead(4));
}

// 初始化設定
void setup() {
    Serial.begin(115200);
    pinMode(4, OUTPUT);
    
    // 初始化DHT11感測器
    dht.begin();
    
    // 初始化計時器
    // 設定頻率為100000Hz (100kHz)
    timer = timerBegin(100000);
    
    // 將中斷函數附加到計時器
    timerAttachInterrupt(timer, &interrupt_func);
    
    // 設定計時器警報
    timerAlarm(timer, 100000, true, 0);

    if(timer == NULL) {
        Serial.println("Error occur in setting timer");
    } else {
        Serial.print("Frequency: ");
        Serial.println(timerGetFrequency(timer));
    }
}

// 主程式迴圈
void loop() {
    // 讀取濕度數值
    float humidity = dht.readHumidity();
    
    // 檢查讀取是否成功
    if (isnan(humidity)) {
        Serial.println("Failed to read humidity from DHT sensor!");
    } else {
        // 輸出濕度數值
        Serial.print("Humidity: ");
        Serial.print(humidity);
        Serial.println("%");
    }
    
    // 計數器相關操作
    Serial.print("Counter: ");
    Serial.println(counter);
    counter++;
    
    // 延遲1秒
    delay(1000);
}
