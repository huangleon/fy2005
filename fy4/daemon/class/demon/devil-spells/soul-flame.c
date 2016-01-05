// void_sense.c

#include <ansi.h>

inherit SSERVER;
int soul_flame(object me, object obj, int lvl, int counter);
int cast(object me, object target)
{
	int lvl,i, number;
	object env, *inv;
	if(me->query("class")!="npc" && userp(me))
		return notify_fail("ֻ��ӫ����ʿ�ſ���ʹ����ڤħ�䣡\n");
		
        if((int) me->query_skill("devil-spells",1) < 200)
                return notify_fail("�����ڤħ�䲻�����\n");
        if(! me->is_fighting() )
                return notify_fail("��ħ�������ֻ����ս����ʹ�ã�\n");

        if( me->query_temp("marks/soul_flame") )
        	return notify_fail("������ʹ��ħ�����꣡\n");
   	lvl = (int) me->query_skill("spells");
	if( me->query("mana") < 110 )
		return notify_fail("��ķ���������\n");
        if( me->query("sen") <= 60 )
                return notify_fail("����񲻹���\n");

	me->add("mana", -100);
	me->receive_damage("sen", 50);
	message_vision(NOR CYN"$N��ɫ������������������������������־�����ǰ������������״�� \n" NOR, me);

	message_vision(HIB"�������ĵ�����·��ܵ��ٻ��ӵ������ڶ��� \n$N��Χ��ʱ����˿ֲ����˼������� \n"NOR, me);
        me->set_temp("marks/soul_flame", 1);
        if(target)
        	soul_flame(me, target, lvl, lvl/150);
        else
        {
        	env = environment(me);
        	inv = all_inventory(env);
        	for(i=0; i<sizeof(inv); i++) {
                	if( inv[i]==me ) continue;
                	if( inv[i]->is_corpse() ) continue;
			if( !inv[i]->is_character()) continue;
                	if( !inv[i]->is_fighting(me)) continue;              	
                	number++;
                	soul_flame(me, inv[i], lvl/number, lvl/100);
                	
        	}
        }
        
        if (userp(me)) me->start_busy(3) ;
        	else  me->start_busy(1);
        return 1;

}

int soul_flame(object me, object obj, int lvl, int counter)
{
        int ratio,c;
        if (counter<1) {
        	me->delete_temp("marks/soul_flame");
        	return 0;
        }
        
        if ( !objectp(obj) || ! obj->is_fighting() ){
        	me->delete_temp("marks/soul_flame");
        	return 0;
        }
        
        
        message_vision(NOR BLU "\n�䶯�������$N���������ζ�����\n"NOR, obj);
        
        if(obj->is_zombie()==1) {
                message_vision(RED "$N����һ�󽹳�ζ������ʱ���ɺںڵ�ľ̿��\n" NOR, obj);
                obj->die();
                return 1;
        }
//		message_vision("a"+lvl*((int) me->query("combat_exp")/2 + random((int) me->query("combat_exp")) ),me);
	// ratio =  lvl*((int) me->query("combat_exp")/2 + random((int) me->query("combat_exp")) )/ (10 + (int) obj->query("combat_exp"))/260;
	// overflow...bite neon

	c=(me->query("combat_exp")/2 + random(me->query("combat_exp")))/260*lvl;
	ratio =  c / (1 + random(obj->query("combat_exp")));

        if (ratio )  {
        	obj->set_temp("last_damage_from", me);
/*        	obj->receive_wound("gin",3*lvl/5+1, me);
			obj->receive_wound("kee",lvl +  50, me);
			obj->receive_wound("sen",4*lvl/7+1, me);*/
        	obj->receive_wound("gin",3*lvl/2+1, me);
			obj->receive_wound("kee",lvl*2 +  50, me);
			obj->receive_wound("sen",4*lvl/3+1, me);
        	message_vision(HIC "\nһ�����䶯�����������߰������$N��\n"NOR, obj);
        	COMBAT_D->report_status(obj);                                        
        } 
        else {
        	message_vision(HIY "\n$N����Ծ�������˶��߰�Ļ��档\n"NOR, obj);
        }
        counter--;
        call_out("soul_flame", 2+random(2), me, obj ,lvl*2/3, counter);
        return 1;
}
