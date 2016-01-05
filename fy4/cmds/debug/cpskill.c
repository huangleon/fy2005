// File : /cmds/arch/cpstat.c
// annie 07.04.2003 dancing_faery@hotmail.com

#include <dbase.h>
#include <ansi.h>

inherit F_DBASE;
inherit F_ANNIE;

int help(object me);

int main(object me, string arg)
{
	string tmp1,tmp2;
    	object ob, ob1;


	seteuid(geteuid(me));

	if (!arg)
		return notify_fail ("\n[USAGE]\n����cpskill <source> <destination>\n");
    
    	sscanf (arg, "%s %s", tmp1,tmp2);

	if (!tmp1 || !tmp2)
		return notify_fail ("\n[USAGE]\n����cpskill <source> <destination>\n");
	
    	ob=present(tmp1, environment(me));
    	ob1=present(tmp2, environment(me));

	if (!ob || !ob1)
		return notify_fail ("\n[USAGE]\n����cpskill <source> <destination>\n");

	if (!ob->is_character())
		if (!ob1->is_character())
			return notify_fail ("Cpstat����ָ��ĸ���Դ��Ŀ��Դ���������");
	
	tell_object(me,annie_skillcp(ob,ob1));
    	return 1;
}


int help(object me)
{
    write( @HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : cpskill ][0m
[0;1;37m����������������������������������������������������������������[0m

ָ��˵��: ��ָ���������ƶ������ϵ����м���

[0;1;37m����������������������������������������������������������������[0m
HELP
        );
    return 1;
}