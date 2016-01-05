#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�ڹ�", ({ "black dog", "dog" }) );
        set("race", "Ұ��");
        set("combat_exp", 50000);
        set("long",	"һ��ȫ����ڣ��ڵ÷����Ĵ󹷡�\n"	);
        set("no_arrest",1);
        set_skill("move", 100);
        set_skill("dodge", 100);
        set_skill("throwing", 100);
        set_skill("feidao", 50);
		map_skill("throwing", "feidao");
        setup();
		carry_object(__DIR__"obj/biao");
}

void init()
{
	object	me;

        ::init();
		add_action("know_dog", "tell");
        if( interactive(me = this_player()) && !is_fighting() ) {
			if(name() == "�ڹ�") {
               	call_out("dogattack", 2, me);
		}
        }
}

int know_dog(string arg)
{
        string  obname, things;
		object	dog;

        if(!arg || sscanf(arg, "%s %s", obname, things)!=2 )
                return notify_fail("tell <��> <��>\n");
        if(obname == "dog") {
           if(things == "���ɾ�") {
            	message_vision(HIY "\n$N��$n˵�������Ȼ�ϳ������������㲻�ã�\n", this_object(), this_player());
				dog = new(__DIR__"hdog.c");
				if(objectp(dog)) {
					dog->move(environment());
					dog->kill_ob(this_player());
				}
				destruct(this_object());
                return 1;
           }
        }
        return 0;
}

int dogattack(object me)
{
	object		groom;
	set_leader(me);
	if (environment(me) == environment())
	{
		message_vision(HIR "\nವ�һ������$n���ڰ������һ֧���ڣ�������$n�ĺ��ģ�\n"NOR, this_object(), me);
		me->receive_damage("kee", 50, this_object());
	}
	return 1;
}

