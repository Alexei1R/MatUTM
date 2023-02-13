@echo off


rem 
where python >nul 2>&1
if %ERRORLEVEL% NEQ 0 (
  echo Python is not installed
  start https://www.python.org/downloads/
) else (
  echo Python is already installed.
)

call vendor\premake\premake5.exe vs2022
pause
