@echo off
echo Compilation du projet...
g++ main.cpp -o carpooling_app.exe

if %ERRORLEVEL% EQU 0 (
    echo Compilation reussie !
    echo Lancement de l'application...
    .\carpooling_app.exe
) else (
    echo Erreur lors de la compilation. Assurez-vous d'avoir G++ installe (MinGW).
)
pause
