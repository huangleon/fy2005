// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("Ī֮��", ({ "mo zhixu","mo","zhixu" }) );
        set("title",YEL"��ʨ���"NOR);
		set("nickname",WHT"��������"NOR);
        set("gender", "����" );

		set("age",27);

	set("chat_chance",2);
	set("chat_msg", ({
		"Ī֮���Ĵ���������ʯͷ�����������������\n",
		"Ī֮���ͷ�������˵Ľţ�����������ģ���ҩ������Զ�������á�\n",
	}) );

        set("combat_exp", 6400000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(70) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name(HIR BLK"���е�"NOR, ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��ɫ����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",220,200,0,"/obj/weapon/","fighter_w","ittouryu",2);
}
