#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("������", ({ "gate keeper","keeper" }) );
	set("title",YEL"�������"CYN" ������"NOR);
	set("nickname",HIR"��"HIB"��"NOR);
	set("gender", "����" );

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("reward_npc", 1);
	set("difficulty", 1);

	set("combat_exp", 8000000);
	set("chat_chance", 0);
	set("chat_msg", ({
	"������˵�������ţ��������Ѫ����������\n",
	}) );

	setup();
	add_money("coin" , 1+random(100));

	auto_npc_setup("disciple",200,220,0,"/obj/weapon/","fighter_w","mixed_demon",4);

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(YEL"а����"NOR, ({ "unholy armor","armor"}) );
	weapon->set("long","а����(Unholy armor)��\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/sword");
	weapon=carry_object("/obj/weapon/blade");
	weapon=carry_object("/obj/weapon/whip");
	weapon=carry_object(__DIR__"obj/wolfclaw");
	weapon->set_name(BLU"��ȱ��צ"NOR, ({ "claw"}) );
	weapon->set("long","��ȱ��צ(Claw)��\n");
	weapon->set("value",0);
	weapon->wield();

}
/*
int kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);	// rascal design :p
	return 1;
}
*/
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
