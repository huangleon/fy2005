#include <ansi.h>
inherit SMART_NPC;
void smart_fightx();

void create()
{
	object weapon;
	set_name("��¥�޲���", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "����" );
	set("nickname",HIR"��ħ ��ħ ��ħ ��ħ"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	auto_npc_setup("disciple",200,220,0,"/obj/weapon/","fighter_w","demon-blade",2);
	setup();

	weapon=carry_object("/obj/weapon/blade");
	weapon->set_name(NOR CYN"����ն"NOR, ({"whole gale","gale" }) );
	weapon->set("long","����һ������ĳ����������ϵ���СС�ģ��������죢���֡�\n");
	weapon->set("value",0);
	weapon->wield();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("������", ({ "the guardian","guardian" }) );
	weapon->set("long","�������������ס�\n");
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
