#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int test(int num);

void create()
{
    	set_name("���Ի�",({"hunter zhang","zhang","hunter"}));
    	set("title","�ٲ�����");
    	set("long","
һ�����ɵĺ��ӣ�����С����������ϸϸ������һ���������ɡ����Ի���
��������������������������ٲ�����Ĺ���������Ϊ���ó�ѱ�ޣ�����
ʹ������\n");
    	
    	set("gender","����");
    	set("age",32);
    	 	
    	set("combat_exp",4000000);  
    	set("attitude", "friendly");
    	
    	set("death_msg",CYN"\n$N��̾һ��˵�������ӳ����ӥ�������ȴ��Сȸ��Ϲ���ۡ��� \n"NOR);
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n���Ի�˵��ɱ����������ʵ�ˣ��㲻�ú�����������\n",
        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"���Ի��������õİ�����֦��������ɹ��Σ���������Ȼ��˸����ơ�\n",
    	}) );    	    	

		auto_npc_setup("wang",200,160,0,"/obj/weapon/","fighter_w","xinyue-dagger",1);
	
	
		setup();
    	carry_object("/obj/armor/cloth")->wear();    
    	carry_object(__DIR__"obj/shuzhi");  
    	carry_object(__DIR__"obj/hdagger")->wield();  
}


