// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("ʯ�ҵ�", ({ "shi gandang","shi","gandang" }) );
        set("title",YEL"��ʨ���"NOR);
		set("nickname",CYN"�����ҵ�"NOR);
        set("gender", "����" );

		set("age",47);

	set("chat_chance",2);
	set("chat_msg", ({
		"ʯ�ҵ�������ɽ����ȥ����ͷ�󺹡�\n",
		"ʯ�ҵ����˲�����̾��������ʲ��ɽ��û�³���ô�߸�ɶ��\n",
	}) );

        set("combat_exp", 5600000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(70) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name(YEL"�ҵ���"NOR, ({ "hammer" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��ɫ����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",220,200,0,"/obj/weapon/","fighter_w","pangu-hammer",1);
}
