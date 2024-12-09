gcc c/bindump/bindump.c -o c/bindump/bindump
cp c/bindump/bindump /data/data/com.termux/files/usr/bin
echo "bindump"

gcc c/hex2string/hex2string.c -o c/hex2string/hex2string
cp c/hex2string/hex2string /data/data/com.termux/files/usr/bin
echo "hex2string"

gcc c/octaldump/octaldump.c -o c/octaldump/octaldump
cp c/octaldump/octaldump /data/data/com.termux/files/usr/bin
echo "octaldump"

gcc c/txt2bin/txt2bin.c -o c/txt2bin/txt2bin
cp c/txt2bin/txt2bin /data/data/com.termux/files/usr/bin
echo "txt2bin"

gcc c/txt2hex/txt2hex.c -o c/txt2hex/txt2hex
cp c/txt2hex/txt2hex /data/data/com.termux/files/usr/bin
echo "txt2hex"

g++ cpp/8bit/8bit.cpp -o cpp/8bit/8bit
cp cpp/8bit/8bit /data/data/com.termux/files/usr/bin
echo "8bit"

g++ cpp/bin2dec/bin2dec.cpp -o cpp/bin2dec/bin2dec
cp cpp/bin2dec/bin2dec /data/data/com.termux/files/usr/bin
echo "bin2dec"

g++ cpp/dec2hex/dec2hex.cpp -o cpp/dec2hex/dec2hex
cp cpp/dec2hex/dec2hex /data/data/com.termux/files/usr/bin
echo "dec2hex"

g++ cpp/hex2bin/hex2bin.cpp -o cpp/hex2bin/hex2bin
cp cpp/hex2bin/hex2bin /data/data/com.termux/files/usr/bin
echo "hex2bin"

g++ cpp/hex2dec/hex2dec.cpp -o cpp/hex2dec/hex2dec
cp cpp/hex2dec/hex2dec /data/data/com.termux/files/usr/bin
echo "hex2dec"

g++ cpp/ohms/ohms.cpp -o cpp/ohms/ohms
cp cpp/ohms/ohms /data/data/com.termux/files/usr/bin
echo "ohms"

g++ cpp/race_est/race_est.cpp -o cpp/race_est/race_est
cp cpp/race_est/race_est /data/data/com.termux/files/usr/bin
echo "race_est"

g++ cpp/ticket/ticket.cpp -o cpp/ticket/ticket
cp cpp/ticket/ticket /data/data/com.termux/files/usr/bin
echo "ticket"

g++ cpp/unix/unix.cpp -o cpp/unix/unix
cp cpp/unix/unix /data/data/com.termux/files/usr/bin
echo "unix"

gforth fortran/calc/calc.f90 -o fortran/calc/calc
cp fortran/calc/calc /data/data/com.termux/files/usr/bin 
echo "calc"
