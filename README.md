# UnixDEV
Some code I made for my Unix workstation

Should work with most linux and BSD distros

To compile:

Download the current release on the right hand side of the main repository page

Unzip the current release

Copy code.zip and code.sh to your home folder. You can simply open a terminal where the file was downloaded and run:
        
        cp code.zip code.sh ~/

Go to your home folder and run:
        
        sudo chmod +x code.sh

Then run:
        
        ./code.sh

Now you should be able to run any C++, C, and Fortran app from the command line

If you have a disro like Fedora, Arch, FreeBSD or OpenBSD and you don't mind Fortran cimpilation failing

For Fedora:

        ./code-yum.sh

For Arch:

        ./code-arch.sh

For FreeBSD:

        ./code-bsd.sh

For OpenBSD:

        ./code-openbsd.sh
