#include <ansi.h>
inherit SMART_NPC;
void create()
{
        set_name("ǳǳ", ({ "qian qian","qian" }) );
        set("gender", "Ů��" );
        set("title", "���");
        set("nickname",HIG"ਰ��Ƽ�һյ�裬�Կ����Ʋ���ϼ"NOR);
        set("age", 22);
        set("long", "ǳǳ��΢Ц��ǳǳ����裬ǳǳ�����ᡣ\n");
        set("combat_exp", 1400000);
        set("chat_chance", 1);
        set("chat_msg", ({
        "ǳǳ����һЦ������˵����ݴ����ڶ�ͥ��ë�峤�ڻ�ɽ������������������
�Ҳ��������ģ��������ڰ��Ƶ���ѽ��ȴ�Ǳ����������\n",
	}) );
        set("attitude", "friendly");
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",120,120,0,"/obj/weapon/","fighter_w","taiji",1);
        setup();
        carry_object("/d/jinan/npc/obj/changbao")->wear();
}


int accept_fight(object me)
{
        command("say СŮ�����е����ǧ�����⣬СŮ�Ӹ�����Ҿ������ǡ�\n");
        return 0;
}
