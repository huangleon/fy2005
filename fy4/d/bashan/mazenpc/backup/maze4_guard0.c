#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("�����˲�", ({ "disciple" }) );
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

	set("combat_exp", 6500000);

	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	setup();
	add_money("coin" , 1+random(100));

	auto_npc_setup("disciple",200,220,0,"/obj/weapon/","fighter_w","mixed_demon",4);
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"��ħʥ��"NOR, ({ "unholy armor","armor"}) );
	weapon->set("long","һ������ɫ����ף���֪�Ǻ������ơ�\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/sword");
	weapon=carry_object("/obj/weapon/blade");
	weapon=carry_object("/obj/weapon/whip");
	weapon=carry_object("/d/bashan/mazenpc/obj/wolfclaw")->wield();

}

int kill_ob(object who)
{
	::kill_ob(who);
	auto_smart_fight(100);	// rascal design :p
	return 1;
}

/*
update /adm/daemons/smartd;update /std/char/npc_mid;update here;ask ke about silencer;call mingyue->delete_temp(inquiry_time);update /d/bashan/mazenpc/maze1_guard16;clone;call disciple->ccommand(kill fighter);
update /adm/daemons/smartd;update /std/char/npc_mid;update /d/bashan/mazenpc/maze1_guard18;clone;call disciple->ccommand(kill herald);
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
