inherit NPC;
#include <ansi.h>

void create()
{
	set_name("��С��", ({ "long xiaoyun","long","xiaoyun" }) );
	set("gender", "����" );
	set("title", HIR "�캢��"NOR);
	set("age", 14);
	set("long","һ��������а��δ�����µ�С���ӣ������ٱ�����ˣ�����\n");
	set("combat_exp", 3000);
	set("per",30);
	set_skill("unarmed",50);
	set_skill("dodge",50);
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
}


void greeting(object ob)
{
	if( !ob || environment(ob) != environment() ) return;
	switch( random(10) ) {
		case 0: message_vision("$N���������ҵ�С��ɵ����Ϲٽ��һ�����Ӧ����Ϊͽ�ġ�\n",this_object(),ob);
			break;
		case 1:
			command("grin");
			break;
	}
}
