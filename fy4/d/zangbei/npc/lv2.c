#include <ansi.h>
inherit SMART_NPC;

int recruit();

void create()
{
    	set_name("���㴨",({"lv xiangchuan","lv"}));
	set("title",WHT"���ʱ��"NOR);
	set("long","
���㴨�Ǹ���ɫ�԰ף����ʱ����ˡ����Ա���������͹�������������
��Ϊ����û��ʲô�˲������ִ��󲻵���Ц�����ҿ��¡����㴨����
����������������֣�Ҳ��������������ڰ�������֮һ��������
���ڻ���һ��İ�����������Ҳû���κ����ܱȵ���������\n");
   	
     	set("gender","����");
     	
    	set("age",32); 	 	
    	
    	set("combat_exp",6400000);  
    	set("attitude", "friendly");
    	
   	set("inquiry", ([
		
   	]));
    	
    	set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([

        ]) );    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(30) :),
        }) );
    	set("chat_chance",1);
    	set("chat_msg",({
		
    	}) );    	    	
    	
	auto_npc_setup("wang",200,200,0,"/obj/weapon/","fighter_w","tanzhi-shentong",2);
	set_skill("tanzhi-shentong",160);
	setup();
    	carry_object("obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/throwing/qixing")->wield();
 
}


void die(){
	object owner, me, laobo;
	if(objectp(me=query_temp("last_damage_from") ))     
        if(owner=me->query("possessed")) {
		me = owner;
	}
	if (me) {
		
		if (me->query_temp("marks/kuaihuo/��ɱ���㴨")) {
			me->delete_temp("marks/kuaihuo");
			if (laobo = present("sun yubo",environment(me)))
				 laobo->thank_you(me);
			me->delete_temp("marks/kuaihuo");	
			REWARD_D->riddle_set(me,"��԰����",14);
		}
	}
	::die();
}
