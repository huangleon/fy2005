/* ����ǳЦ����գ��ϳ�����֪Ϊ˭��
��������ĳ�˼�����������ı��룬���ڻ�������ϳ������һ����
��ôɽ�˺��ģ���ô������ģ����ǵֲ�סһ�������������ҹ�λء�
���������ڣ������˶ϳ�����������̾�������ϳ�����ʽ,annie 07.01.03
*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

	string *msg=     ({
	HIW"���������ո�¥������ǧ��⣻"NOR,
	HIW"����������˼�����Ͼ���檳���\n"NOR,
	HIW"\n�����������絴��ʣ����������ˣ�\n"NOR,
	WHT"���������������ĩ��˼�븡�Ƴ���\n"NOR,
	WHT"\n������������Թ������ݣ���Ҷ�����\n"NOR,
	WHT"������������ĺ�������꣬�뻪�ܼ�����\n"NOR,
	HIR BLK"����������������Ը����Ů���������ƾ��ã�\n"NOR,
	});

	string *msg3=     ({
	HIW"�����ո�¥������ǧ��⣬������˼�����Ͼ���檳���\n"NOR,
	WHT"���絴��ʣ����������ˣ��������ĩ��˼�븡�Ƴ���\n"NOR,
	WHT"Թ������ݣ���Ҷ�����ĺ�������꣬�뻪�ܼ�����\n"NOR,
	HIR BLK"Ը����Ů���������ƾ��ã����������ܣ���\n"NOR,
	});

	string *msg2=     ({
	HIR BLK"������ɽ������ӯ�䣬��Ŀ���"NOR,
	HIR BLK"Ʈ����Ե��������Ӱ������Ѱ�飬��ɢ������\n"NOR,
	HIR BLK"��ɽǧ�أ�������������ȡ���鶯���ݡ�\n"NOR,
	WHT"�����ӣ����������ˣ�����˾ɡ�\n"NOR,
	WHT"һ����ȥ��ã����ƽ��Ц����ң�Ρ�\n"NOR,
	WHT"�������ˮ��ٯ����磬�����̼̣��˺޳�����\n"NOR,
	HIW"���Ϊ˭��\n"NOR,
});

int perform(object me, object target) 
{
	int i, skill,j,k ,l;
	object weapon,ob;
	string obn;

	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIR BLK"���ϳ�����ʽ��"NOR"ֻ�ܶ�ս���еĶ���ʹ�á�\n");

	skill = me->query_skill("daimonsword",1);
	if (skill < 220)
		return notify_fail(HIR BLK"���ϳ�����ʽ��"NOR"������Ҫ220����̾������\n");
	
	if (!me->is_fighting())
		return notify_fail(HIR BLK"���ϳ�����ʽ��"NOR"ֻ����ս����ʹ�á�\n");
	
	if (userp(me))
	{
		if (me->query("class")!= "demon")
			return notify_fail("ֻ��ħ�̵��Ӳ���ʩչ"HIR BLK"���ϳ�����ʽ��"NOR"��\n");

		if (!me->query("marry") || me->query("divorced"))
			return notify_fail("�������������ģ������޷�����ס��̾��������֮���ڡ�\n");

		ob = FINGER_D->acquire_login_ob(me->query("marry"));

		if (ob)
			return notify_fail("�������������ģ������޷�����ס��̾��������֮���ڡ�\n");

		if (me->query("max_force") < 20)
 			return notify_fail("�����ں���Թ��ɱ�������ʹ�ó�"HIR BLK"���ϳ�����ʽ��"NOR"��\n");

		me->add("max_force",-20);	// *bud
	}

	
	message_vision(HIR BLK"\n$N���������۾����ὣ��$n��ȥ��ȫȻ����$n��������Ĺ�����\n" NOR, me,target);
	message_vision(HIY"\n$n����һ�������Բ�Ը������ᣬ��$Nȫ��������\n" NOR, me,target);

	j = target->query_busy();
	target->stop_busy();

	me->add_temp("is_unconcious",1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	me->add_temp("buffup/no_abs",1);		// IGNORE IRON-CLOTH
	k = me->query("resistance/kee");
	l = me->query_temp("resistance/kee");
	me->set("resistance/kee",0);
	me->set_temp("resistance/kee",0);
	for (i=0; i<4+random(5);i++)		// PFMǰ��Ӳ��4-8 normal hit
	   	COMBAT_D->do_attack(target,me, TYPE_REGULAR);
	me->set("resistance/kee",k);
	me->set_temp("resistance/kee",l);
	me->add_temp("buffup/no_abs",-1);		
	me->add_temp("is_unconcious",-1);
	// ����û?...��������û��,��Ҫ�ȴ����˵...
	// �Ѿ���ʬ����*snicker

	target->start_busy(j+1);
	me->stop_busy();

	message_vision(HIC"\n$nһ�ֹ���֮�£�$N�˺۱��壬����Ȼ����������\n$n�����ٶȻ�����ȴ��$N�ѽ���ǰ���������ۣ��������г������������������\n" NOR, me,target);
	message_vision(HIC"\n$N���еĽ��ڿ��л���һ�������İ뻡�����޴��$n��ȥ������\n\n" NOR, me,target);

	target->add_temp("is_unconcious",1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	target->add_temp("buffup/no_abs",1);		// IGNORE IRON-CLOTH
	k = target->query("resistance/kee");
	l = target->query_temp("resistance/kee");
	target->set("resistance/kee",0);
	target->set_temp("resistance/kee",0);
	for (i=0; i<7;i++)		// counter
	   	COMBAT_D->do_attack(me,target, TYPE_REGULAR,me->query("gender") == "Ů��"?msg[i]:msg2[i]);
	target->set("resistance/kee",k);
	target->set_temp("resistance/kee",l);
	target->add_temp("is_unconcious",-1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	target->add_temp("buffup/no_abs",-1);		// IGNORE IRON-CLOTH

	weapon = me->query_temp("weapon");

	if (me->query("gender") == "Ů��")
	{
		message_vision(HIR BLK"\n�����������������ܣ���\n" NOR, me,target);
		message_vision(BLU"\n��$N��ʽ����������"+weapon->name()+BLU"ббָ����森����\n" NOR, me,target);
		message_vision(HIR BLK"\n������������������������������������������ͽ���\n" NOR, me,target);
		message_vision(RED"\n��������������"+weapon->name()+RED"����Ϊǧ�㺮�⣬���ܵ���$n��ȥ��\n\n" NOR, me,target);
	}
	else
	{
		message_vision(HIW"\n����޺ۣ�\n" NOR, me,target);
		message_vision(BLU"\n��$N��ʽ����������"+weapon->name()+BLU"ббָ����森����\n" NOR, me,target);
		message_vision(HIW"\n��������ħ��ǧ�ء��ܡ��ѡ��ݡ�\n" NOR, me,target);
		message_vision(RED"\n��������"+weapon->name()+RED"����Ϊǧ�㺮�⣬���ܵ���$n��ȥ��\n\n" NOR, me,target);
	}




	i = weapon->query("weapon_prop/damage");
	i *= 10;
	for (j=0;j<i;j++)	// loop 1500-,������perform duanchang��NPC��ϡ��,Ӧ����ռ��̫��ʱ��.
		if (random(target->query("combat_exp")) < random(me->query("combat_exp")) )
			k += 1 + random(10);	// 1 - 10
			
	message_vision(YEL"\n����һ����û��ɲ�Ǽ�����"+chinese_number(k)+YEL"Ƭ"+weapon->name()+YEL"����Ƭ���$n���塣\n" NOR, me,target);
	target->receive_wound("kee",k);
    COMBAT_D->report_status(target);

	weapon->unequip();
	if(weapon->query("owner"))
	{
		weapon->set("orig_name", weapon->query("name"));
		weapon->set("weapon_prop/damage",1);
	}
	else
		weapon->set("weapon_prop",0);
	me->reset_action();
	weapon->set("name","�����" + weapon->query("name")+"��Ƭ");
	weapon->set_temp("apply/long",({"����һ��"+ weapon->query("name")+"\n��"}));
	weapon->set("item_damaged", 1);
	weapon->set("value",0);
	weapon->move(environment(me));
	weapon->save();

	i = 0;

	obn = target->name();

	if (target->query("kee") < 1)
	{
		i = 1;
		message_vision(CYN"\n$n���������ŵ��۹⿴��$N���ƺ��������������ϻ������ִ򷨣�\n" NOR, me,target);
		message_vision(CYN"$n��ͷ�������죬����ǧ�����ȴ��һ����Ҳ�²�������"NOR, me,target);
		target->die();				// 
	}

	if (me->query("kee")<1 || me->query("gin") < 1 || me->query("sen") < 1)	// misson accomplished,���Է��ĵ�ȥ��..
	{
		if (!i)
		{
			message_vision(CYN"\n$N��Ҳվ�����ȣ������ĵ��¡�\n" NOR, me,target);
			message_vision(CYN"��ȥ֮ʱ��$N��Ȼ�޺޵Ŀ���"+obn+"���۵����ޱȵ��ź���\n"NOR, me);
		}
		else
		{
			message_vision(CYN"$N����"+obn+"���£�ǿ�˵�һ������Ҳ֧�Ų�ס��\n" NOR, me);
			message_vision(CYN"$N���ϴ���һĨ�����ź���΢Ц�������ĺ�����������\n"NOR, me);
		}
		me->die();				// 
		return 1;
	}

	if (!i)
	{
		message_vision(CYN"\n$Nǿ�˵�һ������Ҳ֧�Ų�ס��˫��һ����������Ȼ���¡�\n" NOR, me);
		me->unconcious();
	}
	else
	{
		message_vision(CYN"$N����"+obn+"���£�ǿ�˵�һ������Ҳ֧�Ų�ס��\n"NOR,me);
		message_vision(CYN"$N���ϴ���һĨ�����ź���΢Ц��������������ȥ��\n"NOR,me);
		me->unconcious();
	}

	return 1;
}


