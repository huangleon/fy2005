// thousand_hand.c

#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
	set_name( "����Ů", ({ "girl nu","nu", "girl" }) );
	set("long", "����ǧ��¥���ϰ˽�֮һ��
����Ů����ѡ����ӯ��
�̺�է�����£��ཫ���ǲ����ˣ��峪áƵƵ��
���ںã���Ϸ������
��������ž�ҹ��̤�භ�����ഺ��������Ⱥ�档
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
	set_skill("unarmed", 1+random(200));
	setup();
        carry_object(__DIR__"obj/nu")->wear();

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
    
    if((NATURE_D->get_current_day_phase() == 0)) {
        message_vision("$N��$n���˸��򸣣�\n",this_object(),me);
        command("smile");
		command("say �㻹�������ģ�������㣡\n");
		pai = new(__DIR__"obj/nupai");
		if(pai)
		pai->move(me);
        message_vision("$N�ó�Ů��赸�$n��\n",this_object(),me);
		return 1;	
	}
	
	command("say ��ɲ��Ǳ�����ϲ����Ү��");
	return 0;
	
}

