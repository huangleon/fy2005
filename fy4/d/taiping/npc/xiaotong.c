inherit NPC;
#include <ansi.h>

void create()
{
        set_name( "��СС", ({ "kid", "small kid" }) );
		set("title", "��֪Сͯ");
		set("gender", "����" );
		set("age", random(5)+4);
		set("int", 26);
		set("long",
		"һ���������С���ӣ����ڵ����沣�����ӡ�\n");
        set("chat_chance", 1);
        set("chat_msg", ({
                "��СС˵���������Ҫ׬�ܶ�Ǯ������ȥ�����Ľ�㡣\n"
        }) );
		set("inquiry", ([
        	"*" : 	"�ҳ�����ʲô����֪����ʲô������֪����\n",
   		]));
		set("attitude", "peaceful");
		set("combat_exp", 20000);
        set_skill("unarmed", 50);
        set_skill("taiji", 50);
        map_skill("unarmed", "taiji");
		setup();
		carry_object("obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/ball");
}


/*
void init() {
	
	object ob;
	::init();
	if( interactive(ob = this_player())) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	object paper;
	int pass;
	if( !ob || environment(ob) != environment()) return;

	if (ob->query("marks/parrot/����") && ob->query("marks/parrot/������ҵ�����")
		&& ob->query("marks/parrot/��ʯ������") && ob->query("marks/parrot/ʬ�������")
		&& ob->query("marks/parrot/����Ѫū")&& ob->query("marks/parrot/ɱ������")
		&& ob->query("marks/parrot/ɱ�ϻ׳�"))
		pass=1;
	
	
	if( pass && !random(5) && !ob->query("marks/parrot/����ͷ����") && !ob->query("marks/parrot/����ү")) {
		message_vision(CYN"$N���������Ÿ���ͷ����һ�����������ҽ����㡣��\n"NOR,this_object(),ob);
		ob->set("marks/parrot/����ͷ����",1);
		paper= new(__DIR__"obj/paper");
		if (paper) {
			paper->move(this_object());
			command("give paper to "+ob->get_id());
		}
		return;
	}
}

*/