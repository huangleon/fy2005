// tea_waiter.c

inherit NPC;
inherit F_VENDOR;

void create()
{
        set_name("��ҩ��", ({ "med seller","seller" }) );
        set("gender", "����" );
        set("age", 30);
        set("long",
                "һ�������õ���ҩ�ĵĻ�ơ�\n");
	set("combat_exp", 5000);
        set("chat_chance", 2);
        set("chat_msg", ({
                "��ҩ�ĸ߽е���ม��������ϰ�ҩ����\n",
                "��ҩ�ĸ߽е���ม����������衫��\n",
                "��ҩ�ĸ߽е���ม���������衫��\n",
                "��ҩ�Ľе������ģ�֪����Ȫ֮ˮ�𣿺�����Ȫˮ���ٶ������ţ�\n",
                "��ҩ�Ľе����������ҩ����������Ȫˮ���������ģ���ĵط�������ȥ��\n",

        }) );

        set("attitude", "friendly");
        set("vendor_goods", ([
                __DIR__"obj/sendrug":50,
                __DIR__"obj/keedrug":50,
                __DIR__"obj/gindrug":50,
        ]) );
        setup();
        carry_object("/obj/armor/cloth")->wear();

}

void init()
{
        add_action("do_vendor_list", "list");
}

