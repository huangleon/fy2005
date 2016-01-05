// waiter.c

inherit SMART_NPC;
inherit F_VENDOR;

void create()
{
	object weapon;
    set_name("��ϼɽС��", ({ "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λ��ϼɽС�����Ÿ���¨������һ�����³�����\n");
	set("combat_exp", 4900000);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ([
		__DIR__"obj/staff" : 5,
		__DIR__"obj/tea" : 50,
		__DIR__"obj/food" : 50,
	]) );
	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(25) :),
        }) );

	setup();
        weapon=carry_object("/obj/weapon/staff");
        weapon->set_name("��ɽ��", ({ "staff" }) );
		weapon->set("value",0);
		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("�ٶ�ȹ", ({ "skirt" }) );
		weapon->set("value",0);
		weapon->wear();

		auto_npc_setup("waiter",190,170,0,"/obj/weapon/","fighter_w","cloudstaff",1);

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
			say( "��ϼɽС����ȵ�����λ" + RANK_D->query_respect(ob)
				+ "��ЪЪ���ٹ�ȥ��ɽͷ�ߵúܣ��ȹ���ЪЪ�ȣ�������ɽ�Ȱɡ�\n");
			break;
		case 1:
			say( "��ϼɽС���к�������λ" + RANK_D->query_respect(ob)
				+ "����������Ӳ��Ӳ�ĸ����ɣ����˵úܣ����ģ�\n");
			break;
		case 2:
			say( "��ϼɽС���к�������λ" + RANK_D->query_respect(ob)
				+ "�������ȵ���̹��̵��Ȳ�ɣ����˵úܣ����ģ�\n");
			break;
	}
}



void reset()
{
        set("vendor_goods", ([
		__DIR__"obj/staff" : 5,
		__DIR__"obj/tea" : 50,
		__DIR__"obj/food" : 50,
		]) );
}



// ���p��dancing_faery@hotmail.com

