#include <stdio.h>
#include "autoconfig.h"
void test_driver4()
{
#ifdef CONFIG_TEST_ENABLE
    printf("4CONFIG_TEST_ENABLE\n");
#endif
	printf("4CONFIG_TEST_SHOW_STRING: %s\n", CONFIG_TEST_SHOW_STRING);
	printf("4CONFIG_TEST_SHOW_INT: %d\n", CONFIG_TEST_SHOW_INT);
#ifdef CONFIG_TEST_TOP_ENABLE
    printf("4CONFIG_TEST_TOP_ENABLE\n");
#endif
#ifdef CONFIG_TEST_SUB_0_ENABLE
    printf("4CONFIG_TEST_SUB_0_ENABLE\n");
#endif
#ifdef CONFIG_TEST_SUB_1_ENABLE
    printf("4CONFIG_TEST_SUB_1_ENABLE\n");
#endif
	printf("4CONFIG_TEST_SHOW_SUB_INT: %d\n", CONFIG_TEST_SHOW_SUB_INT);
}