#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("Ħ�����Ȳ���", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("title",HIR"ǧ������ ����һ��"NOR);
	set("gender", "����");
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","feixian-sword",1);
	setup();

	weapon=carry_object("/obj/weapon/sword");
	weapon->set_name(NOR MAG"��������"NOR, ({"shinra" }) );
	weapon->set("long","����һ�����ɵĶ̽��������ϵ���һ����죬��߿��˸�СС�ģ������֡�\n");
	weapon->set("value",0);
	weapon->wield();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(WHT"����֮��"NOR, ({ "suit" }) );
	weapon->set("long","һ����ɫ���Ƴ��ۡ�\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/music/qixianqin");
	weapon->set_name(RED"�ķ���"NOR, ({"tremor ting","ting" }) );
	weapon->set("long","һ������ɫ��ľ�١�\n");
	weapon->set("value",0);

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
