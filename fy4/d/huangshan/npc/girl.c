// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
void create()
{
        set_name("С����", ({"little girl", "girl"}) );
        set("gender", "Ů��" );
        set("age",5);
        set("long", "
С����ͷ����������裬�ۺ�����������һ��꣬ˮ����Ĵ��۾��ڰ׷�����
����һ˫�۾���Щ΢�죬�ƺ��տ޹�����֪�����Ǹ����˼ҵĺ��ӣ����Ǹ�
�游ĸ����ɽ�Ŀ��ˡ�\n");
        set("attitude", "friendly");

        set("chat_chance", 1);
        set("no_arrest", 1);
        set("no_lu_letter",1);
        set("chat_msg", ({
		"С�����૵������ҵ���ӡ�����ôһ���ӾͲ������أ��� \n"
        }) );
	setup();

	carry_object(__DIR__"obj/jade")->wear();
	carry_object(__DIR__"obj/shoe")->wear();
	carry_object(__DIR__"obj/wcloth")->wear();
}


int kill_ob(object me){
    	message("vision", "һ����ζ�˱ǣ���ֻ����ͷ���ۻ���ȫ��������\n",me);
    	message("vision", "���ƺ�����С�������΢΢����һ�¡�\n", 
    		environment(), me);
    	me->unconcious();
	message_vision("$Nת����ȥ����Ӱ�����������˼����Ͳ����ˡ�\n", this_object());
    	destruct(this_object());
    	return 1;
}

int accept_object(object who, object ob){
    	string  id;
  
    	if(ob->query("marks/toy")){
    		if( ob->name() == "���") {
    		message_vision("$N��������" + ob->name() + "���ĵ�����������\n", 
            	         this_object(), this_player());
			command("remove jade");
			command("give jade to " + who->get_id());
		} 
    	} else{
        	return notify_fail("С����ҡҡͷ˵�����Ҳ�Ҫ������� \n");
    	}
    	call_out("leave", 1);
	return 1;
}

void leave() {
	message_vision("$N�ı����������˿�ȥ��\n", this_object());
	destruct(this_object());
}

void die()
{
	object jade;
	if(jade=present("yu pei",this_object()))
	{
		jade->set("mark/blood",1);
		jade->set("long","һ����Ө��͸�����壬��������һ�鵭��ɫ��ӡ�������һ��ꡣ\n");
		message_vision("��Ѫ�ɽ�������Ӣ��С���ﻺ�����¡������ʺ��Ѫ����������֮�ϡ�\n",this_object());
		
	}	
	::die();
}


