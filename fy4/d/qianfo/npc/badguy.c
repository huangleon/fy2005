// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
int rape();

void create()
{
        set_name("ɥ������������", ({ "pig" }) );
        set("gender", "����");
        set("age", 24);
	set("str",30);
        set("long",
                "��������ڹ��컯����ǿ����Ů������\n");
        set("combat_exp", 6000);
        set("score", 400);
        set("chat_chance", 1);
        set("chat_msg", ({
                (: rape() :),
        }) );
        set_skill("unarmed", 100);
        set_skill("parry", 20);
        set_skill("dodge", 40);
        setup();
}

void init()
{
	add_action("do_look","look");
	::init();
}

int rape() {
	object lady,ob=this_object();
	string msg;
	
	if (!lady=present("lady",environment(ob))) {
		message_vision("ɥ�����������������µµ��ת�ţ���������ش������㡣\n",ob);
		return 1;
	}
	switch (random(3)) {
		case 0: msg="ɥ��������������Ц�Ű�����ǧ��С���Ь�ӡ���\n";break;
		case 1: msg="ɥ��������������Ц�Ű�����ǧ��С������ӡ���\n";break;
		case 2: msg= "ɥ��������������Ц�Ű�����ǧ��С��ġ�������\n";
	}
	msg+= "ǧ��С��������ȣ�����ѽ�����컯����ǿ����Ů����\n";
	message_vision(msg,ob);
	return 1;
}

int do_look(string arg){

	if (arg && arg[0..2] == "pig" ){
		if (!present(arg))	return 0;
		write("��������ڹ��컯����ǿ����Ů������\n");
		write("��������Լ��ʮ���ꡣ\n");
		write("�书������������ɲ⣬�����ƺ����ء�\n");
		return 1;
	}
	return 0;
}



void die()
{
	object me;
	me=this_object()->query_temp("last_damage_from");
	if(objectp(me))
        me->set_temp("marks/lady",1);
	::die();
}
