DIM Line$[200], Bit$, Code$, Dec$, File1$, File2$, Out$, Type$
DIM Cmp, Lnum, Num, Off, Rep, Codes
$GLIB
$GTK
$CPP
$CPPHDR
#include "./include/functions.c"
 
IF (ARGC < 4) THEN
   PRINT "ERROR: Missing some parameters, check the readme"
   EXIT(1)
END IF
Code$ = argv$[1]
Type$ = argv$[2]
File1$ = argv$[3]
File2$ = argv$[4]
IF EXIST(File2$) THEN KILL File2$
IF EXIST(File1$) THEN 
  COPYFILE File1$, File2$
ELSE
  PRINT "ERROR: ROM doesn't exists"
  EXIT(1)
END IF
REPLACE "-" WITH "" IN Code$
REPLACE "+" WITH LF$ IN Code$
Codes = SPLIT(Line$, Code$, LF$)
PRINT "Codes to inject: " + STR$(Codes)
Bit$ = LCASE$(RIGHT$(File1$, LEN(File1$) - INSTRREV(File1$, ".")))
PRINT "Rom to patch: " & File1$
PRINT "Patch at: " & File2$

IF EXIST(File2$) THEN OPEN File2$ FOR BINARY AS FP2
PRINT CRLF$ & "Log:"

FOR Lnum = 0 TO Codes
 Line$[Num] = TRIM$(UCASE$(Line$[Num]))
 IF Line$[Lnum] <> "" THEN
  Code$ = Line$[Lnum]
  PRINT "Parsing code: " & Code$
  Dec$ = ""
'==== SMS/PCE/RAW ===========================================
  IF INSTR(Code$, ":") THEN
    IF Bit$ = "pce" OR (Bit$ = "sms" AND LOF(File1$) % 1024) THEN Off = Off + 512
    Off = HEX2DEC(LEFT$(Code$, LEN(Code$) - 3))
    Rep = HEX2DEC(RIGHT$(Code$, 2))
    IF Off < LOF(File1$) THEN
     SEEK FP2, Off
     PUT$ FP2, CHR$(Rep), 1
     Out$ = Line$[Lnum] & CRLF$ & Out$
     Print Out$
    END IF
   END IF
'===== GB/GG SHORT ===========================================
   IF Type$ = "1" THEN
    IF LEN(Code$) = 6 THEN
     Code$ = HEX$(HEX2DEC(MID$(Code$, 6, 1)) XOR 15) & MID$(Code$, 3, 3) & ":" & LEFT$(Code$, 2)
     Off = HEX2DEC(LEFT$(Code$, 4))
     Rep = HEX2DEC(RIGHT$(Code$, 2))
     FOR Num = 0 TO LOF(File1$) / 8192
      IF Off < LOF(File1$) THEN
       SEEK FP2, Off
       PUT$ FP2, CHR$(Rep), 1
       Out$ = Line$[Lnum] & " - " & TRIM$(HEX$(Off)) & ":" & TRIM$(HEX$(Cmp)) & ":" & TRIM$(HEX$(Rep)) & CRLF$ & Out$
      END IF
      Off = Off + 8192
     NEXT
    END IF
'===== GB/GG LONG ============================================
    IF LEN(Code$) = 9 THEN
     Code$ = HEX$(HEX2DEC(MID$(Code$, 6, 1)) XOR 15) & MID$(Code$, 3, 3) & ":" & LEFT$(Code$, 2) & ":" & _
     MID$(Code$, 7, 1) & MID$(Code$, 9, 1)
     Dec$ = LPAD$(BIN$(HEX2DEC(MID$(Code$, 9, 2))), 8, 48)
     Code$ = LEFT$(Code$, 8) & HEX$(BIN2DEC(MID$(Dec$, 7, 2) & LEFT$(Dec$, 6)) XOR 186)
     Off = HEX2DEC(LEFT$(Code$, 4))
     Cmp = HEX2DEC(RIGHT$(Code$, 2))
     Rep = HEX2DEC(MID$(Code$, 6, 2))
     FOR Num = 0 TO LOF(File1$) / 8192
      IF Off < LOF(File1$) THEN
       SEEK FP2, Off
       GET$ FP2, Code$, 1
       IF ASC(Code$) = Cmp THEN
        SEEK FP2, Off
        PUT$ FP2, CHR$(Rep), 1
        Out$ = Line$[Lnum] & " - " & TRIM$(HEX$(Off)) & ":" & TRIM$(HEX$(Cmp)) & ":" & TRIM$(HEX$(Rep)) & CRLF$ & Out$
       END IF
      END IF
      Off = Off + 8192
     NEXT
    END IF
   END IF
