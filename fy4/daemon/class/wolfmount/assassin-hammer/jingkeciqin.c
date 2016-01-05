//�������// Silencer @ FY4 workgroup. Oct.2004

#include <ansi.h>
#include <combat.h>

int tobe(object me,object target,object weapon, object room);
int disrupted (object me, object who, string how);

int perform(object me, object target)
{
	string msg;
	int extra,i;
	object weapon;
	int duration;
	function f = (: disrupted :);
	
	extra = me->query_skill("assassin-hammer",1);
	if(me->query("class")!="wolfmount")
		return notify_fail("ֻ����ɽ���Ӳ���ʹ�á�������ء�\n");
	if ( extra < 100) 
		return notify_fail("��������ء���Ҫ100���Ĳ��˴�����\n");
	
	if (me->query_skill_mapped("force")!="wolf-force")
		return notify_fail("���˴�����Ҫ�����ķ�Ϊ������\n");
	
	if( !target || !target->is_character()) 
		return notify_fail(HIR"��Ҫ����˭��\n"NOR);
	
	if( target==me) return notify_fail(HIR"�㲻����ˣ�\n"NOR);
		
	if(environment(me)->query("no_fight")) 
		return notify_fail("���ﲻ׼��ɱ����\n");
		
	if (userp(me))
	if (!COMBAT_D->legitimate_kill(me, target)) {
		if (stringp(target->query("NO_KILL")))
			return notify_fail(target->query("NO_KILL"));
		if (stringp(target->query("NO_PK")))
			return notify_fail(target->query("NO_PK"));	
		else 
			return notify_fail("���޷��������ˡ�\n");
	}
	
	if (target->is_corpse())
		return notify_fail("���Ѿ�û������\n");
				
	if(target->is_fighting(me) || target->query_max_hate()== me)
		return notify_fail("ս�����޷�ʹ�þ�����أ�\n");
	
	// This won't affect single ppl much, it just prevent 2 wolves ping-pang
	duration = target->query_temp("marks/just_assed")+6 - time();
	if (duration>0)
		return notify_fail("�����Ѿ��������˷ɴ���Ŀ���˻��߸����˷ɴ������ϼ����Ӱɡ�\n");	
	target->set_temp("marks/just_assed",time());
		
	me->delete_temp("last_damage_from");
	weapon = me->query_temp("weapon");
	tell_object(me, HBBLU WHT"\n�㰵������" + target->query("name") + HBBLU WHT"�����Ϣ��������������ء����ƴ�����\n"NOR);
	call_out("tobe", 6, me, target, weapon, environment(me));	
	me->start_busy(4,f);
	return 1;
}


int disrupted(object me, object who, string how)
{
	if (how == "hit")
	{
		tell_object(me,WHT"���ˣ��������ˣ��㲻�ò������˾�����ص���ͼ��\n"NOR);
		return 1;	
	}
	return 0;
}


        	
int tobe(object me,object target,object weapon, object room)
{
	string msg;
	int hit_damage, damage, rate, stage, crit;
	
	if (!me)	return 1;
		
	if(!target || environment(target)!=environment(me)
		|| room!= environment(me)) 
	{
		tell_object(me, WHT"���ϧ����Ҫ��ɱ��Ŀ�������ˡ�\n"NOR);	
		return 1;
	}
	
	if (me->query_temp("last_damage_from") || me->query_temp("is_unconcious"))
		return 1;
		
	if(target->is_fighting(me) || target->query_max_hate()== me) {
		tell_object(me, "ս�����޷�ʹ�þ�����أ�\n");
		return 1;
	}
	
	if (target->is_corpse()) {
		tell_object(me, "���Ѿ�û������\n");
		return 1;
	}	
	
	if(!present(weapon,me) || weapon->query("equipped")!="wielded"){
		tell_object(me, WHT"�����ˣ�����ô�������������ˣ� \n"NOR);
		return 1;
	}
		
	msg = YEL "\n$NԾ���������"+weapon->query("name")+YEL"һת�������������֮����\n$N��һ����" + weapon->query("name") + YEL"���ַɳ��������ɳ��Х�Ż���$n�� \n"NOR;
	message_vision(msg, me, target);
	weapon->move(environment(me));
	
	rate = 80;

    stage = F_LEVEL->get_level(me->query("combat_exp"));	 
    if (stage >= 105 )   		rate = 100;				// 6.6 M
	else if (stage >=95)		rate = 90;				// 5.6 M

		
	// 150*3 + 100 = 550
	// 485*3 + 100 = 1555; 1555*1.5= 2332 average
	// 150*3 + 100 = 550, 485*3 + 100 = 1555
	// Players can reach skill cap @4.6M, so we use hard code to limit it
	//  @4.6M ����, 1088*1.5 = 1632
	//	1321* 1.5 = 1982 dmg @ 5.6M+
	//  1555* 1.5 = 2332 dmg @ 6.6M + 

	
	hit_damage = 100 + me->query_skill("hammer") * 3*  rate/100;
	hit_damage = hit_damage * (F_ABILITY->check_ability(me,"bolang2_add")*2 + 100)/100;

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
	target->kill_ob(me);
    	me->kill_ob(target);
	me->stop_busy();
	return 1;
}