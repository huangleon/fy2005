#include <ansi.h>
inherit NPC;

void create()
{
        set_name("���ӹ�ĸ", ({ "guimu","���ӹ�ĸ","��ĸ","ghost" }) );
    	set("long","�����Ŀ�Ĺ�ĸվ���ھŸ���״���죬��Ŀ�����Ĺ���֮�䡣\n");
        set("gender", "Ů��" );
        set("age",2200);
    	set("no_arrest",1);

    	set("combat_exp",7000000);  
    	set("attitude", "friendly");
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({

    	}) );
    	setup();    
    	carry_object(__DIR__"obj/ghostcloth")->wear();
}

int is_ghost() { return 1; }

