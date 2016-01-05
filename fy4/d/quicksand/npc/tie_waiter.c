// TIE@FY3
inherit NPC;
inherit F_VENDOR;
void create()
{
    	set_name("������", ({ "sun tuozi","sun" }) );
	set("gender", "����" );
	set("age", 52);
	set("long","һ�����Ե���ͬϺ��һ�����Ϻ���\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("rank_info/respect", "�ϰ�");
	set("vendor_goods", ([
		__DIR__"obj/tie1" : 10,
		__DIR__"obj/tie2" : 30,
		__DIR__"obj/tie3" : 10,
		__DIR__"obj/tie4" : 5,
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
            say( "�����ӵ�����λ" + RANK_D->query_respect(ob)
				+ "��Ҫ��ʲô��\n");
			break;
		case 1:
            say( "�����ӿ����������Ҷ�����ֵ������ˡ�������\n");
			break;
		case 2:
            say( "�����������ʵ�����λ" + RANK_D->query_respect(ob)
                + "����˵˵�Ϲٺ�С��˭ʤ���Щ?��\n");

			break;
	}
}
