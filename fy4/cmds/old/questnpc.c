// by suu for questnpc
#include <ansi.h>
int main(object me, string str)
{
        string output;
        me->add("sen",-5);
        output =  YEL"������������������������"NOR + RED"  ����2005Ѫ��ϭ  "NOR + YEL"��������������������������\n"NOR;
        output += YEL"������������������������"NOR + CYN"~~~~~~~~~~~~~~~~"NOR + YEL"��������������������������\n"NOR;
        output += QUESTNPC_D->dyn_evil_quest_list();
        output += YEL"������������������������������������������������������������������\n"NOR;
        output += YEL"������������������������������������������������������������������\n"NOR;
		output += YEL"������������������������"NOR + BLU"  ����2005������  "NOR + YEL"��������������������������\n"NOR;
        output += YEL"������������������������"NOR + CYN"~~~~~~~~~~~~~~~~"NOR + YEL"��������������������������\n"NOR;
        output += QUESTNPC_D->dyn_good_quest_list();
        output += YEL"������������������������������������������������������������������\n"NOR;
        output += YEL"������������������������������������������������������������������\n"NOR;

        me->start_more("", output, 0);
        return 1;
}

int help(object me)
{
        write(@HELP
ָ���ʽ: questnpc

���ָ����������֪Ŀǰ�����б����͵�NPC.

HELP
        );
        return 1;
}
