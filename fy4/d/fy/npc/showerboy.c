// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("Сͯ", ({ "little kid","kid" }) );
    	set("title", "��������");
	set("gender", "����" );
	set("age", 14);
	set("long",
		"һ��������а��Сͯ\n");
	set("combat_exp", 350000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		__DIR__"obj/white_towel":100,

	]) );
	set_skill("unarmed",200);
	set_skill("dodge",200);
	setup();
	carry_object(__DIR__"obj/yellow_cloth")->wear();
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
message_vision("$N�ڰ�æ��̧��ͷ����$nһ�ۡ�\n",this_object(),ob);
			break;
	}
}


void reset()
{
	set("vendor_goods", ([
		__DIR__"obj/white_towel":100,
	]) );
}