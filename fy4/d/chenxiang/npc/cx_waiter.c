// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
    	set_name("���˸�", ({ "waiter" }) );
	set("gender", "����" );
    	set("title", "���õ�" );
	set("age", 22);
	set("long",
		"��λ��С����Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
    	set("combat_exp", 3500);
	set("attitude", "friendly");
	set("vendor_goods", ([
        	"/obj/food_item/shuihu" : 10,
        	"/obj/food_item/shaobing" : 30,
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
            say( "���˸�Ц�Ǻǵ�˵������λ" + RANK_D->query_respect(ob)
                + "�������ȿ�ˮ��ЪЪ�Űɡ�\n");
			break;
		case 1:
            say( "���˸��ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
		case 2:
            say( "���˸�˵������λ" + RANK_D->query_respect(ob)
                + "��С����ձ������ִ࣬���ǳ���һ������\n");
			break;
	}
}
