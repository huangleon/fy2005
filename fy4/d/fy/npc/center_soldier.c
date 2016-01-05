#include <ansi.h>

inherit NPC;
string	summon_more( object who);
void create()
{
        set_name("Ѳ��ʿ��", ({ "patrol police","police" }) );
        set("long","
��Ȼ���Ƴ��ﲻ��ֹе��������������˵���Ƥ�µ��Ҿ�̫�����ˣ����ԣ������
����Ψһ��һ��ִ��Ѳ�������ʿ��������ά���㳡���ΰ��������д�����׵���
ͼ��ǧ��Ҫ����ײ������������ǰ�Ǹ�ʲô�ģ���������ʲôԭ�򣬴��������
���˷������񣬶������к��³���
һ�仰��"HIR"�ڴ˵�ɱ���ߣ�����
\n"NOR);
        set("class","wudang");
        set("combat_exp", 11000000);

        set("chat_chance_combat", 99);
        set("chat_msg_combat", ({
                (: perform_action, "sword.chanzijue" :),
				(: summon_more(this_object()) :),
        }) );
                
        set_skill("unarmed", 200);
        set_skill("sword", 350);
        set_skill("parry", 350);
        set_skill("dodge", 350);
        set_skill("move", 350);
		set_skill("taiji-sword",200);
		set_skill("five-steps",200);
		set_skill("lingxi-zhi",200);
	
		map_skill("unarmed","lingxi-zhi");
		map_skill("parry","taiji-sword");
		map_skill("dodge","five-steps");
		map_skill("move","five-steps");
		map_skill("sword","taiji-sword");
        
        set_temp("apply/attack", 170);
		set_temp("apply/dodge", 170);
		set_temp("apply/parry", 170);
        set_temp("apply/armor", 170);
        set_temp("apply/damage", 200);
        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/sword")->wield();
}

void init() {
	object ob;
	::init();
	add_action("do_killing", "kill");
}


int do_killing(string arg)
{
    object player, victim;
    string id,id_class;
    player = this_player();
    if(!arg || arg == "") return 0;
    victim = present(arg, environment(player));
    if(!objectp(victim))
		return notify_fail("����û������ˡ�\n");
    if(living(victim))
    {
       	if(userp(victim)&& victim!=player)
        {
            if (ANNIE_D->check_buff(victim,"fugitive"))	return 0;
            message_vision(HIW"$N����$n�ȵ����󵨿�ͽ������������ɱ�ˣ�����������־͸���\n"NOR, this_object(), player);
            this_object()->kill_ob(player);
            player->kill_ob(this_object());
            player->start_busy(2);
            return 0;
        } 
    }
    return 0;
}


string summon_more(object who)
{
	int i;
	object *enemy;
	object another;
	seteuid(getuid());
	if (random(3)) {
		message_vision(HIW"$N��е�������ס�ˣ������ү��!\n"NOR, this_object());	
		another = new(__DIR__"patrol_officer");
		another->move(environment(who));
		message_vision(HIY"Ѳ���ڹ����˹�����\n"NOR, this_object() );
		message_vision(HIY"Ѳ���ڹٺȵ����η����񣬾����ڷ��Ƴ������ң�\n"NOR,this_object());	
		enemy = who->query_enemy();
		i = sizeof(enemy);
		while(i--) {
			if( enemy[i] && living(enemy[i]) ) {
			another->kill_ob(enemy[i]);
			enemy[i]->kill_ob(another);
			another->set_leader(enemy[i]);
			}
		}
		return "1";
	}
	return "0";
}