'===== MD ====================================================
   IF Type$ = "2" THEN
    FOR Num = 0 TO LEN(Code$)
     IF MID$(Code$, Num, 1) = "A" THEN Dec$ = Dec$ & "00000"
     IF MID$(Code$, Num, 1) = "B" THEN Dec$ = Dec$ & "00001"
     IF MID$(Code$, Num, 1) = "C" THEN Dec$ = Dec$ & "00010"
     IF MID$(Code$, Num, 1) = "D" THEN Dec$ = Dec$ & "00011"
     IF MID$(Code$, Num, 1) = "E" THEN Dec$ = Dec$ & "00100"
     IF MID$(Code$, Num, 1) = "F" THEN Dec$ = Dec$ & "00101"
     IF MID$(Code$, Num, 1) = "G" THEN Dec$ = Dec$ & "00110"
     IF MID$(Code$, Num, 1) = "H" THEN Dec$ = Dec$ & "00111"
     IF MID$(Code$, Num, 1) = "J" THEN Dec$ = Dec$ & "01000"
     IF MID$(Code$, Num, 1) = "K" THEN Dec$ = Dec$ & "01001"
     IF MID$(Code$, Num, 1) = "L" THEN Dec$ = Dec$ & "01010"
     IF MID$(Code$, Num, 1) = "M" THEN Dec$ = Dec$ & "01011"
     IF MID$(Code$, Num, 1) = "N" THEN Dec$ = Dec$ & "01100"
     IF MID$(Code$, Num, 1) = "P" THEN Dec$ = Dec$ & "01101"
     IF MID$(Code$, Num, 1) = "R" THEN Dec$ = Dec$ & "01110"
     IF MID$(Code$, Num, 1) = "S" THEN Dec$ = Dec$ & "01111"
     IF MID$(Code$, Num, 1) = "T" THEN Dec$ = Dec$ & "10000"
     IF MID$(Code$, Num, 1) = "V" THEN Dec$ = Dec$ & "10001"
     IF MID$(Code$, Num, 1) = "W" THEN Dec$ = Dec$ & "10010"
     IF MID$(Code$, Num, 1) = "X" THEN Dec$ = Dec$ & "10011"
     IF MID$(Code$, Num, 1) = "Y" THEN Dec$ = Dec$ & "10100"
     IF MID$(Code$, Num, 1) = "Z" THEN Dec$ = Dec$ & "10101"
     IF MID$(Code$, Num, 1) = "0" THEN Dec$ = Dec$ & "10110"
     IF MID$(Code$, Num, 1) = "1" THEN Dec$ = Dec$ & "10111"
     IF MID$(Code$, Num, 1) = "2" THEN Dec$ = Dec$ & "11000"
     IF MID$(Code$, Num, 1) = "3" THEN Dec$ = Dec$ & "11001"
     IF MID$(Code$, Num, 1) = "4" THEN Dec$ = Dec$ & "11010"
     IF MID$(Code$, Num, 1) = "5" THEN Dec$ = Dec$ & "11011"
     IF MID$(Code$, Num, 1) = "6" THEN Dec$ = Dec$ & "11100"
     IF MID$(Code$, Num, 1) = "7" THEN Dec$ = Dec$ & "11101"
     IF MID$(Code$, Num, 1) = "8" THEN Dec$ = Dec$ & "11110"
     IF MID$(Code$, Num, 1) = "9" THEN Dec$ = Dec$ & "11111"
    NEXT
    Code$ = MID$(Dec$, 17, 8) & MID$(Dec$, 9, 8) & RIGHT$(Dec$, 8) & MID$(Dec$, 30, 3) & MID$(Dec$, 25, 5) & LEFT$(Dec$, 8)
    Dec$ = LPAD$(HEX$(BIN2DEC(LEFT$(Code$, 24))), 6, 48) & ":" & LPAD$(HEX$(BIN2DEC(RIGHT$(Code$, 16))), 4, 48)
    Off = HEX2DEC(LEFT$(Dec$, 6))
    Cmp = HEX2DEC(MID$(Dec$, 8, 2))
    Rep = HEX2DEC(RIGHT$(Dec$, 2))
    IF Off < LOF(File1$) THEN
     SEEK FP2, Off
     PUT$ FP2, CHR$(Cmp), 1
     SEEK FP2, Off + 1
     PUT$ FP2, CHR$(Rep), 1     
     Out$ = Line$[Lnum] & " - " & TRIM$(HEX$(Off)) & ":" & TRIM$(HEX$(Cmp)) & TRIM$(HEX$(Rep)) & CRLF$ & Out$
    END IF
   END IF
