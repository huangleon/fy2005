#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("�����޲���", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "����" );
	set("nickname",HIR"�� �� �� �� ��"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(40) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_u","kwan-yin-spells",2);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("�޺�����", ({ "monk cloth","cloth" }) );
	weapon->set("long","һ�����о���ħ����������ġ�\n");
	weapon->set("value",0);
	weapon->wear();

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
