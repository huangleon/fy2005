inherit SMART_NPC;
#include <ansi.h>
void create()
{
    	set_name("����" , ({ "jian chi","jian" }) );
    	set("long", "�򽣶��գ�Ϊ�����ա�\n");
		set("attitude", "friendly");
    	set("age", 62);
        set("gender", "����" );
        create_family("���Ƴ�",1, "����");
    	set("per",4);
    	set("combat_exp", 4000000);

    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(80) :),
	     		CYN"����ɵЦ�����ǺǺǺǡ���������������ฺ������������ٺٺ١���\n"NOR,
        }) );


		set("chat_chance", 1);
        set("chat_msg", ({
        	"����ɵЦ�����ǺǺǺǡ���������������\n",
        	"����ɵЦ����ฺ������������ٺٺ١���\n",
        
        }) );
    	auto_npc_setup("ouyang",200,180,0,"/obj/weapon/","fighter_w","feixian-sword",1);


		setup();
        carry_object(__DIR__"obj/mayi")->wear();
        carry_object(__DIR__"obj/chengyin")->wield();
}



/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
