// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("ָ���ʽ: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("�Ҳ���������\n");
	message_vision("$N��һ�ӣ�$nӦ��ˤ���ڵ��ϣ���\n",me,ob);
	ob -> unconcious();
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	uncon <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

ʹ������Բ��ѡ�

[0;1;37m����������������������������������������������������������������[0m   

HELP
   );
   return 1;
}
