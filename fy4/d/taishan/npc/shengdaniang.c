inherit SMART_NPC;
#include <ansi.h>

void create()
{
        set_name("ʢ����", ({ "sheng daniang","daniang" }) );
        set("nickname",HIR "ɢ����Ů" NOR);
        set("gender", "Ů��");
        set("age", 65);
        set("long","��ͷ������˿��ʢ��ׯŮ���ˣ������˳ơ�ɢ����Ů����ʢ���\n");
      
      	set("chat_chance", 1);
		set("chat_msg", ({
		 	"ʢ����˵��������ϱ��һ������һ�������ڴ������˵���������������ʮ���궼��Ը��Ȣ���ˡ�\n",
		}) );
	  
        set("score", 2000);
        set("class", "huashan");
        set("reward_npc", 1);
		set("difficulty", 5);
        
        set("combat_exp", 3700000);        
                
        set("chat_chance_combat", 100);
   	 	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
     	}) ); 		

		auto_npc_setup("wang",180,160,0,"/obj/weapon/","fighter_w","tanzhi-shentong",1);
        setup();
        carry_object(__DIR__"obj/n_stone")->wield();
		carry_object("/obj/armor/cloth")->wear();
}
