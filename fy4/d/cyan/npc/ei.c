// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();

void create()
{
	object weapon;
        set_name("������", ({ "yu qingdi","yu","qingqi" }) );
        set("title","��ϼɽ "HIB"����"NOR);
		set("nickname",MAG"��������֯�ɺ�"NOR);
        set("gender", "Ů��" );
		set("class","moon");

		set("age",21);

        set("long","�����������ɽ���ߣ�ĬĬ����\n");

	set("chat_chance",1);
	set("chat_msg", ({
		"�����������ɽ���ߣ�ĬĬ����\n",
		"������΢̾����Ȼ�����Ӿ��������ʹ�ȥ������\n",
		"������������������Ļ����У��͵͵�������Щ��ǰ˵������������ˣ����Ѿ�ɢ���������ˡ���\n",
	}) );
 
        set("combat_exp", 7000000);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
             }) );


		set("death_msg",CYN"\n$N���һЦ�����������۾���\n"NOR);

		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name("���ٵ�", ({ "blade" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/weapon/dagger");
        weapon->set_name("����֦", ({ "dagger" }) );
		weapon->set("value",0);

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("����", ({ "cloth" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",220,200,0,"/obj/weapon/","fighter_w","spring-blade",4);
}
