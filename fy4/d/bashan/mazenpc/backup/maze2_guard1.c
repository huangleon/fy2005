#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("�첿��", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("nickname",HIR"������һժ�� ���������"NOR);
	set("gender", "Ů��" );

	set("attitude", "aggressive");

	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(20) :),
	}) );

	set("combat_exp", 9000000);

	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);


	auto_npc_setup("disciple",200,200,0,"/obj/weapon/","fighter_w","daimonsword2",4);
	setup();

	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"��ħʥ��"NOR, ({ "unholy armor","armor"}) );
	weapon->set("long","һ������ɫ����ף���֪�Ǻ������ơ�\n");
	weapon->set("value",0);
	weapon->wear();


	weapon=carry_object("/obj/weapon/blade");
	weapon->set_name(NOR CYN"����ն"NOR, ({"whole gale","gale" }) );
	weapon->set("long","����һ������ĳ����������ϵ���СС�ģ��������죢���֡�\n");
	weapon->set("value",0);
	weapon->wield();


}


/*
update /adm/daemons/smartd;update /std/char/npc_mid;update here;ask ke about silencer;call mingyue->delete_temp(inquiry_time);update /d/bashan/mazenpc/maze1_guard16;clone;call disciple->ccommand(kill fighter);
update /adm/daemons/smartd;update /std/char/npc_mid;update here;update /d/maze/npc/test;clone;update /d/bashan/mazenpc/maze2_guard6;clone;call disciple->ccommand(kill k);
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
