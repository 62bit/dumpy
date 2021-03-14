@echo off

if not exist output\ (
   mkdir output\
)
pushd output\
	  cl /nologo /Fe"dumpy.exe" /O2 ..\*.c
popd
