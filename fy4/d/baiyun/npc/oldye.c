#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("Ҷ�Ϸ���", ({ "old ye","ye" }) );
        set("gender", "����" );
        set("title", "һҶ�� ��ѧ��");
        set("nickname",HIY"һҶ��Ŀ������̩ɽ��������������������"NOR);
        set("age", 72);
        set("long", "Ҷ�Ϸ��Ӿ�˵����Ҷ��һ�ŵ��ϳ������������£������Ƶ��������ꡣ\n");
        set("combat_exp", 1000000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "Ҷ�Ϸ���һ�ֳ�һ�������һ���۰��룬ҡͷ���ԣ���֪���ơ�\n",
		}) );
        set("attitude", "friendly");
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",120,120,0,"/obj/weapon/","fighter_w","feixian-sword",1);
        setup();
        carry_object(__DIR__"obj/sengyi")->wear();
}
int accept_fight(object me)
{
        command("say ���Ӷ��ڶ�������Ҳ��\n");
        return 0;
}
