#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra;
	int tmp, timer, duration, i;
	object *team, *team1;
	mapping buff;
	
	extra = me->query_skill("xuezhan-spear",1);
	tmp = me->query_skill("hawk-steps",1);
	
	if(me->query("class")!="fugui")
    		return notify_fail("ֻ�и���ɽׯ���Ӳ���ʹ�����˷���������ݡ�\n");
	
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "hawk-steps")
		return notify_fail("���˷���������ݡ���Ҫ������������ϣ�\n");
	if ( userp(me) && me->query_skill_mapped("force") != "skyforce")
		return notify_fail("���˷���������ݡ���Ҫ�̿��ķ�����ϣ�\n");
	
	if ( extra < 190 || tmp < 160 || me->query_skill("skyforce",1) < 160) 	
		return notify_fail("��Ҫ190����Ѫսǹ����160��������������160���ı̿��ķ���\n");
			
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("���˷���������ݡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (extra>=250) timer = 20;
	else if (extra >=210)	timer = 30; 
	else	timer = 40;
				
	duration = me->query("timer/pfm/bafang")+timer-time();
	if (duration>0)
    		return notify_fail("���˷���������ݡ���Ҫ"+chinese_number(duration)+"�������ٴ�ʹ�á�\n");

	tmp=tmp/2;	

	if (ANNIE_D->check_buff(me,"fg-afo")>0) {
		ANNIE_D->debuff(me,"fg-afo");		
		team1 = me->query_team();
		if (pointerp(team1) && sizeof(team1)>1) {
			team = filter_array(team1,(: present($1,environment($2)) :),me);
			if (pointerp(team) && sizeof(team)>1) {
				for (i=0;i<sizeof(team);i++){
					if (team[i]==me)	continue;
					if (ANNIE_D->check_buff(team[i],"fg-afo-bffy"))	continue;
					if (team[i]->query("class")=="fugui")	continue;
					buff =
						([
							"caster":me,
							"who": team[i],
							"type":"fg-afo-bffy",
							"att":"bless",
							"name":"�̿��ķ��������",
							"buff1":"pfm/fg-afo-bffy",
							"buff1_c":me->query_skill("xuezhan-spear",1),
							"time":  30,
							"buff_msg": "",
						]);
					tell_object(team[i],BGRN + HIW+me->name(1)+BGRN + HIW"����Ц��Ц��������к�Ȼ�ֳ��������ġ�\n"NOR);
					ANNIE_D->buffup(buff);
				}
			}
		}
	}	

	target->set_temp("no_check_pfm_win",1);
	
//	me->add_temp("apply/attack",tmp);
    msg = HIR "\n\n$N���һ��������ìӰ�к�Ȼʹ����Ѫսǹ�����е�����һ����--�˷�--����--������--��\n"NOR;
    message_vision(msg, me, target);
    
    msg=HIR"�����š�\n$N����$w"+HIR"�ɻ�������$n"+HIR"������" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
	target->set_temp("skip_damage_record",1);
	
    msg = HIR  "�����š�\n$N����$w"NOR+HIR",��������ìӰ,���մ���$n��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "����š�\n$N��$w"NOR+HIR"��������,Ӳ�����㳯$n"NOR+HIR"���˹�����" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�ﾰ�š�\n����$N����$w"NOR+HIR"�û���ǧ��������,�����ܶ�,����$n��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�ﾪ�š�\n$N��$w"NOR+HIR"��û�������,����һ����һ��������ˣ�����$n��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);	
    msg = HIR  "�￪�š�\n$N��������,����$w"NOR+HIR"�󿪴���,����㳯$n"+HIR"Ϯ�˹�����" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIR  "�����š�\n$N�Ϻ�һ��,����$w"NOR+HIR"Ѹ�籼�׿���糸,����ͱ��$n��" NOR;
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
    msg = HIW  "�����š�\n$w"NOR+HIW"����һ�������κ�����֮���Ļ���,���絶�а㻮��$n"NOR+HIW"�����ţ�" NOR;
	me->add_temp("apply/attack",tmp*2);
	me->add_temp("apply/damage",extra);	
	COMBAT_D->do_attack(me,target,TYPE_PERFORM,msg);
        me->add_temp("apply/attack",-tmp*2);
        me->add_temp("apply/damage",-extra);
        me->set("timer/pfm/bafang",time()); 
     
		if (objectp(target))	{
			if (target->query_temp("damaged_during_attack")) 
				 COMBAT_D->win_lose_check(me,target,1);
		}
	
		if (objectp(target))	{
			target ->delete_temp("no_check_pfm_win"); 
			target->delete_temp("skip_damage_record");
		}

        
        
        
        me->perform_busy(4);
	return 1;
}
