// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("�䵱С��", ({ "wudang dizi" }) );

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
 		"���³���"  :"action�䵱С�������������³��ŵǸ��գ����������һ�ˣ���һ���ġ�\n",
 		"����"  :"�����ǿ���һζ��ҩ��\n",
              ]) );

        set("combat_exp", 4200000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("������", ({ "sword" }) );
		weapon->set("unit","��");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("���׵���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",200,180,0,"/obj/weapon/","fighter_w","taiji-sword",2);
}
