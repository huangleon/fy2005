#include <ansi.h>
inherit NPC;
void create()
{
        set_name("ѩ����", ({ "xue yiren" }) );
        set("gender", "Ů��");
		set("age",25);
		set("combat_exp", 1000000);
        set("class","demon");
        
        set("long",	"һ����Ư����Ů�ˣ�������ȥ������һ��磬һ���ƣ�һƬѩ����\n");
	
		set_skill("demon-steps",100);
		set_skill("demon-strike",100);
		set_skill("move",300);
        set_skill("dodge", 150);
		set_skill("unarmed",100);
		set_skill("parry",100);
	
		map_skill("unarmed","demon-strike");
		map_skill("dodge","demon-steps");
		map_skill("move","demon-steps");
	
        set("chat_chance", 1);
        set("chat_msg", ({
			(: random_move :),
			name()+"Ц��Ц������������һ�������������Ը���ġ�\n",
			name()+"������������һ�У�Ϊ���ǶԸ�л������ү��\n"
        }) );
		setup();
        carry_object(__DIR__"obj/ycloth")->wear();
        carry_object(__DIR__"obj/fshoe")->wear();
}
