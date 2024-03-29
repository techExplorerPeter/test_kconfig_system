#include <stdio.h>
#include "autoconfig.h"
#ifdef CONFIG_DRIVER_TEST_GEN
#include "driver_test.h"
#include "driver_test1.h"
#include "driver_test2.h"
#endif
int main()
{
    printf("hello, test1\n");
#ifdef CONFIG_DRIVER_TEST_GEN    
	test_driver();
    test_driver1();
    test_driver2();
    test_driver3();
    test_driver4();
#endif
    return 0;
}