'===== NES SHORT =============================================
   IF Type$ = "3" THEN
    FOR Num = 0 TO LEN(Code$)
     IF MID$(Code$, Num, 1) = "A" THEN Dec$ = Dec$ & "0000"
     IF MID$(Code$, Num, 1) = "P" THEN Dec$ = Dec$ & "0001"
     IF MID$(Code$, Num, 1) = "Z" THEN Dec$ = Dec$ & "0010"
     IF MID$(Code$, Num, 1) = "L" THEN Dec$ = Dec$ & "0011"
     IF MID$(Code$, Num, 1) = "G" THEN Dec$ = Dec$ & "0100"
     IF MID$(Code$, Num, 1) = "I" THEN Dec$ = Dec$ & "0101"
     IF MID$(Code$, Num, 1) = "T" THEN Dec$ = Dec$ & "0110"
     IF MID$(Code$, Num, 1) = "Y" THEN Dec$ = Dec$ & "0111"
     IF MID$(Code$, Num, 1) = "E" THEN Dec$ = Dec$ & "1000"
     IF MID$(Code$, Num, 1) = "O" THEN Dec$ = Dec$ & "1001"
     IF MID$(Code$, Num, 1) = "X" THEN Dec$ = Dec$ & "1010"
     IF MID$(Code$, Num, 1) = "U" THEN Dec$ = Dec$ & "1011"
     IF MID$(Code$, Num, 1) = "K" THEN Dec$ = Dec$ & "1100"
     IF MID$(Code$, Num, 1) = "S" THEN Dec$ = Dec$ & "1101"
     IF MID$(Code$, Num, 1) = "V" THEN Dec$ = Dec$ & "1110"
     IF MID$(Code$, Num, 1) = "N" THEN Dec$ = Dec$ & "1111"
    NEXT
    IF LEN(Code$) = 6 THEN
     Code$ = MID$(Dec$, 9, 1) & MID$(Dec$, 14, 4) & MID$(Dec$, 22, 3) & MID$(Dec$, 5, 1) & MID$(Dec$, 10, 4) & _
     MID$(Dec$, 18, 3) & MID$(Dec$, 1, 1) & MID$(Dec$, 6, 3) & MID$(Dec$, 21, 1) & MID$(Dec$, 2, 3)
     Dec$ = LPAD$(HEX$(BIN2DEC(LEFT$(Code$, 16))), 4, 48) & ":" & LPAD$(HEX$(BIN2DEC(RIGHT$(Code$, 8))), 2, 48)
     Off = HEX2DEC(LEFT$(Dec$, 4))
     Rep = HEX2DEC(RIGHT$(Dec$, 2))
     IF LOF(File1$) % 1024 <> 0 THEN Off = Off + 16
     IF LOF(File1$) >= 49169 THEN
      FOR Num = 0 TO LOF(File1$) / 8192
       IF Off < LOF(File1$) THEN
        SEEK FP2, Off
        PUT$ FP2, CHR$(Rep), 1
        Out$ = Line$[Lnum] & " - " & TRIM$(HEX$(Off)) & ":" & TRIM$(HEX$(Cmp)) & ":" & TRIM$(HEX$(Rep)) & CRLF$ & Out$
       END IF
       Off = Off + 8192
      NEXT
     ELSE
      SEEK FP2, Off
      PUT$ FP2, CHR$(Rep), 1
      Out$ = Line$[Lnum] & " - " & TRIM$(HEX$(Off)) & ":" & TRIM$(HEX$(Cmp)) & ":" & TRIM$(HEX$(Rep)) & CRLF$ & Out$
     END IF
    END IF
'===== NES LONG ==============================================
    IF LEN(Code$) = 8 THEN
     Code$ = MID$(Dec$, 9, 1) & MID$(Dec$, 14, 4) & MID$(Dec$, 22, 3) & MID$(Dec$, 5, 1) & MID$(Dec$, 10, 4) & _
     MID$(Dec$, 18, 3) & MID$(Dec$, 1, 1) & MID$(Dec$, 6, 3) & MID$(Dec$, 29, 1) & MID$(Dec$, 2, 3) & _
     MID$(Dec$, 25, 1) & MID$(Dec$, 30, 3) & MID$(Dec$, 21, 1) & MID$(Dec$, 26, 3)
     Dec$ = LPAD$(HEX$(BIN2DEC(LEFT$(Code$, 16))), 4, 48) & ":" & LPAD$(HEX$(BIN2DEC(MID$(Code$, 17, 8))), 2, 48) & ":" & _
     LPAD$(HEX$(BIN2DEC(RIGHT$(Code$, 8))), 2, 48)
     Off = HEX2DEC(LEFT$(Dec$, 4)) - 49152
     Cmp = HEX2DEC(RIGHT$(Dec$, 2))
     Rep = HEX2DEC(MID$(Dec$, 6, 2))
     IF LOF(File1$) % 1024 <> 0 THEN Off = Off + 16
     FOR Num = 0 TO LOF(File1$) / 8192
      IF Off < LOF(File1$) THEN
       SEEK FP2, Off
       GET$ FP2, Code$, 1
       IF ASC(Code$) = Cmp THEN
        SEEK FP2, Off
        PUT$ FP2, CHR$(Rep), 1
        Out$ = Line$[Lnum] & " - " & TRIM$(HEX$(Off)) & ":" & TRIM$(HEX$(Cmp)) & ":" & TRIM$(HEX$(Rep)) & CRLF$ & Out$
       END IF
      END IF
      Off = Off + 8192
     NEXT
    END IF
   END IF
