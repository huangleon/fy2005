// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("���ֺ���", ({ "shaolin dizi" }) );

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
 		"���³���"  :"action���ֺ��о��е�������ô֪������������͵͵���磿\n",
		"����" :"����ô��������㳡�����ϣ��ϣ��ϣ������������ϣ��ϣ��������ˡ�",
              ]) );


        set("combat_exp", 3700000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );

		setup();
        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("������", ({ "staff" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name("���´�", ({ "hammer" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/weapon/spear");
        weapon->set_name("�ߴ��ǹ", ({ "spear" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/weapon/axe");
        weapon->set_name("ɱ����", ({ "axe" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("������", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",200,160,0,"/obj/weapon/","fighter_w","wuche-axe",2);

}
