// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int skill, num, i, duration, mod, add;
	string msg, name;
	object *env, *huwei, weapon;
	string *poem = ({"�������ָڻ�ս�������ƿ���һϪ����"HIY"��ת��һ����",
"������ˮմ�̴��������빬ͥ�����ܡ�"HIY"����ת��һ����",
"���Ϸ�ֻ���С�󣬱�ԯ���շ����ݡ�"HIY"����ת��һ����",
"���Ľ��߳߳���ʥ��ŭָ�����᲻�ա�"HIY"��ת��һ����",
"������ͷ����ʰ��ɽ�ӡ�"HIY"��ǰת��һ����",
"�������ڣ���"HIY"���ת��һ����"
	});

	
	if (userp(me))
        if (me->query("family/master_id")!="master yue" 
        	|| me->query("class")!="official")
        	return notify_fail("ֻ�����ɵĵ��Ӳ���ʹ�á��廢����ꇡ���\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 180 || me->query_skill("leadership",1)< 180)
		return notify_fail("���廢����ꇡ���Ҫ180��������180������֮����\n");        		
	  
	    add = F_ABILITY->check_ability(me,"3_array_add",3)*4/10;     
    duration = me->query("timer/pfm/yue_array")-time() + 10 -add ;
	if (duration>0)
        	return notify_fail("����Ҫ�ȴ�Ƭ�̣�"+ duration +"�룩�����ٴα���󷨡�\n");
        
    if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���廢����ꇡ�ֻ����ս����ʹ�á�\n");
		
    if (me->query_temp("guard_count")<2)
        	return notify_fail("��Ļ���̫�٣��в�����Ү��\n");
        
    env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
		&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi"  :), me);
	if (!sizeof(huwei))
		return notify_fail("��Ļ�������������޷��������廢����ꇡ�\n");
	
	msg = "\n"BGRN + HIY"$N"BGRN + HIY"�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"�廢����֮��"NOR HIR" 	

$N"HIR"�����ȵ����������ùᶷţ���Ľ�ֱ�ڱ�����ն����񻹳��ݣ����ʵ�̳�򻧺
����δ�䣬����ڽ�����Ӧ�ͣ�����������\n"NOR;
  	message_vision(msg, me);
  	me->set("timer/pfm/yue_array",time());
  	
  	for (i=0;i<sizeof(huwei);i++) {
  		if (huwei[i]->query_temp("is_unconcious") 
  			|| !huwei[i]->is_fighting(target)
  			|| huwei[i]->is_busy())	continue;
  			msg = HIW+poem[i]+ "������ǰֱȡ$n��"HIY"����" + huwei[i]->name()+"��\n"NOR;
  		if (huwei[i]->query("skill")== "spear" || huwei[i]->query("skill")=="hammer") {
  			huwei[i]->add_temp("apply/attack", skill*2);
  			huwei[i]->add_temp("apply/damage", skill);

  			COMBAT_D->do_attack(huwei[i],target, TYPE_PERFORM,msg);

  			huwei[i]->add_temp("apply/attack", -skill*2);
  			huwei[i]->add_temp("apply/damage", -skill);
  			
  			huwei[i]->perform_busy(1);
		}
  	}

	me->perform_busy(1);	
    return 1;
}
