#include <ansi.h>
inherit SMART_NPC;

int answer();

void create()
{
        set_name("ʯ��", ({ "shi tuo","shituo" }) );
        set("title","��������");
        set("gender", "����" );
        set("age", 42);
	set("long","
�����ݵĴ󺺡�����������Ƥ���ģ�¶��һ��������ڡ�����ʵ�ļ�����
��һ���������Ƿ���˵Ľ���Ƥ��͹͹������û�а��⻬�ɾ��ĵط���
�ٿ���һ˫�۾��������ɵģ���ֱ���۰׺������Ӷ��ֲ�������˭Ҳ��
�������ϻ����������������۾������۾����ڵ����㣬ȴ�ֺ���û��
�Ƽ����Ƶģ��۾������Ƴ���а����ȴ���ƿն���ʲô��û�С�\n");
		set("combat_exp", 6400000);
		set("class","beggar");
		set("reward_npc",1);
		set("difficulty",3);
        
		set("inquiry",([
			"ɳĮ": (: answer() :),
			"desert": (: answer() :),		
		]));
	
		set("chat_chance_combat", 100);
	    set("chat_msg_combat", ({
		     (: auto_smart_fight(70) :),
	        }) );
        	
		set("attitude", "friendly");
      	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","dragonstrike",1);
        setup();
        carry_object(__DIR__"obj/scloth")->wear();

}


int answer(){
	message_vision("ʯ�ղ��Բ���������ƣ����������ָ������ǰ���˻Ρ�\n",this_object());
	return 1;
}


