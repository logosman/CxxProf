
@echo off

REM Copy to install/bin directory and execute

DEL %~dp0\cxxprof_dyn_network.dll
copy %~dp0\..\..\cxxprof_dyn_network\bin\cxxprof_dyn_network.dll .

set PATH=%PATH%;%~dp0/../../../thirdparty/boost/bin/
set PATH=%PATH%;%~dp0/../../../thirdparty/pluma/bin/
set PATH=%PATH%;%~dp0/../../../thirdparty/zmq/bin/
set PATH=%PATH%;%~dp0/../../../thirdparty/sqlite3/bin/
set PATH=%PATH%;%~dp0/../../../thirdparty/sqlite3cc/bin/

%~dp0\cxxprof_server.exe
