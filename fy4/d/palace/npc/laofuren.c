inherit SMART_NPC;
#include <ansi.h>
void create()
{
        set_name("���ϸ���", ({ "old woman" }) );
        set("nickname",HIR "������" NOR);
        set("gender", "Ů��");
        set("age", 85);
        set("long","��������������Ԫ����ˣ���������Ȼ���ݲ��ϣ���˫Ŀȴ����ӥ��������
֮�䣬ɢ����һ����������Ĺ�ʣ������ľ���\n");

      
      	set("chat_chance", 1);
		set("chat_msg", ({
	 		"�ϸ������������۹⿴���㣬��ֻ���ò���������\n",
		}) );
	  
        set("attitude", "friendly");
        set("score", random(20000));
        set("class", "huashan");
        set("reward_npc", 1);
		set("difficulty", 5);
        set("combat_exp", 4800000);        
        
        set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     	}) ); 		

		auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","tanzhi-shentong2",1);
        setup();

        carry_object(__DIR__"obj/b_stone")->wield();
		carry_object(__DIR__"obj/b_skirt")->wear();
		if (!random(10)) carry_object(BOOKS"throwing_75");
}