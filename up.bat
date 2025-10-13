@echo off
cd /d "%~dp0"
set /p n=31:
echo --- Güncellemeler çekiliyor ---
git pull --rebase

echo --- Değişiklikler ekleniyor ---
git add .

echo --- Commit atılıyor ---
git commit -m "%n%" 

echo --- Push ediliyor ---
git push

echo --- İşlem tamamlandı ---
pause
