// silencer@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object target, object friend)
{
	string msg;
	int k;
	object you;
	int skl_me, extra_me, skl_you,extra_you,ob;
		
	if (userp(me) && me->query_skill("yiyangzhi",1)< 100)
		return notify_fail("һָ��Ǭ����Ҫ��������һ��ָ����\n");

	target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��Ǭ����ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	skl_me= me->query_skill("yiyangzhi",1);
	extra_me= me->query_skill("unarmed");
		
	if (!friend || friend == me) {
        msg = BBLU + HIY+"$Nʩչ��������һ��ָ��"+ HIY +
        	"����ָӰ�����ų��ȵ�ָ�磬����$n"HIY"��ȫ��\n\n" + NOR;
        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
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
	if(!you->query_skill("tenderzhi",1) || you->query_skill_mapped("unarmed") != "tenderzhi" ) 
        return notify_fail("ͬ��û����ϵ��书��\n");  
    if(objectp(ob=you->query_temp("weapon")) && ob->query("skill_type") != "unarmed") 
        return notify_fail("ͬ�鲻�ǿ��֡�\n");
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
        
	skl_you= you->query_skill("tenderzhi",1);
	extra_you= you ->query_skill("unarmed");
		
	msg = BBLU+ HIR+"$Nʩչ��������һ��ָ��"+ HIG + you->name()+"ʩչ����������ָ��\n"+ HIY +
	"����ָӰ������������ȵ�ָ�磬����$n��ȫ��\n\n" + NOR;
		
		me->add_temp("apply/attack",skl_you+skl_me*2);
		me->add_temp("apply/damage",extra_you*2+extra_me*2);
	    COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
		me->add_temp("apply/attack",-skl_you-skl_me*2);
	    me->add_temp("apply/damage",-extra_you*2-extra_me*2);
		
		me->perform_busy(2);
		you->perform_busy(2);
		
	return 1;
}

