#include <ansi.h>
inherit NPC;

void create()

{

        set_name("��һ��", ({ "wang yihu","yihu","wang"}) );
        set("title", "����կ ������" );
        set("nickname", HIY"�������"NOR);
        set("gender", "����");
        set("age", 33);
	set("long",
		"һ�����δ󺺡�����˼�壬��������������������ѿ�ɽ�󸫣�һ\n���Ⱦͱȳ�׼�����˶��ء�\n" );
        set("combat_exp", 600000);
        set("score", 17000);
	set("cor",30);
	set("attitude","killer");
        set("bellicosity", 600);
        
        set_skill("force", 100);
        set_skill("axe", 100);
        set_skill("parry", 120);
        set_skill("dodge", 120);
	set_skill("wuche-axe",120);
	set_skill("puti-steps",120);
	
	map_skill("axe", "wuche-axe");
	map_skill("parry","wuche-axe");
	map_skill("dodge","puti-steps");
	
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "axe.sanbanfu" :)
        }) );

        setup();

        carry_object(__DIR__"obj/huge_axe")->wield();
        carry_object(__DIR__"obj/leather")->wear();
        carry_object(__DIR__"obj/fur_coat")->wear();        
//        add_money("gold", 1);
}



void init()

{

	object me;
	::init();
	me = this_player();
	if(interactive (me) && environment(me) == environment() && !me->is_fighting()) 
	{
		remove_call_out("greeting");
		call_out("greeting", 1, me);
	}
}



void greeting(object me)

{
	if((string)me->name() !="��ɽ��" && !me->query_temp("marks/keychain_ehg") ) 
	{
		command("say �����������㿴�����ӵĸ����ж�죡\n");
		this_object()->kill_ob(me);
	}
	else
	{
		command("say ��ɽ������θ����Ӵ��ռ���û�У�\n");
	}
}

