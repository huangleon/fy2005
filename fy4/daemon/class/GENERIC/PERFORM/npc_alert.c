#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
	object soldier, *enemy;
	string where;
	int strategy,leadership, exp, title, i;
	
	if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");
		
	if ((string)me->query("class") != "official")
	return notify_fail("�㲻�ǳ�͢���٣������Լ��չ��Լ��ɣ�\n");
	
	strategy = (int)me->query_skill("strategy",1);
	leadership = (int)me->query_skill("leadership",1);
	exp = (int)me->query("combat_exp");
	
        if( !me->is_fighting() )
        return notify_fail("����û����Ҫɱ�㣡\n");
	
	if( me->query_temp("guard_count") >1 )
                return notify_fail("�������ڵĹ�λ�����Ѿ��ܵ��㹻�ı�����\n");
	
	if (leadership+strategy>260 && random(100)<5)
		message_vision(HIB "\n$N����һ����Х��Ԯ������ʲ��Ҳû�з�����\n" NOR, me); 
	else {
		seteuid(getuid());
		if (me->query("family/master_id")!="master yue"){
			soldier= new("/obj/npc/shiwei");
			soldier->move(environment(me));
	        	soldier->set("title", "��͢һƷ��������");
	        	soldier->invocation(me, (leadership+strategy));
	        } else {
	        	soldier= new("/obj/npc/huwei");
			soldier->move(environment(me));
	        	soldier->invocation(me, (leadership+strategy));
        	}
        	if (soldier->query("combat_exp")>me->query("combat_exp"))
        		soldier->set("combat_exp",me->query("combat_exp")*4/5);
        	enemy = me->query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
				soldier->kill_ob(enemy[i]);
				if( userp(enemy[i]) ) enemy[i]->fight_ob(soldier);
				else enemy[i]->kill_ob(soldier);
			}
		}
        	soldier->set("possessed", me);
        	soldier->set_leader(me);       	 	
        	me->add_temp("guard_count",1);
        	message_vision(HIB "\n$N����һ����Х��Ԯ��\n" NOR, me);   
		message_vision(HIB "\n$NӦ��������\n" NOR, soldier);
	}

	return 1;
}
