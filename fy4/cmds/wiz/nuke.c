// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("ָ���ʽ: nuke <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("�Ҳ��������ҡ�\n");
	message_vision("$N˫��һ�٣�һ�����׽�$n��Ϊ�ɻң���\n",me,ob);
	ob->set("kickout_time",time());
	ob -> save();
	seteuid(ROOT_UID);
	destruct(ob);
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	nuke <���>[0m
[0;1;37m����������������������������������������������������������������[0m   
   
��ĳ������߳����ƣ�����ʹ����һ��Сʱ�ڲ��������ߡ�

�������	ban, imprison

[0;1;37m����������������������������������������������������������������[0m   
HELP
   );
   return 1;
}
