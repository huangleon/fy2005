#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("�����޲���", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("nickname",HIR"���� ���� ������"NOR);
	set("gender", "Ů��" );

	set("attitude", "aggressive");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(50) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("unarmed",200);
	set_skill("fengyu-piaoxiang",320);
	map_skill("dodge","fengyu-piaoxiang");
		
	set_skill("kaleidostrike",240);
	map_skill("unarmed","kaleidostrike");
	
	set("perform_unarmed_attack","demon/unarmed/kaleidostrike/xukongyeyue");      

	setup();

	weapon=carry_object("/obj/armor/hat");
	weapon->set_name(HIR"�埬֮��"NOR, ({ "hairpin"}) );
	weapon->set("long","һö�������Ρ�\n");
	weapon->set("value",0);
	weapon->wear();

	carry_object(__DIR__"obj/wolfclaw")->wield();

}

