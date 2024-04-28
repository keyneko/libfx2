#include <fx2regs.h>
#include <fx2debug.h>
#include <fx2delay.h>
#include <stdio.h>

DEFINE_DEBUG_PUTCHAR_FN(PA0, 9600)

int main(void) {
  // Any of these will work at 57600 baud:
  // CPUCS = 0;  // 12MHz
  CPUCS = _CLKSPD0;  // 24MHz
  // CPUCS = _CLKSPD1; // 48Mhz

  OEA = (1U<<0);
  PA0 = 1;

  int cnt = 0;

  while(1) {
    delay_ms(1000);
    printf("Hello, world %d\r\n", cnt);
    cnt++;
  };
}
