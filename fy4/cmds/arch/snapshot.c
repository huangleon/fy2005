
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("ָ���ʽ: snapshot <living>\n");
	ob = find_player(arg);
	if (!ob) return notify_fail("�Ҳ���������\n");
	if (!userp(ob))
		return notify_fail("�㲻�ܶԷ����ʹ�ô������ο�˵����\n");
	"/feature/nada.c"->snapshot(ob);	
	write("Ok.\n");
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	snapshot <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

���������ҵ�������һ�������ࡱ�����Ǽ��ڰ���
��д����ķ���Դ��

[0;1;37m����������������������������������������������������������������[0m   

HELP
   );
   return 1;
}
