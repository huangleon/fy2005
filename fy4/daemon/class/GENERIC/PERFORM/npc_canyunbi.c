// sillencer@fy4.com

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object *ob;
    	int i, skill, bonus,enhance,num;
    	string msg;

    	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");  
    	
    	if(me->query("class")!="knight")
    		return notify_fail("ֻ�п���ֵ��Ӳ��ܹ�ʹ��"+HIG"��������ϲ��Ʊ̡�"NOR+"��\n");

	if (me->query_skill("dream-herb",1)<100)
		return notify_fail("��������廨�����������졣\n");
		
	if(!me->is_fighting() ) {
        	tell_object(me,"��������ϲ��Ʊ̡�ֻ����ս����ʹ�á�\n");
		return 1;
	}

    	if (target) {
    		tell_object(me,"��������ϲ��Ʊ̡�����Ҫָ��Ŀ�ꡣ\n");
    		return 1;
    	}

//	500 + 150
    	skill = me->query_skill("herb");
	skill = skill + F_LEVEL->get_level(me->query("combat_exp"))*3;
	bonus = me->query_skill("dream-herb",1);
	
	msg =  HIG "$N������ת����ɫͻȻ��ñ�����������\n\n" NOR;
	message_vision(msg,me);

    	me->start_busy(3);

    	msg = HIG "$N"HIG"��һҧ��⣬ʹ�������廨�������������ġ�������ϲ��Ʊ̡����� \n��Ѫ�������Ũ��һ�㣬����׷����䡣\n\n" NOR;
	message_vision(msg,me);
	
	me->add_temp("apply/herb",bonus);
	ob = all_inventory(environment(me));
    	for(i=0; i<sizeof(ob); i++)   {
        	if (!living(ob[i]) || ob[i]==me ) continue;
		if (!ob[i]->is_fighting(me)) continue;
		if (ob[i]->query_temp("dot/dream-herb")) continue;
		if (!COMBAT_D->legitimate_kill(me, ob[i])) continue;
		enhance = skill/50;
		if (COMBAT_D->do_magic_attack(me, ob[i], "herb", "kee", enhance))
		{
			msg =  HIR "�廨����������Ϣ������$n�����ڣ�����\n" NOR;
			message_vision(msg,me,ob[i]);
			message_vision(YEL"$Nֻ����ǰ"+HIG"��"+HIG"��"+HIM"��"+HIY"�"NOR+YEL"���ƺ�������ֻС���ڷ��衣\n"NOR,ob[i]);
			num = skill/2 + random(skill/2);
			// 250 + random(250)--> 475 + random(475)
			// -- 2900 + random(2900) in 48 sec
			num = COMBAT_D->magic_modifier(ob[i],me,"kee",num);
			ob[i]->receive_wound("kee",num,me);
			ob[i]->set_temp("dot/dream-herb",1);
			call_out("dot",6,me,ob[i],8,0,num);
    		} else
    			tell_object(me,HIW"����廨����"+ob[i]->name()+"�����ˣ���\n"NOR);
    	}
    	me->add_temp("apply/herb",-bonus);
    	return 1;

}


void dot (object me, object enemy, int total, int count, int amount)
{
	int num;
	if (!enemy || !enemy->is_fighting(me)) {
		if (enemy) {
			message_vision(WHT"$N����ɫ�����ָ�����������\n"NOR,enemy);
			enemy->delete_temp("dot/dream-herb");
		}
		return;
	}
	message_vision(YEL"$Nֻ����ǰ"+HIG"��"+HIG"��"+HIM"��"+HIY"�"NOR+YEL"���ƺ�������ֻС���ڷ��衣\n"NOR,enemy);
	num = COMBAT_D->magic_modifier(enemy,me,"kee",amount);
	enemy->receive_wound("kee",num,me);
	enemy->set_temp("dot/dream-herb",1);
	count = count+1;
	if (count<total) call_out("dot",6,me, enemy,total,count, amount);
		else {
			message_vision(WHT"$N����ɫ�����ָ�����������\n"NOR,enemy);
			if (enemy) enemy->delete_temp("dot/dream-herb");
			return;
	}
	return ;
}
