#include <ansi.h>
inherit NPC;

void create()
{
		object		biao, bag;
        set_name("����ʹ��", ({ "ghost" }) );
        set("gender", "����");
        set("per", 1);
        set("class", "ghost");
        create_family("����ɽׯ", 2, "����");
        set("combat_exp", 150000);
        set("long",	"��������Ȼ�ѱ���һ����ƽ�ˣ���˵�������µı��Ǳ��˸�������û����Ŀ��
��tell ghost no face��\n");
        set("no_arrest",1);
        set_skill("move", 150);
        set_skill("dodge", 100);
        set_skill("five-steps", 100);
        set_skill("sword", 140);
        set_skill("three-sword", 50);
        set_skill("parry",100);
        map_skill("parry","three-sword");
		map_skill("dodge", "five-steps");
		map_skill("move", "five-steps");
		map_skill("sword", "three-sword");
        setup();
		carry_object(__DIR__"obj/clip2")->wield();
		carry_object(__DIR__"obj/cloth")->wear();
}

void init()
{
	object		me;

        ::init();
        if( interactive(me = this_player()) && !is_fighting() ) {
		add_action("do_accept", "accept");
		add_action("do_tell", "tell");
                remove_call_out("greeting");
                call_out("greeting", 1, me);
        }
}

int do_tell(string arg)
{
	string 	obname, things;
	object me = this_player();
        if(!arg || sscanf(arg, "%s %s", obname, things)!=2 )
                return notify_fail("tell <��> <��>\n");
	if(!this_player()->query_temp("marks/test")) return 0;
	this_player()->set_temp("marks/test", 0);
	if(obname == "ghost") {
		if(things == "no face" || things == "û����Ŀ" || things == "֪������") {
			remove_call_out("do_test");
			message_vision(YEL "\n$N��ɫ��ü�Ϊ�ѿ�����$n˵��������Թ�ȥ�ˡ�\n"NOR, this_object(), this_player());
			this_player()->set_temp("marks/��Լ", 1);
           	REWARD_D->riddle_done(me,"����ɽׯ",10,1);
		
        	return 1;
		}
	}
	return 0;
}

int greeting(object me)
{
	message_vision(YEL "\n$N��$n˵�����������һ�أ��ͽ���һ�У�accept test����\n"NOR, this_object(), me);
	return 1;
}

int do_accept(string arg)
{
	if( arg != "test" ) {
                return notify_fail("��Ҫ����ʲô��\n");
	}
	remove_call_out("do_test");
	message_vision( YEL "$N˵�����ã����������ʱ��׼����\n"NOR, this_object());
	this_player()->set_temp("marks/test", 1);
	call_out("do_test", 15, this_player());
	return 1;
}

int do_test(object me)
{
	int	kee;

	if(objectp(me)) {
		me->set_temp("marks/test", 0);
		if(environment(me) == environment()) {
			message_vision(YEL "\n$N˵����׼���ˣ�������һ�У�\n"NOR, this_object());
			kee = (int)me->query("kee");
			COMBAT_D->do_attack(this_object(), me, query_temp("weapon"));
			if( (int)me->query("kee") < kee  || !present(me, environment())) { 
				message_vision(YEL "\n$N˵��������һ�ж��Ӳ��£������Բ�������\n"NOR, this_object());
				return 1;
			}
			else {
				message_vision(YEL "\n$N��$n˵�����ù�������Թ�ȥ�ˡ�\n"NOR, this_object(), me);
				me->set_temp("marks/��Լ", 1);
				return 1;
			}
		}
	}
	return 0;
}
