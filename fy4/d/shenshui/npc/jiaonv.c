// Silencer @ FY4 workgroup. Aug.2004

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("��Ů" , ({ "jiao nu"}) );
	set("long", "һ������ɴ����翣������ǰ�������Ů��,����ˮ�ﳩ�Ρ�\n");
	set("attitude", "friendly");
	set("age", 14);
  	set("gender", "Ů��" );
    	set("per", 30);
	set("combat_exp", 50000);
	
	set("inquiry", ([
	]) );

	set("chat_chance", 1);
    	set("chat_msg", ({
	     "��Ů��ˮ�ﻶ���������ȥ��\n",
        }) );
	
    	set_skill("parry", 180);
    	set_skill("charm", 180);
		    	    		
	setup();

}

