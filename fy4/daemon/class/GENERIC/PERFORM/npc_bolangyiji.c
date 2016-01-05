//����һ��// Silencer @ FY4 workgroup. Oct.2004

#include <ansi.h>
#include <combat.h>

int tobe(object me,object target,object weapon, object room);

int perform(object me, object target)
{
	string msg;
	int extra,i;
	object weapon;
	
    if(userp(me))
		return notify_fail("����ѡ�õ��书��û�����ֱ�ɱ������\n");  
		
	extra = me->query_skill("assassin-hammer",1);
	if(me->query("class")!="wolfmount")
		return notify_fail("ֻ����ɽ���Ӳ���ʹ�á�����һ����\n");
	if ( extra < 100) 
		return notify_fail("������һ������Ҫ100���Ĳ��˴�����\n");
	
	if (me->query_skill_mapped("force")!="wolf-force")
		return notify_fail("���˴�����Ҫ�����ķ�Ϊ������\n");
		
	if( !target || !target->is_character()) 
		return notify_fail(HIR"��Ҫ����˭��\n"NOR);
	
	if( target==me) return notify_fail(HIR"�㲻����ˣ�\n"NOR);
	
	if (!target->is_fighting(me))
		return notify_fail("ս����Ĵ�ɱ��ʹ�á�������ء�\n");
	
	weapon = me->query_temp("weapon");
	tell_object(me, HBBLU HIC"\n����䲻��������ת��" + target->query("name") + HBBLU HIC"��󣬡�����һ�������ƴ�����\n"NOR);	
	call_out("tobe", 7, me, target, weapon, environment(me));	
	me->start_busy(3);
	return 1;
}

        	
int tobe(object me,object target,object weapon, object room)
{
	string msg;
	int hit_damage, damage,crit,rate,stage;
	
	if(!me || !target || environment(target)!=environment(me)
		|| !target->is_fighting(me) || room!=environment(me)) 
	{
		if (me)
			tell_object(me, WHT"���ϧ����Ҫ��ɱ��Ŀ�������ˡ�\n"NOR);	
		return 0;
	}
		
	if(!present(weapon,me) || weapon->query("equipped")!="wielded"){
		tell_object(me, WHT"�����ˣ�����ô�������������ˣ� \n"NOR);
		return 0;
	}
		
	msg = YEL "\n$NԾ������"+weapon->query("name")+YEL"һת�������������֮����\n$N��һ����" + weapon->query("name") + YEL"���ַɳ��������ɳ��Х�Ż���$n�� \n"NOR;
	message_vision(msg, me, target);
	
	rate = 80;
	
    stage = F_LEVEL->get_level(me->query("combat_exp"));	 
    if (stage >= 105 )   		rate = 100;				// 6.6 M
	else if (stage >=95)		rate = 90;				// 5.6 M
	
//	write ("rate is " + rate + "\n");	
	// 150*3 + 100 = 550, 485*3 + 100 = 1555
	// Players can reach skill cap @4.6M, so we use hard code to limit it
	//  @4.6M ����, 1088*1.5 = 1632
	//	1321* 1.5 = 1982 dmg @ 5.6M+
	//  1555* 1.5 = 2332 dmg @ 6.6M + 
	
	hit_damage = 100 + me->query_skill("hammer")*3 *rate/100;
		
	hit_damage = hit_damage * (F_ABILITY->check_ability(me,"bolang2_add")*2 + 100)/100;
	if (F_ABILITY->check_ability(me,"bolang1_add") > random(100))
		hit_damage = hit_damage *2;
	
	// inherently 2% critical chance
	if (F_ABILITY->check_ability(me,"bolang1_add")+2 > random(100)) {
		hit_damage = hit_damage *2;
		crit = 1;
	}
		
	if (COMBAT_D->do_busy_attack(me, target, "assassin-hammer/bolangyiji","unarmed", 500, 10)
		|| ANNIE_D->check_buff(me,"assassinate"))
	{
		damage = hit_damage + random(hit_damage);
			
		if (ANNIE_D->check_buff(me,"assassinate"))
			damage = hit_damage *2;
		
		damage = COMBAT_D->magic_modifier(me, target, "kee", damage);
		if (damage >= hit_damage *3/2)
			msg = HIR"ֻ��" +weapon->query("name")+ HIR"����һ���Х�����ҵľ��硰�䡱�ػ�����$n"HIR"��ͷ����\n"NOR;
		else
			msg = HIR"ֻ��" +weapon->query("name")+ HIR"����һ���Х�����ҵľ��硰�䡱�ػ�����$n"HIR"���ؿڣ�\n"NOR;
		
		if (crit)
			msg = HBRED+HIW"ֻ��" +weapon->query("name")
			+ HBRED+HIW"����һ���Х�����ҵľ��硰�䡱�ػ�����$n"HBRED+HIW"��ü�ģ�\n"NOR;	
		
		message_vision(msg, me, target);
		target->receive_damage("kee",damage, me);
		target->set("eff_kee",target->query("kee"));
		COMBAT_D->report_status(target);		
	}else 
	{
		msg = HIR"ֻ��" +weapon->query("name")+ HIR"����һ�󾢷�����$n"HIR"���Դ��ɹ���ֻ���û�л��У�\n"NOR;
		message_vision(msg, me, target);
	}
	
	return 1;
}