// hu.c

inherit NPC;
#include <ansi.h>
 
void create()
{
		set_name("���������", ({ "nakedman" }) );
		set("title",HIB "�޾�����"NOR);
		set("gender", "����" );
		set("age", 35);
    	set("long","
���⣬������������Ҳҵĺ����ӣ�Ҳ�������������������Ц�ݣ�
һ˫�ֺ������Ĵ��۾�, �����ǳ�������õ����Ѻ����������������ӡ�
\n");
		set("combat_exp", 1000000);
		set("attitude", "friendly");
	
		set_skill("force", 150);
		set_skill("bibo-force", 150);
    	set_skill("unarmed", 120);
    	set_skill("dodge", 120);
    	set_skill("luoriquan", 120);
    	set_skill("move", 120);
    	set_skill("fengyu-piaoxiang", 200);
    	set_skill("parry", 120);
    	
    	map_skill("force"  , "bibo-force");
    	map_skill("unarmed", "luoriquan");
    	map_skill("dodge"  , "fengyu-piaoxiang");
		map_skill("move"  , "fengyu-piaoxiang");
	
		set("chat_chance_combat", 50);
    	set("chat_msg_combat", ({
        (: perform_action, "dodge.zonghengsihai" :),
            }) );
	
		setup();
}
