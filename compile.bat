@echo off
gcc mousecat.c -Wl,-subsystem,windows -s -o mousecat
pause
