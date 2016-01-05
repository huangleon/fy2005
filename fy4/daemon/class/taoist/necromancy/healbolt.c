// healbolt.c

#include <ansi.h>
inherit SSERVER;

int cast(object me, object target)
{
	string msg;
	int amount, cost, lvl, i, j, num, duration;
	object *enemy, *team1, team;
	int ann;

	if( me->query("class") != "taoist" ) {
		return notify_fail("ֻ�����幬�ĵ��Ӳ��ܹ�ʹ�����������\n");
	}
	lvl = me->query_skill("necromancy",1);
	if( lvl < 80 ) {
		return notify_fail("������֮������Ҫ80�������������\n");
	}
	if( me->query_skill_mapped("force") != "gouyee" ) {
		return notify_fail("���������ʹ�ù����ķ�����ת���š�\n");
	}
	team = me->query_team();
	if( !sizeof(team) ) {
		return notify_fail("������֮����ֻ���ڶ�����ʹ�á�\n");
	}
	duration = me->query("timer/pfm/sq_heal") - time() + 10;
	if( duration > 0 ) {
		return notify_fail("�㾫���ѽߣ���ȴ�"+ duration +"����ܹ��ٴ�ʹ�á�����֮������\n");
	}
	team1 = filter_array(team, (: present($1,environment($2)) :), me);
	num = sizeof(team1);
	if( num < 2 ) {
		return notify_fail("�����û�ж��ѣ������в��ǳ������ֺ�ô��\n");
	}
	if( lvl <= 120 ) {
		ann = 5;
	} else {
		ann = 10;
	}
	// self -800 ~ 2000kee, everyone else + 800~2000 kee;
	amount = lvl * ann;
	if( me->query("kee") < amount) {
		return notify_fail("�����Ѫ����ʩ�˷�����\n");
	}
	if( me->query("mana") < 300 ) {
		return notify_fail("������֮����������Ҫ300������\n");
	}
	if( userp(me) ) {
		me->add("mana", -300);
	}
	msg = BBLU + HIW "
$N�����૵��������ģ�����һ�ӣ�һ�������İ������������ڿ���������\n\n" NOR;				
	message_vision(msg, me);
	me->set("timer/pfm/sq_heal", time());
	me->set_temp("last_damage_from","ʹ�ð���֮������������\n");
	me->receive_damage("kee", amount);
	for( i = 0; i < num; i++ ) {
		if( !COMBAT_D->legitimate_buff(me, team1[i]) ) {
			continue;
		}
		if( team1[i] == me) {
			continue;
		}
		if( team1[i]->query("kee") < team1[i]->query("max_kee") ) {
			team1[i]->receive_fulling("kee", amount, me);
			tell_object(team1[i], WHT"��������漣��ؿ�ʼ���ϡ�\n"NOR);
			if( team1[i]->is_fighting() ) {
				enemy = team1[i]->query_enemy();
				for( j = 0;j < sizeof(enemy); j++) {
					if( !enemy[j]->is_fighting(me) ) {
						enemy[j]->kill_ob(me);
						me->kill_ob(enemy[j]);
					}
				}
			}
		}
	}
	me->perform_busy(2);
	return 1;
}




/*

������     /��              ��\      
������   ��   �ܣߣߡ�������  ��       
������   �� ����    ���������v��       
������    �M                  ��       
������    ��   /��\    /��\   ��      
������    ��   ����    ��  �� ��       
������   ��    \ /    \��/    ��      
������    ����      ��      ���M         
������    ���v��    ��   ������         
������    �q������������������           
������   ��   ��           /���\����    
������  ��____��  �� ��  �� .. ����     
������        \���/ ����ܡ�         
                       ��             
����������������- FengYun - ������
 ��������������annie 06.2005
 ��������dancing_faery@hotmail.com

*/
