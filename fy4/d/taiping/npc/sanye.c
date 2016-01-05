inherit SMART_NPC;
#include <ansi.h>

int do_help();
int do_cont();

void create()
{
    	set_name("����ү",({"wu sanye","wu","sanye"}));
    	set("title",HIR"����"NOR);
    	set("long","
��ү���䣬����ɽ���������û�˸ҽ��������֣��ҽе��˵ڶ����ʲô��
�ֶ��в������ˡ�����үʲô�����ɣ�ֻ����̫ƽ����ط���һ�������ġ���\n");
    	set("gender","����");
    	set("age",52);
		set("combat_exp", 9000000);
        set("attitude", "friendly");	
	
		set("reward_npc",20);
	
		set("inquiry", ([
        	"�ϴ�":		"action����ү������ζ���Ц��Ц��\n",
        	"����":		(: do_help :),
        	"����":		(: do_help :),
        	"job":		(: do_help :),
        	"�ر�":		(: do_cont :),	
   		]));
   		
    	set("chat_chance",1);
    	set("chat_msg",({
			"����ү΢Ц���������м����������Ǹ������ˡ������������˶�����������\n",
			"����ү���ͷ̾Ϣ�ŵ���Ů�����ǱȽ϶��ɵģ���������������Ů�ˣ���һֱ��\n��Ϊ��Ҫɱ��������\n",
    	}) );
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
		 (: auto_smart_fight(40) :),
        }) );
    	
		auto_npc_setup("wang",300,200,0,"/obj/weapon/","fighter_w","dragonstrike",1);
		setup(); 
    	set_skill("yijinjing",200);
    	set_skill("iron-cloth",200);
    	map_skill("iron-cloth","yijinjing");
    	carry_object(__DIR__"obj/bluecloth2")->wear();  
}


void init() {
	
	object ob;
	::init();
	add_action("do_answer","answer");
	if( interactive(ob = this_player()) && REWARD_D->riddle_check(ob,"�Ѫ����")==8) {
		remove_call_out("greeting");
		call_out("greeting", 1, ob);
	}
}


