/* ����ǳЦ����գ��ϳ�����֪Ϊ˭��
��������ĳ�˼�����������ı��룬���ڻ�������ϳ������һ����
��ôɽ�˺��ģ���ô������ģ����ǵֲ�סһ�������������ҹ�λء�
���������ڣ������˶ϳ�����������̾�������ϳ�����ʽ,annie 07.01.03
*/

#include <ansi.h>
#include <combat.h>
inherit SSERVER;

	string *msg3=     ({
	HIW"�����ո�¥������ǧ��⣬������˼�����Ͼ���檳���"NOR,
	WHT"���絴��ʣ����������ˣ��������ĩ��˼�븡�Ƴ���"NOR,
	HIR BLK"Թ������ݣ���Ҷ�����ĺ�������꣬�뻪�ܼ�����"NOR,
	});

	string *msg4=     ({
	HIW"������ɽ������ӯ�䣬��Ŀ���Ʈ����Ե��������Ӱ������Ѱ�飬��ɢ������\n"NOR"$N�Ľ��ƺ��������裬���������������ͻȻ������ָ������$n��"NOR,
	WHT"��ɽǧ�أ�������������ȡ���鶯���ݡ������ӣ����������ˣ�����˾ɡ�\n"NOR"$N����һ���������з�һ�䣬���������������������Ȼɭ�ϣ�����������"NOR,
	HIR BLK"һ����ȥ��ã����ƽ��Ц����ң�Ρ��������ˮ��ٯ����磬�����̼̣��˺޳�����\n"NOR"$N����$w��Ȼ���գ�����Բת��$w����һ�������İ뻡������$n��"NOR,
});

int perform(object me, object target) 
{
	int i, skill,j,k ,l;
	object weapon,ob,*pros;
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

		if (me->query("max_force") < 100)
 			return notify_fail("�����ں���Թ��ɱ�������ʹ�ó�"HIR BLK"���ϳ�����ʽ��"NOR"��\n");

		me->add("max_force",-100);	// *bud
	}

	message_vision(CYN"\n$N���������۾���ʹ������̾������ɱʽ����$n���ֻ�ȥ������\n" NOR, me,target);

	pros = target->query_temp("protectors");
	target->delete_temp("protectors");

	target->add_temp("is_unconcious",1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	target->add_temp("buff/no_abs",1);		// IGNORE IRON-CLOTH
	k = target->query("resistance/kee");
	l = target->query_temp("resistance/kee");
	target->set("resistance/kee",0);
	target->set_temp("resistance/kee",0);
	for (i=0; i<3;i++)		// counter
	   	COMBAT_D->do_attack(me,target, TYPE_REGULAR,me->query("gender") == "Ů��"?msg3[i]:msg4[i]);
	target->set("resistance/kee",k);
	target->set_temp("resistance/kee",l);
	target->add_temp("is_unconcious",-1);	// NO DODGE,NO PARRY. NO EXT FUNCTION IN COMBATD.... :( annie 
	target->add_temp("buff/no_abs",-1);		// IGNORE IRON-CLOTH

	target->set_temp("protectors",pros);

	weapon = me->query_temp("weapon");

	if (me->query("gender") == "Ů��")
	{
		message_vision(HIR BLK"\nԸ����Ů���������ƾ��ã����������ܣ���\n" NOR, me,target);
		message_vision(BLU"������$N��ʽ����������"+weapon->name()+BLU"ббָ����森����\n" NOR, me,target);
		message_vision(HIR BLK"����������������������������������������ͽ���\n" NOR, me,target);
		message_vision(RED"��������������"+weapon->name()+RED"����Ϊǧ�㺮�⣬���ܵ���$n��ȥ��\n" NOR, me,target);
	}
	else
	{
		message_vision(HIR BLK"\n���Ϊ˭������޺ۣ�\n" NOR, me,target);
		message_vision(BLU"����$N��ʽ����������"+weapon->name()+BLU"ббָ����森����\n" NOR, me,target);
		message_vision(HIR BLK"����������ħ��ǧ�ء��ܡ��ѡ��ݡ�\n" NOR, me,target);
		message_vision(RED"��������"+weapon->name()+RED"����Ϊǧ�㺮�⣬���ܵ���$n��ȥ��\n" NOR, me,target);
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

	me->perform_busy(2);

	return 1;
}


