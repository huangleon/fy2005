#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void goaway();

void create()
{

		set_name("����ׯ��",({"blacksuit guard","guard"}));
    	set("title",WHT"���ׯ"NOR);
    	set("long", "׷Ѳ��ׯ�ڵĺ��´󺺣�����֮����Ѫ�߲������ǵ���ͫ�������Ѫ��\n");
		
		set("group","li_guard");
		set("age",40);
		set("combat_exp", 8000000);
        
        set("chat_chance", 50);
        set("chat_msg", ({
			(: goaway :),	
        }) );
        	
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
				
		setup();
		carry_object("obj/armor/cloth",
						([	"name": "���ׯׯ��",
    						"long": "һ����ɫ��ׯ����\n",
    					 ]))->wear();
}


void goaway()
{
	object ob,me;
	object *inv;
	int i;
	
	if (!environment())	return;
		
	inv = all_inventory(environment());
	
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]->query("sanye")){
    			kill_ob(inv[i]);
    			inv[i]->kill_ob(this_object());
    	}
    }
    
    if (objectp(me= query("mission_target"))) {
    	if (environment(me)== environment()) {
    		kill_ob(me);
    		me->kill_ob(this_object());
		}
	}
	
	if (is_fighting())	return;
	
	environment()->delete("in_mission");		
	message_vision(YEL"$N˵�������ѱ����ˣ���ʤ��ʤ������$N����ׯ����ʧ��\n"NOR,this_object());
	
	if (objectp(me)) 
		tell_object(me,HIR"�������ׯ���ж�ʧ���ˣ�����\n"NOR);
	
	
		
	destruct(this_object());
}


void die(){
	
	object me, middle, young;
	int count;
	object *inv;
	int i;
	
	if (!environment())	return;
		
	inv = all_inventory(environment());
	
	for (i=0;i<sizeof(inv);i++) {
		if (inv[i]== this_object())	continue;
		if (inv[i]->query("group")=="li_guard"){
    			::die();			// have a friend alive.
    			return;
    	}
    }
        
	if (!objectp (me = query("mission_target"))) {
		command("say �ٺ٣����Ƕ������ˣ�ĳ���������٣�");
		::die();
		return;
	}
	
	if (! (count = query("count")))	{
		command("say bugged no count");
		::die();
		return;
	}
	
	count++;
	
	if (count< 4) {
		command("say ���ˡ����ˡ���������ס�ˣ�");
		message_vision(BLU"\nֻ���಼�����ׯ���������˼���ׯ����\n"NOR, this_object());
		message_vision(BLU"����ׯ���е����������Ŀ�ͽ���������ׯ����ô��\n"NOR, this_object());
		environment()->init_mission(count, query("combat_exp"), me);
		::die();
		return;
	}
	
	if (young = present("young man")) {
		message_vision(CYN"\n����������������У������Ц��һ����һ����Ծ����ׯ�С�\n"NOR, young);
		destruct(young);
	}
	
	if (middle = present("middle age man")){
		message_vision(CYN"\n$N˵������ȥ"NOR+YEL"�ر�"CYN"��ү����������������ˣ�˵�ձ����������ׯ�С�\n"NOR, middle);
		destruct(middle);
	}
				
	if (objectp(me)) {
		if (REWARD_D->riddle_check(me,"�Ѫ����")==11)
			REWARD_D->riddle_set(me,"�Ѫ����",12);
		if (me->query("marks/quest/���ׯ"))
			me->set("marks/quest/���ׯ",2);
		environment()->delete("in_mission");		
		tell_object(me,HIR"\n�������ׯ�ļƻ����ɹ����������"NOR+YEL"�ر�"HIR"����ү��"NOR);
	}
		
	::die();
}
	