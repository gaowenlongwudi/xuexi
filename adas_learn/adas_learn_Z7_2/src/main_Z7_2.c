/*
 * main implementation: use this 'C' sample to create your own application
 *
 */

#include "derivative.h" /* include peripheral declarations */
# include <string.h>       //字符串处理
# include <stdint.h>       //c语言标准数据类型库

uint32_t str0[10];
char str[10];
extern void xcptn_xmpl(void);

int main(void)
{
	volatile int counter = 0;
	
	xcptn_xmpl ();              /* Configure and Enable Interrupts */

	/* Loop forever */
	for(;;) {	   
	   	counter++;
	   	memset(str,0,sizeof(str));

	}
}
