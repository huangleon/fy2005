// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("��������", ({ "skeletal fodder","fodder" }) );
        set("gender", "����" );
		set("class","huashan");

		set("age",335);

        set("long","һ�߿�����ʮ�ֺ��˵Ĺ�����\n");

        set("combat_exp", 3000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
             }) );

		auto_npc_setup("waiter",200,200,0,"/obj/weapon/","fighter_w","xuezhan-spear",1);
		setup();

        weapon=carry_object("/obj/weapon/spear");
        weapon->set_name("ùľì", ({ "spear" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("���鲼Ƭ", ({ "cloth" }) );
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
�������鲼Ƭ(Cloth)
  ��������ùľì(Spear)"NOR"\n");
		return 1;
	}
	return 0;
}