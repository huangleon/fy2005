// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
	object weapon;
        set_name("��ɽ����", ({ "huashan dizi" }) );

		set("title","ǰ�������"NOR);

		set("gender", "Ů��" );
		set("age",37);


	set("chat_chance",1);
	set("chat_msg", ({
		"��������˽��ἰ�˵��˵���緶���޲�������\n",
	}) );

        set("inquiry",([
 		"�˵���"  :"�˵�����������˲����˲����˲���\n",
 		"�˼���"  :"�˵�����������˲����˲����˲���\n",
 		"���³���"  :"action��ɽ�������Ϸ���һĨ���Σ��˼ҵ�һ�ε����ӣ���Ҫ������˵����\n",
 		"��һ��"  :"action��ɽ�����ߺ����������㵫ȥ�Ҹ������ԣ���֪��ʲô�ǵ�һ���ˡ�\n",
              ]) );

        set("combat_exp", 3200000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );


		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("��ɫ���廨��", ({ "needle" }) );
		weapon->set("unit","��");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("÷������", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",200,160,0,"/obj/weapon/","fighter_w","qingfeng-sword",2);
}
