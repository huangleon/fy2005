inherit SMART_NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	object weapon;
    set_name("������", ({ "hanhun" }) );
    set("gender", "����" );
    set("age", 63);
    set("title", HIB "��������"NOR);
    set("long",
      "�������Ѿ������ˣ��ϵü����Ӳ����ǰѴ󴸣�\nȻ��������������ı�����ȴ��Ȼ��ħ\n��������õ���Ʒ��\n");
    set("attitude", "friendly");
    set("class","demon");
    set("combat_exp",4200000);
	set("vendor_goods", ([
	"/obj/generate/commonweapon/60/axe":20,
	"/obj/generate/commonweapon/60/blade":20,
	"/obj/generate/commonweapon/60/fist":20,
	"/obj/generate/commonweapon/60/hammer":20,
	"/obj/generate/commonweapon/60/spear":20,
	"/obj/generate/commonweapon/60/staff":20,
	"/obj/generate/commonweapon/60/sword":20,
	"/obj/generate/commonweapon/60/throwing":20,
	"/obj/generate/commonweapon/60/whip":20,
	]) );

    set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	(: auto_smart_fight(20) :),
      }) );

	auto_npc_setup("disciple",180,160,0,"/obj/weapon/","fighter_w","dragonwhip2",4);
    setup();
	weapon=carry_object("/obj/armor/cloth");
	weapon->set_name(HIB"����"NOR, ({ "cloth"}) );
	weapon->set("long"," ");
	weapon->set("value",0);
	weapon->wear();
}


void init()
{
    add_action("do_vendor_list", "list");
    ::init();
}


void reset()
{
	set("vendor_goods", ([
	"/obj/generate/commonweapon/60/axe":20,
	"/obj/generate/commonweapon/60/blade":20,
	"/obj/generate/commonweapon/60/fist":20,
	"/obj/generate/commonweapon/60/hammer":20,
	"/obj/generate/commonweapon/60/spear":20,
	"/obj/generate/commonweapon/60/staff":20,
	"/obj/generate/commonweapon/60/sword":20,
	"/obj/generate/commonweapon/60/throwing":20,
	"/obj/generate/commonweapon/60/whip":20,
	]) );
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

