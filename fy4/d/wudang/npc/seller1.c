// waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("�ձ�����", ({ "oldman", "man" }) );
	set("gender", "����" );
	set("age", 52);
	set("long",
		"��λ�ձ���������¯������ĳ���\n");
	set("combat_exp", 5000);
	set("vendor_goods", ([
		__DIR__"obj/liandao.c":99,
		__DIR__"obj/axe.c":99,
		__DIR__"obj/dingpa.c":99,
		__DIR__"obj/basket.c":99,
		__DIR__"obj/hammer.c":99,
		__DIR__"obj/chutou.c":99,
	]) );
	setup();
	carry_object("/obj/armor/cloth")->wear();
}

void init()
{	
	object ob;

	::init();
	add_action("do_vendor_list", "list");
}

void reset(){
		set("vendor_goods", ([
		__DIR__"obj/liandao.c":99,
		__DIR__"obj/axe.c":99,
		__DIR__"obj/dingpa.c":99,
		__DIR__"obj/basket.c":99,
		__DIR__"obj/hammer.c":99,
		__DIR__"obj/chutou.c":99,
	]) );
}