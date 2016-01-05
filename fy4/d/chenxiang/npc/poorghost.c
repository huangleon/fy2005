// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int tell_him();
void create()
{
    	set_name("�Ȼ۶�", ({ "gu huier", "huier" }) );
    	set("gender", "Ů��" );
    	set("age", 24);
    	set("attitude","friendly");
        set("long", "
�Ȼ۶���ǰ�ڳ��������������ģ���ϧ�ڼ������ʱ��ʧ������ˮ�У�
����ȥ�ȵ�����ֻ���ü���������һ��ͷ����ʬ��ȴ��ˮ�����ˣ���
Ҳû���ҵ���\n");
    	
    	set("combat_exp", 15000);
    	set("inquiry", ([
			"��ү":		"����ȥ�ľ�ү�ƹ�����ĳ��������и�ӡ�������Ʒ����\n",
			"������":	"�����򱱾��ǳ������ˣ�\n",	
			"����":		"������ܰѶ��ɱ�ˣ�������ҵĶ��ˣ�\n",
			"�����":	"������ܰѶ��ɱ�ˣ�������ҵĶ��ˣ�\n",
			"ͷ��":		"action�Ȼ۶����������һ�ƶϷ�����������\n",
			"hair":		"action�Ȼ۶����������һ�ƶϷ�����������\n",	
        	]));
    	setup();
    	carry_object("/obj/armor/cloth")->wear();
}


int is_ghost() { return 1; }


void init()
{
    	object ob;
    	::init();
    	if( interactive(ob=this_player()) && ob->visible(this_object()))
    	{
        	remove_call_out("greeting");
        	call_out("greeting", 1, ob);
    	}
}

void greeting(object ob)
{
    	if (!ob || environment(ob)!= environment())	return;
    		
    	tell_object(ob,"�Ȼ۶���������Ұɣ�������һ�����Ͼͳ�����\n");
    	tell_object(ob,"��֪��֪������ȥ�ľ�ү�ƹ�����ĳ��������и�ӡ�������Ʒ����\n"); 
    	ob->set_temp("marks/huier",1);
}


int accept_object(object me, object obj)
{
    	object hair;
    	
    	if(obj->query("huier")) {
        	command("say ����ҿ����Ʒ�����ˣ�\n");
        	command("say �治֪����ôл�㣬����ͷ����������Ψһ���µĶ�����");
        	command("say ���͸�����������ɡ�");
        	
        	hair = new(__DIR__"obj/hair");
        	if (!hair->move(me))
        		hair->move(environment());	       	
        	return 1;
    	}
    	return 0;
}