'===== SNES ==================================================
   IF Type$ = "4" THEN
    FOR Num = 0 TO LEN(Code$)
     IF MID$(Code$, Num, 1) = "D" THEN Dec$ = Dec$ & "0"
     IF MID$(Code$, Num, 1) = "F" THEN Dec$ = Dec$ & "1"
     IF MID$(Code$, Num, 1) = "4" THEN Dec$ = Dec$ & "2"
     IF MID$(Code$, Num, 1) = "7" THEN Dec$ = Dec$ & "3"
     IF MID$(Code$, Num, 1) = "0" THEN Dec$ = Dec$ & "4"
     IF MID$(Code$, Num, 1) = "9" THEN Dec$ = Dec$ & "5"
     IF MID$(Code$, Num, 1) = "1" THEN Dec$ = Dec$ & "6"
     IF MID$(Code$, Num, 1) = "5" THEN Dec$ = Dec$ & "7"
     IF MID$(Code$, Num, 1) = "6" THEN Dec$ = Dec$ & "8"
     IF MID$(Code$, Num, 1) = "B" THEN Dec$ = Dec$ & "9"
     IF MID$(Code$, Num, 1) = "C" THEN Dec$ = Dec$ & "A"
     IF MID$(Code$, Num, 1) = "8" THEN Dec$ = Dec$ & "B"
     IF MID$(Code$, Num, 1) = "A" THEN Dec$ = Dec$ & "C"
     IF MID$(Code$, Num, 1) = "2" THEN Dec$ = Dec$ & "D"
     IF MID$(Code$, Num, 1) = "3" THEN Dec$ = Dec$ & "E"
     IF MID$(Code$, Num, 1) = "E" THEN Dec$ = Dec$ & "F"
    NEXT
    Rep = HEX2DEC(LEFT$(Dec$, 2))
    Code$ = LPAD$(BIN$(HEX2DEC(MID$(Dec$, 3, 2))), 8, 48) & LPAD$(BIN$(HEX2DEC(MID$(Dec$, 5, 2))), 8, 48) & _
    LPAD$(BIN$(HEX2DEC(MID$(Dec$, 7, 2))), 8, 48)
    Dec$ = MID$(Code$, 11, 4) & MID$(Code$, 19, 4) & LEFT$(Code$, 4) & MID$(Code$, 23, 2) & MID$(Code$, 9, 2) & _
    MID$(Code$, 5, 4) & MID$(Code$, 15, 4)
    Code$ = LPAD$(HEX$(BIN2DEC(LEFT$(Dec$, 8))), 2, 48) & LPAD$(HEX$(BIN2DEC(MID$(Dec$, 9, 8))), 2, 48) & _
    LPAD$(HEX$(BIN2DEC(RIGHT$(Dec$, 8))), 2, 48) & ":" & HEX$(Rep)
    Off = HEX2DEC(LEFT$(Code$, 6))
    IF LOF(File1$) % 1024 <> 0 THEN Off = Off + 512
    Dec$ = HEX$(Off)
'===== SNES HIROM ============================================
    Num = 65493
    IF LOF(File1$) % 1024 <> 0 THEN Num = Num + 512
    SEEK FP2, Num
    GET$ FP2, Bit$, 1
    IF ASC(Bit$) <> 33 AND ASC(Bit$) <> 49 THEN Off = BIN2DEC("0" & LEFT$(LPAD$(BIN$(HEX2DEC(Dec$)), 24, 48), 8) & _
    RIGHT$(LPAD$(BIN$(HEX2DEC(Dec$)), 24, 48), 15))
    IF Off >= 4194304 AND Off <= 8388607 THEN Off = Off - 4194304
    IF Off >= 8388608 AND Off <= 12582911 THEN Off = Off - 8388608
    IF Off >= 12582912 AND Off <= 16777215 THEN Off = Off - 12582912
    IF Off < LOF(File1$) THEN
     SEEK FP2, Off
     PUT$ FP2, CHR$(Rep), 1
     Out$ = Line$[Lnum] & " - " & TRIM$(HEX$(Off)) & ":" & TRIM$(HEX$(Rep)) & CRLF$ & Out$
    END IF
   END IF
'=============================================================
  END IF
NEXT
CLOSE FP2
PRINT "Final Changes:"
PRINT Out$
