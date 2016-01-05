// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
    set_name("��С��", ({ "inn waiter","waiter" }) );
	set("gender", "����" );
	set("cor",10);
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 2000);
	set("attitude", "friendly");
	set("rank_info/respect", "С����");
	set("vendor_goods", ([
		"/obj/food_item/wineskin" : 10,
		"/obj/food_item/dumpling" : 30,
		"/obj/food_item/chicken_leg" : 40,
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
			say( "��С��Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "��С���ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
		case 2:
			say( "��С��˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȼ���С��ĺ�ưɣ��⼸��Ŵӽ����￪���Ӵ��\n");
			break;
	}
}
