#include <ansi.h>
#include <command.h>

inherit SMART_NPC;

void create()
{

		set_name("���´�",({"blue cloth man","man"}));
    	set("title",WHT"�ߺ�ɽׯ"NOR);
    	set("long", "�ߺ������Ӹ���Ƹ���ĸ��֣������£��ֳֵָ���\n");
		set("age",40);
		set("combat_exp", 4500000);
        	
		set("nb_chat_chance", 100);
    	set("nb_chat_msg_combat", ([
    		1: name()+"�ȵ������ٲ������������������£�������Ҳ�߲����ˣ���\n",

        ]) );  
    	
    	set("chat_chance", 1);
    	set("chat_msg", ({
    		"���´󺺰����������õ����Ŵ����ϵ�һ��ľͷ��\n",
			"���´�˵���������������ֳ��ֺȣ�����ȴ����ͷ�ɺ��ţ���ˬ����\n",
			"���´󺺲��������������Ķ�����������Ц��������\n",
			"���´������������ֹ��ţ�����ô��û���࣬�������ﶼ�����������ˡ���\n",
        }) ); 
    	
    	set("chat_chance_combat", 100);
    	set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
        }) );
    	    	
		auto_npc_setup("wang",200,180,1,"/obj/weapon/","fighter_w","shenji-blade",1);

		setup();
		carry_object(__DIR__"obj/bluecloth")->wear();
}


int accept_object(object who, object ob)
{
		if (ob->query("food_supply")) {
		if (ob->query("food_remaining")) {
		if (ob->query("value")>=500) {
			message_vision(CYN"
$N�������촽˵����ͦ���ɵģ��������ȥתת�ɣ���Ҫ����������������û�ù��ӳԣ���\n"NOR,this_object());
			who->set_temp("taiping/boat_enter",1);
			return 1;
		} else 
			message_vision(CYN"
$N��м�ؿ���"+ob->name()+"һ��˵����ʲô���߰�������������\n"NOR,this_object());
	} else 
		message_vision(CYN"$N��ŭ������С����ڿ��ү����\n"NOR,this_object());	
	}
	
        return 0;
} 