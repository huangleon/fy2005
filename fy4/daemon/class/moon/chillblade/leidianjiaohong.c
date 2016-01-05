
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target, object friend)
{
	string msg;
	int k;
	object you,weapon,ob;
	int skl_me, extra_me, skl_you,extra_you,extra, skill;
		
	if (me->query_skill("chillblade",1) < 20)
		return notify_fail("���׵罻�䡻��Ҫ����20���ı����߾���\n");
	
	if (me->query("gender") == "Ů��")
		return notify_fail("Ů�Ӳ��ʺ�ʩչ���������ġ��׵罻�䡻��\n");

	target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���׵罻�䡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	weapon = me->query_temp("weapon");
	
	skl_me= me->query_skill("chillblade",1);
	extra_me= me->query_skill("blade");
		
	if (!friend || friend == me) {
		msg = HIY"\n$N"HIY"����"+weapon->name()+HIY+"�����ػӳ������Ҳ����ĵ������$n"HIY"������һƬ�ڳ��ĵ��ơ�\n"NOR;
        msg+= HIR"������ͻ���Ѳ�֮����һ������������"+weapon->name()+HIR"��Ȼ������������$n"HIR"��ȥ��\n"NOR;
        message_vision(msg, me, target);
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,"");
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
		me->perform_busy(2);
		return 1;		
	}
		
	you = friend;
	if ( you->team_member(me) 
			|| (!userp(me) && you->query("npc_team")==me->query("npc_team")))
		k = 1;
		
	if (!k)
		return notify_fail("ͬ�������������ͬһ�������С�\n");  
    
    // ��ͬ������ж�           
	if(!you->query_skill("chillblade",1) || you->query_skill_mapped("blade") != "chillblade" ) 
        return notify_fail("ͬ��û����ϵ��书��\n");  
    if (you->query_skill("chillblade",1)< 20)
    	return notify_fail("ͬ��ı����߾��ȼ�̫�͡�\n");
    if(!objectp(ob=you->query_temp("weapon")) || ob->query("skill_type") != "blade") 
        return notify_fail("ͬ��û�гֵ���\n");
	if (you->query("gender")=="����")
		return notify_fail("���׺ϻ���ֻ����Ůʹ�á�\n");
	if (you->is_busy())
		return notify_fail("ͬ����æ���ء�\n");
	if (you->query_temp("till_death/lockup") || you->query_temp("is_unconcious"))
		return notify_fail("ͬ�������޷�ʹ���ؼ���\n");					
	if (you == target)
		return notify_fail("�����ﷴ����\n");
	if (userp(you) && !you->is_fighting(target))
		return notify_fail("ͬ����Է�������ս���С�\n");

	if (userp(me))
	if (!COMBAT_D->legitimate_kill(you, target)) {
		if (stringp(target->query("NO_KILL")))
			return notify_fail(target->query("NO_KILL"));
		if (stringp(target->query("NO_PK")))
			return notify_fail(target->query("NO_PK"));	
		else 
			return notify_fail("������취��ͬ�鳶�����������������ɣ�\n");
	}
	
	// this is to prevent those annoying checking, 2 vs 1 == kill
	 	if (!me->is_killing(target->get_id())){
 			me->kill_ob(target);
 			target->kill_ob(me);
 		}
 		
 		if (!you->is_killing(target->get_id())){
        	you->kill_ob(target);
        	target->kill_ob(you);
        }
        
	skl_you= you->query_skill("chillblade",1);
	extra_you= you ->query_skill("blade");
	skill = skl_me + skl_you;
		
	

	msg = HIY"\n$N����"+weapon->name()+HIY+"�����ػӳ������Ҳ����ĵ������$n������һƬ�ڳ��ĵ��ơ�\n"NOR;
	message_vision(msg,me,target);
	msg = HIG"\n$N"HIG"���е�"+weapon->name()+HIG+"ͻȻ����һƬ��Ļ��Ļ�����꣬�������졣\n"NOR;
	message_vision(msg,you,target);

	message_vision(HIW"\n��Ļ�뵶����������ɲʱ��϶�Ϊһ��Ѹ����ҹ�׵磬���������磬ֱֱ��"+target->name()+"������\n"NOR,me);
	
	me->add_temp("apply/attack", skill);
	me->add_temp("apply/damage", extra_me);
	COMBAT_D->do_attack(me,target, TYPE_PERFORM," ");
	me->add_temp("apply/damage", -extra_me);
	me->add_temp("apply/attack", -skill);
	
	you->add_temp("apply/attack", skill);
	you->add_temp("apply/damage", extra_you);
	COMBAT_D->do_attack(you,target, TYPE_PERFORM," ");
	you->add_temp("apply/attack", -skill);
	you->add_temp("apply/damage", -extra_you);
	
	me->perform_busy(2);
	you->perform_busy(2);
		
	return 1;
}

