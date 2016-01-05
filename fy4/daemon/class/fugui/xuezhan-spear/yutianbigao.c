#include <ansi.h>
#include <combat.h>
inherit SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra,mod;
	int tmp;
	int basic;
	int i, flag;
	object weapon,*team, *team1;
	mapping buff;
	
	if (me->query("class") != "fugui")
		return notify_fail("������ȸߡ��Ǹ�����ӵľ��С�\n");
		
	extra = me->query_skill("xuezhan-spear",1);
	tmp = me->query_skill("hawk-steps",1);
		
	dodskill = (string) me->query_skill_mapped("dodge");
	if ( dodskill != "hawk-steps")
		return notify_fail("������ȸߡ���Ҫ������������ϣ�\n");
	if ( userp(me) && me->query_skill_mapped("force") != "skyforce")
		return notify_fail("������ȸߡ���Ҫ�̿��ķ�����ϣ�\n");
	
	if ( extra < 140 || me->query_skill("skyforce",1) < 140 || tmp < 120) 
		return notify_fail("������Ҫ140����Ѫսǹ����140���ı̿��ķ���120��������������\n");	
			
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("������ȸߡ�ֻ�ܶ�ս���еĶ���ʹ�á�\n");
		
	basic = extra/40 + tmp/40;
	if (basic>4)	basic=4;
	
	extra = extra * 60/100;			// coeff adjustion.

	if (ANNIE_D->check_buff(me,"fg-afo")>0) {
		ANNIE_D->debuff(me,"fg-afo");		
		team1 = me->query_team();
		if (pointerp(team1) && sizeof(team1)>1) {
			team = filter_array(team1,(: present($1,environment($2)) :),me);
			if (pointerp(team) && sizeof(team)>1) {
				for (i=0;i<sizeof(team);i++){
					if (team[i]==me)	continue;
					if (ANNIE_D->check_buff(team[i],"fg-afo-ytbg"))	continue;
					if (team[i]->query("class")=="fugui")	continue;
					buff =
						([
							"caster":me,
							"who": team[i],
							"type":"fg-afo-ytbg",
							"att":"bless",
							"name":"�̿��ķ�������Ӣ��",
							"buff1":"pfm/fg-afo-ytbg",
							"buff1_c":me->query_skill("xuezhan-spear",1),
							"time":  30,
							"buff_msg": "",
						]);
					ANNIE_D->buffup(buff);
					tell_object(team[i],BGRN + HIW+me->name(1)+BGRN + HIW"����Ц��Ц��������к�Ȼ�ֳ��������ġ�\n"NOR);
				}
			}
		}
	}	
	
	weapon = me->query_temp("weapon");
	msg = HIY "\n\n$N"HIY"������" +weapon->name()+ HIY"��أ�����������չ�ᣬһ�ɳ��죡\n"NOR;
	message_vision(msg, me, target);
		
	mod =10;
	 	
	if(COMBAT_D->do_busy_attack( me, target, "xuezhan-spear/yutianbigao", "rev-unarmed", 100, mod))
	{
		message_vision(BLU"���$N"NOR+BLU"Ŀ�ɿڴ�����֪����мܣ�\n"NOR,target);
		target->start_busy(1);
		me->add_temp("apply/damage",extra);
           	for(i=0;i<basic;i++)
          	{
	   		if (me->is_busy()) continue;
	   		msg = HIY"��Ц���У�$N"YEL"����»��������ֽ�����Ծ��\n"NOR;
	   		COMBAT_D->do_attack(me,target, TYPE_PERFORM,msg,"����");
		}
		me->add_temp("apply/damage",-extra);
		target->stop_busy();
		me->perform_busy(3);	
	}
	else{
		me->perform_busy(2);
		message_vision(YEL"����$Nһ�ۿ���$n"NOR+YEL"�Ĺ��ƣ�$n"NOR+YEL"���ּ�ʧ���������ƣ�\n"NOR,target,me);
		if (!target->is_busy() && me->query_skill("xuezhan-spear",1)<250){
			msg = YEL"$N"NOR+YEL"�˻���$n"NOR+YEL"������\n"NOR;
			target->add_temp("apply/attack", extra);
			target->add_temp("apply/damage", extra);
			COMBAT_D->do_attack(target,me,TYPE_PERFORM,"");
			target->add_temp("apply/attack",-extra);
			target->add_temp("apply/damage",-extra);
		}
	}
	
	return 1;
}



