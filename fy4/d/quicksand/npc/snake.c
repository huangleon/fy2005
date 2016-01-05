inherit NPC;
void use_poison();

void create()
{
        set_name("��β��", ({ "snake" }) );
        set("race", "����");
        set("age", 4);
		set("long", "һ���綾����β�ߡ�\n");

        set_skill("dodge", 50);
        set("bellicosity", 300 );
        
        set("combat_exp", 5000 + random(50000));      
        
        set("chat_chance_combat", 1);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
        }) );
        setup();
    	if (!random(2)) carry_object("/d/shanliu/npc/obj/xiangweishedan");
}

void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,"��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
        ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(3)+3);
}


void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
                kill_ob(ob);
        }
}

