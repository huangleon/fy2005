// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "������", ({ "girl liu","liu", "girl" }) );
	set("long", "����ǧ��¥���ϰ˽�֮һ��
�����������ﲻʤ�ߡ�
����ϴ�������ۣ�����ҡŪ����֫����������ˡ�
���������������ŵ͡�
�߷����˴����������ѩů��ʱ�������������
\n");
	set("attitude", "friendly");
	set("title", HIM "���ϰ˽�"NOR);

	set("age", 17);
        set("gender", "Ů��" );

	set("per", 40);
	set("combat_exp", 120000);
        set("chat_chance", 1);
        set("chat_msg", ({
"�������Ӷ�������������裺
����������ˮ��
׳ʿһȥ�ⲻ����\n",
        }) );

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(: summon_more(this_object()) :),
	}) );
	set_skill("dagger", 100);
	setup();
        carry_object(__DIR__"obj/liu")->wear();
	carry_object(__DIR__"obj/wuqi")->wield();


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
	object pai;
    
    if( (int) obj->value() >=  50000)
	{
        message_vision("$N��$n���˸��򸣣�\n",this_object(),me);
        command("smile");
		command("say �ۣ�������ϲ����Ү��̫лл���ˣ�������㣡\n");
		pai = new(__DIR__"obj/liupai");
		if(pai)
		pai->move(me);
	        message_vision("$N�ó�����赸�$n��\n",this_object(),me);
		return 1;	
	}

	ccommand("say �㵱���Ƕ��ǵ���潰���");
	return 0;
}

