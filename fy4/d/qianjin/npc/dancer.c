
inherit NPC;
#include <ansi.h>
void create()
{
	set_name("������Ů", ({ "dancer" }) );
	set("gender", "Ů��" );
	set("title", HIY "ɴ������"NOR);
	set("age", 18);
	set("long",
		"һ��ɴ�����ʣ���Ұ�Ըе�������Ů��\n");
	set("combat_exp", 300000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 5);
        set("chat_msg", ({
		"������Ů˫������İڶ��ţ�\n",
		"������Ůȫ�����߰��Ť����������Ŀ�ⷢ����\n",
		"������Ů�ڿն�����շ��˼�Ȧ����Ĩ��Ĩ��ߵĿ�ˮ��\n",
        }) );
	set_skill("unarmed",100);
	set_skill("tenderzhi",50);
	set_skill("dodge",100);
	set_skill("stormdance",100);
	map_skill("dodge","stormdance");	
	map_skill("unarmed","tenderzhi");
	setup();
	carry_object(__DIR__"obj/halfcloth")->wear();
}
