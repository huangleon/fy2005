// tie@fengyun
#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string msg;
        string *style_siqi = ({
HIG "�ɽ�����$N����ᵯ����$w��ֱ��$n��$l��" NOR,
HIG "�ƽ�����$N����$w�������ƣ�Ʈ��$n��$l��" NOR,
HIG "ʯ������$N����$w������ǧ�����$n��$l��" NOR,
HIG "Ȫ������$N�����ڶ�������$w����ˮ��Ϯ��$n��$l��" NOR
});
        string *style_qiusheng= ({
HIR "��ɽ�续����$N����Ծ��ֱ�����죬����$w�������������϶��¹���$n��$l��" NOR,
HIR "������������$N�����һ������������$w��Х��������$n��$l��" NOR,
HIR "�������ڣ���$N����һ��������$wȦת��Х����ǿ������Х����Ȼһ�壬����$n��$l��" NOR
});
        string *style_mix= ({
HIG "�ɽ�����$N����ᵯ����$w��ֱ��$n��$l��" NOR,
HIR "��ɽ�续����$N����Ծ��ֱ�����죬����$w�������������϶��¹���$n��$l��" NOR,
HIG "�ƽ�����$N����$w�������ƣ�Ʈ��$n��$l��" NOR,
HIR "������������$N�����һ������������$w��Х��������$n��$l��" NOR,
HIG "ʯ������$N����$w������ǧ�����$n��$l��" NOR,
HIR "�������ڣ���$N����һ��������$wȦת��Х����ǿ������Х����Ȼһ�壬����$n��$l��" NOR,
HIG "Ȫ������$N�����ڶ�������$w����ˮ��Ϯ��$n��$l��" NOR
});


	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs;
	
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("�۾�Զ���ģ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if((int)me->query("bellicosity") > 50)
                return notify_fail("���ɱ��̫�أ�ʩչ�������������ʽ��\n");
	
	if(pointerp(obs=me->query_team()) )
	{
	FLAG=1;
	for(i=0;i<sizeof(obs);i++)
	{
	if(obs[i] == me) continue;
	if(!obs[i]) {FLAG=0; continue;}
	if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
	if(!obs[i]->query_skill("siqi-sword", 1)/2) {FLAG=0; continue;}
	if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
	if(ob->query("skill_type") != "sword"){FLAG=0; continue;}
	if(obs[i]->query_skill_mapped("sword") != "siqi-sword") {FLAG=0; continue;}
	if(obs[i]->is_busy()) {FLAG=0; continue;}	
	}	
	if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("blade");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/30;
	
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	skl_you=(int)you->query_skill("sword");
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/30;
        me->add_temp("apply/attack",(skl_you+skl_me)/2);
        me->add_temp("apply/damage",(extra_you+extra_me));
        you->add_temp("apply/attack",(skl_you+skl_me)/2);
        you->add_temp("apply/damage",(extra_you+extra_me));
        you->kill_ob(target);
	for(i=0;i<sizeof(style_mix);i++)
	if(i%2) COMBAT_D->do_attack(me,target,TYPE_PERFORM,style_mix[i]);
	else    COMBAT_D->do_attack(you,target,TYPE_PERFORM,style_mix[i]);
        me->add_temp("apply/attack",-(skl_you+skl_me)/2);
        me->add_temp("apply/damage",-(extra_you+extra_me));
        you->add_temp("apply/attack",-(skl_you+skl_me)/2);
        you->add_temp("apply/damage",-(extra_you+extra_me));
		you->perform_busy(3);
	}
	else
	{
        me->add_temp("apply/attack",skl_me/5);
        me->add_temp("apply/damage",extra_me/2);
        for(i=0;i<sizeof(style_qiusheng);i++)
        COMBAT_D->do_attack(me,target,TYPE_PERFORM,style_qiusheng[i]);
        me->add_temp("apply/attack",-skl_me/5);
        me->add_temp("apply/damage",-extra_me/2);
	}	
	me->perform_busy(3);

	return 1;
}
