// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("���ô󽫾�", ({ "skeletal general","general" }) );
        set("title",RED"��ս������"NOR);
        set("gender", "����" );
		set("class","huashan");

		set("age",375);

        set("long","һλǰ��ս���պյĽ������������һ��ʬ�ǡ���\n");

        set("combat_exp", 8000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(100) :),
             }) );



		setup();

        weapon=carry_object("/obj/weapon/sword");
        weapon->set_name("��ʴ����", ({ "sword" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("����ս��", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",300,220,0,"/obj/weapon/","fighter_w","sharen-sword",1);

}


void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
	


		write("һλǰ��ս���պյĽ������������һ��ʬ�ǡ���
��������Լ������ʮ���ꡣ
������������ʣ�Ľ����ǹ������ѡ�
��������ս��(Cloth)
  ����������ʴ����(Sword)"NOR"\n");
		return 1;
	}
	return 0;
}