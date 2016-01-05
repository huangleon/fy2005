// annie 07.2003
// dancing_faery@hotmail.com

// *lazy blanche

#include <ansi.h>
#include <combat.h>
inherit NPC;
int look_stone();


void smart_fight()
{
	string msg;
	object t = select_opponent();
	object me=this_object();
	int i;

	if (is_busy())
		return;

	if (!query("enemy") || environment(query("enemy")) != environment())
		set("enemy",t);
	
	t=query("enemy");

	i=query("pfm");
	i++;
	if (i>=5)
		i=1;
	
	set("pfm",i);

	switch (i)
	{
	case 1:
		msg=YEL"\n$N"YEL"ʹ��̫�������е���ɳ������$n"YEL"����������ǧ����ɳ�����಻��������ɱ����...\n"NOR;
		msg += WHT"���$n"WHT"��$N"WHT"���˸����ֲ������������ͣ�����ɳ����\n\n" NOR;
		message_vision(msg,me,t);
		t->force_busy(3);
		perform_busy(1);
		break;
	case 2:
		message_vision(HIY"\n$N"HIY"��$n"HIY"�������ͣ�����һ��"+me->query_temp("weapon")->name()+HIY"�ó��������������ʵʵ�������޷죬����̫�������в��־����С��ϸ��Ʒ⡹��\n"NOR,me,t);
		message_vision(HIC "$N"HIC"Ϊ$n"HIC"������������ܲ�������ʱ�����ٳ���\n\n"NOR,t,me);
		t->force_busy(3);
		perform_busy(1);
		break;
	case 3:
		msg = HIR "\n$N"HIR"ץס$n"HIR"�������������ƣ������Ķ���˫ȭ�û�Ϊ�������СС��ԲȦ��$n"HIR"��ȥ��\n";
		msg += "	���$pͷ��Ŀѣ����$P��ȭ��Χס��������ƵƵ���У�\n\n" NOR;
		t->force_busy(3);
		me->perform_busy(random(2));
		t->receive_damage("kee",1800,me);
		message_vision(msg, me, t);
		COMBAT_D->report_status(t, 0);
		break;
	case 4:
			msg=YEL"\n$N"YEL"����������˫ȭһת��$n"YEL"����ײײ��б���ȥ�������˼���ת����\n"HIC"
Ȼ��$n"HIC"�Ų���δͣ�ȣ�һ���Ի�Ѥ���Ľ����Ѿ�����ת˲���Ƚ���ǰ��\n"NOR;

	me->add_temp("apply/attack", 800);
	me->add_temp("apply/damage", 3210);
		COMBAT_D->do_attack(me,t, TYPE_PERFORM,msg);
	me->add_temp("apply/damage", -3210);
	me->add_temp("apply/attack", -800);
	perform_busy(2);
	delete("enemy");
	}
}

void create()
{
	object weapon;
	set_name("����׿", ({ "li qingzhuo","li","qingzhuo","liqingzhuo" }) );
	set("class","wudang");
	set("gender", "����" );
	set("age", 26);

	set("nickname",WHT"�����Ϣ"NOR);
	set("title","�䵱�� "CYN"������"NOR);

	set("long","\n��Զ��һ��ǬǬ�����İ��£���Զ��һ���ӻ����յ��ὣ��\n����׿������������һվ������һ���ոճ��ʵľ���������\n\n");

	set("no_fly",1);
	set("no_arrest",1);

	set("attitude", "peaceful");

	set("inquiry",([
		"*": "action����׿һ�Բ�����תͷ���ߡ�",
		]) );

	set("combat_exp", 4800000);

	set("always_duxin",1);

	set_skill("sword", 200);
	set_skill("lefthand-sword", 220);
	set_skill("taiji-sword", 220);
	set_skill("windsword", 220);
	map_skill("sword","taiji-sword");
	set_skill("move",400);
	set_skill("five-steps",220);
	map_skill("move","five-steps");

	set_skill("unarmed", 200);
	set_skill("luoriquan", 220);
	set_skill("taiji", 220);
	map_skill("unarmed","taiji");

	set("no_kill",1);
	set_skill("iron-cloth",300);
	set_skill("incarnation",400);
	map_skill("iron-cloth","incarnation");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: smart_fight() :),
	}) );

	setup();



        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name(WHT"���"NOR, ({ "sword" }) );
		weapon->set("long"," ");
		weapon->set("no_drop",1);
		weapon->set("nodrop_weapon",1);

		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
		weapon->set("no_get",1);
        weapon->set_name("һ����Ⱦ�İ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}

