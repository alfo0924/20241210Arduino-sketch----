
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
