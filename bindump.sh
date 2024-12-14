echo "\n"
echo "bindump.c"
echo "		PID 0"
echo "---- ---- ---- ----"
bindump c/bindump/bindump c/bindump/bindump.binary
hexdump c/bindump/bindump > c/bindump/bindump.hex
echo "hexdump complete"
octaldump c/bindump/bindump c/bindump/bindump.oct
binwalk -e c/bindump/bindump > c/bindump/bindump.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "octaldump.c"
echo "		PID 1"
echo "---- ---- ---- ----"
bindump c/octaldump/octaldump c/octaldump/octaldump.binary
hexdump c/octaldump/octaldump > c/octaldump/octaldump.hex
echo "hexdump complete"
octaldump c/octaldump/octaldump c/octaldump/octaldump.oct
binwalk -e c/octaldump/octaldump > c/octaldump/octaldump.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "txt2bin.c"
echo "		PID 2"
echo "---- ---- ---- ----"
bindump c/txt2bin/txt2bin c/txt2bin/txt2bin.binary
hexdump c/txt2bin/txt2bin > c/txt2bin/txt2bin.hex
echo "hexdump complete"
octaldump c/txt2bin/txt2bin c/txt2bin/txt2bin.oct
binwalk -e c/txt2bin/txt2bin > c/txt2bin/txt2bin.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "txt2hex.c"
echo "		PID 3"
echo "---- ---- ---- ----"
bindump c/txt2hex/txt2hex c/txt2hex/txt2hex.binary
hexdump c/txt2hex/txt2hex > c/txt2hex/txt2hex.hex
echo "hexdump complete"
octaldump c/txt2hex/txt2hex c/txt2hex/txt2hex.oct
binwalk -e c/txt2hex/txt2hex > c/txt2hex/txt2hex.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "hex2string.c"
echo "		PID 4"
echo "---- ---- ---- ----"
bindump c/hex2string/hex2string c/hex2string/hex2string.binary
hexdump c/hex2string/hex2string > c/hex2string/hex2string.hex
echo "hexdump complete"
octaldump c/hex2string/hex2string c/hex2string/hex2string.oct
binwalk -e c/hex2string/hex2string > c/hex2string/hex2string.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "8bit.cpp"
echo "		PID 5"
echo "---- ---- ---- ----"
bindump cpp/8bit/8bit cpp/8bit/8bit.binary
hexdump cpp/8bit/8bit > cpp/8bit/8bit.hex
echo "hexdump complete"
octaldump cpp/8bit/8bit cpp/8bit/8bit.oct
binwalk -e cpp/8bit/8bit > cpp/8bit/8bit.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "bin2dec.cpp"
echo "		PID 6"
echo "---- ---- ---- ----"
bindump cpp/bin2dec/bin2dec cpp/bin2dec/bin2dec.binary
hexdump cpp/bin2dec/bin2dec > cpp/bin2dec/bin2dec.hex
echo "hexdump complete"
octaldump cpp/bin2dec/bin2dec cpp/bin2dec/bin2dec.oct
binwalk -e cpp/bin2dec/bin2dec > cpp/bin2dec/bin2dec.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "dec2hex.cpp"
echo "		PID 7"
echo "---- ---- ---- ----"
bindump cpp/dec2hex/dec2hex cpp/dec2hex/dec2hex.binary
hexdump cpp/dec2hex/dec2hex  > cpp/dec2hex/dec2hex.hex
echo "hexdump complete"
octaldump cpp/dec2hex/dec2hex cpp/dec2hex/dec2hex.oct
binwalk -e cpp/dec2hex/dec2hex > cpp/dec2hex/dec2hex.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "hex2bin.cpp"
echo "		PID 8"
echo "---- ---- ---- ----"
bindump cpp/hex2bin/hex2bin cpp/hex2bin/hex2bin.binary
hexdump cpp/hex2bin/hex2bin  > cpp/hex2bin/hex2bin.hex
echo "hexdump complete"
octaldump cpp/hex2bin/hex2bin cpp/hex2bin/hex2bin.oct
binwalk -e cpp/hex2bin/hex2bin > cpp/hex2bin/hex2bin.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "hex2dec.cpp"
echo "		PID 9"
echo "---- ---- ---- ----"
bindump cpp/hex2dec/hex2dec cpp/hex2dec/hex2dec.binary
hexdump cpp/hex2dec/hex2dec  > cpp/hex2dec/hex2dec.hex
echo "hexdump complete"
octaldump cpp/hex2dec/hex2dec cpp/hex2dec/hex2dec.oct
binwalk -e cpp/hex2dec/hex2dec > cpp/hex2dec/hex2dec.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "ohms.cpp"
echo "		PID 10"
echo "---- ---- ---- ----"
bindump cpp/ohms/ohms cpp/ohms/ohms.binary
hexdump cpp/ohms/ohms  > cpp/ohms/ohms.hex
echo "hexdump complete"
octaldump cpp/ohms/ohms cpp/ohms/ohms.oct
binwalk -e cpp/ohms/ohms > cpp/ohms/ohms.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "watts.cpp"
echo "		PID 11"
echo "---- ---- ---- ----"
bindump cpp/watts/watts cpp/watts/watts.binary
hexdump cpp/watts/watts > cpp/watts/watts.hex
echo "hexdump complete"
octaldump cpp/watts/watts cpp/watts/watts.oct
binwalk -e cpp/watts/watts > cpp/watts/watts.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "race_est.cpp"
echo "		PID 12"
echo "---- ---- ---- ----"
bindump cpp/race_est/race_est cpp/race_est/race_est.binary
hexdump cpp/race_est/race_est  > cpp/race_est/race_est.hex
echo "hexdump complete"
octaldump cpp/race_est/race_est cpp/race_est/race_est.oct
binwalk -e cpp/race_est/race_est > cpp/race_est/race_est.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "ticket.cpp"
echo "		PID 13"
echo "---- ---- ---- ----"
bindump cpp/ticket/ticket cpp/ticket/ticket.binary
hexdump cpp/ticket/ticket  > cpp/ticket/ticket.hex
echo "hexdump complete"
octaldump cpp/ticket/ticket cpp/ticket/ticket.oct
binwalk -e cpp/ticket/ticket >  cpp/ticket/ticket.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "unix.cpp"
echo "		PID 14"
echo "---- ---- ---- ----"
bindump cpp/unix/unix cpp/unix/unix.binary
hexdump cpp/unix/unix  > cpp/unix/unix.hex
echo "hexdump complete"
octaldump cpp/unix/unix cpp/unix/unix.oct
binwalk -e cpp/unix/unix > cpp/unix/unix.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "kmph2mph.cpp"
echo "		PID 15"
echo "---- ---- ---- ----"
bindump cpp/kmph2mph/kmph2mph cpp/kmph2mph/kmph2mph.binary
hexdump cpp/kmph2mph/kmph2mph  > cpp/kmph2mph/kmph2mph.hex
echo "hexdump complete"
octaldump cpp/kmph2mph/kmph2mph cpp/kmph2mph/kmph2mph.oct
binwalk -e cpp/kmph2mph/kmph2mph > cpp/kmph2mph/kmph2mph.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "mph2kmph.cpp"
echo "		PID 16"
echo "---- ---- ---- ----"
bindump cpp/mph2kmph/mph2kmph cpp/mph2kmph/mph2kmph.binary
hexdump cpp/mph2kmph/mph2kmph  > cpp/mph2kmph/mph2kmph.hex
echo "hexdump complete"
octaldump cpp/mph2kmph/mph2kmph cpp/mph2kmph/mph2kmph.oct
binwalk -e cpp/mph2kmph/mph2kmph > cpp/mph2kmph/mph2kmph.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "c2f.cpp"
echo "		PID 17"
echo "---- ---- ---- ----"
bindump cpp/c2f/c2f cpp/c2f/c2f.binary
hexdump cpp/c2f/c2f  > cpp/c2f/c2f.hex
echo "hexdump complete"
octaldump cpp/c2f/c2f cpp/c2f/c2f.oct
binwalk -e cpp/c2f/c2f > cpp/c2f/c2f.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "f2c.cpp"
echo "		PID 18"
echo "---- ---- ---- ----"
bindump cpp/f2c/f2c cpp/f2c/f2c.binary
hexdump cpp/f2c/f2c  > cpp/f2c/f2c.hex
echo "hexdump complete"
octaldump cpp/f2c/f2c cpp/f2c/f2c.oct
binwalk -e cpp/f2c/f2c > cpp/f2c/f2c.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "fma.CPP"
echo "		PID 19"
echo "---- ---- ---- ----"
bindump cpp/fma/fma cpp/fma/fma.binary
hexdump cpp/fma/fma  > cpp/fma/fma.hex
echo "hexdump complete"
octaldump cpp/fma/fma cpp/fma/fma.oct
binwalk -e cpp/fma/fma > cpp/fma/fma.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "force.f90"
echo "		PID 20"
echo "---- ---- ---- ----"
bindump fortran/force/force fortran/force/force.binary
hexdump fortran/force/force  > fortran/force/force.hex
echo "hexdump complete"
octaldump fortran/force/force fortran/force/force.oct
binwalk -e fortran/force/force > fortran/force/force.binwalk
echo "binwalk complete"
echo "\n"

echo "\n"
echo "calc.f90"
echo "		PID 21"
echo "---- ---- ---- ----"
bindump fortran/calc/calc fortran/calc/calc.binary
hexdump fortran/calc/calc  > fortran/calc/calc.hex
echo "hexdump complete"
octaldump fortran/calc/calc fortran/calc/calc.oct
binwalk -e fortran/calc/calc > fortran/calc/calc.binwalk
echo "binwalk complete"
echo "\n"
