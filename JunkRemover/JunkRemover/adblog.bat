@echo off
setlocal enabledelayedexpansion

if not exist "DeviceLog" mkdir "DeviceLog"

set check=false

adb devices | findstr /r /c:"device$" >nul
IF %ERRORLEVEL% EQU 0 (
    set check=true
) ELSE (
    set check=false
)

IF "!check!"=="true" (
    adb devices
    echo ADB Device Is Connected.
    echo.
    echo Log Files Can Be Found Inside The DeviceLog Folder.
    echo To stop the log recording, Press 'Ctrl + C'.
    echo Press Enter To Continue:
    pause>nul
    echo Starting log recording...
    timeout /t 2 /nobreak>nul

    for /f %%A in ('powershell -NoLogo -Command "Get-Date -Format yyyyMMdd_HHmmss"') do set "ts=%%A"

    set "logfile=DeviceLog\logs_!ts!.txt"

    adb logcat | powershell -NoLogo -Command "$input | Tee-Object -FilePath '!logfile!'"

) ELSE (
    color 4 & echo No ADB Device Found. 
    echo Press Enter To Exit.
    pause>nul
    exit /b
)

pause >nul
exit /b