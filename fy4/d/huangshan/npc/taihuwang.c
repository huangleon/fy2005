inherit SMART_NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();

void create()
{
        set_name("������", ({ "wang zhenxiang","wang" }) );
        set("gender", "����");
        set("age", 55);
        set("long","̫����ʮ�Ķ���ܶ��������������ү�ӡ�\n");
        set("inquiry", ([
            	"�����" : (: kill_him :),
             	"��ź�" : (: fanghe :),
              	"������" : (: peiyu :),
   	]));
      	 	   	
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"������Ц�����������޼��ŵ���������������С����������ģ���\n",
	 	"����������õط�ѽ�õط���\n",
	}) );
	  
        set("attitude", "friendly");
        set("title","̫����");
        set("nickname", HIG"ˮ�ϴ��"NOR);
        set("score", 0);
        set("reward_npc", 1);
		set("difficulty",5);
	
		set("class","yinshi");
                       
        set("combat_exp", 4000000);        
        
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(20) :),
        }) );
    	
    	    	
    	auto_npc_setup("wang",180,175,0,"/obj/weapon/","fighter_w","thunderwhip",1);
		setup();
    	
		carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/w_whip")->wield();
		if (!random(10)) carry_object(BOOKS"whip_75");
}

 
int kill_him()
{
        object me;
        me = this_player();
        command("say ������֪�����治�٣��� \n");
        this_object()->kill_ob(me);
        me->kill_ob(this_object());
        return 1;
}

int fanghe()
{
    command( "say �ź������������޼��ŵ������ˡ�");	
    return 1;
}


int peiyu()
{
    command ("say ��С���������ֲ��ɲĵĶ��ӡ�");
    return 1;
}
