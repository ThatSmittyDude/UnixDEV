bindump c/bindump/bindump c/bindump/bindump.binary
hexdump c/bindump/bindump > c/bindump/bindump.hex
octaldump c/bindump/bindump c/bindump/bindump.oct
binwalk -e c/bindump/bindump > c/bindump/bindump.binwalk
echo "hexdump complete"
echo "binwalk.c"
echo "\n"

bindump c/octaldump/octaldump c/octaldump/octaldump.binary
hexdump c/octaldump/octaldump > c/octaldump/octaldump.hex
octaldump c/octaldump/octaldump c/octaldump/octaldump.oct
binwalk -e c/octaldump/octaldump > c/octaldump/octaldump.binwalk
echo "hexdump complete"
echo "octaldump.c"
echo "\n"

bindump c/txt2bin/txt2bin c/txt2bin/txt2bin.binary
hexdump c/txt2bin/txt2bin > c/txt2bin/txt2bin.hex
octaldump c/txt2bin/txt2bin c/txt2bin/txt2bin.oct
binwalk -e c/txt2bin/txt2bin > c/txt2bin/txt2bin.binwalk
echo "hexdump complete"
echo "txt2bin.c"
echo "\n"

bindump c/txt2hex/txt2hex c/txt2hex/txt2hex.binary
hexdump c/txt2hex/txt2hex > c/txt2hex/txt2hex.hex
octaldump c/txt2hex/txt2hex c/txt2hex/txt2hex.oct
binwalk -e c/txt2hex/txt2hex > c/txt2hex/txt2hex.binwalk
echo "hexdump complete"
echo "txt2hex.c"
echo "\n"

bindump c/hex2string/hex2string c/hex2string/hex2string.binary
hexdump c/hex2string/hex2string > c/hex2string/hex2string.hex
octaldump c/hex2string/hex2string c/hex2string/hex2string.oct
binwalk -e c/hex2string/hex2string > c/hex2string/hex2string.binwalk
echo "hexdump complete"
echo "hex2string.c"
echo "\n"

bindump cpp/8bit/8bit cpp/8bit/8bit.binary
hexdump cpp/8bit/8bit > cpp/8bit/8bit.hex
octaldump cpp/8bit/8bit cpp/8bit/8bit.oct
binwalk -e cpp/8bit/8bit > cpp/8bit/8bit.binwalk
echo "hexdump complete"
echo "8bit.cpp"
echo "\n"

bindump cpp/bin2dec/bin2dec cpp/bin2dec/bin2dec.binary
hexdump cpp/bin2dec/bin2dec > cpp/bin2dec/bin2dec.hex
octaldump cpp/bin2dec/bin2dec cpp/bin2dec/bin2dec.oct
binwalk -e cpp/bin2dec/bin2dec > cpp/bin2dec/bin2dec.binwalk
echo "hexdump complete"
echo "bin2dec.cpp"
echo "\n"

bindump cpp/dec2hex/dec2hex cpp/dec2hex/dec2hex.binary
hexdump cpp/dec2hex/dec2hex  > cpp/dec2hex/dec2hex.hex
octaldump cpp/dec2hex/dec2hex cpp/dec2hex/dec2hex.oct
binwalk -e cpp/dec2hex/dec2hex > cpp/dec2hex/dec2hex.binwalk
echo "hexdump complete"
echo "dec2hex.cpp"
echo "\n"

bindump cpp/hex2bin/hex2bin cpp/hex2bin/hex2bin.binary
hexdump cpp/hex2bin/hex2bin  > cpp/hex2bin/hex2bin.hex
octaldump cpp/hex2bin/hex2bin cpp/hex2bin/hex2bin.oct
binwalk -e cpp/hex2bin/hex2bin > cpp/hex2bin/hex2bin.binwalk
echo "hexdump complete"
echo "hex2bin.cpp"
echo "\n"

bindump cpp/hex2dec/hex2dec cpp/hex2dec/hex2dec.binary
hexdump cpp/hex2dec/hex2dec  > cpp/hex2dec/hex2dec.hex
octaldump cpp/hex2dec/hex2dec cpp/hex2dec/hex2dec.oct
binwalk -e cpp/hex2dec/hex2dec > cpp/hex2dec/hex2dec.binwalk
echo "hexdump complete"
echo "hex2dec.cpp"
echo "\n"

