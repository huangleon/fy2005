// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
inherit F_VENDOR;
void create()
{
	set_name("�����������", ({ "youngman" }) );
	set("gender", "����" );
	set("age", 25);
	set("long",
"��������һ�����ǵ������˵����������������ı��ӣ��ر���������ˡ�
\n");
	set("combat_exp", 5000);
	set("attitude", "friendly");
	set("per",1);
	set("vendor_goods", ([
		__DIR__"obj/hezi" : 100,
        __DIR__"obj/jianskin" : 30,
		__DIR__"obj/caomian" : 100,
        __DIR__"obj/jiannan" : 30,
		__DIR__"obj/miantiao": 40,
		"/obj/food_item/wineskin" : 50,
	]) );
        set("inquiry", ([
                "ɱ�˰�" : "Ŷ�������Ѿ��Ǻܾ���ǰ�����ˣ�����˵�Ǽһ��аѵ��������ĵ���������ɱ�ģ�\n",
		"murder" : "Ŷ�������Ѿ��Ǻܾ���ǰ�����ˣ�����˵�Ǽһ��аѵ��������ĵ���������ɱ�ģ�\n",
        ]));

	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/qiju");
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
	switch( random(10) ) {
		case 0:
command("say �����Կ����ճ����ģ�\n");	
			break;
	}
}

int accept_object(object me, object obj)
{
	command("say ��л��λ" + RANK_D->query_respect(me) + "\n");	
        return 1;
}


void reset(){
	set("vendor_goods", ([
		__DIR__"obj/hezi" : 100,
        __DIR__"obj/jianskin" : 30,
		__DIR__"obj/caomian" : 100,
        __DIR__"obj/jiannan" : 30,
		__DIR__"obj/miantiao": 40,
		"/obj/food_item/wineskin" : 50,
	]) );
}	