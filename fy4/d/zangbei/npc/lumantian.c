#include <ansi.h>
inherit SMART_NPC;
inherit INQUIRY_MSG;

int kill_him();

void create()
{
    	set_name("½����",({"lu mantian","lu"}));
	set("title","����");
	set("long","
���˵���ĸߴ󣬺ܿ�ΰ���ż�����ɫ�ĳ��ۣ����׵�ͷ�����˷��٣���
�ﶣ�����죬����������ö������\n");
   	
     	set("gender","����");
     	
    	set("age",72); 	 	
    	
    	set("combat_exp",8500000);  
    	set("attitude", "friendly");
    	
    	set("inquiry", ([
 				"��������":	(: kill_him :),
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
    	
	auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","longfenghuan",1);
	
	setup();
    	carry_object(__DIR__"obj/cyancloth")->wear();
	carry_object("/obj/weapon/hammer/tiedan")->wield(); 
}

int kill_him(){
	object me, ob;
	me = this_player();
	ob = this_object();
	
		if (!me->query_temp("marks/kuaihuo/�����_½����")) {
			message_vision(CYN"½����˵���Ҳ�֪������˵Щʲô��\n"NOR,ob);
			return 1;
		}
		
		if (REWARD_D->riddle_check(me,"��԰����")<8){
			command("haha");
			command("say ��һ�������԰��С�ӣ��繦δ����ȴ����ָ֤��½���죡");
			command("heng");
			return 1;
		}
		
		if (REWARD_D->riddle_check(me,"��԰����")== 9) {
			command("hehe");
			command("say �������ս�թ���Ƶ����ģ�������ı�����󶯣�");
			return 1;
		}
					
		message_vision(CYN"½�����Ŀ����䣬����$n�����˺ܾòų�������������֪����˭����Ҳ֪������
˭����Ȼ�ҵ������Ѿ�����ײ�ƣ����ǹ�ͬ�ĵ��������񲮣���ô�ͺ����ɡ�\n"NOR,ob,me);
		tell_object(me,WHT"\nanswer yes/no\n"NOR);
		me->set_temp("zangbei/lumantian_talk",1);
		add_action("do_answer","answer");
		return 1;
}

int do_answer(string arg){
	object me, ob;
	me = this_player();
	ob = this_object();
	
	if (!me->query_temp("zangbei/lumantian_talk"))
		return 0;
	
	if (!arg || (arg!="yes" && arg!="no"))
		return notify_fail("answer yes/no ");
	
	if (arg == "yes") {
		me->ccommand("touch "+ob->query("id"));
		message_vision(YEL"
$N���ͷ˵��������ˣ�������ȴ�ʱ�����в������������\n"NOR,me);
		REWARD_D->riddle_set(me,"��԰����",9);
//		me->set("marks/kuaihuo/½����",2);
		return 1;
	}
	
	if (arg == "no") {
		message_vision(YEL"
$N��ɫ���������ϲ����л�����԰���������㣿\n"NOR,me);
		me->kill_ob(ob);
		ob->kill_me(me);
		REWARD_D->riddle_set(me,"��԰����",10);
//		me->set("marks/kuaihuo/½����",1);
		return 1;
	}
	me->delete_temp("zangbei/lumantian_talk");
	return 0;
}


		
void die(){
	 object me, owner;
        if(objectp(me=query_temp("last_damage_from") ))     
        	if(owner=me->query("possessed")) {
			me = owner;
		
		} 
        
        if (me)
        if (REWARD_D->riddle_check(me,"��԰����")==10)
        	REWARD_D->riddle_set(me,"��԰����",11);
/*        
        if(me->query("marks/kuaihuo/ҹ����Ӱ"))
        {
                me->set("marks/kuaihuo/��԰�̿�",1);
        }*/
        ::die();
}	