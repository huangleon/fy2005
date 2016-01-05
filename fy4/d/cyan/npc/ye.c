#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("ҵ;��", ({ "ye tuling","ye","tuling" }) );
	set("title","����;��");
	set("gender", "����" );

	set("no_fly",1);
	set("no_curse",1);
	set("no_arrest",1);

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(100) :),
	}) );

	set("combat_exp", 10000000);

	setup();

	auto_npc_setup("disciple",200,220,0,"/obj/weapon/","fighter_w","starrain",4);

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name("��ɫ����", ({ "da pao"}) );
	weapon->set("long","\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/dart");
	weapon->set_name(YEL"���ľҶ"NOR, ({ "leaf"}) );
	weapon->set("long"," \n");
	weapon->set("base_value",0);
	weapon->set_amount(300);
	weapon->wield();

	weapon=carry_object("/obj/weapon/blade");
	weapon->set_name(CYN"�컡��"NOR, ({ "blade"}) );
	weapon->set("long","\n");
	weapon->set("value",0);
	weapon->wield();

}

int kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);	// rascal design :p
	return 1;
}

int	is_ghost() { return 1;}


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
