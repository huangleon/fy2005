#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int exert(object me, object target, int amount)
{
    int skill, num, i, duration, mod;
	string msg, name;
	object *env, *huwei, *huwei1;
	
	if (userp(me))
    if (me->query("class")!="official")
        return notify_fail("ֻ�й�Ա����ʹ�á���������\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 50 || me->query_skill("leadership",1)< 50
		|| me->query_skill("manjianghong",1)<50 )
		return notify_fail("����������Ҫ50������������֮�����������ķ���\n");        		
	       
    duration = me->query("timer/pfm/gf_motivate")-time() + 10;
	if (duration>0)
        	return notify_fail("����Ҫ�ȴ�Ƭ�̣�"+ duration +"�룩�����ٴ�ʹ�ü�����\n");
    
    if (me->query_temp("guard_count")<1)
        return notify_fail("��û���������ò������С�\n");
        
    if (!me->is_fighting())
		return notify_fail("���ؼ�ֻ����ս����ʹ�á�\n");
	
    env = all_inventory(environment(me));
	huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2
			&& $1->query("id")!="bodyguard" && $1->query("id")!="sishi" :), me);
	if (!sizeof(huwei))
		return notify_fail("��Ļ������������\n");
	
	huwei1 = filter_array(huwei, (: !$1->query_temp("is_unconcious") 
					&& $1->is_fighting() && !$1->is_busy() :), me);
	if (!sizeof(huwei1))
		return notify_fail("��Ļ������Թ˲�Ͼ�ء�\n");					
		
	if (me->query("family/master_id")=="master yin")
		msg = HIY "$N"HIY"������������ɱ����������ǧ���������Ǹ����ϰ�������\n"NOR;
	else
		msg = HIY"$N"HIY"����������������ƥ�����𣬾��ұ����������޺�������\n"NOR;
		
	message_vision(msg, me);
  	
  	me->set("timer/pfm/gf_motivate",time());
  	
  	if (!random(4) && me->query("family/master_id")=="master yin"){
  		message_vision(BLU"�������㿴���ң��ҿ����㣬һ��û�ԡ�\n"NOR, me);
  		return 1;
  	}
  		
  	i = random(sizeof(huwei1[i]));
  	 		
  	if (huwei1[i]->query("skill")=="hammer")
  		huwei[i]->ccommand("perform fanbei");
  	else if (huwei1[i]->query("skill")=="spear")
  		huwei[i]->ccommand("perform zonghengtianxia");
  	else
  		huwei[i]->ccommand("perform tianwaifeixian");
  		
  	if (!huwei[i] || huwei[i]->is_busy()) {
  			return 1;	// perform �� busy �˻�������
  	}
  	
  	message_vision(BLU"����������������������\n"NOR, me);
    return 1;
}

