#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("�첿��", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "����" );
	set("nickname", HIR"ɱ�Ŀ�Ϣ ��ħ֮�Ĳ�����"NOR);
	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);

	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","dagou-stick1",2);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"��ħʥ��"NOR, ({ "unholy armor","armor"}) );
	weapon->set("long","һ������ɫ����ף���֪�Ǻ������ơ�\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/staff");
	weapon->set_name(HIW"��������"NOR, ({ "still killer"}) );
	weapon->set("long","һ��ɭȻ�׹ǡ�\n");
	weapon->set("value",0);
	weapon->wield();

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
