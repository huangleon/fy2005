#define SCORE_COST 5000
#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
    object who;
    if( !arg ) return notify_fail("ָ���ʽ : assign <id>\n");
    if(me->query("organization/privs") != -1) 
	return notify_fail("��û������Ȩ����\n");
    if(!objectp(who = present(arg, environment(me))) 
       || !living(who) || !userp(who) || me == who)
        return notify_fail("����û�������ҡ�\n");
    if(who->query("organization/org_name") != me->query("organization/org_name"))
	return notify_fail( who->query("name") + "������" + 
                            me->query("organization/org_name") + "��һ���ӡ�\n");
    if((int)me->query("organization/generation") >=
       (int)who->query("organization/generation"))
	return notify_fail(who->query("name") +
                           "�ı��ݱ������ͣ�\n");
    if((int)who->query("score") < SCORE_COST)
	return notify_fail( who->query("name") + "�����۲���"+
                            chinese_number(SCORE_COST)+"�㡣\n");
    who->set("organization/privs",-1);
	who->delete("organization/org_title");
    me->set("organization/privs",1);
    who->add("score",-SCORE_COST);
    message_vision("$N������֮λ����$n��\n",me,who);
    CHANNEL_D->do_sys_channel("info",sprintf(
        "%s(%s)����%s��������֮λ������%s(%s)��",me->query("name"),
        me->query("id"),me->query("organization/org_name"),who->query("name"),who->query("id")));
    return 1;
}
int help(object me)
{
    write(@HELP
ָ���ʽ : assign <id>
 
���ָ��������㴫��һ��֮���ĵ�λ����������
��Ȼ����λ�����Ҫ��һ��������������������
HELP
        );
    return 1;
}
