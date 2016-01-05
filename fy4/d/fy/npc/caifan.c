// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("���˵�", ({ "cai fan","fan" }) );
        set("gender", "����" );
        set("age", 40);
        set("long",
                "һ��Ϊ��������ձ�����С���ˣ�\n");
	set("combat_exp", 2000);
        set("attitude", "friendly");
        set("rank_info/respect", "�϶���");
        set("chat_chance", 3);
        set("chat_msg", ({
                "���˵�Ц������һ��������ɣ��߲�һ��Ҷ�³�ʤ����\n",
        }) );

        set("vendor_goods", ([
                __DIR__"obj/smallvege":11,
                __DIR__"obj/bigvege":22,
                __DIR__"obj/midvege":22,
                __DIR__"obj/tomato":10,
                __DIR__"obj/cucumber":10,

        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}


