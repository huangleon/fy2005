#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *ob;
   	int i, skill, my_exp,his_exp, bonus, damage;
	
	if( !me->is_fighting() )
        	return notify_fail("����Ϣ��ֻ����ս����ʹ�á�\n");

	// 180 + 200 + 100 = 480;
   	skill = me->query_skill("divineforce",1)*2;
	
	bonus = (me->query("combat_exp")-2000000)/5000 * skill/1000;
	if (bonus>skill) bonus= skill;
	if (bonus>0) skill= skill+bonus;
			
	me->perform_busy(2);
	message_vision(HIB "$N���������������ͻȻ�³�һ������ɫ�Ķ���\n" NOR, me);
	
	my_exp=me->query("combat_exp");
	
	ob = all_inventory(environment(me));
    	for(i=0; i<sizeof(ob); i++)   {
        	if (!living(ob[i]) || ob[i]==me ) continue;
		if (!ob[i]->is_fighting(me)) continue;
		if (ob[i]->query_temp("divineforce/dot")) continue;
		his_exp=ob[i]->query("combat_exp");
		if (my_exp/2+ random(my_exp/80 * skill)>his_exp) {
			message_vision(HIC"$N"+HIC"�����ȷ����棬һ��θ���������˳�����\n"NOR,ob[i]);	

			ob[i]->set("force",ob[i]->query("force")/2);
			ob[i]->set("mana",ob[i]->query("mana")/2);
			ob[i]->set("atman",ob[i]->query("atman")/2);

			call_out("dot",6, me,ob[i],20,0, skill*2);  
			ob[i]->set_temp("divineforce/dot",1);
    		}
    	}
    	return 1;
}

void dot (object me, object enemy, int total, int count, int amount)
{
	int num;
	if (!objectp(enemy))	return;
	if (!enemy->is_fighting(me)) {
		message_vision(WHT"$N����һ����������Χ�ĸ��ó�����������ɢȥ�ˡ�\n"NOR,enemy);
		enemy->delete_temp("divineforce/dot");
		return;
	}

	message_vision(MAG"$N"+MAG"�������ͨ�죬����������ת��ҡҡ��׹��\n"NOR,enemy);

	enemy->set("force",enemy->query("force")*2/3);
	enemy->set("mana",enemy->query("mana")*2/3);
	enemy->set("atman",enemy->query("atman")*2/3);

	enemy->set_temp("divineforce/dot",1);
	count= count + 1;
	if (count<total) call_out("dot",6,me, enemy,total,count, amount);
		else {
			message_vision(WHT"$N����һ����������Χ�ĸ��ó�����������ɢȥ�ˡ�\n"NOR,enemy);
			enemy->delete_temp("divineforce/dot");
		}
	return ;
}


