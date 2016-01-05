// waiter.c
#include <ansi.h>
inherit SMART_NPC;
inherit F_VENDOR;

void create()
{
	object weapon;
    set_name("����", ({ "zhu yan","zhuyan","yan" }) );
	set("gender", "Ů��" );
	set("age", 16);
	set("price_modifier",500);
	set("per",32);
	set("score",-32);
	set("title",WHT"ɽ����ɫ"NOR);
	set("long","һ�����㶯�˵ĳ�����Ů���������Լ��Ľſ���ɽ��֮�ϡ�\n");
	set("combat_exp", 7200000);
	set("attitude", "friendly");
	
	set("chat_chance",2);
	set("chat_msg", ({
		"���ճ����Ľ�ë������һ��ˮ������㣬���������⶯�ˡ�\n",
		"���ճ���������ҧ���촽����������������˼Һ����㡭��\n",
		"���յ������ֳ�һ˿ʹ��֮ɫ�����Ÿ�����ߵ�������ԥ������\n",
	}) );

	set("vendor_goods", ([
		__DIR__"obj/amulet1" : 1,
		__DIR__"obj/amulet2" : 1,
		__DIR__"obj/amulet3" : 1,
		__DIR__"obj/amulet4" : 1,
		__DIR__"obj/amulet5" : 1,
		__DIR__"obj/amulet6" : 1,
	]) );
	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );

		set("death_msg",CYN"\n$N�����Ŀڣ�������������ҧ�������㡭���ú��ġ���\n"NOR);

		auto_npc_setup("waiter",150,200,0,"/obj/weapon/","fighter_w","daimonsword2",4);
		setup();

        weapon=carry_object("/obj/weapon/blade");
        weapon->set_name(CYN"��˪��"NOR, ({ "relic knot","blade" }) );
		weapon->set("long","һ����״�Źֵ�������\n");
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name(MAG"����ɴȹ"NOR, ({ "longskirt" }) );
		weapon->set("long","һ��������ɴ֯�͵ĳ�ȹ��ȹ�ڷ����Լ�ɼ���\n");
		weapon->set("value",0);
		weapon->wear();

        weapon=carry_object("/obj/armor/boots");
        weapon->set_name("����Ѫ������Ь", ({ "shoes" }) );
		weapon->set("value",0);
		weapon->wear();


}

void init()
{	
	object ob;

	::init();
	if( interactive(ob = this_player()) && !is_fighting() ) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
	add_action("do_vendor_list", "list");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "����̧ͷ������һ�ۣ��촽�䶯�����£��ֵ���ͷȥ��\n");
			break;
		case 1:
			say( "��������ɽ���ϣ����������ŷ�����һ��Ҳû��ע�⵽�㡣\n");
			break;
	}
}
