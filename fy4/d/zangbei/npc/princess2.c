inherit SMART_NPC;
#include <ansi.h>

void create()
{
	set_name("���ù���", ({ "princess" }) );
	set("title","����");
	set("gender", "Ů��" );
	set("age", 22);
	set("per",100);
	set("class","baiyun");
	set("group","guizi");
	set("long","
���������������ڰ�͸����ɴ���к������֣������̲�ס��࿴���ۡ���
������������ת������Ȼ�ݺ��ֻ����������΢΢����Щ��ɬ����������
ٯ��Ů����ѧ���\n");
	set("combat_exp", 6400000);
	set("attitude", "friendly");
	set("chat_chance",1);
	set("chat_msg",({
		"���ù�����Ц������͵�����ˣ����ѵ�����û�п����᣿��\n",
    	}) );  
    	
    set("chat_chance_combat", 100);
       set("chat_msg_combat", ({
	       	(: auto_smart_fight(60) :),    
     }) );
        
    auto_npc_setup("xuebin",250,200,1,"/obj/weapon/","fighter_w","musician",1);
	set_skill("music",250);
	setup();
	carry_object(__DIR__"obj/pcloth")->wear();
	carry_object(__DIR__"obj/dsword")->wield();

}
	