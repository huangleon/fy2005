#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int estate();

void create()
{
    	set_name("Ҷ��",({"ye xiang","ye","yexiang"}));
	set("title",HIR"�����"NOR);
   	set("long","
Ҷ�豾�Ǹ���Ӣ���ܼ�ǿ���ˣ�ȫ�����ž������ű��˵ķ�â���ͺ���
һ��ĥ��ѩ���ĵ��������ڣ��������⣬��Ӣ�������ϵļ����ѽ����ɳۡ�
�����´����۾��ѱ�ð����޹⣬���ӿ�ʼ����͹���������������˻��
������\n");
   	
     	set("gender","����");
     	set("group","khlr");
     	
    	set("combat_exp",5100000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 		"����":		"���ϴ����ζ���õ�����ֵĵ�����\n",
 		"С��":		(: message_vision(CYN"Ҷ������ƺ��ֺ���һ�ڣ�����¶��ʹ��֮ɫ��\n"NOR,this_object()) :),
   	]));
    	
    	set("death_msg",CYN"
Ҷ�軺������������ֻ��һ�Σ�����˾�������������ÿ����һ���ж����ٻ�
����ô��һ�λ���ġ������㣬�Ȼ�������ʱ��ǧ��ĪҪ�������\n"NOR);  	
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		"Ҷ���Ц��������Ҳ��֪��Ϊ��ʲô����ֻ�Ǻ�Ȼ���ú�ƣ�룬ƣ���ʲô��
������ȥ�������ָо���Ҳ���ᶮ�ġ���\n",
		"����ȻЦ��Ц���������ϴ󻹿����Һ������ľ��Ѿ���ܶԵ������ˣ���ʵ��
��������������ֻ������򡣡�\n",
		"Ҷ�����ÿ���ˣ������Լ������ˣ�������˶����������˵İڲ���ֻ�к���
���ܷ������ܸı��Լ������ˣ���ֻ�����Լ�Ϊʲô���������ˡ���\n",
		"Ҷ��˵������Ҫ��ס���ϲ���ɱ�����ģ���\n",
    	}) );    	    	
    	
	auto_npc_setup("wang",250,180,0,"/obj/weapon/","fighter_w","bat-blade",1);
	
	setup();
    carry_object("/obj/armor/cloth")->wear();
    carry_object("/obj/weapon/blade",([	"name": "������",
    						"long": "һ��������������������ɵĸֵ�����\n",
    						 ]))->wield();    
 
}



