#include <ansi.h>
#include <command.h>

inherit SMART_NPC;
int letter();

void create()
{

		set_name("��Ц",({"chang xiao","chang","xiao"}));
    	set("nickname","����");
    	set("title",WHT"�Ĵ�����"NOR);
    	set("long", "
�����Ϲ���Ц�ݣ��Ͱ���Ц�ݣ���ò����һ���������ò����ʹ�����˹ٷ�����Ҳ
���ԵúͰ����ס���˭�뵽������һ���ˣ������ģ����Ľ������ȶ��߻��ݶ�����
���겻����ʮ���꣬����ݹ�������ʮ�꣬���������ϵ���ȴ�ѹ�ǧ��ƽ��ÿ���գ�
����һ�������������ϡ�֪����Щ�µ��ˣ��ǲ����Ծ������Ͱ����ף�\n");
		set("age",47);
		set("combat_exp", 9000000);
        	
		set("reward_npc",10);
		set("ssrm_7hit",1);  
		
		set("inquiry", ([
        	"tie hen" : 	"�������飬�ٺ٣��ҵ�Ҫ�����������Ǹ�ʲô��ɫ��\n",
           	"����" : 		"�������飬�ٺ٣��ҵ�Ҫ�����������Ǹ�ʲô��ɫ��\n",
   			"�鱦": 	(: letter :),
   			"̫ƽ����":	(: letter :),
   			"����":			"��ʮ���������е��ֶ����������֣�û�����鲻����������\n",
   			"��":			"��ʮ���������е��ƴ�����ҩ���֣�û�����ϲ������Ķ�ҩ��\n",
   		]));
    	
    	
    	set("chat_chance",1);
    	set("chat_msg",({
			"��Ц��Ц������̫ƽ�����鱦һ�����ǲ��ˮ��ʯ�����ɡ�\n",
    	}) );  
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
	     	10: 	"\n��Ц����������ĳ���˵��ʺ�֮����������һ��Ѫ���ˣ�\n",
        ]) ); 
		set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(30) :),    
        }) );
	
    	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","sharen-sword",1);
	
		setup();
		carry_object(__DIR__"obj/o_cloth2")->wear();
		carry_object(__DIR__"obj/o_sword")->wield();
}


int letter(){
	
	command("heihei");
	command("say ̫ƽ�����鱦ʧ��һ�����ɵ����࣬ʲôѪ��������������һ�ɺ��ԡ�");
	command("say ����ǰ�����鱦�ڴ����������г��֣�û�뵽���ڹ���δ�ʳ��������
��"YEL"��"CYN"������������Ѷ���ģ���Ȼ���Ĵ������е����ޣ�");
	command("say �����޾�ȻҲ���ˣ���˵��������Ѫ�������С�");
	command("say �ҵ��˵أ�����Ҫ�Ѵ˰����ˮ��ʯ����");
	command("say ����"YEL"����"CYN"����Ҳ�ܽ����ſڣ�");
	
	this_player()->set("marks/parrot/��Ц",1);
	return 1;
}
	
	