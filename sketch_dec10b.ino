// 宣告一個硬體計時器指標，初始值為空
hw_timer_t * timer = NULL;

// 定義中斷服務程序（ISR）函數
// 當計時器觸發中斷時，此函數會被呼叫
// 功能：將腳位4的輸出狀態反轉（HIGH變LOW，LOW變HIGH）
void ARDUINO_ISR_ATTR interrupt_func() {
    digitalWrite(4, !digitalRead(4));
}

// 初始化設定
void setup() {
    // 設定序列埠通訊速率為115200 bps
    Serial.begin(115200);
    // 設定腳位4為輸出模式
    pinMode(4, OUTPUT);
    
    // 初始化計時器
    // 參數應該要有三個：計時器編號(0-3)、預分頻值(通常是80)、計數方向(true為向上計數)
    timer = timerBegin(100000);
    
    // 將中斷函數附加到計時器
    // 設定當計時器觸發時要執行的函數
    timerAttachInterrupt(timer, &interrupt_func);
    
    // 設定計時器警報
    // 參數：計時器物件、計數值、是否自動重載、中斷優先級
    timerAlarm(timer,100000,true,0);

    // 檢查計時器是否成功初始化
    if(timer == NULL) {
        Serial.println("Error occur in setting timer");
    } else {
        // 輸出計時器的頻率資訊
        Serial.print("Frequency: ");
        Serial.println(timerGetFrequency(timer));
    }
}

// 宣告計數器變數
int counter = 0;

// 主程式迴圈
// 目前為空，原本的功能已被註解掉：
// - 輸出計數器值
// - 計數器加1
// - 延遲2000毫秒(2秒)
void loop() {
    Serial.println(counter);
    counter++;
    delay(2000);
}
