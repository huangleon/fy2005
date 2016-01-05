inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("С��", ({ "waiter" }) );
	set("gender", "����" );
	set("age", 22);
	set("long",
		"��λС�������������Ŷ�����\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ([
		__DIR__"obj/skin" : 100,
		__DIR__"obj/peach" : 300,
	]) );
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
	switch( random(3) ) {
		case 0:
			say( "С�����˲���˵������λ" + RANK_D->query_respect(ob)
				+ "�������������\n");
			break;
		case 1:
			say( "С�����½����Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "��������ѽ��\n");
			break;
		case 2:
			say( "С��˵������λ" + RANK_D->query_respect(ob)
				+ "���ٲ���ɾ�û���ˡ�\n");
			break;
	}
}


void reset(){
	set("vendor_goods", ([
		__DIR__"obj/skin" : 100,
		__DIR__"obj/peach" : 300,
	]) );
}	