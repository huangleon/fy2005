#include <ansi.h>
inherit SMART_NPC;


void create()
{
    	set_name("�ϼ���",({"lao jiaren","jiaren"}));
	set("title","Ѧ��ׯ");
   	set("long","
һ���׷��ԲԵ��ϼ��ˣ��������͡�����ʱ����Ѧ�����ͯ����Ѧ���ѽ���
ʮ�ꡣ����ʱ����Ҳ�Ǹ���׳��С���ӣ�Ҳ�������ʮ���ص�������Ҳɱ��
Щ���ֺú��������ڣ������������գ������䣬���ϵļ������ɳڣ����һ�
�������������߼���·���ᴭ������\n");
     	set("gender","����");
    	set("age",72);
    	 	
    	set("combat_exp",4000000);  
    	set("attitude", "friendly");
    	    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
	
    	}) );    	    	
    	    	
	auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","xuanyuan-axe",1);
	
	setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/jiapu");
    	
}
