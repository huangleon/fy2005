#include <ansi.h>
inherit SMART_NPC;

void create()
{
	set_name("�Ŷ���",({"gudong san","gudong"}));
	set("long", "һ��ͷ����Щ���׵�С��ͷ���������۾���µµ��ת��\n");
	set("nickname",YEL"�ᱦ���"NOR);
	set("age",30+random(20));
	set("attitude", "friendly");
	set("combat_exp", 5000000);
	set("gender","����");
	
	set("inquiry", ([
   		"�Ͼ���ʯ":		"��ʯ���������ҿ�����\n",
   		"��ˮ�ĸ���":	"�������ס�˿�һ�����ˣ�û�������ˮ��\n",
   		"����֮��":		"����֮�������ţ�һ��һ�ƣ��������������֮����֮����\n",
   		"������":		"�������������£�����������һ��ȥ�ݷðݷá�\n",	
   		"Ӣ����":		"��������������˹������\n",
   		"�ᱦ���":		"������������\n",
   	]));
   	
   	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
     }) );
   	
   	auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","thunderwhip2",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	carry_object("/obj/armor/hat",([	"name": "��ʽձñ",
    						"long": "һ������΢�ݣ���ͷ�����ձñ���ƺ��ǲ���Ʒ��\n",
    						"value": 0,
    						 ]))->wear();    
	carry_object("/obj/weapon/whip",([	"name": "��Ƥ��",
    						"long": "һ��������Ƥ�ޣ�����ʱ���Ծ������䡣\n",
    						"value": 0,
    						 ]))->wield();   
}


int accept_object(object who, object ob)
{
	object stone;
	if(ob->query("name") == WHT"����"NOR) {
 	 	if (REWARD_D->riddle_check(who,"�Ͼ�֮��")!=3) {
 	 		command("say �ٵġ��ٵġ���ֵһ�ģ�");
 	 		return 0;
 	 	}
 	 	command("giggle");
 	 	command("say ��������ϱ�����ĵ��ˣ�����ʯ���ü�ˮ�ݳ����ģ���ֵ���ģ�");
 	 	message_vision(CYN"$N���۾���µµ��һת��\n",this_object());
 	 	command("say ���������Ȼ�ҵ����ˣ��ɲ��ܽ��Ҳ���֮��˵��ȥ��");
 	 	command("say ��ϱ��������ʲô���ã����ǡ���̫���������ˣ��ҵ��������������");
 	 	command("say ����Ҫ�Ұ�ʲôæ�Ϳ��ڰɡ�");
 	 	REWARD_D->riddle_set(who,"�Ͼ�֮��",4);
 	 	return 1;
 	 }
 	 
 	 if (ob->query("name") == HIM"�Ͼ���ʯ"NOR&& ob->query("jile")==1){
 	 	if (REWARD_D->riddle_check(who,"�Ͼ�֮��")!=4) {
 	 		command("say ��������������������֣�����ɱ��֮����");
 	 		return 0;
 	 	}
 	 	message_vision(CYN"$N�����۾����˿�"+ob->name()+CYN"���ٺٵ�Ц��������\n"NOR, this_object());
 	 	message_vision(CYN"$N˫��һ������ž��һ����Ȼ��"+ob->name()+CYN"���������룬
���ѵ���ʯ�£���Ȼ��һ����Ѱ��С�ı�ʯ��ɢ�������ĵ��Ϲ⡣\n"NOR,this_object());
 	 	command("say С�ӣ��������ڱ�ɽ��ʶ������");
 	 	command("say ������������������У�����ǰΪ��������û�뵽��Ȼ���䵽������С�");
 		REWARD_D->riddle_done(who,"�Ͼ�֮��",20,1);
 		stone = new("/obj/gem/stargem2");
 		stone->set("item_owner", who);
 		stone->move(who);
 		return 1;
 	}
 			 	
 	command("say �ҹŶ���ֻ�����˵Ķ��������˵��Ҳ�Ҫ��");
 	return 0; 	
 	 	
} 

	
		