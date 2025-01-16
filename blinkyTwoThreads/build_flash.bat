@echo off

REM Variables

set APP_DIR=%cd%
set BUILD_DIR=%APP_DIR%\build
set BOARD_NAME=sam_v71_xult


REM check if the build directory exists, create it if not 
IF NOT EXIST %BUILD_DIR% (
    mkdir %BUILD_DIR%
    echo Directory %BUILD_DIR% created.
) ELSE (
    echo Directory %BUILD_DIR% already exists. 
)
REM BUild the application
west build -p always -b %BOARD_NAME% %APP_DIR% -d %BUILD_DIR%

REM flash the image to the target/board
west flash -d %BUILD_DIR%