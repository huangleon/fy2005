inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();

void create()
{
        set_name("���ݾ�", ({ "lin shoujuan","lin" }) );
        set("gender", "����");
        set("age", 55);
        set("long",
"���¸߹ڣ�����һ����׺����ĳ�����ͷ����Ȼ���ѻ��ף���������
�Ƿ����ʣ�ȫ����̬������\n"
);
        set("inquiry", ([
            "�����" : (: kill_him :),
             "��ź�" : (: fanghe :),
              "������" : (: peiyu :),
   	]));
      
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"���ݾ�Ц�����������޼��ŵ���������������С����������ģ���\n",
	 	"���ݾ�����õط�ѽ�õط���\n",
	}) );
	  
        set("attitude", "friendly");
        set("title","���ݴ��");
        set("nickname", HIG"�⻨��"NOR);

        set("reward_npc", 1);
	set("difficulty",5);
	set("class","swordsman");   
                
        set("combat_exp", 3500000);        
	set("class","swordsman");
   
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 200);
        set_skill("sword", 200);
        set_skill("parry", 150);
        set_skill("dodge", 150);
        set_skill("magic",150);
                
        set_skill("qidaoforce", 150);
	set_skill("shadowsteps",200);
	set_skill("yue-strike",200);
        set_skill("softsword",150);
        set_skill("perception",150);
        
        map_skill("unarmed","yue-strike");
        map_skill("force", "qidaoforce");
        map_skill("dodge","shadowsteps");
        map_skill("move","shadowsteps");
        map_skill("parry","softsword");
        map_skill("sword","softsword");

        set_temp("apply/armor", 30);
        setup();

	set("chat_chance_combat", 50);
        set("chat_msg_combat", ({
        	(: perform_action("sword.muyufeihong") :),
        }) );

//        add_money("gold", random(4));
        carry_object("/obj/weapon/sword")->wield();
	carry_object("/obj/armor/cloth")->wear();
	carry_object(__DIR__"obj/pozhi1");
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