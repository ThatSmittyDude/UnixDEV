echo "\n"
echo "Compiling"
echo "bindump.c"
echo "		PID 0"
echo "---- ---- ---- ----"
gcc c/bindump/bindump.c -o c/bindump/bindump --static
sudo cp c/bindump/bindump /bin
echo "bindump complete"

echo "\n"
echo "Compiling"
echo "octaldump.c"
echo "		PID 1"
echo "---- ---- ---- ----"
gcc c/octaldump/octaldump.c -o c/octaldump/octaldump --static
sudo cp c/octaldump/octaldump /bin
echo "octaldump complete"

echo "\n"
echo "Compiling"
echo "txt2bin.c"
echo "		PID 2"
echo "---- ---- ---- ----"
gcc c/txt2bin/txt2bin.c -o c/txt2bin/txt2bin --static
sudo cp c/txt2bin/txt2bin /bin
echo "txt2bin complete"

echo "\n"
echo "Compiling"
echo "txt2hex.c"
echo "		PID 3"
echo "---- ---- ---- ----"
gcc c/txt2hex/txt2hex.c -o c/txt2hex/txt2hex --static
sudo cp c/txt2hex/txt2hex /bin
echo "txt2hex complete"

echo "\n"
echo "Compiling"
echo "hex2string.c"
echo "		PID 4"
echo "---- ---- ---- ----"
gcc c/hex2string/hex2string.c -o c/hex2string/hex2string --static
sudo cp c/hex2string/hex2string /bin
echo "hex2string complete"

echo "\n"
echo "Compiling"
echo "8bit.cpp"
echo "		PID 5"
echo "---- ---- ---- ----"
g++ cpp/8bit/8bit.cpp -o cpp/8bit/8bit --static
sudo cp cpp/8bit/8bit /bin
echo "8bit complete"

echo "\n"
echo "Compiling"
echo "bin2dec.cpp"
echo "		PID 6"
echo "---- ---- ---- ----"
g++ cpp/bin2dec/bin2dec.cpp -o cpp/bin2dec/bin2dec --static
sudo cp cpp/bin2dec/bin2dec /bin
echo "bin2dec complete"

echo "\n"
echo "Compiling"
echo "dec2hex.cpp"
echo "		PID 7"
echo "---- ---- ---- ----"
g++ cpp/dec2hex/dec2hex.cpp -o cpp/dec2hex/dec2hex --static
sudo cp cpp/dec2hex/dec2hex /bin
echo "dec2hex complete"

echo "\n"
echo "Compiling"
echo "hex2bin.cpp"
echo "		PID 8"
echo "---- ---- ---- ----"
g++ cpp/hex2bin/hex2bin.cpp -o cpp/hex2bin/hex2bin --static
sudo cp cpp/hex2bin/hex2bin /bin
echo "hex2bin complete"

echo "\n"
echo "Compiling"
echo "hex2dec.cpp"
echo "		PID 9"
echo "---- ---- ---- ----"
g++ cpp/hex2dec/hex2dec.cpp -o cpp/hex2dec/hex2dec --static
sudo cp cpp/hex2dec/hex2dec /bin
echo "hex2dec complete"


echo "\n"
echo "Compiling"
echo "ohms.cpp"
echo "		PID 10"
echo "---- ---- ---- ----"
g++ cpp/ohms/ohms.cpp -o cpp/ohms/ohms --static
sudo cp cpp/ohms/ohms /bin
echo "ohms complete"

echo "\n"
echo "Compiling"
echo "watts.cpp"
echo "		PID 11"
echo "---- ---- ---- ----"
g++ cpp/watts/watts.cpp -o cpp/watts/watts --static
sudo cp cpp/watts/watts /bin
echo "watts complete"

echo "\n"
echo "Compiling"
echo "race_est.cpp"
echo "		PID 12"
echo "---- ---- ---- ----"
g++ cpp/race_est/race_est.cpp -o cpp/race_est/race_est --static
sudo cp cpp/race_est/race_est /bin
echo "race_est complete"

echo "\n"
echo "Compiling"
echo "ticket.cpp"
echo "		PID 13"
echo "---- ---- ---- ----"
g++ cpp/ticket/ticket.cpp -o cpp/ticket/ticket --static
sudo cp cpp/ticket/ticket /bin
echo "ticket complete"

echo "\n"
echo "Compiling"
echo "unix.cpp"
echo "		PID 14"
echo "---- ---- ---- ----"
g++ cpp/unix/unix.cpp -o cpp/unix/unix --static
sudo cp cpp/unix/unix /bin
echo "unix complete"

echo "\n"
echo "Compiling"
echo "kmph2mph.cpp"
echo "		PID 15"
echo "---- ---- ---- ----"
g++ cpp/kmph2mph/kmph2mph.cpp -o cpp/kmph2mph/kmph2mph --static
sudo cp cpp/kmph2mph/kmph2mph /bin
echo "kmph2mph complete"

echo "\n"
echo "Compiling"
echo "mph2kmph.cpp"
echo "		PID 16"
echo "---- ---- ---- ----"
g++ cpp/mph2kmph/mph2kmph.cpp -o cpp/mph2kmph/mph2kmph --static
sudo cp cpp/mph2kmph/mph2kmph /bin
echo "mph2kmph complete"

echo "\n"
echo "Compiling"
echo "c2f.cpp"
echo "		PID 17"
echo "---- ---- ---- ----"
g++ cpp/c2f/c2f.cpp -o cpp/c2f/c2f --static
sudo cp cpp/c2f/c2f /bin
echo "c2f complete"

echo "\n"
echo "Compiling"
echo "f2c.cpp"
echo "		PID 18"
echo "---- ---- ---- ----"
g++ cpp/f2c/f2c.cpp -o cpp/f2c/f2c --static
sudo cp cpp/f2c/f2c /bin
echo "f2c complete"

echo "\n"
echo "Compiling"
echo "fma.cpp"
echo "		PID 19"
echo "---- ---- ---- ----"
g++ cpp/fma/fma.cpp -o cpp/fma/fma --static
sudo cp cpp/fma/fma /bin
echo "fma complete"

echo "\n"
echo "Compiling"
echo "force.f90"
echo "		PID 20"
echo "---- ---- ---- ----"
gfortran fortran/force/force.f90 -o fortran/force/force --static
sudo cp fortran/force/force /bin
echo "force complete"

echo "\n"
echo "Compiling"
echo "calc.f90"
echo "		PID 21"
echo "---- ---- ---- ----"
gfortran fortran/calc/calc.f90 -o fortran/calc/calc --static
sudo cp fortran/calc/calc /bin
echo "calc complete"
