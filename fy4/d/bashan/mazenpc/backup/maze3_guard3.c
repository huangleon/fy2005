#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("�����޲���", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "����" );

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

		set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("combat_exp", 6000000);

	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	setup();
	add_money("coin" , 1+random(100));

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","kaleidostrike",4);

	weapon=carry_object("/obj/armor/hat");
	weapon->set_name(HIR"�埬֮��"NOR, ({ "hairpin"}) );
	weapon->set("long","һö�������Ρ�\n");
	weapon->set("value",0);
	weapon->wear();

	carry_object(__DIR__"obj/wolfclaw")->wield();

	set_temp("apply/attack",200);
	set_temp("apply/parry",200);
}

int kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);	// rascal design :p
	return 1;
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/
