#include <ansi.h>
inherit NPC;

void create()
{
        set_name("СҶ��", ({ "xiao yezi","yezi" }) );
        set("long","
СҶ���ǵ��������ͯ��������ֻ��ʮ����������ӣ�ü��Ŀ�㣬
����һ���ʺ�����ѣ���������ϲ�������ӡ�\n");
	
	set("title", "��ͯ");
    set("attitude", "friendly");
    set("class", "assassin");
    set("reward_npc", 1);
	set("difficulty", 3);
	
	set("age",15);
    set("combat_exp", 3500000);

	set("inquiry", ([
                "���³���":	"���³������ҵ�����Ү��\n",
                "di qinglin" : 	"��С��ү��\n",
                "������" : 	"��С��ү��\n",
        ]));
        
	set_skill("sword",200);
	set_skill("sharen-sword",170);
	set_skill("parry",200);
	set_skill("dodge",200);
	set_skill("lefthand-sword",170);
	set_skill("jinhong-steps",160);
	set_skill("unarmed",160);
	set_skill("flame-strike",150);
		
	map_skill("unarmed","flame-strike");
	map_skill("dodge","jinhong-steps");
	map_skill("parry","lefthand-sword");
	map_skill("sword","sharen-sword");

	set("death_msg","\n$N��е�����������ˮ���������죬С��ү����Ź���ģ������� \n"NOR);
        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
                (: perform_action,"sword.sharenruma"  :),
        }) );

        setup();
        carry_object("/obj/armor/cloth",([	
    					"name":  RED"�ʺ������"NOR,
    					"long": "һ���ʺ�����ѣ���ϧ�°�˺�˸����ӡ�\n",
    					 ]))->wear();
        carry_object(__DIR__"obj/bishou");
}


int accept_object(object who, object ob)
{
	if (ob->is_fighting())
		return notify_fail("СҶ����æ���أ�û�����㡣\n");
	
	if(ob->query("libie_evidence")) 
	{
		if(!who->query_temp("libie/lian_corpse"))
		{
    			message_vision(CYN"СҶ��˵���ۣ��첼ͷ����ϲ����ɫ���������������ģ��Ҳ�ҪҮ��\n"NOR,who);
    			return 0;
    		}
    		
    		message_vision(YEL"СҶ�ӵ���ɫ��Ȼ���ˣ������Ц�ݺ�Ȼ��ʧ��\n"NOR,who);
    		kill_ob(who);
		who->set_temp("libie/di_1",1);
		return 1;
	}
	
	return 0;
}


void heart_beat()
{	object dagger;
	
	dagger=present("dagger",this_object());
	if(objectp(dagger))
	{
	if(!this_object()->is_fighting())
	{
		if (dagger->query("equipped"))
			this_object()->ccommand("unwield dagger");
	}
	else if (!dagger->query("equipped"))
			this_object()->ccommand("wield dagger");
	}
	::heart_beat();
}
