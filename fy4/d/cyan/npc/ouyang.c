// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("ŷ����", ({ "ouyang ji","ouyang","ji" }) );
        set("title",YEL"��ʨ���"NOR);
		set("nickname",HIC"���ױ�"NOR);
        set("gender", "����" );

		set("age",47);

        set("long","������ǽ�ʨ��ֵĽ�����һ·���ױ޷������뻯�������������ܵС�\n");

	set("chat_chance",8);
	set("chat_msg", ({
		"ŷ������ü������ʲô�����ַ�������嶹��һ���ô��������Ӳ��ʯ�ڣ�\n",
		"ŷ������ü�������˰ѻ��Ͳ������������ʲô���壿\n",
		"ŷ�����ƺ�һ��������˵������ܽ��⻬�Ͱγ�����\n",
	}) );

        set("combat_exp", 5800000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(40) :),
        }) );



		set("death_msg",CYN"\n$N��е����㡫����������������\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/whip");
        weapon->set_name(HIC"���ױ�"NOR, ({ "whip" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��ɫ����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",220,200,0,"/obj/weapon/","fighter_w","thunderwhip",1);
}
