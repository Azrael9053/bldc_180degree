-------- PROJECT GENERATOR --------
PROJECT NAME :	180degree
PROJECT DIRECTORY :	C:\WorkSpace\180degree\180degree
CPU SERIES :	RX600
CPU TYPE :	RX62T
TOOLCHAIN NAME :	Renesas RX Standard Toolchain
TOOLCHAIN VERSION :	1.0.1.0
GENERATION FILES :
    C:\WorkSpace\180degree\180degree\dbsct.c
        Setting of B,R Section
    C:\WorkSpace\180degree\180degree\typedefine.h
        Aliases of Integer Type
    C:\WorkSpace\180degree\180degree\sbrk.c
        Program of sbrk
    C:\WorkSpace\180degree\180degree\iodefine.h
        Definition of I/O Register
    C:\WorkSpace\180degree\180degree\intprg.c
        Interrupt Program
    C:\WorkSpace\180degree\180degree\vecttbl.c
        Initialize of Vector Table
    C:\WorkSpace\180degree\180degree\vect.h
        Definition of Vector
    C:\WorkSpace\180degree\180degree\resetprg.c
        Reset Program
    C:\WorkSpace\180degree\180degree\180degree.c
        Main Program
    C:\WorkSpace\180degree\180degree\sbrk.h
        Header file of sbrk file
    C:\WorkSpace\180degree\180degree\stacksct.h
        Setting of Stack area
START ADDRESS OF SECTION :
 H'1000	B_1,R_1,B_2,R_2,B,R,SU,SI
 H'FFFF8000	PResetPRG
 H'FFFF8100	C_1,C_2,C,C$*,D*,P,PIntPRG,W*
 H'FFFFFFD0	FIXEDVECT

* When the user program is executed,
* the interrupt mask has been masked.
* 
* Program start 0xFFFF8000.
* RAM start 0x1000.

SELECT TARGET :
    RX600 Segger J-Link
DATE & TIME : 2022/5/27 ¤U¤È 01:25:27
