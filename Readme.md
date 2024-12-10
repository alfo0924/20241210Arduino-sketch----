
## sketch_dec10a.ino 

### 程式運作原理解析

**變數定義部分**
- `ledPin`: 定義LED連接的腳位為4
- `previousMillis`: 儲存上一次LED閃爍的時間點
- `interval`: 設定閃爍間隔為1000毫秒（1秒）
- `totalSeconds`: 用於計算累計經過的秒數

**初始化設定**
- `setup()`函數中設定Pin 4為輸出模式
- 初始化Serial通訊，設定鮑率為9600

**主要運作邏輯**
1. **時間追蹤機制**
   - `currentMillis = millis()`: 持續獲取Arduino啟動後經過的毫秒數
   - `currentMillis - previousMillis >= interval`: 檢查是否已經過了1秒

2. **計時與更新機制**
   - 當時間間隔達到1秒，`previousMillis`會更新為目前時間
   - `totalSeconds`計數器加1，記錄總經過秒數

3. **LED控制與顯示**
   - LED會短暫亮起100毫秒後熄滅
   - 透過Serial Monitor顯示累計秒數

**特點說明**
- 使用`millis()`而非`delay()`作為主要計時方式，避免程式阻塞
- LED閃爍和秒數計算同步進行
- Serial Monitor即時顯示經過的秒數，方便監控

# sketch_dec10b.ino


1. **硬體計時器設定**：
   - 使用ESP32的硬體計時器功能
   - 設定計時器觸發頻率和中斷處理機制

2. **中斷處理機制**：
   - 當計時器達到設定值時，會觸發中斷
   - 中斷觸發時會執行`interrupt_func()`函數
   - 實現LED的自動切換狀態

3. **錯誤處理**：
   - 程式中包含了計時器初始化檢查機制
   - 如果計時器初始化失敗，會輸出錯誤訊息

4. **注意事項**：
   - `timerBegin()`函數參數設定不完整，應修正為三個參數
   - 主迴圈目前是空的，可根據需求加入其他功能


# sketch_dec10C.ino
