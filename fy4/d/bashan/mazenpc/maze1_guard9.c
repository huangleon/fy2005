#include <ansi.h>
inherit SMART_NPC;


void create()
{
	object weapon;
	set_name("ҹ�沿��", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "Ů��" );
	set("nickname", HIR"�����ܵü��ȿ�"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);


	auto_npc_setup("disciple",200,200,1,"/obj/weapon/","fighter_w","jin-gang",2);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(BLU"Ѫ��֮��"NOR, ({ "cloth"}) );
	weapon->set("long","һ�����а߰�Ѫ�������¡�\n");
	weapon->set("value",0);
	weapon->wear();

}

