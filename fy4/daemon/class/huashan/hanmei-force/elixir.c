// ����˪������elixir����Team Heal over time 
//	This stacks with remedy
//	The callout is always on HS player to avoid heal from other room (remedy style)

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount1)
{
	int level,i,j, skill, amount, ability, num;
	object *enemy, *mem, *team1, *team;
	
	if(me->query("class")!="huashan")
		return notify_fail("ֻ�л�ɽ���Ӳ����ô��ķ���\n");

	level=me->query_skill("hanmei-force",1);
	if (level < 200 || me->query_skill("cloud-dance",1) < 200) 
		return notify_fail("��Ҫ170���ĺ�÷�ķ��ͻ÷�Ʈ���衣\n");
		
	if (me->query_temp("pfm/hanmei_elixir"))
		return notify_fail("���Ѿ���ʹ�ø��ķ��ˡ�\n");
		
	skill = 250;
		
	if( me->query("force") < 400 )
		return notify_fail("��Ҫ400���������\n");
		
	message_vision(HIG "$N˫��ƽ����ǰ���������죬��͵������紺�ٴ�أ�ů�����ˡ�\n\n"NOR,me);
	
	if (userp(me)) {
		if (F_ABILITY->check_ability(me,"heal_add")> random(100))	
			tell_object(me,YEL"������Ϣ��ͨ�����������ʹ������һ�У�\n"NOR);
		else
			me->add("force", -400);
	}
	me->set_temp("pfm/hanmei_elixir", 1);
			
	//	amount = 250; 250*8 = 2000�� cost 400 force
	amount = skill;	
	amount = COMBAT_D->magic_modifier(me, me, "kee",amount);
		    
	team1 = me->query_team();
	if (!mapp(team1))	team1 = ({ me});
	team = filter_array(team1,(: present($1,environment($2)) :),me);
	num = sizeof(team);	
	for (i=0; i<num; i++) {
		target = team[i];
		if(target->is_fighting()) {
			enemy = target->query_enemy();
			for (j=0;j<sizeof(enemy);j++) {
				if (!enemy[j]->is_fighting(me)) {
					enemy[j]->kill_ob(me);
					me->kill_ob(enemy[j]);
				}
			}	
		}	
		call_out("fillup",8, me, 8,0, amount);        
	}
	
	me->perform_busy(1);
	return 1;

}

void fillup (object me, int total, int count, int amount)
{
	object *team1, *enemy, target, *team;
	int i, j, num;
	if (!me)	return;
	if (me->query_temp("pfm/hanmei_elixir")<1) {
		me->delete_temp("pfm/hanmei_elixir");
		tell_object(me,YEL"��˪���Ĺ�Ч��ʧ�ˡ�\n"NOR);
		return;
	}
			
	if(++count>total)
	{
		tell_object(me,YEL"��˪���Ĺ�Ч��ʧ�ˡ�\n"NOR);
		me->delete_temp("pfm/hanmei_elixir");
		return;
	}
	else {
		team1 = me->query_team();
		if (!(team1)|| sizeof(team1)<2)	team1 = ({ me});
		team = filter_array(team1,(: present($1,environment($2)) :),me);
		num = sizeof(team);
		for (i=0; i<num; i++) {
//			reset_eval_cost();	
			target = team[i];
			if(target->is_fighting()) {
				enemy = target->query_enemy();
				for (j=0;j<sizeof(enemy);j++) {
					if (!enemy[j]->is_fighting(me)) {
						enemy[j]->kill_ob(me);
						me->kill_ob(enemy[j]);
					}
				}	
			}	
			if (target->query("kee") < target->query("max_kee")) {
				target->receive_fulling("kee", amount,me);
			}
			tell_object(target,WHT"��͵�������������������������ϡ�\n"NOR);
		}
	}
	call_out("fillup",8,me,total,count, amount);
	return ;
}


