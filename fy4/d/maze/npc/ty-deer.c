#include <ansi.h>;
inherit NPC;

void create()
{
		set_name("С¹", ({ "little deer", "deer"}) );
    	set("race", "����");
    	set("age", 5);
    	set("long", "һͷǳǳ��ë���ϴ��Ű�ɫ�ߵ��С¹��\n");
    	set_skill("dodge", 100);
		set("target_name","С¹");
		set("maze","taoyuan");
		set("chat_chance",1);
    		set("chat_msg",({
		(: random_move() :),
    	}) );  
	
		set("combat_exp", 50000);
		set("self_go_msg",1);
		set("arrive_msg","С¹�ı����������˹�����");
		set("leave_msg","С¹�ı������������ˡ�");
		set("env/wimpy",99);
		setup();
}