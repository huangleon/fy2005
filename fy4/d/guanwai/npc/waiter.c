// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����", ({ "waiter" }) );
	set("gender", "����" );
    	set("title", "�ϰ�" );
	set("age", 62);
	set("long",
		"һ����ͷ��Ц�����æ��������ʱ������ڲ����ϵ�Ĩ��������\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set_skill("iron-cloth", 2000);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 50);
	map_skill("unarmed", "bloodystrike");
	set("rank_info/respect", "�϶���");
	set("vendor_goods", ([
		__DIR__"obj/junksword":50,
		__DIR__"obj/junkblade":50,
		__DIR__"obj/junkstaff":50,
		__DIR__"obj/jade3":50,
		"/obj/item/bag":50,
        	"/obj/medicine/snake_drug":50,
        __DIR__"obj/huboots":50,
		__DIR__"obj/wineskin":50,
        __DIR__"obj/guskin":50,
		__DIR__"obj/sheep_leg":50,
		__DIR__"obj/jingtong": 50,

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
	add_action("do_rent","rent");
}

void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(3) ) {
		case 0:
			say( "���ϰ�����Ц�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȱ��裬ЪЪ�Ȱɡ�\n");
			break;
		case 1:
			say( "���ϰ������ò����ϵ�ë��Ĩ��Ĩ�֣�˵������λ" + RANK_D->query_respect(ob)
				+ "����������\n");
			break;
		case 2:
			say( "���ϰ�����˵������λ" + RANK_D->query_respect(ob)
				+ "�������ȼ���С��ľưɣ��⼸��Ŵӽ����￪���Ӵ��\n");
			break;
	}
}

int do_rent(string arg)
{

	object ob, chefu;
	object me = this_player();
	object silver;
	if (arg != "carriage" && arg != "mache")
	{
		return notify_fail("��Ҫ��ʲô��\n");
	}

	if (query("mark/rented"))
	{
		tell_object(me,"
����˵����ѽ�����Ѿ����ȥ�ˣ���λ�͹��ǲ��ǹ����������
����Ȳ������Ҹ���ָ��һ���ݾ��ɡ�����Help newbie������ѡ��
·��ָ�ϣ������м�����������·��˵����\n");
		return 1;
	}
	if (me->query_temp("marks/guanwai_mache",1))
		me->delete_temp("marks/guanwai_mache");
	else {
	    if (me->query("deposit")<800)
	    	return notify_fail("��������Ĵ���������ӡ�\n");
		me->add("deposit",-800);
		tell_object(me, "������վ������˻���ת���˰������ӡ�\n");
	}
	
	ob=new("/d/fy/npc/obj/carriage");
    	ob->move(environment());
	message_vision("$Nʻ�˹��� \n",ob);

    chefu=new("/d/fy/npc/chefu");
    chefu->move(environment());
    chefu->get_quest("/d/guanwai/guanwaicarriageway");
    chefu->set_carriage(ob);
	message_vision("$N���˹��� \n",chefu);

	set("mark/rented",1);
	message_vision("$N�����ţ��������� \n",me);
	me->move(ob);
	chefu->go_now();
	
	call_out("check_status",30,chefu);
	return 1;
}

int check_status(object ob)
{
	if (!ob)
	{
		set("mark/rented",0);
	}else
	{
		call_out("check_status",30,ob);
	}
}

void reset()
{
	set("vendor_goods", ([
		__DIR__"obj/junksword":50,
		__DIR__"obj/junkblade":50,
		__DIR__"obj/junkstaff":50,
		__DIR__"obj/jade3":50,
		"/obj/item/bag":50,
        	"/obj/medicine/snake_drug":50,
        __DIR__"obj/huboots":50,
		__DIR__"obj/wineskin":50,
        __DIR__"obj/guskin":50,
		__DIR__"obj/sheep_leg":50,
		__DIR__"obj/jingtong": 50,

	]) );
}
