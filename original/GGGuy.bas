GUI "Game Genie Guy!", ICON, 100
DIM Form AS CONTROL, Check1 AS CONTROL, Check2 AS CONTROL, Combo AS CONTROL, Edit1 AS CONTROL, Edit2 AS CONTROL, Edit3 AS CONTROL
DIM Line$[200], Bit$, Code$, Dec$, File1$, File2$, Out$
DIM Cmp, Lnum, Num, Off, Rep

SUB FORMLOAD
Form = BCX_FORM("Game Genie Guy! (20150313)", 0, 0, 150, 218)
Check1 = BCX_CHECKBOX ("Checksum", Form, 101, 5, 141, 35, 15)
Check2 = BCX_CHECKBOX ("Make IPS", Form, 102, 43, 141, 33, 15)
Combo = BCX_COMBOBOX("", Form, 103, 5, 35, 139, 52)
Edit1 = BCX_INPUT("", Form, 104, 5, 10, 105, 11)
Edit2 = BCX_EDIT("", Form, 105, 5, 60, 139, 69)
Edit3 = BCX_EDIT("", Form, 106, 5, 168, 139, 41)
BCX_GROUP("Rom:", Form, 107, 2, 2, 147, 24)
BCX_GROUP("Codes (One per line or combine with + ):", Form, 108, 2, 52, 147, 82)
BCX_GROUP("Options:", Form, 109, 2, 135, 147, 24)
BCX_GROUP("System:", Form, 110, 2, 27, 147, 24)
BCX_GROUP("Result:", Form, 111, 2, 160, 147, 54)
BCX_BUTTON("Browse", Form, 112, 114, 10, 30, 11)
BCX_BUTTON("Reset", Form, 113, 80, 143, 30, 11)
BCX_BUTTON("Patch", Form, 114, 114, 143, 30, 11)
SendMessage(Combo, CB_ADDSTRING, 0, "Game Boy/Gear/Master System")
SendMessage(Combo, CB_ADDSTRING, 1, "Genesis/Mega Drive")
SendMessage(Combo, CB_ADDSTRING, 2, "Hex (XXXX:XX)")
SendMessage(Combo, CB_ADDSTRING, 3, "Nintendo")
SendMessage(Combo, CB_ADDSTRING, 4, "Super Nintendo")
SendMessage(Combo, CB_ADDSTRING, 5, "TurboGrafx-16/PC Engine")
MODSTYLE(Form, 0, WS_MAXIMIZEBOX OR WS_SIZEBOX)
CENTER(Form)
SHOW(Form)
SetWindowPos(Form, HWND_TOPMOST, 0, 0, 0, 0, SWP_NOMOVE OR SWP_NOSIZE)
END SUB

BEGIN EVENTS
SELECT CASE CBMSG
CASE WM_COMMAND
'===== OPEN ==================================================
IF CBCTL = 112 THEN
 File1$ = GETFILENAME$("Open", "All Files(*.*)|*.*|", 0, Form)
 CHDIR APPEXEPATH$
 BCX_SET_TEXT(Combo, "")
 BCX_SET_TEXT(Edit1, File1$)
 BCX_SET_TEXT(Edit3, "")
 SendMessage(Check1, BM_SETCHECK, 0, 0)
 Bit$ = LCASE$(RIGHT$(File1$, LEN(File1$) - INSTRREV(File1$, ".")))
 IF Bit$ = "gb" OR Bit$ = "gbc" OR Bit$ = "gg" OR Bit$ = "sms" THEN BCX_SET_TEXT(Combo, "Game Boy/Gear/Master System")
 IF Bit$ = "bin" OR Bit$ = "gen" OR Bit$ = "md" OR Bit$ = "32x" THEN BCX_SET_TEXT(Combo, "Genesis/Mega Drive")
 IF Bit$ = "fds" OR Bit$ = "nes" OR Bit$ = "unf" THEN BCX_SET_TEXT(Combo, "Nintendo")
 IF Bit$ = "bsx" OR Bit$ = "fig" OR Bit$ = "sfc" OR Bit$ = "smc" OR Bit$ = "swc" THEN BCX_SET_TEXT(Combo, "Super Nintendo")
 IF Bit$ = "pce" THEN BCX_SET_TEXT(Combo, "TurboGrafx-16/PC Engine")
 IF Bit$ = "smd" THEN
  MSGBOX ".SMD files are unsupported. Choose a .BIN or .GEN", "Oops!"
  BCX_SET_TEXT(Edit1, "")
 END IF
 IF EXIST("ucon64.exe") AND BCX_GET_TEXT$(Combo) <> "" AND BCX_GET_TEXT$(Combo) <> "Nintendo" AND _
 BCX_GET_TEXT$(Combo) <> "TurboGrafx-16/PC Engine" THEN SendMessage(Check1, BM_SETCHECK, 1, 0)
