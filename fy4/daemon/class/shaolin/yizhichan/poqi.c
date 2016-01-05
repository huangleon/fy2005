// hippo@fengyun	2010.3.11

#include <ansi.h>
#include <combat.h>

void enforce_refresh(object ob,int off);
inherit SSERVER;

int perform(object me, object target)
{
	string msg;
	int myexp,yourexp,lvl,extra,mod,duration,old_force_factor;
	mapping buff;
	
	if (me->query("class")!="shaolin") 
		return notify_fail("��������Ϊ�����ؼ���\n");
		
	extra=me->query_skill("yizhichan",1);
	if(extra<150)
		return notify_fail("����������Ҫ150��һָ����\n");	

	duration = me->query("timer/pfm/sl_poqi") - time() + 600;
    if( duration > 0 ) {
       	return notify_fail("�㻹��Ҫ�ȴ�"+(int)(duration+1)+"�����Ҳ����ٴ�ʹ�á���������\n");
	}

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("��������ֻ�ܶ�ս���еĶ���ʹ�á�\n");
	
	if (ANNIE_D->check_buff(target,"enforcedown"))
		return notify_fail(target->name()+"�����Ѿ����ƽ⡣\n");
		
	mod = COMBAT_D->can_busy(me, target, "yizhichan");	
	if (!mod)
		return notify_fail(HIW"���˹�����տ���޷��óѡ�\n"NOR);
	
	//lvl = 250;					
	lvl = (int) me->query_skill("unarmed") /40 + 1;
	if (!userp(me)) 	lvl = 300;
		
	msg = BRED +HIY"
$Nʹ��һ�С���������һָ���ٵľ���$n���ϸ���Ѩ����\n" NOR;
	message_vision(msg, me, target);
	if (COMBAT_D->do_busy_attack( me, target, "yizhichan/poqijue","unarmed", lvl*100, mod))
	{
		old_force_factor=target->query("force_factor");
		target->set("force_factor",0);
		msg = RED"$n�������ʱ���Ѿ����ˣ�ȫ�����¸���ʹ���Ͼ���\n"NOR;
		message_vision(msg, me, target);
		buff =
		([
			"caster":me,
			"who":	 target,
			"type": "enforcedown",
			"att":  "curse",
			"name": "һָ��������",
			"time":  60,
//			"buff0": "force_factor",
//			"buff0_c": target->query("force_factor"),
			"buff_msg": "",
			"disa_msg": "",
			//"condition_type":  "<���ٶ�>",
			"warn_msg":"",
			"disa_type": 0, 
		]);
		ANNIE_D->buffup(buff);	
		call_out("enforce_refresh",60,target,old_force_factor);
		me->set("timer/pfm/sl_poqi", time());
	} else	{
			msg = WHT"$n����$N�����ƣ����Ų�æ�Ķ㿪��\n"NOR;
			message_vision(msg,me,target);
			me->set("timer/pfm/sl_poqi", time());
	}
	me->perform_busy(1); 
	return 1;
}

void enforce_refresh (object ob,int off) {
	if (ob)
		ob->set("force_factor",off);
}