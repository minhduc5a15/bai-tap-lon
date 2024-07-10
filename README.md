# Bài Tập Lớn

## Bài tập lớn môn kỹ thuật lập trình năm nhất của nhóm 5

### Chủ đề: Game "Ai là triệu phú"

### Trưởng nhóm:
[Phạm Minh Đức](http://laptrinhonline.club/user/MinhDuc_CNTT1_K64)

### Thành viên nhóm:
- Phạm Minh Đức
- Nguyễn Quý Việt Anh
- Nguyễn Tường Huy
- Vũ Đức Long
- Bùi Ngọc Phúc

### Ngôn ngữ lập trình:
C

### Cách chạy dự án

- Clone dự án
    ```shell
    git clone https://github.com/minhduc5a15/Bai-Tap-Lon
    cd Bai-Tap-Lon
    ```

- Tải **[MSYS2](https://github.com/msys2/msys2.github.io)**

- Vào **MSYS2-MINGW64**, chạy dưới quyền administrator, chạy các câu lệnh sau
    ```shell
    pacman -S mingw-w64-x86_64-toolchain
    pacman -S mingw-w64-x86_64-raylib
    pacman -S mingw-w64-x86_64-cjson
    ```

- Quay trở lại terminal, chạy lệnh
    ```shell
    mkdir build
    cd build
    cmake -G "MinGW Makefiles" ..
    ```
- Output sẽ dạng như thế này:
    ```
    -- The C compiler identification is GNU 14.1.0
    -- Detecting C compiler ABI info
    -- Detecting C compiler ABI info - done
    -- Check for working C compiler: path/msys64/mingw64/bin/cc.exe - skipped
    -- Detecting C compile features
    -- Detecting C compile features - done
    -- Found PkgConfig: path/msys64/mingw64/bin/pkg-config.exe (found version "2.2.0")
    -- Checking for module 'raylib'
    --   Found raylib, version 4.5.0
    -- Configuring done (1.5s)
    -- Generating done (0.0s)
    -- Build files have been written to: path/Bai-Tap-Lon/build
    ```
- Tiếp tục chạy lệnh:
    ```shell
    mingw32-make
    ```

- Output sẽ có dạng như thế này:
    ```
    [  5%] ................
    [ 10%] ................
    [ 15%] ................
    [ 20%] ................
    [ 25%] ................
    ...
    [ 75%] ................
    [ 80%] ................
    [ 85%] ................
    [ 90%] ................
    [ 95%] ................
    [100%] Linking C executable Bai-Tap-Lon.exe
    [100%] Built target Bai-Tap-Lon
    ```

    - Chỉ khi có 2 dòng này thì mới tiếp tục: 
    ```shell
        [100%] Linking C executable Bai-Tap-Lon.exe
        [100%] Built target Bai-Tap-Lon
    ```
- Trong file **[constants.c](https://github.com/minhduc5a15/Bai-Tap-Lon/blob/main/constants/constants.c)**, thay đổi đường dẫn 'resource/' thành đường dẫn tới dự án, dạng 'path/to/Bai-Tap-Lon' .
- Cuối cùng chạy lệnh sau để xem kết quả.
```shell
./raylib-project.exe
```

[![Typing SVG](https://readme-typing-svg.demolab.com?font=Fira+Code&weight=600&size=21&duration=3500&pause=1000&color=46D4F7&multiline=true&repeat=false&random=false&width=435&lines=Happy+coding!!!%F0%9F%98%8A%F0%9F%98%8A%F0%9F%98%8A;----------------------;Quick+fox+jumps+nightly+above+wizard)](https://git.io/typing-svg)
