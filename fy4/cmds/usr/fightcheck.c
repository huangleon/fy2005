// smash.c 2-22-95
 
#include "/doc/help.h"
#include <ansi.h>
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	string arg2, para, list;
	
	if (!arg)	return notify_fail("fightcheck <-����> NPC��\n");
	para = "all";
	
	if (sscanf(arg,"-%s %s",para,arg2)==2){
		arg = arg2;
	}
			
	ob = present(arg, environment(me));
	if (!ob) return notify_fail("�����û�����NPC��\n");
	
	tell_object(me,WHT"NPC "+arg+" ״��������\n"NOR);
	
	write("======================================================\n");
	switch (para) {
		case "hate":		
					list = sprintf("�����б�%O\n",ob->query_hate_list());
					list += sprintf("ʵ�������б�%O\n", ob->query_hate_list2());
					list += sprintf(YEL"��ǰ��ս���е�����������%O\n"NOR,ob->query_max_hate());
					break;
		case "damage":	
					list = sprintf("�˺��б�%O\n", ob->query_damage_list());
					list += sprintf("�ۺ϶����˺��б�%O\n", ob->query_combined_damage_list());
					list += sprintf(YEL"��ǰ���ȶ��飺%O\n"NOR,ob->query_max_damage_dealer());
					break;
		case "all":		
					list = sprintf("�����б�%O\n", ob->query_hate_list());
					list += sprintf("ʵ�������б�%O\n", ob->query_hate_list2());
					list += sprintf(YEL"��ǰ��ս���е�����������%O\n"NOR,ob->query_max_hate());
					list += sprintf("�˺��б�%O\n", ob->query_damage_list());
					list += sprintf("�ۺ϶����˺��б�%O\n", ob->query_combined_damage_list());
					list += sprintf(YEL"��ǰ���ȶ��飺%O\n"NOR,ob->query_max_damage_dealer());
	}

	write(list);
	write("======================================================\n");
	return 1;
}
 
int help(object me)
{
   write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ :  fightcheck <-����> NPC
[0;1;37m����������������������������������������������������������������[0m   
   
���Լ��ָ����NPC��һϵ�����ˡ��������

������-hate	������ޣ�-damage ����˺�
[0;1;37m����������������������������������������������������������������[0m   
HELP
   );
   return 1;
}
