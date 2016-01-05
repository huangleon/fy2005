#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

int startit();

void create()
{

		set_name("����������",({"middle age man","man"}));
    	set("long", "һ���߸����ݵ������ˣ���������ү���µĸɽ���\n");
		set("age",40);
		set("combat_exp", 5000000);
		
		set("sanye",1);
		
		set("max_kee", 8000);
		set("max_gin", 8000);
		set("max_sen", 8000);
		
		set("inquiry", ([
        	"����":	 (: startit :),
        	"mission":	 (: startit :),
        	"��ү":	"��ү��������ү��������̫ƽ���һ�оͶ�����ү���ˡ�\n",
   		]));        	
		
		set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	    	 (: auto_smart_fight(30) :),
        }) );
	
		set("chat_chance",1);
    	set("chat_msg",({
				"����������˵��ֻ����ү"YEL"����"NOR"һ�������Ǳ㹥��ׯȥ��\n",
    	}) );   

		auto_npc_setup("xuebin",200,180,1,"/obj/weapon/","random","random",1);
		setup();
		carry_object(__DIR__"obj/whitecloth")->wear();
}


int	startit(){
	
	object me,young;
	
	me = this_player();
	
	
	if (REWARD_D->riddle_check(me,"�Ѫ����")!=11 && me->query("marks/quest/���ׯ")!=1){
		command("say ʲô�˸Ҽٴ���ү����������ô��");
		return 1;
	}
	
	if (objectp(environment()->query("in_mission")) || is_fighting()) {
		command("say ����������ͷ�ĵ�����˵�ɣ�");
		return 1;
	}
		
	command("say �ã���ү�����ѵ���ֻ����ǰ����׼���ˣ�����������ɱ���⣡");
	if (young= present("young man"))
		young->ccommand("say ʮ��ĥһ����˪��δ���ԣ����հ�ʾ������Ǯ�����ơ�");
			
	message_vision(WHT"\n������������ָһ����һ����ɫ������ƿ��У����ׯ�����ʱɱ�����졣\n\n"NOR, me);
	
	message_vision(BLU"ǽ�ڽŲ������ҷ�������Ȼ����һ������ׯ����\n"NOR, me);
	message_vision(BLU"����ׯ���е���̫��ͷ�϶������ϻ�������ë��������ˣ�\n\n"NOR,me);
	
	environment()->set("in_mission", me);
	environment()->init_mission( 1, me->query("combat_exp"), me);
	return 1;
}
	