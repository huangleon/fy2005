// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("������", ({ "lan tianmeng","lan","tianmeng" }) );

		set("class","assassin");
		set("title",YEL"ʨ��"NOR);
//		set("nickname",BLU"�ֹ�׽Ӱ��һ����ɱ"NOR);

        set("gender", "����" );
		set("age",47);

		set("chat_chance",1);
		set("chat_msg", ({
			"�����͹��������ص����Ժ�Ҳ�����������˵�Ī֮�����ǡ�\n",
		}) );
		set("death_msg",CYN"\n$N��е����㡫����������������\n"NOR);

        set("combat_exp", 5100000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
    		 (: auto_smart_fight(20) :),
        }) );
    	
    	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","pangu-hammer",1);

		setup();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name("��ʮ���ﺳ��׵", ({ "hammer" }) );
		weapon->set("value",0);
		weapon->wield();


        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("ʨ������", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

}
