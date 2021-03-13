@echo off

if not exist output\ (
   mkdir output\
)
pushd output\
	  cl /nologo /Zi ..\*.c
popd
