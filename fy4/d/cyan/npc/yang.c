// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("����", ({ "yang yan","yang","yan" }) );
        set("title",YEL"��ʨ���"NOR);
		set("nickname",CYN"��"NOR);
        set("gender", "����" );

		set("age",47);

        set("combat_exp", 3400000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(25) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("���ֵ�", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��ɫ����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/weapon/spear");
        weapon->set_name(HIY"��ҫʨ����"NOR, ({ "flag" }) );
		weapon->set("long","һ�������Żƽ�ʨ�ӵĴ��졣");
		weapon->set("value",0);

    	auto_npc_setup("ouyang",200,150,0,"/obj/weapon/","fighter_w","shortsong-blade",1);
}
