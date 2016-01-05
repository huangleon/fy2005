#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�й�", ({ "jia gun", "jiagun" }) );
        set("long",
                "�й�����һ�������Ĳ�ͷ���������ͺ���ֻ��Ƥ���Ź�ͷ����û�б�
�飬Ҳû���⡣�۾���ɭɭ�ģ���С���������ϼ��������ǵ�ʵ��Ҫ
�����Ƴ�����Ҳ����ƨ��Ҫ���ų�����\n");
    	set("chat_chance",1);
	set("chat_msg",	({
		"�й���ɭɭ�������㣬�������������ʾ������������У��Ϳ��õ�
���ƣ�������׽�÷�����鰸���������͡���\n",
	})  );

        set("combat_exp", 350000);
		
		set_skill("dodge",100);
		set_skill("move",100);
		set_skill("shenji-steps",80);
		set_skill("staff",100);
		set_skill("fumostaff",100);
		set_skill("parry",100);
	
		map_skill("staff","fumostaff");
		map_skill("dodge","shenji-steps");
		map_skill("move","shenji-steps");
			
		setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/shawei")->wield();
}


void init(){
	::init();	
    	if( !query_heart_beat(this_object()) ) set_heart_beat(1);
	add_action("do_accept", "accept");
}


void heart_beat()
{
	object ob,me;
	
	if(me = query("test_target"))
	if(query("accept_test")==1)
	{
		say("\n�й����˵�ͷ��˵�����ܺã����ǵ�һ��....\n\n");
       		COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
                
        	if( me->query_temp("last_damage_from") ==this_object() || !present(me, environment())) 
        	{
        		say("�й���м��˵��������һ�ж��Ų���������̫����....\n");
                	delete("accept_test");
        	}
        	else add("accept_test",1);
       }
       else if(query("accept_test")==2)
       {
       	        say("\n�й�˵�������ǵڶ���....\n\n");
        	COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
        	if( me->query_temp("last_damage_from") ==this_object() || !present(me, environment())) 
        	{
			say("�й����ߡ���һ����˵������㹦��Ҳ�ҳ�����....\n");
                	delete("accept_test");
        	}
        	else add("accept_test",1);
        }
        else if(query("accept_test")==3)
        {
        	say("\n�й�˵��������������....\n\n");
        	COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
        	if( me->query_temp("last_damage_from") ==this_object() || !present(me, environment())) 
        	{
         		say("�й�������ȥ��������....\n");
         	       	delete("accept_test");
        	}
        	else add("accept_test",1);
        }
        else if(query("accept_test")==4)
        {
                say("\n�й�����Ц��˵�������и������İ����ˣ�\n\n");

       	ob = new(__DIR__"obj/yaopai");
		ob->move(me);

		write("�й���"+me->query("name")+"һ�����ơ�");
		me->set_temp("yaopai",1);
		say("\n�й�˵���������ƾ����������ɳ��롣�����˿��������������֪������Э���참���ˡ�\n");
		say(HIG"�й�˵��������Ҫ�Ļ�������Ҳû��������Ǹ�������ϵ����ˣ�����ɽ��������ȥ��\n\n"NOR);
		delete("accept_test");
        }
        ::heart_beat();
}


int do_accept(){
    	mapping guild;
		object ob;
	        
    	if(!this_player()->query_temp("jiegaoshi")){
      		return 0;
    	}
		if(query("accept_test")){
			return notify_fail("�й�����æ���Ժ�һ�¡�\n");
		}
    	set("accept_test",1);
    	set("test_target",this_player());
    	this_player()->delete_temp("jiegaoshi");
    	if( this_player()->query_temp("last_damage_from")) {
        	this_player()->delete_temp("last_damage_from");
    	}
		heart_beat();        
        return 1;
}

/*
void die(){
	object ob;
	object *enemy;
	
	ob = query_temp("last_damage_from");
	if(!ob) { 
		enemy = this_object()->query_enemy();
		if(sizeof(enemy))
			ob=enemy[0];
	} else {
		if(userp(ob)) { 	
			ob->set_temp("marks/killjia",1);
		}
	}
	::die();
}
				
*/