#include <ansi.h>
inherit NPC;

void create()
{
        set_name("����", ({ "guizi","����","ghost" }) );
    	set("long","һ����Ŀ�����Ĺ��ӣ����ϵı�����˼����С�\n");
        set("gender", "����" );
        set("age",200);
    	set("no_arrest",1);
    	set("per",1);
    	
    	set("combat_exp",1500000);  
    	set("attitude", "friendly");
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
    	}) );
    	setup();    

}

int is_ghost() { return 1; }

