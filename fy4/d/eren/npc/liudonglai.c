#include <ansi.h>
#include <command.h>
#include <condition.h>

inherit SMART_NPC;
int kill_him();

void create()
{

	set_name("������",({"liu donglai","liu","donglai"}));
    	set("title",YEL"��������"NOR);
    	set("long", "
һ��������������ˣ����źܿ������뷢���ѷ��ף�����ȴ���Ƿ�����棬
��������Ů�ˡ�������Ҳ�����úܺã���ָ�޳��������������������
�յ�����Ҳ���ڷ�������\n");

	set("age",59);
	set("combat_exp", 6400000);
        set("attitude", "friendly");
	
	set("inquiry", ([
             "������" : (: kill_him :),
       	]));

	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );

	auto_npc_setup("xuebin",250,180,0,"/obj/weapon/","fighter_w","softsword",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/weapon/sword/sword_liu")->wield();    
}


int kill_him()
{
        object me, another;
        
        me = this_player();
 		if (this_object()->is_fighting()) {
 		tell_object(me,"����������û�ջش��㡣\n");
 		return 1;
 		}
        message_vision(CYN"
�������������Ǵ����������£���Ȼ�����������䣬���������ص�ʮ����ǰ����
���ǻ���ͬ�����ġ���������Ϊ������ʵ�ڲ��Ǹ�������������Ϊ�˸�Ů�ˣ�
���������磬���������ҵģ����ǰ�����ȴ������Ȩ�ƺ�Ǯ�ƣ�ǿռ��������\n"NOR,this_object());
        return 1;
}