// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("ָ���ʽ: exec <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("�Ҳ��������ҡ�\n");
	message_vision("$N˫��һ�٣�һ�����׽�$n��Ϊ�ɻң���\n",me,ob);
	ob -> save();
        BAN_D->dynamic_add(query_ip_number(ob));
	seteuid(ROOT_UID);
	destruct(ob);
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	exec <���>[0m
[0;1;37m����������������������������������������������������������������[0m   

��ĳ������߳����Ʋ�����IP��ʱBAN��
����������REBOOT�����IP�ſ���������

���ָ�� ban, nuke

[0;1;37m����������������������������������������������������������������[0m 
HELP
   );
   return 1;
}
