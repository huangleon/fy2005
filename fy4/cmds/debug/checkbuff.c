// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
        object ob;
        string id,act;
        if (!arg) 
        return notify_fail("ָ���ʽ: checkbuff <living> <buff>\n");

        if( sscanf(arg, "%s %s", id, act)!=2 )
        return notify_fail("ָ���ʽ: checkbuff <living> <buff>\n");

        ob = present(id, environment(me));
        if (!ob) return notify_fail("�Ҳ���������\n");

        write("Check buff "+arg+" = "+ANNIE_D->check_buff(ob,act)+"\n");

        return 1;
}
 

