// edit.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
	if( !file ) return notify_fail("ָ���ʽ��edit <����>\n");

	if( in_edit(me) ) return notify_fail("���Ѿ���ʹ�ñ༭���ˡ�\n");

	seteuid(geteuid(me));
	ed(resolve_path(me->query("cwd"), file));
	return 1;
}

int help(object me)
{
  write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	edit <����>, edit here[0m
[0;1;37m����������������������������������������������������������������[0m   

ָ���ʽ : edit <����>, edit here

���ô�һָ���ֱ�������ϱ༭������
[0;1;37m����������������������������������������������������������������[0m   
HELP
    );
    return 1;
}
