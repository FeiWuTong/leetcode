@ set start=300
@ set end=321
@ set baseFile=template.cpp

:loop
@ copy %baseFile% %start%.cpp
@ set /a start+=1
@ if %start%==%end% exit
@ goto loop