#include <ansi.h>
inherit NPC;
void use_poison();
void create()
{
    set_name(HIG"����"NOR, ({ "spirit snake", "snake" }) );
    set("race", "Ұ��");
    set("age", 1);
    set("gender", "����");
    set("long", "һ��ȫ��Ө�̵�С�ߡ� \n");
    set("attitude","peaceful");
    set("limbs", ({ "ͷ��", "����","β��", "�ߴ�" }) );
    set("verbs", ({ "bite"}) );
	set("weight", 300);
	set("max_kee", 3000);
        set("max_sen", 3000);
        set("eff_gin", 9999);
        set("eff_kee", 3000);
        set("eff_sen", 3000);
        set("gin", 3000);
        set("kee", 9999);
        set("sen", 3000); 

	set("combat_exp", 10000000);
    set("chat_chance_combat", 30);
    set("chat_msg_combat", ({
    	(: use_poison :),
    }));
    setup();
}

void use_poison()
{
    object *enemy, ob;
    string msg;

    enemy = query_enemy();
    if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	message_vision(HIG"$N�����޺����ͷ��һ��ϸ���˿���̹�ɳ�������$n��\n"NOR, this_object(),ob);
    tell_object(ob,HIC"��ֻ��������һ�飬һ����˳�ž�������ȫ��\n"NOR);
    ob->receive_wound("kee",50);
    ob->apply_condition("canxia", 
    	(int)this_player()->query_condition("canxia")
    	+ random(2)+1);
}

void invocation(object who)
{
	int level;
	level = who->query("combat_exp")/3000;
	set("str",10+level/20+random(level/20));
    set("combat_exp", 100000 + level/8*level*level/4+random(level/8*level*level)*3/4);
	set("leader",who);
	set("possessed",who);
	return;
}

int heal_up()
{
        if( environment() && !is_fighting() ) {
                call_out("leave", 1);
                return 1;
        }
        return ::heal_up() + 1;
}
void leave()
{
        object owner,snakesword;
		owner = query("possessed");
		if (objectp(owner))	owner->add_temp("max_snake",-1);
		if (objectp(owner) && present(owner,environment(this_object())) && 	(snakesword = present("snake sword",owner)))
        {
			if (snakesword->query("equipped"))
				message_vision("$N����һ�����̽���$n���е�"+snakesword->query("name")+"�ϲ����ˡ�\n",this_object(),owner);
			else
				message_vision("$N����һ���������$n���е�"+snakesword->query("name")+"�ϲ����ˡ�\n",this_object(),owner);
        }else
		{
			message_vision("$N����һ��,Ѹ�ٵ������ˡ�\n",this_object());
		}
        destruct(this_object());
		return;
}
void die()
{
	object owner;
	owner= query("possessed");
	if (objectp(owner))	owner->add_temp("max_snake",-1);
	message_vision("$Ṉ����������Ϊһ̯��Ѫ��������ʧ������\n",this_object());
	destruct(this_object());
	return;
}