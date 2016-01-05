// rm.c

#include "/doc/help.h"

inherit F_CLEAN_UP;
int help(object me);

int main(object me, string file)
{
	seteuid(geteuid(me));
    if (!file) return notify_fail("��Ҫɾ���Ǹ�����?\n");
	if( rm(resolve_path(me->query("cwd"), file)) )
		write("Ok.\n");
	else
		write("��û��ɾ�����������Ȩ����\n");
	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	rm <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

��ָ�������ɾ����Ȩ�޸ĵĵ�����

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
