inherit SMART_NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();

void create()
{
	object armor;
        set_name("����¥", ({ "wang yulou","wang" }) );
        set("gender", "����");
        set("age", 55);
        set("long","�����齭�������崫�ĺ���һ��Ũü���ף�����������������ˡ�\n");
        set("inquiry", ([
            "�����" : (: kill_him :),
             "��ź�" : (: fanghe :),
              "������" : (: peiyu :),
   	]));
      	 	   	
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"����¥Ц�����������޼��ŵ���������������С����������ģ���\n",
	 	"����¥�����õط�ѽ�õط���\n",
	}) );
	  
        set("attitude", "friendly");
        set("title","���ϴ���");
        set("nickname", HIG"�屡����"NOR);
        set("score", 0);
        set("reward_npc", 1);
		set("difficulty",5);
		set("class","beggar");
        
        set("combat_exp", 4500000);        
               
	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
     }) ); 		

	auto_npc_setup("wang",200,170,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();

	armor=new("/obj/armor/cloth");
	armor->set_name(HIY"�������컷����"NOR,({"cloth"}) );
	armor->move(this_object());
	armor->wear();
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