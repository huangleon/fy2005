#include <ansi.h>
inherit SMART_NPC;

void create()
{
        set_name("�������", ({ "mr er" }) );
        set("gender", "����");
	set("age",35);
	set("combat_exp", 900000);
        set("class","baiyun");
        set("long",
"��װ���ڣ����������������������԰׵������۽�������������˵�����İ�����
��������������һ���Ũü�䣬�ַ·�����˳�ޡ�\n"
	);

        set("chat_chance", 1);
        set("chat_msg", ({
		(: random_move :),
        }) );
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(80) :),
        }) );
    	    	
    	auto_npc_setup("wang",150,150,1,"/obj/weapon/","fighter_w","feixian-sword",1);
        setup();
	carry_object("/obj/armor/cloth")->wear();
}
