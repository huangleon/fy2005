inherit NPC;
#include <ansi.h>

void create()
{
    set_name("ɢ����Ů", ({ "flower girl","girl" }) );
	set("gender", "Ů��" );
	set("age", 18);
	set("long",
            "һ���ڷ����磬������ѩ����Ů�����������ƾպ컨����������ڻ����ϡ�\n");
        set("combat_exp", 80000);
	set("attitude", "friendly");
	set("per",30);
        set("chat_chance", 1);
        set("chat_msg", ({
        "ɢ����Ů������������Ÿ�ʽ�ʻ���������Ц�������ں��ߡ�\n",
        }) );
	set_skill("unarmed",20);
	set_skill("dodge",100);
	setup();
        carry_object(__DIR__"obj/baiqun")->wear();
}