'===== IPS ===================================================
 IF Bit$ = "ips" THEN
  IF EXIST("ucon64.exe") THEN
   File2$ = GETFILENAME$("Open", "All Files(*.*)|*.*|", 0, Form)
   CHDIR APPEXEPATH$
   Code$ = LEFT$(File1$, INSTRREV(File1$, ".")) & RIGHT$(File2$, LEN(File2$) - INSTRREV(File2$, "."))
   IF EXIST(Code$) THEN KILL Code$
   IF EXIST(File2$) THEN COPYFILE File2$, Code$
   SHELL "ucon64 --nbak -o " & CHR$(34) & LEFT$(Code$, INSTRREV(Code$, "\") - 1) & CHR$(34) & " " & CHR$(34) & Code$ & CHR$(34) & _
   " -i " & CHR$(34) & File1$ & CHR$(34)
   Out$ = RIGHT$(File1$, LEN(File1$) - INSTRREV(File1$, "\")) & " applied to " & RIGHT$(Code$, LEN(Code$) - INSTRREV(Code$, "\"))
   BCX_SET_TEXT(Edit3, Out$)
  ELSE
   MSGBOX "ucon64.exe is required for IPS patching.", "Oops!"
  END IF
 END IF
END IF
'===== RESET LOG =============================================
IF CBCTL = 113 THEN
 Out$ = ""
 BCX_SET_TEXT(Edit3, "")
END IF
'===== PATCH =================================================
IF CBCTL = 114 THEN
 FOR Num = 0 TO 200
  Line$[Num] = ""
 NEXT
 Code$ = BCX_GET_TEXT$(Edit2)
 REPLACE "-" WITH "" IN Code$
 REPLACE "+" WITH LF$ IN Code$
 SPLIT(Line$, Code$, LF$)
 FOR Num = 0 TO 200
  Line$[Num] = TRIM$(UCASE$(Line$[Num]))
 NEXT
 IF BCX_GET_TEXT$(Edit1) <> "" AND Line$[0] <> "" THEN
  File1$ = TRIM$(BCX_GET_TEXT$(Edit1))
  Bit$ = LCASE$(RIGHT$(File1$, LEN(File1$) - INSTRREV(File1$, ".")))
  IF File2$ <> LEFT$(File1$, INSTRREV(File1$, ".") - 1) & " GG." & RIGHT$(File1$, LEN(File1$) - INSTRREV(File1$, ".")) THEN Out$ = ""
  File2$ = LEFT$(File1$, INSTRREV(File1$, ".") - 1) & " GG." & RIGHT$(File1$, LEN(File1$) - INSTRREV(File1$, "."))
  IF EXIST(File2$) THEN KILL File2$
  IF EXIST(File1$) THEN COPYFILE File1$, File2$
  IF EXIST(File2$) THEN OPEN File2$ FOR BINARY AS FP2
  FOR Lnum = 0 TO 200
   IF Line$[Lnum] <> "" THEN
    Code$ = Line$[Lnum]
    Dec$ = ""
'===== SMS/PCE/RAW ===========================================
    IF INSTR(Code$, ":") THEN
     IF Bit$ = "pce" OR Bit$ = "sms" AND LOF(File1$) % 1024 THEN Off = Off + 512
     IF BCX_GET_TEXT$(Combo) <> "Hex (XXXX:XX)" THEN BCX_SET_TEXT(Combo, "Hex (XXXX:XX)")
     Off = HEX2DEC(LEFT$(Code$, LEN(Code$) - 3))
     Rep = HEX2DEC(RIGHT$(Code$, 2))
     IF Off < LOF(File1$) THEN
      SEEK FP2, Off
      PUT$ FP2, CHR$(Rep), 1
      Out$ = Line$[Lnum] & CRLF$ & Out$
      BCX_SET_TEXT(Edit3, Out$)
     END IF
    END IF
'===== GB/GG SHORT ===========================================
    IF BCX_GET_TEXT$(Combo) = "Game Boy/Gear/Master System" THEN
     IF LEN(Code$) = 6 THEN
      Code$ = HEX$(HEX2DEC(MID$(Code$, 6, 1)) XOR 15) & MID$(Code$, 3, 3) & ":" & LEFT$(Code$, 2)
      Off = HEX2DEC(LEFT$(Code$, 4))
      Rep = HEX2DEC(RIGHT$(Code$, 2))
      FOR Num = 0 TO LOF(File1$) / 8192
       IF Off < LOF(File1$) THEN
        SEEK FP2, Off
        PUT$ FP2, CHR$(Rep), 1
        Out$ = Line$[Lnum] & " - " & TRIM$(HEX$(Off)) & ":" & TRIM$(HEX$(Cmp)) & ":" & TRIM$(HEX$(Rep)) & CRLF$ & Out$
        BCX_SET_TEXT(Edit3, Out$)
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
         BCX_SET_TEXT(Edit3, Out$)
        END IF
       END IF
       Off = Off + 8192
      NEXT
     END IF
    END IF
'===== MD ====================================================
    IF BCX_GET_TEXT$(Combo) = "Genesis/Mega Drive" THEN
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
      BCX_SET_TEXT(Edit3, Out$)
     END IF
    END IF
'===== NES SHORT =============================================
    IF BCX_GET_TEXT$(Combo) = "Nintendo" THEN
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
         BCX_SET_TEXT(Edit3, Out$)
        END IF
        Off = Off + 8192
       NEXT
      ELSE
       SEEK FP2, Off
       PUT$ FP2, CHR$(Rep), 1
       Out$ = Line$[Lnum] & " - " & TRIM$(HEX$(Off)) & ":" & TRIM$(HEX$(Cmp)) & ":" & TRIM$(HEX$(Rep)) & CRLF$ & Out$
       BCX_SET_TEXT(Edit3, Out$)
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
         BCX_SET_TEXT(Edit3, Out$)
        END IF
       END IF
       Off = Off + 8192
      NEXT
     END IF
    END IF
'===== SNES ==================================================
    IF BCX_GET_TEXT$(Combo) = "Super Nintendo" THEN
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
      BCX_SET_TEXT(Edit3, Out$)
     END IF
    END IF
'=============================================================
   END IF
  NEXT
  CLOSE FP1
  CLOSE FP2
'===== CHECKSUM ==============================================
  IF SendMessage(Check1, BM_GETCHECK, 0, 0) <> 0 AND Out$ <> "" THEN
   IF EXIST("ucon64.exe") THEN
    Bit$ = LCASE$(RIGHT$(File1$, LEN(File1$) - INSTRREV(File1$, ".")))
    IF Bit$ = "gb" OR Bit$ = "gbc" OR Bit$ = "gg" THEN Bit$ = "gb"
    IF Bit$ = "bin" OR Bit$ = "gen" OR Bit$ = "md" OR Bit$ = "32x" THEN Bit$ = "gen"
    IF Bit$ = "bsx" OR Bit$ = "fig" OR Bit$ = "sfc" OR Bit$ = "smc" OR Bit$ = "swc" THEN Bit$ = "snes"
    SHELL "ucon64 --nbak --" & Bit$ & " --chk -o " & CHR$(34) & LEFT$(File1$, INSTRREV(File1$, "\") - 1) & CHR$(34) & " " & _
    CHR$(34) & File2$ & CHR$(34)
   ELSE
    MSGBOX "ucon64.exe is required for checksum fixing.", "Oops!"
   END IF
  END IF
'===== IPS ===================================================
  IF SendMessage(Check2, BM_GETCHECK, 0, 0) <> 0 AND Out$ <> "" THEN
   IF EXIST("ucon64.exe") THEN
    Code$ = LEFT$(File1$, INSTRREV(File1$, ".") - 1) & " GG.ips"
    IF EXIST(Code$) THEN KILL Code$
    SHELL "ucon64 -o " & CHR$(34) & LEFT$(File1$, INSTRREV(File1$, "\") - 1) & CHR$(34) & " " & CHR$(34) & File2$ & CHR$(34) & _
    " --mki=" & CHR$(34) & File1$ & CHR$(34)
   ELSE
    MSGBOX "ucon64.exe is required for IPS creation.", "Oops!"
   END IF
  END IF
'=============================================================
  END IF
END IF
END SELECT
END EVENTS
