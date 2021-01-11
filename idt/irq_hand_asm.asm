global irq0
global irq1
global irq2
global irq3
global irq4
global irq5
global irq6
global irq7
global irq8
global irq9
global irq10
global irq11
global irq12
global irq13
global irq14
global irq15
 
global load_idt
 
extern _Z12irq0_handlerv
extern _Z12irq1_handlerv
extern _Z12irq2_handlerv
extern _Z12irq3_handlerv
extern _Z12irq4_handlerv
extern _Z12irq5_handlerv
extern _Z12irq6_handlerv
extern _Z12irq7_handlerv
extern _Z12irq8_handlerv
extern _Z12irq9_handlerv
extern _Z13irq10_handlerv
extern _Z13irq11_handlerv
extern _Z13irq12_handlerv
extern _Z13irq13_handlerv
extern _Z13irq14_handlerv
extern _Z13irq15_handlerv
 
irq0:
  pushad
  call _Z12irq0_handlerv
  popad
  iret
 
irq1:
  pushad
  call _Z12irq1_handlerv
  popad
  iret
 
irq2:
  pushad
  call _Z12irq2_handlerv
  popad
  iret
 
irq3:
  pushad
  call _Z12irq3_handlerv
  popad
  iret
 
irq4:
  pushad
  call _Z12irq4_handlerv
  popad
  iret
 
irq5:
  pushad
  call _Z12irq5_handlerv
  popad
  iret
 
irq6:
  pushad
  call _Z12irq6_handlerv
  popad
  iret
 
irq7:
  pushad
  call _Z12irq7_handlerv
  popad
  iret
 
irq8:
  pushad
  call _Z12irq8_handlerv
  popad
  iret
 
irq9:
  pushad
  call _Z12irq9_handlerv
  popad
  iret
 
irq10:
  pushad
  call _Z13irq10_handlerv
  popad
  iret
 
irq11:
  pushad
  call _Z13irq11_handlerv
  popad
  iret
 
irq12:
  pushad
  call _Z13irq12_handlerv
  popad
  iret
 
irq13:
  pushad
  call _Z13irq13_handlerv
  popad
  iret
 
irq14:
  pushad
  call _Z13irq14_handlerv
  popad
  iret
 
irq15:
  pushad
  call _Z13irq15_handlerv
  popad
  iret
 
load_idt:
	mov edx, [esp + 4]
	lidt [edx]
	sti
	ret
