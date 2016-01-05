#include <ansi.h>
#include <command.h>
#include <condition.h>

inherit SMART_NPC;
int kill_him();

void create()
{
	set_name("����ʦ̫",({"liaoyin"}));
    	set("title",YEL"÷��������"NOR);
	set("long", "
һ�����°�������ᣬ˫�ֺ�ʲ����վ�ڴ��ǰ��ʯ���Ͽ����㡣�����˸�
���������Ҷһ�������ϿݻƵ����ϣ������˼�į��ʹ�ĺۼ����������е�
���֣�ȫ�Ѿ�����̫Զ��Ҳ̫���ˡ����������۾��ȴ���Ǵ���һ˿ϣ��
֮ɫ��\n");
	set("gender","Ů��");
	set("age",59);
	set("combat_exp", 5500000);
        set("attitude", "friendly");
	
	set("inquiry", ([
//             "������" : (: kill_him :),
//             "�һ�����" : (: kill_him :),
      	]));
	
	set("reward_npc",1);
	set("difficulty",5);
		
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(70) :),    
        }) );
	
	
	auto_npc_setup("liaoyin",200,200,0,"/obj/weapon/","fighter_w","necromancy",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/necklace",([	"name": "̴ľ����",
    						"long": "һ��̴ľ�������ɵľ�����\n",
    						"value": 1,
    						 ]))->wear();    
}


int kill_him()
{
        object me, another;
        
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"����ʦ̫����û�ջش��㡣\n");
 		return 1;
 		}
        message_vision(CYN"$N���Ϻ�Ȼ¶�����䵭�����ص�΢Ц������Ц�ݱ����ó������ϵġ�\n"NOR,this_object());
        message_vision(CYN"$N����Ц�ŵ������ҵ���ʮ���꣬�Ҿ�֪��һ���������������ģ�����
�ҹ�Ȼ�ȵ��ˡ���\n"NOR,this_object());
        another = new(__DIR__"taohua");
	another->move(environment(this_object()));
        destruct(this_object());
        return 1;
}