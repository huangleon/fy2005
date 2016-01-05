#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	int lvl;

	if( me!=this_player(1) ) return 0;
	if( wiz_level(me) < wiz_level("(arch)") )
		return notify_fail("�����ʦ�ȼ�̫�ͣ�û��ʹ�����ָ���Ȩ����\n");
	
	if( !arg || arg=="" ) {
		return notify_fail("��ǰQuest�Ķ��⽱��Ϊ��"+ QUESTS_D->query_holiday()+" \n");	
	}
	
	if( sscanf(arg, "%d", lvl)!=1 ) 
		return notify_fail("�μ�HELP��ʽ˵����\n");
		
	seteuid(getuid());
	
	if (lvl>=0 && lvl<=900) {
		QUESTS_D->set_holiday(lvl);
		write(HIR"\n��ǰÿ��Quest�Ľ���Ϊԭ����"+ (lvl+100)+"%����Ч�ڳ�����ϵͳ�������ٴ����á�\n"NOR);
		CHANNEL_D->do_sys_channel("info","���ʹ����Quest���ľ���/����������������Ϊ "+(lvl+100)+"������Ҽ��Ͱ���");
		log_file("QBONUS_UPDATE_LOG", 
					sprintf("(%s)%s �Ķ�QUEST������%d��\n",
   					ctime(time()), 
   					me->name(1)+"("+ me->query("id")+")", 
					lvl,
				));
		return 1;
	}
		
	return notify_fail("��ֻ������0-900֮������֡�\n");
}

int help (object me)
{
        write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	holiday_bonus <����>[0m
[0;1;37m����������������������������������������������������������������[0m   

�������Ǹ�������ʦ��̬�ı���Ϸ��Quest�Ľ�����0-900��

���� = ��������*��100+bonus��/100

�������޸ĵı������bonus��ֵ������˵bonus = 100�൱�ڼӱ�����

ÿ������������BONUS�Զ��ָ�Ϊ0

������Ӱ��Quest���õľ���ֵ���Լ�Quest���õ�ABILITYֵ��
������Ӱ�����е���/adm/daemons/questd��give_reward�����Ľ���
�������TASKû��Ӱ��

[0;1;37m����������������������������������������������������������������[0m  
HELP
);
        return 1;
}
 
