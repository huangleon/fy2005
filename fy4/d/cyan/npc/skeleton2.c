// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("����ʿ��", ({ "skeletal soldier","soldier" }) );
        set("gender", "����" );
		set("class","huashan");

		set("age",355);

        set("long","һ�߿�����ʮ�ֺ��˵Ĺ�����\n");

        set("combat_exp", 4000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
             }) );


		auto_npc_setup("waiter",200,180,0,"/obj/weapon/","fighter_w","dagou-stick1",2);
		setup();

        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("�����", ({ "halberd" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("���ƾ���", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();



}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
	


		write("һ�߿�����ʮ�ֺ��˵Ĺ�����
��������Լ������ʮ���ꡣ
������������ʣ�Ľ����ǹ������ѡ�
�������ƾ���(Cloth)
  �������������(Halberd)"NOR"\n");
		return 1;
	}
	return 0;
}