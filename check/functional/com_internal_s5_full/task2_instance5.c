/*Instance 5 of task t2*/

#include "embUnit.h"
#include "tpl_os.h"

DeclareMessage(rm_always);

/*test case:test the reaction of the system called with 
 an activation of a task*/
static void test_t2_instance5(void)
{
	StatusType result_inst_1, result_inst_2;
	StatusType received_char;
	
	SCHEDULING_CHECK_INIT(24);
	result_inst_1 = ReceiveMessage(rm_always, &received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT_FIRST(24,1, (int)received_char);
	SCHEDULING_CHECK_AND_EQUAL_INT(24,E_OK, result_inst_1);
		
	SCHEDULING_CHECK_INIT(25);
	result_inst_2 = TerminateTask();
	SCHEDULING_CHECK_AND_EQUAL_INT(25,E_OK, result_inst_2);
}

/*create the test suite with all the test cases*/
TestRef COMInternalTest_seq5_t2_instance5(void)
{
	EMB_UNIT_TESTFIXTURES(fixtures) {
		new_TestFixture("test_t2_instance5",test_t2_instance5)
	};
	EMB_UNIT_TESTCALLER(COMInternalTest,"COMInternalTest_sequence5",NULL,NULL,fixtures);
	
	return (TestRef)&COMInternalTest;
}