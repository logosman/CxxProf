
@echo off

REM Copy to install/bin directory and execute

DEL brofiler_dyn_network.dll
copy ..\install\brofiler_dyn_network\bin\brofiler_dyn_network.dll .
copy ..\install\brofiler_server\bin\brofiler_server.exe .

set PATH=%PATH%;../thirdparty/boost/bin/
set PATH=%PATH%;../thirdparty/pluma/bin/
set PATH=%PATH%;../thirdparty/zmq/bin/

brofiler_server.exe
