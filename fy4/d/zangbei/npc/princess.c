inherit NPC;
#include <ansi.h>

void create()
{
	set_name("���ù���", ({ "princess" }) );
	set("title","��ԡ");
	set("gender", "Ů��" );
	set("cor",20);
	set("age", 22);
	set("per",100);
	set("NO_KILL",1);
	set("long","
�������������壬������б������ӳ���£���ֱ����һ��������������
һ�εξ�Ө��ˮ�飬������������ȱ�Ĳ��ӣ����������������ţ�����
Ц�������壬Ц���紺�յİٻ���š�\n");
	set("combat_exp", 500000);
	set("attitude", "friendly");
	set("chat_chance",1);
    	
    	set_skill("thunderwhip",100);
	set_skill("whip",100);
	set_skill("dodge",100);
	set_skill("zuixian-steps",150);
	set_skill("parry",100);
	set_skill("unarmed",100);
	set_skill("pofeng-strike",100);
	map_skill("unarmed","pofeng-strike");
	map_skill("whip","thunderwhip");
	map_skill("parry","thunderwhip");
	map_skill("dodge","zuixian-steps");
	
	setup();

}
	