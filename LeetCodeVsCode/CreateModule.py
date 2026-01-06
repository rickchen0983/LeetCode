import os
import json
import sys
import shutil
from pathlib import Path

# --- 共用路徑設定 ---
BASE_DIR = Path(__file__).parent.absolute()
SOLUTION_DIR = BASE_DIR / "Solution"
VSCODE_DIR = BASE_DIR / ".vscode"
MAIN_C_PATH = BASE_DIR / "Main.c"

def update_json_configs(module_name, action="add"):
    """更新 tasks.json 與 c_cpp_properties.json"""
    c_rel_path = f"Solution/{module_name}/{module_name}.c"
    inc_path = f"./Solution/{module_name}"
    
    # 1. 更新 tasks.json
    tasks_path = VSCODE_DIR / "tasks.json"
    if tasks_path.exists():
        with open(tasks_path, 'r', encoding='utf-8') as f:
            data = json.load(f)
        
        for task in data.get("tasks", []):
            if task.get("label") == "build":
                # 處理通用 args 與 windows args
                arg_lists = [task.get("args", [])]
                if "windows" in task:
                    arg_lists.append(task["windows"].get("args", []))
                
                for args in arg_lists:
                    if action == "add" and c_rel_path not in args:
                        if "-o" in args:
                            args.insert(args.index("-o"), c_rel_path)
                    elif action == "delete" and c_rel_path in args:
                        args.remove(c_rel_path)
        
        with open(tasks_path, 'w', encoding='utf-8') as f:
            json.dump(data, f, indent=4, ensure_ascii=False)

    # 2. 更新 c_cpp_properties.json
    cpp_path = VSCODE_DIR / "c_cpp_properties.json"
    if cpp_path.exists():
        with open(cpp_path, 'r', encoding='utf-8') as f:
            data = json.load(f)
        
        for config in data.get("configurations", []):
            inc_list = config.get("includePath", [])
            if action == "add" and inc_path not in inc_list:
                inc_list.append(inc_path)
            elif action == "delete" and inc_path in inc_list:
                inc_list.remove(inc_path)
        
        with open(cpp_path, 'w', encoding='utf-8') as f:
            json.dump(data, f, indent=4, ensure_ascii=False)

def update_main_c(module_name, action="add"):
    """在 Main.c 新增或刪除 #include"""
    if not MAIN_C_PATH.exists(): return
    
    lines = MAIN_C_PATH.read_text(encoding='utf-8').splitlines()
    target_include = f'#include "Solution/{module_name}/{module_name}.h"'
    
    if action == "add":
        if not any(target_include in l for l in lines):
            insert_idx = 0
            for i, line in enumerate(lines):
                if line.strip().startswith("#include"):
                    insert_idx = i + 1
            lines.insert(insert_idx, target_include)
    elif action == "delete":
        lines = [l for l in lines if target_include not in l]
        
    MAIN_C_PATH.write_text("\n".join(lines) + "\n", encoding='utf-8')

def add_module(module_name):
    """新增模組邏輯"""
    target_dir = SOLUTION_DIR / module_name
    target_dir.mkdir(parents=True, exist_ok=True)
    
    h_file = target_dir / f"{module_name}.h"
    c_file = target_dir / f"{module_name}.c"
    
    if not h_file.exists():
        h_file.write_text(f"#ifndef {module_name.upper()}_H\n#define {module_name.upper()}_H\n\nvoid solve_{module_name}(void);\n\n#endif\n", encoding="utf-8")
    if not c_file.exists():
        c_file.write_text(f'#include "{module_name}.h"\n#include <stdio.h>\n\nvoid solve_{module_name}(void) {{\n    printf("Running {module_name}...\\n");\n}}\n', encoding="utf-8")
    
    update_json_configs(module_name, "add")
    update_main_c(module_name, "add")
    print(f"✅ 已新增模組: {module_name}")

def delete_module(module_name):
    """刪除模組邏輯"""
    target_dir = SOLUTION_DIR / module_name
    
    # 1. 刪除實體資料夾
    if target_dir.exists():
        shutil.rmtree(target_dir)
        print(f"🗑️ 已刪除資料夾: Solution/{module_name}")
    
    # 2. 清理設定檔
    update_json_configs(module_name, "delete")
    update_main_c(module_name, "delete")
    print(f"✅ 已從設定檔與 Main.c 移除: {module_name}")

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("用法:")
        print("  新增: python CreateModule.py <ModuleName>")
        print("  刪除: python CreateModule.py delete <ModuleName>")
        sys.exit(1)

    if sys.argv[1] == "delete" and len(sys.argv) == 3:
        delete_module(sys.argv[2])
    else:
        # 為了相容舊用法，如果只有一個參數就視為 add
        mod_name = sys.argv[2] if sys.argv[1] == "add" else sys.argv[1]
        add_module(mod_name)