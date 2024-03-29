#include <stdio.h>
#include "autoconfig.h"
void test_driver3()
{
#ifdef CONFIG_TEST_ENABLE
    printf("3CONFIG_TEST_ENABLE\n");
#endif
	printf("3CONFIG_TEST_SHOW_STRING: %s\n", CONFIG_TEST_SHOW_STRING);
	printf("3CONFIG_TEST_SHOW_INT: %d\n", CONFIG_TEST_SHOW_INT);
#ifdef CONFIG_TEST_TOP_ENABLE
    printf("3CONFIG_TEST_TOP_ENABLE\n");
#endif
#ifdef CONFIG_TEST_SUB_0_ENABLE
    printf("3CONFIG_TEST_SUB_0_ENABLE\n");
#endif
#ifdef CONFIG_TEST_SUB_1_ENABLE
    printf("3CONFIG_TEST_SUB_1_ENABLE\n");
#endif
	printf("3CONFIG_TEST_SHOW_SUB_INT: %d\n", CONFIG_TEST_SHOW_SUB_INT);
}