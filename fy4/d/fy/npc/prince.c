// Tie @ fy3
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("С����", ({ "little prince", "prince"}) );
        set("gender", "����" );
        set("age", 12);
        set("long", "���ǵ�����ϵ�С���ӣ����ܳ谮��һ����\n");
	set("class","official");
        set("combat_exp", 900000);
        set("attitude", "friendly");
	
	set_skill("dodge", 200);
	set_skill("leadership",150);
	set_skill("strategy",150);
        set_skill("parry",200);
        
        set("intellgent",1);
        
        set("chat_chance", 1);
        set("chat_msg", ({
                "С�����ſڵ�����"+HIR"��"NOR+"һ�������δ�����"+HIG"��"NOR+"��\n",
        }) );
        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: ccommand, "alert" :),
        }) );
	setup();
	carry_object(__DIR__"obj/fycloth")->wear();
}

