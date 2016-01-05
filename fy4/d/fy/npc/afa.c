// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����", ({ "a fa","fa" }) );
    	set("title", "С³��");
	set("gender", "����" );
	set("age", 35);
	set("long",
		"����ܰ����㿴���尢�������ӡ�\n");
	set("combat_exp", 3000);
	set("attitude", "friendly");
	set("per",30);
	set("vendor_goods", ([
		AREA_RESORT"obj/bblade" : 20,
        	AREA_RESORT"obj/bsword" : 20,
	]) );
	set_skill("unarmed",5);
	setup();
	carry_object("/obj/armor/cloth")->wear();
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
message_vision("$N��$n˵�����֪��֪������Ϭ������������Ī�ö�����ľ����Ļ�������\n",this_object(),ob);
			break;
	}
}
