// death_recover.c	��Ϊ��ʦר��ָ������ָ������BUG����ɵ�������ʧ��
//		-- silencer@fy4

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object player;
	mapping death;
	string *lost_skill;
	int player_level, i;
	
	if( me!=this_player(1) ) return 0;
		
	if( !arg)
		return notify_fail("ָ���ʽ��death_recover <ʹ����>\n");

	player = find_player(arg);
	if (!player || !objectp(player))
		return notify_fail("��ǰû��"+arg+"�����ҡ�\n");
		
	death = player->query("death");
	if (!death || !sizeof(death))
		return notify_fail("����û��������¼���޷��ô�����ָ���\n");

	write(sprintf("��ҵ�������¼Ϊ%O\n",death));
		
	/*message_vision(HIW"$N�����еķ���һ�ӣ�һ����͵Ĺ�â���������ע��$n���ڡ�\n\n"NOR,me,player); */
	
	tell_object(me,player->query("id")+"�ϴ�����ʱ��Ϊ"+ctime(death["time"])+"��\n");
	tell_object(player,"�ϴ�����ʱ��Ϊ"+ctime(death["time"])+"��\n");
	player->add("combat_exp",death["exp_lost"]);
		tell_object(player,"����ʧ�ľ���ֵȫ���ָ��ˣ�������Իָ�������\n");
	player->delete("attr_apply");	// if they have more from previous death... well, lucky them.		
	
	/*log_file("BUG_RECOVER", sprintf(
		"%s �� %s �� %s �ָ�һ��������ʧ��(exp %d, pot %d)\n",
			me->query("id"), ctime(time()), player->query("id"),
			death["exp_lost"], death["pot_lost"]));*/
	
	player->delete("death");
						
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37m����������������������������������������������������������������[0m
[0;1;36m��ʦָ���ʽ : 	death_recover <ĳ��>[0m
[0;1;37m����������������������������������������������������������������[0m   

���������������ʧֵ����ҵ������ж��м�¼��
���������ṩ����ʦ�ָ������ϵͳBUG��ɵĲ�����������

[0;1;37m����������������������������������������������������������������[0m 
HELP
    );
    return 1;
}