bindump cpp/ohms/ohms cpp/ohms/ohms.binary
hexdump cpp/ohms/ohms  > cpp/ohms/ohms.hex
octaldump cpp/ohms/ohms cpp/ohms/ohms.oct
binwalk -e cpp/ohms/ohms > cpp/ohms/ohms.binwalk
echo "hexdump complete"
echo "ohms.cpp"
echo "\n"

bindump cpp/race_est/race_est cpp/race_est/race_est.binary
hexdump cpp/race_est/race_est  > cpp/race_est/race_est.hex
octaldump cpp/race_est/race_est cpp/race_est/race_est.oct
binwalk -e cpp/race_est/race_est > cpp/race_est/race_est.binwalk
echo "hexdump complete"
echo "race_est.cpp"
echo "\n"

bindump cpp/ticket/ticket cpp/ticket/ticket.binary
hexdump cpp/ticket/ticket  > cpp/ticket/ticket.hex
octaldump cpp/ticket/ticket cpp/ticket/ticket.oct
binwalk -e cpp/ticket/ticket >  cpp/ticket/ticket.binwalk
echo "hexdump complete"
echo "ticket.cpp"
echo "\n"

bindump cpp/unix/unix cpp/unix/unix.binary
hexdump cpp/unix/unix  > cpp/unix/unix.hex
octaldump cpp/unix/unix cpp/unix/unix.oct
binwalk -e cpp/unix/unix > cpp/unix/unix.binwalk
echo "hexdump complete"
echo "unix.cpp"
echo "\n"

bindump cpp/kmph2mph/kmph2mph cpp/kmph2mph/kmph2mph.binary
hexdump cpp/kmph2mph/kmph2mph  > cpp/kmph2mph/kmph2mph.hex
octaldump cpp/kmph2mph/kmph2mph cpp/kmph2mph/kmph2mph.oct
binwalk -e cpp/kmph2mph/kmph2mph > cpp/kmph2mph/kmph2mph.binwalk
echo "hexdump complete"
echo "kmph2mph.cpp"
echo "\n"

bindump cpp/mph2kmph/mph2kmph cpp/mph2kmph/mph2kmph.binary
hexdump cpp/mph2kmph/mph2kmph  > cpp/mph2kmph/mph2kmph.hex
octaldump cpp/mph2kmph/mph2kmph cpp/mph2kmph/mph2kmph.oct
binwalk -e cpp/mph2kmph/mph2kmph > cpp/mph2kmph/mph2kmph.binwalk
echo "hexdump complete"
echo "mph2kmph.cpp"
echo "\n"

bindump cpp/c2f/c2f cpp/c2f/c2f.binary
hexdump cpp/c2f/c2f  > cpp/c2f/c2f.hex
octaldump cpp/c2f/c2f cpp/c2f/c2f.oct
binwalk -e cpp/c2f/c2f > cpp/c2f/c2f.binwalk
echo "hexdump complete"
echo "c2f.cpp"
echo "\n"

bindump cpp/f2c/f2c cpp/f2c/f2c.binary
hexdump cpp/f2c/f2c  > cpp/f2c/f2c.hex
octaldump cpp/f2c/f2c cpp/f2c/f2c.oct
binwalk -e cpp/f2c/f2c > cpp/f2c/f2c.binwalk
echo "hexdump complete"
echo "f2c.cpp"
echo "\n"

bindump cpp/fma/fma cpp/fma/fma.binary
hexdump cpp/fma/fma  > cpp/fma/fma.hex
octaldump cpp/fma/fma cpp/fma/fma.oct
binwalk -e cpp/fma/fma > cpp/fma/fma.binwalk
echo "hexdump complete"
echo "fma.cpp"
echo "\n"

bindump fortran/force/force fortran/force/force.binary
hexdump fortran/force/force  > fortran/force/force.hex
octaldump fortran/force/force fortran/force/force.oct
binwalk -e fortran/force/force > fortran/force/force.binwalk
echo "hexdump complete"
echo "force.f90"
echo "\n"

bindump fortran/calc/calc fortran/calc/calc.binary
hexdump fortran/calc/calc  > fortran/calc/calc.hex
octaldump fortran/calc/calc fortran/calc/calc.oct
binwalk -e fortran/calc/calc > fortran/calc/calc.binwalk
echo "hexdump complete"
echo "calc.f90"
echo "\n"
