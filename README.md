# LeetCode C 語言練習專案手冊

本專案是一個使用 **C 語言** 進行 **LeetCode 演算法練習** 的開發環境。  
透過自動化腳本與 VS Code（或 Cursor）設定整合，大幅簡化 **新題目建立、編譯與管理流程**，讓你可以專注在演算法本身。

**※注意:** 此說明只適用於LeetCodeVsCode資料夾

---

## 🚀 核心功能

- **快速建立模組**  
  一鍵生成題目資料夾與對應的 `.c` / `.h` 樣板。

- **自動環境配置**  
  腳本會自動：
  - 將新題目 `.c` 檔加入編譯任務  
  - 更新標頭檔搜尋路徑（`includePath`）  
  - 在 `Main.c` 中加入對應的 `#include`

- **一鍵清理題目**  
  支援完整刪除題目模組，並同步清除所有相關設定，避免殘留設定造成編譯錯誤。

---

## 🛠️ 環境需求

### 編譯器
- **Windows**：需安裝 `gcc`（建議使用 MinGW-w64）
- **macOS**：需安裝 `clang`（Xcode Command Line Tools）

### 其他工具
- **Python**：3.x（用於執行 `CreateModule.py`）
- **編輯器**：推薦使用 **VS Code** 或 **Cursor**

---

## 📂 專案架構

```plaintext
.
├── Main.c                # 程式進入點，用於測試各個題目模組
├── CreateModule.py       # 題目模組自動化管理腳本
├── ListLib/              # 自定義通用工具庫（如 Linked List）
├── Solution/             # LeetCode 題目解法
│   └── ModuleName/       # 各題目的獨立資料夾
│       ├── ModuleName.c
│       └── ModuleName.h
└── .vscode/              # VS Code / Cursor 編輯器設定
```

## ⌨️ 自動化腳本使用說明 (CreateModule.py)
**1. 新增題目模組**
當你要開始寫一個新題目時（例如 AddTwoLists），請在終端機輸入：

**PowerShell:**
```
python CreateModule.py AddTwoLists
```

執行結果：

在 Solution/AddTwoLists 下建立 AddTwoLists.c 與 AddTwoLists.h。

在 tasks.json 的編譯參數中自動加入該路徑。

在 c_cpp_properties.json 中加入該資料夾至 includePath。

在 Main.c 中自動新增 #include "Solution/AddTwoLists/AddTwoLists.h"。

**2. 刪除題目模組**
若要移除某個題目及其所有相關配置：

**PowerShell:**
```
python CreateModule.py delete AddTwoLists
```

**執行結果：**

刪除 Solution/AddTwoLists 資料夾及其內容。

從 tasks.json 與 c_cpp_properties.json 中移除相關路徑。

從 Main.c 中自動刪除對應的 #include 行。

## 🔨 編譯與除錯
編譯程式
專案已配置預設編譯任務 build。

快捷鍵：按下 Ctrl + Shift + B (Windows) 或 Cmd + Shift + B (macOS)。

手動執行：在編輯器頂部選單選擇 Terminal -> Run Build Task -> build。

## 除錯 (Debug)
專案提供 Windows (gdb) 與 macOS (lldb) 的除錯配置。

在程式碼中設置斷點。

切換至 Run and Debug 視窗。

選擇對應系統的 C: 執行程式 並按下 F5 鍵啟動。

## 📝 開發備註
測試函式：每個模組預設會生成一個 solve_ModuleName() 函式，請在 Main.c 的 main() 函式中呼叫它來執行測試。

IntelliSense：若發現標頭檔下有紅字警告，請確認 c_cpp_properties.json 是否已透過腳本正確更新。
若標頭檔出現紅字警告，請確認：

c_cpp_properties.json 是否已正確更新 includePath
