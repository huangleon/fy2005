inherit NPC;
#include <ansi.h>

void init();
int do_killing(string);
int accept_object(object,object);
void create()
{
	set_name("��ϲ", ({ "ding xi", "xi","dingxi" }) );
	set("gender", "����" );
        set("title", HIG "��ϲȵ"NOR);
	set("age", 20);
	set("per", 30);
	set("class","wolfmount");
	set("attitude","friendly");
	set("long",
		"�����Ǻ���ͣ������š�������Ǵ������ŵ�΢Ц��\n�������ǳ���������ϲ���Ķ�ϲ�����ߡ������Ķ�ϲ��\n"
		);
	
	set("cor",200);
	set("combat_exp", 3000000);
	set("score", 90000);
        
	set_skill("unarmed", 120);
	set_skill("xinyue-dagger", 110);
	set_skill("parry", 180);
	set_skill("dodge", 140);
	set_skill("dagger", 120);
	set_skill("xueyeqianzong",150);
	set_skill("perception",150);
	set_skill("dragonstrike",180);
	set_skill("move",180);
	
	map_skill("unarmed","dragonstrike");
	map_skill("dagger","xinyue-dagger");
	map_skill("dodge","xueyeqianzong");
	map_skill("move","xueyeqianzong");
	map_skill("parry","xinyue-dagger");
	
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
     		(: perform_action, "dagger.douzhuanxingyi" :),
        }) );

	setup();
	carry_object("/obj/armor/cloth")->wear();
        carry_object(__DIR__"obj/shortsword")->wield();
}

void init()
{
	add_action("do_killing", "kill");
	::init();
}

int do_killing(string arg)
{
	object player, victim;
	string name;
	player = this_player();
	if( !arg) return 0;
	if( objectp(victim = present(arg, environment(this_object()))) && living(victim))
	{
		name = (string)victim->name();
		if( (string)name == "������")
		{
			message_vision("$N����ص������������ǲ����ֲ����ˡ���\n", this_object());
			this_object()->kill_ob(player);
			player->kill_ob(this_object());
			return 1;
		}
		else if((string)name == "�鶫��")
		{
			if (REWARD_D->riddle_check( player, "�ھ��ڼ�") == 1)
			{
			message_vision( HIM "�������ʯ��һ˲������ǰһ����ֻ���鶫����ڴ��Ѿ�����һ��Ѫ����

�鶫��Ŀ�ɿڴ��ؿ����Լ����˿ڣ��ֿ��˿���ϲ����������ÿ������......��
��δ��������ҡҡ��׹��
ԭ����$N�ù鶫������֮�ʣ���֪����ʲô�ַ�������������\n\n"NOR,this_object());	
				victim->set("kee",victim->query("max_kee")/2);
				victim->set("eff_kee",victim->query("kee"));
				REWARD_D->riddle_set( player, "�ھ��ڼ�", 2);
			}
		}
	}
	return 0;		
}
