// smash.c 2-22-95
 
#include "/doc/help.h"

inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	if (!arg) return notify_fail("ָ���ʽ: smash <living>\n");
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("�Ҳ���������\n");
	if (userp(ob))
		return notify_fail("�㲻�ܶ����ʹ�ô������ο�˵����\n");
	
	message_vision("$N��һ�ӣ�һ����������������$n��Ϊ촷ۣ���\n",me,ob);
	
	ob ->set_temp("last_damage_from", me);
	ob -> die();
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	smash <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

����������ڷ���ҵ����
����Ҵ���������ɲμ� nuke, exec, imprison, ban

���������ʦ��Ϊ����˺������ߣ����������⣬��ο�dest���

[0;1;37m����������������������������������������������������������������[0m   

HELP
   );
   return 1;
}
