// �����컨�꡻��mantianhuayu����ÿ40������һö���������Ϊ��ö, 

#include <ansi.h>
#include <combat.h>

inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int extra,i,bonus, chance;
	int num, j, count, twice, x;
	object weapon, *enemy;
	
	if(me->query_skill("tanzhi-shentong",1) < 80)
		return notify_fail("�����컨�꡻������Ҫ80���ĵ�ָ��ͨ��\n");
	
	num = me->query_skill("tanzhi-shentong",1)/40;
	if (num > 5) num = 5;
	
	weapon = me->query_temp("weapon");
	count = weapon->query_amount();
	if (count < 10)
		return notify_fail("������Ҫ10ö������\n");
		
	enemy=me->query_enemy();
	if(!sizeof(enemy))
		return notify_fail("�����컨�꡻ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	if(target)
		return notify_fail("������в���Ҫָ��ʹ�ö��󣡣�\n");
			
	msg = HIY"$N"HIY"˫��һ�����"+ weapon->name() + HIY"ͻȻ�����з׷׷ɳ���
����"+HIC"  ��"+HIG"  ��"+HIY"  ��"+HIR"  ��"+NOR HIY" ɢ�����У�������£�\n" NOR;
	message_vision(msg,me);
	if (userp(me))	weapon->set_amount(count-1);
	i = 0;
	x = 0;
	
	for (j=0; j<num;j++)
	{
		msg=YEL"$N"YEL"���е�$w"YEL"����$n"YEL"��$l����"NOR;
		COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
		if (!enemy[i]->query_temp("damaged_during_attack")) x++;
		if (i==sizeof(enemy)-1) i=0;
			else i++;
	}
	
	chance = F_ABILITY->check_ability(me,"huayu_add")+ F_ABILITY->check_ability(me,"3_huayu_add",3)*2;
//	CHANNEL_D->do_sys_channel("sys",sprintf("chance is %d",chance));
		
	if (me->query("class") == "huashan" 
			&& chance >random(200) ) {
		twice = 1;
		message_vision(HIY"\n$N����һ��ת�ۣ�����"+weapon->name()+ HIY "�������������\n\n"NOR,me);	
                i= sizeof(enemy)-1;
		for ( j = num; j>0; j--)
		{
			msg=YEL"$N"YEL"���е�$w"YEL"����$n"YEL"��$l����"NOR;
			COMBAT_D->do_attack(me,enemy[i], TYPE_PERFORM,msg);
			if (!enemy[i]->query_temp("damaged_during_attack")) x++;
			if (i==0) i=sizeof(enemy)-1;
				else i--;
		}
	}

	if (x>0) {		// Ҳ����˵�����ٱ�֤ 400 damage
		msg = HIY"\n����������������âһ��"+chinese_number(x)+"ö"+ weapon->name()
				+ HIY"��Ȼ���ɹ�����������$N"HIY"���ϡ�\n\n"NOR;
		message_vision(msg, me);
		me->set_temp("pfm/hs_mthy_shield",x);			
	}

	if (num>2) { 
		me->perform_busy(3);
	}
	else   
		me->perform_busy(2);
				
	return 1;
}


