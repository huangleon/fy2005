// silencer@fengyun

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

int perform(object me, object friend)
{
		string msg;
		int skl_me, skl_you, extra_me, extra_you,i,j,k;
		object you,ob,target,*myteam;
	
		if (userp(me) && me->query_skill("yizhichan",1)< 100)
			return notify_fail("�κ�ָ��Ҫ��������һָ������\n");
			
		target = offensive_target(me);
		if( !target
		||	!target->is_character()
		||	!me->is_fighting(target) )
			return notify_fail("�κ�ָֻ�ܶ�ս���еĶ���ʹ�á�\n");
        
    	skl_me= me->query_skill("yizhichan",1);
		extra_me= me->query_skill("unarmed");
                           
	        msg = BBLU + HIY"
$N"NOR+ BBLU + HIY"���д��ŵ����ľ��⣬����Զɽ��Ц���ɣ���ʳָ���죬��ָ���ˣ�
����ָ���أ�����һָ�κϣ��޿ա��޻������������\n\n" + NOR;

        me->add_temp("apply/attack",skl_me);
        me->add_temp("apply/damage",extra_me);
        COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-skl_me);
        me->add_temp("apply/damage",-extra_me);
		me->perform_busy(2);
		return 1;

}


