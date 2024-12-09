gcc c/bindump/bindump.c -o c/bindump/bindump --static
sudo cp c/bindump/bindump /bin
echo "bindump"

gcc c/hex2string/hex2string.c -o c/hex2string/hex2string --static
sudo cp c/hex2string/hex2string /bin
echo "hex2string"

gcc c/octaldump/octaldump.c -o c/octaldump/octaldump --static
sudo cp c/octaldump/octaldump /bin
echo "octaldump"

gcc c/txt2bin/txt2bin.c -o c/txt2bin/txt2bin --static
sudo cp c/txt2bin/txt2bin /bin
echo "txt2bin"

gcc c/txt2hex/txt2hex.c -o c/txt2hex/txt2hex --static
sudo cp c/txt2hex/txt2hex /bin
echo "txt2hex"

g++ cpp/8bit/8bit.cpp -o cpp/8bit/8bit --static
sudo cp cpp/8bit/8bit /bin
echo "8bit"

g++ cpp/bin2dec/bin2dec.cpp -o cpp/bin2dec/bin2dec --static
sudo cp cpp/bin2dec/bin2dec /bin
echo "bin2dec"

g++ cpp/dec2hex/dec2hex.cpp -o cpp/dec2hex/dec2hex --static
sudo cp cpp/dec2hex/dec2hex /bin
echo "dec2hex"

g++ cpp/hex2bin/hex2bin.cpp -o cpp/hex2bin/hex2bin --static
sudo cp cpp/hex2bin/hex2bin /bin
echo "hex2bin"

g++ cpp/hex2dec/hex2dec.cpp -o cpp/hex2dec/hex2dec --static
sudo cp cpp/hex2dec/hex2dec /bin
echo "hex2dec"

g++ cpp/ohms/ohms.cpp -o cpp/ohms/ohms --static
sudo cp cpp/ohms/ohms /bin
echo "ohms"

g++ cpp/race_est/race_est.cpp -o cpp/race_est/race_est --static
sudo cp cpp/race_est/race_est /bin
echo "race_est"

g++ cpp/ticket/ticket.cpp -o cpp/ticket/ticket --static
sudo cp cpp/ticket/ticket /bin
echo "ticket"

g++ cpp/unix/unix.cpp -o cpp/unix/unix --static
sudo cp cpp/unix/unix /bin
echo "unix"

g++ cpp/kmph2mph/kmph2mph.cpp -o cpp/kmph2mph/kmph2mph --static
sudo cp cpp/kmph2mph/kmph2mph /bin
echo "kmph2mph"

g++ cpp/mph2kmph/mph2kmph.cpp -o cpp/mph2kmph/mph2kmph --static
sudo cp cpp/mph2kmph/mph2kmph /bin
echo "mph2kmph"

g++ cpp/c2f/c2f.cpp -o cpp/c2f/c2f --static
sudo cp cpp/c2f/c2f /bin
echo "c2f"

g++ cpp/f2c/f2c.cpp -o cpp/f2c/f2c --static
sudo cp cpp/f2c/f2c /bin
echo "f2c"

g++ cpp/fma/fma.cpp -o cpp/fma/fma --static
sudo cp cpp/fma/fma /bin
echo "fma"

gfortran fortran/calc/calc.f90 -o fortran/calc/calc --static
sudo cp fortran/calc/calc /bin
echo "calc"

gfortran fortran/force/force.f90 -o fortran/force/force --static
sudo cp fortran/force/force /bin
echo "force"
