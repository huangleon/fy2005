// Silencer@fengyun workgroup	June.2005

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
        int skill, num, i, duration, mod,add;
	string msg, msg1, name;
	object *env, *huwei, *enemy, goner, weapon;
	
	if (userp(me))
        if (me->query("family/master_id")!="master yue" 
        	|| me->query("class")!="official")
        	return notify_fail("ֻ�����ɵĵ��Ӳ���ʹ�á����������󡻡�\n");
        	
	skill = me->query_skill("strategy",1);

	if (me->query_skill("strategy",1) < 200 || me->query_skill("leadership",1)< 200)
		return notify_fail("��������������Ҫ200��������200������֮����\n");        		
	  
	    add = F_ABILITY->check_ability(me,"3_array_add",3)*4/10;     
    duration = me->query("timer/pfm/yue_array_busy")-time() + 10 -add;
	if (duration>0)
        return notify_fail("����Ҫ�ȴ�Ƭ�̣�"+ duration +"�룩�����ٴα���󷨡�\n");
        
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������������ֻ����ս����ʹ�á�\n");
		
    if (me->query_temp("guard_count")<2)
       	return notify_fail("��Ļ���̫�٣��в�����Ү��\n");
        
    env = all_inventory(environment(me));
    huwei = filter_array(env, (: living($1) && $1->query("possessed")== $2 :), me);
    
    if (!huwei || sizeof(huwei)<1)
    	return notify_fail("����ߵĻ���̫�٣��в�����Ү��\n");
    	
    goner = huwei[random(sizeof(huwei))];
	if (!goner->is_fighting(target))
		return notify_fail("��Ļ�������ս���У��޷�����������������\n");
			
    if (target->is_busy())
		return notify_fail("�����ѱ�����Ӧ��ʹ�ù����Ե��󷨣�\n");
	
	mod = COMBAT_D->can_busy(me, target, "puti-steps");	
	if (!mod)
		mod = 10000;
			
    weapon = goner->query_temp("weapon");
	name = goner->query("name");
	if(weapon && weapon->query("skill_type") == "spear") msg1 = "���˴�ǹ";
	else if ( weapon && weapon->query("skill_type") == "hammer") msg1 = "���˴���";
	else	msg1 = "����";
	
	msg = BGRN + HIY "$N"BGRN + HIY"�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"��������֮��\n" NOR WHT"
����ɱ��һ�������ۡ�����" + msg1 + "��" + target->query("name")+ "������ȥ��\n\n"NOR;; 	
  	
  	message_vision(msg, me);
  	
	me->set("timer/pfm/yue_array_busy",time());
  	
  	if (COMBAT_D->do_busy_attack( me, target, "puti-steps/liu", "step", 200, mod))
	{		
		message_vision(HIW"$N⧲���������$nײ�˸����ţ���ʱ���󷨳�����ס��\n"NOR,target, goner);
		target->force_busy(3);
	}
	else{
		message_vision(YEL"$N���Ų�æ���������ߣ�$nһͷײ���˵��ϣ��󷨶�ʱ���ҡ�\n"NOR, target, goner); 
		goner->die();
	}
  	
  	return 1;
}

