@echo off
gcc mousecat.c -s -Wl,-subsystem,windows -static -s -o mousecat
pause
