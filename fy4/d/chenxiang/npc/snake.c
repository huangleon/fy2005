
inherit NPC;
void use_poison();

void create()
{
        set_name("�޻���", ({ "huge serpent" }) );
        set("race", "����");
        set("age", 400);
        set("long", "�����޴��ޱȣ����������˶����������ϻ�ð��ŧѪ��\n");
        
        set_skill("dodge", 200);
        set_temp("apply/damage",100);
        set("combat_exp", 2999999);
        set("chat_chance_combat", 10);
        set("chat_msg_combat", ({
                (: use_poison :),
        }) );
        setup();
		
}


void use_poison()
{
        object *enemy, ob;
        string msg;

        enemy = query_enemy();
        if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];

        tell_object(ob,"��������Ͼ�ʹ������һ��������������ӡ�ۡ�\n");
		ob->receive_wound("kee",40);
                ob->apply_condition("snake_poison", 
                (int)this_player()->query_condition("snake_poison")
                + random(10)+10);
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) && !ob->query_temp("marks/cured_jia") ) {
                kill_ob(ob);
        }
}



int cure_arong(object me)
{
	 object room,obj;
 	if(!query("cured") && me->query_temp("marks/cured_monk") &&
        	               me->query_temp("marks/cured_jia") &&
				!me->query_temp("marks/cured_snake")) {
 		tell_object(me,"�޻������ϵĶ�����ŧѪ����ʼ��������ʧ�ˣ�����\n");
 		tell_object(me,"�޻���̧��β����������ϲ��˲䣬�ƺ�������ĸ�л��\n");
 		me->set_temp("marks/cured_snake",1);
 		tell_object(me,"�޻����������³����ִ����������ӣ�Ȼ����β�;�ס����������һ�ף�����\n\n\n");
 		tell_object(me,"�������ڿն��𣮣���Ŷร�����������\n\n\n");
 		set("cured",1);
 		obj = new(__DIR__"obj/pearl");
 		obj->move(me);
 		room = load_object(AREA_CHENXIANG"wol2");
 		me->move(room);
 		me->delete_temp("marks/cured_monk");
 		me->delete_temp("marks/cured_jia");
 		me->delete_temp("marks/cured_snake");
 		me->delete_temp("marks/asked_jianu");
 	} 
 	return 1;

}


int	reset(){
	set("cured",0);
}