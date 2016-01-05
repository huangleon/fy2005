// waiter.c

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("����", ({ "xuniang" }) );
	set("gender", "Ů��" );
	set("age", 54);
	set("title", HIG "������ϣ������̴�"NOR);
	set("long",
		"��λ������������ɫ���Ե��������㡣\n");
	set("combat_exp", 200000);
        set("attitude", "friendly");
	set("per",20);
	set("vendor_goods", ([
                __DIR__"obj/glxj":120,
                __DIR__"obj/cpdx":120,
                __DIR__"obj/pxhy":120,
                __DIR__"obj/hhdq":120,

	]) );
	set_skill("unarmed",100);
	set_skill("tenderzhi",50);
	set_skill("dodge",50);
	set_skill("stormdance",50);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/wch_skirt")->wear();
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
	switch( random(4) ) {
		case 0:
message_vision("$N���$nһ�ۣ����˶��˰ɣ�������������\n",this_object(),ob);
			break;
		case 1:
message_vision("$N΢�ڱ�ˮͰ��ϸһ�������¶����צ����֣���$n�����У��������˰ɡ�\n",this_object(),ob);
			break;
		case 2:
message_vision("$N����$nһ�ۣ�����������Ц��������¶���ѵ��˴��Ļ�����\n",this_object(),ob);
			break;
	}
}


void reset(){
	set("vendor_goods", ([
                __DIR__"obj/glxj":120,
                __DIR__"obj/cpdx":120,
                __DIR__"obj/pxhy":120,
                __DIR__"obj/hhdq":120,

	]) );	
	
}