void greeting(object ob) {
	
	if( !ob || environment(ob) != environment()) return;
	
	tell_object(ob,CYN"
����ү�������žƱ���������һ���ƣ����̷ҷ������ڴ��ߡ�

����ү��Ŀ������������ϣ�������˵���ܺã������ڵ��㣬

��Ϊ����Ҫ�ҵ�"YEL"����"CYN"��

������˭Ҳ�ﲻ���㣬��Ц���ܣ����Ӻ�Ҳ���ܡ�\n\n"NOR);
	if (REWARD_D->riddle_check(ob,"�Ѫ����")==8)
		REWARD_D->riddle_set(ob,"�Ѫ����",9);
	return;
}
		
	
int do_cont(){
	
	object me;
	
	me = this_player();
	
	if (REWARD_D->riddle_check(me,"�Ѫ����")!=12 && !me->query("marks/quest/���ׯ"))
		return 0;
	
	if (me->query("marks/quest/���ׯ")==1){
		command("say ������ȥ���³ɺ�����"YEL"�ر�"CYN"!");
		return 1;
	}
	
	if (me->query("marks/quest/���ׯ")==2) {
		QUESTS_D->special_reward(me,"�������ׯ");
		me->delete("marks/quest/���ׯ");
	}
	
	
	tell_object(me,CYN"����ү�����۾�˵���ܺá��ܺá�
����ү˵������ׯ����ʵ�Ǹ����ӣ�Ŀ�����������ׯ��ע��������Ҳ���Կ���
���Ǹ�����֮�ˡ���������������ȥ����ɴӳ������ҷ��֮ʱ����ׯ��Ǳ�룬
ɱ�������ֲ����������������ߣ��ɿ����ׯ�����ţ��м��мǡ�\n"NOR);

	if (REWARD_D->riddle_check(me,"�Ѫ����")==12) 
		REWARD_D->riddle_set(me,"�Ѫ����",13);
	
	REWARD_D->riddle_done(me,"�Ѫ���ׯ",20,1);		// �Ӵ˿ɽ���
	
	return 1;
}


	
	
	

	
		

int do_help() {
	
	int pass;
	object me;
	
	me = this_player();
	
	if (REWARD_D->riddle_check(me,"�Ѫ����")==10 || REWARD_D->riddle_check(me,"�Ѫ����")==11
		|| me->query("quest/quest")== "�������ׯ") {
		tell_object(me,CYN"
����ү˵�����ձ��ǹ������ׯ�Ĵ��ʱ�������Ѿ�ǲ���ֽ����������Χס��
ֻ�����ׯǽ�߱��ϣ����Ÿ��Ƿ���ɭ�ϣ�����Ҫ���������ĸ���ǰȥ����
��ס��ֻ�轫����ɨ���ɾ������"YEL"�ر�"CYN"���ң�ʣ�µ���������ȥ����\n"NOR);
		if (REWARD_D->riddle_check(me,"�Ѫ����")==10)
			REWARD_D->riddle_set(me,"�Ѫ����",11);
		if (me->query("quest/quest")=="�������ׯ")
		{
			if (me->query("marks/quest/���ׯ")!=1)
				me->set("marks/quest/���ׯ",1);
			else
				command("say ������ȥ���³ɺ�����"YEL"�ر�"CYN"!");
		}
		return 1;
	}
	
	if (REWARD_D->riddle_check(me,"�Ѫ����")==9) {
		tell_object(me,CYN"
����ү�������ƺ��ܶ���һ�е�Ŀ�⿴���㣺��̫ƽ����ÿһ���˵����٣���
��֪���Ļ����࣬���Ӻ�����Щ�ƻ���Ҳ�����ҵ�����֮�У�����ͼ����ʲô
�ѵ��㻹����������

����ү�������ǳǳ����һ�ڵ����㵽�������Ű��죬���ж�����Ҫɱ�㣿
�������ƻ��˴˰����㻹�ܻ����뿪�������ô��

����үЦЦ˵��������֪���ⰸ�ӵĹؼ�������������������ϣ�����������
���Ķ��֡���Ҫ�ģ�ֻ��������ӣ���������û�г�ͻ��ֻ�й�ͬ�ĵ��ˡ���
Ȼ��Ҫɱ���ң�ɱ��������Ǳ������쾭������£�

����ү�����Ľ��ŵ����ҿ��԰���ס���Ļ���������İ������������ʱ�̣�
����ϰ�߾��������㣬���Ƿ�Ҫ�Ұ����æ��\n"NOR,this_object());
		me->set_temp("marks/parrot/answer_sanye",1);
		return 1;
	}
	
	
	command("say ʲô���������£���Ȼ��ȥ���㡣");
	return 1;
}



int do_answer(string arg)
{
	object me,key;
	int i, gotit;
	
	me=this_player();
	if(!me->query_temp("marks/parrot/answer_sanye")) return 0;
		
	if(arg=="yes" || arg == "Ҫ" || arg == "sure" || arg == "��" ){
		tell_object(me, CYN"����ү�Ǻ�һЦ�������������˵����Ȼ�Ǹ������ˣ�
������ˣ�����Э���Ը���������ǰ����һ��"YEL"����"CYN"��\n"NOR);
		me->delete_temp("marks/parrot/answer_sanye");
		me->delete_temp("marks/parrot/reject_sanye");
		REWARD_D->riddle_set(me,"�Ѫ����",10);
		return 1;	
	}
	
	if(arg=="no" || arg == "��Ҫ"){
		tell_object(me,CYN"����ү����һ�µ�������ϣ����úõ��ٿ���һ�¡�\n"NOR);
		me->set_temp("marks/parrot/reject_sanye",1);
		me->delete_temp("marks/parrot/answer_sanye");
		return 1;
    }
    
	return 0;
	
}