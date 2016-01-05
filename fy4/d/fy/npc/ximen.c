inherit NPC;
#include <ansi.h>
int kill_him();
int fanghe();
int peiyu();
void smart_fight();

void create()
{
        object armor;
        set_name("���ŷ�", ({ "ximen feng" }) );
        set("gender", "����");
        set("age", 65);
        set("long","��λ�ų������µ�һ���������������������㣬������
���ž��ȣ�Ҳ������������\n" );
        set("inquiry", ([
            	"�����" : (: kill_him :),
             	"��ź�" : (: fanghe :),
              	"������" : (: peiyu :),
   	]));
      
      	set("chat_chance", 1);
	set("chat_msg", ({
	 	"���ŷ�Ц�����������޼��ŵ���������������С����������ģ���\n",
	 	"���ŷ�����ò�ѽ�ò裡\n",
	}) );
	  
        set("attitude", "friendly");
        set("title",HIY"éɽ"NOR);
        set("nickname",HIY"�����޹�"NOR);
        set("score", 10000);
        set("reward_npc", 1);
	set("difficulty",5);
	set("class","lama");
        set("no_busy",6);
        
        set("toughness",150);
        
        set("combat_exp", 2500000);        
        
        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
               (: smart_fight() :),
        }) );

	set_skill("perception", 150);          
        set_skill("move", 200);
        set_skill("force", 200);
        set_skill("spells", 150);
        set_skill("unarmed", 180);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("magic",150);
        set_skill("bloodystrike", 200);
	set_skill("iron-cloth",1000);
	set_skill("kwan-yin-spells",130);
	        
        map_skill("unarmed","bloodystrike");
        map_skill("iron-cloth","xisui");
	map_skill("spells","kwan-yin-spells");        
        
        set_temp("apply/dodge", 30);
        set_temp("apply/armor", 30);
        setup();

//        add_money("gold", random(5));
        armor=new("/obj/armor/cloth");
	armor->set_name(HIW"������"NOR,({"cloth"}) );
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

smart_fight()
{
	int i,num;
	object *enemy, who;
	who = this_object();
	if (who->is_busy()) return;
	enemy = this_object()->query_enemy();
	for(i=0;i<sizeof(enemy);i++)
	{
		if (enemy[i]->is_zombie() && random(2))
		{
			who->cast_spell("ni");
			return;
		}		
	}
	return;
}