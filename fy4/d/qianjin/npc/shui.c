// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "����ˮ", ({"girl shui", "shui", "girl" }) );
	set("long", "����ǧ��¥���ϰ˽�֮һ��
����ˮ�����ƽ�԰�С�
б��ůҡ��䶯���仨��ů���ƺ죬ƻĩ����硣
����Ŀ����ԾС������
������ҡ�����ȣ�������Ӱ���ɹ���Զ������ء�
\n");
	set("attitude", "friendly");
	set("title", HIM "���ϰ˽�"NOR);

	set("age", 17);
        set("gender", "Ů��" );


	set("per", 40);
	set("combat_exp", 50000);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("unarmed", 1+random(100));
	setup();
        carry_object(__DIR__"obj/shui")->wear();
        carry_object(__DIR__"obj/shuipai");

}

string summon_more(object who)
{
	int i;
	object *enemy,*ob;
	object another;
	seteuid(getuid());
	ob=all_inventory(environment(who));
	ob=filter_array(ob,(: $1->query("id")=="jianu" && $1->query("name")=="��ū": ));
	if (sizeof(ob)<1) {
	another = new(__DIR__"jianu");
	another->move(environment(who));
	message_vision(another->name()+ "���˹�����\n"
		, this_object() );
	enemy = who->query_enemy();
	i = sizeof(enemy);
	while(i--) {
		if( enemy[i] && living(enemy[i]) ) {
			another->kill_ob(enemy[i]);
			enemy[i]->kill_ob(another);
			another->set_leader(enemy[i]);
			}
		}
	}
	return "1";
}


int accept_object(object me, object obj)
{
	message_vision("$N΢Ц��˵�����Ѿ���������Ҫ���ˣ���ʲô����Ҫ�ˡ�\n",this_object());
	return 0;
}

