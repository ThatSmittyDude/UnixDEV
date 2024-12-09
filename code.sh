cd ~
rm -r code
unzip code.zip
rm code.zip
cd code
chmod +x apt.sh
chmod +x build.sh
./apt.sh
./build.sh
