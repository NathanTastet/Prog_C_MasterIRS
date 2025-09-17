#include "tp_checklist.h"
#include "serieb-macro.h"

bool exb01(void *);
bool exb02(void *);
bool exb03(void *);
bool exb04(void *);
bool exb05(void *);
bool exb06(void *);
bool exb07(void *);
bool exb08(void *);
bool exb09(void *);
bool exb10(void *);
bool exb11(void *);
bool exb12(void *);
bool exb13(void *);
bool exb14(void *);
bool exb15(void *);
bool exb16(void *);
bool exb17(void *);
bool exb18(void *);
bool exb19(void *);
bool exb20(void *);

struct tpc_t tests[] = {
    {"exb01 try1", exb01, &exb01_1}, {"exb01 try2", exb01, &exb01_2},
    {"exb02 try1", exb02, &exb02_1}, {"exb02 try2", exb02, &exb02_2},
    {"exb02 try3", exb02, &exb02_3}, {"exb02 try4", exb02, &exb02_4},
    {"exb03 try1", exb03, &exb03_1}, {"exb03 try2", exb03, &exb03_2},
    {"exb03 try3", exb03, &exb03_3}, {"exb03 try4", exb03, &exb03_4},
    {"exb04 try1", exb04, &exb04_1}, {"exb04 try2", exb04, &exb04_2},
    {"exb04 try3", exb04, &exb04_3}, {"exb04 try4", exb04, &exb04_4},
    {"exb05 try1", exb05, &exb05_1}, {"exb05 try2", exb05, &exb05_2},
    {"exb05 try3", exb05, &exb05_3}, {"exb05 try4", exb05, &exb05_4},
    {"exb06 try1", exb06, &exb06_1}, {"exb06 try2", exb06, &exb06_2},
    {"exb07 try1", exb07, &exb07_1}, {"exb07 try2", exb07, &exb07_2},
    {"exb07 try3", exb07, &exb07_3}, {"exb07 try4", exb07, &exb07_4},
    {"exb08 try1", exb08, &exb08_1}, {"exb08 try2", exb08, &exb08_2},
    {"exb09 try1", exb09, &exb09_1}, {"exb09 try2", exb09, &exb09_2},
    {"exb10 try1", exb10, &exb10_1}, {"exb10 try2", exb10, &exb10_2},
    {"exb11 try1", exb11, &exb11_1}, {"exb11 try2", exb11, &exb11_2},
    {"exb12 try1", exb12, &exb12_1}, {"exb12 try2", exb12, &exb12_2},
    {"exb13 try1", exb13, &exb13_1}, {"exb13 try2", exb13, &exb13_2},
    {"exb13 try3", exb13, &exb13_3}, {"exb13 try4", exb13, &exb13_4},
    {"exb15 try1", exb15, &exb15_1}, {"exb15 try2", exb15, &exb15_2},
    {"exb15 try3", exb15, &exb15_3},
    {"exb16 try1", exb16, &exb16_1}, {"exb16 try2", exb16, &exb16_2},
    {"exb16 try3", exb16, &exb16_3},
    {"exb17 try1", exb17, &exb17_1}, {"exb17 try2", exb17, &exb17_2},
    {"exb17 try3", exb17, &exb17_3}, {"exb17 try4", exb17, &exb17_4},
    {"exb18 try1", exb18, &exb18_1}, {"exb18 try2", exb18, &exb18_2},
    {"exb18 try3", exb18, &exb18_3},
    {"exb19 try1", exb19, &exb19_1}, {"exb19 try2", exb19, &exb19_2},
    {"exb19 try3", exb19, &exb19_3}, {"exb19 try4", exb19, &exb19_4},
    {"exb20 try1", exb20, &exb20_1}, {"exb20 try2", exb20, &exb20_2},
    {"exb20 try3", exb20, &exb20_3}, {"exb20 try4", exb20, &exb20_4},
};