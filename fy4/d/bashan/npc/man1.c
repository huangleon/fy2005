// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("ؤ�����", ({ "gaibang dizi" }) );

		set("title","ǰ�������"NOR);

		set("gender", "����" );
		set("age",37);


		set("chat_chance",1);
		set("chat_msg", ({
			"��������˽��ἰ�˵��˵���緶���޲�������\n",
		}) );

            set("inquiry",([
 		"�˵���"  :"�˵�����������˲����˲����˲���\n",
 		"�˼���"  :"�˵�����������˲����˲����˲���\n",
 		"���³���"  :"actionؤ�����֧֧���᣺�����ұ���ҧ�ˣ������㲻Ҫ���߰�������\n",
              ]) );

		set("combat_exp", 2700000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(50) :),
        }) );


		setup();

        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("�Ϲ���", ({ "staff" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�ܶ���ӵĲ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",170,160,0,"/obj/weapon/","fighter_w","dagou-stick",2);
}
