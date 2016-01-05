// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("����ߵ�", ({ "toy seller","seller" }) );
        set("gender", "����" );
        set("age", 60);
        set("long",
                "һ���ú�����һ���;��ÿ��׵����̣�\n");
	set("combat_exp", 3000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "����ߵĻ��˻����е���ߣ�Ц�����������ԣ���\n",
        }) );

        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/windche":15,
		__DIR__"obj/niren":20,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}

