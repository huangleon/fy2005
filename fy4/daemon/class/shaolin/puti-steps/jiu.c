// Silencer@fengyun workgroup	June.2005


#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target)
{
    int skill, num, i, duration,title, orforce, force,timer, extra;
	object *team, *team1, *shiwei;
	mapping buff;
	string msg;
	
    if (userp(me))
    if (me->query("family/master_id")!="master yue" 
        	|| me->query("class")!="official")
        	return notify_fail("ֻ�����ɵĵ��Ӳ���ʹ�á������ǌm�󡻡�\n");
        	
	skill = me->query_skill("strategy",1);
	if (me->query_skill("strategy",1) < 230 || me->query_skill("leadership",1)< 230)
		return notify_fail("�������ǌm����Ҫ230��������230������֮����\n");        		
	       
    extra = me->query_skill("unarmed");
	if (userp(me) &&extra < 220) 
		return notify_fail("�������ǌm����Ҫ220����Ч���ֳ�ȭ!\n");
	
	if (me->query_temp("weapon"))
		return notify_fail("�������ǌm�󡻵��ؼ���Ҫ����ʹ�á�\n");
	
	if (me->query_skill_mapped("unarmed")!="changquan")
		return notify_fail("�������ǌm�󡻵��ؼ���Ҫ���ֳ�ȭ����ϡ�\n");
			
    if (me->query_temp("guard_count")<2)
        	return notify_fail("��Ļ���̫�٣��в�����Ү��\n");
	
	timer = 900 - F_ABILITY->check_ability(me,"jiu_add")*60;
    duration = me->query("timer/pfm/yue-jiu")-time() + timer;
    if ( duration >0)
		return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration/60)+"�������Ҳ����ٴη��������ǌm��\n");
	
    if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�������ǌm��ֻ����ս����ʹ�á�\n");
        	
	me->set("timer/pfm/yue-jiu",time());
    
    msg = BGRN + HIY "$N"BGRN + HIY"�Ӷ�������ǹ��������������λ�λ�����Ʈҡ����������˲���г�"HIW"�����ǌm֮��\n" NOR; 	
  	message_vision(msg, me);		
  	
  	message_vision(WHT"ֻ���������񣬺�����٣�����ݵ���������ɽ����$N"WHT"���������\n"NOR, me); 	        
    me->set("timer/pfm/yue-jiu",time());
    
    target->set_temp("no_check_pfm_win",1);
	
	me->add_temp("marks/full_hit_damage",1);
	
	me->add_temp("apply/attack",extra*3/2);
	me->add_temp("apply/damage",extra);
	
	msg = HIY  "$N"HIY"ʹ�����ֳ�ȭ�еġ���ԧ��ȭ����һ��������ʽ��$n"HIY"������\n" NOR;
	message_vision(msg,me,target);
	msg = HIY  "��һȭ��" NOR;
	COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "ǰһȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "��һȭ��" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        msg = HIY  "�����һȭ����" NOR;
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack",-extra*3/2);
		me->add_temp("apply/damage",-extra);
        me->add_temp("marks/full_hit_damage",-1);
		
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		} 
		
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}
	   
    return 1;
}
	