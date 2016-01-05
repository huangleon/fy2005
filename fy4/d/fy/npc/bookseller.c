// 2009 FengYun
// Edit by hippo 2009.11
// Т�� ����

inherit NPC;
inherit F_VENDOR;
#include <ansi.h>
void create()
{
	set_name("��ǧ��", ({ "du qianli","du","qianli" }) );
	set("gender", "����" );
	set("age", 91);
	set("title", CYN "�Ÿ߰˶�"NOR);
	set("long","��λ�ϰ岻���Ÿ߰˶������һ��ǵ����̫�ӵ���ʦ��\n");
	set("combat_exp", 150000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
                BOOKS"literate_21" : 50,
                BOOKS"force_21" : 	50,
                BOOKS"magic_21" : 	50,
                BOOKS"move_21" :	50,
                BOOKS"spells_21": 	50,
                BOOKS"fore_21":		50,
                BOOKS"chant_21":	50,
                BOOKS"unarmed_21":	50,
                BOOKS"swimming_30": 50,

	]) );
	
	set_skill("unarmed",150);
	set_skill("dodge",150);
	set_skill("parry",150);
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
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
	switch( random(10) ) {
		case 0:
message_vision("$Nҡͷ���Եص���������ʱ���������������������Ӫ��·�࣮����\n",this_object(),ob);
			break;
		case 1:
message_vision("$N����$nһ�ۣ��ͺߵ����ᷢΪ���ޣ����������ɡ������ڽ�Ϧ������\n",this_object(),ob);
			break;
	}
}


void reset()
{
	if (random(5))
	{
		set("vendor_goods", ([
                BOOKS"literate_21" : 50,
                BOOKS"force_21" : 	50,
                BOOKS"magic_21" : 	50,
                BOOKS"move_21" :	50,
                BOOKS"spells_21": 	50,
                BOOKS"fore_21":		50,
                BOOKS"chant_21":	50,
                BOOKS"unarmed_21":	50,
                BOOKS"swimming_30": 50,
								//__DIR__"obj/mo": 0,
		]) );
	} else
	{
		set("vendor_goods", ([
                BOOKS"literate_21" : 50,
                BOOKS"force_21" : 	50,
                BOOKS"magic_21" : 	50,
                BOOKS"move_21" :	50,
                BOOKS"spells_21": 	50,
                BOOKS"fore_21":		50,
                BOOKS"chant_21":	50,
                BOOKS"unarmed_21":	50,
                BOOKS"swimming_30": 50,
								__DIR__"obj/mo": 1,
		]) );
	}
}