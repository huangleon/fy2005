
inherit NPC;
inherit F_VENDOR;

void create()
{
	set_name("����", ({ "yan song", "song" }) );
	set("gender", "Ů��" );
	set("age", 22);
	set("per", 30);
	set("long",
		"�����Ǹ��׸�ɮ�ĵ�������ӡ�\n");
        create_family("������", 21, "����");
	
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("class","lama");
	set_skill("iron-cloth", 100);
	set_skill("jin-gang", 60);
	set_skill("unarmed", 100);
	set_skill("bloodystrike", 100);
	set_skill("staff",100);
	set_skill("cloudstaff",50);
	
	map_skill("unarmed", "bloodystrike");
	map_skill("iron-cloth", "jin-gang");
	map_skill("staff","cloudstaff");
	
	set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "staff.longxianyuye" :),
		(: perform_action, "unarmed.fofawubian" :),
	
        }) );	
        set("inquiry", ([
                "������": "��....������ӣ��������㡣\n",
                "��������": "��....����������أ����������ڴ�Į���ˡ�\n",
        ]) );
	set("vendor_goods", ([
		__DIR__"obj/fake-tooth":30,
	]) );
	setup();
    carry_object(__DIR__"obj/whtclothh")->wear();
	carry_object(__DIR__"obj/5staff")->wield();
}


void init()
{	
	object ob;
	::init();
	add_action("do_vendor_list", "list");
}
