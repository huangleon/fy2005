// �𷽲���������ǧ�����б��Թ����Թ��ӯ����������̾���������ŭʽ,annie 6.29.03


#include <ansi.h>
inherit SSERVER;

int perform(object me, object target) 
{
	int i, skill ;
	object weapon,ob;
	string obn;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIC"�����ŭʽ��"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	skill = me->query_skill("daimonsword",1);
	if (skill < 200)
		return notify_fail(HIC"�����ŭʽ��"NOR"������Ҫ200����̾������\n");
	
	if (!me->is_fighting())
		return notify_fail(HIC"�����ŭʽ��"NOR"ֻ����ս����ʹ�á�\n");
	
	if (userp(me))
	{
		if (me->query("class")!= "demon")
			return notify_fail("ֻ��ħ�̵��Ӳ���ʩչ"HIC"�����ŭʽ��"NOR"��\n");

		if (!me->query("marry") || me->query("divorced"))
			return notify_fail("�������������ģ������޷�����ס��̾��������֮���ڡ�\n");

		ob = FINGER_D->acquire_login_ob(me->query("marry"));

		if (ob)
			return notify_fail("�������������ģ������޷�����ס��̾��������֮���ڡ�\n");

		if (me->query("bellicosity") < 1000)
 			return notify_fail("�����ں���Թ��ɱ�������ʹ�ó�"HIC"�����ŭʽ��"NOR"��\n");

		me->add("bellicosity",-1000);
	}
	
	weapon = me->query_temp("weapon");
	message_vision(HIW"\n$N����������������������"+weapon->name()+HIW"бб��ָ����̬���ء�\n" NOR, me);
	me->perform_busy(2);
    call_out("do_bash", 1, me,target,weapon);
	return 1;
}


int do_bash(object me,object target,object weapon)
{
	object tw;
	int i;
	int ax,bx,cx,dx;	// ��....cindy�����forumla��..
	if(!me||!target||!me->is_fighting(target)||environment(target)!=environment(me))
		return 0;
	if(!present(weapon,me))
		return 0;
	if (weapon->query("equipped")!="wielded" && userp(me))
		return 0;
	
	tw = target->query_temp("weapon");
	ax = me->query_skill("sword");
	bx = target->query_skill(tw?tw->query("skill_type"):"unarmed");
	cx = me->query("combat_exp");
	dx = target->query("combat_exp");
	ax = ax - bx;		// 200sword/200daimonswordΪ500,�������Ӧ����600����,����exp�����Ϊ0.
	if (ax<0)
		ax = 0;
	cx = cx * 10 / dx * 20;	// ��ͬ����200, 1.5��300, 0.5��100.
	ax += cx;			// ������ͬ������˶���,ӦΪ200����
	ax = (ax>0?random(ax)*10:1);	// 1000
//	cx = random(ax)/10+1;			// 50
	cx = random(ax)/5+1;			// 100

//	message_vision(HIY "\n$N����һ�������������"+weapon->name()+HIY"ɫת��죬�ڿ��д���һ��ɽ����ǻ���$n��\n" NOR, me,target);
	message_vision(HIC "\n$Nһ�����ȣ�����ǰ������"+weapon->name()+HIC"һ���������������磬���Ƴ��գ���к���£�\n" NOR, me,target);

	if (tw && tw->query("skill_type") != "throwing")	// �������ܵ�..
	{
		message_vision(HIR "����֮�У�$N��æ��̧"+tw->name()+HIR"����"+weapon->name()+HIR"�ᵲ��ȥ��\n" NOR, target);
//		message_vision(HIR "debug:"+tw->query("weapon_prop/damage")+HIR"��"+cx+HIR"��\n" NOR, target);
		if (tw->query("weapon_prop/damage") <= cx)
		{
			message_vision(HIR"ֻ��������һ�����죬$N���е�"+tw->name()+HIR"Ӧ�����ۡ�\n" NOR, target);
			tw->unequip();
			if(tw->query("owner"))
			{
				tw->set("orig_name", tw->query("name"));
				tw->set("weapon_prop/damage",1);
			}
			else
				tw->set("weapon_prop",0);
			target->reset_action();
			tw->set("name","�ϵ���" + tw->query("name"));
			tw->set("item_damaged", 1);
			tw->set("value",0);
			tw->save();

			target->receive_damage("kee",(ax+random(ax)));
			target->receive_wound("kee",ax);
			COMBAT_D->report_status(target);
		
		}
		else
		{
			message_vision(HIR"ֻ��������һ�����죬"+tw->name()+HIR"����������ĳ�����һƬ��������Ѻۡ�\n\n" NOR, target);
			tw->add("weapon_prop/damage",-cx);
			target->add_temp("apply/damage",-cx);
//			target->reset_action();
			tw->save();
		}
	}
	else
	{
		message_vision(HIR"$N�����мܣ�һ�������ܲ�������Թ�����г�һ�������Ѫ�ڡ�\n" NOR, target);
		target->receive_damage("kee",(ax+random(ax))*2);
		target->receive_wound("kee",ax*2);
	    COMBAT_D->report_status(target);
	}
	return 1;
}
