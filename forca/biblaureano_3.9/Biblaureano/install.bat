@echo off


cd %HOMEPATH%\Desktop\Biblaureano

echo Removendo arquivos antigos
del /Q bin\Debug\*
del /Q bin\Debug\*

set CAMINHO=%CD%
echo %CAMINIHO%

if %PROCESSOR_ARCHITECTURE% == AMD64 (
	echo Compilando a biblioteca
	"C:\Program Files (x86)\CodeBlocks\MinGW\bin\mingw32-g++.exe" -w -Wall -fPIC -Wsign-compare -fexceptions -g     -c "%CAMINHO%\main.cpp" -o %CAMINHO%\obj\Debug\main.o
	"C:\Program Files (x86)\CodeBlocks\MinGW\bin\mingw32-g++.exe" -shared -Wl,--output-def=%CAMINHO%\bin\Debug\libBiblaureano.def  -Wl,--dll  %CAMINHO%\obj\Debug\main.o   -o %CAMINHO%\bin\Debug\Biblaureano.dll
	
	echo Copiando arquivos para os diretórios do sistema
	del /Q %APPDATA%\CodeBlocks\default.conf
	copy /Y %CAMINHO%\default_win.conf %APPDATA%\CodeBlocks\

	copy /Y %CAMINHO%\bin\Debug\Biblaureano.dll C:\Windows\system32\
	copy /Y %CAMINHO%\biblaureano.h "C:\Program Files (x86)\CodeBlocks\MinGW\include\"
) else (
	echo Compilando a biblioteca
	"C:\Program Files\CodeBlocks\MinGW\bin\mingw32-g++.exe" -w -Wall -fPIC -Wsign-compare -fexceptions -g     -c "%CAMINHO%\main.cpp" -o %CAMINHO%\obj\Debug\main.o
	"C:\Program Files\CodeBlocks\MinGW\bin\mingw32-g++.exe" -shared -Wl,--output-def=%CAMINHO%\bin\Debug\libBiblaureano.def  -Wl,--dll  %CAMINHO%\obj\Debug\main.o   -o %CAMINHO%\bin\Debug\Biblaureano.dll

	echo Copiando arquivos para os diretórios do sistema
	del /Q %APPDATA%\CodeBlocks\default.conf
	copy /Y %CAMINHO%\default_win.conf %APPDATA%\CodeBlocks\

	copy /Y %CAMINHO%\bin\Debug\Biblaureano.dll C:\Windows\system32\
	copy /Y %CAMINHO%\biblaureano.h "C:\Program Files\CodeBlocks\MinGW\include\"
)

cd %APPDATA%\CodeBlocks\
rename default_win.conf default.conf

echo Terminado!
pause