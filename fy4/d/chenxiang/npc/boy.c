// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int give_him();
void create()
{
	set_name("�����ɿ��С����", ({ "boy","little boy" }) );
	set("gender", "����" );
	set("age", 5);
	set("long", "����һ��СС�к������óݰ״�����ǿɰ���\n");
	set("combat_exp", 5);
	set("attitude", "friendly");
	set("per",20);
	set("arrive_msg", "����Ť椵����˹���");
	set("leave_msg", "����Ť椵�������");
    	set("chat_chance", 1);
    	set("chat_msg", ({
	                (: random_move :)
    	}) );
    	set("inquiry", ([
	    	"���ɿ�" : (: give_him :),
		"kaidangku" : (: give_him :),
    	]));
	
	setup();
	carry_object(__DIR__"obj/kaidang")->wear();
}
int give_him()
{
	object me , obj;
	me = this_player();
	if( !query("given")) {
		command("remove kaidangku");
		set_name("��ƨ�ɵ�С����", ({"boy", "little boy"}) );
		command("give kaidangku to " + me->get_id());  
	
		set("given",1);
		return 1;
	} else {
		message_vision("$N��ͷ���˿��Լ����ŵ�ƨ�ɣ���$nҡ��ҡͷ��\n", this_object(), me);
	}
	return 1;
}

void reset(){
	object *inv;
	int i;
	set("given",0);
	inv = all_inventory(this_object());
	if(sizeof(inv) == 0){
		carry_object(__DIR__"obj/kaidang")->wear();
	}
}