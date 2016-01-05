#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
	set_name("������", ({ "disciple" }) );
	set("title",YEL"�������"NOR);
	set("gender", "����" );
	set("nickname",HIR"�ڶ������һ�ѻ�"NOR);
	
	set("attitude", "aggressive");
	set("chat_chance_combat", 100);
	set("chat_msg_combat", ({
		(: auto_smart_fight(30) :),
	}) );

	set("combat_exp", 9000000);
	set("death_msg",CYN"\n$N������������λ�������ξ壿Ī����ȥ��Ī����ȥ����\n"NOR);

	set_skill("dragonwhip",180);
	set_skill("whip",200);
	set_skill("dodge",200);
	set_skill("fall-steps",200);
	set_skill("unarmed", 200);
	set_skill("spicyclaw",200);
	set_skill("divineforce",200);
	set_skill("xiaohun-whip",150);
	
	map_skill("parry","xiaohun-whip");
	map_skill("whip","dragonwhip");
	map_skill("force","divineforce");
	map_skill("unarmed","spicyclaw");
	map_skill("dodge","fall-steps");
		
	set("perform_weapon_attack","demon/whip/dragonwhip/thousandfeather");      
	set("perform_weapon_attack2","demon/whip/dragonwhip/firestorm");

	setup();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIY"����֮��"NOR, ({ "dragon cloth","cloth"}) );
	weapon->set("long","һ����ɫ���Ƴ�����\n");
	weapon->set("value",0);
	weapon->wear();

	weapon=carry_object("/obj/weapon/whip");
	weapon->set_name(HIR"�����"NOR, ({ "whip"}) );
	weapon->set("long","һ���������ɵĳ��Ƥ�ޡ�\n");
	weapon->set("value",0);
	weapon->wield();

	set_temp("apply/parry",200);
	set_temp("apply/attack",100);
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
