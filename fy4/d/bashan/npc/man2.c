// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;

void create()
{
		object weapon;
        set_name("����������", ({ "diwanggu dizi" }) );

		set("title","ǰ�������"NOR);

		set("gender", "����" );
		set("age",37);

        set("inquiry",([
 		"�˵���"  :"�˵�����������˲����˲����˲���\n",
 		"�˼���"  :"�˵�����������˲����˲����˲���\n",
 		"���³���"  :"action���������˳�˼Ƭ�̵���"YEL"��ʦ"CYN"ÿ�����³��ţ�����"YEL"�չ�"CYN"���졣\n",
 		"�չ�"  :"�չ�ô�������˲��ڣ����Ÿ������˴���������ϰ��������\n",
 		"��ʦ"  :"��ʦ���ǵ����ȹ��������\n",
 		"������"  :"�����ȹ�����������Ǽ�ʦ��\n",
              ]) );

		set("chat_chance",1);
		set("chat_msg", ({
			"��������˽��ἰ�˵��˵���緶���޲�������\n",
		}) );

        set("combat_exp", 3700000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );

		setup();

        weapon=carry_object("/obj/weapon/hammer");
        weapon->set_name("��Ӭ��", ({ "pai" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("����ս��", ({ "armor" }) );
		weapon->set("value",0);
		weapon->wear();

    	auto_npc_setup("ouyang",200,170,0,"/obj/weapon/","fighter_w","pangu-hammer",2);
}
